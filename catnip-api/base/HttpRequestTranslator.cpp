#include "HttpRequestTranslator.h"
#include "HttpRequestMethodTranslator.h"
#include <sstream>

namespace
{
    std::istream& GetLine(std::istream &s, std::string &line)
    {
        if (std::getline(s, line) && !line.empty())
        {
            auto pos = line.rfind('\r');
            if (pos != std::string::npos)
                line.erase(line.begin() + pos);
            
            pos = line.rfind('\n');
            if (pos != std::string::npos)
                line.erase(line.begin() + pos);
        }
        
        return s;
    }
}

std::unique_ptr<HttpRequest> HttpRequestTranslator::Translate(const std::string &request)
{
    std::stringstream lineReader(request);
    std::string line;
    
    if (!GetLine(lineReader, line) || line.empty())
        return nullptr;
    
    auto requestMethod = HttpRequestMethod::Invalid;
    std::string requestUrl;
    std::stringstream(line) >> requestMethod >> requestUrl;
    
    HttpHeaders headers;
    while (GetLine(lineReader, line) || !line.empty())
        headers.Append(line);
    
    std::stringstream payloadss;
    payloadss << lineReader.rdbuf();
    auto payload = payloadss.str();
    
    return std::make_unique<HttpRequest>(requestMethod, requestUrl, headers, payload);
}
