#include <iostream>
#include <fstream>

#define MAGIC_NUM 1310438493
using namespace std;

long int gcd(long int a, long int b) {
    long int x;
    while (b) {
        x = a % b;
        a = b;
        b = x;
    }
    return a;
}

int main() {
    string Line;
    int RelativePrimes = 0;
    ifstream Numbers("szamok.txt");
    while (!Numbers.eof()) {
        getline(Numbers, Line);
        long int number = stol(Line);
        if (gcd(number, MAGIC_NUM) == 1) {
            RelativePrimes++;
        }
    }

    Numbers.close();
    cout << RelativePrimes;
    return 0;
}
