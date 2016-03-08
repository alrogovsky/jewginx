//
//  main.cpp
//  jewginx
//
//  Created by Alexander Rogovsky on 17/02/16.
//  Copyright © 2016 Alexander Rogovsky. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include "HttpServer.hpp"

int main(int argc, char** argv)
{
    int port = 0;
    int workers = 0;
    
    int opt = 0;
    while ( (opt = getopt(argc,argv,"p:")) != -1){
        switch (opt){
            case 'p':
                port = std::stoi(optarg);
                break;
            case 'w':
                workers = std::stoi(optarg);
                break;
        }
    }
    
    HttpServer* server = new HttpServer();
    server->start(port, workers);
    
    return 0;
    
}
