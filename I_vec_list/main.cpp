#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main() {
    list <int>::iterator Iterl;
    vector <int>::iterator Iterv;
    vector<int> vec;
    list<int> lst;
    int n,a;
        cin>>n;
        for (int i=0;i<n;i++){
            cin>>a;
            vec.push_back(a);
            lst.push_back(a);
          
        }
    if (*(lst.begin())<*(lst.end())){
        Iterl=lst.end();
        Iterl--;
    }
    else{
        Iterl=lst.begin();
    }
    lst.erase(Iterl);
    Iterv=vec.end();
    Iterv--;
    for (int i=0;i<2;i++)
        vec[i]=*(Iterv)*(-1);
    for(int i: lst){
            
            cout<<i<<" ";
        
        }
    cout<<endl;
    for(int i: vec){
            
            cout<<i<<" ";
        
        }
    return 0;
}
/*
 5
 2 3 4 5 9
 2 3 4 5
 -9 -9 4 5 9
 
 4
 9 3 7 2
 3 7 2
 -2 -2 7 2
 */
