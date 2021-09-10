#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string>
#include <unistd.h>
#include "commands.h"

class BotClient {
    private:
        int socketfd;
        int packet_len;

    void hello(char cmd_output[256]) {
        std::cout << "PROCESSING" << std::endl;
        sprintf(cmd_output, "HELLO!!");
    }

    void send_msg(char message[]) {
        send(socketfd, message, packet_len, 0);
    }

    int msg_to_cmd(char message[]) {
        const char *errstr;
        int command = strtonum(message, 0, 100, &errstr);

        if (errstr) {
            return -1;
        }

        return command;
    }

    public:
        BotClient(int socketfd, int packet_len = PACKET_LEN) {
            this->socketfd = socketfd;
            this->packet_len = packet_len;
        }


    void process_command(char message[]){
        //convert string command to int
        int command = msg_to_cmd(message);

        char cmd_output[256] = {'\0'};
        bool cmd_ran = true;

        //determine command to to run
        switch (command) {
            case SAY_HELLO:
                hello(cmd_output);
                break;
            default:
                std::cout << "NOT A VALID COMMAND" << std::endl;
                cmd_ran = false;
        }

        if (!cmd_ran || cmd_output == NULL) {
            return;
        }

        send_msg(cmd_output);
    }

    void clean_up() {
        close(this->socketfd);
    }
};

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
       exit(0);
    }

    std::cout << "CONNECTION ESTABLISHED" << std::endl;

    //create client
    BotClient bc(network_socket);

    char server_command[256];
    int bytes_read = recv(network_socket, server_command, 256, 0);
    std::cout << bytes_read << " " << server_command << " " << strlen(server_command) << std::endl;

    bc.process_command(server_command);



    close(network_socket);

    return 0;
}