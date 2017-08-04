//Dijkstra's Algorithm for single source shortest path

#include <bits/stdc++.h>
#define MAX 10000

using namespace std ;

void dijkstra(int source);

int v;
int adj[MAX][MAX];

int main ()
{
    int i, j, e, x, y, w;

    cout << "Enter the no. of vertex: ";
    cin >> v;

    cout << "Enter the no. of edge: ";
    cin >> e;

    cout << "Enter the connected edges: ";
    for(i=1; i<=e; i++)                                 //Creating adjacent matrix for bi-directional graph
    {

        cin >> x >> y >> w;
        adj[x][y] = w;
        adj[y][x] = w;

    }
    cout << endl;
    int source;
    cout << "Enter the source node: ";
    cin >> source;
    dijkstra(source);

    return 0;
}

void dijkstra(int source)
{
    priority_queue< pair<int,int>, vector< pair <int, int> >, greater <pair <int, int> > > pq;          //priority_queue decreases the time complexity
                                                                                                        //greater is an alternative for cmp function
    int distance[100];
    int u, i;

    for(i=1; i<=v; i++)                                     //Initial distance infinite for all vertex
        distance[i] = 10000;

    distance[source] = 0;

    pq.push(make_pair(distance[source], source));

    while(!pq.empty())
    {
        pair <int,int> node = pq.top();
        pq.pop();

        u = node.second;

        for(i=1; i<=v; i++)
        {
            if(adj[u][i])                                               //Checking if connected
            {
                if((distance[u] + adj[u][i]) < distance[i])             //Update
                {
                    distance[i] = distance[u] + adj[u][i];
                    pq.push(make_pair(distance[i], i));
                }
            }
        }
    }

    cout << "Nodes with their respective shortest path:" << endl;

    for(i=1; i<=v; i++)
        printf("%d\t\t%d\n", i, distance[i]);
}
