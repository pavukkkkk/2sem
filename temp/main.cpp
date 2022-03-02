



#include <iostream>
#include <cmath>
using namespace std;


template <typename x> void print(x** m, int n, int k) {
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cout << m[i][j] << "\t";
        }
        cout << endl;
    }
}

template <typename x> x** inp(int n, int k){
    x** m = new x* [n];
    cout << "vvedite maricu: " << endl;
    for (int i = 0; i < n; i++) {
        m[i] = new x[k];
        for (int j = 0; j < k; j++) {
            cin >> m[i][j];
        }
    }
    return m;
        }
    
template <typename x> double f(x** m, int n, int k) {
    double s=0;
    int h=0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            if(m[i][j] <0){
                s+=m[i][j];
                h++;
            }
        }
    }
        if (h>0)
            return (abs(s)/h)*(-1);
        return 0;
    
}

int main(){
    int n,k;
    cout<<"Vvedite razmer matrici: ";
   cin>>n>>k;
    int **m= inp<int>(n,k);
    double **m2= inp<double>(n,k);
    print(m,n,k);
    print(m2,n,k);
    cout<<f(m,n,k)<<endl;
    cout<<f(m2,n,k)<<endl;
}

