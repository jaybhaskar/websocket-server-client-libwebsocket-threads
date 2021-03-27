#ifndef SERVERINTERFACE_H
#define SERVERINTERFACE_H

#include<string>

class serverinterface
{
public:
    serverinterface() {}
    virtual ~serverinterface() {}
    virtual bool start_tvplus_service(const std::string& Address, unsigned short port) = 0;
    virtual unsigned short port() const = 0 ;
    virtual void close() =0;
};

#endif // SERVERINTERFACE_H
