#include "tvpluswebsocketclient.h"

static struct lws *web_socket = NULL;

#define EXAMPLE_RX_BUFFER_BYTES (10)

tvpluswebsocketclient::tvpluswebsocketclient()
{
    memset( &info, 0, sizeof(info) );

    info.port = CONTEXT_PORT_NO_LISTEN;
    info.protocols = protocols;
    info.gid = -1;
    info.uid = -1;
    context = lws_create_context( &info );
}



tvpluswebsocketclient::~tvpluswebsocketclient()
{
     lws_context_destroy( context );
}

int tvpluswebsocketclient::callback_example( struct lws *wsi, enum lws_callback_reasons reason, void *user, void *in, size_t len )
{
        switch( reason )
        {
                case LWS_CALLBACK_CLIENT_ESTABLISHED:
                        lws_callback_on_writable( wsi );
                        break;

                case LWS_CALLBACK_CLIENT_RECEIVE:
                        printf("[Test Protocol] Received data: %s\n",(char*)in);

                        break;

                case LWS_CALLBACK_CLIENT_WRITEABLE:
                {
                        unsigned char buf[LWS_SEND_BUFFER_PRE_PADDING + EXAMPLE_RX_BUFFER_BYTES + LWS_SEND_BUFFER_POST_PADDING];
                        unsigned char *p = &buf[LWS_SEND_BUFFER_PRE_PADDING];
                        size_t n = sprintf( (char *)p, "%u", rand() );
                        lws_write( wsi, p, n, LWS_WRITE_TEXT );
                        break;
                }

                case LWS_CALLBACK_CLOSED:
                case LWS_CALLBACK_CLIENT_CONNECTION_ERROR:
                        web_socket = NULL;
                        break;

                default:
                        break;
        }

        return 0;
}

struct lws_protocols tvpluswebsocketclient::protocols[] =
{
        {
                "example-protocol",
                callback_example,
                0,
                EXAMPLE_RX_BUFFER_BYTES,
        },
        { NULL, NULL, 0, 0 }
};



void tvpluswebsocketclient::run() {
    time_t old = 0;
    while( 1 )
    {
            struct timeval tv;
            gettimeofday( &tv, NULL );

            if( !web_socket && tv.tv_sec != old )
            {
                    struct lws_client_connect_info ccinfo = {0};
                    ccinfo.context = context;
                    ccinfo.address = "localhost";
                    ccinfo.port = 8000;
                    ccinfo.path = "/";
                    ccinfo.host = lws_canonical_hostname( context );
                    ccinfo.origin = "origin";
                    ccinfo.protocol = protocols[PROTOCOL_EXAMPLE].name;
                    web_socket = lws_client_connect_via_info(&ccinfo);
            }

            if( tv.tv_sec != old )
            {
                    lws_callback_on_writable( web_socket );
                    old = tv.tv_sec;
            }

            lws_service( context, 250 );
    }

}
