#Trust Aware Multi Criteria Routing Engine (C++)

#Overview
This project implements a trust aware shortest path finding engine in C++ using classical Data Structures and Algorithms Concepts.

It extends Dijkstras algorithm to support:
- Multi criteria edge evaluation
- Trust threshold filtering
- Composite edge scoring
- Array based adjacency list representation

The goal of this project was to demonstrate and apply the core DSA principles i have learnt to solve constrained path optimization problems.

## Problem Statement

Given a directed graph where each edge has:

- Latency (time cost)
- Monetary cost
- Trust score (0.0 to 1.0)

Find the min cost path between a source and destination node such that:

- Only edges with trust >= threshold are considered
- Edge cost is computed using a composite scoring function

## Core Concepts Used

- Graph Representation (Array-based adjacency list)
- Struct based edge modeling
- Priority Queue (Min Heap)
- Greedy Algorithms
- Modified Dijkstras Algorithm
- Multi criteria composite scoring
- Constraint filtering

## Graph Representation

The graph is implemented using fixed-size arrays:

```
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
```

This avoids dynamic containers and demonstrates manual adjacency list management.

## Composite Scoring Function

Each edge is assigned a composite weight:

```
Score = latency + cost + (10 / trust)
```

Higher trust results in a lower penalty.
Edges below the trust threshold are ignored.

---

## Algorithm Used

Modified Dijkstra’s Algorithm:

1. Initialize all node distances to infinity.
2. Set source node distance to 0.
3. Use a min-heap (priority queue) to always process the node with the lowest current cost.
4. Ignore edges below trust threshold.
5. Relax edges using composite scoring.
6. Stop when destination is reached.


## Time and Space Complexity

Time Complexity:

O((V + E) log V)


Where:
- V = number of nodes
- E = number of edges

Space Complexity:

O(V + E)


## Example Input

```
Enter number of nodes: 4
Enter number of edges: 4

Edge 1: 0 1 10 5 0.9
Edge 2: 0 2 15 2 0.5
Edge 3: 1 3 10 3 0.8
Edge 4: 2 3 5 1 0.9

Enter source node: 0
Enter destination node: 3
```


## Compilation

Using MSYS2 / MinGW:

```
g++ trust_routing.cpp -o trust_routing
./trust_routing
```


## Features

- Trust-aware path filtering
- Composite multi-criteria optimization
- Array-based adjacency list implementation
- Heap-optimized shortest path computation
- Interactive user input


## Possible Improvements

- Path reconstruction (print actual path)
- Undirected graph support
- Configurable trust threshold input
- Adjustable weight coefficients
- Edge normalization for real-world scaling


## Motivation

This project was built to explore how classical DSA algorithms and concepts such as Dijkstra can be applied to handle real world constraints like reliability and trust scoring.
I tried to demonstrate algorithm modification, constraint modeling, and efficient implementation without relying on high level graph libraries.
