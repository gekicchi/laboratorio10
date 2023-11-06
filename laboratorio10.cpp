#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph
{
	public:
		Graph(vector<vector<int>> p) { paths = p; }
		~Graph(){};
		vector<vector<int>> getPath() { return paths; }
		
		void addEdge(int u, int v)
		{
			paths[u][v] = 1;
			paths[v][u] = 1;
		}
		
		void printGraph()
		{
			cout << "Matriz de Adyacencia:\n";
			for (vector<int> row : paths)
			{
				for (int val : row)
					cout << val << " ";
					
				cout << "\n";
			}
		}
		
		bool areAdjacent(int u, int v)
		{
			
			if (paths[u][v] == 1)
				return true;
				
			return false;
		}
		
		void findPath(int start, int end)
		{
			vector<bool> visited(8,false);
			vector<int> path(8,0);
			stack<int> stack;
			
			stack.push(start);
			visited[start] = true;
			
			while (!stack.empty())
			{
				int curr = stack.top();
				stack.pop();
				path.push_back(curr);
				
				if (curr == end)
				{
					cout << "Camino Encontrado: ";
					for (int vertex : path)
						cout << vertex << " ";
					cout << endl;
					
					return;
				}
				
				for (int adj : paths[curr])
				{
					if (!visited[adj] && areAdjacent(adj, curr))
					{
						stack.push(adj);
						visited[adj] = true;
					}
				}
			}
			
			cout << "No hay Camino" << endl;
			return;
		}
		
	private:
		vector<vector<int>> paths;
};

//void add_path()

int main()
{
	// Create an empty adjacency matrix
	vector<vector<int>> graph(8, vector<int>(8, 0));
	Graph attempt(graph);
	
	attempt.addEdge(0,2);
	attempt.addEdge(0,3);
	attempt.addEdge(0,4);
	attempt.addEdge(1,2);
	attempt.addEdge(1,3);
	attempt.addEdge(1,4);
	attempt.addEdge(1,5);
	attempt.addEdge(1,6);
	attempt.addEdge(2,5);
	attempt.addEdge(2,6);
	attempt.addEdge(3,6);
	attempt.addEdge(3,7);
	attempt.addEdge(4,5);
	attempt.addEdge(4,7);
	attempt.addEdge(6,7);
	attempt.printGraph();
	
	if (attempt.areAdjacent(1,3))
		cout << "Son Adyacentes" << endl;
	else
		cout << "No Son Adyacentes" << endl;
		
	if (attempt.areAdjacent(4,2))
		cout << "son adyacentes" << endl;
	else
		cout << "no son adyacentes" << endl;
		
	attempt.findPath(0,1);
	
	return 0;
}
