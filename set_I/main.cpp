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
    int n,k,number;
    
    set<int> s,s1;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>k;
        k=abs(k);
        s1.clear();
        while (k>0){
            number=k%10;
            k/=10;
            s1.insert(number);
        }
        for(auto x: s1)
        {
            if (s.end()==s.find(x)){
                cout<<x<<" ";
            }
            
            s.insert(x);
        }
        cout<<endl;
    }
  
    return 0;
}
/*
 4
 123
 1 2 3
 456
 4 5 6
 374
 7
 671
 */
