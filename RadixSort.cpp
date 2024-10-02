#include <iostream>

void CountingSort(std::string array[], int n, int place) {
    const int max = 26;
    std::string output[n];
    int count[max];

    for(int i = 0; i < max; i++)
        count[i] = 0;

    for (int i = 0; i < n; i++)
        count[((int)array[i][place] - 97)]++;

    for (int i = 1; i < max; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(int)array[i][place] - 97] - 1] = array[i];
        count[(int)array[i][place] - 97]--;
    }

    for (int i = 0; i < n; i++)
        array[i] = output[i];
}

void Radixsort(std::string array[], int n, int m, int k){
    for (int i = 0; i < k ; i++)
        CountingSort(array, n, m - 1 - i);
}


int main(){
    int n, m, k;
    std::cin >> n >> m >> k;
    std::string arr[n];
    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    Radixsort(arr,n,m,k);

    for(int i = 0; i < n; i++) {
        std::cout << arr[i] << '\n';
    }
}