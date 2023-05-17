#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>
#include <QString>

using namespace std;

/**
 * @brief The Edge struct
 */
struct Edge {

    /**
     * @brief u index of first node
     */
    int u;

    /**
     * @brief v index of second node
     */
    int v;

    int weight;
};

/**
 * @brief node
 * pair of int to represent node (weight, index)
 * Used for MST
 */
typedef pair<int, int> node;

/**
 * @brief Graph class based on undirected adjacency matrix
 */
template <class Type>
class Graph
{
public:
    Graph();

    /**
     * @brief dfsOrder Order of nodes after DFS is run
     */
    vector<Type> dfsOrder;

    /**
     * @brief bfsOrder Order of nodes after BFS is run
     */
    vector<Type> bfsOrder;

    /**
     * @brief shortestOrder Visit all nodes in shortest order.
     * Populated by shortestPath()
     */
    vector<Type> shortestOrder;

    /**
     * @brief dijkstraOrder Order of nodes for multiDijkstra()
     */
    vector<Type> dijkstraOrder;

    /**
     * @brief Output edges in MST
     */
    QString mstString;

    /**
     * @brief Adds node to graph
     * @param obj Object to add to graph
     */
    void addNode(const Type obj);

    /**
     * @brief Add edge between two nodes
     * @param objU Name of first node
     * @param objV Name of second node
     * @param weight Weight of edge
     */
    void addEdge(const Type& objU, const Type& objV, int weight);

    /**
     * @brief Starts MST (Prim-Jarnik)
     * @return Total distance
     */
    int startMST();

    /**
     * @brief Starts DFS and populates dfsOrder
     * @param start Starting node
     * @return Total cost (distance)
     */
    int startDFS(const Type& start);

    /**
     * @brief Starts BFS and populates bfsOrder
     * @param start Starting node
     * @return Total cost (distance)
     */
    int startBFS(const Type& start);

    /**
     * @brief Start Dijkstra from starting point to destination
     * @param start Starting node
     * @param dest Destination
     * @return Total distance travelled
     */
    int startDijkstra(const Type& start, const Type& dest);

    /**
     * @brief Start recursive Dijkstra (visits all given nodes)
     * Saves path order to dijkstraOrder
     * @param nodes All nodes to visit
     * @param start Starting node
     * @return Total distance travelled
     */
    int startMultiDijkstra(vector<Type> nodes, const Type& start);

    /**
     * @brief Finds shortest path to all nodes
     * Saves path in shortestOrder
     * @param start Starting node
     * @return Distance travelled
     */
    int startShortestPath(const Type& start);

    void clearGraph(); // New function to clear the graph

private:

    /**
     * @brief size number of nodes
     */
    int size;

    /**
     * @brief List of data associated with index
     */
    vector<Type> nodeList;

    /**
     * @brief Adjacency matrix
     */
    vector<vector<Edge>> adjMatrix;

    /**
     * @brief Helper function to get index of node
     * @param obj Object to be found
     * @return Index of obj
     */
    int getIndex(const Type& obj);

    /**
     * @brief DFS recursive function
     * @param v Starting node index
     * @param visited Keeps track of each visited node
     * @return Total cost (distance)
     */
    int dfs(int v, vector<bool>& visited);

    /**
     * @brief Dijkstra pathfinding algorithm
     * @param start Name of starting node
     * @return Two dimentional array hold data for paths
     */
    vector<vector<int>> DijkstraPaths(const Type& start);

    /**
     * @brief Recursively runs Dijkstra over nodes
     * @param nodes List of nodes to visit
     * @param start Starting node
     * @return Total distance
     */
    int multiDijkstra(vector<Type> nodes, const Type& start);

    /**
     * @brief Finds shortest path from node to node
     * @param start Starting node
     * @return Total distance
     */
    int shortestPath(const Type& start);

    /**
     * @brief Compares Edges (sorts in increasing order)
     * @param a Edge a
     * @param b Edge b
     * @return true if Edge a is less than b
     */
    static bool compareWeight(const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    }


};

#endif // GRAPH_H
