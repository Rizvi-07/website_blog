//Bellman Ford Algorithm for single source shortest path

#include<bits/stdc++.h>
#define MAX 10000

using namespace std;

struct node{
    int u, v, w;                            //starting & ending node & cost respectively
};

vector <node> V;
int u, v, w;
int n, m;
node temp;
int d[MAX];

void belmanford(int source)
{
    for(int i=0;i<=n;i++)               //Initially all distance are infinite
        d[i]=100000;

    d[source] = 0;

    for(int i=0; i<n-1; i++)                            //Takes n-1 iterations to determine the result
        for(int j=0; j<m; j++)
            if (d[V[j].u] + V[j].w < d[V[j].v])             //Relax (main update)
                d[V[j].v] = d[V[j].u] + V[j].w;



}
bool negative_cycle()                                   //Checking for any negative cycle
{
     for(int j=0; j<m; j++)                             //Looking for a relax in the nth iteration; if found, not possible
            if(d[V[j].u] + V[j].w < d[V[j].v])
                return true;
    return false;
}

int main()
{
        cout << "Enter the no. of vertex: ";
        cin >> n;

        cout << "Enter the no. of edges: ";
        cin >> m;

        for(int i=0; i<m; i++)
        {
            cin >> u >> v >> w;
            temp.u = u;
            temp.v = v;
            temp.w = w;
            V.push_back(temp);
        }

        belmanford(0);

        if(negative_cycle())
            cout << "Not Possible!" << endl;
        else
        {
            cout << endl << "Nodes with their respective shortest path:" << endl;
            for(int i=0; i<n; i++)
                cout << i << "\t\t" << d[i] <<endl;
        }
    return 0;
}
