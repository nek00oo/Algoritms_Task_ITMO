#include <iostream>
#include <vector>

void CountingSort(int array[], int amin, int amax, int N) {
    std::vector<int> result(N);
    std::vector<int> counter(amax - amin + 1,0);
    for (int i = 0; i < N; i++){
        counter[array[i] - amin]++; //Делаем +1 к ячейке [array[i] - amin], которая отвечает за число array[i]
    }
    for (int i = 1; i <= amax - amin; i++){
        counter[i] += counter[i - 1]; //К нынешней ячейке добавляем число из предыдущей
    }                                 //Получаем адрес элементов в отсортированном массиве (от предыдущего ДО нынешнего)
    for (int i = N - 1; i >= 0; i--){ //Идём с конца т.к индекс в массиве counter показывает ДО какого элемента идём данное число
        result[counter[array[i] - amin] - 1] = array[i]; //и получается, что запись мы начинаем с ДО до ОТ.
        counter[array[i] - amin]--; //уменьшаем счётчик числа (по индексу)
    }
    for (int i = 0; i < N; i++){
        std::cout << result[i] << " ";
    }
}

int main() {
    int n, amax, amin;
    std::cin >> n;
    int array[n];
    for (int i = 0; i < n; i++)
        std::cin >> array[i];
    amax = amin = array[0];
    for(int i = 0; i < n; i++) {
        if (array[i] < amin) {
            amin = array[i];
        }
        if (array[i] > amax) {
            amax = array[i];
        }
    }
    CountingSort(array, amin, amax, n);
    return 0;
}