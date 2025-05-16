#include <iostream>
#include <unistd.h> 
#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstring>
using namespace std;

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return 1;
    }

    sockaddr_in addr{};
    addr.sin_family = AF_INET;

    cout << "Enter server IP: ";
    string ip_address;
    cin >> ip_address;

    if (inet_pton(AF_INET, ip_address.c_str(), &addr.sin_addr) <= 0) {
        cerr << "Invalid IP address\n";
        return 1;
    }

    cout << "Enter port: ";
    int port;
    cin >> port;
    cin.ignore();  
    addr.sin_port = htons(port);

    if (connect(sock, (sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("Connection failed");
        return 1;
    }

    string input;
    char buffer[1024];

    while (true) {
        cout << "> ";
        getline(cin, input);
        if (input.empty()) break;

        write(sock, input.c_str(), input.size());
        int bytes = read(sock, buffer, sizeof(buffer));
        if (bytes == 0) {
            cout << "Server closed the connection.\n";
            break;
        } else if (bytes < 0) {
            perror("Read error");
            break;
        }

        cout << "Server echoed: " << string(buffer, bytes) << "\n";
        
    }

    close(sock);
    return 0;
}
