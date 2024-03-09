#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
vector<string> Messages;

vector<pair<int, int>> vectorOfPairsOfNumberAndOccurences;

struct Num {
    char num{};
    float countFail = 0;
    float countOccurences = 0;
    float percentage{};
};
vector<Num> vectorOfFailedDigits;

void printVector(vector<int> &v) {
    for (int i: v) {
        cout << i << " ";
    }
}

void printStructs() {
    for (auto number: vectorOfFailedDigits) {
        cout << number.countOccurences << " " << number.countFail << " " << number.num << " " << number.percentage
             << "\n";
    }
}

void fillNumVector() {
    for (int i = 0; i < 10; i++) {
        Num number;
        number.num = i + '0';
        vectorOfFailedDigits.push_back(number);
    }
}

void fillPairVector() {
    vectorOfPairsOfNumberAndOccurences.clear();
    for (int i = 0; i < 10; i++) {
        pair<int, int> p;
        p.first = 0;
        p.second = i;
        vectorOfPairsOfNumberAndOccurences.push_back(p);
    }
}

int countQuestionMarks() {
    int QuestionMarks = 0;
    for (const string &message: Messages)
        for (char character: message)
            if (character == '?') QuestionMarks++;
    return QuestionMarks;
}

int findMostProbableDigit(int i) {
    for (int j = 0; j < 500; j++) {
        for (auto &p: vectorOfPairsOfNumberAndOccurences) {
            if (p.second == Messages[j][i] - '0') {
                p.first++;
            }
        }
    }
    sort(vectorOfPairsOfNumberAndOccurences.begin(), vectorOfPairsOfNumberAndOccurences.end());
    reverse(vectorOfPairsOfNumberAndOccurences.begin(), vectorOfPairsOfNumberAndOccurences.end());
    return vectorOfPairsOfNumberAndOccurences[0].second;
}

string findMostProbableCode() {
    string mostProbableCode;
    for (int i = 0; i < 100; i++) {
        mostProbableCode.append(to_string(findMostProbableDigit(i)));
        fillPairVector();
    }
    return mostProbableCode;
}

void updateStruct(string &mostProbableCode, int count, int i) {
    for (auto &number: vectorOfFailedDigits) {
        if (number.num == mostProbableCode[i]) {
            number.countFail += (float) count;
            number.countOccurences += 500;
            number.percentage = number.countFail / number.countOccurences;
            break;
        }
    }
}

void completeStruct(string &mostProbableCode) {
    int count = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 500; j++) {
            if (Messages[j][i] != mostProbableCode[i]) {
                count++;
            }
        }
        updateStruct(mostProbableCode, count, i);
        count = 0;
    }
}

string findLongestWrongSequence(string &mostProbableCode) {
    string str1 = "", str2 = "";
    for (string &message: Messages) {
        for (int i = 0; i < 100; i++) {
            if (message[i] != mostProbableCode[i]) {
                str1 += message[i];
            } else {
                if (str1.length() > str2.length())
                    str2 = str1;
                str1 = "";
            }
        }
    }
    return str2;
}

int main() {
    ifstream File("uzenetek.txt");
    string Line;
    while (getline(File, Line))
        Messages.push_back(Line);

    fillNumVector();
    fillPairVector();

    string mostProbableCode = findMostProbableCode();
    cout << countQuestionMarks() << "\n" << mostProbableCode << "\n";
    completeStruct(mostProbableCode);
    printStructs();
    cout << findLongestWrongSequence(mostProbableCode);
    return 0;
}
