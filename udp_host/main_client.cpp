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

    const int port = 30000;
    const int port_to_send_to = 40000;
    net::Socket socket;
    if ( !socket.Open( port ) )
    {
        cout << "failed to create socket!\n";
        return false;
    }

    // send a packet

    const char data[] = "hello world!";
    socket.Send( net::Address(127,0,0,1,port_to_send_to), data, sizeof( data ) );
    
    return 0;
}

