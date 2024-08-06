/*
    Chọn K thành viên trong N thành viên
    const char *a[] = {"Tom", "John", "Rose"}; 
    
    -> Print 3 possible combinations:
        {"Tom", "John"}, {"Tom", "Rose"}, {"John", "Rose"} 
*/

#include <iostream>
#include <string.h>
using namespace std; 

void generate(const char **a, int N, int K, int start, int position, int *mark) 
{     
    if(position == K) {
        cout << "{"; 
        for(int i = 0; i < K - 1; i++) {
            cout << "\"" << a[mark[i]] << "\", "; 
        }
        cout << "\"" << a[mark[K-1]] << "\""; 
        cout << "}" << "\n"; 
        return; 
    }

    for(int i = start + 1; i < N; i++) {
        mark[position] = i; 
        generate(a, N, K, i, position + 1, mark); 
    }

}

int main()
{
    int N = 5; 
    int K = 3; 
    const char *a[N] = {"Tom", "John", "Rose", "David", "Eva"}; 
    int mark[K] = {0}; 

    for(int i = 0; i < N - K + 1; i++) {
        mark[0] = i; 
        generate(a, N, K, i, 1, mark); 
    }

    return 0; 
}