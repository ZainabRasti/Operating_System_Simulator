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

                	 cout << "\n\t------------------------\n\tDelete File has taken Ram : " << 3 << endl;
        cout << "\tremaining RAM = " << temp - 3 << "gb" << endl;
         cout << "\n\t------------------------\n";

        cout << "\n\n";
   

}

 

//Delete a file

void deletefile()

{

    float n = 3;

    displaymemory(n);

    int status;

    char fileName[20];

    cout << "Enter the Name of File: " << endl;

    cin >> fileName;

    status = remove(fileName);

    if (status == 0)

        cout << "\nFile Deleted Successfully!" << endl;

    else

        cout << "\nErorr Occurred!" << endl;

    cout << endl;

}

int main(int argc, char** argv)

{

     temp = stoi(argv[1]);
	int ch = 1;
   


                int shared_memory_id;

                key_t key = ftok("shmfile", 65);

                float *shared_memory;

                shared_memory_id = shmget(key, 1024, 0666);

                shared_memory = (float *)shmat(shared_memory_id, NULL, 0);

                mem = shared_memory[0];

                while(1)
                {
                system("clear");
    

                	deletefile();
                
                sleep(3);
                
                cout << " Enter 0 to EXIT Delete File App\n";
                cin >> ch;
                if(ch == 0)
                	return 0;
                }
        shared_memory[0]=shared_memory[0]+0.05;

        shared_memory[7]=0;
        
        sleep(2);

        return 0;

}
