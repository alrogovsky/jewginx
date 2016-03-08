//
//  HttpRequest.cpp
//  jewginx
//
//  Created by Alexander Rogovsky on 08/03/16.
//  Copyright © 2016 leet software inc. All rights reserved.
//

#include "HttpRequest.hpp"

HttpRequest::HttpRequest(char* raw){
    rawReq = raw;
}

void HttpRequest::makeResponse(){
    
    if (!rawReq){
        fprintf(stdout, "ERROR\n");
    }
    
    char* reqType = strtok(rawReq, " ");
    
    if(strcmp(reqType, "GET") != 0) {
//        return new HttpResponse(405);
    }
    
}