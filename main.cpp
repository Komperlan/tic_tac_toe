#include <iostream>

using namespace std;

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
}
