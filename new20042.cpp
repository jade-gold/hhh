#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define inf 1000000000

struct node{
    node* next =NULL;
    int value;
    int weight;
    node(int v=0,int w=0, node *n=NULL){value=v;weight=w;next=n;}
    bool operator <(const node& n)
    {
        if(weight < n.weight)
            return true;
        else 
            return false;
    }
    bool operator ==(const node& n)
    {
        if(weight == n.weight)
            return true;
        else 
            return false;
    }
    friend bool operator >(const node& a,const node& b)
    {
        if(a.weight > b.weight)
            return true;
        else 
            return false;
    }
};

int main()
{
    int n,m,s,t;
    cin >> n >> m >> s >> t;
    node * list = new node[n+1];
    int x,y,z;
    for(int i=1;i<=m;i++)
    {
        cin >> x >> y >> z;
        list[x].next=new node(y,z,list[x].next);
        list[y].next=new node(x,z,list[y].next);
    }
    int * dis = new int[n+1];
    int * isin = new int[n+1];
    int * vis = new int[n+1];
    for(int i=1;i<=n;i++)
        {dis[i]=inf;isin[i]=0;vis[i]=0;}
    priority_queue<node,vector<node>,greater<node>> q;
    q.push(node(s,0));
    dis[s]=0;
    
    while(!q.empty())
    {
        int f = q.top().value;
        int d = q.top().weight;
        vis[f]=1;
        if(f==t)
        {
            cout << d;
               system("pause"); 
         return 0;
        }
           
        q.pop();
        isin[f]=0;
        node* n = list[f].next;
        while(n!=NULL)
        {
            if(n->weight+d<dis[n->value])
            {
                dis[n->value]=d+n->weight;
                q.push(node(n->value,dis[n->value]));
            }
            n=n->next;
        }
    }
    cout << dis[t];
    system("pause");
    return 0;
}