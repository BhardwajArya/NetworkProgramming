#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <cstring>
#include <iostream>
using namespace std;
int main() {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);


    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    bind(server_fd, (sockaddr*)&address, sizeof(address));

    cout<<"Server listening on port 8080"<<endl;

    int client_fd = accept(server_fd, NULL, NULL);

    const char* msg = "Hello from server";
    send(client_fd, msg, strlen(msg), 0);
    close(client_fd);
    close(server_fd);

}
