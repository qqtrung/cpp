// #include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <vector>
#include <cstdint>
#include <algorithm>

#define sz(v) ((int) v.size())
#define all(v) (v).begin(), (v).end() 

using namespace std; 
using int64 = int64_t; 
using ii = pair<int, int>; 


size_t DataType(int64 largeNumber) {
    return largeNumber; 
}

int main() {

    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr); 

    int64 largeNumber = 9223372036854775807; 

    vector<int> a = {4, 2, 3, 4, 1, 4}; 
    a.emplace_back(10);
    a.emplace_back(11);  

    sort(all(a)); 

    vector<int> v = {0, 3, 4, 8, 9, 10}; 
    int idx = lower_bound(v.begin(), v.end(), 9) - v.begin(); 

    return 0;
}
