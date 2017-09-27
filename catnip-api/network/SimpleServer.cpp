#include "SimpleServer.h"

#include <memory>

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

namespace
{
    std::unique_ptr<addrinfo, decltype(&freeaddrinfo)> GetServerAddrInfo()
    {
        addrinfo hint, *info;
        
        memset(&hint, 0, sizeof(hint));
        
        hint.ai_family = AF_INET;
        hint.ai_socktype = SOCK_STREAM;
        hint.ai_protocol = IPPROTO_TCP;
        hint.ai_flags = AI_PASSIVE;
        
        getaddrinfo(NULL, "17123", &hint, &info);
        
        return std::unique_ptr<addrinfo, decltype(&freeaddrinfo)>(info, freeaddrinfo);
    }
    
    int InitServer()
    {
        auto info = GetServerAddrInfo();
        
        auto listenfd = socket(info->ai_family, info->ai_socktype, info->ai_protocol);
        bind(listenfd, info->ai_addr, info->ai_addrlen);
        
        listen(listenfd, SOMAXCONN);
        
        return listenfd;
    }
}

SimpleServer::SimpleServer()
: _delegate(nullptr)
{
    
}

void SimpleServer::SetDelegate(SimpleServerDelegate &delegate)
{
    _delegate = &delegate;
}

void SimpleServer::Start()
{
    assert(_delegate);
    
    auto listenfd = InitServer();
    _delegate->ServerStarted();
    
    for(;;)
    {
        char buf[4096];
        auto clientfd = accept(listenfd, nullptr, nullptr);
        
        auto recvsize = recv(clientfd, buf, sizeof(buf), 0);
        
        if (recvsize > 0)
        {
            auto request = std::string(buf, recvsize);
            auto response = _delegate->RequestReceived(request);
            send(clientfd, response.c_str(), response.length(), 0);
        }
        else
        {
            // either connection closed or socket error
            break;
        }
        
        close(clientfd);
    }
}
