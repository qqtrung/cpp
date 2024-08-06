#include <bits/stdc++.h>
using namespace std; 
typedef long long ll; 
const int N = 10; 
int C[N][N] = {0}; 

/*

9! / (4! * 3! * 2!) = 9.8.7.6 / 4.3.2.1 * 5.4.3 / 3.2.1 * 2.1 / 2.1 = 9C4 * 5C3 * 2C2 

*/

int main()
{
    C[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];  
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            cout << C[i][j] << " "; 
        }
        cout << "\n"; 
    }

    cout << C[9+1][4+1] * C[5+1][3+1] * C[2+1][2+1]; 

    return 0; 
}