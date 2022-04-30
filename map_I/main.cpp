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


