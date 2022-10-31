#include <stdio.h>

void swap(int *one, int *two){
    int c;
    c = *one ; *one = *two ; *two = c;
}

int partition(int *array, int left, int right){
    int x = array[right];
    int i = left-1;
    for(int j = left; j <= right - 1; j++){
        if(array[j] <= x){
            i++;
            swap(&array[i],&array[j]);
        }
    }
    swap(&array[i+1],&array[right]);
    return i+1;
}

void quick_sort(int *array, int left, int right){
    if(left < right){
        int q = partition(array, left, right);
        quick_sort(array, left, q-1);
        quick_sort(array, q+1 , right);
    }

}

int main(int argc, char *argv[]){
    int n;
    scanf("%d",&n);
    int array[n];
    for(int i = 0; i < n; i++){
        scanf("%d",(array+i));
    }
    quick_sort(array,0,n-1);
    for(int i = 0; i < n; i++){
        printf("%d ",*(array+i));
    }
    return 0;
}
