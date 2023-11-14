#Monty - Stacks, Queues - LIFO, FIFO					14.11.23

#Overview
This project implements Monty Hall's Doors game using stacks and queues. The game is played as follows:

The player chooses a door from among three doors.
The host opens one of the remaining doors, revealing a goat.
The host asks the player if they want to switch doors.
If the player switches doors, they win if the car is behind the door they switched to. Otherwise, they lose.
Stacks and queues
A stack is a last-in-first-out (LIFO) data structure. This means that the last element added to the stack is the first element removed. A queue is a first-in-first-out (FIFO) data structure. This means that the first element added to the queue is the first element removed.

#Implementation
In this project, the three doors are represented by a stack. The player's choice of door is added to the top of the stack. The host's choice of door is removed from the top of the stack. If the player switches doors, the door they switched to is popped from the top of the stack.

#Running the program
To run the program, simply compile and execute the source code. The program will prompt the user to choose a door. The program will then open one of the remaining doors, revealing a goat. The program will then ask the user if they want to switch doors. The program will then print out whether the user won or lost.

#Conclusion
This project demonstrates how to use stacks and queues to implement a simple game. The project also highlights the importance of choosing the right data structure for the job. In this case, a stack is the ideal data structure for representing the three doors, because it allows the host to easily reveal one of the doors without revealing the car.

					AUTHORS
1. Mariam Yoda				ALX Software Engineering Student
2. Samuel Ayitey			ALX Software Engineering Student
