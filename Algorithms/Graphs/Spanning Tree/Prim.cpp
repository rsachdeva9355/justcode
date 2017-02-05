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

// A structure to represent an adjacency list node
struct AdjListNode
{
    long dest;
    long weight;
    struct AdjListNode* next;
};
 
// A structure to represent an adjacency list
struct AdjList
{
    struct AdjListNode *head;  // pointer to head node of list
};
 
// A structure to represent a graph. A graph is an array of adjacency lists.
// Size of array will be V (number of vertices in graph)
struct Graph
{
    long V;
    struct AdjList* array;
};
 
// A utility function to create a new adjacency list node
struct AdjListNode* newAdjListNode(long dest, long weight)
{
    struct AdjListNode* newNode =
            (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
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
    for (i = 1; i <= V; ++i)
        graph->array[i].head = NULL;
 
    return graph;
}
 
// Adds an edge to an undirected graph
void addEdge(struct Graph* graph, long src, long dest, long weight)
{
    // Add an edge from src to dest.  A new node is added to the adjacency
    // list of src.  The node is added at the begining
    struct AdjListNode* newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

typedef bool (*comp)(pair<long, pair<long, long>>, pair<long, pair<long, long>>);
bool compare(pair<long, pair<long, long>> a, pair<long, pair<long, long>> b)
{
   return (a.first < b.first);
}

void prims(Graph *graph) {
	priority_queue<pair<long, pair<long, long> >, vector< pair<long, pair<long, long>> >, comp> pq(compare);
	AdjListNode* node;
	AdjListNode* next;
	for (long v = 1; v <= graph->V; ++v)
    {
        node = graph->array[v].head;
        if (node->next != NULL) {
        	next = node -> next;
        	break;
        }
    }
    pq.push(pair<long, pair<long, long>> (make_pair(next -> weight, make_pair(node -> dest, next -> dest))));
    while(!pq.empty()) {
    }

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

void printVector(std::vector< pair<long, long> > v) {
	cout << "Printing Vector " << endl;
	for (vector< pair<long, long> >::iterator it = v.begin(); it != v.end(); it++) {
		cout << it -> first << " " << it -> second << " ";
	}
	cout << endl;
}

int main() {
	
	long n, m;
	cin >> n >> m;
	Graph *graph = createGraph(n);
	for (long i = 0; i < m; i++) {
		long x, y, w;
		cin >> x >> y >> w;
		addEdge(graph, x, y, w);
	}

	prims(graph);
	
	return 0;
}