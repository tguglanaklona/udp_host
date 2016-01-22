/* 
 * File:   socket.h
 * Author: vnc
 *
 * Created on January 22, 2016, 7:50 PM
 */

#ifndef SOCKET_H
#define	SOCKET_H

#ifndef ADDRESS_H
#include "address.h"
#endif

class Socket
    {
    public:

        Socket();
        ~Socket();
        bool Open( unsigned short port );
        void Close();
        bool IsOpen() const;
        bool Send( const Address & destination, const void * data, int size );
        int Receive( Address & sender, void * data, int size );

    private:

        int handle;
    };

#endif	/* SOCKET_H */

