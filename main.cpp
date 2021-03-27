#include <libwebsockets.h>
#include <string.h>
#include <stdio.h>
#include "serverinterface.h"
#include "websocketserver.h"

#include "tvpluswebsocketclient.h"

#include<thread>






int main( int argc, char *argv[] )
{


    std::thread ts([]{
         serverinterface *server = new websocketserver();
         server->start_tvplus_service("localhost",8000);
    });

    std::thread t([]{
        tvpluswebsocketclient client;
        client.run();

    });

    while( 1 )
    {

    }
    ts.join();
    t.join();

    return 0;
}

