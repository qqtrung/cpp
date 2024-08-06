#include <iostream>
#include <vector>
using namespace std; 

class Mobile
{
private:   
    string name; 
    int price; 

public:

    Mobile()
    {
        
    }

    Mobile(string name, int price) 
    {
        this->name = name;
        this->price = price; 
    }

    void print()
    {
        cout << name << " - " << price << " d\n";  
    }
}; 

class Crawler : public Mobile
{

private:
    string url;
    
public: 

    Crawler(string url) 
    {
        this->url = url; 
    }

    vector<Mobile *> execute() 
    {
        vector<Mobile *> items; 
        items.push_back( new Mobile("iphone 11 64GB", 8950000) ); 
        items.push_back( new Mobile("iphone 11 128GB", 12500000) ); 
        items.push_back( new Mobile("iphone 13 Pro Max 256GB", 18990000) ); 
        items.push_back( new Mobile("iphone 14 Pro 512GB", 23790000) );   
        return items;       
    }

}; 


int main()
{   
    string url = "Mobiles.com/iphone";     
    Crawler *task = new Crawler(url); 
    vector<Mobile *> items = task->execute(); 
    
    cout << "Crawled " << items.size() << " phone from" << url << "\n"; 

    for(Mobile *Mobile : items) {
        Mobile->print(); 
    }

    return 0; 
}