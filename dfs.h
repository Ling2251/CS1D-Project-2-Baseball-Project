#ifndef DFS_H
#define DFS_H

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

struct Edge
{
unsigned int origin;
unsigned int destination;
unsigned int distance;
};

typedef pair<int, int> Pair;

const string originNames[] =
{
    "Angel Stadium",
    "Busch Stadium",
    "Chase Field",
    "Citi Field",
    "Citizens Bank Park",
    "Comerica Park",
    "Coors Field",
    "Dodger Stadium",
    "Fenway Park",
    "Globe Life Park in Arlington",
    "Great American Ball Park",
    "Guaranteed Rate Field",
    "Kauffman Stadium",
    "Marlins Park",
    "Miller Park",
    "Minute Maid Park",
    "Nationals Park",
    "Oakland-Alameda County Coliseum",
    "Oracle Park",
    "Oriole Park at Camden Yards",
    "Petco Park",
    "PNC Park",
    "Progressive Field",
    "Rogers Centre",
    "Safeco Field",
    "SunTrust Park",
    "Target Field",
    "Tropicana Field",
    "Wrigley Field",
    "Yankee Stadium"
};


class Graph
{
public:
Graph(vector<Edge> &edges, unsigned int num);
void DFS(unsigned int num, unsigned int startFrom);
void printGraph(unsigned int num)const;

private:
vector< vector<Pair> > adjList; // Adjacent List
void DFS_TRAVERSAL(unsigned int current, vector<bool> &visited, vector<Pair> & route, int &dist);
};


Graph::Graph(vector<Edge> &edges, unsigned int num)
{
// Resizes the vector to num number of elements of type vector<Pair>
adjList.resize(num);

// this for will traverses through the vector of edges and pushes the link between the origin and destination to the adjacency list
for(auto &edge : edges)
{
unsigned int origin = edge.origin;
unsigned int destination = edge.destination;
unsigned int distance = edge.distance;

adjList[origin].push_back(make_pair(destination, distance));
adjList[destination].push_back(make_pair(origin, distance));
}
}

void Graph::printGraph(unsigned int num)const
{
  for(unsigned int i = 0; i < num; i++)
  {
      cout << "Starting stadium : " << originNames[i];
  }
}


#endif // DFS_H
