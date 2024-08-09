/*

Cho 1 mảng gồm N phần tử. 
Ta chỉ được chọn giá trị đầu tiên hoặc giá trị cuối cùng trong dãy
Mỗi lần chọn 1 phần tử và xóa phần tử đó khỏi mảng 
Có hai người chơi và ta là người chơi đi trước 
Dữ liệu đầu vào đảm bảo ta có thể chiến thắng khi đi trước 

Nhiệm vụ: chúng ta cần tìm ra chúng ta có thể chiến thắng với số điểm tối thiểu là bao nhiêu 
Tại sao lại không cần tìm chiến thắng với số điểm tối đa do khi đó quá đơn giản. Bạn nghĩ người chơi thứ hai ngu ngốc như bạn sao. 

Ví dụ:
n = 6 : {4, 42, 39, 19, 25, 6} 

Ta có thể thấy chúng ta có thể chiến thắng tối thiểu với điểm số 68 như sau 
chúng ta chọn 4 sau đó đối thủ đương nhiên sẽ chọn 42 sau đó chúng ta chọn 39 
sau đó đối thủ sẽ chọn 19 sau đó chúng ta chọn 25 và cuối cùng đối thủ chọn 6 

Tổng điểm của ta là 68 và của đối thủ là 67 
Bài này rõ ràng ta không thể dùng thuật toán tham lam (greedy algorithm) và chúng ta nên dùng quy hoạch động (dynamic programing) 

*/

/*

Lý giải thuật toán quy hoạch động bên trên 
    +   Ta gọi dp[i][j] là giá trị chiến thắng tối thiểu trong đoạn v[i, j]
    +   Rõ ràng ban đầu ta có 2 sự lựa chọn tại vị trí i, j 
        
        +   Nếu ta chọn vị trí i: có nghĩa là đối thủ sẽ có quyền kiểm soát trong đoạn v[i + 1, j] 
                Nếu đối thủ chọn tại vị trí v[i + 1] thì sau đó chúng ta sẽ có quyền kiểm soát tại vị trí v[i + 2, j] 
                    Chúng ta sẽ thu được giá trị chiến thắng tối thiểu tại vị tí v[i + 2, j] 
                Nếu đối thủ chọn tại vị trí v[j] thì sau đó chúng ta sẽ có quyền kiểm soát tại vị trí v[i + 1, j - 1]
                    Chúng ta sẽ thu được giá trị chiến thắng tối thiểu tại vị trí v[i + 1, j - 1] 
            -> Nếu chọn vị trí i thì ta sẽ thu được hai vị trí chiến thắng tối thiểu là v[i + 2, j] && v[i + 1, j - 1] 
            -> Nếu chọn vị trí i thì ta sẽ thêm được gía trị chiến thắng tối thiểu sau: = min(dp[i + 2][j], dp[i + 1][j - 1])
        
        +   Nếu ta chọn vị trí j: có nghĩa là đối thủ sẽ có quyền kiểm soát trong đoạn v[i, j - 1] 
                Nếu đối thủ chọn tại vị trí v[i] thì sau đó chúng ta sẽ có quyền kiểm soát tại vị trí v[i + 1, j - 1] 
                    Chúng ta sẽ thu được giá trị chiến thắng tối thiểu tại vị tí v[i + 1, j - 1] 
                Nếu đối thủ chọn tại vị trí v[j - 1] thì sau đó chúng ta sẽ có quyền kiểm soát tại vị trí v[i, j - 2]
                    Chúng ta sẽ thu được giá trị chiến thắng tối thiểu tại vị trí v[i, j - 2] 
            -> Nếu chọn vị trí j thì ta sẽ thu được hai vị trí chiến thắng tối thiểu là v[i + 1, j - 1] && v[i, j - 2] 
            -> Nếu chọn vị trí j thì ta sẽ thêm được gía trị chiến thắng tối thiểu sau: = min(dp[i + 1][j - 1], dp[i][j - 2])
    
    +   Vậy để chiến thắng tối thiểu tại vị trí v[i, j]: thì ta có dp[i][j] = max { min { dp[i + 2][j],    } + v[i], min { dp[i + 1][j - 1], } + v[j] }
                                                                                        { dp[i + 1][j - 1] }             { dp[i][j - 2]      }                                                                      
*/ 


#include <iostream>
#include <vector>
#include <string>
using namespace std; 
using ll = long long; 

const int N = 100; 
ll dp[N][N] = {0}; 

int main()
{
    int n;
    cin >> n;

    vector<ll> a(n+1);
    for (int i = 1; i <= n; i++) 
        cin >> a[i]; 

    for (int j = 1; j <= n; j++) {
        for (int i = j; i >= 1; i--) {
            if (i == j) {
                dp[i][j] = a[i]; 
            } 
            else if (i == j - 1) { 
                dp[i][j] = max(a[i], a[j]); 
            }
            else {
                dp[i][j] = max ( min (dp[i + 2][j], dp[i + 1][j - 1]) + a[i], min (dp[i + 1][j - 1], dp[i][j - 2]) + a[j]); 
            }
        }
    }

    for (int j = 1; j <= n; j++) {
        for (int i = j; i >= 1; i--) {
            string s; 
            s += "dp[" + to_string(i) + "]" + "[" + to_string(j) + "]: " + to_string(dp[i][j]) + "\t\t"; 
            cout << s; 
        }
        cout << "\n"; 
    }
    cout << "Result = " << dp[1][n]; 
    return 0; 
}