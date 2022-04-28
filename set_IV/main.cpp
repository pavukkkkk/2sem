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


int main() {
    int n;
    cin >> n;
    cin.get();
    set<int> numbers1, numbers2, numbers3;
    string s1,s2;
    getline(cin, s1);
    stringstream sio1(s1);
    int elem;
    while (sio1 >> elem)
    {
        if (numbers3.find(elem) == numbers3.end()) {
            numbers1.insert(elem);
            numbers3.insert(elem);
        }
        else {
            numbers1.erase(elem);
        }
    }
    numbers3.clear();
    for (int i = 0; i < n-1; i++) {
        getline(cin, s2);
      
        stringstream sio2(s2);
       
        
        while (sio2 >> elem)
        {
            if (numbers3.find(elem) == numbers3.end()) {
                numbers2.insert(elem);
                numbers3.insert(elem);
            }
            else {
                numbers2.erase(elem);
            }
        }
        cout << "chisla: ";
        for (auto x : numbers1)
        {

            if (numbers3.find(x) == numbers3.end()) {
                cout << x << " ";
            }

        }
        cout << endl;
        numbers1 = numbers2;
        numbers2.clear();
        numbers3.clear();

    }

    /*
5
123 345 67 34 345
213 43 345 122
chisla: 34 67 123
123 345 67 34 345
chisla: 43 122 213
123 100 500 500
chisla: 34 67
1
chisla: 100 123



3
123 23 123 324 123 14
15 23
chisla: 14 324
     */
}

#include <map>
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
using namespace std;
bool dig(string s) {
    set<char> n{'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
    if (s[0] == '-' && s.length() > 1 || n.find(s[0]) != n.end()) {
        for ( int i = 1; i < s.length(); i++) {
            if (n.find(s[i]) == n.end()) {
                return false;
            }
        }
        return true;
    }
    return false;
}


int main()
{
    int n, i=0;
    string s;
    map<int, string> m1;
    ifstream in("input.txt");
    ofstream out("output.txt");
    while (in >> s) {
        i++;
        if (!dig(s)) {
            m1[i] = s;
        }
    }

    for (auto x : m1)
    {
        if (x.second.length() % (x.first) == 0)
        {
            cout << x.first << " " << x.second << endl;
        }
    }
    in.close();
    out.close();
  
}
/*
100
-213
q21
-
-1
214
2fd1
*/

