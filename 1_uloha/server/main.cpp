#include "include/Server.h"

int main(int argc, char **argv) {

    if (argc <= 1) {
        cout << "Nezadali jste port na kterem ma server poslouchat." << endl;
        return 1;
    }

    Server server = Server(stoi(argv[1]));

    server.Run_Server();

    return 0;
}
