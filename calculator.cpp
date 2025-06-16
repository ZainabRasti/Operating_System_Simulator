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

                	 cout << "\n\t------------------------\n\tCalculator has taken Ram : " << 4 << endl;
        cout << "\tremaining RAM = " << mem << "gb" << endl;
         cout << "\n\t------------------------\n";

        cout << "\n\n";

}


 

void calculator()

{

        int shared_memory_id;

                key_t key = ftok("shmfile", 65);

                float *shared_memory;

                shared_memory_id = shmget(key, 1024, 0666);

                shared_memory = (float *)shmat(shared_memory_id, NULL, 0);

                shared_memory[0]=shared_memory[0]+0.5;

                mem=shared_memory[0];

                 cout<<shared_memory[0]<<endl<<endl;

                 

    int option;


    while (true)

    {

                system("clear");
	displaymemory(4);
	
        cout << "Press 1 for addition" << endl;

        cout << "Press 2 for subtraction" << endl;

        cout << "Press 3 for multiplication" << endl;

        cout << "Press 4 for division" << endl;

        cout << "Press 5 to quit" << endl;

        cin >> option;

        if (option == 1)

        {

            int a, b, sum = 0;

            cout << "Enter first number" << endl;

            cin >> a;

            cout << "Enter second number" << endl;

            cin >> b;

            sum = a + b;

            cout << "Sum of a and b is " << sum << endl;

        }

        else if (option == 2)

        {

            int a, b, sub = 0;

            cout << "Enter first number" << endl;

            cin >> a;

            cout << "Enter second number" << endl;

            cin >> b;

            sub = a - b;

            cout << "difference of a and b is " << sub << endl;

        }

        else if (option == 3)

        {

            int a, b, pro = 0;

            cout << "Enter first number" << endl;

            cin >> a;

            cout << "Enter second number" << endl;

            cin >> b;

            pro = a * b;

            cout << "Product of a and b is " << pro << endl;

        }

        else if (option == 4)

        {

            int a, b, div = 0;

            cout << "Enter first number" << endl;

            cin >> a;

            cout << "Enter second number" << endl;

            cin >> b;

            div = a / b;

            cout << "Product of a and b is " << div << endl;

        }

        else if (option == 5)

        {

            shared_memory[1]=0;

                    shared_memory[0]=shared_memory[0]+0.5; 

            break;

        }

        else

        {

            cout << "Wrong option" << endl;

        }

    }   

}


int main(int argc, char** argv)

{

     temp = stoi(argv[1]);

    	sleep(2);

                calculator();

       

        return 0;

}
