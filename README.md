# CPU-Scheduling-Simulator

Write a program to simulate following CPU scheduling algorithms:

1) First Come First Serve (FCFS)

2) Shortest Job First (SJF)

3) Preemptive Priority Scheduling

4) Round Robin (RR)

The task information will be read from an input file (input.txt) with the following format:

Pid Arrival_Time Burst_Time Priority

All of fields are integer type where

Pid is a unique numeric process ID

Arrival_Time is the time when the task arrives in the unit of milliseconds

Burst_Time is the CPU time requested by a task, in the unit of milliseconds

Priority is the priority associated with each task with low numbers representing high priority.

Note: for RR algorithm you need to define a Time-quantum.

What to do?

Create a simple user interface to ask user for input.txt file, a scheduling algorithm and Time-quantum if RR is chosen.

Print progress of task every unit time (millisecond).
Once all tasks are completed, the program should compute and print :
Average waiting time
Average response time
Average turnaround time
CPU utilization rate
