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
        std::cout << "realthisPrivate->x: " << this << " " << this->x << std::endl;
    }

    void realthisProtected()
    {
        std::cout << "realthisProtected->x: " << this << " " << this->y << std::endl;
    }

    A* getThisA()
    {
        return this;
    }

    // the hien tinh da hinh cho nay neu khong co virtual thi khi cho den lop co so thi no se thuc thi ham o lop co so luon 
    // ma khong ghi de len phuong thuc nay. Neu trong class con co phuong thuc write thi khi co virtual no se ghi de len 
    // va thuc hien tinh da hinh o cho nay nhe day la 1 tinh rat hay trong con tro o tren cpp 
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

    /*
        friend std::istream& operator>>(std::istream &in, Point &point)
        {
            in >> point.r;
            in >> point.c;
            return in;
        }
    */

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

    /*
        ban chat la tra ve 1 con tro toi class istream de lay dau vao
        cua nguoi dung

        noi chung duoi day ta co the thay dung lop istream de lay dau
        vao cua nguoi dung nhu the nao

        chung ta co the hieu don gian istream& la kieu tra ve
        operator la ten cua ham
        dau vao la cac thu tren

        ta thuong khong the thay doi format cua ham nhap va xuat
        ly do cac ham nay da duoc viet san roi
    */
    

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


class STATIC
{
private: 
    // neu dung dong nay thi ta khong can khai bao bien ben ngoai 
    // dong nay chi chay duoc trong cpp 17 tro len 
    // static int st; 
    inline static int st = 1; 
    int a; 
public: 
    void checkStatic() 
    {
        st++; 
    }    
    int getst() 
    {
        return st; 
    }
    int *getAddressStatic()
    {
        return &st; 
    }
    int *getAddressnotStatic() 
    {
        return &a; 
    }

}; 
/*
    cai nay la neu ta khong dung inline ma ta dung ben ngoai
    nhung noi chung thi bay gio thuong se dung inline it ai 
    con dung ben ngoai nua 
*/
/* 
    int STATIC::st = 1; 
*/

class AbstractClass 
{
public:
    // pure virtual funtion 
    virtual void abstractClass() = 0; 
    /*
        pure virtual funtion la 1 ham thuan ao tuc la lop con ke thua tu abstractclass nay bat buoc
        phai cai dat pure virtual funtion nay thi moi khoi tao duoc class con  
    */
    virtual void Class() {} 
}; 

class Subclass : AbstractClass 
{
public:
    Subclass(std::string name) 
    {
        std::cout << name << "\n\n"; 
    }
    void abstractClass() {} // vi subclass ke thua tu abstractclass len bat buoc phai co dong nay moi khoi tao duoc subclass 
    void Class() {}  // dong nay co the co hoac khong co cung duoc 
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
    std::cout << std::endl << "\n";

    Point point;
    std::cin >> point;
    std::cout << point;
    std::cout << "\n";

    Super super;
    std::cin >> super;
    std::cout << super << "\n";

    /* 
        Qua vi du nay ta co the thay ban chat phep toan tu trong cpp
    */
    my_istream mis;
    int fin;
    mis.operator+(fin);
    mis + fin;
    mis.operator<<(fin);
    mis << fin;
    std::cout << mis.a << "\n\n";
    
    /*
        Ban chat cua bien static no se luu o 1 vung nho khi chung ta
        tao 1 constructor moi thi no se khong khoi tao lai dieu do rat co ich 
        boi le ham hay bien do no se duoc thuc thi o 1 vung nho rieng biet va khong
        can phai khoi tao lai dieu nay giup cai thien bo nho va hieu suat cua 
        chuong trinh chung ta 
    */
    
    /*
        noi tom lai ta thuong dung static cho bien khi bien do khong can thay 
        doi hoac khong muon bien do khoi tao lai de giup cai thien space 
        
        ham static ta thuong dung khi ham do dung chung cho cac doi tuong 
        co cung 1 phuong thuc giong nhau va cach hoat dong giong nhau 
        
        va ban chat cua bien static lien quan den vung nho khi thuc hien
        chuong trinh 
    */
    
    STATIC st1; 
    st1.checkStatic(); 
    STATIC st2; 
    st2.checkStatic(); 
    std::cout << st1.getst() << std::endl; 
    std::cout << st2.getst() << std::endl; 
    std::cout << "Address of memeber Static: " << "\n"; 
    std::cout << st1.getAddressStatic() << std::endl; 
    std::cout << st2.getAddressStatic() << std::endl;
    std::cout << "Address of member not Static: " << "\n"; 
    std::cout << st1.getAddressnotStatic() << std::endl; 
    std::cout << st2.getAddressnotStatic() << std::endl << "\n"; 

    // su khac biet giua virtual funtion va pure virtual funtion 
    Subclass subclass("pure virtual funtion"); 
     


}



    