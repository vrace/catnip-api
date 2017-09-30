#ifndef REQUEST_MAPPING_H
#define REQUEST_MAPPING_H

#include "RestController.h"
#include <string>

class RequestMapping
{
public:
    RequestMapping(const std::string &mapping, RestController &controller);
    
    const std::string& GetMapping() const;
    RestController& GetController() const;
    
private:
    std::string _mapping;
    RestController &_controller;
};

#endif
