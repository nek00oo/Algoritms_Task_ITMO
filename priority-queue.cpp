#include <iostream>
#include <vector>

void decrease(std::vector<int>& heap, int toNumber, int size, int index){
    heap.push_back(toNumber);
    heap[index] = heap[size]; //Добавили элемент, size++ не делали, значит индекс size
    heap.pop_back();          //Не делаем size-- т.к не делали size++
    int i = index;
    while(i > 0 and heap[(i - 1) / 2] > heap[i]){
        std::swap(heap[(i - 1) / 2], heap[i]);
        i = (i-1)/2;
    }
}

int remove(std::vector<int>& heap, int size){
    int res = heap[0];
    heap[0] = heap[size - 1];
    heap.pop_back();
    int i = 0;
    while (true){
        int j = i;
        if(2*i+1 < size and heap[2 * i + 1] < heap[i]) {
            j = 2 * i + 1;
        }
        if(2*i+2 < size and heap[2 * i + 2] < heap[2 * i + 1]){
            j = 2*i+2;
        }
        if (heap[i] <= heap[j] or j == i) break;
        std::swap(heap[j], heap[i]);
        i = j;
    }
    return res;
}

void insert(std::vector<int>& heap, int x, int size){
    heap.push_back(x);
    int i = size - 1;
    while(i > 0 and heap[(i - 1) / 2] > heap[i]){
        std::swap(heap[(i - 1) / 2], heap[i]);
        i = (i-1)/2;
    }
}

int main(){
    std::vector<int> Command;
    std::vector<int> Queue;
    std::string line;
    int size = 0;
    int number, toNumber;
    int index;
    while (std::cin >> line){
        if (line == "push"){
            size++;
            std::cin >> number;
            Command.push_back(number);
            insert(Queue,number, size);
        }
        else if (line == "extract-min"){
            Command.push_back(0);
            if(size>0){
                std::cout << remove(Queue, size) << '\n';
                size--;
            }
            else std::cout << '*' << '\n';

        }
        else if (line == "decrease-key"){
            Command.push_back(0);
            std::cin >> index >> toNumber;
            number = Command[index-1];
            Command[index-1] = toNumber;
            for(int i = 0; i < size; i++){
                if(Queue[i] == number){
                    decrease(Queue,toNumber,size,i);
                    break;
                }
            }
        }
    }
    return 0;
}
