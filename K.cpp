#include <iostream>
using namespace std;


void indexK(int *array1, int left, int right, int k) {
    int pivot = array1[(left + right) / 2];
    int i = left;
    int j = right;
    while (i <= j) {
        while (array1[i] < pivot) i++;
        while (array1[j] > pivot) j--;
        if (i <= j) {
            swap(array1[i++], array1[j--]);
        }
    }
    if (left < j and k <= j) indexK(array1,left, j, k);
    if (i <= k and i < right) indexK(array1,i, right, k);
}

int main() {
    int n, k;
    cin >> n >> k;
    int A, B, C;
    int array1[n];
    cin >> A >> B >> C >> array1[0] >> array1[1];
    for (int j = 2; j < n; j++) {
        array1[j] = A * array1[j - 2] + B * array1[j - 1] + C;
    }
    indexK(array1,0, n - 1, k - 1);
    cout << array1[k-1];
    return 0;
}