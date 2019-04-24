

#include <sys/socket.h> // enable using socks
#include <netinet/in.h>  // enable using structsockaddr_in
#include <string.h> // enable using memset()
#include <arpa/inet.h> // enable using inet_pton
\

#include <boost/program_options.hpp> //enable usingboost lib
namespace po = boost::program_options;

#include <iostream>
using namespace std;

int main(int ac, char* av[])
{
    cout << "Hello World!" << endl;
    po::options_description desc("Allowed options");
    desc.add_options()
        ("help", "produce help message")
        ("port", po::value<int>(), "set servers port")
        
    ;

    po::variables_map vm;
    po::store(po::parse_command_line(ac, av, desc), vm);
    po::notify(vm);

    if (vm.count("help")) {
        cout << desc << "\n";
        return 1;
    }

    if (vm.count("port")) {
        cout << "Server's port set to "
     << vm["port"].as<int>() << ".\n";
        int port = vm["port"].as<int>();
    } else {
        cout << "Server's port was not set.\n";
    }

   /* struct sockaddr_in serv_addr; // server address
    memset(&serv_addr,'0',sizeof(serv_addr));
    serv_addr.sin_family = AF_INET; // IPv4 protocol
    serv_addr.sin_port = htons(PORT); // htons convert PORT to network order
    inet_pton(AF_INET,"127.0.0.1",&serv_addr.sin_addr); // convert do adres to binary
    
    int sock_fd = socket(AF_INET,SOCK_STREAM,0);
    
    connect(sock_fd,(struct sockaddr *)&serv_addr, sizeof(serv_addr));
    
    char msg []= "Hello Server";
    send(sock_fd,msg,strlen(msg),0);
        
    cout<< "Messange send"<<endl;
     shutdown(sock_fd,-2);
    cout<<"Connection shutted down"<<endl;*/
    return 0;
}
