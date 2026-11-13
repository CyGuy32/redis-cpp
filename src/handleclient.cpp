#include <iostream>
#include <sys/socket.h>

#include "handleclient.hpp"

void handleclient(int client_fd) {

    const std::string PONG_RESPONSE = "+PONG\r\n";

    std::cout << "Client connected\n";

    char buffer[1024];
    ssize_t bytes_received = recv(client_fd, buffer, sizeof(buffer), 0);

    while (bytes_received > 0) {
      send(client_fd, PONG_RESPONSE.c_str(), PONG_RESPONSE.length(), 0);
      bytes_received = recv(client_fd, buffer, sizeof(buffer), 0);
    }
}