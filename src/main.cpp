#include "chat.h"
#include "lib/network.h"
#include <string>
#include <iostream>

int main() {
    network n;
    network n2;
    n2.connectToHost("127.0.0.1", 39058);
    chat c;
    n.connectToHost("127.0.0.1", 39059);
    c.writeMessage("testing!\n", n);
    printf("%d\n", n.getSocket());
    printf("%d\n", n2.getSocket());
    c.writeMessage("testing2!\n", n2);
    std::string msg;
    std::string msg2;
    int i = 0;
    while (i < 2) {
        msg = c.readMessage(n);
        msg2 = c.readMessage(n2);
        if(!msg.empty()) {
            std::cout << n.getSocket() << ": " <<  msg;
        }
        if(!msg2.empty()) {
            std::cout << n2.getSocket() << ": " << msg2;
        }
    }
    n.closeSocket();
    return 0;
}












