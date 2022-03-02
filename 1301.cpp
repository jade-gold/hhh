#include <iostream>
using namespace std;

void bubble(int a[],int b[],int left, int right)
{
    if(left+1==right)
        return;
    bubble(a,b,left,(left+right)/2);
    bubble(a,b,(right+left)/2,right);
    int r=(left+right)/2,l=left,point=0;
    int *aa = new int[right-left];
    int *bb = new int[right-left];
    while(r<right && l<(right+left)/2)
    {
        if(a[r]>a[l])
        {
            aa[point]=a[l];
            bb[point]=b[l]+r-(left+right)/2;
            l++;
        }
        else{
            aa[point]=a[r];
            bb[point]=b[r]+(left+right)/2-l;
            r++;
        }
        point++;
    }
    if(l==(right+left)/2)
        for(int i=r;i<right;i++)
        {
            aa[point]=a[i];
            bb[point]=b[i];
            point++;
            
        }
    else
        for(int i=l;i<(left+right)/2;i++)
        {
            aa[point]=a[i];
            bb[point]=b[i]+(right-left)/2;
            point++;
        }
    for(int i=left;i<right;i++)
    {
        a[i]=aa[i-left];
        b[i]=bb[i-left];
    }
}
int main()
{
    int n,num;
    cin >> n;
    for(int i=1;;i=i*2)
        if(i>=n)
        {
            num = i;
            break;
        }
    int *a = new int[num];
    int *b = new int[num]; //用于记录相应交换次数
    int max = -100000;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        if(a[i]>max)
            max = a[i];
        b[i]=0;
    }
    for(int i=n;i<num;i++)
    {
        a[i]=max+i;
        b[i]=0;
    }
    bubble(a,b,0,num);
    for(int i=0;i<n;i++)
        cout << b[i] << " ";
    system("pause");
    return 0;
} 