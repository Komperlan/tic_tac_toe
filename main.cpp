#include <iostream>

int main(){
    char gF[3][3];
    for(int x = 0; x<3; x++){
        for(int y = 0; y<3; y++){
            gF[x][y] = '_';
        }
    }

    while(CheckGameState(gF) == "Game`s Continue"){
        PlayerTurn(gF);
        if(CheckGameState(gF) == "Game`s Continue"){
            AIturn(gF);
        }
        Output_game_field(gF);
    }
    std:: cout<< CheckGameState(gF);
}