#include <iostream>
#include <string>
#include "lists.cpp"
#include <fstream>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");


int main(){
    Stack<double> st1,st2,st0;
    Queue<double> q1,q2;
    List<double> l1;
    DoubleLinkedList<double> l2;
    double value;
    while (in>>value){
        if(value>=0){
            st2.Push(value);
            q2.Put(value);
            l1.Insert(l1.GetLength()+1, value);
            l2.InsertRight(l2.GetLength(), value);
            
        }
        else{
            st1.Push(value);
            q1.Put(value);
            
            if (l2.Getfirstplus()!=0){
                l1.Insert(l1.Getfirstplus()+1, value);
                l2.InsertRight(l2.Getfirstplus(), value);
            }
            else{
                l1.Insert(1, value);
                l2.InsertLeft(1, value);
            }
            }
    }
    while (!q2.Empty())
    {
        st0.Push(st2.Pop());
        q1.Put(q2.Get());
    }
    while (!st1.Empty()){
        st0.Push(st1.Pop());
    }
    while (!st0.Empty()){
        cout<<st0.Pop()<<" ";
    }
    cout<<endl;
    while (!q1.Empty()){
        cout<<q1.Get()<<" ";
    }
    cout<<endl;
    l2.PrintLeftToRight();
    l1.Print();
    l1.~List();
    l2.~DoubleLinkedList();
        in.close();
        out.close();
}
