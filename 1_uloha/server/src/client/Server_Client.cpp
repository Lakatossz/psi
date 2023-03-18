#include "../../include/client/Server_Client.h"

Server_Client::Server_Client(int socket_number)
{
    this->socket_number = socket_number;
    connected = false;
    last_time = time_in_milli();
}

Server_Client::~Server_Client()
{
    this->socket_number = 0;
    connected = false;
}

int Server_Client::GetSocket()
{
    return socket_number;
}

void Server_Client::SetLastTime(long long last_time)
{
    this->last_time = last_time;
}

long long Server_Client::GetLastTime()
{
    return last_time;
}

void Server_Client::SetConnected(bool connected)
{
    this->connected = connected;
}

bool Server_Client::GetConnected()
{
    return connected;
}
