//
//  Constants.cpp
//  jewginx
//
//  Created by Alexander Rogovsky on 08/03/16.
//  Copyright © 2016 leet software inc. All rights reserved.
//

#include "Constants.hpp"

char* ROOT_DIR = nullptr;

const int MAX_HTTP_REQUEST = 2000;

const int WORKERS_COUNT = 4;
const int DEFAULT_PORT = 80;
const char* DEFAULT_ROOT_DIR = "/Users/alex/Desktop";
const char* INDEX_FILE = "/index.html";

const char* METHOD_NOT_ALLOWED = "Method Not Allowed";
const char* OK = "OK";
const char* BAD_REQUEST = "Bad Request";
const char* NOT_FOUND = "Not Found";

std::map<std::string, const char*> EXTENSIONS = {
    {"no_ext", "text/plain"},
    {"html", "text/html"},
    {"css", "text/css"},
    {"js", "text/javascript"},
    {"jpg", "image/jpeg"},
    {"jpeg", "image/jpeg"},
    {"png", "image/png"},
    {"gif", "image/gif"},
    {"swf", "application/x-shockwave-flash"},
    {"default", "text/plain"}
};
