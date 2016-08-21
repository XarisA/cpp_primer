#ifndef EX_13_28
#define EX_13_28

#include <string>

class TreeNode {
public:
    TreeNode() : left(nullptr), right(nullptr) {}
    TreeNode(const TreeNode &rhs) : value(rhs.value), count(rhs.count), left(rhs.left), right(rhs.right) {++*count;}
    ~TreeNode() {
        if (--*count == 0) {
            delete count;
            delete left;
            delete right;
        }
    }
private:
    std::string value;
    int *count;
    TreeNode *left;
    TreeNode *right;
};

class BinStrTree {
public:
    BinStrTree() : root(new TreeNode()) {}
    BinStrTree(const BinStrTree &b) : root(new TreeNode(*b.root)) {};
    ~BinStrTree() { delete root; }
private:
    TreeNode *root;
};

#endif