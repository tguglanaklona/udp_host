/* 
 * File:   address.h
 * Author: vnc
 *
 * Created on January 22, 2016, 7:52 PM
 */

#ifndef ADDRESS_H
#define	ADDRESS_H

class Address
    {
    public:

        Address();
        Address( unsigned char a, unsigned char b, unsigned char c, unsigned char d, unsigned short port );
        Address( unsigned int address, unsigned short port );
        unsigned int GetAddress() const;
        unsigned char GetA() const;
        unsigned char GetB() const;
        unsigned char GetC() const;
        unsigned char GetD() const;
        unsigned short GetPort() const;
        bool operator == ( const Address & other ) const;
        bool operator != ( const Address & other ) const;

    private:

        unsigned int address;
        unsigned short port;
    };

#endif	/* ADDRESS_H */

