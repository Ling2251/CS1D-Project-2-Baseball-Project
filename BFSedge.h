#ifndef BFSEDGE_H_
#define BFSEDGE_H_
 #include <iostream>
 #include <vector>
 #include <queue>
 #include <string>
 #include <iomanip>
 #include <algorithm>
 #include <cstring>
 using namespace std;

 class Vertex
 {
 public:

 // constrcutor
 Vertex()
 {
 // this vertex = 0 and visited assign to false
 vertex = 0;
 visited = false;
 }

 // set function to set vertex from main
 void setVertex(int _vertex)
 {
 // assing vertex
 vertex = _vertex;
 }

 // change visited status function
 void changeVertexType(bool _visited)
 {
 // assign visited to a boolean value
 visited = _visited;
 }

 // verify function
 bool isVisited()const
 {
 // return boolean value
 return visited;
 }

 // get function to return the vertex value
 int getVertex()const
 {
 return vertex;
 }
 private:
 int vertex; // Vertex in the graph
 bool visited; // Whether or not the vertex has been visited
 };


 enum EdgeType
 {
 UNEXPLORED, // Unexplored edge
 DISCOVERY, // Discovery edge (edge leading to a new/unvisited vertex)
 CROSS // Cross edge (edge leading to an already visited vertex)
 };


 /*
 class BFSEdge
 This class represents a BFSEdge object. It manages four attributes: weight,
 origin, destination, type
 */
 class BFSEdge
 {
 public:

 //constructor
 BFSEdge()
 {
 //initialize weight and type
 weight = 0;
 type = UNEXPLORED;
 }

 // constructor
 BFSEdge(int _weight, int _destination, int _origin)
 {
 //assign value from main
 weight = _weight;
 origin.setVertex(_origin);
 destination.setVertex(_destination);
 type = UNEXPLORED;
 }

 // change function call from vertex class
 void changeVertexType(bool _visited)
 {
 destination.changeVertexType(_visited);
 }

 void changeEdgeType(EdgeType _type)
 {
 type = _type;
 }

 // verify function
 bool isVisited()const
 {
 return (destination.isVisited());
 }

 EdgeType edgeType()const
 {
 return type;
 }
 int getDistance()const
 {
 return weight;
 }
 int getDestination()const
 {
 return destination.getVertex();
 }
 int getOrigin()const
 {
 return origin.getVertex();
 }

 private:
 int weight; // distance between two vertices/weight of the edge
 Vertex origin; // the city of origin/start vertex
 Vertex destination; // the destination city/opposite vertex
 EdgeType type; // the edge type -> unexplored, discovery, or cross
 };
 #endif
