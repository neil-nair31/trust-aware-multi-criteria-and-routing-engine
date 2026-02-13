#include <iostream>
#include <queue>
#include <climits>
using namespace std;

#define MAXN 100
#define MAXE 100

struct Edge {
    int to;
    int latency;
    int cost;
    float trust;
};

Edge adj[MAXN][MAXE];
int edgeCount[MAXN];

float trust_score = 0.6;

void addEdge(int u, int v, int latency, int cost, float trust) {
    adj[u][edgeCount[u]].to = v;
    adj[u][edgeCount[u]].latency = latency;
    adj[u][edgeCount[u]].cost = cost;
    adj[u][edgeCount[u]].trust = trust;
    edgeCount[u]++;

}

int computescore(Edge e){
    int trust_pen = (int)(10/e.trust);
    return e.latency + e.cost + trust_pen; 
}

int dijkstra(int start,int end,int n){
    int dist[MAXN];
    for(int i = 0; i < n; i++){
        dist[i] = INT_MAX;
    }
priority_queue<
    pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>>
> pq;

dist[start] = 0;
pq.push({0, start});

while(!pq.empty()){
    int curr_cost = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    if(node == end){
        return curr_cost;
    }

    for(int i = 0; i < edgeCount[node]; i++){
        Edge e = adj[node][i];
        if (e.trust < trust_score) {
            continue; 
        }
        int new_cost = curr_cost + computescore(e);
        if(new_cost < dist[e.to]){
            dist[e.to] = new_cost;
            pq.push({new_cost, e.to});
        }
    }
}
return -1;
}

int main(){
    int n, m;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;
    for(int i = 0; i < n; i++){
        edgeCount[i] = 0;
    }
    cout << "Now enter edge details.\n";
    cout << "For each edge, enter:\n";
    cout << "u, v, latency, cost, trust";
    cout << "Example: 0 1 10 5 0.9\n";
    for(int i = 0; i < m; i++){
        int u, v, latency, cost;
        float trust;
        cout << "Edge " << i + 1 << ": ";
        cin >> u >> v >> latency >> cost >> trust;
        addEdge(u, v, latency, cost, trust);
    }
    int start, end;
    cout << "\nEnter source node: ";
    cin >> start;
    cout << "Enter destination node: ";
    cin >> end;
    int result = dijkstra(start, end, n);
    if(result == -1){
        cout << "No trustworthy path found.\n";
    }
    else{
        cout << "Minimum trusted cost from node "
             << start << " to node "
             << end << " is: "
             << result << "\n";
    }
    return 0;
}