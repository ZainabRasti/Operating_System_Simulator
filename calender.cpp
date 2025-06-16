#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <ctime>
#include <cstdlib>
#include <sys/ipc.h>
#include <sys/shm.h>

using namespace std;

float mem;
int temp;
// Timer function
void time()
{
    int sec_prev = 0;
    while (1)
    {
        int seconds, minutes, hours;

        // Storing total seconds
        time_t total_seconds = time(0);

        // Getting values of seconds, minutes, and hours
        struct tm *ct = localtime(&total_seconds);

        seconds = ct->tm_sec;
        minutes = ct->tm_min;
        hours = ct->tm_hour;

        // Converting it into 12-hour format
        string str = (hours >= 12) ? "PM" : "AM";
        hours = (hours > 12) ? hours - 12 : hours;

        // Printing the result when the second changes
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

                	 cout << "\n\t------------------------\n\tCalender has taken Ram : " << 3 << endl;
        cout << "\tremaining RAM = " << mem << "gb" << endl;
         cout << "\n\t------------------------\n";

        cout << "\n\n";

}


int dayNumber(int day, int month, int year)
{
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    year -= month < 3;
    return (year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7;
}

string getMonthName(int monthNumber)
{
    string months[] = {"January", "February", "March", "April", "May", "June",
                       "July", "August", "September", "October", "November", "December"};

    return months[monthNumber];
}

int numberOfDays(int monthNumber, int year)
{
    if (monthNumber == 1)
    {
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            return 29;
        else
            return 28;
    }
    return 31 - (monthNumber % 7 % 2);
}

// Function to print the calendar of the given year
void calendar()
{

    int year;
    cout << "Enter Year: ";
    cin >> year;
    cout << "\e[1;32m\tCalendar for " << year << "\n";
    int days;
    int current = dayNumber(1, 1, year);
    for (int i = 0; i < 12; i++)
    {
        days = numberOfDays(i, year);
        cout << "\e[1;31m\n  ------------ " << getMonthName(i) << " ------------\n\e[0m";
        cout << "\e[1;32m  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";
        int k;
        for (k = 0; k < current; k++)
            cout << "    ";

        for (int j = 1; j <= days; j++)
        {
            cout << "   ";
            cout << j;
            if (++k > 6)
            {
                k = 0;
                cout << "\n";
            }
        }

        if (k)
            cout << "\n";
        current = k;
    }
}
int main(int argc, char** argv)

{
int ch;
     temp = stoi(argv[1]);

    int shared_memory_id;
    key_t key = ftok("shmfile", 65);
    float *shared_memory;
    shared_memory_id = shmget(key, 1024, 0666);
    shared_memory = (float *)shmat(shared_memory_id, NULL, 0);
    mem = shared_memory[0];
    while(1)
                {
                system("clear");
    
 displaymemory(2);
    calendar();
                sleep(3);
                
                cout << " Enter 0 to EXIT Move File App\n";
                cin >> ch;
                if(ch == 0)
                	return 0;
                }
   
    
    sleep(5);
    shared_memory[10] = 0;
    return 0;
}

