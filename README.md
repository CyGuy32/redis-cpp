# Redis Server in C++

A Redis server implementation in progress, built to learn C++, socket programming,
and debugging. I'm using this project to understand how clients connect to a
server, how bytes move over TCP, and how Redis represents commands and responses.

## Current progress

- Creates an IPv4 TCP listening socket on port `6379`.
- Accepts one client connection.
- Sends the hardcoded RESP response `+PONG\r\n`, then exits.

The server currently sends its response immediately after connecting. Command
reading and parsing, repeated requests, and key-value storage are not implemented
yet.

## Build and run locally

On macOS, with a C++23-capable `clang++` compiler:

```sh
clang++ -std=c++23 src/main.cpp -o /tmp/redis-learning
/tmp/redis-learning
```

In another terminal on the same computer:

```sh
nc -v 127.0.0.1 6379
```

The client should display `+PONG`. Restart the server for each connection.
Ensure another Redis instance is not already using port `6379`.

## Debugging notes

During local testing, an existing Redis instance was listening on
`127.0.0.1:6379`, while this server was bound to the wildcard address on the same
port. The client reached the existing instance instead of this program.
Inspecting listeners with `lsof` and testing on a different port helped identify
the conflict.

## Acknowledgment

Started from the C++ starter repository for the
[CodeCrafters Build Your Own Redis challenge](https://codecrafters.io/challenges/redis).
I'm working through the implementation incrementally and documenting what I learn.
