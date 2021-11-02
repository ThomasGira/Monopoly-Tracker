#include <iostream>
#include "game.hpp"
#include <cstdlib>
using namespace std;

int main(){
    game monopoly;

    cout << "Welcome to Monopoly!" << endl;
    
    int selection;
    string playerName;
    string insert;
    bool finished = false;
    while(finished == false){
        cout << "Enter 1 to enter addidtional player or 2 to start game" << endl;
        cin.clear();
        fflush(stdin);
        getline(cin,insert);
        selection = stoi(insert);
        if(selection == 1){
            cout << "Enter Player Name" << endl;
            getline(cin,playerName);
            monopoly.createPlayer(playerName);
            finished = false;
        }
        else if(selection == 2){
            finished = true;
        }
        else{
            cout << "Error. Incorrect Entry" << endl;
            finished = false;
        }
    }
    bool end = false;
    while(end == false){
        int playerNum = monopoly.checkTurn();
        //cout << "playerNum: " << playerNum << endl;
        monopoly.playerTurn(playerNum);
        cout << " test complete" << endl;
        end = monopoly.checkEnd();
    }
}