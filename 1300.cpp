#include <iostream>
#include <cstdlib>
using namespace std;

const int N = 4e7 + 1;
int n, k;
int a[N];
int find_k_th(int num, int k, int a[]);
void read_input_data() {
    int m;
    cin >> n >> k >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    unsigned int z = a[m];
    for (int i = m + 1; i <= n; i++) {
        z ^= z << 13;
        z ^= z >> 17;
        z ^= z << 5;
        a[i] = z & 0x7fffffff;
    }
}


int pick_good(int num)
{
    return a[rand() % num+1];
}

int find_k_th(int num, int k)
{
    int good_pivot = pick_good(num);
    int left=0,mid=0,right=0;
    int *l = new int[num];
    int *r = new int[num];
    int *m = new int[num];
    for(int i=1;i<=num;i++)
        if(a[i]<good_pivot)
            l[left++] = a[i];
        else if(a[i]==good_pivot)
            m[mid++] = a[i];
        else
            r[right++] = a[i];
    if(k <= left)
    {
        for(int i=1;i<=left;i++)
            a[i]=l[i-1];
        delete [] l;
        delete [] m;
        delete [] r;
        return find_k_th(left,k);
    }
    else if(k > left && k <= left+mid)
        return good_pivot;
    else
    {
        for(int i=1;i<=right;i++)
            a[i]=r[i-1];
        delete [] l;
        delete [] m;
        delete [] r;
        return find_k_th(right,k-left-mid);
    }
}

int main()
{
    read_input_data();
    int x = find_k_th(n,k);
    cout << x;
    system("pause");
    return 0;
}