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
#include <string>

#include<iostream>
#include <iomanip>

using namespace std;

static int j = 1;

float mem = 0;

unsigned int m = 100;

float *shared_memory;

 

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

//Display memory

 

//calculator

 

//GAME # 1

 

 struct Task
{//struct for kepping the values that are to identify and stored each process
  int id;
  string name;
  int ramUse; //in MBs
  int priority; //Higher the number ,higher the  priority

};
Task t[20];

 int countTask = 0;

 void *initialize(void *args){

   t[0].id=1; t[0].name="Calculator";    
   t[0].ramUse=4;t[0].priority=1;
   
   t[1].id=2; t[1].name="TIC TAC TOE";  
   t[1].ramUse=6;t[1].priority=2;
   
   t[2].id=5; t[2].name="Make FIle";    
   t[2].ramUse=2; t[2].priority=3;
   
   
   t[3].id=7; t[3].name="Move File";    
   t[3].ramUse=2; t[3].priority=8;
   
   t[4].id=8; t[4].name="Copy File Content";
   t[4].ramUse=3; t[4].priority=7;
   
   t[5].id=9; t[5].name="Delete FIle";    
   t[5].ramUse=3;t[5].priority=9;
   
   t[6].id=10;t[6].name="Find FCSF";  
   t[6].ramUse=3;t[6].priority=10;
   

   
   t[7].id=11;t[7].name="play music";  
   t[7].ramUse=5;t[7].priority=19;
   
   t[8].id=12;t[8].name="open calendar";  
   t[8].ramUse=2;t[8].priority=15;
   
   t[9].id=19;t[9].name="NotePad";  
   t[9].ramUse=4;t[9].priority=6;
   
   t[10].id=17;t[10].name="Stopwatch";  
   t[10].ramUse=2;t[10].priority=12;
   
   t[11].id=13;t[11].name="Guess Game";
   t[11].ramUse=5;t[11].priority=11;
   
   t[12].id=17;t[12].name="Open Google Chrome";
   t[12].ramUse=3;t[12].priority=17;

 t[13].id=17;t[13].name="Time";
   t[13].ramUse=1;t[13].priority=18;

 t[14].id=17;t[14].name="Rock Paper Scissor";
   t[14].ramUse=1;t[14].priority=18;

 t[15].id=17;t[15].name="To Do List";
   t[15].ramUse=1;t[15].priority=19;
 t[16].id=17;t[16].name="Expense Sheet";
   t[16].ramUse=1;t[16].priority=20;
 t[17].id=17;t[17].name="Quiz";
   t[17].ramUse=1;t[17].priority=21;

   countTask = 14;
    pthread_exit(NULL);
}

 

 //void playAudiochoice() {
    //system("canberra-gtk-play -f OS.wav");
//}
// Define the function before it is called
void playAudiochoice() {
    system("aplay /home/ns3/Desktop/Operating_System/OS.wav");
}

void* func(void *arg)

{

   while(true)

   {

    int n,temp;

    pthread_detach(pthread_self());

    cout<<"=======CHOOSE OPTION========\n";

    cout << "1 : Calculator" << endl;

    cout << "2 : TIC TAC TOE" << endl;

    cout << "3 : Make file" << endl;

    cout << "4 : Move file" << endl;

    cout << "5 : Copy file content" << endl;

    cout << "6 : Delete a file" << endl;

    cout << "7 : Find FCFS" << endl;

    cout << "8 : Play music" << endl;

    cout << "9 : Open calendar" << endl;

    cout << "10 : Notepad" << endl;

    cout << "11 : Stopwatch" << endl;
    cout << "12 : Guess Game" << endl;
cout << "13 : Rock Paper Scissor Game" << endl;
    cout << "14 : Open Google Chrome" << endl;
    cout << "15 : Time" << endl;
cout << "16 : To Do List" << endl;
cout << "17 : Expense Sheet" << endl;
cout << "18 : Quiz" << endl;
    cout<<"19 : exit"<<endl;

    cin >> n;
	cout<<"\n\t---------"<<"Total Ram is " << mem<<"-----------"<<endl;
	
	if(t[n-1].ramUse > mem || mem < 0)
	{
		cout<<"Ram available is for this process is not enough"<<endl;
		cout<<"Avaliable Ram is : "<<*shared_memory<<endl;
		cout<<"Ram Recquired is : "<<t[n-1].ramUse<<endl;
		
		cout<<"Waiting for any process to end--------"<<endl;
		sleep(3);
		n=14;
	}

   
   sleep(3);


    if (n == 1)
    {
    	

                 cout << shared_memory[0]<<endl<<endl;

        // Open a new terminal window, compile/run a C++ file, and close the window when done

   string command = "gnome-terminal -- bash -c 'g++ calculator.cpp -o my_executable && ./my_executable " + to_string(mem) + "; exit' &";
    
      // Open a new terminal window, compile/run a C++ file, and close the window when done

    system(command.c_str());
 

    // Open a new tab in the current terminal window, compile/run a C++ file, and close the tab when done

 //   system("gnome-terminal --tab -- bash -c 'g++ calculator.cpp -o my_executable && ./my_executable; exit' &");

   
     // Open a new terminal window and compile/run a C++ file

    //system("gnome-terminal -- bash -c 'g++ calculator.cpp -o my_executable && ./my_executable; exec bash' &");

 

    // Open a new tab in the current terminal window and compile/run a C++ file

   // system("gnome-terminal --tab -- bash -c 'g++ calculator.cpp -o my_executable && ./my_executable; exec bash' &");

        shared_memory[0]=shared_memory[0]-4;

        shared_memory[1]=1;
    }

    else if (n == 2)

    {
    
    string command = "gnome-terminal -- bash -c 'g++ game.cpp -o my_executable && ./my_executable " + to_string(mem) + "; exit' &";
    
      // Open a new terminal window, compile/run a C++ file, and close the window when done

    system(command.c_str());

 

    // Open a new tab in the current terminal window, compile/run a C++ file, and close the tab when done

   // system("gnome-terminal --tab -- bash -c 'g++ game.cpp -o my_executable && ./my_executable; exit' &");

        shared_memory[2] = 1;

        shared_memory[0] = shared_memory[0]-4;

    }

    else if (n == 3)

    {

       

        shared_memory[4]=1;

        shared_memory[0]=shared_memory[0]-2;

        // Open a new terminal window, compile/run a C++ file, and close the window when done

  	string command = ("gnome-terminal -- bash -c './make 1; echo \"Press Enter to exit...\"; read'");
      // Open a new terminal window, compile/run a C++ file, and close the window when done

    system(command.c_str());
 

    // Open a new tab in the current terminal window, compile/run a C++ file, and close the tab when done

    //system("gnome-terminal --tab -- bash -c 'g++ makeFile.cpp -o my_executable && ./my_executable; exit' &");

 

    }

    else if (n == 4)

    {

       

        shared_memory[0]=shared_memory[0]-2;

        shared_memory[5]=1;
float mem = 4.0; // Example memory value
    string command = "gnome-terminal -- bash -c './moveFile " + to_string(mem) + "; exit'";

    // Run the moveFile executable in a new terminal
    system(command.c_str());

        // Open a new terminal window, compile/run a C++ file, and close the window when done

    //string command = "gnome-terminal -- bash -c 'g++ moveFile.cpp -o my_executable && ./my_executable " + to_string(mem) + "; exit' &";
    
      // Open a new terminal window, compile/run a C++ file, and close the window when done

    //system(command.c_str());
 

    // Open a new tab in the current terminal window, compile/run a C++ file, and close the tab when done

  //  system("gnome-terminal --tab -- bash -c 'g++ moveFile.cpp -o my_executable && ./my_executable; exit' &");

 

    }

    else if (n == 5)

    {

       

        shared_memory[0]=shared_memory[0]-3;

        shared_memory[6]=1;

        // Open a new terminal window, compile/run a C++ file, and close the window when done

   string command = "gnome-terminal -- bash -c 'g++ copyFile.cpp -o my_executable && ./my_executable " + to_string(mem) + "; exit' &";
    
      // Open a new terminal window, compile/run a C++ file, and close the window when done

    system(command.c_str());

    // Open a new tab in the current terminal window, compile/run a C++ file, and close the tab when done

   // system("gnome-terminal --tab -- bash -c 'g++ copyFile.cpp -o my_executable && ./my_executable; exit' &");

 

    }

    else if (n == 6)

    {

       

        shared_memory[0]=shared_memory[0]-3;

        shared_memory[7]=1;

        // Open a new terminal window, compile/run a C++ file, and close the window when done

    string command = "gnome-terminal -- bash -c 'g++ deleteFile.cpp -o my_executable && ./my_executable " + to_string(mem) + "; exit' &";
    
      // Open a new terminal window, compile/run a C++ file, and close the window when done

    system(command.c_str());
 

    // Open a new tab in the current terminal window, compile/run a C++ file, and close the tab when done

   // system("gnome-terminal --tab -- bash -c 'g++ deleteFile.cpp -o my_executable && ./my_executable; exit' &");

 

    }

    else if (n == 7)

    {

       
        shared_memory[0]=shared_memory[0]-3;

        shared_memory[8]=1;

        // Open a new terminal window, compile/run a C++ file, and close the window when done

    string command = "gnome-terminal -- bash -c 'g++ fcfs.cpp -o my_executable && ./my_executable " + to_string(mem) + "; exit' &";
    
      // Open a new terminal window, compile/run a C++ file, and close the window when done

    system(command.c_str());
 

    // Open a new tab in the current terminal window, compile/run a C++ file, and close the tab when done

  //  system("gnome-terminal --tab -- bash -c 'g++ fcfs.cpp -o my_executable && ./my_executable; exit' &");

 

    }


    else if (n == 8) {
        thread audioThread1(playAudiochoice);
        shared_memory[0] = shared_memory[0] - 5;
        shared_memory[9] = 1;
        audioThread1.join();
    }

    else if (n == 9)

    {

        shared_memory[0]=shared_memory[0]-3;

        shared_memory[10]=1;

        // Open a new terminal window, compile/run a C++ file, and close the window when done

    string command = "gnome-terminal -- bash -c 'g++ calender.cpp -o my_executable && ./my_executable " + to_string(mem) + "; exit' &";
    
      // Open a new terminal window, compile/run a C++ file, and close the window when done

    system(command.c_str());
 

    // Open a new tab in the current terminal window, compile/run a C++ file, and close the tab when done

   // system("gnome-terminal --tab -- bash -c 'g++ calender.cpp -o my_executable && ./my_executable; exit' &");

 

    }
    else if (n == 10)

    {

        shared_memory[0]=shared_memory[0]-2;

        shared_memory[10]=1;

        // Open a new terminal window, compile/run a C++ file, and close the window when done

    string command = "gnome-terminal -- bash -c 'g++ notepad.cpp -o my_executable && ./my_executable; exit' &";
    
      // Open a new terminal window, compile/run a C++ file, and close the window when done

    system(command.c_str());
 

    // Open a new tab in the current terminal window, compile/run a C++ file, and close the tab when done

   // system("gnome-terminal --tab -- bash -c 'g++ calender.cpp -o my_executable && ./my_executable; exit' &");

 

    }
   else if (n == 11) {
    shared_memory[0] = shared_memory[0] - 2;
    shared_memory[10] = 1;

    // Command to run the stopwatch
    string command = "gnome-terminal -- bash -c './stopwatchh; echo \"Press Enter to exit...\"; read -n 1'";
    
    // Execute the command
    system(command.c_str());
}
    
    else if (n == 12)

    {

        shared_memory[0]=shared_memory[0]-2;

        shared_memory[10]=1;

        // Open a new terminal window, compile/run a C++ file, and close the window when done

    //string command = "gnome-terminal -- bash -c 'g++ guessgame.cpp -o my_executable && ./my_executable; exit' &";
 string command = ("gnome-terminal -- bash -c './guessgame; echo \"Press Enter to exit...\"; read'");
    
      // Open a new terminal window, compile/run a C++ file, and close the window when done

    system(command.c_str());
 

    // Open a new tab in the current terminal window, compile/run a C++ file, and close the tab when done

   // system("gnome-terminal --tab -- bash -c 'g++ calender.cpp -o my_executable && ./my_executable; exit' &");

 

    }
else if (n == 13)

    {

        shared_memory[0]=shared_memory[0]-2;

        shared_memory[10]=1;

        // Open a new terminal window, compile/run a C++ file, and close the window when done

    //string command = "gnome-terminal -- bash -c 'g++ guessgame.cpp -o my_executable && ./my_executable; exit' &";
 //system("gnome-terminal -- bash -c './guessgame; echo \"Press Enter to exit...\"; read'");
     string command = ("gnome-terminal -- bash -c './rockpaper; echo \"Press Enter to exit...\"; read'");
      // Open a new terminal window, compile/run a C++ file, and close the window when done

    system(command.c_str());
 

    // Open a new tab in the current terminal window, compile/run a C++ file, and close the tab when done

   // system("gnome-terminal --tab -- bash -c 'g++ calender.cpp -o my_executable && ./my_executable; exit' &");

 

    }


else if (n == 14)
    {
        shared_memory[11] = 1;
     	system("xdg-open http://www.google.com");
    }

    else if (n==15)

    {
 cout << shared_memory[0]<<endl<<endl;

    shared_memory[0]=shared_memory[0]-1;

        shared_memory[11]=1;

                    // Open a new terminal window, compile/run a C++ file, and close the window when done
string command = "gnome-terminal -- bash -c 'g++ Time.cpp -o my_executable && ./my_executable; read -p \"Press Enter to exit...\"'; exit' &";

   //string command = "gnome-terminal -- bash -c 'g++ Time.cpp -o my_executable && ./my_executable " + to_string(mem) + "; exit' &";
    
      // Open a new terminal window, compile/run a C++ file, and close the window when done

    system(command.c_str());
   

    }
 else if (n==16)

    {
 cout << shared_memory[0]<<endl<<endl;

    shared_memory[0]=shared_memory[0]-1;

        shared_memory[12]=1;

                    // Open a new terminal window, compile/run a C++ file, and close the window when done
 // Open a new terminal window, compile/run a C++ file, and close the window when done
    string command = "gnome-terminal -- bash -c 'g++ ToDo.cpp -o my_executable && ./my_executable; read -p \"Press Enter to exit...\"'";;

   //string command = "gnome-terminal -- bash -c 'g++ Time.cpp -o my_executable && ./my_executable " + to_string(mem) + "; exit' &";
    
      // Open a new terminal window, compile/run a C++ file, and close the window when done

    system(command.c_str());
   

    }
 else if (n==17)

    {
 cout << shared_memory[0]<<endl<<endl;

    shared_memory[0]=shared_memory[0]-1;

        shared_memory[13]=1;

 // Open a new terminal window, compile/run a C++ file, and close the window when done
    string command = "gnome-terminal -- bash -c 'g++ expense.cpp -o my_executable && ./my_executable; read -p \"Press Enter to exit...\"'";

   //string command = "gnome-terminal -- bash -c 'g++ Time.cpp -o my_executable && ./my_executable " + to_string(mem) + "; exit' &";
    
      // Open a new terminal window, compile/run a C++ file, and close the window when done

    system(command.c_str());
   

    }
 else if (n==18)

    {
 cout << shared_memory[0]<<endl<<endl;

    shared_memory[0]=shared_memory[0]-1;

        shared_memory[14]=1;


    // Open a new terminal window, compile/run a C++ file, and close the window when done
    string command = "gnome-terminal -- bash -c 'g++ quiz.cpp -o my_executable && ./my_executable; read -p \"Press Enter to exit...\"'";

    // Execute the command
    system(command.c_str());
}
	else if (n==19)
{
break;
}

    system("clear");

    }

    pthread_exit(NULL);

   

}
void printInColor(const string& text, int colorCode) {
    cout << "\033[1;" << colorCode << "m" << text << "\033[0m";
}

void playAudio() {
    system("canberra-gtk-play -f os.wav");
}



void header() {
    cout << "\033[2J\033[1;1H"; // Clear screen

    string osSimulator = R"(
  ____                       _   _                _____           _                    _____ _                 _       _             
 / __ \                     | | (_)              / ____|         | |                  / ____(_)               | |     | |            
| |  | |_ __   ___ _ __ __ _| |_ _ _ __   __ _  | (___  _   _ ___| |_ ___ _ __ ___   | (___  _ _ __ ___  _   _| | __ _| |_ ___  _ __ 
| |  | | '_ \ / _ \ '__/ _` | __| | '_ \ / _` |  \___ \| | | / __| __/ _ \ '_ ` _ \   \___ \| | '_ ` _ \| | | | |/ _` | __/ _ \| '__|
| |__| | |_) |  __/ | | (_| | |_| | | | | (_| |  ____) | |_| \__ \ ||  __/ | | | | |  ____) | | | | | | | |_| | | (_| | || (_) | |   
 \____/| .__/ \___|_|  \__,_|\__|_|_| |_|\__, | |_____/ \__, |___/\__\___|_| |_| |_| |_____/|_|_| |_| |_|\__,_|_|\__,_|\__\___/|_|   
       | |                                __/ |          __/ |                                                                     
       |_|                               |___/          |___/                                                                      
    )";

    // Print in green color (32)
    printInColor(osSimulator, 32);

    cout << endl;
    cout << "\t\t  \033[1;35mLaiba Khalid 23F-0784\033[0m" << endl;
    sleep(1); // Sleep for 1 second
    cout << "\t\t  \033[1;34mZainab Rasti 23F-0775\033[0m" << endl;
}


int mode()
{
		int choice1;
		cout<<"\t\t------------------------"<<endl;
	cout << "\t\t\tWELCOME TO LOGIN PAGE!"<<endl;
	cout<<"\t\t------------------------"<<endl;
	cout<<"Welcome! How do you want to Log In? \nPlease Select from the following options:\n1. User.\n2. Kernal.\nEnter the number of selected option:";
	cin>>choice1;
	system("clear");
	return choice1;
	
}

int main()

{

	thread audioThread(playAudio);
pthread_t thr;
  pthread_create(&thr,NULL,&initialize,NULL);  //loading tasks
  pthread_join(thr,NULL);
 system("clear");

    cout<<endl<<endl<<endl;

    header();

    cout << "\n\n\n\t\t  PLEASE WAIT LOADING....." << endl;

    sleep(5);
    
    
     audioThread.join();

    system("clear");
       int kChoice;
	while(1)
	{
	 cout << "\n\n";

    cout << "Welcome \n" << endl;
	system("clear");
		int ch = mode();
    switch(ch)
    {
    	
    case 1:
    {
    		int n;

   

 //   header();

int tempcore;
    int hard_drive_gb;
    // RAM input with validation
    while(true) {
        cout << "Enter total RAM to allocate (in GB, 1-16): ";
        cin >> mem;
        if(mem >= 1 && mem <= 16) break;
        cout << "Invalid input! Please enter between 1-16 GB." << endl;
    }

    // Hard drive input with validation
    while(true) {
        cout << "Enter hard drive size (in GB, 32-1024): ";
        cin >> hard_drive_gb;
        if(hard_drive_gb >= 32 && hard_drive_gb <= 1024) break;
        cout << "Invalid input! Please enter between 32-1024 GB." << endl;
    }

    // Core input with validation
    while(true) {
        cout << "Enter number of CPU cores (1-8): ";
        cin >> tempcore;
        if(tempcore >= 1 && tempcore <= 8) break;
        cout << "Invalid input! Please enter between 1-8 cores." << endl;
    }
     int shm_id;

    key_t key = ftok("shmfile", 65);

   

    shm_id = shmget(key, 1024, IPC_CREAT | 0666);

    shared_memory = (float *)shmat(shm_id, NULL, 0);

    shared_memory[0]=mem;

    for(int i=1;i<11;i++)

    {

        shared_memory[i]=0;

    }

    shared_memory[0] = mem;

  

   

    while (true)

    {
    system("clear");

        cout<<"CHOOSE : "<<endl;

        cout << "1 : Next" << endl;

        cout << "2 : End" << endl;

        cin >> n;

        system("clear");

        if (n == 1)

        {

            pthread_t* ptid = new pthread_t[n];

            pthread_create(&ptid[1], NULL, &func,NULL);

            pthread_join(ptid[1], NULL);

        }

        else if (n == 2)

        {

            break;

        }

    }

    pthread_exit(NULL);
    
    break;
    }
    
    case 2:
    {
    string pass;
    	   cout<<"\t\t------------------------"<<endl;
                cout << "\t\t\tPLEASE ENTER PASSWORD TO LOGIN!"<<endl;
                cout<<"\t\t------------------------"<<endl;
       cout<<"Enter password of kernal: ";
       cin>>pass;
       if(pass=="admin")
       {
         cout<<"yahoo!!!password is correct:))\n";
       }
       while(pass!="admin")
       {
           cout<<"Try again OR press 0 to shutdown"<<endl;
           cin>>pass;
           if(pass=="0")
              break;
       }
	do
	{
       
	cout<<"1. To Add Task"<<endl;
	cout<<"2. To Delete Task"<<endl;
	cout<<"0. To Shutdown"<<endl;
	cin>>kChoice;

if(kChoice == 1)
{
cout<<"\t\t------------------------"<<endl;
                               cout << "\t\t\tWELCOME TO THE PAGE TO ADD TASK!"<<endl;
                               cout<<"\t\t------------------------"<<endl;
                               cout<<"\n\t\tTOTAL TASK Before any addition"<<endl;
 	cout << left << setw(20) << "Name" << setw(20) << "Priority" << setw(20) << "RAM" << endl;
for (int i = 0; i <= countTask; ++i) {
    if (t[i].name != "") {
        cout << left << setw(20) << t[i].name << setw(20) << t[i].priority << setw(20) << t[i].ramUse << endl;
    }
}
 
 cout <<"\n\n\tEnter Details of new task "<<endl;
 		cout<<"Enter the name of Task:";
		cin>>t[++countTask].name;
		cout<<"Enter the Priority of Task:";
		cin>>t[countTask].priority;
		cout<<"Enter the Ram usage of Task:";
		cin>>t[countTask].ramUse;
    	cout<<"\n\n\t\tTOTAL TASK"<<endl;
 	cout << left << setw(20) << "Name" << setw(20) << "Priority" << setw(20) << "RAM" << endl;
for (int i = 0; i <= countTask; ++i) {
    if (t[i].name != "") {
        cout << left << setw(20) << t[i].name << setw(20) << t[i].priority << setw(20) << t[i].ramUse << endl;
    }
}
    sleep(5);
}
else if(kChoice == 2)
{
string inp;
cout<<"\t\t------------------------"<<endl;
                               cout << "\t\t\tWELCOME TO THE PAGE TO DELETE TASK!"<<endl;
                               cout<<"\t\t------------------------"<<endl;
                               
                               cout<<"\n\t\tTOTAL TASK Before any deletion"<<endl;
 	cout << left << setw(20) << "Name" << setw(20) << "Priority" << setw(20) << "RAM" << endl;
for (int i = 0; i <= countTask; ++i) {
    if (t[i].name != "") {
        cout << left << setw(20) << t[i].name << setw(20) << t[i].priority << setw(20) << t[i].ramUse << endl;
    }
}
 
cout<<"\n\tPlease enter the name of task you want to delete:";
cin>>inp;
for(int i = 0;i<=countTask;i++)
{
if(inp==t[i].name)
{
t[i].name="";
t[i].id=0;
t[i].priority=0;
t[i].ramUse=0;
cout<<"Task deleted succesfully"<<endl;
break;
}
}
cout<<"\n\n\t\tTOTAL TASK"<<endl;
    cout << left << setw(20) << "Name" << setw(20) << "Priority" << setw(20) << "RAM" << endl;
for (int i = 0; i <= countTask; ++i) {
    if (t[i].name != "") {
        cout << left << setw(20) << t[i].name << setw(20) << t[i].priority << setw(20) << t[i].ramUse << endl;
    }
}
  sleep(5);
}
else if (kChoice == 0)
	{
		cout<<"\n\n\tExiting .....\n";
		
	}

}while((kChoice==1)||(kChoice==2));
system("clear");
break;
    
    }
	
	
	}
	
	
	}

}
