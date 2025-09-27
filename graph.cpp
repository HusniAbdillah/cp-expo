#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adj;
    void printGraph(vector<bool>& visited, int current = -1, string action = "") {
        system("cls");
        cout << "Visualisasi Graph Traversal\n\n";
        cout << action << "\n\n";
    
        cout << "Adjacency List:\n";
        for (int i = 0; i < V; i++) {
            cout << i << " -> ";
            for (auto v : adj[i]) cout << v << " ";
            cout << endl;
        }
        
        cout << "\nStatus Node:\n";
        for (int i = 0; i < V; i++) {
            if (i == current)
                cout << "\033[1;32m" << i << ": " << (visited[i] ? "Visited" : "Not Visited") << "\033[0m\n";
            else if (visited[i])
                cout << "\033[1;34m" << i << ": Visited\033[0m\n";
            else
                cout << i << ": Not Visited\n";
        }
        
        Sleep(1000);
    }

public:
    Graph(int v) {
        V = v;
        adj.resize(v);
    }
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;
        
        visited[start] = true;
        q.push(start);
        
        printGraph(visited, start, "Memulai BFS dari node " + to_string(start));
        
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            
            printGraph(visited, current, "Memeriksa node " + to_string(current));
            
            for (int neighbor : adj[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                    printGraph(visited, neighbor, "Mengunjungi tetangga: " + to_string(neighbor));
                }
            }
        }
        
        printGraph(visited, -1, "BFS selesai!");
    }
    
    void DFS(int start) {
        vector<bool> visited(V, false);
        DFSUtil(start, visited);
        printGraph(visited, -1, "DFS selesai!");
    }
    
    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        printGraph(visited, v, "Mengunjungi node " + to_string(v));
        
        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }
};

int main() {
    int v, e, choice;
    cout << "Masukkan jumlah vertex: ";
    cin >> v;
    
    Graph g(v);
    
    cout << "Masukkan jumlah edge: ";
    cin >> e;
    
    cout << "Masukkan " << e << " edge (u v):\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    
    int start;
    cout << "Masukkan vertex awal: ";
    cin >> start;
    
    cout << "Pilih algoritma traversal:\n";
    cout << "1. Breadth-First Search (BFS)\n";
    cout << "2. Depth-First Search (DFS)\n";
    cin >> choice;
    
    if (choice == 1)
        g.BFS(start);
    else if (choice == 2)
        g.DFS(start);
    else
        cout << "Pilihan tidak valid\n";
    
    return 0;
}