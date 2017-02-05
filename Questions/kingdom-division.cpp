#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int degree[1000001];

#define MOD 1000000007

// A structure to represent an adjacency list node
struct AdjListNode
{
    long dest;
    struct AdjListNode* next;
};
 
// A structure to represent an adjacency list
struct AdjList
{
    struct AdjListNode *head;  // pointer to head node of list
    int size;
};
 
// A structure to represent a graph. A graph is an array of adjacency lists.
// Size of array will be V (number of vertices in graph)
struct Graph
{
    long V;
    struct AdjList* array;
};
 
// A utility function to create a new adjacency list node
struct AdjListNode* newAdjListNode(long dest)
{
    struct AdjListNode* newNode =
            (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}
 
// A utility function that creates a graph of V vertices
struct Graph* createGraph(long V)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
 
    // Create an array of adjacency lists.  Size of array will be V
    graph->array = (struct AdjList*) malloc((V + 1) * sizeof(struct AdjList));
 
     // Initialize each adjacency list as empty by making head as NULL
    long i;
    for (i = 1; i <= V; ++i) {
        graph->array[i].head = NULL;
        graph->array[i].size = 0;
    }
 
    return graph;
}
 
// Adds an edge to an undirected graph
void addEdge(struct Graph* graph, long src, long dest)
{
    // Add an edge from src to dest.  A new node is added to the adjacency
    // list of src.  The node is added at the begining
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
    graph->array[src].size ++;
 
    // // Since graph is undirected, add an edge from dest to src also
    // newNode = newAdjListNode(src);
    // newNode->next = graph->array[dest].head;
    // graph->array[dest].head = newNode;
    // graph->array[src].size ++;
}
 
// A utility function to print the adjacenncy list representation of graph
void printGraph(struct Graph* graph)
{
    long v;
    for (v = 1; v <= graph->V; ++v)
    {
        struct AdjListNode* pCrawl = graph->array[v].head;
        cout<<"\n Adjacency list of vertex " << v << " head";
        while (pCrawl)
        {
            cout<<"->" << pCrawl->dest;
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

void populateDegree(Graph *graph) {
	for (int i = 1; i <= graph -> V; i++) {
		degree[i] = graph -> array[i].size;
	}
}

long solve(Graph *graph) {
	long count = 1;
    for (long v = 1; v <= graph->V; ++v)
    {
    	if (degree[v] > 2) {
	        struct AdjListNode* pCrawl = graph->array[v].head;
	        while (pCrawl)
	        {
	            int vertex = pCrawl->dest;
	            if (degree[vertex] >= 	1) {
	            	count = (count % MOD + 1) % MOD;
	            }
	            pCrawl = pCrawl->next;
	        }
       	}
    }
    return count;
}

void printVector(std::vector< pair<long, long> > v) {
	for (vector< pair<long, long> >::iterator it = v.begin(); it != v.end(); it++) {
		cout << it -> first << " " << it -> second << " ";
	}
	cout << endl;
}

int main() {

	int n;
	cin >> n;
	Graph *graph = createGraph(n);
	for (int i = 0; i < n - 1; ++i)
	{
		int x, y;
		cin >> x >> y;
		addEdge(graph, x, y);
		addEdge(graph, y, x);
	}

	populateDegree(graph);
	long solution = solve(graph);
	solution = (solution % MOD + solution % MOD) % MOD;
	cout << solution << endl;
	return 0;
}