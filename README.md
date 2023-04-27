# threadDemo

A Windows console app demonstrating C++ thread basics. 

### Motivation
I built this simple thread project for later reference. Hopefully, it will be helpful for anyone else who stumbles on it.

### Design Overview
The app accepts three case-sensitive inputs: "start", "stop", and "exit". "start" creates a new thread, calling the *testThread* function, and then detaches the thread. "stop" terminates the thread, which can be restarted by entering "start" again. "exit" terminates the thread, if active, and closes the app.

### Future Updates
- Execute multiple simultaneous threads.

### Known Issues
- Error/exception handling.
- User input is case-sensitive.