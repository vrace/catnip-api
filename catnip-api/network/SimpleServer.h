#ifndef SIMPLE_SERVER_H
#define SIMPLE_SERVER_H

#include "SimpleServerDelegate.h"

class SimpleServer
{
public:
    SimpleServer();
    
    void SetDelegate(SimpleServerDelegate &delegate);
    void Start();
    
private:
    SimpleServerDelegate* _delegate;
};

#endif
