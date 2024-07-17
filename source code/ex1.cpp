/*
    Cho dãy số nguyên gồm n phần tử, hãy đưa toàn bộ số chẵn về cuối dãy theo thứ tự tăng dần từ cuối mảng với các số chẵn đó 
*/

#include <iostream>
using namespace std; 

void swap(int *a, int *b) 
{
    int tmp = *a;
    *a = *b;
    *b = tmp; 
}

int main()
{

    int  a[] = {0, 3, 4, 2, 1, 5, 8, 9, 7, 10, 4, 8, 30, 44, 3}; 

    int size = sizeof(a) / sizeof (*a); 

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < i; j++) {
            if(a[i] % 2 == 0 && a[j] % 2 == 0) {
                if(a[i] > a[j]) {
                    swap(&a[i], &a[j]); 
                } 
            } 
            else {
                if(a[j] % 2 == 0) {
                    swap(&a[i], &a[j]); 
                }
            }
        }
    }

    for(int i = 0; i < size; i++) {
        cout << a[i] << " "; 
    }
    
    return 0; 
}