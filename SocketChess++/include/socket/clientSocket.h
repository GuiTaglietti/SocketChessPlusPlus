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
#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include <sys/socket.h>
#include <arpa/inet.h>
#include <string>

namespace socketchess {

namespace clientsocket {

class ClientSocket {
public:
    explicit ClientSocket(const std::string &ip, int port) noexcept;
    virtual ~ClientSocket() noexcept;

    // Funções membro
    [[nodiscard]] virtual bool sendMessage(const std::string &message) const noexcept = 0;
    [[nodiscard]] virtual bool receiveMessage(std::string &message) const noexcept = 0;

protected:
    int sock;
    struct sockaddr_in serv_addr;
};

class ConcreteClientSocket : public ClientSocket {
public:
    explicit ConcreteClientSocket(const std::string &ip, int port) noexcept;
    ~ConcreteClientSocket() noexcept override = default;

    /*[[nodiscard]]*/ bool sendMessage(const std::string &message) const noexcept override;
    /*[[nodiscard]]*/ bool receiveMessage(std::string &message) const noexcept override;
};

} // namespace clientsocket

} // namespace socketchess

#endif // CLIENTSOCKET_H
