#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <set>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");


int main() {
    int n;
    cin>>n;
    cin.get();
    set<int> numbers;
    string s;
    for (int i=0;i<n;i++){
        getline(cin, s);
        stringstream sio(s);
        int elem;
                while (sio >> elem)
                {
                    numbers.insert(elem);
                }
        cout<<"chisla: ";
        for(auto x: numbers)
      {
          
              cout<<x<<" ";
         }
        cout<<endl;
        numbers.clear();
        
    }
  
    /*
     3
     123 3546 123 45 9845 245
     chisla: 45 123 245 3546 9845
     124 12 124 35 12 0 -24 33 48 -17
     chisla: -24 -17 0 12 33 35 48 124
     99
     chisla: 99
     */
}
