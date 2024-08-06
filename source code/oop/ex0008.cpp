#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std; 

class CurrencyFormatterStrategy
{
public:
    virtual string format(long long money) = 0; 
}; 

class ViVnCurrencyFormatterStrategy : public CurrencyFormatterStrategy
{
public:
    string format(long long money) 
    {
        return "ViVnCurrencyFormatterStrategy(" + to_string(money) + ")"; 
    }
}; 

class EnUsCurrencyFormatterStrategy : public CurrencyFormatterStrategy
{
public:
    string format(long long money) 
    {
       return "EnUsCurrencyFormatterStrategy(" + to_string(money) + ")"; 
    }
}; 

class CurrencyFormatter
{
private:
    CurrencyFormatterStrategy* strategy; 
public:
    void setStrategy(CurrencyFormatterStrategy* strategy) 
    {
        this->strategy = strategy; 
    }

    string format(long long money) 
    {
        return strategy->format(money); 
    }
}; 

class LayoutItem
{
public:
    virtual map<string, string> getInfo() = 0; 
}; 

class LayoutStrategy
{   
protected:
    vector<LayoutItem*> layoutItems; 
    vector<string> attributeNames; 
public:
    virtual void print() = 0; 

    void addItem(LayoutItem* item) {
        layoutItems.push_back(item); 
    }

    void setAttributeNames(vector<string>& attributeNames) 
    {
        this->attributeNames = attributeNames; 
    }
}; 

class Layouter
{
private:
    LayoutStrategy* strategy; 
public:
    void setStrategy(LayoutStrategy *strategy)  
    {
        this->strategy = strategy; 
    }

    void print() 
    {
        strategy->print(); 
    }

    void addItem(LayoutItem *item) 
    {
        strategy->addItem(item); 
    }

    void setAttributeNames(vector<string>& attributeNames) 
    {
        strategy->setAttributeNames(attributeNames); 
    }
    
}; 

class SimpleLayoutStrategy : public LayoutStrategy
{
public:
    void print() 
    {
        for(int i = 0; i < layoutItems.size(); i++) {
            LayoutItem *layoutItem = layoutItems[i]; 

            map<string, string> info = layoutItem->getInfo(); 

            for(int j = 0; j < attributeNames.size(); j++) {
                string attributeName = attributeNames[j];
                cout << info[attributeName]; 

                if(j + 1 < attributeNames.size()) {
                    cout << "\t-\t"; 
                }  
            }
            cout << "\n"; 
        }
    }
}; 

class TableLayoutStrategy : public LayoutStrategy
{
public:
    void print() 
    {
        for(int i = 0; i < attributeNames.size(); i++) {
            string attributeName = attributeNames[i]; 
            cout << attributeName << "\t|\t"; 
        }
        cout << "\n";

        for(int i = 0; i < layoutItems.size(); i++) {
            LayoutItem *layoutItem = layoutItems[i]; 

            map<string, string> info = layoutItem->getInfo(); 

            for(int j = 0; j < attributeNames.size(); j++) {
                string attributeName = attributeNames[j];
                cout << info[attributeName]; 

                if(j + 1 < attributeNames.size()) {
                    cout << "\t-\t"; 
                }  
            }
            cout << "\n"; 
        }
    }
}; 



class Mobile : public LayoutItem
{
private:
    string name;
    long long price; 
    CurrencyFormatter *currencyFormatter;  
public:
    Mobile(string name, long long price) 
    {
        this->name = name; 
        this->price = price; 
    }

    void print() 
    {
        cout << name << " - " << currencyFormatter->format(price); 
    }

    void setCurrencyFormatter(CurrencyFormatter *currencyFormatter) 
    {
        this->currencyFormatter = currencyFormatter; 
    }

    map<string, string> getInfo()
    {
        map<string, string> info; 
        info["Name"] = name; 
        info["Price"] = currencyFormatter->format(price); 
        return info; 
    }
}; 

class Crawler
{
private:    
    const char* url; 
public:
    Crawler(const char* url) 
    {
        this->url = url; 
    }

    vector <Mobile*> execute()
    {
        vector<Mobile*> list; 
        list.push_back(new Mobile("Iphone 11 64GB", 20000000)); 
        list.push_back(new Mobile("Iphone 12 64GB", 25000000)); 
        list.push_back(new Mobile("Iphone 13 64GB", 30000000)); 
        list.push_back(new Mobile("Iphone 14 64GB", 35000000)); 
        return list; 
    }
}; 



int main()
{   
    const char* url = "mobiles.com/iphone"; 

    Crawler* task = new Crawler(url); 
    vector<Mobile*> items = task->execute(); 
 
    cout << "Crawred " << items.size() << " phones from " << url << "\n"; 

    CurrencyFormatter* currencyFormatter = new CurrencyFormatter(); 
    CurrencyFormatterStrategy* strategy = new ViVnCurrencyFormatterStrategy();     
    currencyFormatter->setStrategy(strategy); 

    Layouter* layouter = new Layouter(); 
    LayoutStrategy *layoutStrategy = new TableLayoutStrategy(); 
    layouter->setStrategy(layoutStrategy); 

    vector<string> attributeNames = {"Name", "Price"}; 
    layouter->setAttributeNames(attributeNames); 

    for(Mobile *mobile: items) 
    {
        mobile->setCurrencyFormatter(currencyFormatter); 
        layoutStrategy->addItem(mobile); 
    }
    layouter->print(); 

    // for(Mobile *mobile: items) 
    // {
    //     mobile->setCurrencyFormatter(currencyFormatter); 
    //     mobile->print(); 
    //     cout << "\n"; 
    // } 
    return 0; 
}