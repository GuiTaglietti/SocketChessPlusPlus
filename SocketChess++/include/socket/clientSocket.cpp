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

#include "clientSocket.h"

namespace socketchess {

namespace clientsocket {

ClientSocket::ClientSocket(const std::string &ip, int port) noexcept {
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cerr << "Erro na criação do socket" << std::endl;
        return;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, ip.c_str(), &serv_addr.sin_addr) <= 0) {
        std::cerr << "Endereço inválido/ Endereço não suportado" << std::endl;
        return;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cerr << "Falha na conexão" << std::endl;
        return;
    }
}

ClientSocket::~ClientSocket() noexcept {
    close(sock);
}

ConcreteClientSocket::ConcreteClientSocket(const std::string &ip, int port) noexcept
    : ClientSocket(ip, port) {}

bool ConcreteClientSocket::sendMessage(const std::string &message) const noexcept {
    return send(sock, message.c_str(), message.size(), 0) != -1;
}

bool ConcreteClientSocket::receiveMessage(std::string &message) const noexcept {
    char buffer[1024] = {0};
    int valread = read(sock, buffer, 1024);
    if (valread > 0) {
        message = std::string(buffer, valread);
        return true;
    }
    return false;
}

} // namespace clientsocket

} // namespace socketchess
