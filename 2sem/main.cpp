
#include <iostream>
using namespace std;
int f(int a){
    a=abs(a);
    int k=2;
    int i=2;
    while (i*i<a){

        if (a%i==0){
            k+=2;
        }
        i++;
        
    }
    if (i*i==a){
        k++;
    }
    return k;
}

int g(int a){
    int b = f(a);
    for (int i=a+1; ;i++){
        if (f(i)==b){
            return i;
        }
    }
    
}
int grec(int a, int b){
    if (f(a)==b){
        return a;
    }
    return grec(a+1,b);
    
}
int main() {
  
    int a;
    cout<<"Vvedite chislo: ";
    cin >>a;
    cout<<"Chislo s takim je kol-vom deliteley: ";
    cout<<g(a)<<endl;
    cout<<grec(a+1,f(a))<<endl;
}
/*
 Test
 vedite chislo: 10
 Chislo s takim je kol-vom deliteley: 14
 Vvedite chislo: 3
 Chislo s takim je kol-vom deliteley: 5
 Vvedite chislo: 22
 Chislo s takim je kol-vom deliteley: 26
 */
