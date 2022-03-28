#include<iostream>
#include<deque>
using namespace std;


struct node{
    node* next =NULL;
    int value;
    node(int v=0, node *n=NULL){value=v;next=n;}
};

int main(){
    int n,p1,p2;
    int a,b;
    cin >> n >> p1 >> p2;
    node * list = new node[n+1];
    int * in = new int[n+1];
    int * top = new int[n+1];
    for(int i=1;i<=n;i++)
    {
        in[i]=0;
        top[i]=0;
    }    
    for(int i=1;i<=p1;i++)
    {
        cin >> a >> b;
        list[a].next=new node(b,list[a].next);
        in[b] = in[b]+1;
    }
    int num = 0;
    deque<int> q;
    for(int i=1;i<=n;i++)
    {
        if(in[i]==0 && top[i]==0)
        {
            num++;
            top[i]=num;
            q.push_front(i);
            while(!q.empty())
            {
                int front = q.front();
                q.pop_front();
                node * n = list[front].next;
                while(n!=NULL)
                {
                    in[n->value]--;
                    if(in[n->value]==0)
                    {
                        num++;
                        top[n->value]=num;
                        q.push_back(n->value);
                    }
                    n=n->next;
                }
            }
        }
    }
    for(int i=1;i<=p2;i++)
    {
        cin >> a >>b;
        if(top[a]>top[b])
            cout << b << " " << a << endl;
        else
            cout << a << " " << b << endl;
    }
    system("pause");
    return 0;

}