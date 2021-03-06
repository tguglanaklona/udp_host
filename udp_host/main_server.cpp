/* 
 * File:   main.cpp
 * Author: vnc
 *
 * Created on January 22, 2016, 7:48 PM
 */

#include <cstdlib>
#include "net.h"
using namespace std;
#include <iostream>

/*
 * 
 */
int main(int argc, char** argv) {

    // create socket

    const int port = 40000;
    net::Socket socket;
    if ( !socket.Open( port ) )
    {
        cout << "failed to create socket!\n";
        return false;
    }

    // receive packets

    while ( true )
    {
        net::Address sender;
        unsigned char buffer[65534];
        int bytes_read = socket.Receive( sender, buffer, sizeof( buffer ) );
        if ( !bytes_read )
            continue;
        
        // process packet
        cout << "packet received\n";
    }
    
    return 0;
}

