class Node;

class Tree {
    private:
        Node *root;
    public:
        Tree() : Tree(nullptr) {};
        Tree(Node *r) : root(r) {};
};