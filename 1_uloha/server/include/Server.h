#pragma once

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <arpa/inet.h>
#include <algorithm>
#include <pthread.h>
#include "client/Server_Client.h"
#include "other/Other.h"
#include <list>
#include <thread>

#define ERR_SOCK 8
#define ERR_BIND 9
#define ERR_CONN 10
#define ERR_PARAM 11

#define MAX_CLIENTS 100

#define MAX_MESS_SIZE 255

using namespace std;

/**
 * Definice tridy server.
 * Obsahuje vsechny potrebne atributy pro beh serveru.
 */
class Server {

private:

    /* Socket serveru. */
    int server_socket;

    /* Struktura pro adresu. */
    struct sockaddr_in addr;

    /* Urcuje, jestli server bezi. */
    bool running;

    /* Seznam vlaken, ktera obsluhuji klienty. */
    //list<thread> client_threads;

public:

    Server(int port);

    virtual ~Server();

    /*  */
    void Run_Server();

    static void * Handle_Client(void *client_socket);

    /* Radne zavre socket a dekrementuje pocet klientu na serveru. */
    static void Close_Socket(int socket);

    static void Closed_Stream(int client_socket);

};
