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

#define ERR_SOCK 8
#define ERR_BIND 9
#define ERR_CONN 10

#define MAX_CLIENTS 1000

#define MAX_MESS_SIZE 256

using namespace std;

/**
 * Definice tridy server.
 * Obsahuje vsechny potrebne atributy pro beh serveru.
 */
class Server {

private:

    /** Socket serveru. */
    int server_socket;

    /** Struktura pro adresu. */
    struct sockaddr_in addr;

    /** Urcuje, jestli server bezi. */
    bool running;

public:

    /** Vytvori nevy server s danym portem. */
    Server(int port);

    /** Spusti server, uvede ho do stavu, kdy je pripraven na pripojeni klientu. */
    void Run_Server();

    /** Zpracuje komunikaci s klientem (funkce vlakna). */
    static void * Handle_Client(void *client_socket);

    /** Radne zavre socket a dekrementuje pocet klientu na serveru. */
    static void Close_Socket(int socket);

    /** Zavre socket, pokud se klient neocekavane odpojil. */
    static void Closed_Stream(int client_socket);

};
