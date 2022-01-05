# 21-minitalk
## Build
* **`make`** - *build server and client*
* **`make server`** - *build server only*
* **`make client`** - *build client only*
* **`make clean`** - *delete object files*
* **`make fclean`** - *delete object and executable files*
## Usage (Only UNIX system)
1. **`./server`** - starting the server, it will listen for messages until it is killed by signals. \
Server display your PID, which needs to be passed to the client.
2. **`./client <PID> <message to server>`** - where in <...> arguments:
   * **`<PID>`** - PID's server
   * **`<message to server>`** - the message to send to the server
## Example 
> Start server
* **`./server`**

> Output:
* **`PID: 37396`**

> In another terminal send a message to the server
* **`./client 38035 "Hello, world\! "`** 

> In the terminal where the server is running, the message will appear: 
* **`Hello, world!`**