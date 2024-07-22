#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Employee
{
public:
    int id;
    string name;
public:
    Employee() = default;
    Employee(int id, string name) {
        this->id = id;
        this->name = name;
    }

    friend ostream& operator<< (ostream &out, const Employee &emp)
    {
        out << emp.id << " " << emp.name << "\n";
        return out;
    }
};

int main()
{
    const string sort_field = "name";
    vector<Employee> emps = {
        Employee(0, "trung"),
        Employee(1, "nam"),
        Employee(2, "ngoan"),
        Employee(3, "tam"),
        Employee(4, "thuy"),
    };

    auto compare = [&sort_field] (const Employee &a, const Employee &b)
                   -> bool
    {
        if (sort_field == "name") {
            return a.name < b.name;
        }
        else if (sort_field == "id") {
            return a.id < b.id;
        }
        else {
            return false;
        }
    };

    sort(emps.begin(), emps.end(), compare);
    for (Employee &emp : emps) {
        cout << emp;
    }
    cout << compare(emps[0], emps[1]);

    return 0;
}
