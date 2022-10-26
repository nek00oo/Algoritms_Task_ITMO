#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *link;

    Node(int data){
        this->data = data;
        this->link = nullptr;
    }
};

class Stack{
    Node *top;
public:
    Stack(){top = NULL;}

    void push_back(int data){
        Node *temp = new Node(data);    //Временная переменная
        temp->link = top;
        top = temp;
    }

    void popAndPrint()
    {
        Node* temp;

        if (top == NULL) {
            exit(1);
        }
        else {

            temp = top;
            top = top->link;
            cout << temp->data << '\n';
            delete temp;
        }
    }

};


int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    Stack ms;
    int number;
    int n;
    cin >> n;
    char c;
    for (int i = 0; i < n; i++){
        cin >> c;
        if (c == '+') {
            cin >> number;
            ms.push_back(number);
        }
        else{
            ms.popAndPrint();
        }
    }

    return 0;
}

