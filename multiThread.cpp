/*
Liangjie Shen 
CS4310 Project 1
3/20/2022
Multithreaded Sorting Application
*/
#include <iostream> // input and output
#include <string>   // string library
#include <algorithm> // sort()

using namespace std;

// define constant
#define SIZE 10

// global list
int originalList[SIZE] = {7,12,19,3,18,4,2,6,15,8};
int mergeThread[SIZE];

// Function to merge array in sorted order
void mergeSort(int thread0[], int thread1[],int n, int m)
{
    // print original threads
    cout << "Original Thread 0: ";
    for(int i = 0; i < SIZE/2 ; i++){
        cout << thread0[i] << " ";
    }
    cout << endl;

    cout << "Original Thread 1: ";
    for(int i = 0; i < SIZE/2 ; i++){
        cout << thread1[i] << " ";
    }
    cout << endl;

    // sort the two threads
    sort(thread0, thread0 + SIZE/2);
    sort(thread1, thread1 + SIZE/2);
    
    // print sorted threads
    cout << "Sorted Thread 0: ";
    for(int i = 0; i < SIZE/2 ; i++){
        cout << thread0[i] << " ";
    }
    cout << endl;

    cout << "Sorted Thread 1: ";
    for(int i = 0; i < SIZE/2 ; i++){
        cout << thread1[i] << " ";
    }
    cout << endl;
    
    // merge two array
    int i = 0, j = 0, k = 0;
    while (i < n) {
        mergeThread[k] = thread0[i];
        i++;
        k++;
    }
    while (j < m) {
        mergeThread[k] = thread1[j];
        j++;
        k++;
    }
 
    // sort it recursively
    sort(mergeThread, mergeThread + n + m);
}

int main(){
    
    // initialize threads
    int thread0[5],thread1[5],counter = 5;

    // welcome message
    cout << "Welcome to the Multithreaded Sorting Application!" << endl;
    
    // fill in the two threads by spliting the original list
    for(int i = 0; i < SIZE/2; i++){
        thread0[i] = originalList[i];
        thread1[i] = originalList[counter];
        counter++;
    }

     // print the original list
    cout << "Original List: ";
    for(int i = 0; i < SIZE ; i++){
        cout << originalList[i] << " ";
    }
    cout << endl;

    // sort the two unsorted thread and merge them
    mergeSort(thread0,thread1,SIZE/2,SIZE/2);

    // print the merged list
    cout << "Merged Thread: ";
    for(int i = 0; i < SIZE ; i++){
        cout << mergeThread[i] << " ";
    }
    cout << endl;

}