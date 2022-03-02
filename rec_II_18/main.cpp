#include <iostream>

using namespace std;

int f(int* mass, int i, int n) {

    if (i < n-1)
        return max(mass[i], f(mass, i + 1, n));
    else
        return mass[i];


}

int main() {

    int n;
    cout<<"Vvedite razmer massiva: ";
    cin >> n;
    int* mass = new int[n];
    cout<<"Vvedite elementi massiva: ";
    for (int i = 0; i < n; i++)
        cin >> mass[i];

    cout << "Naibolshiy element: "<<f(mass, 0, n)<<endl;

}

/*
 Vvedite razmer massiva: 1
 Vvedite elementi massiva: 1
 Naibolshiy element: 1
 Vvedite razmer massiva: 5
 Vvedite elementi massiva: 1 2 3 4 5
 Naibolshiy element: 5
 Vvedite razmer massiva: 6
 Vvedite elementi massiva: 6 1 2 8 0 3
 Naibolshiy element: 8
 */
