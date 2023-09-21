
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
int AITurn(char gF[3][3]){
    for (int i = 0; i < 3; ++i){
        if (gF[i][0] == gF[i][1] and gF[i][1] == 'O' and gF[i][2] == '_'){
            char *gF_address = &gF[i][2];
            *gF_address = 'O';
            return 0;
        }
        if (gF[i][1] == gF[i][2] and gF[i][1] == 'O' and gF[i][0] == '_'){
            char *gF_address = &gF[i][0];
            *gF_address = 'O';

            return 0;
        }
        if (gF[i][2] == gF[i][0] and gF[i][0] == 'O' and gF[i][1] == '_'){
            char *gF_address = &gF[i][1];
            *gF_address = 'O';
            return 0;
        }
    }
    for (int i = 0; i < 3; ++i){
        if (gF[0][i] == gF[1][i] and gF[1][i] == 'O' and gF[2][i] == '_'){
            char *gF_address = &gF[2][i];
            *gF_address = 'O';
            return 0;
        }
        if (gF[1][i] == gF[2][i] and gF[1][i] == 'O' and gF[0][i] == '_'){
            char *gF_address = &gF[0][i];
            *gF_address = 'O';
            return 0;
        }
        if (gF[2][i] == gF[0][i] and gF[0][i] == 'O' and gF[1][i] == '_'){
            char *gF_address = &gF[1][i];
            *gF_address = 'O';
            return 0;
        }
    }
    if (gF[0][0] == gF[1][1] and gF[0][0] == 'O' and gF[2][2] == '_'){
        char *gF_address = &gF[2][2];
        *gF_address = 'O';
        return 0;
    }
    if (gF[0][0] == gF[2][2] and gF[0][0] == 'O' and gF[1][1] == '_'){
        char *gF_address = &gF[1][1];
        *gF_address = 'O';
        return 0;
    }
    if (gF[2][2] == gF[1][1] and gF[1][1] == 'O' and gF[0][0] == '_'){
        char *gF_address = &gF[0][0];
        *gF_address = 'O';
        return 0;
    }
    if (gF[0][2] == gF[1][1] and gF[1][1] == 'O' and gF[2][0] == '_'){
        char *gF_address = &gF[2][0];
        *gF_address = 'O';
        return 0;
    }
    if (gF[0][2] == gF[2][0] and gF[2][0] == 'O' and gF[1][1] == '_'){
        char *gF_address = &gF[1][1];
        *gF_address = 'O';
        return 0;
    }
    if (gF[2][0] == gF[1][1] and gF[1][1] == 'O' and gF[0][2] == '_'){
        char *gF_address = &gF[0][2];
        *gF_address = 'O';
        return 0;
    }
    for (int i = 0; i < 3; ++i){
        if (gF[i][0] == gF[i][1] and gF[i][1] == 'O' and gF[i][2] == '_'){
            char *gF_address = &gF[i][2];
            *gF_address = 'O';
            return 0;
        }
        if (gF[i][1] == gF[i][2] and gF[i][1] == 'O' and gF[i][0] == '_'){
            char *gF_address = &gF[i][0];
            *gF_address = 'O';
            return 0;
        }
        if (gF[i][2] == gF[i][0] and gF[i][0] == 'O' and gF[i][1] == '_'){
            char *gF_address = &gF[i][1];
            *gF_address = 'O';
            return 0;
        }
    }
    for (int i = 0; i < 3; ++i){
        if (gF[0][i] == gF[1][i] and gF[1][i] == 'X' and gF[2][i] == '_'){
            char *gF_address = &gF[2][i];
            *gF_address = 'O';
            return 0;
        }
        if (gF[1][i] == gF[2][i] and gF[1][i] == 'X' and gF[0][i] == '_'){
            char *gF_address = &gF[0][i];
            *gF_address = 'O';
            return 0;
        }
        if (gF[2][i] == gF[0][i] and gF[0][i] == 'X' and gF[1][i] == '_'){
            char *gF_address = &gF[1][i];
            *gF_address = 'O';
            return 0;
        }
    }
    if (gF[0][0] == gF[1][1] and gF[0][0] == 'X' and gF[2][2] == '_'){
        char *gF_address = &gF[2][2];
        *gF_address = 'O';
        return 0;
    }
    if (gF[0][0] == gF[2][2] and gF[0][0] == 'X' and gF[1][1] == '_'){
        char *gF_address = &gF[1][1];
        *gF_address = 'O';
        return 0;
    }
    if (gF[2][2] == gF[1][1] and gF[1][1] == 'X' and gF[0][0] == '_'){
        char *gF_address = &gF[0][0];
        *gF_address = 'O';
        return 0;
    }
    if (gF[0][2] == gF[1][1] and gF[1][1] == 'X' and gF[2][0] == '_'){
        char *gF_address = &gF[2][0];
        *gF_address = 'O';
        return 0;
    }
    if (gF[0][2] == gF[2][0] and gF[2][0] == 'X' and gF[1][1] == '_'){
        char *gF_address = &gF[1][1];
        *gF_address = 'O';
        return 0;
    }
    if (gF[2][0] == gF[1][1] and gF[1][1] == 'X' and gF[0][2] == '_'){
        char *gF_address = &gF[0][2];
        *gF_address = 'O';
        return 0;
    }
    if (gF[0][0] == gF[2][2] and gF[0][0] == 'X' and gF[1][1] == 'O'){
        char *gF_address = &gF[0][1];
        *gF_address = 'O';
        return 0;
    }
    if (gF[0][2] == gF[2][0] and gF[2][0] == 'X' and gF[1][1] == 'O'){
        char *gF_address = &gF[0][1];
        *gF_address = 'O';
        return 0;
    }
    if (gF[0][0] == '_'){
        char *gF_address = &gF[0][0];
        *gF_address = 'O';
        return 0;
    }
    if (gF[0][2] == '_'){
        char *gF_address = &gF[0][2];
        *gF_address = 'O';
        return 0;
    }
    if (gF[2][2] == '_'){
        char *gF_address = &gF[2][2];
        *gF_address = 'O';
        return 0;
    }
    if (gF[2][0] == '_'){
        char *gF_address = &gF[2][0];
        *gF_address = 'O';
        return 0;
    }
    for (int i = 0; i < 3; ++i){
        for (int j = 0; j < 3; ++j){
            if (gF[i][j] == '_'){
                char *gF_address = &gF[i][j];
                *gF_address = 'O';
            }
        }
    }
}

void Output_game_field(char gF[3][3]){
    std:: cout<<"\n";
    for (int x = 0; x<3; x++){
        std::cout<<"   ";
        for (int y = 0; y<3; y++){
            std:: cout<<gF[x][y];
            if(y!=2){
                std::cout<<" | ";
            }
        }
        std:: cout<<"\n";
        if(x!=2) {
            std::cout << "  ---|---|---  ";
        }
        std:: cout<<"\n";

    }
}
int main(){
    char gF[3][3];
    for(int x = 0; x<3; x++){
        for(int y = 0; y<3; y++){
            gF[x][y] = '_';
        }
    }
    cout<< CheckGameState(gF);
    while(CheckGameState(gF) == "Game's Continue"){
        std::cout<<"F";
        PlayerTurn(gF);
        if(CheckGameState(gF) == "Game's Continue"){
            AITurn(gF);
        }
        Output_game_field(gF);
    }
    std:: cout<< CheckGameState(gF);
}