#include <iostream>
#include <string>

using namespace std;

class Auto
{
public:

    Auto(string type)//конструктор класса
    {
        this->type = type;
    }

    virtual string GetType()//вирутальная функция, чтобы можно было переопределить ее в наследнике, которая выводит тип/марку машины
    {
        return type;
    }
private:
    string type;//тип/марка машины
};

class wheels : public Auto//класс наследник от предыдущего
{
public:
    wheels(string type):Auto(type)//делегирующий конструктор без собственной логики, тот же самый что и прошлом
    {}
    string GetType() override
    {
        return "4 wheels " + ::Auto::GetType();//переопределяем виртуальную функцию, с указанием класса откуда берем функцию иначе получим рекурсию, потому что будет вызывать сам себя
    }
};

class Driver
{
public:
    void print(Auto* type)//просто выводим на экран
    {
        cout << type->GetType() << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "ru");
    Auto a1("sedan");
    wheels w1("hach");

    Driver d1;
    d1.print(&w1);
}