#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

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
    for (i = 1; i <= V; ++i)
        graph->array[i].head = NULL;
 
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
 
    // Since graph is undirected, add an edge from dest to src also
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
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
	long t;
	long n;
	cin >> t;
	while(t--) {
		cin >> n;
		vector< pair<long, long> > valueKey;
		for (long i = 1; i <= n; i++) {
			long x;
			cin >> x;
			valueKey.push_back(pair<long, long>(x, i));
		}
		sort(valueKey.begin(), valueKey.end());
		long arr[n + 1];
		long j = 1;
		for (vector< pair<long, long> >::iterator it = valueKey.begin(); it != valueKey.end(); it++) {
			arr[it->second] = j++;
		}

		Graph* graph = createGraph(n);
		for (long i = 0; i < n - 1; i++) {
			long x, y;
			cin >> x >> y;
			addEdge(graph, x, y);
		}
		bool visited[n+1];
	}

	return 0;
}