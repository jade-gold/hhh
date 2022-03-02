#include<iostream>
#include<complex>
#include<cmath>
using namespace std;

#define cp complex<double>
#define pi 3.14159265358979323846

void fft(cp *a, int n, int inv){
    int bit=0;//bit记录了n的二次幂
    while((1<<bit)<n) bit++;
    int *rev= new int[n];
    for(int i=0;i<n;i++)
    {
        rev[i]=0;
        rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
        if(i<rev[i]){
            cp tmp=a[i];
            a[i]=a[rev[i]];
            a[rev[i]]=tmp;
        }//这个让序列只交换一次
    }
    for(int mid=1;mid<n;mid*=2)
    {
        cp temp(cos(pi/mid),inv*sin(pi/mid));//mid次单位根
        for(int i=0;i<n;i+=mid*2)
        {
            cp omega(1,0);//创建变量用来决定A2前面系数
            for(int j=0;j<mid;j++)
            {
                cp x=a[i+j],y=omega*a[i+j+mid];
                a[i+j]=x+y;
                a[i+j+mid]=x-y;
                omega=omega*temp;
            }
        }
    }
}

int main()
{
    int n,m,k1,k2;
    cin >> n >> m;
    for (int i=1;;i=i*2)
        if(i>=n+1)
        {
            k1=i;
            break;
        }
    for (int i=1;;i=i*2)
        if(i>=m+1)
        {
            k2=i;
            break;
        }
    if(k1 < k2)
        k1=k2;
    cp *a = new cp[2*k1];
    cp *b = new cp[2*k1];
    int *c = new int[2*k1];
    for(int i=0;i<2*k1;i++)
        a[i]=b[i]=c[i]=0;
    for(int i=0;i<n+1;i++)
        cin >> a[i];
    for(int i=0;i<m+1;i++)
        cin >> b[i];
    fft(a,2*k1,1);
    fft(b,2*k1,1);
    for(int i=0;i<2*k1;i++)
        a[i]*=b[i];
    fft(a,2*k1,-1);
    for(int i=0;i<m+n;i++)
    {
        c[i]=(int)(a[i].real()/(2*k1)+0.5);
        cout << c[i]<< " ";
    }   
    cout << (int)(a[m+n].real()/(2*k1)+0.5);
    system("pause"); 
    return 0;
}