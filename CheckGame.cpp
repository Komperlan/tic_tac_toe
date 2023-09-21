#include <iostream>
#include <string>


using namespace std;


string CheckGameState(char gF[3][3]) {
    int n,m,flag;
    n = 3;
    m = 3;
    flag = 0;
    if (((gF[0][0] == 'X') & (gF[0][1] == 'X') & (gF[0][2] == 'X'))
        || ((gF[1][0] == 'X') & (gF[1][1] == 'X') & (gF[1][2] == 'X'))
        || ((gF[2][0] == 'X') & (gF[2][1] == 'X') & (gF[2][2] == 'X'))
        || ((gF[0][0] == 'X') & (gF[1][0] == 'X') & (gF[2][0] == 'X'))
        || ((gF[0][1] == 'X') & (gF[1][1] == 'X') & (gF[2][1] == 'X'))
        || ((gF[0][2] == 'X') & (gF[1][2] == 'X') & (gF[2][2] == 'X'))
        || ((gF[0][0] == 'X') & (gF[1][1] == 'X') & (gF[2][2] == 'X'))
        || ((gF[0][2] == 'X') & (gF[1][1] == 'X') & (gF[2][0] == 'X'))) {
        flag = 1;
        return "Player's_win";
    }
    if (((gF[0][0] == 'O') & (gF[0][1] == 'O') & (gF[0][2] == 'O'))
        || ((gF[1][0] == 'O') & (gF[1][1] == 'O') & (gF[1][2] == 'O'))
        || ((gF[2][0] == 'O') & (gF[2][1] == 'O') & (gF[2][2] == 'O'))
        || ((gF[0][0] == 'O') & (gF[1][0] == 'O') & (gF[2][0] == 'O'))
        || ((gF[0][1] == 'O') & (gF[1][1] == 'O') & (gF[2][1] == 'O'))
        || ((gF[0][2] == 'O') & (gF[1][2] == 'O') & (gF[2][2] == 'O'))
        || ((gF[0][0] == 'O') & (gF[1][1] == 'O') & (gF[2][2] == 'O'))
        || ((gF[0][2] == 'O') & (gF[1][1] == 'O') & (gF[2][0] == 'O'))) {
        flag = 1;
        return "AI's_win";
    }


    int count_continue;
    count_continue = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((gF[i][j] == '_') & (flag = 0)){
                count_continue ++;
            }
        }
    }
    if (count_continue>0 & flag == 0){
        return "Game's Continue";
    }


    int count_draw;
    count_draw = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((gF[i][j] != '_') & (flag = 0)){
                count_draw ++;
            }
        }
    }
    if (count_draw == 9){
        return "Draw";
    }
}