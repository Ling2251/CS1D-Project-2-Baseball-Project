#ifndef GRAPHBFS_H_
#define GRAPHBFS_H_
#include "BFSEdge.h"

    const string originStadiumNames[] =
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

    typedef pair<int, int> Pair;
    /*******************************************************************************
    * class GraphBFS
    * This class represents a GraphBFS object. It manages two attributes: size,
    * adjMatrix
    *******************************************************************************/
    class GraphBFS
    {
    public:

    //constructor
    GraphBFS(vector<BFSEdge> &BFSEdges, int size)
    {
    // Initializes variables
    this->size = size;

    // Creates dynamic array of pointers
    adjMatrix = new BFSEdge*[size];

    // Creates a row for every pointer
    for (int i = 0; i < size; i++)
    {
    adjMatrix[i] = new BFSEdge[size];

    // Initializes all entries to 0 to indicate no BFSEdge between the two
    // vertices
    memset(adjMatrix[i], 0, size * sizeof(BFSEdge));
    }

    // Inserts all the BFSEdges into the matrix
    for (auto &BFSEdge : BFSEdges)
    {
    int origin = BFSEdge.getOrigin();
    int destination = BFSEdge.getDestination();

    adjMatrix[origin][destination] = BFSEdge;
    }
    }

    void BFS(int start)
    {
    // Declaring & Initializing variables
    int current = start; // IN - starting index
    int distance = 0; // CALC - the distance traveled on the discovery BFSEdges
    vector<Pair> route; // IN - the order of the cities traveled in the BFS

    BFS_Utility(current, route, distance);

    // Displays the results of the DFS
    cout << endl << endl;
    cout << "DFS Starting from " << originStadiumNames[start] << ":" << endl;
    cout << originStadiumNames[start] << " -> ";

    for (unsigned i = 0; i < route.size(); i++)
    {
    cout << originStadiumNames[route[i].first];

    if (i < route.size() - 1)
    {
    cout << " -> ";
    }
    }
    cout << endl << endl;

    cout << "The total miles of the discovery edges useing BFS is: " << distance <<
    endl;

    }

    private:
    int size; // Size of matrix (num of vertices)
    BFSEdge **adjMatrix; // Adjacency Matrix

    void BFS_Utility(int current, vector<Pair> &route, int &distance)
    {
    // Declaring variables
    vector<Pair> path; // PROC - contains the adjacent vertices to sort them
    queue<int> vertices; // PROC - contains the vertices in the order visited

    // setting the current vertex to be visited
    for (int i = 0; i < size; i++)
    {

    adjMatrix[i][current].changeVertexType(true);

    }

    // Loops while all vertices have not been visited yet
    do
    {
    // inserts the adjacent vertices in path as a pair
    // (distance, destination)
    for (int col = 0; col < size; col++)
    {
    if (adjMatrix[current][col].getDistance() != 0)
    {
    path.push_back(Pair(adjMatrix[current][col].getDistance(),
    adjMatrix[current][col].getDestination()));
    }
    }

    // sorts the vertices by their distance in ascending order
    // (shortest to longest distance)
    sort(path.begin(), path.end());

    // Loops for all the adjacent vertices
    for (unsigned col = 0; col < path.size(); col++)
    {
    // If the adjacent vertex has yet to be visited
    if (!adjMatrix[current][path[col].second].isVisited())
    {
    // adds the new visited BFSEdge/vertex to the route
    route.push_back(Pair(path[col].second, path[col].first));

    // adds the new vertex to the vertices visited
    vertices.push(path[col].second);

    // adds the distance of the BFSEdge to the total
    // distance traveled
    distance += path[col].first;

    // sets the vertex to visited
    for (int i = 0; i < size; i++)
    {

    adjMatrix[i][path[col].second].changeVertexType(true);

    }

    // sets BFSEdge to discovery from unexplored
    adjMatrix[current]
    [path[col].second].changeEdgeType(DISCOVERY);

    adjMatrix[path[col].second]
    [current].changeEdgeType(DISCOVERY);

    // displays the information of the discovery BFSEdge
    cout << left << setw(10) << "Discovery" << "BFSEdge: "
    << left << setw(14) << originStadiumNames[current] << " -> "
    << left << setw(15)
    << originStadiumNames[path[col].second]
    << " (Distance: " << path[col].first << ")" << endl;
    }
    // If the vertex has been visited and the BFSEdge is unexplored
    else if (adjMatrix[current][path[col].second].edgeType() == UNEXPLORED)
    {
    // sets BFSEdge to cross
    adjMatrix[current][path[col].second].changeEdgeType(CROSS);
    adjMatrix[path[col].second][current].changeEdgeType(CROSS);

    // displays the information of the cross BFSEdge
    cout << left << setw(10) << "Cross" << "BFSEdge: ";
    cout << left << setw(14) << originStadiumNames[current] << " -> "
    << left << setw(15)
    << originStadiumNames[path[col].second]
    << " (Distance: " << path[col].first << ")" << endl;
    }
    }
    // Sets the current vertex to the first vertex from the given level
    current = vertices.front();

    // Deletes that vertex from the queue to indicate it has been used
    vertices.pop();

    // PROC -- empties the vector that holds the adjacent vertices of the
    // previous vertex
    while (!path.empty())
    {
    path.pop_back();
    }
    } while (!vertices.empty());
    }
    };
    #endif
