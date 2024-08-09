#include <iostream>
#include <map>
#include <vector>
#include <cstdint>
#include <algorithm>

using namespace std; 
using int64 = int64_t; 
using ii = pair<int, int>; 
#define sz(v) ((int) v.size())
#define all(v) (v).begin(), (v).end() 


size_t DataType(int64 largeNumber) {
    return largeNumber; 
}

int main() {

    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr); 

    int64 largeNumber = 9223372036854775807; 
    cout << DataType(largeNumber) << "\n"; 
    
    vector<int> a = {4, 2, 3, 4, 1, 4}; 
    a.emplace_back(10); // faster push_back 

    sort(all(a)); 
    // for (int i = 0; i < sz(a); i++) {
    //     cout << a[i] << " "; 
    // }

    return 0;
}
