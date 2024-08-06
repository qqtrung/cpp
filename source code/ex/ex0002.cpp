/*
    Cho hai mảng a, b và giá trị k. 
    Hãy thử tìm kiếm xem các phần tử trong mảng a và b có tổng a[i] + b[j] = k hay không 
    Nếu có hãy in 1 trường hợp đó ra màn hình. 
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 
int main() 
{
    int k = 17; 
    vector<int> a = {0, 1, 2, 3, 4, 5, 6, 7}; 
    vector<int> b = {3, 4, 5, 6, 7, 8, 9, 10}; 

    sort(a.begin(), a.end()); 
    sort(b.begin(), b.end()); 

    int n = a.size(); 

    int i = 0; 
    int j = n - 1; 

    while (i < n && j >= 0)
    {
        if(a[i] + b[j] == k) {
            cout << a[i] << " " << b[j] << endl; 
            break; 
        }
        else if(a[i] +b[j] > k) {
            j--; 
        } 
        else {
            i++; 
        }
    }
     

    return 0; 
}