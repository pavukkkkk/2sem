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
    set<char> s,s1,s_difference;
    cin>>n;
    cin.get();
    getline(cin, str1);
    for (char x: str1){
        s1.insert(x);
    }
    for (int i=0; i<n-1; i++){
        getline(cin, str);
        for (int j=0; j<str.size(); j++){
            s.insert(str[j]);
        }
    }
    cout<<"unique letters in the first line: "<<endl;
    std::set_difference(s1.begin(), s1.end(),
        s.begin(), s.end(),
        std::inserter(s_difference,s_difference.end()));
    for (auto x : s_difference)
    {


        cout << x << " ";


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
