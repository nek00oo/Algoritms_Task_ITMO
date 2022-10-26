#include <stdio.h>


void incertion_srot(int *a, int n){
    int key,i;
    for(int j = 1; j < n; j++){
        key = a[j];
        i = j - 1;
        while(i >= 0 && a[i] > key){
            a[i+1] = a[i];
            i--;
        }
        a[i+1] = key; // т.к перед этим был i-- , то мы по сути ставим на место a[i]
    }

}


int main(){
    int n;
    scanf("%d",&n);
    int array[n];
    for(int i = 0; i < n; i++){
        scanf("%d",(array+i));
    }
    incertion_srot(array,n);
    for(int i = 0; i < n; i++){
        printf("%d ",*(array+i));
    }
    return 0;
}