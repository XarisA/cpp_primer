#include <iostream>
#include <memory>

using std::string;
using std::shared_ptr;
using std::cout;
using std::endl;

struct destination {
    string ip;
    int port;
    destination(string _ip, int _port) : ip(_ip), port(_port) {}
};

struct connection {
    string ip;
    int port;
    connection(string _ip, int _port) : ip(_ip), port(_port) {}
};

connection connect(destination *dest) {
    shared_ptr<connection> cp(new connection(dest->ip, dest->port));
    cout << "Connection created! " << cp->ip << ':' << cp->port << endl;
    return *cp;
}

void disconnect(connection conn) {
    cout << "Connection closed! " << conn.ip << ':' << conn.port << endl;
}

void end_connection(connection *p) {
    disconnect(*p);
}

void func(destination &dest) {
    connection c = connect(&dest);
    //shared_ptr<connection> p(&c, end_connection);
    shared_ptr<connection> p(&c, [](connection *p) {disconnect(*p);});
    cout << "Connecting..." << endl;
}

int main() {
    destination dest("192.168.0.1", 22);
    func(dest);

    return 0;
}