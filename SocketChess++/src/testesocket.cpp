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
#include <thread>
#include <atomic>
#include <unistd.h>

#include "../include/socket/serversocket.h"
#include "../include/socket/clientsocket.h"

std::atomic<bool> running(true);

void runServer() {
    socketchess::serversocket::ConcreteServerSocket server(8080);

    if (!server.start_listening()) {
        std::cerr << "Failed to start listening" << std::endl;
        return;
    }

    std::cout << "Server is listening on port 8080..." << std::endl;

    int clientSocket = server.accept_connection();
    if (clientSocket < 0) {
        std::cerr << "Failed to accept connection" << std::endl;
        return;
    }

    std::cout << "Client connected" << std::endl;

    while (running) {
        std::string message;
        if (server.receive_message(clientSocket, message)) {
            std::cout << "Client: " << message << std::endl;
            if (message == "exit") {
                running = false;
                break;
            }
        }

        std::cout << "Server: ";
        std::getline(std::cin, message);
        server.send_message(clientSocket, message);
        if (message == "exit") {
            running = false;
            break;
        }
    }

    close(clientSocket);
}

void runClient(const std::string &ip) {
    socketchess::clientsocket::ConcreteClientSocket client(ip, 8080);

    while (running) {
        std::string message;
        std::cout << "Client: ";
        std::getline(std::cin, message);
        client.send_message(message);
        if (message == "exit") {
            running = false;
            break;
        }

        if (client.receive_message(message)) {
            std::cout << "Server: " << message << std::endl;
            if (message == "exit") {
                running = false;
                break;
            }
        }
    }
}

int main() {
    int choice;
    std::cout << "Press 1 to start as server, 2 to start as client: ";
    std::cin >> choice;
    std::cin.ignore();  // Ignore the newline character left in the buffer

    if (choice == 1) {
        std::thread serverThread(runServer);
        serverThread.join();
    } else if (choice == 2) {
        std::string ip;
        std::cout << "Enter server IP: ";
        std::cin >> ip;
        std::cin.ignore();  // Ignore the newline character left in the buffer

        std::thread clientThread(runClient, ip);
        clientThread.join();
    } else {
        std::cerr << "Invalid choice" << std::endl;
    }

    return 0;
}
