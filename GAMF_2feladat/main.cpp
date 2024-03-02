#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <sstream>
#include <cmath>
#include <string>

using namespace std;

vector<vector<string>> games;

struct whiteRook1 {
    string position = "a1";
    bool alive = true;
    string name = "WR1";
};
struct whiteRook2 {
    string position = "h1";
    bool alive = true;
    string name = "WR2";
};
struct whiteHorse1 {
    string position = "b1";
    bool alive = true;
    string name = "WH1";
};
struct whiteHorse2 {
    string position = "g1";
    bool alive = true;
    string name = "WH2";
};
struct whiteBishop1 {
    string position = "c1";
    bool alive = true;
    string name = "WB1";
};
struct whiteBishop2 {
    string position = "f1";
    bool alive = true;
    string name = "WB2";
};
struct whiteQueen {
    string position = "d1";
    bool alive = true;
    string name = "WQ";
};
struct whiteKing {
    string position = "e1";
    bool alive = true;
    string name = "WK";
};

struct blackRook1 {
    string position = "a8";
    bool alive = true;
    string name = "BR1";
};
struct blackRook2 {
    string position = "h8";
    bool alive = true;
    string name = "BR2";
};
struct blackHorse1 {
    string position = "b8";
    bool alive = true;
    string name = "BH1";
};
struct blackHorse2 {
    string position = "g8";
    bool alive = true;
    string name = "BH2";
};
struct blackBishop1 {
    string position = "c8";
    bool alive = true;
    string name = "BB1";
};
struct blackBishop2 {
    string position = "f8";
    bool alive = true;
    string name = "BB2";
};
struct blackQueen {
    string position = "d8";
    bool alive = true;
    string name = "BQ";
};
struct blackKing {
    string position = "e8";
    bool alive = true;
    string name = "BK";
};

struct game {
    whiteRook1 WR1;
    whiteRook2 WR2;
    whiteHorse1 WH1;
    whiteHorse2 WH2;
    whiteBishop1 WB1;
    whiteBishop2 WB2;
    whiteQueen WQ;
    whiteKing WK;

    blackRook1 BR1;
    blackRook2 BR2;
    blackHorse1 BH1;
    blackHorse2 BH2;
    blackBishop1 BB1;
    blackBishop2 BB2;
    blackQueen BQ;
    blackKing BK;
};

vector<game> vectorOfGames;
vector<pair<string, string>> vectorOfPairsOfNameAndPosition;

bool canMoveStraight(string position, string whereToMove) {
    if (position[0] == whereToMove[0] || position[1] == whereToMove[1]) return true;
    else return false;
}

bool canMoveDiagonal(string position, string whereToMove) {
    int difference0 = abs(int(position[0]) - int(whereToMove[0]));
    int difference1 = abs(int(position[1]) - int(whereToMove[1]));

    if (difference0 == difference1) return true;
    else return false;
}

bool canMoveL(string position, string whereToMove) {
    int difference0 = abs(int(position[0]) - int(whereToMove[0]));
    int difference1 = abs(int(position[1]) - int(whereToMove[1]));

    if ((difference0 == 1 && difference1 == 2) || (difference0 == 2 && difference1 == 1)) return true;
    else return false;
}

void determinePiece(string &position1, string &position2, string whichToMove, const string &whereToMove) {
    if (whichToMove != " ") {
        if (position1[0] == whichToMove[0] ||
            position1[1] == whichToMove[0]) {
            position1 = whereToMove;
        } else {
            position2 = whereToMove;
        }
    }
}

void moveRook(string &position1, string &position2, const string &whereToMove, string whichToMove) {
    determinePiece(position1, position2, std::move(whichToMove), whereToMove);

    if (canMoveStraight(position1, whereToMove) &&
        !canMoveStraight(position2, whereToMove))
        position1 = whereToMove;
    else
        position2 = whereToMove;
}

void moveHorse(string &position1, string &position2, const string &whereToMove, string whichToMove) {
    determinePiece(position1, position2, std::move(whichToMove), whereToMove);

    if (canMoveL(position1, whereToMove) &&
        !canMoveL(position2, whereToMove))
        position1 = whereToMove;
    else
        position2 = whereToMove;
}

void moveBishop(string &position1, string &position2, const string &whereToMove, string whichToMove) {
    determinePiece(position1, position2, std::move(whichToMove), whereToMove);

    if (canMoveDiagonal(position1, whereToMove) &&
        !canMoveDiagonal(position2, whereToMove))
        position1 = whereToMove;
    else
        position2 = whereToMove;
}

pair<string, string> createPair(int i, game &currentGame) {
    pair<string, string> p;
    switch (i) {
        case 0:
            p.first = currentGame.WR1.name;
            p.second = currentGame.WR1.position;
            break;
        case 1:
            p.first = currentGame.WR2.name;
            p.second = currentGame.WR2.position;
            break;
        case 2:
            p.first = currentGame.WH1.name;
            p.second = currentGame.WH1.position;
            break;
        case 3:
            p.first = currentGame.WH2.name;
            p.second = currentGame.WH2.position;
            break;
        case 4:
            p.first = currentGame.WB1.name;
            p.second = currentGame.WB1.position;
            break;
        case 5:
            p.first = currentGame.WB2.name;
            p.second = currentGame.WB2.position;
            break;
        case 6:
            p.first = currentGame.WQ.name;
            p.second = currentGame.WQ.position;
            break;
        case 7:
            p.first = currentGame.WK.name;
            p.second = currentGame.WK.position;
            break;
        case 8:
            p.first = currentGame.BR1.name;
            p.second = currentGame.BR1.position;
            break;
        case 9:
            p.first = currentGame.BR2.name;
            p.second = currentGame.BR2.position;
            break;
        case 10:
            p.first = currentGame.BH1.name;
            p.second = currentGame.BH1.position;
            break;
        case 11:
            p.first = currentGame.BH2.name;
            p.second = currentGame.BH2.position;
            break;
        case 12:
            p.first = currentGame.BB1.name;
            p.second = currentGame.BB1.position;
            break;
        case 13:
            p.first = currentGame.BB2.name;
            p.second = currentGame.BB2.position;
            break;
        case 14:
            p.first = currentGame.BQ.name;
            p.second = currentGame.BQ.position;
            break;
        case 15:
            p.first = currentGame.BK.name;
            p.second = currentGame.BK.position;
            break;
        default:
            break;

    }
    return p;
}

void initVector(game &currentGame) {
    for (int i = 0; i < 16; i++) {
        bool isSame = false;
        pair<string, string> p = createPair(i, currentGame);
        if (!vectorOfPairsOfNameAndPosition.empty()) {
            for (auto p0: vectorOfPairsOfNameAndPosition) {
                if (p0.first == p.first) {
                    p0.second = p.first;
                    isSame = true;
                }
            }
        }
        if (!isSame) {
            vectorOfPairsOfNameAndPosition.push_back(p);
        }
    }
}

void moveAPiece(char moved, bool white, game &currentGame, const string &whereToMove, const string &whichToMove) {
    switch (moved) {
        case 'K':
            if (white) currentGame.WK.position = whereToMove;
            else currentGame.BK.position = whereToMove;
            break;
        case 'V':
            if (white) currentGame.WQ.position = whereToMove;
            else currentGame.BQ.position = whereToMove;
            break;
        case 'B':
            if (white) moveRook(currentGame.WR1.position, currentGame.WR2.position, whereToMove, whichToMove);
            else moveRook(currentGame.BR1.position, currentGame.BR2.position, whereToMove, whichToMove);
            break;
        case 'F':
            if (white) moveBishop(currentGame.WB1.position, currentGame.WB2.position, whereToMove, whichToMove);
            else moveBishop(currentGame.BB1.position, currentGame.BB2.position, whereToMove, whichToMove);
            break;
        case 'H':
            if (white) moveHorse(currentGame.WH1.position, currentGame.WH2.position, whereToMove, whichToMove);
            else moveHorse(currentGame.BH1.position, currentGame.BH2.position, whereToMove, whichToMove);
            break;
        default:
            break;
    }
}

void determineWhereToMove(const string &move, string &whereToMove, string &whichToMove) {
    size_t found1 = move.find('x');
    if (found1 == string::npos && move.length() == 3)
        whereToMove = move.substr(1, 2);
    else if (found1 == string::npos && move.length() == 4) {
        whereToMove = move.substr(2, 2);
        whichToMove = move.substr(1, 1);
    } else
        whereToMove = move.substr(2, 2);
}

void killPiece(const string &whereToMove, game &currentGame) {
    for (int p = 0; p < vectorOfPairsOfNameAndPosition.size(); p++) {
        if (vectorOfPairsOfNameAndPosition[p].second == whereToMove) {
            if (vectorOfPairsOfNameAndPosition[p].second == currentGame.WR1.position) currentGame.WR1.alive = false;
            if (vectorOfPairsOfNameAndPosition[p].second == currentGame.WR2.position) currentGame.WR2.alive = false;
            if (vectorOfPairsOfNameAndPosition[p].second == currentGame.WH1.position) currentGame.WH1.alive = false;
            if (vectorOfPairsOfNameAndPosition[p].second == currentGame.WH2.position) currentGame.WH2.alive = false;
            if (vectorOfPairsOfNameAndPosition[p].second == currentGame.WB1.position) currentGame.WB1.alive = false;
            if (vectorOfPairsOfNameAndPosition[p].second == currentGame.WB2.position) currentGame.WB2.alive = false;
            if (vectorOfPairsOfNameAndPosition[p].second == currentGame.WQ.position) currentGame.WQ.alive = false;
            if (vectorOfPairsOfNameAndPosition[p].second == currentGame.WK.position) currentGame.WK.alive = false;
            auto it = std::find(vectorOfPairsOfNameAndPosition.begin(), vectorOfPairsOfNameAndPosition.end(), p);
            vectorOfPairsOfNameAndPosition.erase(p);
        }
    }
}

void movePiece() {
    for (const auto &gamer: games) {
        game currentGame;
        initVector(currentGame);
        int i = 0;
        bool white;
        for (auto move: gamer) {
            if (i % 2 == 0) white = true;
            else white = false;

            string whereToMove;
            string whichToMove = " ";

            determineWhereToMove(move, whereToMove, whichToMove);

            char moved = move[0];

            moveAPiece(moved, white, currentGame, whereToMove, whichToMove);

            i++;
        }
    }
}

int main() {
    string line;
    ifstream File("jatszmak.txt");
    while (getline(File, line)) {
        vector<string> moves;
        string s;
        stringstream ss(line);
        while (getline(ss, s, '\t')) {
            size_t found = s.find('\t');
            if (found == string::npos)
                moves.push_back(s);
        }
        games.push_back(moves);
    }

    string winners;
    int numOfHorseMoves = 0;
    for (const auto &moves: games) {
        if (moves.size() % 2 == 0)
            winners.append("s");
        else
            winners.append("v");

        for (auto move: moves) {
            if (move[0] == 'H') {
                numOfHorseMoves++;
            }
        }
    }
    cout << winners << "\n" << numOfHorseMoves * 4;
    return 0;
}
