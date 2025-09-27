#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

#define INF 0x3f3f3f3f

class Graph {
    int V;
    vector<vector<pair<int, int>>> adj;
    
    void printGraph(vector<int>& dist, int src, int current = -1, string action = "") {
        system("cls");
        cout << "Algoritma Dijkstra - Mencari Jarak Terpendek dari Node " << src << "\n\n";
        cout << action << "\n\n";
        
        cout << "Status Jarak:\n";
        for (int i = 0; i < V; i++) {
            cout << "Node " << i << ": ";
            if (dist[i] == INF)
                cout << "∞";
            else {
                if (i == current)
                    cout << "\033[1;32m" << dist[i] << "\033[0m";
                else if (dist[i] < INF)
                    cout << "\033[1;34m" << dist[i] << "\033[0m"; 
                else
                    cout << dist[i];
            }
            cout << endl;
        }
        
        Sleep(1000);
    }
    
public:
    Graph(int v) {
        V = v;
        adj.resize(v);
    }
    
    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    void dijkstra(int src) {
        vector<int> dist(V, INF);
        dist[src] = 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        
        printGraph(dist, src, src, "Memulai dari node " + to_string(src));
        
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            
            printGraph(dist, src, u, "Memproses node " + to_string(u));
            
            for (auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                
                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                    
                    printGraph(dist, src, v, "Update jarak ke node " + to_string(v) + 
                               " menjadi " + to_string(dist[v]));
                }
            }
        }
        
        printGraph(dist, src, -1, "Dijkstra selesai!");
    }
};

int main() {
    int V, E, src;
    
    cout << "Masukkan jumlah vertex: ";
    cin >> V;
    
    Graph g(V);
    
    cout << "Masukkan jumlah edge: ";
    cin >> E;
    
    cout << "Masukkan " << E << " edge (u v weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }
    
    cout << "Masukkan vertex sumber: ";
    cin >> src;
    
    g.dijkstra(src);
    
    return 0;
}