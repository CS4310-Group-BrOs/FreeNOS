# CS 4310 - FreeNOS
- Andrew Arteaga
- Sergey Hambardzumyan
- Zane Reis
## Wait
We created the `wait` command inside FreeNOS. This command lets you choose a currently running process and wait on it. The command waits until the process terminates, and no other commands can be run during the waiting time.
## Priority
Processes are given a priority level ranging from 1 through 5 with a default level of 3. The process list (`ps`) command displays the priority levels of processes via the `-l` flag. We also created an implementation of `renice`. Similar to the corresponding POSIX command, it allows you to change the priority level of a specified process. The scheduler runs processes based on their priority level. A process with a priority of 5 will have the highest precedence.
