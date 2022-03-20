/*
Liangjie Shen 
CS4310 Project 1
3/20/2022
*/
#include <iostream> // input and output
#include <fstream>  // read from file
#include <string>   // string library

using namespace std;

// define constant
#define SIZE 20

// function declaration
void FCFS(int[],int[],int[],int[]); 
void SJF(int[],int[],int[],int[]);
void PPS(int[],int[],int[],int[]);
void RR(int[],int[],int[],int[]);
int sizeOfArray(int[]);
double average(int[], int);
double rate(int[],int[],int);

int main()
{
    // variables and array declaration
    int pid[SIZE] = {0}, arrivalTime[SIZE], burstTime[SIZE], priority[SIZE];
    string info[SIZE];
    int number,option = 0,timeQuantum = 0;
   
    // welcome message
    cout << "Welcome to the CPU Scheduling Simulator!" << endl;
    
    
    // open file to read
    ifstream file("input.txt");
    
    // assign each value to the specified arrays
    for(int i = 0; i < SIZE; i++ ){
        file >> pid[i] >> arrivalTime[i] >> burstTime[i] >> priority[i];
    }
    
    // close the file
    file.close();
    
    // ask for a specific scheduling algorithm
    while(option < 1 || option > 4){
        cout << "Choose a scheduling algorithm[1-4]:" << endl;
        cout << "1) First Come First Serve (FCFS)\n2) Shortest Job First (SJF)";
        cout << "\n3) Preemptive Priority Scheduling\n4) Round Robin (RR)" << endl;
        cin >> option;
    }
    
    // ask for a time time quantum if Round Robin I 
    if(option == 4){
        cout << "Time-quantum: ";
        cin >> timeQuantum;
    }
    
    switch(option){
        
        case 1:
            FCFS(pid,arrivalTime,burstTime,priority); // First Come Fist Serve
            break;
        
        case 2:
            SJF(pid,arrivalTime,burstTime,priority); // Shortest Job First
            break;
            
        case 3:
            PPS(pid,arrivalTime,burstTime,priority); //  Preemptive Priority Scheduling
            break;
            
        case 4:
            RR(pid,arrivalTime,burstTime,priority); // Round Robin
            break;
       
    }
    
    
    
    return 0;
}

// get the length of the array
int sizeOfArray(int array[]){
    int counter = 0;
    for(int i = 0; i < SIZE; i++){
        if(array[i] == 0)
            break;
        counter++;
    }
    return counter;
}

// returns the average of an integer array
double average(int array[], int size){
    double result;
    for(int i  = 0; i < size; i++){
            result+=array[i];
    }
    return result/size;
}

// returns the CPU utilization rate 
double rate(int burst[],int end[],int size){
    int sum,max = 0;
    for(int i = 0; i < size; i++){
        sum += burst[i];
        if(end[i]>max)
            max = end[i];
    }
    return sum / max *100;
}

void FCFS(int pid[],int arrivalTime[],int burstTime[],int priority[]){
    
    int size = 0, start = 0,end = 0;
    
    size = sizeOfArray(pid);

    int startTime[size],endTime[size],turnAround[size],waitingTime[size],responseTime[size];
    double averageWaitingTime, averageResponseTime, averageTurnaroundTime, CPUUtilizationRate;
   
    for(int i = 0; i < size ; i++){
        start = end;
        startTime[i] = start;
        end += burstTime[i];
        endTime[i] = end;
        
        for(int j = start; j < end; j++)
            cout << "P" << pid[i] << " is running!\t" << j+1 << "ms" << endl;
        cout << "P" << pid[i] << " is done!" << endl;

        turnaround[i] = endTime[i] - arrivalTime[i];
        waitingTime[i] = turnaround[i] - burstTime[i];
        responseTime[i] = startTime[i] - arrivalTime[i];
    }  

    cout << "\nAverage waiting time: " << average(waitingTime,size) << endl;
    cout << "Average response time: " << average(responseTime,size) << endl;
    cout << "Average turnaround time: " << average(turnaroundTime,size) << endl;
    cout << "CPU utilization rate: " << rate(burstTime,end,size) << "%" << endl;
    
    
}

void SJF(int pid[],int arrivalTime[],int burstTime[],int priority[]){
    cout << 2;
}
void PPS(int pid[],int arrivalTime[],int burstTime[],int priority[]){
    cout << 3;
}
void RR(int pid[],int arrivalTime[],int burstTime[],int priority[]){
    cout << 4;
}



