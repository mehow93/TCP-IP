#include <iostream>
#include <sys/socket.h> // anable using socks
#include <netinet/in.h>  // anable using structsockaddr_in
#define PORT 2399
using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    int sockfd = socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in address; // adres
    struct sockaddr_in serv_addr; // server address
    return 0;
}
