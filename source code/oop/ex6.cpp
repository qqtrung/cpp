#include <iostream>
#include <vector>
using namespace std; 


class Project 
{
public:
    virtual int grantMoney()
    {
        return 0; 
    }

    virtual void print() 
    {

    }
}; 

class Mvp : public Project 
{
private:
    string name; 
    int monthMarketing; 
    int monthOperating; 

public:

    Mvp(string name, int monthMarketing, int monthOperating) 
    {
        this->name = name; 
        this->monthMarketing = monthMarketing; 
        this->monthOperating = monthOperating; 
    }

    int grantMoney() 
    {
        return (monthMarketing + monthOperating) * 15000000; 
    }

    void print() 
    {
        cout << " San pham: " << name << ". " << "Van hanh: " << monthOperating << " thang. " << "Marketing " << monthMarketing << " thang. " << "Kinh phi: " << grantMoney() << "\n"; 
    }
}; 

class Idea : public Project 
{
private:
    string name; 
    int monthIdea; 

public:

    Idea(string name, int monthIdea) 
    {
        this->name = name; 
        this->monthIdea = monthIdea; 
    }

    int grantMoney() 
    {
        return monthIdea * 20000000; 
    }

    void print() 
    {
        cout << " Y tuong: " << name << ". " << "Phat trien: " << monthIdea << " thang. "  << "Kinh phi: " << grantMoney() << "\n"; 
    }


}; 


int main()
{
    cout << "Chuong trinh ho tro Hackathon cua AlphaTech thang 6/2023." << "\n";
     
    vector<Project*> projects = {
        new Idea("SuperTech", 6), 
        new Mvp("Futurecar", 6, 3), 
        new Idea("VirtualHouse", 7), 
        new Idea("NightVision", 4), 
        new Mvp("SmartKey", 4, 5)
    }; 

    cout << "So du an: " << projects.size() << endl; 
    int sum = 0; 
    for(int i = 0; i < projects.size(); i++) {
        sum += projects[i]->grantMoney(); 
        cout << i + 1 << "."; 
        projects[i]->print(); 
    }
    cout << "Tong tien tai tro: " << sum << "\n"; 

    for(int i = 0; i < projects.size(); i++) {
        delete projects[i];
    }
     
    return 0; 
}