#include <iostream>
#include<deque>
using namespace std;

struct node{
    node* next =NULL;
    int value;
    node(int v=0, node *n=NULL){value=v;next=n;}
};

deque<int> q;


int main()
{
    int n,m,s,t;
    int u,v,w;
    cin >> n >> m >> s >> t;
    node* zero = new node[n+1];
    node* one =new node[n+1];
    int * a = new int[n+1];
    int * dis = new int[n+1];

    for(int i=1;i<=n;i++)
        {a[i]=1;dis[i]=0;}
    for(int i=1;i<=m;i++)
    {
        cin >> u >> v >> w;
        if(w==0)
        {
            zero[u].next=new node(v,zero[u].next);
            zero[v].next=new node(u,zero[v].next);
        }
        else{
            one[u].next=new node(v,one[u].next);
            one[v].next=new node(u,one[v].next);
        }
    }
    a[s]=0;
    q.push_front(s);
    while(true)
    {
        deque<int> qq = q;
        while(!qq.empty())
        {
            int s=qq.front();
            qq.pop_front();
            node* z = zero[s].next;
            while (z!=NULL)
            {
                if(a[z->value]==1){
                    q.push_front(z->value);
                    qq.push_front(z->value);
                    dis[z->value]=dis[s];}
                if(z->value==t)
                {
                    cout << dis[t];
                    system("pause");
                    return 0;
                }
                a[z->value]=0;
                z=z->next;
            }
        }
        qq = q;
        q.clear();
        while(!qq.empty())
        {
            int s=qq.front();
            qq.pop_front();
            node* o = one[s].next;
            while (o!=NULL)
            {
                if(a[o->value]==1){
                    q.push_front(o->value);
                    dis[o->value]=dis[s]+1;}
                if(o->value==t)
                {
                    cout << dis[t];
                    system("pause");
                    return 0;
                }
                a[o->value]=0;
                o=o->next;
            }
        }     
    }
    cout << dis[s];
    system("pause");
    return 0;
}