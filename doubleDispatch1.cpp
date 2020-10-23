// Copyright 2020 Magellan

#include <iostream>

class Client1;
class Client2;

class BaseServer {
    public:
        virtual void display(Client1 &client1) = 0;
        virtual void display(Client2 &client2) = 0;
};

class Server1 : public BaseServer {
    public:
        virtual void display(Client1 &client1) override {
            std::cout << "Server1 - Client1\n";
        }

        virtual void display(Client2 &client2) override {
            std::cout << "Server1 - Client2\n";
        }
};

class Server2 : public BaseServer {
    public:
        virtual void display(Client1 &client1) override {
            std::cout << "Server2 - Client1\n";
        }

        virtual void display(Client2 &client2) override {
            std::cout << "Server2 - Client2\n";
        }
};

class BaseClient {
    public:
        virtual void clientDisplay(BaseServer &server) = 0;
};

class Client1 : public BaseClient {
    public:
        virtual void clientDisplay(BaseServer &server) override {
            server.display(*this);
        }
};

class Client2 : public BaseClient {
    public:
        virtual void clientDisplay(BaseServer &server) override {
            server.display(*this);
        }
};

int main() {
    Server1 server1;
    Client1 client1;
    client1.clientDisplay(server1);

    return (0);
}
