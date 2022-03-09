#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream in("input.txt");


class Persona
{
protected:
    string date;
public:
    
    public:
    Persona(): date(""){};
    Persona(string x): date(x){};
    virtual void inputc()=0;
    virtual void Show()=0;
    int  Age(){
        string month =date.substr(date.find('.')+1,date.find('.'));
        string day =date.substr(0,date.find('.'));
        string year =date.substr(date.rfind('.')+1);
        
        
        if (month >"03" || (month =="03" && day >= "06")){
            return 2021-stoi(year);
    }
        else{
            return 2021 +1 - stoi(year);
        }

    }

};

class Enrolee: public Persona
{
protected:
    string surname;
    string fac;
public:
    Enrolee():Persona(), fac(""), surname(""){
        
    }
    Enrolee(string x, string y, string z):Persona(x), fac(y), surname(z){
        
    }
    void inputc(){
        in>>date>>surname>>fac;
       
       }
    void Show(){
        cout<<date<<" "<<surname<<" "<<fac<<endl;
        
    }
    
    
};

class Student: public Enrolee
{
protected:
    int course;
public:
    Student():Enrolee(), course(0){
    }
    Student(string x, string y, string z, int a): Enrolee(x,y,z), course(a){
    }
    void inputc(){
        in>>date>>surname>>fac>>course;
       }
    void Show(){
        cout<<date<<" "<<surname<<" "<<fac<<" "<<course<<endl;
    }
};


class Teacher: public Enrolee
{
protected:
    string post;
    int experience;
public:
    Teacher():Enrolee(), post(""), experience(0){
    }
    Teacher (string x, string y, string z, string a, int b): Enrolee(x,y,z),  post(a), experience(b){
    }
    void inputc(){
        in>>date>>surname>>fac>>post>>experience;
       }
    void Show(){
        cout<<date<<" "<<surname<<" "<<fac<<" "<<post<<" "<<experience<<endl;
    }
};

    
int main() {
    Persona *persons[100];
    for(int i=0; i<6;i++){
        if (i<3){
            persons[i]=new Enrolee();
        }
        else{
            persons[i]=new Teacher();
        }
    }
    int i=0;
    while (i<6) {
        persons[i]->inputc();
        persons[i]->Show();
        cout<<persons[i]->Age()<<endl;
        i++;
    }
    in.close();
    return 0;
}
