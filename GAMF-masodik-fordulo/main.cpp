#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;
string MAGIC0 = "216816212162121681684816816";

vector<int> magicVector;

void enterMagicIntoVector() {
    for (char c: MAGIC0) {
        magicVector.push_back(c - '0');
    }
}

vector<vector<int>> FirstProblemA(int n, int start) {
    vector<vector<int>> listOfSequence;
    vector<int> startVector;
    int a = start;
    while (a != 0) {
        startVector.push_back(a % 10);
        a /= 10;
    }
    listOfSequence.push_back(startVector);
    for (int i = 1; i < n; i++) {
        vector<int> x = listOfSequence[i - 1];
        vector<int> newX;
        for (int q: x) {
            if (q * 2 > 9) {
                newX.push_back((q * 2) / 10);
                newX.push_back((q * 2) % 10);
            } else newX.push_back(q * 2);
        }
        listOfSequence.push_back(newX);
    }
    return listOfSequence;
}

int FirstProblemB() {
    for (int i = 10; i < 100; i++) {
        int count = 0;
        vector<vector<int>> triedSequence = FirstProblemA(31, i);
        for (auto a: triedSequence) {
            unsigned long int k = magicVector.size() - 1;
            for (unsigned long int g = a.size() - 1; g > a.size() - 28; g++) {
                if (a.size() < 27)
                    break;
                if (a[g] == magicVector[k]) {
                    count++;
                }
                k--;
            }
            if (count == 27)
                return i;
            count = 0;
        }

    }
}


int main() {
    enterMagicIntoVector();
    /*
    int n;
    cin >> n;
    vector<vector<int>> t = FirstProblemA(n, 1);
    for (auto a: t) {
        for (int i: a) {
            cout << i;
        }
        cout << "\n";
    }
    */
    cout << FirstProblemB();
    /*

    */
    return 0;
}
