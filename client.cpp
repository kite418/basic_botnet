#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string>
#include <unistd.h>
#include "commands.h"

void hello() {
    std::cout << "HELLO!!@#!@#!@#!@#" << std::endl;
}

void process_command(char command[]){

    //convert string command to int
    const char *errstr;
    int command_id = strtonum(command, 0, 100, &errstr);
    if (errstr) {
        return;
    }

    //determine command to to run
    switch (command_id == SAY_HELLO) {
        case 1:
            hello();
            break;
        default:
            std::cout << "NOT A VALID COMMAND" << std::endl;
    }

}


int main() {
    int network_socket;
    network_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;

    int connection_status = connect(network_socket, (struct sockaddr*) &server_address, sizeof(server_address));
    if (connection_status == -1) {
       std::cout << "ERROR CONNECTING IDK" << std::endl;
    }

    std::cout << "CONNECTION ESTABLISHED" << std::endl;
    char server_command[256];
    recv(network_socket, server_command, sizeof(server_command), 0);

    process_command(server_command);

    close(network_socket);

    return 0;
}