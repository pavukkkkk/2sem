#include <iostream>
#include <fstream>
using namespace std;
ifstream in("input.txt");




class Money
{
private:
    int nominal;
    int amount;
public:
    Money() : nominal(0), amount(0) {
    }
    Money(int x, int y) : nominal(x), amount(y) {
    }
    void printnom() {
        cout << nominal;
    }
    void printam() {
        cout << amount<<endl;
    }
    bool budjet(int x) {
        return nominal * amount >= x;
    }
    int number(int x) {
        return (nominal * amount) / x;

    }
    int sum() {
        return nominal * amount;
    }
    void set_n_a(int x, int y)
    {
        nominal = x;
        amount = y;
    }
    Money& operator ++() {
        ++amount;
        return *this;
    }
    Money& operator--() {
        --amount;
        return *this;
    }
    Money operator ++(int) {
        Money tmp = *this;
        amount++;
        return tmp;
    }
    Money operator --(int) {
        Money tmp = *this;
        amount--;
        return tmp;
    }
    Money operator + (int x) {
        return Money(nominal, amount + x);
    }
    Money operator - (int x) {
        return Money(nominal, amount + x);
    }

    void inputc() {
        in >> nominal >> amount;
    }
    void outc() {
        cout << nominal << " " << amount << endl;
    }
    friend Money operator +(int x, Money& tht) {
        return Money(tht.nominal, tht.amount + x);
    }
    friend Money operator -(int x, Money& tht) {
        return Money(tht.nominal, x - tht.amount);
    }
};



int main() {

    Money* a = new Money[1000000];
    int i = 0;
    a[i].inputc();
    while (!in.eof()) {
        (a[i]++).printam();
        cout << " ";
        (a[i] + 5).printam();
        cout << " ";
        (10 - a[i]).printam();
        cout << " ";
        cout << a[i].budjet(3000);
        cout << " ";
        cout << a[i].number(30000);
        cout << endl;
        i++;
        a[i].inputc();


    }
    cout << endl << endl;
    a[0].printam();
    ++a[0];
    a[0].printam();
    a[1] = ++(++a[0]);
    a[0].printam();
    a[1].printam();
    in.close();

    return 0;
}
