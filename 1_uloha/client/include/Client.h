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

#define MAX_CLIENTS 5

#define MAX_MESS_SIZE 255

using namespace std;

class Client {

private:

    int port;

    char message[MAX_MESS_SIZE] = { 0 };

    int message_length = 0;

    /* Urcuje, jestli klient bezi. */
    bool running;

public:

    Client(int port, string message);

    ~Client();

    void Run_Client();
};
