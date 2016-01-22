/* 
 * File:   main.cpp
 * Author: vnc
 *
 * Created on January 22, 2016, 7:48 PM
 */

#include <cstdlib>
#include "net.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    // create socket

    const int port = 30000;
    net::Socket socket;
    if ( !socket.Open( port ) )
    {
        cout << "failed to create socket!\n";
        return false;
    }

    // send a packet

    const char data[] = "hello world!";
    socket.Send( net::Address(127,0,0,1,port), data, sizeof( data ) );

    // receive packets

    while ( true )
    {
        net::Address sender;
        unsigned char buffer[256];
        int bytes_read = socket.Receive( sender, buffer, sizeof( buffer ) );
        if ( !bytes_read )
            break;
        
        // process packet
        cout << "packet received\n";
    }
    
    return 0;
}

