# CS 4310 - FreeNOS
- Andrew Arteaga
- Sergey Hambardzumyan
- Zane Reis
## Wait
Created the wait command inside of FreeNOS. This command let's you choose a currently running procces and wait on it. The command waits until the process terminates, and during the waiting time no other commands can be ran.
## Priority
Processes are given a priority level, with a default level of 3, and can range from 1 through 5. The process list command can display the priority levels of each process with a flag option. We also created a renice command, similar to Ubuntu, that allows you to change the priority level of a specified process. The scheduler runs processes based on priority level, a process with a priority of 5 will have the highest precendence.
