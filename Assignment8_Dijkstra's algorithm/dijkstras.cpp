/*
Assignment 8
Title : dijkstra's algorithm
Aim : To make a graph data structure and find shortest distance from the source node to all nodes using dijkstra's algorithm
*/

#include <unordered_map> // header files
#include <list>
#include <iostream>
#include <vector>
#include <stack>
#include <climits>
#include <queue>
using namespace std;

// class : graph - to implement graph data structure
class graph
{
private:
    int nodes;
    unordered_map<int, list<pair<int, int>>> adj;

public:
    graph(int nodes); // constructor : takes no of nodes as input parameter

    void add_edge(int u, int v, int w); // adds an edge between nodes u and v with given weight w

    void make_list(); // creates an adjacancy list for the graph

    void print_adj(); // prints the adjacancy list of the graph

    void print_arr(vector<int> dist); // prints the array given in input parameter

    void dijkstra(int src); // implementation of dijkstra's algorithm
};

// parameterized constructor : input no of nodes
graph ::graph(int nodes)
{
    this->nodes = nodes;
}

// adds an edge between u and v with weight w
void graph ::add_edge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

// creates an adjacacncy list for graph
void graph ::make_list()
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


// print adjoint list of the graph
void graph ::print_adj()
{
    cout << endl;
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
    cout << endl;
}

// print the array given in the input parameter
void graph ::print_arr(vector<int> dist)
{
    cout << "The shortest path : " << endl;
    for (int i = 0; i < dist.size(); i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
}


// implementation of dijkstra's algoritm
void graph ::dijkstra(int src)
{
    vector<int> dist(this->nodes, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
    // make distance of src node o and push to the min heap
    dist[src] = 0;
    min_heap.push({0, src});

    while (!min_heap.empty())
    {
        // fetch the data at the top of min heap
        pair<int, int> top = min_heap.top();
        min_heap.pop();
        int curr_src = top.second;
        int curr_dist = top.first;
        for (auto neighbour : adj[curr_src])
        { // find neighbours of the current node
            if (neighbour.second + curr_dist < dist[neighbour.first])
            { // distance is less, update and push it
                dist[neighbour.first] = neighbour.second + curr_dist;
                min_heap.push({dist[neighbour.first], neighbour.first});
            }
        }
    }
    // print the array of the shortest distance
    print_arr(dist);
}

int main()
{
    cout << "-----------------Dijkstra's Algorithm--------------------" << endl;
    int nodes;                 
    cout << "Enter no of nodes : " << endl;
    cin >> nodes;               //input of no of nodes from user 
    graph g(nodes);             // make graph g
    g.make_list();              // make agjacancy list of graph
    g.print_adj();              // display adjacancy list
    cout << "To find the shortest path enter source node : " << endl;
    int src;
    cin >> src;                 // take input for source node
    g.dijkstra(src);            // implement dijstra's algorithm
    return 0;
}

/*
sample testcases :- 
i) 4 4 0 1 1 0 2 2 2 3 1 1 3 4  
    src - 0
ii) 5 8 0 1 3 0 2 2 1 2 1 1 3 4 2 3 5 2 4 2 3 4 1 4 0 3
    src - 0

output :-
0 1 2 3
0 3 2 4 3
*/