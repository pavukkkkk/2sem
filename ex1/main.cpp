//
//  main.cpp
//  ex1
//
//  Created by Константин Кириленко on 07.03.2022.
//

#include <iostream>
using namespace std;

int main() {
    int *a=new int(5);
    
    int *b=a;
    *a++;

    cout<<*a<<" "<<*b;
}
