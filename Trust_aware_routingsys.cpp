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


