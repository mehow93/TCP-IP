

#include <sys/socket.h> // enable using socks
#include <netinet/in.h>  // enable using structsockaddr_in
#include <string.h> // enable using memset()
#include <arpa/inet.h> // enable using inet_pton
#include <string>
#include <cstring>
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
            ("msg",  po::value<string>(), "set txt messange")
            ("n",    po::value<int>(), "set quantity of messanges")

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

    }
    if (vm.count("msg")){
        cout<<"Messange set to "
           << vm["msg"].as<string>() << ".\n";
    }
    if (vm.count("n")){
        cout<<"Quantity of messanges: "
           << vm["n"].as<int>() << ".\n";
    }
    int port_num = vm["port"].as<int>(); // creating variable for port
    string msg_txt = vm["msg"].as<string>(); // creating txt of messange
    int n = vm["n"].as<int>(); // Quantity of messanges

    struct sockaddr_in serv_addr; // server address
    memset(&serv_addr,'0',sizeof(serv_addr));
    serv_addr.sin_family = AF_INET; // IPv4 protocol
    serv_addr.sin_port = htons(port_num); // htons convert PORT to network order
    inet_pton(AF_INET,"127.0.0.1",&serv_addr.sin_addr); // convert do adres to binary
    int sock_fd = socket(AF_INET,SOCK_STREAM,0);

    connect(sock_fd,(struct sockaddr *)&serv_addr, sizeof(serv_addr));
    char cstry[msg_txt.size()+1]; // making space for converting string to char
    strcpy(cstry, msg_txt.c_str()); //copy

   for(int i=0; i<n; i++)// sending
    send(sock_fd,cstry,strlen(cstry),0);

    cout<< "Messange send"<<endl;
    shutdown(sock_fd,-2);
    cout<<"Connection shutted down"<<endl;
    return 0;
}
