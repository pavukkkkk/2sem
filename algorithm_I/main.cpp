#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#include <iostream>
#include <numeric>

class point {
public:

    int x;
    int y;
    point(int x, int y) : x(x), y(y) {}
    point &operator=(const point & b){
        x=b.x;
        y=b.y;
        return *this;
    }

};

bool uslovie(point a) {
    return (a.x > 0);



}

bool uslovie2(point a) {
    return (max(a.x,a.y)%min(a.x,a.y)==0);



}
bool predicat(point a, point b){
    return (a.x+a.y<b.x+b.y);
}

int summ(int a, point b){
    return (a+b.x);
}
    int main() {


    vector<point> v;
        vector<point> v1;

    int x, y;
    int n,k=0;
    cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> x >> y;
            point a(x, y);
            v.push_back(a);
            v1.push_back(a);
        }
        stable_sort(v1.begin(), v1.end(), predicat);
       point b = *find_if(v.begin(), v.end(), uslovie2);
        cout<<"pervaya tochka s kratnimi koordinatami: "<<b.x<<" "<<b.y<<endl;
        k=accumulate(v.begin(),v.end(),0,summ);
        v.erase(remove_if(v.begin(), v.end(), uslovie),v.end());
        cout<<"summa: "<<k<<endl;
        cout<<"noviymassiv: ";
        for (auto i : v) {

            cout << i.x << " " << i.y << endl;

        }
        cout<<"otsortirovanniy massiv: "<<endl;
        for (auto i : v1) {

            cout << i.x << " " << i.y << endl;

        }

        
    }
/*
 4
 3 4
 2 -3
 3 6
 -3 1
 pervaya tochka s kratnimi koordinatami: 3 6
 summa: 5
 noviymassiv: -3 1
 otsortirovanniy massiv:
 -3 1
 2 -3
 3 4
 3 6
 
 4
 -5 5
 3 -3
 4 -10
 -7 1
 pervaya tochka s kratnimi koordinatami: -5 5
 summa: -5
 noviymassiv: -5 5
 -7 1
 otsortirovanniy massiv:
 4 -10
 -7 1
 -5 5
 3 -3
 
 */
