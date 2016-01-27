/* 
 * File:   main.cpp
 * Author: vnc
 *
 * Created on January 22, 2016, 7:48 PM
 */

#include <cstdlib>
#include "net.h"
#include <stdlib.h>
#include <signal.h>
#include <string.h>
//using namespace std;

int process();

/*
 * 
 */
int main(int argc, char** argv) {

    // create socket

    const int port = 40000;
    net::Socket socket;
    if ( !socket.Open( port ) )
    {
        printf("%s", "failed to create socket!\n");
        return 0;
    }

    // receive packets
    char buffer[65535];

    while ( __AFL_LOOP(1000) )
    {
        memset(buffer, 0, 65535);
        size_t bytes_read = read(0, buffer, 65535);

        //net::Address sender;
        //int bytes_read = socket.Receive( sender, buffer, sizeof( buffer ) );
        if ( !bytes_read )
            continue;
        
        // process packet
        process();
    }
    
    return 0;
}

int process(){
	printf("%s", "packet received\n");
	return 0;
}
