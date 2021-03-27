#ifndef TVPLUSWEBSOCKETCLIENT_H
#define TVPLUSWEBSOCKETCLIENT_H

#include <libwebsockets.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


class tvpluswebsocketclient
{
public:
    enum protocols
    {
            PROTOCOL_EXAMPLE = 0,
            PROTOCOL_COUNT
    };
    tvpluswebsocketclient();
    virtual ~tvpluswebsocketclient();
    static struct lws_protocols protocols[];
    struct lws_context_creation_info info;
    static int callback_example( struct lws *wsi, enum lws_callback_reasons reason, void *user, void *in, size_t len );
    struct lws_context *context;
    void run();
};

#endif // TVPLUSWEBSOCKETCLIENT_H
