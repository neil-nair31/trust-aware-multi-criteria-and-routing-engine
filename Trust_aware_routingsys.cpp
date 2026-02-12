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
    int trust;
};

Edge adj[MAXN][MAXE];
int edgeCount[MAXN];

float trust_score = 0.6;

void addEdge(int u, int v, int latency, int cost, int trust) {
    adj[u][edgeCount[u]].to = v;
    adj[u][edgeCount[u]].latency = latency;
    adj[u][edgeCount[u]].cost = cost;
    adj[u][edgeCount[u]].trust = trust;
    edgeCount[u]++;

}

int computescore(Edge e){
    int trust_pen = (int)(e.10/trust)
    return e.latency + e.cost + trust_pen; 
}

int djikstra(int start, int end){
    int dist[MAXN];
    if(int i = 0; i < MAXN; i++){
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
        Edge e = adj[node][i]
        if e.trust < trust_score {
            continue; 
        }
        int new_cost = curr_cost + computescore(e);
        if(new_cost < dist[e.to]){
            dist[e.to] = new_cost;
            pq.push({new_cost, e.to});
        }
    }
}
}
