#pragma once

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <sys/time.h>
#include <cstring>
#include "../other/Other.h"

/**
 * Definice tridy predstavujici klienta.
 */
class Server_Client {

private:

    /* Cislo socketu, na kterem klient posloucha. */
    int socket_number;

    /* Posledni cas, kdy se klient ozval. */
    long long last_time;

    /* Stav klienta. 1 - pripojen, 0 - odpojen. */
    bool connected;

public:

    explicit Server_Client(int socket_number);

    virtual ~Server_Client();

    int GetSocket();

    void SetLastTime(long long last_time);

    long long GetLastTime();

    void SetConnected(bool connected);

    bool GetConnected();
};
