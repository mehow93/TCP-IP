#include <iostream>
#include <sys/socket.h> // anable using socks
#include <netinet/in.h>  // anable using structsockaddr_in
#include <string.h> // anable memset()
#include <arpa/inet.h> // anable inet_pton
#include <istream> // anable read
#define PORT 2399
using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    int sock_fd = socket(AF_INET,SOCK_STREAM,0);

    struct sockaddr_in address; // adres
    struct sockaddr_in serv_addr; // server address
    char msg []= "Hello Server";



    memset(&serv_addr,'0',sizeof(serv_addr));

    serv_addr.sin_family = AF_INET; // IPv4 protocol
    serv_addr.sin_port = htons(PORT); // htons convert PORT to network order
    inet_pton(AF_INET,"127.0.0.1",&serv_addr.sin_addr); // convert do adres to binary
    connect(sock_fd,(struct sockaddr *)&serv_addr, sizeof(serv_addr));
    send(sock_fd,msg,strlen(msg),0);
    cout<< "Messange send"<<endl;


    return 0;
}
