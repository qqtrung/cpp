#include<iostream>
#include<assert.h> 
using namespace std;

int main()
{
    
    int x = 8; 
    x = 7; 
    if(x == 7) {
        assert(false); 
    } else {
        cout << "login successfully"; 
    }
    
    return 0;
}