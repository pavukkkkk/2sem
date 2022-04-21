#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

class Goods{
    string name;
    int n;
public:
    void changen(int n){
        this->n=n;
    }
    string getname(){
        return name;
    }
    int getn(){
        return n;
    }
    Goods(): name(""),n(0){}
    Goods(string s, int w): name(s),n(w){}
};

class GoodsList{
    list<Goods> lst;
public:
    void doble(int n){
   
    for (auto iter = lst.begin(); iter != lst.end(); iter++)
        {
            if ((*iter).getn()>n){
                (*iter).changen(n/2);
                lst.insert(iter, Goods((*iter).getname(),n/2));
            
            }
        }
    }
    void push(Goods a){
        lst.push_back(a);
        
    }
    void print(){
        for(auto i: lst){
                
                cout<<i.getname()<<" "<<i.getn();
            cout<<endl;
            
            }
    }
};

class GoodsVec{

    vector<Goods> vec;
public:
    void push(Goods a){
        vec.push_back(a);
        
    }
    Goods middle(){
        return vec[vec.size()/2];
    }
    void doble(int n){
        //переделать цикл
        const vector <Goods>::iterator Iterv=vec.end();
        for (auto iter = vec.begin(); iter != Iterv; iter++)
        {
            if ((*iter).getn()>n){
                (*iter).changen(n/2);
                vec.push_back(Goods((*iter).getname(),n/2));
            
            }
        }
    }
    void print(){
        for(auto i: vec){
                
                cout<<i.getname()<<" "<<i.getn();
            cout<<endl;
            
            }
    }
};



int main() {
    GoodsList l;
    GoodsVec v;
    int a;
    string s;
    int n,k;
    cin>>k>>n;
    for (int i=0;i<k;i++){
        {
            cin>>s>>a;
            Goods b(s,a);
       l.push(b);
            v.push(b);
        
        }
      
    }
    l.doble(n);
    v.doble(n);
    l.print();
    v.print();
    cout<<v.middle().getname()<<" "<<v.middle().getn()<<endl;
    return 0;
}
/*
 5 4
 a 2
 b 3
 c 4
 d 5
 e 6
 a 2
 b 3
 c 4
 d 2
 d 2
 e 2
 e 2
 a 2
 b 3
 c 4
 d 2
 e 2
 d 2
 e 2
 d 2
 */
