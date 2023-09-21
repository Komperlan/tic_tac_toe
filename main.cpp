
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int PlayerTurn(char gF[3][3]) {
    int line, column, c = 0;
    bool Flag = false;
    cout << "Сделайте ход" << '\n';
    cin >> line >> column;
    while (not Flag) {
        if (gF[line - 1][column - 1] == '_' and ((line < 4 and line > 0) and (column < 4 and column > 0))) {
            Flag = true;
        } else {
            cout << "Ведите координаты еще раз, сначала строку, потом столбец" << '\n';
            cin >> line >> column;
            c += 1;
            if (c == 10) {
                cout << "Ты тупой? еще раз вводи." << '\n';
                cin >> line >> column;
            }
        }

    }
    if (Flag) {
        char *gF_address = &gF[column - 1][line - 1];
        *gF_address = 'X';

    }
}

int main() {
    PlayerTurn(gF);
}