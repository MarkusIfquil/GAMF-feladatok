#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> Words;
vector<pair<int, int>> ASCIINumbers;
vector<string> WordsWithASCIIof607;
vector<pair<int, char>> numberOccurences;

bool isPrime(int n) {
    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0)
            return false;
    return true;
}

int CountVowelWords() {
    int Vowels, WordsWith4Vowels = 0;
    for (const string &word: Words) {
        Vowels = 0;
        for (char character: word) {
            if (character == 'A' || character == 'E' || character == 'I' || character == 'O' || character == 'U')
                Vowels++;
        }
        if (Vowels >= 4)
            WordsWith4Vowels++;
    }
    return WordsWith4Vowels;
}

int CountWordsWithESAT() {
    int containsESAT = 0;
    int checkpoint;
    for (const string &word: Words) {
        checkpoint = 0;
        swaws:
        for (int i = checkpoint; i < word.length(); i++) {
            if (word[i] == 'E') {
                for (int j = i + 1; j < word.length(); j++) {
                    if (word[j] == 'E' || word[j] == 'A' || word[j] == 'T') {
                        checkpoint = j;
                        goto swaws;
                    } else if (word[j] == 'S') {
                        for (int h = j + 1; h < word.length(); h++) {
                            if (word[h] == 'E' || word[h] == 'S' || word[h] == 'T') {
                                checkpoint = h;
                                goto swaws;
                            } else if (word[h] == 'A') {
                                for (int q = h + 1; q < word.length(); q++) {
                                    if (word[q] == 'E' || word[q] == 'S' || word[q] == 'A') {
                                        checkpoint = q;
                                        goto swaws;
                                    } else if (word[q] == 'T') {
                                        containsESAT++;
                                        //cout << word << " ";
                                        goto gaming;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        gaming:
    }
    return containsESAT;
}

int AddUpASCIIvalues(const string &word) {
    int WordInASCII = 0;
    for (char c: word) {
        WordInASCII += int(c);
    }
    return WordInASCII;
}

void throwASCIIIntoVector(int ascii) {
    bool InVector = false;
    for (auto &a: ASCIINumbers) {
        if (a.second == ascii) {
            a.first++;
            InVector = true;
            break;
        }
    }
    if (!InVector) {
        pair<int, int> p;
        p.first = 1;
        p.second = ascii;
        ASCIINumbers.push_back(p);
    }
}

void throwCharIntoVector(char &c)
{
    bool InVector = false;
    for (auto &a: numberOccurences) {
        if (a.second == c) {
            a.first++;
            InVector = true;
            break;
        }
    }
    if (!InVector) {
        pair<int, char> p;
        p.first = 1;
        p.second = c;
        numberOccurences.push_back(p);
    }
}

int CountWordsWhichASCIIIsPrime() {
    int primeWords = 0, ascii;
    for (const string &word: Words) {
        ascii = AddUpASCIIvalues(word) - 13;
        if (ascii == 607)
            WordsWithASCIIof607.push_back(word);
        //cout << ascii << " " << word << "\n";
        if (isPrime(ascii)) {
            primeWords++;

        }
    }
    return primeWords;
}

int MostPopularASCIICode() {
    int ascii;
    for (const string &word: Words) {
        ascii = AddUpASCIIvalues(word) - 13;
        throwASCIIIntoVector(ascii);
    }

    sort(ASCIINumbers.begin(), ASCIINumbers.end());
    reverse(ASCIINumbers.begin(), ASCIINumbers.end());
    return ASCIINumbers[0].second;
}

string LettersThatAreIn5Words() {
    for (auto &a: WordsWithASCIIof607) {
        for(char &c:a)
        {
            throwCharIntoVector(c);
        }
    }
}

int main() {
    ifstream File("szavak.txt");
    string Line;
    while (getline(File, Line)) {
        Words.push_back(Line);
    }
    cout << CountVowelWords() << " "
         << CountWordsWithESAT() << " "
         << CountWordsWhichASCIIIsPrime() << " "
         << MostPopularASCIICode() << "\n";

    for (const auto &a: WordsWithASCIIof607)
        cout << a << " ";
    return 0;
}
