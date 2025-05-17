#include <iostream>
#include <unistd.h>      
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>

using namespace std;

int main() {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(54000);
    addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_fd, (sockaddr*)&addr, sizeof(addr));
    listen(server_fd, 1);

    cout << "Waiting for connection...\n";
    int client_fd = accept(server_fd, nullptr, nullptr);
    cout << "Client connected!\n";

    char buffer[1024];
    int bytes;

    while (true) {
        bytes=(read(client_fd, buffer, sizeof(buffer)));
        cout << "Received: " << string(buffer, bytes) << "\n";
        
        write(client_fd, buffer, sizeof(buffer));  // echo back
    }

    close(client_fd);
    close(server_fd);
    return 0;
}
