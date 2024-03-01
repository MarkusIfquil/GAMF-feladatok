#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <cmath>
#include <boost/algorithm/string.hpp>
#include <cinttypes>
using namespace std;
string MAGIC0 = "216816212162121681684816816";

vector<unsigned long long int> FirstProblemA(int n, int start) {
    vector<unsigned long long int> listOfSequence;
    listOfSequence.push_back(start);
    for (int i = 1; i < n; i++) {
        unsigned long long int x = listOfSequence[i - 1], y, num = 0, j = 1;
        while (x != 0) {
            y = (x % 10) * 2;
            x = x / 10;
            if (y > 9) {
                num += (y % 10) * j;
                j *= 10;
                num += (y / 10) * j;
            } else {
                num += (y % 10) * j;
            }
            j *= 10;
        }
        listOfSequence.push_back(num);
    }
    return listOfSequence;
}

int FirstProblemB() {
    for (int i = 10; i < 100; i++) {
        vector<unsigned long long int> v = FirstProblemA(31, i);
        for (auto a: v) {
            unsigned long long int x = a, y, num = 0, j = 1, q = 0;
            while (x != 0 && i < 27) {
                y = x % 10;
                x /= 10;
                num += y * j;
                j *= 10;
                q++;
            }
            if(to_string(num)==MAGIC0)
            {

            }

        }
    }
}


int main() {
    vector<vector<string>> vectorOfGames;
    ifstream File("jatszmak.txt");
    string Line;
    while (getline(File, Line)) {
        stringstream ss(Line);
        string s;
        vector<string> vectorOfMovesInGame;
        boost::split(vectorOfMovesInGame, Line, boost::is_any_of("\t"));
        vectorOfGames.push_back(vectorOfMovesInGame);
    }
    File.close();

    int n;
    cin >> n;
    cout << FirstProblemA(n, 1)[n];
    return 0;
}
