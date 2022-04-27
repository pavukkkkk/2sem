#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#include <iostream>
#include <numeric>
#include <set>

#include <iostream>
#include <string>

using namespace std;
int main() {
    int n;
    string str, str1;
    set<char> s;
    cin>>n;
    cin.get();
    getline(cin, str1);
    for (int i=0; i<n-1; i++){
        getline(cin, str);
        for (int j=0; j<str.size(); j++){
            s.insert(str[j]);
        }
    }
    cout<<"unique letters in the first line: "<<endl;
    for(auto x: str1)
    {
    if (s.end()==s.find(x)){
            cout<<x<<" ";
       }
   
}
}
/*
 3
  fas
  fgj
  ,jl
 unique letters in the first line:
 a s
 
 
 3
 fgh
 dskmfg
 hl;m;lmb
 unique letters in the first line: 
 */
