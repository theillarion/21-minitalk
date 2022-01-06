# 21-minitalk
## Summary
The purpose of this project is to code a small data exchange program
using UNIX signals. 
## Solutions
Implemented two solutions with different approaches to interprocessor communication with signals
## Build
* **`make`** or **`make all`** - *build server and client*
* **`make server`** - *build server only*
* **`make client`** - *build client only*
* **`make clean`** - *delete object files*
* **`make fclean`** - *delete object and executable files*
* **`make re`** - equivalent to two consecutivaly entered commands **`make fclean`** and **`make all`**
* **`make debug`** - *build server and client for debugging*
* **`make server_debug`** - *build only server for debugging*
* **`make client_debug`** - *build only client for debugging*
## Usage (Only UNIX system)
1. **`./server`** - starting the server, it will listen for messages until it is killed by signals. \
Server display your PID, which needs to be passed to the client.
2. **`./client <PID> <message to server>`** - where in <...> arguments:
   * **`<PID>`** - PID's server
   * **`<message to server>`** - the message to send to the server
## Example 
Start server
> **`./server`**

Output:
> **`PID: 37396`**

In another terminal send a message to the server
> **`./client 37396 "Hello, world\! "`** 

 In the terminal where the server is running, the message will appear: 
> **`Hello, world!`**