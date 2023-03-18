#include "include/Client.h"

int main(int argc, char **argv) {

    if (argc < 1) {
        cout << "Nezadali jste port, na ktery se ma klient pripojit nebo zpravu, kterou ma klient poslat ." << endl;
        return 1;
    }

    cout << "Spoustim klienta." << endl;

    Client client = Client(stoi(argv[1]), argv[2]);

    client.Run_Client();

    cout << "Koncim klienta." << endl;

    return 0;
}
