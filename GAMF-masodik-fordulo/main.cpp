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
    reverse(magicVector.begin(), magicVector.end());
}

vector<vector<int>> FirstProblemA(int n, int start, bool IsA) {
    vector<vector<int>> listOfSequence;
    vector<int> startVector;
    int a = start;
    while (a != 0) {
        startVector.push_back(a % 10);
        a /= 10;
    }
    reverse(startVector.begin(), startVector.end());
    listOfSequence.push_back(startVector);
    if (IsA) {
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
    } else {
        for (int i = 1; i < n; i++) {
            vector<int> x = listOfSequence[i - 1];
            int sum = 0;
            for (int q: x) {
                sum += q;
            }
            x.push_back(sum);
            listOfSequence.push_back(x);
        }
    }
    return listOfSequence;
}

int FirstProblemB() {
    for (int i = 10; i < 100; i++) {
        vector<vector<int>> triedSequence = FirstProblemA(31, i, true);
        for (const auto &a: triedSequence) {
            int count = 0;
            vector<int> str1;
            for (int j: a)
                str1.push_back(j);
            std::reverse(str1.begin(), str1.end());
            for (int q = 0; q < magicVector.size(); q++) {
                if (str1.size() < magicVector.size()) break;
                if (magicVector[q] != str1[q]) break;
                count++;
            }
            if (count == 27) return i;
        }
    }
}

int main() {
    enterMagicIntoVector();
    int n = 21;
    vector<vector<int>> t = FirstProblemA(n, 1, true);
    cout<<"1.a) ";
    for (int i: t[n - 1])
        cout << i;
    cout << "\n1.b) " << FirstProblemB() <<"\n1.c) ";

    t = FirstProblemA(31,11,false);
    for (int i: t[30])
        cout << i;
    return 0;
}
