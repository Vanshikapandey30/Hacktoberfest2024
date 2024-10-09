#include <bits/stdc++.h>
using namespace std;

int main()
{
        int vertex, edges;
        cout<<"Enter size"<<endl;
        cin>>vertex>>edges;
    //Initialize matrix
        vector<vector<bool> >AdjMat(vertex, vector<bool>(vertex,0));

    // For undirected connected graph Adjecency matrix
        int u,v, weight;
        for(int i=0;i<edges;i++){
            cin>>u>>v;
            AdjMat[u][v] = 1;
            AdjMat[v][u] = 1;
        }

    // For undirected weighted graph
        vector<vector<int> >AdjMat(vertex, vector<int>(vertex,0));
        for(int i=0;i<edges;i++){
            cin>>u>>v>>weight;
            AdjMat[u][v] = weight;
            AdjMat[v][u] = weight;
        }

    // // For Directed connected graph adjecency metrix
        for(int i=0;i<edges;i++){
            cin>>u>>v;
            AdjMat[u][v] = 1;
        }

    // // For Directed connected, weighted graph adjecency metrix
        for(int i=0;i<edges;i++){
            cin>>u>>v>>weight;
            AdjMat[u][v] = weight;
        }

    // //Printing
        for (int i = 0; i < vertex; i++)
        {
            for (int j = 0; j < vertex; j++)
            {
                cout<<AdjMat[i][j]<<" ";
            }

            cout<<endl;
        }

    // Adjicency lest

    int vertex, edges;
    cin >> vertex >> edges;

    // vector<int>AdjLest[vertex];

    int u, v;

    // undirected graph without weight

    for (int i = 0; i < edges; i++)
    {
        cin>>u>>v;
        AdjLest[u].push_back(v);
        AdjLest[v].push_back(u);
    }

    // undirected graph with weight

    vector<pair<int, int>> AdjLest[vertex];
    int weight;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v >> weight;
        AdjLest[u].push_back(make_pair(v, weight));
        AdjLest[v].push_back(make_pair(u, weight));
    }



    // directed graph unweighted.

    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        AdjLest[u].push_back(v);
    }




    // directed graph with weight

    vector<pair<int, int>> AdjLest[vertex];
    int weight;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v >> weight;
        AdjLest[u].push_back(make_pair(v, weight));
    }





    printing
    for (int i = 0; i < vertex; i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < AdjLest[i].size(); j++)
        {
            cout << AdjLest[i][j] << " ";
        }
        cout << endl;
    }


// printing pair
    for (int i = 0; i < vertex; i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < AdjLest[i].size(); j++)
        {
            cout << AdjLest[i][j].first<<" weight = "<<AdjLest[i][j].second << ", ";
        }
        cout << endl;
    }

    return 0;
}
