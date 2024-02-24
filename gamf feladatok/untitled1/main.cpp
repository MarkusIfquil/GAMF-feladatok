#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;
vector<string> locationDatas;

struct location {
    int id{};
    string id_letters;
    float lat{};
    float lon{};
    float area{};
    long int population{};
    string name;
    int distanceFromK{};
    int distanceFromS{};
};

vector<struct location> locations;

int main() {
    ifstream citiesFile("telepules.txt");
    ifstream citiesName("megyek.txt");
    string locationData;
    while (getline(citiesFile, locationData)) {
        stringstream ss(locationData);
        string s;
        while (getline(ss, s, ' ')) {
            locationDatas.push_back(s);
        }
    }

    for (int i = 0; i < locationDatas.size(); i += 9) {
        location l;
        l.id = stoi(locationDatas[i]);
        l.id_letters = locationDatas[i + 1];
        l.lat = stof(locationDatas[i + 2]);
        l.lon = stof(locationDatas[i + 3]);
        l.area = stof(locationDatas[i + 4]);
        l.population = stoi(locationDatas[i + 5]);
        l.name = locationDatas[i + 6];
        l.distanceFromK = stoi(locationDatas[i + 7]);
        l.distanceFromS = stoi(locationDatas[i + 8]);
        locations.push_back(l);
    }

    vector<pair<long int, string>> MegyeTelepulesPairs;
    int dumb = 0;
    for (const location &l: locations) {
        if (MegyeTelepulesPairs.empty()) {
            pair<long int, string> p;
            p.first = l.population;
            p.second = l.id_letters;
            MegyeTelepulesPairs.push_back(p);
        } else {
            bool found = false;
            for (auto &MegyeTelepulesPair: MegyeTelepulesPairs) {
                if (MegyeTelepulesPair.second == l.id_letters) {
                    MegyeTelepulesPair.first += l.population;
                    found = true;
                    break;
                }
            }
            if (!found) {
                pair<long int, string> p;
                p.first = l.population;
                p.second = l.id_letters;
                MegyeTelepulesPairs.push_back(p);
            }
        }
    }

    sort(MegyeTelepulesPairs.begin(), MegyeTelepulesPairs.end());

    /*
    for(location l:locations)
    {
        cout<<l.id <<" "
        <<l.id_letters <<" "
        <<l.lat <<" "
        <<l.lon <<" "
        <<l.area <<" "
        <<l.population <<" "
        <<l.name <<" "
        <<l.distanceFromK <<" "
        <<l.distanceFromS <<"\n"
        ;
    }
    */


    for (auto p: MegyeTelepulesPairs) {
        cout << p.first << "-" << p.second << "\n";
    }

    citiesFile.close();
    citiesName.close();
}
