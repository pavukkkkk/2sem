#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

class stud {
public:
    string lastname, firstname, patronymic;
    int birth;
    double a[5];
    stud(){
    }
    stud(string lastname, string firstname, string patronymic, int birth, int a1, int a2, int a3, int a4, int a5) {
        this->lastname = lastname;
        this->firstname = firstname;
        this->patronymic = patronymic;
        this->birth = birth;
        this->a[0] = a1; this->a[1] = a2; this->a[2] = a3; this->a[3] = a4; this->a[4] = a5;
    }
    void input(){
        cin>>lastname>>firstname>>patronymic>>birth>>a[0]>>a[1]>>a[2]>>a[3]>>a[4];
    }
    void print() {
        cout << lastname << ' ' << firstname << ' ' << patronymic << ' ' << birth << ' ' << a[0] << ' ' << a[1] << ' ' << a[2] << ' ' << a[3] << ' ' << a[4] << endl;
    }
   
};



bool isLower(stud a, stud b) {
    return make_tuple(a.lastname, a.firstname, a.patronymic) < make_tuple(b.lastname, b.firstname, b.patronymic);
}

int main() {
    stud a;
    vector<stud> vec1;
    vector<stud> vec2;

    
    int n;
    cin>>n;
    for (int i=0; i<n;i++){
        a.input();
        vec1.push_back(a);
        vec2.push_back(a);
    }
    cout<<endl;
    sort(vec1.begin(),vec1.end(), isLower);
    stable_sort(vec2.begin(),vec2.end(), isLower);
    for(auto i: vec1){
            
            i.print();
        
        }
    cout<<endl;
    for(auto i: vec2){
            
           i.print();
        
        }
    cout<<endl;
}
/*
 9
 ivanov dmitry alexeevich 1971 1 3 1 1 1
 matov max vladimirovich 1998 2 5 4 2 2
 mescheryakov alexander vladimirovich 1973 5 5 5 5 4
 ivanov dmitry alexeevich 1971 1 3 4 5 3
 kreys dmitry olegovich 1994 3 3 2 5 4
 ivanov sergey igorevich 1990 3 5 5 2 5
 mescheryakov alexander vladimirovich 1973 5 4 5 5 4
 mescheryakov alexander vladimirovich 1973 5 4 2 2 2
 ivanov dmitry alexeevich 1971 1 5 5 5 5

 ivanov dmitry alexeevich 1971 1 3 1 1 1
 ivanov dmitry alexeevich 1971 1 5 5 5 5
 ivanov dmitry alexeevich 1971 1 3 4 5 3
 ivanov sergey igorevich 1990 3 5 5 2 5
 kreys dmitry olegovich 1994 3 3 2 5 4
 matov max vladimirovich 1998 2 5 4 2 2
 mescheryakov alexander vladimirovich 1973 5 5 5 5 4
 mescheryakov alexander vladimirovich 1973 5 4 5 5 4
 mescheryakov alexander vladimirovich 1973 5 4 2 2 2

 ivanov dmitry alexeevich 1971 1 3 1 1 1
 ivanov dmitry alexeevich 1971 1 3 4 5 3
 ivanov dmitry alexeevich 1971 1 5 5 5 5
 ivanov sergey igorevich 1990 3 5 5 2 5
 kreys dmitry olegovich 1994 3 3 2 5 4
 matov max vladimirovich 1998 2 5 4 2 2
 mescheryakov alexander vladimirovich 1973 5 5 5 5 4
 mescheryakov alexander vladimirovich 1973 5 4 5 5 4
 mescheryakov alexander vladimirovich 1973 5 4 2 2 2

 Program ended with exit code: 0
 */
