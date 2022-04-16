#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void rules() {

    cout << "\t\tThese are the rules for the game:" << endl;
    cout << "\n\t\t1. Your starting balance MUST be an integer" << endl;
    cout << "\t\t1. Betting amount MUST be less that your total balance AND an integer" << endl;
    cout << "\t\t2. The number that you guess MUST be between 1 and 10 inclusive" << endl;
    cout << "\t\t3. If you win the game, you get twice the amount of money that you betted added to your balance" << endl;
    cout << "\t\t4. If you lose the game, you will lose the amount of money that you betted" << endl;
    cout << "\t\t5. When you have no money left, the game will quit\n" << endl;
}



int main()
{

    string playerName;
    int playerMoney;
    int bettingMoney;
    int guess;
    int dice;
    char choice;

    srand(time(0));

    cout << "\t\tWelcome To The Casino Game!\n\n" << endl;

    cout << "Please enter your name: ";
    getline(cin, playerName);

    cout << "Hello, " << playerName << "! Please deposit your starting balance (Integer will be converted into £): ";
    cin >> playerMoney;

    do {

        system("clear");

        rules();
        cout << "Your current balance is: £" << playerMoney << endl;

        do {
            cout << "Enter amount of money that you want to bet (Integer will be converted into £): ";
            cin >> bettingMoney;

            if(bettingMoney > playerMoney) {

                cout << "Betting money is more that your total money available! Please re-enter betting money: ";
                cin >> bettingMoney;

            }
        } while (bettingMoney > playerMoney);

        do
        {
            cout << "Please enter your guess: ";
            cin >> guess;

            if(guess < 0 || guess > 10) {

                cout << "Invalid guess! Please re-enter your guess: ";
                cin >> guess;
            }

        } while (guess < 0 || guess > 10);

        dice = rand() % 10 + 1;

        if(guess == dice){

            playerMoney = playerMoney + (bettingMoney * 2);

            cout << "Congratulations! You won the Casino game! You won: £" << (bettingMoney * 2) << ". Your new balance is: £" << playerMoney << endl;
            cout << "The winning number was: " << dice << endl;
        } else {

            playerMoney = playerMoney - bettingMoney;

            cout << "Sorry bad luck this time! You lost: £" << bettingMoney << ". Your new amount is: £" << playerMoney << endl;
            cout << "The winning number was: " << dice << endl;
        }

        if(playerMoney == 0) {

            cout << "You have no more money to play anymore rounds!" << endl;
            break;
        }

        cout << "Do you want to play again (y/n) ?: ";
        cin >> choice;

    }while(choice == 'Y' || choice == 'y');

    cout << "\nThanks for playing! See you next time!" << endl;



    return 0;
}