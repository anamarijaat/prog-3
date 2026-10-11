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

int binary_search_i(int *arr, int start, int end, int key){
    int mid;
    while(start <= end){
        mid = (start+end)/2;
        if (*(arr+mid) == key){
            return mid;
        }
        if (*(arr+mid) < key){
            start = mid + 1;
        }
        if (*(arr+mid) > key){
            end = mid - 1;
        }
    }
    return -1;
}

int binary_search_r(int *arr, int start, int end, int key){
    int mid = (start+end)/2;
    if (*(arr+mid) == key){
        return mid;
    }
    if (*(arr+mid) < key){
        return binary_search_r(arr, mid + 1, end, key);
    }
    if (*(arr+mid) > key){
        return binary_search_r(arr, start, mid - 1, key);
    }
    return -1;
}

int main() {
    
    int n;
    std::cin >> n;
    int a[n];
    int key;
    std::cin >> key;
    for (int i = 0; i < n; i++){
        std::cin >> *(a+i);
    }
    bubble_sort(a, n);
    for (int i = 0; i < n; i++){
        std::cout << *(a+i) << ' ';
    }
    //int indx = binary_search_i(a, 0, n - 1, key);
    int indx = binary_search_r(a, 0, n - 1, key);
    if (indx != -1){
        std::cout << indx;
    }
    else{
        std::cout << "not found";
    }
        
    return 0;
}

