#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;

void solve()
{
    struct tm t; 
    scanf("%d-%d-%d %d:%d:%d", &t.tm_year, &t.tm_mon, &t.tm_mday, &t.tm_hour, &t.tm_min, &t.tm_sec);

    t.tm_year -= 1900;
    t.tm_mon -= 1; 

    time_t ans = mktime(&t); 
    cout << ans << "\n"; 
}

int main()
{
    solve(); 
    return 0; 
}