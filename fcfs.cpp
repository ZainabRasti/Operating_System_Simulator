#include "pthread.h"

#include "iostream"

#include "stdio.h"

#include "stdlib.h"

#include "unistd.h"

#include "bits/stdc++.h"

#include "ctime"

#include "cstdlib"

#include <sys/ipc.h>
#include <string>
#include <algorithm>
#include <sys/shm.h>

using namespace std;

float mem;

 int temp ;

 

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

            system("CLS");

            cout << (hours < 10 ? "0" : "") << hours << ":" << (minutes < 10 ? "0" : "") << minutes << ":" << (seconds < 10 ? "0" : "") << seconds << " " << str << endl;

            break;

        }

 

        sec_prev = seconds;

 

    }

}

void displaymemory(float n)

{

    time();

                	 cout << "\n\t------------------------\n\tFCFS has taken Ram : " << 3 << endl;
        cout << "\tremaining RAM = " << temp-3 << "gb" << endl;
         cout << "\n\t------------------------\n";

        cout << "\n\n";

}

 

class Process 
{
public:
    int id;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};


void calculateCompletionTime(Process* processes, int n) 
{
    int current_time = 0;
    for (int i = 0; i < n; i++) 
    {
        current_time += processes[i].burst_time;
        processes[i].completion_time = current_time;
    }
}


void calculateTurnaroundTime(Process* processes, int n) 
{
    for (int i = 0; i < n; i++) 
    {
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
    }
}


void calculateWaitingTime(Process* processes, int n) 
{
    for (int i = 0; i < n; i++) 
    {
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
    }
}


void printProcesses(Process* processes, int n) 
{
    cout << "Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n";
    for (int i = 0; i < n; i++) {
        cout << processes[i].id << "\t" << processes[i].arrival_time << "\t\t"
             << processes[i].burst_time << "\t\t" << processes[i].completion_time << "\t\t"
             << processes[i].turnaround_time << "\t\t" << processes[i].waiting_time << endl;
    }
}


bool sortByArrivalTime(Process& a, Process& b) 
{
    return a.arrival_time < b.arrival_time;
}


int main(int argc, char** argv)

{

    temp = stoi(argv[1]);
     
    std::string program_name = "my_executable";
    std::string command = "ps aux | grep \"" + program_name + "\" | grep -v grep | wc -l";
    std::string result = std::string(std::getenv("SHELL")) + " -c '" + command + "'";
    std::string output = "";
    FILE* stream = popen(result.c_str(), "r");
    if (stream) {
        char buffer[256];
        while (!feof(stream)) {
            if (fgets(buffer, 256, stream) != NULL) {
                output += buffer;
            }
        }
        pclose(stream);
    }
 
    int n = 0;
    string f;
    system("clear");
    
    cout << "\n\n\n\t LOADING...." << endl;
    sleep(5);
    system("clear");
    cout << "\n\n\n\n";
    cout << "\t\t Welcome to FCFS Calculator  \t\t" << endl;
    sleep(5);
    system("clear");
    cout << "\n\n\n";
    
    while (true)
    {
    	system("clear");
    	displaymemory(3);
    	cout << "1. To FCFS" << endl;
    	cout << "2. for exit" << endl;
    	cin >> n;
    	
    
	    if (n == 1)
	    {
	        int n;
    		cout << "Enter the number of processes: ";
    		cin >> n;
    		
    		Process* processes = new Process[n];

		    for (int i = 0; i < n; i++) 
		    {
			cout << "Enter arrival time and burst time of process " << i + 1 << ": ";
			cin >> processes[i].arrival_time >> processes[i].burst_time;
			processes[i].id = i + 1;
		    }
		    
		    sort(processes, processes + n, sortByArrivalTime);
		    calculateCompletionTime(processes, n);
		    calculateTurnaroundTime(processes, n);
		    calculateWaitingTime(processes, n);
		    printProcesses(processes, n);
		    sleep(10);
		    delete [] processes;
    
	    }
	    else if (n == 2)
	    {
		break;
	    }
	    
    }
    pthread_exit(NULL);
}
