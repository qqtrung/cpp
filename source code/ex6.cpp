/*
    Cho 1 mảng char[] a có nhiều kí tự đặc biệt nhiệm vụ của bạn 
    hãy tách các kí tự của mảng đó ra và phải theo cấp phát động.  
*/

#include <iostream>
#include <cstring>
using namespace std; 

void splitstring(const char *x, char **&a, int &k) 
{
    int lenX = strlen(x); 

    int cnt = 0;    
    for(int i = 0; i < lenX; ) {
        if(isalpha(x[i])) {
            while(isalpha(x[i]) && i < lenX) {
                i++; 
            }
            cnt++; 
        } else {
            i++; 
        }
    }

    a = new char*[cnt]; 

    for(int i = 0; i < lenX; ) {
        if(isalpha(x[i])) {
            int j = i; 
            while(isalpha(x[i]) && i < lenX) {
                i++; 
            }
            a[k] = new char[i - j + 1]; 
            strncpy(a[k], x + j, i - j); 
            a[k][i - j] = '\0';
            k++; 
        } else {
            i++; 
        }
    }
}

int main()
{   
    int k = 0; 
    const char *x = "the #gioi, *di()dong&&ok;;men"; 
    char **a = nullptr; 
    splitstring(x, a, k); 

    for(int i = 0; i < k; i++) {
        cout << a[i] << "\n"; 
        delete[] a[i];
    }  
    delete[] a; 
    return 0; 
}
