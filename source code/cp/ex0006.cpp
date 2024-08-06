#include <bits/stdc++.h>
using namespace std; 
using ll = long long;

// O(n * 14)
void solve2(vector<string>& a) 
{
    unordered_map<string, int> cnt; 

    ll ans = 0; 
    for (string &s: a) {
        for (int j = 0; j < s.length(); j++) {
            if (s[j] == '-') 
                continue; 
            
            string t = s; 
            t[j] = '*'; 
             
            ans += cnt[t]; 
            cnt[t] += 1;
        }
    }

    cout << ans; 
}

bool check(string a, string b) 
{
    int cnt = 0; 
    int n = a.size(); 
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) 
            cnt++; 
    }
    return cnt == 1; 
} 

// O(n^2)
void solve1(vector<string>& a) 
{
    int ans = 0;
    int n = a.size(); 
    for (int i = 0; i + 1 < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (check(a[i], a[j])) 
                ans++; 
        }
    }
    cout << ans; 
}

int main()
{
    int n; 
    cin >> n; 
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i]; 

    // solve1(a); 
    solve2(a); 
    return 0; 
}