#include <iostream>
using namespace std;

struct Beverage
{
    Beverage() 
    {
        cout << "Make new beverage.\n"; 
    }
    Beverage(const Beverage &b) 
    {
        cout << "Copy beverage.\n"; 
    }
}; 

struct Coffee: public Beverage
{
    Coffee() 
    {
        cout << "Make new Coffee.\n"; 
    }
    Coffee(const Coffee &c)
    {
        cout << "Copy coffee.\n"; 
    }
};

struct Cappuchino : public Coffee
{
    Cappuchino() 
    {
        cout << "Make new cappuchino.\n"; 
    }
    // Cappuchino(const Cappuchino& other)
    // {
    //     cout << "Copy Cappuchino.\n"; 
    // }
}; 

int main()
{   

    Cappuchino c1;
    Cappuchino c2(c1); 

    return 0; 
}