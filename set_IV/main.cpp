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

