#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class MatrixGraph
{
	public:
		MatrixGraph(vector<vector<int>> p) { paths = p; }
		~MatrixGraph(){};
		
		void addEdge(int u, int v)
		{
			paths[u][v] = 1;
			paths[v][u] = 1;
		}
		
		void printGraph()
		{
			int count=0;
			cout << "Matriz de Adyacencia:\n";
			cout << "  ";
			for (int i=0; i<8; i++)
				cout << i << " ";
			cout << endl;
			for (vector<int> row : paths)
			{
				cout << count << " ";
				for (int val : row)
				{
					cout << val << " ";
				}
				count++;
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
			vector<int> parent(8,-1);
			vector<int> path;
			queue<int> queue;
			
			queue.push(start);
			visited[start] = true;
			
			while (!queue.empty())
			{
				int curr = queue.front();
				queue.pop();
				
				if (curr == end)
				{
					cout << "Camino Encontrado: ";
					for (int i=end; i != -1; i = parent[i])
						path.push_back(i);
						
					for (int i=path.size()-1;i>-1;i--)
					{
						cout << path[i];
						if (i>0)
							cout << " -> ";
					}
					
					return;
				}
				
				for (int i=0; i<8; i++)
				{
					if (!visited[i] && areAdjacent(i, curr))
					{
						queue.push(i);
						visited[i] = true;
						parent[i] = curr;
					}
				}
			}
			
			cout << "No hay Camino" << endl;
			return;
		}
		
	private:
		vector<vector<int>> paths;
};

class ListGraph
{
	public:
		ListGraph(vector<vector<pair<int, int>>> p) { paths = p; }
		~ListGraph(){}
		
		void AddEdge(int u, int v, int weight)
		{
			paths[u].push_back(make_pair(v, weight));
			paths[v].push_back(make_pair(u, weight));
		}
		
		void PrintGraph()
		{
			for (int i=0; i<8; i++)
			{
				cout << "Nodo " << i << ": ";
				for (const auto& adj : paths[i])
					cout << "("<< adj.first << ", " << adj.second << ")";
				cout << endl;
			}
		}
		
		bool AreAdjacent(int u, int v)
		{
			for (const auto& i : paths[u])
				if (i.first == v)
					return true;
					
			return false;
		}
		
		bool FindPath(int start, int end)
		{
			vector<bool> visited(8, false);
			stack<int> stack;
			
			stack.push(start);
			visited[start] = true;
			
			while(!stack.empty())
			{
				int curr = stack.top();
				stack.pop();
				
				if (curr == end)
					return true;
				
				for (const auto& adj : paths[curr])
				{
					if (!visited[adj.first])
					{
						stack.push(adj.first);
						visited[adj.first] = true;
					}
				}
			}
			
			return false;
		}
		
	private:
		vector<vector<pair<int, int>>> paths;
};

int main()
{
	// ejercicios con matriz de adyacencia
	vector<vector<int>> matrix(8, vector<int>(8, 0));
	MatrixGraph matrixGraph(matrix);
	
	matrixGraph.addEdge(0,2);
	matrixGraph.addEdge(0,3);
	matrixGraph.addEdge(0,4);
	matrixGraph.addEdge(1,2);
	matrixGraph.addEdge(1,3);
	matrixGraph.addEdge(1,4);
	matrixGraph.addEdge(1,5);
	matrixGraph.addEdge(1,6);
	matrixGraph.addEdge(2,5);
	matrixGraph.addEdge(2,6);
	matrixGraph.addEdge(3,6);
	matrixGraph.addEdge(3,7);
	matrixGraph.addEdge(4,5);
	matrixGraph.addEdge(4,7);
	matrixGraph.addEdge(6,7);
	matrixGraph.printGraph();
	
	if (matrixGraph.areAdjacent(1,3))
		cout << "Son Adyacentes" << endl;
	else
		cout << "No Son Adyacentes" << endl;
		
	if (matrixGraph.areAdjacent(4,2))
		cout << "son adyacentes" << endl;
	else
		cout << "no son adyacentes" << endl;
		
	matrixGraph.findPath(0,5);
	cout << endl;
	matrixGraph.findPath(2,4);
	cout << endl;
	matrixGraph.findPath(1,7);
	cout << endl;
	
	// ejercicios con lista de adyacencia y peso
	vector<vector<pair<int,int>>> list(8);
	ListGraph listGraph(list);
	
	listGraph.AddEdge(0, 1, 4);
	listGraph.AddEdge(0, 4, 12);
	listGraph.AddEdge(1, 2, 8);
	listGraph.AddEdge(1, 4, 11);
	listGraph.AddEdge(2, 2, 7);
	listGraph.AddEdge(2, 5, 4);
	listGraph.AddEdge(2, 7, 7);
	listGraph.AddEdge(3, 4, 9);
	listGraph.AddEdge(3, 5, 14);
	listGraph.AddEdge(4, 5, 10);
	listGraph.AddEdge(5, 6, 2);
	listGraph.AddEdge(6, 7, 6);
	
	listGraph.PrintGraph();
	
	if (listGraph.AreAdjacent(1,3))
		cout << "Son Adyacentes" << endl;
	else
		cout << "No Son Adyacentes" << endl;
		
	if (listGraph.AreAdjacent(4,2))
		cout << "son adyacentes" << endl;
	else
		cout << "no son adyacentes" << endl;
		
	if (listGraph.FindPath(0,5))
		cout << "Existe Camino";
	
	return 0;
}
