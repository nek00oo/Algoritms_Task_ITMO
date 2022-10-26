#include <stdio.h>

void merge(int *array,int left, int mid, int right){
    int result[right - left];
    int it1 = 0, it2 = 0;
    while(left + it1 < mid && mid + it2 < right){
        if(*(array + left + it1) < *(array + mid + it2)){
            result[it1 + it2] = *(array + left + it1);
            it1++;
        }
        else{
            result[it1 + it2] = *(array +mid + it2);
            it2++;
        }
    }

    while(left + it1 < mid){
        result[it1 + it2] = *(array + left + it1);
        it1++;
    }
    while(mid + it2 < right){
        result[it1 + it2] = *(array + mid + it2);
        it2++;
    }
    for(int i = 0; i < it1 + it2; i++){
        *(array + left + i) = *(result + i);
    }

}

void merge_sort(int *array, int left, int right){
    if (left + 1 >= right) return;
    int mid = (left + right) / 2;
    merge_sort(array,left,mid);
    merge_sort(array,mid,right);
    merge(array,left,mid,right);
}

int main(int argc, char *argv[]){
    int n;
    scanf("%d",&n);
    int mas[n];

    for(int i = 0; i < n; i++){
        scanf("%d",(mas+i));
    }

    merge_sort(mas,0,n);

    for(int i = 0; i < n; i++){
        printf("%d ",*(mas + i));
    }
    return 0;
}