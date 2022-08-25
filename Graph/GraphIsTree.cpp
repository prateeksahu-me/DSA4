#include bitsstdc++.h
using namespace std;
class Graph
{
	int V;  No. of vertices
	listint adj;  Pointer to an array for adjacency lists
	bool isCyclicUtil(int v, bool visited[], int parent);
public
	Graph(int V);  Constructor
	void addEdge(int v, int w);  to add an edge to graph
	bool isTree();  returns true if graph is tree
};

GraphGraph(int V)
{
	this-V = V;
	adj = new listint[V];
}

void GraphaddEdge(int v, int w)
{
	adj[v].push_back(w);  Add w to vs list.
	adj[w].push_back(v);  Add v to ws list.
}

 A recursive function that uses visited[] and parent to
 detect cycle in subgraph reachable from vertex v.
bool GraphisCyclicUtil(int v, bool visited[], int parent)
{
	 Mark the current node as visited
	visited[v] = true;

	 Recur for all the vertices adjacent to this vertex
	listintiterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
	{
		 If an adjacent is not visited, then recur for
		 that adjacent
		if (!visited[i])
		{
		if (isCyclicUtil(i, visited, v))
			return true;
		}

		 If an adjacent is visited and not parent of current
		 vertex, then there is a cycle.
		else if (i != parent)
		return true;
	}
	return false;
}

 Returns true if the graph is a tree, else false.
bool GraphisTree()
{
	 Mark all the vertices as not visited and not part of
	 recursion stack
	bool visited = new bool[V];
	for (int i = 0; i  V; i++)
		visited[i] = false;

	 The call to isCyclicUtil serves multiple purposes.
	 It returns true if graph reachable from vertex 0
	 is cyclic. It also marks all vertices reachable
	 from 0.
	if (isCyclicUtil(0, visited, -1))
			return false;

	 If we find a vertex which is not reachable from 0
	 (not marked by isCyclicUtil(), then we return false
	for (int u = 0; u  V; u++)
		if (!visited[u])
		return false;

	return true;
}

bool graphValidTree(int n, vectorvectorint& edges){
    Graph g1(n);
	
    for(int i = 0;iedges.size();i++)
    {
        g1.addEdge(edges[i][0],edges[i][1]);
        coutedges[i][0] edges[i][1]endl;
    }
    if(g1.isTree())
        return true;
	else
    	return false;
}


int main(){
    
int n,num;
cinnnum;
vectorvectorintedges;
while(num--)
{
    int a,b;
    cinab;
    vectorinttemp;
    temp.push_back(a);
    temp.push_back(b);
    edges.push_back(temp);
}
coutgraphValidTree(n,edges)endl;
    
}
