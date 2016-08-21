#ifndef FOLDER
#define FOLDER

#include <set>
#include <string>

class Message;

class Folder {
    friend class Message;
    friend void swap(Folder&, Folder&);
public:
    Folder() = default;
    ~Folder() = default;;
    void addMsg(Message*);
    void remMsg(Message*);
private:
    std::set<Message*> messages;
};

void Folder::addMsg(Message *m) {
    messages.insert(m);
}

void Folder::remMsg(Message *m) {
    messages.erase(m);
}

#endif