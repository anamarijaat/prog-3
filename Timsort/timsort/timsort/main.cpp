#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
const int minRUN = 32;
int insertT = 0;
int mergeT = 0;
int timT = 0;

long long min(long long x, long long y){
    if (x < y){
        return x;
    }
    else{
        return y;
    }
}

long long minRunLength(int n) {
    if (n <= 32)
        return n;

    if (n < 64)
        return (n + 1) / 2;

    return 32;
}

void insertion_sort(std::vector<long long>& a, long long start, long long end){
    for (long long i = start; i <= end; i++){
        long long key = a[i];
        long long j = i - 1;
        while (j >= start && a[j] > key){
            insertT++;
            a[j+1] = a[j];
            j = j-1;
        }
        a[j+1] = key;
    }
}

void merge(std::vector<long long>& a, long long left, long long mid, long long right){
    long long n1 = mid - left + 1;
    long long n2 = right - mid;
    std::vector<long long> l1(n1), l2(n2);
    for (long long i = 0; i < n1; i++){
        l1[i] = a[left + i];
    }
    for (long long j  = 0; j < n2; j++){
        l2[j] = a[mid + 1 + j];
    }
    long long i = 0, j = 0;
    long long b = left;
    while (i < n1 && j < n2){
        mergeT++;
        if(l1[i] <= l2[j]){
            a[b] = l1[i];
            i++;
        }
        else{
            a[b] = l2[j];
            j++;
        }
        b++;
    }
    while (i < n1){
        a[b] = l1[i];
        i++;
        b++;
    }
    while (j < n2){
        a[b] = l2[j];
        j++;
        b++;
    }
}

void timSort (std::vector<long long>& a, long long n){
    for (long long i = 0; i < n; i += minRunLength(n)){
        timT++;
        insertion_sort(a, i, min((i+minRunLength(n)-1),(n-1)));
    }
    for (long long j = minRunLength(n); j < n; j *= 2){
        for (long long left = 0; left < n; left += j*2){
            timT++;
            long long mid = min(left + j - 1, n - 1);
            long long right = min((left + 2*j - 1),(n-1));
            if (mid < right){
                merge(a, left, mid, right);
            }
        }
    }
}

int main() {
    
    int n;
    std::cin >> n;
    std::vector<long long> v;
    std::srand(std::time(0));
    for (long long i = 0; i < n; i++){
        long long random_num = (std::rand() % n) + 1;
        v.push_back(random_num);
    }
    for (int i = 0; i < n; i++){
        std::cout << v[i] << ' ';
    }
    clock_t start = clock();
        timSort(v, n);
        clock_t end = clock();
    
    for (int i = 0; i < n; i++){
        std::cout << v[i] << ' ';
    }
        double elapsed = double(end - start) / CLOCKS_PER_SEC;
        std::cout << "Sortiranjeto zavrsi za: " << elapsed << " sekundi.\n";

    std::cout <<"broj na interacii kaj insertion sort:"<<  insertT << std::endl;
    std::cout <<"broj na interacii kaj merge:"<<  mergeT << std::endl;
    std::cout <<"broj na interacii kaj timsort:"<<  timT << std::endl;
    
    return 0;
}
