/*
Assignment 7
Title : prim's and kruskal's algorithm
Aim : To create the graph data structure and implement prim's and kruskal's algorithm to find the minimum spanning tree
*/
#include <unordered_map>
#include <list>
#include <iostream>
#include <vector>
#include <stack>
#include <climits>
#include <queue>
#include<algorithm>

using namespace std;

// class : disjoing_set - to implement dijoint set data structure for kruskal's algorithm
class disjoint_set
{
private:
    vector<int> parent, rank, size;
    // constructor
public:
    disjoint_set(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for (int i = 0; i < n + 1; i++)
        {
            parent[i] = i;
        }
    }

    // to find the ultimate parent
    int findUParent(int u)
    {
        if (u == parent[u])
            return u;

        // return findUParent(parent[u]);  => for O(logn)
        return parent[u] = findUParent(parent[u]);
    }

    // union by rank
    void union_by_rank(int u, int v)
    {
        int par_u = findUParent(u);
        int par_v = findUParent(v);

        // belongs to the same component
        if (par_u == par_v)
            return;

        if (rank[par_u] < rank[par_v])
        {
            parent[par_u] = par_v;
        }
        else if (rank[par_u] > rank[par_v])
        {
            parent[par_v] = par_u;
        }
        else
        {
            parent[par_v] = par_u;
            rank[par_u]++;
        }
    }

    void union_by_size(int u, int v)
    {
        int par_u = findUParent(u);
        int par_v = findUParent(v);

        // belongs to the same component
        if (par_u == par_v)
            return;

        if (size[par_u] < size[par_v])
        {
            parent[par_u] = par_v;
            size[par_v] += size[par_u];
        }
        else
        {
            parent[par_v] = par_u;
            size[par_u] += size[par_v];
        }
    }
};


// class : graph - graph data structure to implement prim's and kruskal's algorithm
class graph
{
private:
    int nodes;
    unordered_map<int, list<pair<int, int>>> adj;

public:
    graph(int nodes)
    {
        this->nodes = nodes;
    }

    void add_edge(int u, int v, int w)
    {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    void make_list()
    {
        cout << "Enter no of edges : " << endl;
        int e;
        cin >> e;
        for (int i = 0; i < e; i++)
        {
            cout << "Enter edge => (start node, end node, weight)" << endl;
            int u, v, w;
            cin >> u >> v >> w;
            add_edge(u, v, w);
        }
    }

    void print_adj()
    {
        cout << "Adjacency list : " << endl;
        for (int i = 0; i < nodes; i++)
        {
            cout << i << " -> ";
            for (auto j : adj[i])
            {
                cout << " [" << j.first << ", " << j.second << "], ";
            }
            cout << endl;
        }
    }

    void print_arr(vector<int> dist)
    {
        cout << "The array of shortest path : " << endl;
        for (int i = 0; i < dist.size(); i++)
        {
            cout << dist[i] << " ";
        }
        cout << endl;
    }

    void display_mst(vector<pair<int, int>> &parent)
    {
        cout << endl
             << "********** Minimum Spanning Tree **********";
        cout << endl;
        cout << "Edge | weight" << endl << "_____|_______" << endl;
        for (int i = 0; i < nodes; i++)
        {
            if (parent[i].first != -1)
                cout << parent[i].first << "--" << i << " | (" << parent[i].second << ")" << endl;
        }
        cout << endl;
    }

    void prims()
    {

        vector<bool> visited(nodes, false);  // to keep track of visited nodes
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        vector<pair<int, int>> parent(nodes + 1, {-1, -1}); 
        vector<int> dist(nodes, INT_MAX);   
        parent[0] = {-1, 0};
        dist[0] = 0;
        int sum = 0;

        min_heap.push(make_pair(0, 0));
        while (!min_heap.empty())
        {
            int u = min_heap.top().second;
            int w = min_heap.top().first;
            min_heap.pop();

            // if already visited then skip
            if (visited[u])
                continue;

            visited[u] = true; // mark current node as visited
            sum += w;
            // add adjacent nodes to pq
            for (auto neighbour : adj[u])
            {
                if (!visited[neighbour.first])     // if not visited the node then make it child and push to min heap
                {
                    parent[neighbour.first] = {u, neighbour.second};
                    min_heap.push({neighbour.second, neighbour.first});
                }
            }
        }
        cout << endl << "*************Prim's algorithm***************" << endl;
        display_mst(parent);
        cout << "The shortest distance is : " << sum << endl;
    }

    void kruskals()
    {
        int V = nodes;
        // make the arr of the edges
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < V; i++)
        {
            for (auto j : adj[i])
            {
                int u = i;
                int v = j.first;
                int w = j.second;

                edges.push_back(make_pair(w, make_pair(u, v)));
            }
        }
        vector<pair<int, int>> mst(nodes + 1, {-1, -1});
        disjoint_set d(V);
        // sort the array of edges
        sort(edges.begin(), edges.end());

        int mstWt = 0;
        for (auto i : edges)
        {
            int wt = i.first;
            int u = i.second.first;
            int v = i.second.second;

            if (d.findUParent(u) != d.findUParent(v))    // u and v does not belong to the same component
            {
                mstWt += wt;
                d.union_by_size(u, v);
                if (mst[u].first == -1)
                {
                    mst[u] = {v, wt};
                }
                else if (mst[v].first == -1)
                {
                    mst[v] = {u, wt};
                }
            }
        }
        cout << "*************Kruskal's algorithm***************" << endl;
        display_mst(mst);
        cout << "The minimum cost is : " << mstWt << endl;
    }
};

int main()
{
    cout << endl <<  "------------- Prims's and Kruskal's Algorithm---------------" << endl << endl;
    int nodes = 0;
    
    // Get the number of nodes from the user
    cout << "Enter no. of nodes : ";
    cin >> nodes;

    // Create a graph object
    graph g(nodes);

    // Populate the graph with user-input edges
    g.make_list();

    // Print the adjacency list of the graph
    g.print_adj();

    // Execute Prim's algorithm to find Minimum Spanning Tree
    g.prims();

    // Execute Kruskal's algorithm to find Minimum Spanning Tree
    g.kruskals();

    return 0;
}

/*
Sample test cases :-
4 4 0 1 1 0 2 2 2 3 1 1 3 4
5 8 0 1 3 0 2 2 1 2 1 1 3 4 2 3 5 2 4 2 3 4 1 4 0 3
*/
