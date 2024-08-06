#include <bits/stdc++.h>
using namespace std; 
typedef long long ll; 

/*

(x + y + z)^2 = x^2 + y^2 + z^2 + 2xy + 2yz + 2xz 
-> sum = xy + yz + xz = [(x + y + z)^2 - (x^2 + y^2 +z^2)] / 2 
sum % 3 == 0 -> (x + y + z)^2 % 3 == (x^2 + y^2 + z^2) % 3

*/
void solve3(vector<ll>& a) // O(n)
{
    int n = a.size(); 
    ll ans = 0; 

    ll dp[3][3] = {0}; 
    dp[0][0] = 1; 

    ll first = 0; 
    ll second = 0; 

    for (int i = 0; i < n; i++) {
        first += a[i]; 
        second += a[i] * a[i]; 

        first %= 3; 
        second %= 3; 

        for (int x = 0; x <= 2; x++) {
            for(int y = 0; y <= 2; y++) {
                ll third = (first - x) * (first - x); 
                ll fourth = second - y; 

                third %= 3; 
                fourth %= 3; 

                if(third < 0) 
                    third += 3; 
                
                if(fourth < 0) 
                    fourth += 3; 

                if (third % 3 == fourth % 3) {
                    ans += dp[x][y]; 
                }
            }
        } 

        dp[first][second]++; 
    }

    cout << ans; 
}

const int N = 1000; 
ll dp[N][N] = {0}; 
ll s[N][N] = {0}; 
void solve2(vector<ll>& a) // O(n^2)
{   
    int n = a.size(); 
    ll ans = 0; 

    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            ll sum = 0;
              
            if (r - 1 >= 0) {
                sum += dp[l][r - 1] + a[r] * s[l][r - 1];
                s[l][r] += s[l][r - 1] + a[r]; 
            } 
            else {
                s[l][r] = a[r]; 
            }

            dp[l][r] = sum; 

            if(sum % 3 == 0) {
                cout << l << " " << r << "\n"; 
                ans++; 
            }
        }
    }
    
    cout << ans; 
}

// O(n^4)
void solve1(vector<ll>& a) 
{
    int n = a.size(); 
    ll ans = 0; 

    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            ll sum = 0 ;
            for (int i = l; i <= r; i++) {
                for(int j = i + 1; j <= r; j++) {
                    sum += a[i] * a[j]; 
                }
            }
            if (sum % 3 == 0) {
                ans++; 
            }
        }
    }
    
    cout << ans; 
}

int main()
{   
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i]; 
    }

    // solve1(a); 
    // solve2(a);
    solve3(a);  

    return 0;
}