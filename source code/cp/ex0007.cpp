#include <bits/stdc++.h>
using namespace std; 
using ll = long long; 

void solve()
{
    vector<string> a(9); 
    for (string &s : a) 
        cin >> s; 

    auto check = [&]() -> bool {
        // check rows 
        unordered_set<char> vis; 
        for (int i = 0; i < 9; i++) {
            vis.clear(); 
            for (int j = 0; j < 9; j++) {
                if (a[i][j] == '.') 
                    continue; 

                // iterator chả về con trỏ sau phần tử nên chỗ này coi như không tìm thấy 
                if(vis.find(a[i][j]) != vis.end()) 
                    return false; 

                vis.insert(a[i][j]); 
            }
        }

        // check cols 
        for (int j = 0; j < 9; j++) {
            vis.clear(); 
            for (int i = 0; i < 9; i++) {
                if (a[i][j] == '.') 
                    continue; 

                if(vis.find(a[i][j]) != vis.end()) 
                    return false; 

                vis.insert(a[i][j]); 
            }
        }

        auto check_square = [&](int r, int c) -> bool {
            vis.clear(); 
            for (int dr = 0; dr < 3; dr++) {
                for (int dc = 0; dc < 3; dc++) {
                    int i = r + dr; 
                    int j = c + dc; 

                    if (a[i][j] == '.')
                        continue; 
                    
                    if (vis.find(a[i][j]) != vis.end()) 
                        return false; 
                    
                    vis.insert(a[i][j]); 
                }
            }
            return true; 
        }; 

        // check squares 
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                if (!check_square(i, j)) 
                    return false; 
            }
        }
        return true; 
    }; 

    if (check()) 
        cout << "VALID\n"; 
    else 
        cout << "INVALID\n"; 

}

int main()
{
    int t; 
    cin >> t; 
    while(t--) 
        solve(); 

    return 0; 
}