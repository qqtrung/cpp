/*
    Có K thợ mỏ và N tờ tiền. 
    Hãy tìm cách chia đều tiền nhất có thể sao cho độ chênh lệch giữa người được nhập cao nhất và thấp nhất là bé nhất 
    In các tờ tiền và tổng tiền mà người nhận nhận được 
*/

#include <iostream>
#include <vector> 
using namespace std; 
const int msize = 10; 

vector <int> a[msize];

void show(int k) 
{
    for(int q = 1; q <= k; q++) {

        int sum = 0; 
        for(int p : a[q]) {
            sum += p; 
        }

        cout << "Nguoi thu " << q << ": "; 
        for(int p : a[q]) {
            cout << p << " "; 
        } 
        cout << "= " << sum << "\n"; 

    }

    cout << "----------\n"; 
}

void solve(const int money[], int k, int size, int position)  
{
    if(position == size) {
        show(k);
        return; 
    }

    for(int j = 1; j <= k; j++) {
        a[j].push_back(money[position]);  
        solve(money, k, size, position+1); 
        a[j].pop_back(); 
    }
}

int main()
{
    int k = 3; 
    int money[] = {3, 6, 15, 16, 21}; 

    solve(money, k, sizeof(money) / sizeof (*money), 0); 

    return 0; 
}