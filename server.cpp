#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include "commands.h"
#include <string.h>

class BotServer {
private:
    int sockfd;
    int packet_len;

public:
    BotServer(int sockfd, int packet_len = PACKET_LEN) {
        this->sockfd = sockfd;
        this->packet_len = packet_len;
    }


};


void sayHello(int client_socket) {
    char cmd[256];
    std::sprintf(cmd, "%d", SAY_HELLO);
    std::cout << cmd << std::endl ;
    send(client_socket, cmd, sizeof(cmd), 0);
}

int main() {
    int server_socket;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));

    listen(server_socket, 5);

    int client_socket;
    client_socket = accept(server_socket, NULL, NULL);

    sayHello(client_socket);

    char response[PACKET_LEN];
    recv(client_socket, response, sizeof(response), 0);
    std::cout << response << std::endl;

    close(client_socket);

    return 0;
}
