#include <iostream>
#include <string>

using namespace std;

void inp(string &s,long i) {
    if (i<s.length()){
        if (s[s.find("a",i)]=='a'){
            cout<<s[s.find("a",i)]<<endl;
        s.insert(s.find("a",i)+1,"b");
            inp(s,s.find("a",i)+1);
        }
        else
            inp(s,i+1);
        }
    else{
        return;
    }

}

int main() {
    string s;
    cout<<"Vvedite stroku: ";
    getline(cin, s);
    inp(s,0);
    cout<<"Novaya stroka: ";
    cout<<s<<endl;
}
/*
 Vvedite stroku: aaaa
 Novaya stroka: abababab
 Vvedite stroku: kkk
 Novaya stroka: kkk
 */
