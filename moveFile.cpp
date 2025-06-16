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

                	 cout << "\n\t------------------------\n\tMove File has taken Ram : " << 2 << endl;
        cout << "\tremaining RAM = " << temp-2 << "gb" << endl;
         cout << "\n\t------------------------\n";

        cout << "\n\n";

}

 

//MOVING FILE

void movefile()

{



    int result = 1;

    char oldname[500];

    char newname[500];

    cout << "Enter the name of a file you want to move (include directory structure)" << endl;

    cin >> oldname;

    cout << "Enter the new location (include directory structure)" << endl;

    cin >> newname;

 

    result = rename(oldname, newname);

    if (result == 0)

        cout << "File successfully moved" << endl;

    else

        cout << "Error moving file" << endl;

}

int main(int argc, char** argv)

{
int ch;
    temp = stoi(argv[1]);

		sleep(3);

                int shared_memory_id;

                key_t key = ftok("shmfile", 65);

                float *shared_memory;

                shared_memory_id = shmget(key, 1024, 0666);

                shared_memory = (float *)shmat(shared_memory_id, NULL, 0);

                mem=shared_memory[0];
                
                while(1)
                {
                system("clear");
    
displaymemory(2);

                movefile();
                sleep(3);
                
                cout << " Enter 0 to EXIT Move File App\n";
                cin >> ch;
                if(ch == 0)
                	return 0;
                }


        shared_memory[0]=shared_memory[0]+0.5;

        shared_memory[5]=0;

        return 0;

}
