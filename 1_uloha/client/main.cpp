#include "include/Client.h"

int main(int argc, char **argv) {

    /** Zkontrolujeme parametry. */
    if (argc < 3) {
        cout << "Nezadali jste port, na ktery se ma klient pripojit nebo zpravu, kterou ma klient poslat ." << endl;
        return EXIT_FAILURE;
    }

    cout << "Spoustim klienta." << endl;

    int port;
    string message;

    try {
        port = stoi(argv[1]);
        message = string(argv[2]);
    } catch (const std::invalid_argument & e) {
        cout << "Parametr musi byt cislo!\n";
        return EXIT_FAILURE;
    } catch (const std::out_of_range & e) {
        cout << "Spatne cislo portu.\n";
        return EXIT_FAILURE;
    }

    if (port <= 65535 && port >= 1) {
        if (message.length() <= 255 && message.length() > 0) {
            Client client = Client(port, message);

            client.Run_Client();

            cout << "Koncim klienta." << endl;
        } else
            cout << "Spatna delka zpravy." << endl;
    } else
        cout << "Spatne cislo portu." << endl;

    return EXIT_SUCCESS;
}
