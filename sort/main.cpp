#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");

class student {
public:
    string a, b, c, d;
    int e, f, g, h, i;
    void inputc(string sRow) {
        stringstream sio(sRow);
        sio >> a >> b >> c >> d >> e >> f >> g >> h >> i;

    }
    double avrg() {

        return (e + f + g + h + i) / 5.;

    }
    void outc() {
        out << a << " " << b << " " << c << " " << d << " " << e << " " << f << " " << g << " " << h << " " << i << endl;
    }
};

bool isLower(student x, student y)
{
        return x.a > y.a;



}

template <typename T>
void selectionSort(T* a, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (isLower(a[j], a[i]))
                swap(a[i], a[j]);
}

template <typename T>
void insertionSort(T* a, int n)
{
    for (int i = 1; i < n; i++)
        for (int j = i; j > 0 && isLower(a[j], a[j - 1]); j--)
            swap(a[j - 1], a[j]);
}

template <typename T>
void bubbleSort(T* a, int n) {
    T temp;
    for (int i = 0; i < n- 1; i++) {
        for (int j = 0; j < n- i - 1; j++) {
            if (isLower(a[j], a[j + 1])) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}





void pr1nt(student* a, int n) {
    for (int i = 0; i < n; i++) {
        a[i].outc();
    }
   out << "######################" << endl;
}

int main()
{
    int numb;
    in >> numb;
    string sRow;
    student st;
    student* m1 = new student[1000];
    student* m2 = new student[1000];
    student* m3 = new student[1000];
    int i = 0;
    in.get();
    while (getline(in, sRow)) 
    {
        cout << i;
        st.inputc(sRow);
       
        m1[i] = st;
        m2[i] = st;
        m3[i] = st;
        i++;
    }
    cout << i;
  

    insertionSort(m1, i );
    selectionSort(m2, i );
    bubbleSort(m3, i );

    pr1nt(m1, i );
    pr1nt(m2, i );
    pr1nt(m3, i );
}

//131
//mescheryakov 0 olegovich 1982 2 2 4 3 3
//mescheryakov 1 olegovich 1982 2 2 4 3 3
//mescheryakov 2 olegovich 1982 2 2 4 3 3
//ivanov alexander sergeevich 1997 5 4 2 5 5
//udavydov stas alexeevich 1990 2 2 3 5 5
//mescheryakov 3 olegovich 1982 2 2 4 3 3
//mescheryakov 4 olegovich 1982 2 2 4 3 3
//
//
//
//
//udavydov stas alexeevich 1990 2 2 3 5 5
//mescheryakov 0 olegovich 1982 2 2 4 3 3
//mescheryakov 1 olegovich 1982 2 2 4 3 3
//mescheryakov 2 olegovich 1982 2 2 4 3 3
//mescheryakov 3 olegovich 1982 2 2 4 3 3
//mescheryakov 4 olegovich 1982 2 2 4 3 3
//ivanov alexander sergeevich 1997 5 4 2 5 5
//######################
//udavydov stas alexeevich 1990 2 2 3 5 5
//mescheryakov 1 olegovich 1982 2 2 4 3 3
//mescheryakov 2 olegovich 1982 2 2 4 3 3
//mescheryakov 0 olegovich 1982 2 2 4 3 3
//mescheryakov 3 olegovich 1982 2 2 4 3 3
//mescheryakov 4 olegovich 1982 2 2 4 3 3
//ivanov alexander sergeevich 1997 5 4 2 5 5
//######################
//ivanov alexander sergeevich 1997 5 4 2 5 5
//mescheryakov 0 olegovich 1982 2 2 4 3 3
//mescheryakov 1 olegovich 1982 2 2 4 3 3
//mescheryakov 2 olegovich 1982 2 2 4 3 3
//mescheryakov 3 olegovich 1982 2 2 4 3 3
//mescheryakov 4 olegovich 1982 2 2 4 3 3
//udavydov stas alexeevich 1990 2 2 3 5 5
//######################
