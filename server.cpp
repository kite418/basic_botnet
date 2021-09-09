#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include "commands.h"
#include <string.h>

void sayHello(int client_socket) {
    std::string cmd_string =  std::to_string(SAY_HELLO);


    send(client_socket, hello_command, sizeof(hello_command), 0);
}

int main() {
    char server_message[256] = "HELLO!!!!";

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
    close(client_socket);

    return 0;
}
