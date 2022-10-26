#include <iostream>

void binpoisk(int* mas,int n, int x){
    int l = 0;
    int r = n;
    int m;
    while(r > l){    //Левый край
        m = (l+r)/2;
        if (mas[m] < x) l = m+1;
        else r = m;
    }
    int left = l + 1;
    l = 0;
    r = n;
    while (r > l) {   //Правый край
        m = (l+r)/2;
        if (mas[m] > x) r = m;
        else l = m+1;
    }
    int right = r;
    if (mas[left-1] == x and mas[right-1] == x) {
        std::cout << left << " " << right << '\n';
    }
    else{
        std::cout << -1 << " " << -1 << std::endl;
        return;
    }

}

int main(int argc, char* argv[]){
    int n;
    std::cin >> n;
    int mas[n];
    for(int i = 0; i < n; i++){
        int a;
        std::cin >> a;
        mas[i] = a;
    }
    int m;
    std::cin >> m;
    for(int i = 0; i < m; i++){
        int num;
        std::cin >> num;
        binpoisk(mas,n,num);
    }
    return 0;

}