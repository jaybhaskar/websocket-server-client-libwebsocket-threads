#ifndef WEBSOCKET_H
#define WEBSOCKET_H


class websocket
{
public:
    websocket();
    virtual ~websocket();
    virtual void run() = 0;

};

#endif // WEBSOCKET_H
