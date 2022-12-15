#include <iostream>

class node {
public:
    int data;
    node *left, *right, *parent;

    explicit node(int data) {
        this->parent = nullptr;
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class tree {
private:
    node *currentNode;

    node *mainNode;

    void DeleteNodeWithNoneChild(node *DeleteNode);

    void DeleteNodeWithOnlyOneChild(node *DeleteNode);

    void DeleteNodeWithTwoChild(node *DeleteNode);

public:


    tree() {
        currentNode = nullptr;
        mainNode = nullptr;
    }

    void InsertNodeInTree(int data);

    int HeightTree(node *Node);

    bool ExistsNode(int value);

    node *NextValue(int value);

    node *PrevValue(int value);

    void DeleteNode(int delete_values);

    node *SearchNode(int value);

};


node *tree::NextValue(int value) {
    currentNode = mainNode;
    node *successor = nullptr;
    while (currentNode != nullptr) {
        if (currentNode->data > value) {
            successor = currentNode;
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }
    }
    return successor;
}

node *tree::PrevValue(int value) {
    currentNode = mainNode;
    node *successor = nullptr;
    while (currentNode != nullptr) {
        if (currentNode->data >= value) {
            currentNode = currentNode->left;
        } else {
            successor = currentNode;
            currentNode = currentNode->right;
        }
    }
    return successor;
}

bool tree::ExistsNode(int value){
    if (mainNode == nullptr)
        return false;
    currentNode = mainNode;
    bool flag = true;
    while (currentNode->data != value) {
        while (value < currentNode->data) {
            if (currentNode->left != nullptr)
                currentNode = currentNode->left;
            else {
                flag = false;
                break;
            }
        }
        while (value > currentNode->data) {
            if (currentNode->right != nullptr)
                currentNode = currentNode->right;
            else {
                flag = false;
                break;
            }
        }
        if (!flag) break;
    }
    return flag;
}


void tree::InsertNodeInTree(int data) {
    node *tmpNode = new node(data);
    if (mainNode == nullptr) {
        mainNode = tmpNode;
    } else {
        currentNode = mainNode;
        while (currentNode->data != tmpNode->data) {
            while (tmpNode->data > currentNode->data) {
                if (currentNode->right != nullptr) {
                    currentNode = currentNode->right;
                } else {
                    tmpNode->parent = currentNode;
                    currentNode->right = tmpNode;
                    currentNode = tmpNode;
                }
            }
            while (tmpNode->data < currentNode->data) {
                if (currentNode->left != nullptr) {
                    currentNode = currentNode->left;
                } else {
                    tmpNode->parent = currentNode;
                    currentNode->left = tmpNode;
                    currentNode = tmpNode;
                }
            }
        }
    }
}

int tree::HeightTree(node *Node) {
    if (Node == nullptr) {
        return 0;
    }
    int leftHeight = HeightTree(Node->left);
    int rightHeight = HeightTree(Node->right);
    return std::max(leftHeight, rightHeight) + 1;
}

void tree::DeleteNode(int del) {
    node *DeleteNode = SearchNode(del);
    if (DeleteNode == nullptr )
        return;
    else {
        if (DeleteNode->left == nullptr and DeleteNode->right == nullptr) {
            DeleteNodeWithNoneChild(DeleteNode);
        } else if (DeleteNode->left == nullptr or DeleteNode->right == nullptr) {
            DeleteNodeWithOnlyOneChild(DeleteNode);
        } else {
            DeleteNodeWithTwoChild(DeleteNode);
        }
    }
}

node *tree::SearchNode(int value) {
    if (mainNode == nullptr){
        return nullptr;
    }
    currentNode = mainNode;
    bool flag = true;
    while (currentNode->data != value) {
        while (value < currentNode->data) {
            if (currentNode->left != nullptr) {
                currentNode = currentNode->left;
            } else {
                flag = false;
                break;
            }
        }
        while (value > currentNode->data) {
            if (currentNode->right != nullptr) {
                currentNode = currentNode->right;
            } else {
                flag = false;
                break;
            }
        }
        if (!flag) return nullptr;
    }
    return currentNode;
}

void tree::DeleteNodeWithNoneChild(node *DeleteNode) {
    if (DeleteNode == mainNode){
        mainNode = nullptr;
        return;
    }
    node *ParentNode = DeleteNode->parent;
    if (ParentNode->left == DeleteNode)
        ParentNode->left = nullptr;
    if (ParentNode->right == DeleteNode)
        ParentNode->right = nullptr;
}

void tree::DeleteNodeWithOnlyOneChild(node *DeleteNode) {
    if (DeleteNode == mainNode){
        if (DeleteNode->right == nullptr){
            mainNode = DeleteNode->left;
        }
        else {
            mainNode = DeleteNode->right;
        }
        mainNode->parent = nullptr;
        return;
    }
    node *ParentNode = DeleteNode->parent;
    if (DeleteNode->left == nullptr) {
        if (ParentNode->left == DeleteNode) {
            ParentNode->left = DeleteNode->right;
        } else {
            ParentNode->right = DeleteNode->right;
        }
        DeleteNode->right->parent = ParentNode;
    } else {
        if (ParentNode->left == DeleteNode) {
            ParentNode->left = DeleteNode->left;
        } else {
            ParentNode->right = DeleteNode->left;
        }
        DeleteNode->left->parent = ParentNode;
    }
}

void tree::DeleteNodeWithTwoChild(node *DeleteNode) {
    node *successor = NextValue(DeleteNode->data);
    DeleteNode->data = successor->data;
    if (successor->parent->left == successor) {
        successor->parent->left = successor->right;
        if (successor->right != nullptr)
            successor->right->parent = successor->parent;
    } else {
        successor->parent->right = successor->right;
        if (successor->right != nullptr)
            successor->right->parent = successor->parent;
    }
}


int main() {
    tree BinarySearchTree;
    std::string line;
    const std::string Insert = "insert";
    const std::string Exists = "exists";
    const std::string Next = "next";
    const std::string Prev = "prev";
    const std::string Delete = "delete";
    int num;
    while (std::cin >> line) {
        std::cin >> num;
        if (line == Insert and !BinarySearchTree.ExistsNode(num)) {
            BinarySearchTree.InsertNodeInTree(num);
        } else if (line == Exists) {
            if (BinarySearchTree.ExistsNode(num)) {
                std::cout << "true" << '\n';
            } else {
                std::cout << "false" << '\n';
            }
        } else if (line == Next) {
            node *NextValue = BinarySearchTree.NextValue(num);
            if (NextValue != nullptr) {
                std::cout << NextValue->data << '\n';
            } else {
                std::cout << "none" << '\n';
            }
        } else if (line == Prev) {
            node *PrevValue = BinarySearchTree.PrevValue(num);
            if (PrevValue != nullptr) {
                std::cout << PrevValue->data << '\n';
            } else {
                std::cout << "none" << '\n';
            }
        } else if (line == Delete) {
            BinarySearchTree.DeleteNode(num);
        }

    }
    return 0;
}
