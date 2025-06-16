#include <iostream>
#include <fstream>
#include <unistd.h>
#include <ctime>
#include <cstdlib>
#include <sys/ipc.h>
#include <sys/shm.h>

using namespace std;

float mem;
int temp;
// Timer function
void time() {
    int sec_prev = 0;
    while (1) {
        int seconds, minutes, hours;
        string str;

        // Storing total seconds
        time_t total_seconds = time(0);

        // Getting values of seconds, minutes, and hours
        struct tm* ct = localtime(&total_seconds);

        seconds = ct->tm_sec;
        minutes = ct->tm_min;
        hours = ct->tm_hour;

        // Converting it into 12-hour format
        if (hours >= 12)
            str = "PM";
        else
            str = "AM";
        hours = hours > 12 ? hours - 12 : hours;

        // Printing the result
        if (seconds == sec_prev + 1 || (sec_prev == 59 && seconds == 0)) {
            system("clear");
            cout << (hours < 10 ? "0" : "") << hours << ":" << (minutes < 10 ? "0" : "") << minutes << ":" << (seconds < 10 ? "0" : "") << seconds << " " << str << endl;
            break;
        }

        sec_prev = seconds;
    }
}

// Display memory function
void displayMemory(float n) {
    time();
    
    cout << "\n\t------------------------\n\tMaking file has taken Ram : " << 2 << endl;
    cout << "Remaining RAM = " << mem << " GB" << endl;
    cout << "\n\t------------------------\n";
    cout << "\n\n";
}

// Make file function
void* makefile(void* args) 
{
    string filename = *(std::string*)args;
    
    fstream file;

    file.open(filename, std::ios::out | std::ios::app);

    if (file.fail() || file.bad()) 
    {
        cout << "Error in creating file " << filename << "!!!" << endl;
    } 
    else 
    {
        cout << "File " << filename << " created successfully." << endl;
    }

    pthread_exit(NULL);
}

int main(int argc, char** argv)

{

     temp = stoi(argv[1]);

    

   pthread_t T1;
    
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
    sleep(3);
    sleep(2);
    system("clear");
    cout << "\n\n\n\n";
    cout << "\t\t Welcome to MakeFIle App  \t\t" << endl;
    sleep(5);
    system("clear");
    cout << "\n\n\n";
    
    while (true)
    {
    displayMemory(2);
    	cout << "1. To make new file" << endl;
    	cout << "2. for exit" << endl;
    	cin >> n;
    
	    if (n == 1)
	    {
	        cout << "Enter Filename : ";
	        cin >> f;
		pthread_create(&T1, NULL, &makefile,(void*)&f);
		pthread_join(T1, NULL);
	    }
	    else if (n == 2)
	    {
		pthread_exit(NULL);
	    }
	    
    }
    return 0;
}

