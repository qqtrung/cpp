#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
using namespace std; 


class Mobile
{
private:
    string code;
    string name; 
    string brand; 
    string mfgday; 
public:
    Mobile()
    {

    }

    Mobile(string code, string name, string brand, string mfgday)
    {
        this->code = code;
        this->name = name; 
        this->brand = brand; 
        this->mfgday = mfgday; 
    }

    friend istream& operator>> (istream &in, Mobile &mobile) 
    {
        in >> mobile.code; 
        in >> mobile.name; 
        in >> mobile.brand; 
        in >> mobile.mfgday; 
        return in; 
    }

    friend ostream& operator<< (ostream &out, Mobile &mobile)
    {
        out << mobile.code << " | "; 
        out << mobile.name << " | "; 
        out << mobile.brand << " | "; 
        out << mobile.mfgday << "\n"; 
        return out; 
    }

    static bool compare(const Mobile &a, const Mobile b)
    {
        int dayA = stoi(a.mfgday.substr(0, 2)); 
        int monthA = stoi(a.mfgday.substr(3, 2)); 
        int yearA = stoi(a.mfgday.substr(6));

        int dayB = stoi(b.mfgday.substr(0, 2)); 
        int monthB = stoi(b.mfgday.substr(3, 2)); 
        int yearB = stoi(b.mfgday.substr(6));

        if(yearA != yearB) 
            return yearA < yearB; 
        else if(monthA != monthB) 
            return monthA < monthB; 
        else if(dayA != dayB) 
            return dayA < dayB; 
        
        return 0; 
    }

    bool operator< (const Mobile &other)
    {
        return compare(*this, other);
    }
    

}; 

int main()
{
    Mobile a("a", "iphone", "toyota", "05/09/2024"); 
    Mobile b("b", "samsung", "gucci", "06/10/1995"); 
    Mobile c("c", "xiaomi", "honda", "07/08/2024");     
    Mobile d("d", "yamaha", "huyndai", "05/08/2026"); 

    vector <Mobile> vector =  {
        a, b, c, d
    }; 

    // sort(vector.begin(), vector.end(), Mobile::compare);  
    sort(vector.begin(), vector.end()); 

    for(Mobile &mobile : vector) {
        cout << mobile; 
    }    
    return 0; 
}