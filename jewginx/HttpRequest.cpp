//
//  HttpRequest.cpp
//  jewginx
//
//  Created by Alexander Rogovsky on 08/03/16.
//  Copyright © 2016 leet software inc. All rights reserved.
//

#include "HttpRequest.hpp"
#include <cstdlib>
#include <sys/stat.h>
#include <fcntl.h>

HttpRequest::HttpRequest(char* raw){
    rawReq = raw;
}

const char* HttpRequest::getContentType(char* extension)
{
    if(extension == NULL) {
        return EXTENSIONS["no_ext"];
    } else {
        const char* ext =  EXTENSIONS[extension];
        if(ext == NULL) {
            return  EXTENSIONS["default"];
        } else {
            return ext;
        }
    }
}

evbuffer* HttpRequest::parseHttp(){
    
    fprintf(stderr, rawReq);
    
    if (!rawReq){
        fprintf(stdout, "ERROR\n");
    }
    
    char* test = rawReq;
    
    char* reqType;
    reqType = strtok(test, " ");
    if(reqType == NULL || (strcmp(reqType, "GET") != 0 && strcmp(reqType, "HEAD") != 0)) {
        return (new HttpResponse(405))->makeResponse();
    }
    
    char* file;
    file = strtok(NULL, " ");
    fprintf(stderr, file);
    if(file == NULL) {
        return (new HttpResponse(400))->makeResponse();
    }
    
    char* path = (char *)malloc(1000);
    strcpy(path, ROOT_DIR);
    strcat(path, file);
    
    char* extension = 0;
    size_t i = strlen(path) - 1;
    while(path[i] != '/') {
        --i;
        if(path[i] == '.') {
            extension = (char*) calloc(strlen(path) - i, sizeof(char));
            strcpy(extension, path + i + 1);
            break;
        }
    }
    
    int fd = open (path, O_RDONLY);
    if(fd < 0) {
        free(path);
            return (new HttpResponse(404))->makeResponse();
    }
    
    struct stat stat_;
    fstat (fd, &stat_);
    
    HttpResponse* response = new HttpResponse(200);
    response->addHeader("Content-type", getContentType(extension));
    response->addHeader("Content-Length", static_cast<int>(stat_.st_size));
    evbuffer *temp = response->makeResponse();
    if(strcmp(reqType, "GET") == 0) {
        evbuffer_add_file(temp, fd, 0, stat_.st_size);
    }
    
    if(path != NULL)
        free(path);
    if(extension != NULL)
        free(extension);
    
    return temp;
}

