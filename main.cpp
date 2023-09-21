#include<iostream>

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