/*
    cho 1 mảng hãy reduce mảng đó theo quy tắc giảm phần tử nguyên tố cạnh nhau đi ví dụ 3 4 5 6 7 -> 7 5 6 7
*/

#include <iostream>
using namespace std; 

bool isPrime(int n) 
{
    if(n < 2) return false;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) return false; 
    }
    return true; 
}

void show(int *a, int idx) 
{
    for(int i = 0; i < idx; i++) {
        cout << a[i] << " "; 
    }
}

void reduce(int *a, int n, int &idx)
{
    for(int i = 0; i < n; ) 
    {
        if(isPrime(a[i])) {
            int sum = 0; 
            while(isPrime(a[i]) && i < n) {
                sum += a[i]; 
                i++; 
            }
            a[idx] = sum; 
            idx++; 
        }
        else {
            while(!isPrime(a[i]) && i < n) {
                a[idx] = a[i]; 
                idx++; 
                i++; 
            }
        }
    }
    show(a, idx); 
}

int main() 
{
    int a[] = {4, 2, 5, 3, 9, 4, 3, 5, 2, 6, 3, 7, 11, 20}; 

    int n = sizeof(a) / sizeof (*a); 
    int idx = 0; 

    reduce(a, n, idx); 

    return 0;
    
}