#include<iostream>
#include<deque>
#include<queue>
#include<vector>
using namespace std;
struct node{
    node* next =NULL;
    int value;
    int a,b;
    node(int v=0,int aa=0,int bb=0, node *n=NULL){value=v;a=aa;b=bb;next=n;}
    friend bool operator >(const node& a,const node& b)
    {
        if(a.a > b.a)
            return true;
        else 
            return false;
    }
};
int n,m,kkk=0;
void dfs(node* list, node* pre, node* inverse, int* isout, int i, int * father)
{
    isout[i]=1;
    node * nn = list[i].next;
    while(nn !=NULL)
    {
        if(isout[nn->value]==0)
        {
            father[nn->value]=i;
            pre[i].next=new node(nn->value,0,0,pre[i].next);
            inverse[nn->value].next=new node(i,0,0,inverse[nn->value].next);
            kkk++;
            dfs(list,pre,inverse,isout,nn->value,father);
        }
        else if(father[i]!=nn->value)
        {
            pre[nn->value].next=new node(i,0,0,pre[nn->value].next);
            inverse[i].next=new node(nn->value,0,0,inverse[i].next);
            kkk++;
        }
        nn=nn->next;
    }
    return ;
}

void SCCs(node* pre, node * inverse, int* scc, int* isout, int* isin)
{
    deque<int> q,p;
    int num=0;
    for(int i=1;i<=n;i++)
    {
        if(isout[i]==0)
        {
            num++;
            isin[i]=1;
            scc[i]=num;
            isout[i]=1;
            q.push_front(i);
            p.push_front(i);
            while(!q.empty())
            {
                int s=q.front();
                q.pop_front();
                node * ni = inverse[s].next;
                while (ni!=NULL)
                {
                    if(isout[ni->value]==0 && isin[ni->value]==0)
                    {
                        isin[ni->value]=1;
                        q.push_front(ni->value);
                        p.push_back(ni->value);
                    }
                    ni=ni->next;
                } 
            }
            q.push_front(i);
            while (!q.empty())
            {
                int s = q.front();
                q.pop_front();
                node * ni = pre[s].next;
                while (ni!=NULL)
                {
                    if(isin[ni->value]==1 && isout[ni->value]==0)
                    {
                        scc[ni->value]=num;
                        q.push_front(ni->value);
                        isout[ni->value]=1;
                    }
                    ni=ni->next;
                }
            }
            while(!p.empty())
            {
                int s = p.front();
                p.pop_front();
                isin[s]=0;
            }
        }
    }
}

int main()
{   
    int s,t,a,b;
    cin >> n >> m;
    node* list = new node[n+1];
    for(int i=1;i<=m;i++)
    {
        cin >> s >> t >> a >> b;
        list[s].next=new node(t,a,b,list[s].next);
        list[t].next=new node(s,a,b,list[t].next);
    }
    int * isout = new int[n+1];
    int * scc = new int[n+1];
    int *isin = new int[n+1];
    int *father = new int[n+1];
    node* pre = new node[n+1];
    node* inverse = new node[n+1];
    for(int i=1;i<=n;i++)
        {isout[i]=0;scc[i]=0;isin[i]=0;father[i]=0;}
    dfs(list,pre,inverse,isout,1,father);
    
    for(int i=1;i<=n;i++)
        {isout[i]=0;scc[i]=0;isin[i]=0;}
    SCCs(pre,inverse,scc,isout, isin);
    
    delete[] pre;
    delete[] inverse;
    for(int i=1;i<=n;i++)
    {
        node *nn = list[i].next;
        while(nn != NULL)
        {
            if(scc[i]!=scc[nn->value])
                nn->a=nn->b;
            nn=nn->next;
        }
    }
    int *vis = new int[n+1];
    for(int i=1;i<=n;i++)
        vis[i]=0;
    priority_queue<node, vector<node>, greater<node>> pri_q;
    long long int sum=0;
    pri_q.push(node(s,0));
    while(!pri_q.empty())
    {
        s = pri_q.top().value;
        t=pri_q.top().a;
        pri_q.pop(); 
        if(vis[s]==0)
        {
            sum = sum + t;
            
            vis[s]=1;
            node* nn = list[s].next;
            while(nn!=NULL)
            {
                if(vis[nn->value]==0)
                    pri_q.push(node(nn->value,nn->a));
                nn=nn->next;
            } 
        }     

    }
    cout << sum;
    cout << kkk;
    system("pause");
    return 0;
}