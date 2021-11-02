#include <string>
#include <vector>
using namespace std;

struct property{
    bool monopoly;
    int housesBuilt;
    int base;
    int house1;
    int house2;
    int house3;
    int apartment;
};

struct player{
    string name;
    int balance;
    int location;
    int playerNum;
    bool bankrupt;
    vector<property*> owned;
    player(string inName, int inPlayerNum){
        name = inName;
        location = 0;
        playerNum = inPlayerNum;
        bankrupt = false;
        balance = 1500;
    }
};

class game{
    public:
        game();
        ~game();
        vector<player*> players;
        vector<property*> properties;
        void createPlayer(string inName);
        void createProperties();
        int checkTurn();
        void playerTurn(int playerNum);
        bool checkEnd();
        bool payPlayer(string name, int ammount);
    private:
        int numPlayers;
        int turn;
        int parking;
        int round;
};