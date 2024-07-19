#include <iostream>
using namespace std;


class PrimeList
{
private:
    int *arr; 
    int size; 
    bool isPrime(int n)
    {
        if(n < 2) return false; 
        for(int i = 2; i * i <= n; i++) {
            if(n % i == 0) return false; 
        }
        return true; 
    }

public:

    PrimeList()
    {
        arr = nullptr; 
        size = 0; 
    }

    ~PrimeList()
    {
        delete[] arr; 
    }

    PrimeList(int upper_bound)
    {
        int cnt = 0; 
        for(int i = 2; i < upper_bound; i++) {
            if(isPrime(i))
                cnt++; 
        }

        if(cnt == 0) {
            arr = nullptr; 
            size = 0; 
        }
        else {
            size = cnt; 
            arr = new int[cnt]; 
            int idx = 0; 
            for(int i = 2; i < upper_bound; i++) {
                if(isPrime(i)) {
                    arr[idx] = i;
                    idx++; 
                }
            }
        }
    }

    friend ostream& operator<< (ostream &out, const PrimeList &list)
    {
        for(int i = 0; i < list.size; i++)
        {
            out << list[i] << " "; 
        }
        out << "\n"; 
        return out; 
    }

    void operator= (const PrimeList &other)
    {   
        if(arr == other.arr) 
            return; 
        
        if(arr != nullptr) 
            delete[] arr;
        
        if(other.size == 0 || other.arr == nullptr) {
            arr = nullptr; 
            size = 0; 
        } 

        size = other.size; 
        arr = new int[size]; 
        for(int i = 0; i < other.size; i++) {
            arr[i] = other.arr[i]; 
        }
    }

    void generate(int upper_bound)
    {
        if(arr == nullptr) 
            delete[] arr; 
        
        size = 0; 

        int cnt = 0;
        for(int i = 2; i < upper_bound; i++) {
            if(isPrime(i)) 
                cnt++; 
        }

        if(cnt == 0) {
            arr = nullptr; 
        }
        else {
            size = cnt; 
            arr = new int[cnt];     
            int idx = 0;
            for(int i = 2; i < upper_bound; i++) {
                if(isPrime(i)) {
                    arr[idx] = i;
                    idx++; 
                }
            }
        }   
    }

    int operator[] (int n) const 
    {
        return arr[n]; 
    }

    int count() 
    {
        return size; 
    }

}; 


int main()
{
    PrimeList list1(50);
    cout << "List1: " << list1; 
    list1.generate(30); 

    PrimeList list2;
    list2 = list1; 
    cout << "List2: " << list2; 
    cout << list2[list2.count() - 1] << endl; 

    return 0; 
}