# threadDemo

A Windows console app demonstrating C++ thread basics. 

To start or stop a thread running a dummy function, enter these commands:
> *test start*

> *test stop*

To start or stop a thread running a counter function, enter:
> *counter start number*

> *counter stop*

where *number* is the counter's limit. Decimals are truncated to integers.

Threads can run simultaneously. To stop all active threads and exit the program, enter:
> *exit*

### Motivation
I wrote this simple thread project for later reference. Hopefully, it will be helpful for anyone who stumbles on it trying to learn C++ threads.

### Future Updates
- None planned.

### Known Issues
- User input is case-sensitive.

### ChangeLog
v1.1.1
- Added error handling to counter function.
- Fixed bug causing counter thread to stall on reaching limit.
- Moved start() function to main().
- Miscellaneous housekeeping.