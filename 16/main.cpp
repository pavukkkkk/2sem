#include <iostream>
#include <string>
#include "Source.cpp"
#include <fstream>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");


int main() {
    Stack<double> st1, st2, st0,st10;
    Queue<double> q1, q2,q0,q10;
    List<double> l1,l10;
    DoubleLinkedList<double> l2,l20;
    double value;
    int k = 0,flag=0;
    while (in >> value) {
        k++;
        st10.Push(value);
        q10.Put(value);
        l10.Insert(l10.GetLength() + 1, value);
        l20.InsertRight(l20.GetLength(), value);
        
        
    }
    
    for (int i = 1; i <= k; i++) {
        value = l10.Get(i);
        if (value < 0) {
            
            if (flag == 0) {
                l1.Insert(1, value);
                l2.InsertLeft(1, value);
            }
            else {
                l1.Insert(flag + 1, value);
                l2.InsertRight(flag, value);
                

            }
            flag++;
            
        }
        else {
            l1.Insert(l1.GetLength() + 1, value);
            l2.InsertRight(l2.GetLength(), value);
        }
    }

    while (!q10.Empty()) {
        value = q10.Get();
        if (value >= 0) {
            q2.Put(value);
        }
        else
            q1.Put(value);

    }
    while (!st10.Empty()) {
        {
            st0.Push(st10.Pop());
        }

    } 
    while (!st0.Empty()) {
        value = st0.Pop();
        if (value >= 0) {
            st2.Push(value);
        }
        else
            st1.Push(value);


    }
    while (!q2.Empty())
    {
        st0.Push(st2.Pop());
        q1.Put(q2.Get());
    }
    while (!st1.Empty()) {
        st0.Push(st1.Pop());
    }
    while (!st0.Empty()) {
        cout << st0.Pop() << " ";
    }
    cout << endl;
    while (!q1.Empty()) {
        cout << q1.Get() << " ";
    }
    cout << endl;
    l2.PrintLeftToRight();
    l2.PrintRightToLeft();
    l1.Print();
    l1.~List();
    l2.~DoubleLinkedList();
    in.close();
    out.close();
}
