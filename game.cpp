#include "pthread.h"

#include "iostream"

#include "stdio.h"

#include "stdlib.h"

#include "unistd.h"

#include "bits/stdc++.h"

#include "ctime"

#include "cstdlib"

#include <sys/ipc.h>

#include <sys/shm.h>

#include<iostream>

#include<cstdlib>

#include<fstream>

#include<iomanip>

using namespace std;

float mem;
int temp;
//timer fuction

void time()

{

    int sec_prev = 0;

    while (1)

    {

        int seconds, minutes, hours;

        string str;

 

        //storing total seconds

        time_t total_seconds = time(0);

 

        //getting values of seconds, minutes and hours

        struct tm* ct = localtime(&total_seconds);

 

        seconds = ct->tm_sec;

        minutes = ct->tm_min;

        hours = ct->tm_hour;

 

        //converting it into 12 hour format

        if (hours >= 12)

            str = "PM";

        else

            str = "AM";

        hours = hours > 12 ? hours - 12 : hours;

 

 

        //printing the result

        if (seconds == sec_prev + 1 || (sec_prev == 59 && seconds == 0))

        {

            system("clear");

            cout << (hours < 10 ? "0" : "") << hours << ":" << (minutes < 10 ? "0" : "") << minutes << ":" << (seconds < 10 ? "0" : "") << seconds << " " << str << endl;

            break;

        }

 

        sec_prev = seconds;

 

    }

}

void displaymemory(float n)

{

    time();

                	 cout << "\n\t------------------------\n\tTik Tak Toe Game taken Ram : " << 6 << endl;
        cout << "\tremaining RAM = " << temp-6 << "gb" << endl;
         cout << "\n\t------------------------\n";

        cout << "\n\n";

}

 

 

int main_menu();

void play_game();

void credits();

void rules();

int score();

void winning_condition();

void lose_condition();

void draw_condition();

bool player1_turn();

bool player2_turn();

bool machine_turn();

bool toss(bool a1, bool b1);

bool tosspvm(bool a7, bool b7);

void pvp(bool a5, bool b5);

void pvm(bool a, bool b);

void askPlayer();

char arr[9] = { '-', '-', '-', '-', '-', '-', '-', '-', '-' };

int main_menu()

{
		
		displaymemory(4);
                int select;
	
                cout << "\t\t\t\t\t\t\tMAIN MENU\n";

                cout << "\t\t\t\t\t\t\t---------\n";

                cout << "Press 1 to Play.\nPress 2 to check Score.\nPress 3 for Instructions/Rules of the game.\nPress 4 for Credits.\nPress 5 to Exit.\n";

                cin >> select;

                switch (select)

                {

                case 1:

                                play_game();

                                break;

                case 2:

                                score();

                                askPlayer();

                                break;

                case 3:

                                rules();

                                askPlayer();

                                break;

                case 4:

                                credits();

                                askPlayer();

                                break;

                case 5:

                                exit(0);

                                break;

                default:

                                cout << "Invalid Input.\nEnter Again!\n";

                                main_menu();

                }
return 0;
}

void play_game()
{

                bool a2 = true, b2 = true;

                int choice;

                cout << "\n\t\t\t\t\t\t\t  MODES\n";

                cout << "\t\t\t\t\t\t\t  -----\n";

                cout << "Press 1 for Player Vs Machine.\nPress 2 for Player Vs Player.\n";

                cin >> choice;

                switch (choice)

                {

                case 1:

                                cout << "Starting Player Vs Machine:-\n";

                                tosspvm(a2, b2);

                                draw_condition();

                                break;

                case 2:

                                cout << "Starting Player Vs Player:-\n";

                                toss(a2, b2);

                                draw_condition();

                                break;

                default:

                                cout << "Invalid Input.\nEnter Again!\n";

                                play_game();

                }

}

bool tosspvm(bool a7, bool b7)

{

                int r1;

                r1 = rand() % 9 + 1;

                if (r1 % 2 == 0)

                {

                                cout << "\nPlayer 1 won the toss.\n";

                                a7 = true;

                                b7 = false;

                                pvm(a7, b7);

                }

                else

                {

                                cout << "Machine won the toss.\n";

                                b7 = true;

                                a7 = false;

                                pvm(a7, b7);

                }

                return 1;

}

bool toss(bool a1, bool b1)

{

                int random = rand() % 9 + 1;

                if (random % 2 == 0)

                {

                                cout << "\nPlayer 1 won the toss.\n";

                                a1 = true;

                                b1 = false;

                                pvp(a1, b1);

                }

                else

                {

                                cout << "\nPlayer 2 won the toss.\n";

                                b1 = true;

                                a1 = false;

                                pvp(a1, b1);

                }

                return 1;

}

void pvp(bool a5, bool b5)

{

                for (int g = 0; g < 3; g++)

                {

                                for (int h = 0; h < 3; h++)

                                {

                                                if (a5 == true)

                                                {

                                                                cout << "Input Player 1:\n";

                                                                player1_turn();

                                                                b5 = true;

                                                                a5 = false;

                                                }

                                                else if (b5 == true)

                                                {

                                                                cout << "Input Player 2:\n";

                                                                player2_turn();

                                                                a5 = true;

                                                                b5 = false;

                                                }

                                }

                }

}

void pvm(bool a, bool b)

{

                for (int t = 0; t < 3; t++)

                {

                                for (int o = 0; o < 3; o++)

                                {

                                                if (a == true)

                                                {

                                                                cout << "\nInput player 1:-\n";

                                                                player1_turn();

                                                                b = true;

                                                                a = false;

                                                }

                                                else if (b == true)

                                                {

                                                                cout << "\nInput Machine:-\n";

                                                                machine_turn();

                                                                a = true;

                                                                b = false;

                                                }

                                }

                }

}

bool player1_turn()

{

                int b1 = 0;

                do

                {

                                cout << "Enter the block number: ";

                                cin >> b1;

                                if (arr[b1 - 1] == 'X' || arr[b1 - 1] == 'O')

                                {

                                                cout << "Invalid Input.\nEnter Again!\n";

                                }

                                else if (b1 < 1 || b1 > 9)

                                {

                                                cout << "Invalid Input.\nEnter Again!\n";

                                }

                } while ((arr[b1 - 1] == 'X' || arr[b1 - 1] == 'O') || (b1 < 1 || b1 > 9));

                arr[b1 - 1] = 'X';

                system("cls");

                cout << "   **Pattern**" << endl << "\t";

                for (int i = 0; i < 9; i++)

                {

                                if (i == 3 || i == 6)

                                {

                                                cout << endl << "\t----------\n\t";

                                }

                                cout << arr[i];

                                if (i == 0 || i == 1 || i == 3 || i == 4 || i == 6 || i == 7)

                                {

                                                cout << setw(2) << "|" << setw(2);

                                }

                }

                cout << endl;

                winning_condition();

                return 1;

}

bool player2_turn()

{

                int b2 = 0;

                do

                {

                                cout << "Enter the block number 2: ";

                                cin >> b2;

                                if (arr[b2 - 1] == 'X' || arr[b2 - 1] == 'O')

                                {

                                                cout << "Invalid Input.\nEnter Again!\n";

                                }

                                else if (b2 < 1 || b2 > 9)

                                {

                                                cout << "Invalid Input.\nEnter Again!\n";

                                }

                } while ((arr[b2 - 1] == 'X' || arr[b2 - 1] == 'O') || (b2 < 1 || b2 > 9));

                arr[b2 - 1] = 'O';

                system("cls");

                cout << "   **Pattern**" << endl << "\t";

                for (int i = 0; i < 9; i++)

                {

                                if (i == 3 || i == 6)

                                {

                                                cout << endl << "\t----------\n\t";

                                }

                                cout << arr[i];

                                if (i == 0 || i == 1 || i == 3 || i == 4 || i == 6 || i == 7)

                                {

                                                cout << setw(2) << "|" << setw(2);

                                }

                }

                cout << endl;

                winning_condition();

                return 1;

}

bool machine_turn()

{

                int b3=0;

                do

                {

                                b3 = rand() % 9 + 1;

                } while (arr[b3-1] == 'X' || arr[b3-1] == 'O');

                arr[b3-1] = 'O';

                system("cls");

                cout << "   **Pattern**" << endl << "\t";

                for (int i = 0; i < 9; i++)

                {

                                if (i == 3 || i == 6)

                                {

                                                cout << endl << "\t----------\n\t";

                                }

                                cout << arr[i];

                                if (i == 0 || i == 1 || i == 3 || i == 4 || i == 6 || i == 7)

                                {

                                                cout << setw(2) << "|" << setw(2);

                                }

                }

                cout << endl;

                winning_condition();

                return 1;

}

void winning_condition()

{

                int i = 0;

                ofstream rec1;

                int p1 = 0, p2 = 0, dr = 0, null = 0;

                bool player = false;

                rec1.open("record.txt");

                while (i < 9)

                {

                                if (arr[i] == 'X' && arr[i + 1] == 'X' && arr[i + 2] == 'X')

                                {

                                                cout << "Player 1 wins.\n";

                                                player = true;

                                                p1 = p1 + 1;

                                                rec1 << p1 << " " << p2 << " " << dr << " " << null;

 

                                }

                                else if (arr[i] == 'O' && arr[i + 1] == 'O' && arr[i + 2] == 'O')

                                {

                                                cout << "Player 2 wins.\n";

                                                player = true;

                                                p2 = p2 + 1;

                                                rec1 << p1 << " " << p2 << " " << dr << " " << null;

                                }

                                i += 3;

                }

                if (player == false)

                {

                                if (arr[0] == 'X' && arr[3] == 'X' && arr[6] == 'X')

                                {

                                                cout << "Player 1 wins.\n";

                                                player = true;

                                                p1 = p1 + 1;

                                                rec1 << p1 << " " << p2 << " " << dr << " " << null;

                                }

                                else if (arr[1] == 'X' && arr[4] == 'X' && arr[7] == 'X')

                                {

                                                cout << "Player 1 wins.\n";

                                                player = true;

                                                p1 = p1 + 1;

                                                rec1 << p1 << " " << p2 << " " << dr << " " << null;

                                }

                                else if (arr[2] == 'X' && arr[5] == 'X' && arr[8] == 'X')

                                {

                                                cout << "Player 1 wins.\n";

                                                player = true;

                                                p1 = p1 + 1;

                                                rec1 << p1 << " " << p2 << " " << dr << " " << null;

                                }

                                else if (arr[0] == 'O' && arr[3] == 'O' && arr[6] == 'O')

                                {

                                                cout << "Player 2 wins.\n";

                                                player = true;

                                                p2 = p2 + 1;

                                                rec1 << p1 << " " << p2 << " " << dr << " " << null;

                                }

                                else if (arr[1] == 'O' && arr[4] == 'O' && arr[7] == 'O')

                                {

                                                cout << "Player 2 wins.\n";

                                                player = true;

                                                p2 = p2 + 1;

                                                rec1 << p1 << " " << p2 << " " << dr << " " << null;

                                }

                                else if (arr[2] == 'O' && arr[5] == 'O' && arr[8] == 'O')

                                {

                                                cout << "Player 2 wins.\n";

                                                player = true;

                                                p2 = p2 + 1;

                                                rec1 << p1 << " " << p2 << " " << dr << " " << null;

                                }

                                else if (arr[0] == 'X' && arr[4] == 'X' && arr[8] == 'X')

                                {

                                                cout << "Player 1 wins.\n";

                                                player = true;

                                                p1 = p1 + 1;

                                                rec1 << p1 << " " << p2 << " " << dr << " " << null;

                                }

                                else if (arr[2] == 'X' && arr[4] == 'X' && arr[6] == 'X')

                                {

                                                cout << "Player 1 wins.\n";

                                                player = true;

                                                p1 = p1 + 1;

                                                rec1 << p1 << " " << p2 << " " << dr << " " << null;

                                }

                                else if (arr[0] == 'O' && arr[4] == 'O' && arr[8] == 'O')

                                {

                                                cout << "Player 2 wins.\n";

                                                player = true;

                                                p2 = p2 + 1;

                                                rec1 << p1 << " " << p2 << " " << dr << " " << null;

                                }

                                else if (arr[2] == 'O' && arr[4] == 'O' && arr[6] == 'O')

                                {

                                                cout << "Player 2 wins.\n";

                                                player = true;

                                                p2 = p2 + 1;

                                                rec1 << p1 << " " << p2 << " " << dr << " " << null;

                                }

                }

                if (player == false)

                {

                                dr = dr + 1;

                                rec1 << p1 << " " << p2 << " " << dr << " " << null;

                }

                rec1.close();

                lose_condition();

}

void lose_condition()

{

                int j = 0;

                bool loss = false;

                while (j < 9)

                {

                                if (arr[j] == 'X' && arr[j + 1] == 'X' && arr[j + 2] == 'X')

                                {

                                                cout << "Player 2 lose.\n";

                                                loss = true;

                                                askPlayer();

 

                                }

                                else if (arr[j] == 'O' && arr[j + 1] == 'O' && arr[j + 2] == 'O')

                                {

                                                cout << "Player 1 lose.\n";

                                                loss = true;

                                                askPlayer();

                                }

                                j += 3;

                }

                if (loss == false)

                {

                                if (arr[0] == 'X' && arr[3] == 'X' && arr[6] == 'X')

                                {

                                                cout << "Player 2 lose.\n";

                                                loss = true;

                                                askPlayer();

                                }

                                else if (arr[1] == 'X' && arr[4] == 'X' && arr[7] == 'X')

                                {

                                                cout << "Player 2 lose.\n";

                                                loss = true;

                                                askPlayer();

                                }

                                else if (arr[2] == 'X' && arr[5] == 'X' && arr[8] == 'X')

                                {

                                                cout << "Player 2 lose.\n";

                                                loss = true;

                                                askPlayer();

                                }

                                else if (arr[0] == 'O' && arr[3] == 'O' && arr[6] == 'O')

                                {

                                                cout << "Player 1 lose.\n";

                                                loss = true;

                                                askPlayer();

                                }

                                else if (arr[1] == 'O' && arr[4] == 'O' && arr[7] == 'O')

                                {

                                                cout << "Player 1 lose.\n";

                                                loss = true;

                                                askPlayer();

                                }

                                else if (arr[2] == 'O' && arr[5] == 'O' && arr[8] == 'O')

                                {

                                                cout << "Player 1 lose.\n";

                                                loss = true;

                                                askPlayer();

                                }

                                else if (arr[0] == 'X' && arr[4] == 'X' && arr[8] == 'X')

                                {

                                                cout << "Player 2 lose.\n";

                                                loss = true;

                                                askPlayer();

                                }

                                else if (arr[2] == 'X' && arr[4] == 'X' && arr[6] == 'X')

                                {

                                                cout << "Player 2 loss.\n";

                                                loss = true;

                                                askPlayer();

                                }

                                else if (arr[0] == 'O' && arr[4] == 'O' && arr[8] == 'O')

                                {

                                                cout << "Player 1 lose.\n";

                                                loss = true;

                                                askPlayer();

                                }

                                else if (arr[2] == 'O' && arr[4] == 'O' && arr[6] == 'O')

                                {

                                                cout << "Player 1 lose.\n";

                                                loss = true;

                                                askPlayer();

                                }

                }

}

void draw_condition()

{

                cout << "\nNone of the players have successfully drawn 3-into-3, so the game is drawn.\n";

                askPlayer();

 

}

void askPlayer()

{

                int num;

                cout << "\nPress 1 to exit OR Press any number to continue.";

                cin >> num;

                system("cls");

                if (num == 1)

                {

                                exit(0);

                }

                else

                {

                                for (int i = 0; i < 9; i++)

                                {

                                                arr[i] = '-';

                                }

                                main_menu();

                }

}

int score()

{

                ifstream rec;

                int score1=0, score2=0, drawn=0;

                rec.open("record.txt");

                cout << "\n\t\t\t\t\t\t\t SCORES\n";

                cout << "\t\t\t\t\t\t\t ------";

                rec >> score1;

                cout << "\nGames won by player 1: " << score1 << endl;

                rec >> score2;

                cout << "Games won by player 2: " << score2 << endl;

                rec >> drawn;

                cout << "Games drawn: " << drawn << endl;

                rec.close();

                return 1;

}

void rules()

{

                cout << "\n\t\t\t\t\t\t   INSTRUCTIONS/RULES\n";

                cout << "\t\t\t\t\t\t   ------------------\n";

                cout << "1. There are only two mods : \n    i)Player Vs Player\n   ii)Player Vs Machine\n2. The goal of tic - tac - toe is to be the first player to get three in a row on a 3 - by - 3 grid.\n3. The player who is playing 'X' always goes first.\n4. Players alternate placing Xs and Os on the board until either player has three\n   in a row, horizontally, vertically, or diagonally or until all squares are filled.\n5. If a player is able to draw three Xs or three Os in a row, then that player wins.\n6. If all squares are filledand neither player has made a complete row Xs or Os, then the game is a draw.\n";

}

void credits()

{

                cout << "\n\t\t\t\t\t\t\t CREDITS\n";

                cout << "\t\t\t\t\t\t\t -------\n";


}

 

int main(int argc, char **argv)

{
	
	 temp = stoi(argv[1]);
		
		

                int shared_memory_id;

                key_t key = ftok("shmfile", 65);

                float *shared_memory;

                shared_memory_id = shmget(key, 1024, 0666);

                shared_memory = (float *)shmat(shared_memory_id, NULL, 0);

                mem=shared_memory[0];

                ofstream rec2;

                rec2.open("record.txt");

                rec2 << 0 << " " << 0 << " " << 0 << " " << 0;

                rec2.close();

                cout << "\t\t\t\t\t\tWELCOME TO TIC-TAC-TOE GAME\n";

                cout << "\t\t\t\t\t\t---------------------------\n\n";
		sleep(3);
                main_menu();

        shared_memory[2]=0;

        shared_memory[0]=shared_memory[0]+1;

        return 0;

}
