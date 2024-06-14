/**
 * MIT License
 * 
 * Copyright (c) 2024 Guilherme Martinelli Taglietti
 *                    Dalton Oberdan Adiers
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include <iostream>
#include <unistd.h>

#include "../include/socket/serversocket.h"

namespace socketchess{

namespace serversocket{

ServerSocket::ServerSocket(int port) noexcept : addrlen(sizeof(address)){
    if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        std::cerr << "Erro na criação do socket!" << std::endl;
        return;
    }
    int opt = 1;
    if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
        std::cerr << "setsockopt!" << std::endl;
        return;
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    if(bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0){
        std::cerr << "Erro no bind!" << std::endl;
        return;
    }
}

ServerSocket::~ServerSocket() noexcept{ close(server_fd); }

ConcreteServerSocket::ConcreteServerSocket(int port) noexcept : ServerSocket(port){}

inline bool ConcreteServerSocket::start_listening(int backlog) const noexcept{
    return listen(server_fd, backlog) == 0;
}

inline int ConcreteServerSocket::accept_connection() const noexcept{
    return accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
}

inline bool ConcreteServerSocket::send_message(int clientSocket, const std::string &message) const noexcept{
    return send(clientSocket, message.c_str(), message.size(), 0) != -1;
}

bool ConcreteServerSocket::receive_message(int clientSocket, std::string &message) const noexcept{
    char buffer[1024] = {0};
    int valread = read(clientSocket, buffer, 1024);
    if(valread > 0){
        message = std::string(buffer, valread);
        return true;
    }
    return false;
}

} // namespace serversocket

} // namespace socketchess
