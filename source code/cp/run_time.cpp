#include <bits/stdc++.h>
using namespace std; 
typedef long long ll; 



int main() 
{
    auto start = chrono::high_resolution_clock::now(); 
    cin.tie(0); 
    ios_base::sync_with_stdio(false); 
    
    ifstream in("input.txt"); 
    cin.rdbuf(in.rdbuf()); 

    ofstream out("output.txt"); 
    cout.rdbuf(out.rdbuf()); 

    // Your code

    auto stop = chrono::high_resolution_clock::now(); 
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start); 
    cerr << "Time taken by funtion: " << duration.count() << " miliseconds"; 

}