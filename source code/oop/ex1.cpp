#include <iostream>

class C
{
public:
    static void endlC()
    {
        std::cout << std::endl;
    }
};

class A
{
public:
    std::string z = "public string A";
protected:
    std::string y = "class A";
private:
    std::string x;
public:

    A()
    {
        static int k = 0;
        int h = 0;
        std::cout << "ctor a,static " << k << ",int " << h;
        k++;
        h++;
        C::endlC();
    }

    ~A()
    {
        std::cout << "dtor a";
        C::endlC();
    }

    A(std::string str)
    {
        std::cout << "ctor str a\n";
        this->x = str;
    }

    A& operator= (const A& other)
    {
        x = "operator + " + other.x;
        return *this;
    }

    void set(std::string other)
    {
        x = other;
    }

    std::string get()
    {
        return this->x;
    }

    void realthisPrivate()
    {
        std::cout << "realthis->x: " << this << " " << this->x << std::endl;
    }

    void realthisProtected()
    {
        std::cout << "realthis->x: " << this << " " << this->y << std::endl;
    }

    A* getThisA()
    {
        return this;
    }

    virtual void write()
    {

    }

};

class B : public A   // no private
{
private:
    std::string x = "class B";
public:
    B()
    {
        std::cout << "ctor b";
        C::endlC();
    }

    B(std::string str)
    {
        this->x = str;
    }

    ~B()
    {
        std::cout << "dtor b";
        C::endlC();
    }

    using A::write;
    using A::get;
    using A::realthisPrivate;
    using A::realthisProtected;
    using A::set;
    using A::getThisA;

    void write()
    {
        std::cout << "class B" << std::endl;
    }

};

class D : public A   // no private
{
public:
    std::string z = "public string D";
private:
    std::string x;
public:
    D()
    {
        std::cout << "ctor d";
        C::endlC();
    }

    ~D()
    {
        std::cout << "dtor d";
        C::endlC();
    }

    using A::write;
    using A::get;
    using A::realthisPrivate;
    using A::realthisProtected;
    using A::set;
    using A::getThisA;

    void write()
    {
        std::cout << "class D" << std::endl;
    }

    D* getThisD()
    {
        return this;
    }
};

class E : public D
{
private:
    std::string x;
public:
    E()
    {
        std::cout << "ctor e";
        C::endlC();
    }

    ~E()
    {
        std::cout << "dtor e";
        C::endlC();
    }

    using D::write;
    using D::get;
    using D::set;
    using D::realthisPrivate;
    using D::realthisProtected;
    using D::getThisA;
    using D::getThisD;

    void write()
    {
        std::cout << "class E" << std::endl;
    }
};


class Friend
{
private:
    std::string name;
    int numberOfFriend = 0;
public:

    Friend()
    {
        std::cout << "ctor Friend";
        C::endlC();
    }

    Friend(std::string name)
    {
        static int numberOfFriend = 0;
        numberOfFriend++;

        if(numberOfFriend > 3)
        {
            std::cout << "Friend Overload";
            C::endlC();
        }
        else
        {
            std::cout << "ctor " << name << "\n";
            this->name = name;
            this->numberOfFriend = numberOfFriend;
        }
    }

    ~Friend()
    {
        std::cout << "dcor Friend";
        C::endlC();
    }

    int getnumberOfFriend()
    {
        return numberOfFriend;
    }

};


class Data
{
public:
    virtual void DataType()
    {
    }
};

class Float: public Data
{
public:
    void DataType()
    {
        std::cout << "Float\n";
    }
};


class Int: public Data
{
public:
    void DataType()
    {
        std::cout << "Int\n";
    }
};

template <typename T> // typename == class
T myMax(T a, T b)
{
    return (a > b) ? a : b;
}

template <typename T>
void InsertSort (T *a, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(a[i] < a[j])
            {
                T tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}


struct Point
{
    int r;
    int c;

    /*friend std::istream& operator>>(std::istream &in, Point &point)
    {
        in >> point.r;
        in >> point.c;
        return in;
    }*/

    friend std::istream& operator>> (std::istream &in, Point &point)
    {
        in >> point.r;
        in >> point.c;
        return in;
    }

    friend std::ostream& operator<< (std::ostream &out, Point &point)
    {
        out << point.r << " ";
        out << point.c << "\n";
        return out;
    }
};

struct Super
{
    std::string name;

    // ban chat la tra ve 1 con tro toi class istream de lay dau vao
    // cua nguoi dung

    // noi chung duoi day ta co the thay dung lop istream de lay dau
    // vao cua nguoi dung nhu the nao

    // chung ta co the hieu don gian istream& la kieu tra ve
    // operator la ten cua ham
    // dau vao la cac thu tren

    // ta thuong khong the thay doi format cua ham nhap va xuat
    // ly do cac ham nay da duoc viet san roi

    friend std::istream& operator>> (std::istream &in, Super &super)
    {
        std::cout << "Nhap sieu nhan: ";
        // in >> super.name;
        in.ignore();
        getline(in, super.name);
        return in;
    }

    // cung giong nhu tren thoi
    friend std::ostream& operator<< (std::ostream &out, Super &super)
    {
        std::cout << "Sieu nhan cua ban ten la: ";
        out << super.name << "\n";
        return out;
    }
};

struct my_istream
{ 
    int a;
    
    void operator+(int x) {
        std::cout << this << "\n";
        a = 8484;
    }

    void operator<<(int x) {
        std::cout << this << "\n";
    }
};


int main()
{
    A a0("nqtrung");
    std::cout<<std::endl;
    B b0;
    std::cout<<std::endl;
    D d0;
    std::cout<<std::endl;
    E e0;
    std::cout<<std::endl;

    a0.set("Nqtrung");
    A c0;
    std::cout<<std::endl;
    c0 = a0;


    a0.write();
    c0.write();
    std::cout<<std::endl;

    a0.realthisPrivate();
    c0.realthisPrivate();
    std::cout<<std::endl;

    b0.write();
    d0.write();
    std::cout<<std::endl;

    b0.realthisPrivate();
    d0.realthisPrivate();
    std::cout<<std::endl;

    b0.realthisProtected();
    d0.realthisProtected();
    std::cout<<std::endl;

    A* p0 = b0.getThisA();
    D* p1 = e0.getThisD();
    std::cout << p0->z << std::endl;
    std::cout << p1->z << std::endl;
    std::cout<<std::endl;

    Friend friend1("nqtrung");
    Friend friend2("kgbien");
    Friend friend3("ntlam");
    Friend friend4("ddhai");
    std::cout << std::endl;

    std::cout << "friend1 " << friend1.getnumberOfFriend();
    C::endlC();
    std::cout << "friend2 " << friend2.getnumberOfFriend();
    C::endlC();
    std::cout << "friend3 " << friend3.getnumberOfFriend();
    C::endlC();
    std::cout << "friend4 " << friend4.getnumberOfFriend();
    C::endlC();
    std::cout << std::endl;


    Int a;
    Float b;
    Data& x = a;
    Data& y = b;
    x.DataType();
    y.DataType();
    std::cout << std::endl;


    Int c;
    Float d;
    Data* e[] = {&c, &d};
    for(int i = 0; i < 2; i++)
    {
        std::cout << "DataType ";
        e[i]->DataType();
    }
    std::cout << std::endl;

    std::cout << myMax(4, 5);
    std::cout << std::endl;
    std::cout << myMax('t', 'a');
    std::cout << std::endl;
    std::cout << std::endl;

    int q[] = {5, 3, 7, 8, 1, 4};
    int n = sizeof(q) / sizeof (*q);
    InsertSort /*<int>*/ (q, n);
    std::cout << "Insertion sort: "; 
    for(int i = 0; i < n; i++)
    {
        std::cout << q[i] << " ";
    }
    std::cout << std::endl;

    Point point;
    std::cin >> point;
    std::cout << point;

    Super super;
    std::cin >> super;
    std::cout << super << "\n";

    /* Qua vi du nay ta co the thay ban chat phep toan tu trong cpp*/
    my_istream mis;
    int fin;
    mis.operator+(fin);
    mis + fin;
    mis.operator<<(fin);
    mis << fin;
    std::cout << mis.a << "\n";


}



