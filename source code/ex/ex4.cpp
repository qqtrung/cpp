/*
    Cho 1 mảng a[] có n phần tử 
    Tìm min, max với chi phí của thuật toán tốt hơn 2n + c
*/

#include <iostream>
using namespace std; 
#define inf 1e9; 

void findminmax(int *a, int n, int &min, int &max) 
{
    int start; 
    if(n % 2 == 0) {
        start = 0; 
    }
    else {
        min = a[0]; 
        max = a[0]; 
        start = 1; 
    }

    for(int i = start; i + 1 < n; i += 2) 
    {
        if(a[i] < a[i+1]) {
            if(a[i] < min) {
                min = a[i]; 
            }
            if(a[i+1] > max) {
                max = a[i+1]; 
            }
        }
        else {
            if(a[i] > max) {
                max = a[i]; 
            }
            if(a[i+1] < min) {
                min = a[i+1]; 
            }
        }
    }
}

int main()
{
    int a[] = {0, 4, 3, 2, 9, 8, 5, 4, 1}; 
    int n = sizeof(a) / sizeof (*a); 

    int min = inf;
    int max = -inf; 
    findminmax(a, n, min, max); 
    cout << min << " " << max << endl; 

    return 0; 
}