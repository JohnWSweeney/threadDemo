# threadDemo

A Windows console app demonstrating C++ thread/concurrency basics. 

## Motivation
I approached writing this project as if I were teaching a crash course on everything I currently know about C++ concurrency. It's a big and important topic for embedded systems, so I'll update it as I learn new techniques. Hopefully, it will be helpful for anyone who stumbles on it in the meantime.

## Functions
Enter the command keywords separated by a space. Commands are currently case-sensitive and must be lower-case. The app supports threads so multiple functions can run simultaneously.

### Dummy Thread
To start or stop a thread running a dummy "hello, world" function, enter these commands:
> *dummy start* <br/>
> *dummy stop*

### Counter Thread
Demonstrates how to pass parameters to a threaded function. To start or stop a thread running a counter function, enter:
> *counter start counterMAX* <br/>
> *counter stop*

where *counterMAX* is the counter's upper limit. Decimals entered for *counterMAX* are truncated to integers. Increments occur every five seconds. 

### App Control
 To stop all active threads, enter:
> *stop all*

 To stop all threads and exit the program, enter:
> *exit*

### Future Updates
- Demonstrate mutex, async features.

### Known Issues
- User input is case-sensitive.

## Download
[threadDemo v1.1.2](https://github.com/JohnWSweeney/threadDemo/releases/download/v1.1.2/threadDemo_v1_1_2.exe) [29 kB]

### ChangeLog
v1.1.2
- Compliled for "release" instead of "debug" (oops). 
- Each .cpp now has its own header.
- Moved atomic bool function status variables to separate .h/.cpp files.
- Moved functions and threaded function calls to separate .h/.cpp files.

v1.1.1
- Added error handling to counter function.
- Fixed bug causing counter thread to stall on reaching limit.
- Moved start() function to main().
- Miscellaneous housekeeping.