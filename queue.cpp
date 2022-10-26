#include <iostream>

class Node {
public:
    int data;
    Node *link;

    Node(int data){
        this->data = data;
        this->link = nullptr;
    }
};

class queue{
    Node *head;
    Node *end;
public:
    queue(){head = nullptr; end = nullptr;}

    void push(int data){
        Node *temp = new Node(data);
        if(head == NULL){
            temp->link = end;
            head = temp;
            end = temp;
        }
        else{
            temp->link = nullptr;
            end->link = temp;
            end = temp;
        }

    }

    void popAndPrint()
    {
        Node* temp;

        if (head == nullptr and end == nullptr){
            exit(1);
        }
        else if(head == end) {
            temp = head;
            head = end->link;
            end = end->link;
            std::cout << temp->data << '\n';
            delete temp;
        }
        else{
            temp = head;
            head = head->link;
            std::cout << temp->data << '\n';
            delete temp;
        }
    }

};

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    queue ms;
    int number;
    int n;
    std::cin >> n;
    char c;
    for (int i = 0; i < n; i++){
        std::cin >> c;
        if (c == '+') {
            std::cin >> number;
            ms.push(number);
        }
        else{
            ms.popAndPrint();
        }
    }
    return 0;
}