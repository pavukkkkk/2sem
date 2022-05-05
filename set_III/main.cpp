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

ifstream in("input.txt");
ofstream out("output.txt");


int main() {
    set<char> v{ '.','!','?' };
    set<char> v1{ '.','!','?',',',':',';' };
    string s;
    char a;
    set<string> words1, words2, wordscurrent;
    while (in >> s) {
        for_each(s.begin(), s.end(), [](char& c) {
            c = ::tolower(c);
            });
        a = s[s.size() - 1];
        if (v1.find(a) != v1.end()) {
            s.replace(s.size() - 1, 1, "");
        }
        wordscurrent.insert(s);

        if (v.find(a) != v.end()) {
            if (a == '.') {
                for (auto x : wordscurrent)
                {
                    words1.insert(x);
                }
            }
            else {
                for (auto x : wordscurrent)
                {
                    words2.insert(x);
                }
            }
            wordscurrent.clear();
        }

    }
    std::vector<string> s_intersection;

    std::set_difference(words2.begin(), words2.end(),
        words1.begin(), words1.end(),
        std::back_inserter(s_intersection));
    for (auto x : s_intersection)
    {


        cout << x << " ";


    }
    in.close();
    out.close();
}

/*
 Hello, my name. Name? hello! Andrey Rublev? Serebro horosho, hleb? rublev.


 andrey
 hleb
 horosho
 serebro

 */
