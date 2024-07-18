/*
    Xóa các phần tử khoảng trắng ở cuối mảng và đưa ra vị trí cần xóa nếu không cần xóa thì in ra không cần xóa 
    Nếu cần xóa thì in ra xóa ở vị trí nào 
 
    char a[] = {' ', ' ', 'A', 'c', ' ', ' '};  -> xóa ở vị trí 5 
    char a[] = {' ', ' ', ' '};                 -> xóa ở vị trí 1 
    char a[] = {' ', ' ', 'a', 'b'};            -> không cần xóa 
*/

#include <iostream>
#include <cstring>
using namespace std; 

int main() 
{
     
    char a[] = {' ', ' ', 'A', 'c', ' ', ' ', '\0'};  // -> xóa ở vị trí 5 
    // char a[] = {' ', ' ', ' ', '\0'};                 // -> xóa ở vị trí 1 
    // char a[] = {' ', ' ', 'a', 'b', '\0'};            // -> không cần xóa 

    int lengthA = strlen(a); 

    bool p = false; 
    int idx = 0; 

    for(int i = 0; i < lengthA; i++) {
        if(isalpha(a[i])) {
            p = true; 
        } 
        else 
        {
            if(p) {
                idx = i; 
            } 
            p = false; 
        }
    }

    if(p == false) {
        cout << "Vi tri xoa " << idx + 1 << "\n"; 
    } else {
        cout << "Khong can xoa" << "\n"; 
    }

    return 0; 
}