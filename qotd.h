// qotd.h    Header file for QOTD project
#include <winsock2.h>

const int  MAX_SERVER_NAME  = 128;
const int  MAX_HOST_SIZE    = 32;
const int  MAX_SERVICE_SIZE = 32;
const int  MAX_HOSTNAME     = 1024;
const int  MAX_PORT         = 128;
const int  MAX_RECV_BUF     = 2048;
const int  MAX_SEND_BUF     = 2048;
const int  WAIT_TIME = 15;

int    wait(SOCKET, int, int);
SOCKET passivesock (const char*, const char*);
SOCKET connectsock (const char*, const char*, const char*);
char* timestamp();
char* getMyIPAddress();
int getIPAddressInfo(char*, char*);
int UDP_recv(SOCKET, char*, int, char*, char*);
int UDP_send(SOCKET, char*, int, const char*, const char*);

