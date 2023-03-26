#include "../include/Server.h"

static fd_set master;

void die(const string& message, int err) {
    cout << "chyba: " << message << endl;
    exit(err);
}

Server::Server(int port)
{
    int skt, res, param = 1;

    skt = socket(AF_INET, SOCK_STREAM, 0);
    if(skt < 0) {
        die("Cannot make socket.\n", ERR_SOCK);
        return;
    }

    master = {};
    addr = {};

    server_socket = skt;

    memset(&addr, 0, sizeof(struct sockaddr_in));

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;
    inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);

    res = setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, (const char *)&param, sizeof(int));
    if(res == -1) {
        cout << "setsockopt ERR" << endl;
        return;
    }

    cout << "Server has been created." << endl;

    running = true;
}

void Server::Run_Server()
{
    int res;
    struct sockaddr_in incoming{};
    socklen_t inlen;

    pthread_t client_threads[MAX_CLIENTS] = { 0 };

    fd_set read_fds, write_fds;

    int fdmax, newfd = 0, curr_sock, return_value;

    struct timeval timeout{};

    FD_ZERO(&master);
    FD_ZERO(&read_fds);
    FD_ZERO(&write_fds);

    cout << "-------------SERVER IS RUNNING----------\n" << endl;
    cout << "IP address: " << inet_ntoa(addr.sin_addr) << endl;
    cout << "Listening on port: " << htons(addr.sin_port) << endl;

    res = bind(server_socket, (struct sockaddr *) &addr, sizeof(struct sockaddr_in));
    if (res != 0) {
        perror("error: ");
        die("Nelze nabindovat adresu.", ERR_BIND);
        return;
    }

    timeout.tv_sec = 0;
    timeout.tv_sec = 10000;
    res = setsockopt(server_socket, SOL_SOCKET, SO_RCVTIMEO, (const char *)&timeout, sizeof(timeout));
    if (res == -1) {
        cout << "set recv timeout ERR" << endl;
        return;
    }

    cout << "Bind OK" << endl;

    /** Server zacina poslouchat. */
    res = listen(server_socket, MAX_CLIENTS);
    if (res != 0) {
        die("Nemuze vytvorit frontu spojeni.", ERR_CONN);
        return;
    }

    cout << "Listen OK" << endl;

    FD_SET(server_socket, &master);

    /** Zatim nejvetsi cislo socketu je to, kde server posloucha. */
    fdmax = server_socket;

    cout << "-------------SERVER IS READY------------" << endl;

    int thread_number = 0;

    while (running) {

        timeout.tv_sec = 0;
        timeout.tv_usec = 1000;

        read_fds = master;
        write_fds = master;

        return_value = select(FD_SETSIZE, &read_fds, &write_fds, nullptr, &timeout);

        if (thread_number > 100) {
            for(int i = 0; i < 50; i++) {
                pthread_join(client_threads[i], nullptr);
            }
            thread_number -= 50;
        }

        /** Posloucha, pokud se pripoji nejaky novy klient. */
        if(return_value == -1) {
            cout << "Server-select() error!" << endl;
            return;
        } else if(return_value) {
            usleep(1);
            inlen = sizeof(incoming);
            if((newfd = accept(server_socket, (struct sockaddr *)&incoming, &inlen)) == -1) {
                cout << "Server-accept() error" << endl;
                return;
            } else {
                /** Vse se podarilo, na serveru je novy klient. */
                cout << "Server-accept() is OK..." << endl;
                FD_SET(newfd, &master);
                if(newfd > fdmax) {
                    fdmax = newfd;
                }

                cout << "Nove spojeni z ip adresy " << inet_ntoa(incoming.sin_addr) << " na socketu " << newfd << endl;

                /** Tady otevru vlakno, kde budu zpracovavat klienty */
                if (pthread_create(&client_threads[thread_number], nullptr, &Server::Handle_Client, &newfd) != 0) {
                    cout << "Nepodarilo se vytvorit vlakno." << endl;
                }
                thread_number++;
            }
        }
    }
}

void * Server::Handle_Client(void *client_socket)
{
    char buf[MAX_MESS_SIZE] = { 0 };
    size_t return_value;

    int socket = (*(int*) client_socket);

    memset(buf, 0, MAX_MESS_SIZE);

    cout << "Zpracovavam klienta na socketu " << socket << endl;
    return_value = recv(socket, buf, MAX_MESS_SIZE, 0);
    if(return_value < 1) {
        /** Socket je zavreny. */
        cout << "Odpojil jsem klienta na socketu: " << return_value << endl;
        Closed_Stream(socket);
        return nullptr;
    } else if (return_value > MAX_MESS_SIZE) {
        cout << "Zprava byla prilis velka!" << endl;
        Closed_Stream(socket);
        return nullptr;
    } else {

        cout << "Delka zpravy: " << (int) buf[0] << endl;
        cout << "Obsah zpravy: " << string(buf + 1) << endl;

        string str = string(buf + 1);
        reverse(str.begin(), str.end());

        memcpy(buf + 1, str.c_str(), str.length());
        buf[0] = (char) str.length();

        cout << "Odesilam zpravu: " << buf << endl;
        send(socket, buf, str.length() + 1, 0);
        Close_Socket(socket);
    }

    return nullptr;
}

void Server::Close_Socket(int socket)
{
    close(socket);
    FD_CLR(socket, &master);
}

void Server::Closed_Stream(int client_socket)
{
    Close_Socket(client_socket);
    cout << "Odpojil jsem klienta, znenadani zavrel socket (recv vratil -1) - po timeoutu." << endl;
}
