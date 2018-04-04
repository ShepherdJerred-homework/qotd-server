// qotdUDPServer
// Jerred Shepherd
#include "qotd.h"
#include <iostream>
#include <fstream>
#include <WinSock2.h>

const int MAX_SIZE = 2048;
const char *port = "17";

using std::cout;
using std::endl;
using std::ifstream;
#pragma comment (lib,"ws2_32.lib")

void printIp() {
    char myIPAddress[16];
    char broadcastAddress[16];

    int status = getIPAddressInfo(myIPAddress, broadcastAddress);
    if (status >= 0) {
        cout << timestamp() << " - " << "Started qotd service on " << myIPAddress << ":" << port << endl;
    } else {
        cout << "Error getting IP address" << endl;
        exit(1);
    }
}

void main() {
    WORD wVersionRequired = 0x0101;
    WSADATA wsaData;
    int err = WSAStartup(wVersionRequired, &wsaData);
    if (err) {
        cout << "Unable to initialize Windows Socket library" << endl;
        return;
    }

    printIp();

    SOCKET s;
    s = passivesock(port, "UDP");

    char buffer[MAX_RECV_BUF];
    char remoteHost[MAX_HOST_SIZE];
    char remotePort[MAX_PORT];
    int numBytesReceived = UDP_recv(s, buffer, MAX_RECV_BUF, remoteHost, remotePort);

    if (buffer == "sendQOTD") {

    } else if (buffer == "shutdown") {

    }

    ifstream fin("qotd.txt");
    if (fin.is_open()) {
        fin.clear();
        char textLine[MAX_SIZE];
        fin.getline(textLine, MAX_SIZE - 2);
        while (!fin.eof()) {
            strcat_s(textLine, MAX_SIZE, "\n");
            int numberCharactersSent = UDP_send(s, textLine, strlen(textLine + 1), remoteHost, remotePort);
            fin.getline(textLine, MAX_SIZE - 2);
        }
    }
}
