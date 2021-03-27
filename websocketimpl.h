#ifndef WEBSOCKETIMPL_H
#define WEBSOCKETIMPL_H

#include<libwebsockets.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "websocket.h"

class websocketimpl : public websocket
{
public:
    enum protocols
    {
        PROTOCOL_HTTP = 0,
        PROTOCOL_EXAMPLE,
        PROTOCOL_COUNT
    };
    websocketimpl();
    virtual ~websocketimpl();
    virtual void run();
private:
    struct lws_context_creation_info info;
    static struct lws_protocols protocols[];
    struct lws_context *context;
    static int callback_http( struct lws *wsi, enum lws_callback_reasons reason, void *user, void *in, size_t len );
    static int callback_example( struct lws *wsi, enum lws_callback_reasons reason, void *user, void *in, size_t len );
};

#endif // WEBSOCKETIMPL_H
