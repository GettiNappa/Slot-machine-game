#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

string gameboard [3] [3];  //Tvådimensionell array som representerar spelfältet
int playerWins = 0;
int accbalance = 0;
int deposit = 0;
int bet = 0;
char replay = 'y';



int winMoneyCounterFunc(int x) {    //Tar emot linecounter, räknar ut vinstsumman och returnerar den.

    int winMoney = 0;

            if (x > 5){
            winMoney = bet*10;
            cout << "Congratulations! You won the jackpot! ";
            }

            else if (x == 5){
                winMoney = bet*7;
                cout << "Congratulations! You had 5 rows right! ";
            }
            else if (x == 4){
                winMoney = bet*5;
                cout << "Congratulations! You had 4 rows right! ";
            }
            else if (x == 3){
                winMoney = bet*4;
                cout << "Congratulations! You had 3 rows right! ";
            }
            else if (x == 2){
                winMoney = bet*3;
                cout << "Congratulations! You had 2 rows right! ";
            }
            else if (x == 1){
                winMoney = bet*2;
                cout << "Congratulations! You had 1 rows right! ";
            }
            else {
                winMoney == 0;
                cout <<endl<<endl;
                cout << "Better luck next time. ";
            }

            cout <<endl<<endl;

            return winMoney;
}
void gameBoardFunc(){           //Skriver ut spelfältet.
        string symbolsAOX [3];
                symbolsAOX [0] = "A";
                symbolsAOX [1] = "O";
                symbolsAOX [2] = "X";

        for(int a = 0; a<3; a++){    //Fyller string gameboard med symbolerna från string symbolsAOX.
            for(int i = 0; i<3; i++){
                int randomizer = rand() % 3;
                cout << "|" << symbolsAOX[randomizer];
                gameboard[a][i] = symbolsAOX[randomizer];

            }
        cout << "|";
        cout <<endl;
        }
        cout <<endl;
        }
void replayFunc() {     //Ger spelaren möjlighetet att spela igen, och instruerar spelaren hur spelet avslutas.
            cout << "If you want to play again, press y and then Enter" << endl;
            cout << "To exit the game, simply close this window. " << endl;     //Operativsystemets funktioner förenklar koden
            cin >> replay;            //då spelaren skriver "y" loopas spelet och några värden nollställs
            cout <<endl<<endl;
}
void depositFunc(int x) { //Om spelaren har satt in en giltig summa adderas den till kontots saldo.

    if( x == 500 || x == 300 || x == 100 ){
    accbalance += x;
    }

}

int main(){

    cout << endl << endl;
    cout << "Welcome!" << endl << endl;

    while( replay == 'y') {
    srand(time(NULL));
    bet = 0;
    int linecounter = 0;

        while( deposit != 500 && deposit !=300 && deposit != 100 || accbalance < 1 ) {  //Utförs ej om det redan finns pengar
        cout << endl << endl;
        cout << "Please insert money (100, 300 or 500 Kr) and press Enter to continue!";
        cout << endl << endl;
        cin >> deposit;

        depositFunc(deposit);                                                         //Räknar ut saldot på spelarens konto

        }

        cout << "Your account balance is:" << accbalance << endl;
        cout << endl << endl;

        cout << "Choose your bet to start playing!";
        cout << endl << endl;

        cin >> bet;
        cout << endl << endl;

        while (bet > accbalance || bet == 0 || bet < 0)   { //Kontrollerar att insatsen är giltig
        cout << "Please choose a valid bet.";
        cout << endl << endl;

        cin >> bet;
        cout << endl << endl;

        }
        accbalance = accbalance-bet;        //Insatsen tas från kontot

        gameBoardFunc();                    //Kallar på spelplanen

        for (int y = 0; y < 3; y++){
            if (gameboard[0][y] == gameboard[1][y] && gameboard[0][y] == gameboard[2][y]){ //Letar efter vinst på lodräta linjer

                linecounter++;
            }
        }
        for (int x = 0; x < 3; x++){
            if (gameboard[x][0] == gameboard[x][1] && gameboard[x][0] == gameboard[x][2]){ //Letar efter vinst på vågräta linjer

                linecounter++;
            }
        }


        if (gameboard [0][0] == gameboard [1][1] && gameboard [0][0] == gameboard [2][2]){ //Letar vinst diagonalt vänster till höger
            linecounter++;
        }

        if (gameboard [0][2] == gameboard [1][1] && gameboard [0][2] == gameboard [2][0]){ //Letar vinst diagonalt höger till vänster
            linecounter++;
        }

            //cout << linecounter <<endl<<endl; //DEBUG: Kollar att antalet vinstlinjer stämmer

            int winSum = 0;
            winSum = winMoneyCounterFunc(linecounter);   //Linecounter skickas till funktionen för att få ut vinstsumman (winSum).

            accbalance += winSum;                        //
            cout << "Your account balance is now: " << accbalance;
            cout <<endl<<endl;

            replayFunc();   //Frågar spelaren om han/hon vill spela igen

    }
}
