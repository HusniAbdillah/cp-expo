#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

class DSU {
public:
    vector<int> parent, rank;
    
    DSU(int n) {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) return;
        
        if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
};

void visualizeGraph(vector<pair<int, pair<int, int>>>& edges, vector<pair<int, pair<int, int>>>& mstEdges, 
                    int V, string action = "") {
    system("cls");
    cout << "Kruskal's MST Algorithm\n\n";
    cout << action << "\n\n";
    
    cout << "Semua Edge (sorted by weight):\n";
    for (auto& edge : edges) {
        int weight = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        cout << u << " -- " << v << " : " << weight << endl;
    }
    
    cout << "\nMST Edges dipilih:\n";
    int totalWeight = 0;
    for (auto& edge : mstEdges) {
        int weight = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        cout << "\033[1;32m" << u << " -- " << v << " : " << weight << "\033[0m" << endl;
        totalWeight += weight;
    }
    
    cout << "\nTotal Weight MST: " << totalWeight << endl;
    Sleep(1000);
}

void kruskalMST(vector<pair<int, pair<int, int>>>& edges, int V) {
    sort(edges.begin(), edges.end());
    
    vector<pair<int, pair<int, int>>> mstEdges;
    DSU dsu(V);
    
    visualizeGraph(edges, mstEdges, V, "Starting Kruskal's Algorithm");
    
    for (auto& edge : edges) {
        int weight = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        
        if (dsu.find(u) != dsu.find(v)) {
            mstEdges.push_back(edge);
            dsu.unite(u, v);
            visualizeGraph(edges, mstEdges, V, "Added edge " + to_string(u) + " -- " + 
                          to_string(v) + " with weight " + to_string(weight));
            
            if (mstEdges.size() == V - 1)
                break;
        } else {
            visualizeGraph(edges, mstEdges, V, "Skipping edge " + to_string(u) + " -- " + 
                          to_string(v) + " (would form a cycle)");
        }
    }
    
    visualizeGraph(edges, mstEdges, V, "Kruskal's Algorithm Complete!");
}

int main() {
    int V, E;
    
    cout << "Masukkan jumlah vertex: ";
    cin >> V;
    
    cout << "Masukkan jumlah edge: ";
    cin >> E;
    
    vector<pair<int, pair<int, int>>> edges;
    
    cout << "Masukkan " << E << " edge (u v weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }
    
    kruskalMST(edges, V);
    
    return 0;
}