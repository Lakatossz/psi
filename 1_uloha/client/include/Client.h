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
#include "other/Other.h"
#include <list>
#include <thread>

#define ERR_SOCK 8
#define ERR_BIND 9
#define ERR_CONN 10
#define ERR_PARAM 11

#define MAX_MESS_SIZE 256

using namespace std;

/**
 * Definice tridy klient.
 * Obsahuje vsechny potrebne atributy pro beh klienta.
 */
class Client {

private:

    /** Port, na ktery se klient pripoji. */
    int port;

    /** Zprava, ktera bude odeslana. */
    char message[MAX_MESS_SIZE] = { 0 };

    /** Delka zpravy. */
    int message_length = 0;

public:

    /** Vytvori noveho klienta s danymi parametry. */
    Client(int port, string message);

    /**
     * Spusti klienta, ktery se pripoji na server a
     * posle zadanou zpravu, nasledne posloucha odpoved.
     */
    void Run_Client();
};
