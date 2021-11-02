#include "game.hpp"
#include <string>
#include <iostream>
using namespace std;
game::game(){
    createProperties();
    numPlayers = 0;
    turn = 0;
    //cout << "Turn: " << turn << endl;
    round = 0;
    parking = 50;
}
game::~game(){
}
void game::createPlayer(string inName){
    int inPlayerNum = numPlayers;
    player* newPlayer = new player(inName, inPlayerNum);
    players.push_back(newPlayer);
    numPlayers++;
}
int game::checkTurn(){
    int curTurn = turn;
    //cout << "Turn: " << curTurn << endl;
    return curTurn;
}
bool game::payPlayer(string name, int ammount){
    bool found = false;
    player* temp;
    int tempBal;
    for(int i=0; i<numPlayers; i++){
        if(name.compare(players[i]->name) == 1){
            temp = players[i];
            tempBal = temp->balance;
            temp->balance = tempBal + ammount;
            found = true;
            cout << "Paying: " << temp->name << " " << ammount << endl;
            cout << "Balance of " << temp-> name << " is " << temp->balance << endl;
            players[i] = temp;
        }
    }
    return found;
}
void game::createProperties(){

}
bool game::checkEnd(){
    //Infinite game
    return false;
}
void menu(){
    cout << "--- Enter Number for Selection ---" << endl;
    cout << "1: Pay Player" << endl;
    cout << "2: Recieve Money" << endl;
    cout << "3: Pay Money" << endl;
    cout << "4: Free Parking" << endl;
    cout << "5: Purchase Property" << endl;
    cout << "6: Purchase Building" << endl;
    cout << "7: End Turn" << endl;
    cout << "8: Admin" << endl;
    return;
}
void game::playerTurn(int playerNum){
    if(turn == 0){
        round++;
    }
    //cout << "playerNum: " << playerNum << endl;
    //cout << "Round: " << round << endl;
    player* curPlayer = players[playerNum];
    //cout << " test" << endl;
    cout << "Round: " << round << endl;
    cout << "Player: " << curPlayer->name << " Balance: " << curPlayer->balance << endl;
    bool curTurn = true;
    bool entry = false;
    int selection;
    int num;
    int tempBal;
    string name;
    string line;
    while(curTurn == true){
        entry = false;
        menu();
        cin >> selection;
        switch(selection){
            case 1:{
                while(entry == false){
                    cin.clear();
                    fflush(stdin);
                    cout << "Enter player name" << endl;
                    cin.clear();
                    fflush(stdin);
                    getline(cin, line);
                    name = line;
                    cin.clear();
                    fflush(stdin);
                    cout << "Enter ammount" << endl;
                    cin.clear();
                    fflush(stdin);
                    getline(cin, line);
                    num = stoi(line);
                    if(num>curPlayer->balance){
                        cout << "Not enough money in the bank" << endl;
                    }
                    else{
                        entry = payPlayer(name, num);
                        if(entry == false){
                            cout << "Error. Incorrect Entry." << endl;
                        }
                        else{
                            curPlayer->balance = tempBal - num;
                            cout << "Balance of playing player " << curPlayer-> name << " is " << curPlayer->balance << endl;
                        }
                    }
                }
                break;
            }
            case 2:{
                while(entry == false){
                    cout << "Enter Dollar Amount" << endl;
                    cin >> num;
                    if(num > 0){
                        curPlayer->balance += num;
                        entry = true;
                    }
                    else{
                        cout << "Error. Incorrect Entry" << endl;
                    }
                }
                break;
            }
            case 3:{
                while(entry == false){
                    cout << "Enter Dollar Amount" << endl;
                    cin >> num;
                    if(num > 0){
                        curPlayer->balance -= num;
                        parking += num;
                        entry = true;
                    }
                    else{
                        cout << "Error. Incorrect Entry" << endl;
                    }
                }
                break;
            }
            case 4:{
                curPlayer->balance += parking;
                parking = 50;
                break;
            }
            case 5:{
                break;

            }
            case 6:{
                break;
            }
            case 7:{
                curTurn = false;
                break;
            }
        }
    }
    //cout << "Number of players: " << numPlayers << endl;
    if(playerNum < numPlayers - 1){
        turn++;
        //cout << "Increased turn to: " << turn << endl;
        return;
    }
    else{
        turn = 0;
        //cout << "Reset turn to: " << turn << endl;
        return;
    }    
}