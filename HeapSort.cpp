#include <iostream>

void SiftDown(int array[], int n, int i){
    while (true){
        int j = i;
        if(2*i+1 < n and array[2*i+1] < array[i]) {
            j = 2 * i + 1;
        }
        if(2*i+2 < n and array[2*i+2] < array[2*i+1]){
            j = 2 * i + 2;
        }
        if (array[i] <= array[j] or i == j) return;
        std::swap(array[j],array[i]);
        i = j;
    }
}

void HeapSort(int array[], int n){
    for(int i = n - 1; i >= 0 ; i--){
        SiftDown(array,n,i);
    }
    for(int i = n - 1; i >= 0; i--){
        std::swap(array[0],array[i]);
        SiftDown(array,i,0);
    }
}

int main(){
    int n;
    std::cin >> n;
    int array[n];
    for(int i = 0; i < n; i++){
        std::cin >> array[i];
    }

    HeapSort(array,n);

    for(int i = n - 1; i >= 0; i--){
        std::cout << array[i] << ' ';
    }
    return 0;

}