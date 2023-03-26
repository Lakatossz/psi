#include "include/Server.h"

int main(int argc, char **argv) {

    if (argc <= 1) {
        cout << "Nezadali jste port na kterem ma server poslouchat." << endl;
        return 1;
    }

    int port;

    try {
        port = stoi(argv[1]);
    } catch (const std::invalid_argument & e) {
        cout << "Parametr musi byt cislo!" << endl;
        return EXIT_FAILURE;
    } catch (const std::out_of_range & e) {
        cout << "Spatne cislo portu." << endl;
        return EXIT_FAILURE;
    }

    if (port <= 65535 && port >= 1) {
        Server server = Server(stoi(argv[1]));

        server.Run_Server();
    } else
        cout << "Spatne cislo portu." << endl;

    return 0;
}
