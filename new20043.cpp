#include<iostream>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;
int main()
{
    int n,p,w,a,s;
    double sum =0;
    cin >> n >> w >> p;
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i = 1; i<=n;i++)
    {
        cin >> a;
        q.push(a);
    }
    while(q.size()>1)
    {
        s = 0;
        s += q.top();
        q.pop();
        s += q.top();
        q.pop();
        sum += s;
        q.push(s);
    }
    int out=0;
    out = ceil(sum * p /100);
    cout << out;
    system("pause");
    return 0;
}