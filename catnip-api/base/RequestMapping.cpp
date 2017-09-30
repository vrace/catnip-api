#include "RequestMapping.h"

RequestMapping::RequestMapping(const std::string &mapping, RestController &controller)
: _mapping(mapping)
, _controller(controller)
{
    
}

const std::string& RequestMapping::GetMapping() const
{
    return _mapping;
}

RestController& RequestMapping::GetController() const
{
    return _controller;
}
