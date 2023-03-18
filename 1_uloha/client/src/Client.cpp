#include "../include/Client.h"

Client::Client(int port, string message)
{
    this->port = port;
    this->message_length = message.length();
    memcpy(this->message + 1, message.c_str(), this->message_length);
    this->message[0] = ((char) message.length());
}

Client::~Client()
{

}

void Client::Run_Client()
{
    int client_fd;
    struct sockaddr_in server_addr;
    char buffer[MAX_MESS_SIZE] = { 0 };
    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        cout << "Nepodarilo se vytvorit socket"<< endl;
        return;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(this->port);

    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
        cout << "Nevalidni adresa" << endl;
        return;
    }

    if ((connect(client_fd, (struct sockaddr*)&server_addr, sizeof(server_addr))) < 0) {
        cout << "Nepodarilo se pripojit na server." << endl;
        return;
    }

    int return_value = send(client_fd,  this->message, this->message_length + 1, 0);
    if (return_value > 0) {
        cout << "Byla odeslana zprava: " << this->message + 1 << " (" << return_value << ")" << endl;
    } else {
        cout << "Nepodarilo se odeslat zpravu." << endl;
        return;
    }

    return_value = read(client_fd, buffer, MAX_MESS_SIZE);

    if (return_value > 0) {
        cout << "Byla ze serveru prijata zprava: " << buffer << endl;
    } else {
        cout << "Server nic neposlal." << endl;
    }

    close(client_fd);
}
