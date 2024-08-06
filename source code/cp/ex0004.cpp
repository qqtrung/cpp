#include <bits/stdc++.h>
using namespace std; 
typedef long long ll; 

/*

4555666555444321 
-> 4556123444555566    

*/

void solve() // O(n)
{
    string s; 
    cin >> s; 
    int n = s.size(); 

    // if(next_permutation(s.begin(), s.end()))
    //     cout << s; 
    // else 
    //     cout << -1; 
    
    for (int i = n - 2; i >= 0; i--) {
        if(s[i] < s[i + 1]) {
            for (int j = n - 1; j > i; j--) {
                if (s[j] > s[i]) {
                    swap(s[i], s[j]); 
                    reverse(s.begin() + i + 1, s.end()); 
                    cout << s;
                    return; 
                }
            }
        }
    }
    cout << -1; 
}


int main()
{
    solve(); 
    return 0; 
}