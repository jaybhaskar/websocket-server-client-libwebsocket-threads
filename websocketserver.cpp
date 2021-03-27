#include "websocketserver.h"
#include "websocketimpl.h"

websocketserver::websocketserver()
{
    m_websocket = new websocketimpl();
}

websocketserver::~websocketserver()
{

}
bool websocketserver::start_tvplus_service(const std::string& Address, unsigned short port)
{
        m_websocket->run();
        return true;
}

unsigned short websocketserver::port() const
{
    return m_port;
}


void websocketserver::close()
{

}
