#include <iostream>

void swapl(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}
int main() {
    
    int a, b;
    std::cin >> a >> b;
    //swapl(&a,&b);
    swap(a,b);
    std::cout << a << ' ' << b;
    return 0;
}
