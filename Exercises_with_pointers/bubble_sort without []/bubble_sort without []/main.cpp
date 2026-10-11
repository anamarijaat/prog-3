#include <iostream>

void bubble_sort(int *a, int len){
    for(int i = 0; i < len; i++){
        for (int j = 0; j < len - 1 - i; j++){
            if (*(a+j) > *(a+j+1)){
                int t = *(a+j);
                *(a+j) = *(a+j+1);
                *(a+j+1) = t;
            }
        }
    }
}


int main() {
    
    int n;
    std::cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        std::cin >> a[i];
    }
    bubble_sort(a, n);
    for (int i = 0; i < n; i++){
        std::cout << *(a+i) << ' ';
    }
        
    return 0;
}
