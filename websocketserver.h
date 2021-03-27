#ifndef WEBSOCKETSERVER_H
#define WEBSOCKETSERVER_H

#include<string>
#include "websocket.h"
#include "serverinterface.h"

class websocketserver : virtual public serverinterface
{

public:
    enum ServerState { Closed, Listening };
    websocketserver();
    virtual ~websocketserver();
    bool start_tvplus_service(const std::string& Address, unsigned short port);
    unsigned short port() const;
    ServerState serverState() const { return m_state; }
    void close();

private:
    ServerState m_state;
    std::string Address;
    unsigned short m_port;
    websocket *m_websocket;
};



#endif // WEBSOCKETSERVER_H
