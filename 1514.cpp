#include<iostream>
#include<deque>
using namespace std;

struct node{
    node* next =NULL;
    int value;
    node(int v=0, node *n=NULL){value=v;next=n;}
};

int main()
{
    int n,m;
    cin >> n >> m;
    node* list = new node[n+1];
    node* inverse = new node[n+1];
    int s,t;
    for(int i=1;i<=m;i++)
    {
        cin >> s >>t ;
        if(s!=t)
        
        {
        list[s].next=new node(t,list[s].next);
        inverse[t].next = new node(s,inverse[t].next);
        }

    }
    int *isin = new int[n+1];
    int *isout = new int[n+1];
    int *scc = new int[n+1]; 
    int *scale = new int[n+1];
    int num=0;
    for(int i=1;i<=n;i++)
    {
        isout[i]=0;
        isin[i]=0;
        scc[i]=0;

    }
    deque<int> q,p;
    for(int i=1;i<=n;i++)
    {
        if(isout[i]==0)
        {
            num++;
            isin[i]=1;
            scale[num]=1;
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
                node * ni = list[s].next;
                while (ni!=NULL)
                {
                    if(isin[ni->value]==1 && isout[ni->value]==0)
                    {
                        scc[ni->value]=num;
                        scale[num]++;
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
    int number=0;
    int *out = new int[num+1];
    for(int i=1;i<=num;i++)
    {
        out[i]=0;
    }

    for(int i=1;i<=n;i++)
    {
        if(out[scc[i]]==0){
            node* ni = list[i].next;
            while (ni!=NULL)
            {
                if(scc[ni->value]!=scc[i])
                {
                    number=number+scale[scc[i]];
                    out[scc[i]]=1;
                    break;
                }
                ni=ni->next;
            }
        }
    }
    cout << number;
    system("pause");
    return 0;
}