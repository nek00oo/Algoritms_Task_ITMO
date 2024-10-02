#include <iostream>


class List{
public:
    List(){
        Size = 0;
        Head = nullptr;
    }
    //~List();
    int GetValuesEnd(){
        Node *current = this->Head;
        while (current->p_next != nullptr){
            return current->data;
            current = current->p_next;
        }
    }
    void GetValuesStart(){
        Node *temp = Head;
        Head = Head->p_next;
        std::cout << temp->data << std::endl;
        delete temp;
        Size--;
    }
    void push_back(int data){
        if (Head == nullptr){
            Head = new Node(data);   //Если это 1 элемент , то мы записывааем его в Head
        }
        else{
            Node *current = this->Head;             //присваиваем адресс Head временной переменной current
            while (current->p_next != nullptr){ //Пока мы не добрались до конца идём дальше
                current = current->p_next;      //Присваиваем указатель next следующего листa
            }
            current->p_next = new Node(data);
        }
        Size++;
    }

    int GetSize() {return Size;}

private:

    class Node{
    public:
        Node *p_next;
        int data;
        Node(int data = 0,Node *p_next = nullptr){ //Если мы будем дабавлять последний элемент, то мы не будем указывать p_next
            this->data = data;
            this->p_next = p_next;
        }
    };
    int Size;
    Node *Head;

};


int main(int argc, char* argv[]){
    List lst;
    lst.push_back(5);
    lst.push_back(10);
    std::cout << lst.GetSize() << std::endl;

    return 0;
}