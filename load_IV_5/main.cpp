#include <iostream>
#include <string>
#include <cmath>
using namespace std;
long double eps = pow(10, -9);
double a,b;

float F(float x){
    if (x*x-5*x >= 10+eps) {
            return a*b;
        }
        else if((x*x-5*x +eps <= 0 ) && x*x-5*x > 10 +eps) {
            return a-b;
        }
        else if (x*x-5*x +eps < 0) {
            return a+b;
        }
    return 0;
}

void F(float x, float &y){
    y=F(x);
    
}
int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "введите диапазон: ";
    double h;
    cin >> a >> b;
    cout << "введите шаг: ";
    cin >> h;
    float y=0;
    for (double i = a; i < b + eps; i += h) {
        F(i,y);
        cout << "f(" << i << ")\t=" << F(i)<<"\t"<< y<< endl;
    }

}
/*
 введите диапазон: 1 1.5
 введите шаг: 0.1
 f(1)    =2.5    2.5
 f(1.1)    =2.5    2.5
 f(1.2)    =2.5    2.5
 f(1.3)    =2.5    2.5
 f(1.4)    =2.5    2.5
 f(1.5)    =2.5    2.5
 */
