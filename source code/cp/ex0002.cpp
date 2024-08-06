#include <bits/stdc++.h>
using namespace std; 
typedef long long ll; 
const int mod = 10; 
const int N = 10;

// top_down dp 
ll dp[N]; 
ll fib(int n) // O(n)
{
    if (n == 1) 
        return 1; 
    
    if (n == 2) 
        return 2; 

    if (dp[n] > 0) 
        return dp[n]; 

    ll result = (fib(n - 1) % mod + fib(n - 2) % mod) % mod; 
    dp[n] = result; 
    return result; 
}

// bottom_up dp 
void solve1() // O(n)
{
    ll n; 
    cin >> n; 

    dp[0] = 1; 
    dp[1] = 1;
    dp[2] = 2; 

    for (ll i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] %= mod;  
    }
    cout << dp[n] << "\n"; 
}

struct Matrix
{
    ll X[2][2] = {0}; 

    friend Matrix operator * (const Matrix& a, const Matrix& b) 
    {
        Matrix c; 
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    c.X[i][j] += a.X[i][k] * b.X[k][j]; 
                    c.X[i][j] %= mod; 
                }
            }
        }       
        return c; 
    }
}; 

Matrix power(const Matrix & a, ll n) 
{
    if (n == 1) 
        return a; 
    
    Matrix result = power(a, n / 2); 

    if(n % 2 == 0) 
        return result * result; 
    
    return result * result * a; 
}

void solve2() // O(log(n)) 
{
    ll n; 
    cin >> n; 

    Matrix a; 
    a.X[0][0] = 1; 
    a.X[0][1] = 1; 
    a.X[1][0] = 1; 
    a.X[1][1] = 0; 

    Matrix ans = power(a, n); 
    cout << ans.X[0][0] << "\n";
}

void solve() 
{
    // ll n; 
    // cin >> n; 
    // cout << fib(n) << "\n"; 
    // solve1(); 
    solve2(); 
}

int main()
{
    int t; 
    cin >> t; 
    while(t--) {
        solve(); 
    }
    return 0; 
}