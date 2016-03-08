//
//  HttpRequest.hpp
//  jewginx
//
//  Created by Alexander Rogovsky on 08/03/16.
//  Copyright © 2016 leet software inc. All rights reserved.
//

#ifndef HttpRequest_hpp
#define HttpRequest_hpp

#include <stdio.h>
#include <cstring>
#include "HttpResponse.hpp"

class HttpRequest {
public:
    HttpRequest(char* rawReq);
    void makeResponse();

private:
    char* rawReq;
    
};

#endif /* HttpRequest_hpp */
