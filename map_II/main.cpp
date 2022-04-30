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
#include <cmath>
#include <sstream>
using namespace std;
class Catalog;


class AllAboutProducer{
    vector<string> movies;
    vector<string> info;
    friend Catalog;
};


class Catalog{
    std::map<string,AllAboutProducer> ctlg;
    vector<string>::iterator iter;
    
public:
    void addProducer(string a){
        ctlg[a];
    }
    void addMovie(string a, string b){
        if (ctlg.find(a) !=ctlg.end()){
            ctlg[a].movies.push_back(b);
            
        }
        else{
            cout<<"Rejissera net v spiske\n";
        }
        
    }
    void changeProducer(string a, string b){
        if (ctlg.find(a) !=ctlg.end()){
        AllAboutProducer tmp = ctlg[a];
        ctlg.erase(a);
        ctlg[b]=tmp;
        }
        else{
            cout<<"Rejissera net v spiske\n";
        }
    }
    void delProducer(string a){
        if (ctlg.find(a) !=ctlg.end()){
        ctlg.erase(a);
            
            }
            else{
                cout<<"Rejissera net v spiske\n";
            }
    }
    void changeMovie(string a, string b, string c){
        if (ctlg.find(a) !=ctlg.end()){
        for (string &x: ctlg[a].movies){
            if (x==b){
                x=c;
                return;
            }
        }
        cout<<"Filma net v spiske\n";
        }
        else{
            cout<<"Rejissera net v spiske\n";
        }
    }
    void dellMovie(string a,string b){
        if (ctlg.find(a) !=ctlg.end()){
        iter =find(ctlg[a].movies.begin(), ctlg[a].movies.end(), b);
        if (iter!=ctlg[a].movies.end()){
            ctlg[a].movies.erase(iter);
        }
        else{
            cout<<"Filma net v spiske\n";
        }
    }
    else{
        cout<<"Rejissera net v spiske\n";
    }
    }
    void addInfo(string a, string b){
        if (ctlg.find(a) !=ctlg.end()){
            ctlg[a].info.push_back(b);
            
        }
        else{
            cout<<"Rejissera net v spiske\n";
        }
        
    }
    void show_if_word(string a) {
        for (auto i : ctlg) {
            for (auto j: i.second.movies){
                if (j.find(a)<j.length()){
                    if ((j.find(a)==0 || j[j.find(a)-1] ==' ')&& (j.find(a)+a.length()==j.length() || j[j.find(a)+a.length()] ==' ')){
                        cout<<j<<endl;
                    }
                }
            }
        }
    }
    void show(string a){
        if (ctlg.find(a) !=ctlg.end()){
            cout<<a<<": ";
            for (string x: ctlg[a].movies){
                cout<<x<<"|";
            }
    }
        else{
            cout<<"Rejissera net v spiske\n";
        }
    }
    void show(){
        for (auto i : ctlg) {
            cout<<i.first;
            cout<<"[";
            for (auto j: i.second.info){
                cout<<j<<"; ";
            }
            cout<<"]: ";
            for (auto j: i.second.movies){
                cout<<j<<"; ";
            }
            cout<<endl;
    }
    }
};

int main() {

    ifstream in("input.txt");
    setlocale(LC_ALL, "Russian");
    Catalog catalog;
    string  s, s1,s2,s3;
    while (getline(in, s)) {
        if (s!="-"){
        stringstream sio(s);
        getline(sio, s1,'|');
        getline(sio, s2,'|');
        catalog.addProducer(s1);
        catalog.addInfo(s1, s2);
        while (getline(sio, s2,'|'))
        {
            catalog.addMovie(s1, s2);
                    }
        
                }
    }
        
    
   
        int n;

    do {
        catalog.show();
        cout << "1) добавить режиссера" << endl;
        cout << "2) удалить режиссера" << endl;
        cout << "3) добавить фильм" << endl;
        cout << "4) удалить фильм" << endl;
        cout << "5) изменить навзание фильма" << endl;
        cout << "6) изменить имя режиссера" << endl;
        cout << "7) найти фильмы, названия которых содержат зажанное слово" << endl;
        cout << "8) добавить информацию о режиссере" << endl;
        cout << "9) выход" << endl;

        std::cin >> n;
        cin.get();
        switch (n) {
        case 1: {
            getline(cin, s);
            catalog.addProducer(s);
            break;
            }
        case 2: {
            getline(cin, s);
            catalog.delProducer(s);
            break;
            }
        case 3: {
            getline(cin, s1);
            getline(cin, s2);
            catalog.addMovie(s1, s2);
            break;
            }
        case 4: {
            getline(cin, s1);
            getline(cin, s2);
            catalog.dellMovie(s1, s2);
            break;
            }
        case 5: {
            getline(cin, s1);
            getline(cin, s2);
            getline(cin, s3);
            catalog.changeMovie(s1, s2,s3);
            break;
            }
        case 6: {
            getline(cin, s1);
            getline(cin, s2);
            catalog.changeProducer(s1, s2);
            break;
            }
        case 7: {
            getline(cin, s1);
            catalog.show_if_word(s1);
            break;
            }
        case 8: {
            getline(cin, s1);
            getline(cin, s2);
            catalog.addInfo(s1, s2);
            break;
            }
        
        case 9: {
            return 0;
            }
        }

    } while (true);
    }

/*sasha jmish|http://sasha.com|killbill|vanya|chemodan
kventin tartila|ssilka|kriminalnoe chego
nikita mihalkov|drugaya ssilka|utomlennie solncem|bolshe filmov ya ne znayu
-
*/

