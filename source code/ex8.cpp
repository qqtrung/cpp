/*
    Dãy con tăng không liên tục và có tổng lớn nhất 
    Hãy in dãy đó ra 

    Ví dụ int a[] = {-3, 4, -2, 1, 2, 6, -1, 7}; 
    -> Tổng lớn nhất = 17
    -> Dãy con tương ứng: {4, 6, 7}  
*/
#include <iostream>
#include <stack>
using namespace std; 

void subsequence(int *a, int n) 
{
    int dp[n]; 
    for(int i = 0; i < n; i++) {
        dp[i] = a[i]; 
    }  

    int parent[n];
    for(int i = 0; i < n; i++) 
        parent[i] = i; 

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(a[i] > a[j]) {
                if(dp[i] < dp[j] + a[i]) {
                    dp[i] = dp[j] + a[i]; 
                    parent[i] = j; 
                }
            }
        }
    }

    int max = -100; 
    for(int i = 0; i < n; i++) {
        if(dp[i] > max) max = dp[i]; 
    }
    
    stack<int> p; 
    for(int i = 0; i < n; i++) {
        if(dp[i] == max) {
            int x = i; 
            p.push(x); 
            while(x != parent[x]) {
                x = parent[x]; 
                p.push(x); 
            }
            break; 
        }
    }

    cout << "Tong lon nhat = " << max << "\n"; 
    cout << "Day con tuong ung: "; 
    while(!p.empty()) {
        cout << a[p.top()] << " ";
        p.pop();  
    }
    cout << "\n"; 

}

int main() 
{
    int a[] = {-3, 4, -2, 1, 2, 6, -1, 7, -1, 33};
    int n = sizeof(a) / sizeof (*a); 

    subsequence(a, n); 

    return 0; 
}