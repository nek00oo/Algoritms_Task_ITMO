#include <stdio.h>

void swap(int *one, int *two){
    int c;
    c = *one ; *one = *two ; *two = c;
}

void quick_sort(int* array, int left, int right){
    int i =left;
    int j = right;
    int x = array[(right + left) / 2];
    while(i <= j){
        while(array[i]<x) i++;
        while(array[j]>x) j--;
        if(i<=j){
            swap(&array[i++],&array[j--]);
        }
        if(left < j) quick_sort(array, left, j);
        if(i < right) quick_sort(array, i, right);
    }

}

int main(int argc, char *argv[]){
    int n;
    scanf("%d",&n);
    int mas[n];

    for(int i = 0; i < n; i++){
        scanf("%d",(mas+i));
    }

    quick_sort(mas, 0, n - 1);

    for(int i = 0; i < n; i++){
        printf("%d ",*(mas + i));
    }
    return 0;
}