#include <iostream>
#include <vector>
using namespace std;

template <typename type>
void print(vector <type>& a, int n) {
    for (int i = 0; i < n; i++)
            cout << a[i] << '\t';

    cout<<endl;
}
template <typename type>
void print(vector <type>& a,int k, int n) {
    for (int i = k; i <= n; i++)
            cout << a[i] << '\t';

    cout<<endl;
}
template <typename type>
int findpivot(vector <type>& a, int i, int j) {
    type firstkey = a[i];
    for (int k = i + 1; k <= j; k++)
        if (a[k] > firstkey)
            return k;
        else if (a[k] < firstkey)
            return i;
    return -1;
}
template <typename type>
int partition(vector <type>& a, int i, int j, int pivot) {
    int l = i;
    int r = j;
    while (l <= r) {
        while (a[l] < pivot)
            l++;
        while (a[r] >= pivot)
            r--;
        if (l < r) {
            swap(a[l], a[r]);

        }

    }
//    cout<<"//BEGIN"<<endl;
//    print(a,i, l-1);
//    print(a, l, j);
        return l;
}
template <typename type>
void quicksort(vector <type>& a, int i, int j) {
    int pivotindex = findpivot(a,i, j);
    if (pivotindex != -1) {
        type pivot = a[pivotindex];
        int k = partition(a,i, j, pivot);
        /*
        cout <<"(" << i << "," << j-1 << ") (" << k << "," << j << ")" << endl;
        cout << k << endl;
        cout<<"//END"<<endl;
*/
        quicksort(a,i, k - 1);

        quicksort(a,k, j);
    }
}


#include<iostream>
template <typename type>
void pushdown(vector <type> &a, int first, int last)
/* элементы a[first]…a[last] составляют частично упорядоченное дерево за исключением, возможно a[first] и сыновей.
   pushdown восстанавливает частично упорядоченное дерево */
{
    int r = first;
    while (r <= last / 2 && last>0)
    {//Если один сын
        if (last == 2 * r)
        {   //проверяем, не нарушена ли упорядоченность по отношению к нему
            //если нарушена, меняем местами
            if (a[r] <a[2 * r]) std::swap(a[r], a[2 * r]);
            r = last;
        }
        //если два сына, проверяем, если кто-то из них меньше родителя, меняем его с
            //родителем местами и переходим к этому сыну
        else if (a[r] <a[2 * r] && a[2 * r] >= a[2 * r + 1])
        {
            std::swap(a[r], a[2 * r]);
            r = 2 * r;
        }
        else if (a[r] < a[2 * r + 1] && a[2 * r + 1] >a[2 * r])
        {
            std::swap(a[r], a[2 * r + 1]);
            r = 2 * r + 1;
        }
        else
            r = last;
    }
}
template <typename type>
void heapSort(vector <type> &a, int n)
//сортирует элементы массива в убывающем порядке
{
    //создание частично упорядоченного дерева
    for (int i = (n-1) / 2; i >= 0; i--) //1
        pushdown(a, i, n-1);      //2
    for (int i = n-1; i >= 1; i--)   //3
    {
        //меняем местами первый – минимальный и последний текущий
        std::swap(a[0], a[i]);      //4
        //исключаем из рассмотрения последний текущий и восстанавливаем частично
        //упорядоченное дерево
        pushdown(a, 0, i - 1);
        //5
       
    }
}





int main() {
    vector<int> m;
    
    
        int n;
        cin >> n;
        vector < vector <int> > a(n, vector <int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }

        for (int i = 0; i <n-1; i++) {
            int c = i;
            int d = 0;

            while (c >=0) {
                m.push_back(a[c][d]);
                c--;
                d++;
            }
//            quicksort(m, 0, m.size()-1);
            heapSort(m, m.size());
            
            c = i;
            d = 0;
            int j = 0;
            while (c >=0) {
                a[d][c] = m[j];
                j++;

                c--;
                d++;

            }
          

            m.clear();
        }


        for (int i = n-1; i >=1; i--) {
            int c = i;
     
            int d = n-1;
            while (c <n) {
                m.push_back(a[c][d]);
                c++;
                d--;
                
            }
            //            quicksort(m, 0, m.size()-1);
            heapSort(m, m.size());
            c = i;
            d = n-1;
            int j = 0;
            while (c <n) {
                a[c][d] = m[j];
                j++;

                c++;
                d--;

            }
         

            m.clear();
        }



        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << a[i][j] << " ";
            }
           cout << endl;
        }


}
/*
 5
 745 -996 876 -745 246
 -964 -217 -168 418 866
 -172 808 -254 -452 -222
 -265 -584 779 -478 77
 -247 -319 -703 -200 540
 
 745 -996 -217 -745 246
 -964 -172 -265 418 -452
 876 -168 -254 -319 -703
 808 -584 779 -478 -200
 -247 866 -222 77 540
 */
