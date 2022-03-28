#include<iostream>
#include<deque>
using namespace std;
#define inf 10000000

struct node{
    node* next =NULL;
    int value;
    int weight;
    node(int v=0,int w=0, node *n=NULL){value=v;weight=w;next=n;}
};

int main()
{
    int n,m;
    cin >> n >> m;
    node* list = new node[n+1];
    int x,y,z;
    for(int i=1;i<=m;i++)
    {
        cin >> x >> y >> z;
        list[x].next=new node(y,z,list[x].next);
    }
    int *dis = new int[n+1];
    int *num = new int[n+1];
    int *isin = new int[n+1];
    int *isout = new int[n+1];
    for(int i=1;i<=n;i++)
    {
        dis[i]=inf;
        num[i]=0;
        isin[i]=0;
        isout[i]=0;
    }
    deque<int> q;
    for(int i=1;i<=n;i++)
    {
        if(isout[i]==0)
        {
            q.push_front(i);
            dis[i] = 0;
            num[i] = 1;
            while(!q.empty())
            {
                int s = q.front();
                q.pop_front();
                node * ni = list[s].next;
                isout[s]=1;
                isin[s]=0;
                while(ni!=NULL)
                {
                    isout[ni->value]=1;
                    if(dis[s]+ni->weight<dis[ni->value])
                    {   
                        dis[ni->value]=dis[s]+ni->weight;
                        if(isin[ni->value]==0)
                        {
                            num[ni->value]++;
                            q.push_back(ni->value);
                        }
                        if(num[ni->value]>=n+100)
                        {
                            cout << "Yes";
                            system("pause");
                            return 0;
                        }
                        isin[ni->value]=1;
                    }
                    ni=ni->next;
                }
            }
        }
    }
    cout << "No";
    system("pause");
    return 0;
}