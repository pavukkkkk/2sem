#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#include <iostream>
#include <numeric>


class melody{

 struct sound{
    int height;
    double length;
    sound(int a, int b): height(a), length(b){}
    };
public:


    bool predicat(sound a){
        return 3<a.height;
    }
   
    vector<sound> m;
    void push(int a, int b){
        sound s(a,b);
        m.push_back(s);
    }
    void change(int z){
    
        transform(m.begin(), m.end(),m.begin(), [z](sound& a) {if (a.height<z){a.length/=2;}else if (a.height>z){a.length*=2;}  return a;
        });
    }
        
    void print(){
    for (auto i : m) {

        cout << i.height << " " << i.length << endl;

    }
    }
};

int main() {
    melody m;
    int x, y;
    int n,r;
    cin >> n>>r;
        for (int i = 0; i < n; i++)
        {
            cin >> x >> y;
            
            m.push(x,y);
        }
    m.change(r);
    cout<<"new melody: "<<endl;
    m.print();
    return 0;
}
/*
 5 4
 3 3
 5 7
 4 7
 10 2
 1 1
 new melody:
 3 1.5
 5 14
 4 7
 10 4
 1 0.5
 */
