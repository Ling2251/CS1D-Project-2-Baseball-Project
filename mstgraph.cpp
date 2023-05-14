#include "mstgraph.h"

/* Functions returns weight of the MST*/

int Graph::kruskalMST()
{
    int mst_wt = 0; // Initialize result

    // Sort edges in increasing order on basis of cost
    sort(edges.begin(), edges.end());

    // Extract all cities
    vector<string> cities;
    for (const auto& e : edges) {
        cities.push_back(e.second.first);
        cities.push_back(e.second.second);
    }
    sort(cities.begin(), cities.end());
    cities.erase(unique(cities.begin(), cities.end()), cities.end());

    // Create disjoint sets
    DisjointSets ds(cities);

    // Iterate through all sorted edges
    for (const auto& e : edges)
    {
        int weight = e.first;
        string src = e.second.first;
        string dest = e.second.second;

        string set_src = ds.find(src);
        string set_dest = ds.find(dest);

        // Check if the selected edge is creating
        // a cycle or not (Cycle is created if src
        // and dest belong to same set)
        if (set_src != set_dest)
        {
            // Current edge will be in the MST
            // so print it with its weight
            cout << src << " - " << dest << " : " << weight << endl;

            // Update MST weight
            mst_wt += weight;

            // Merge two sets
            ds.merge(set_src, set_dest);
        }
    }

    return mst_wt;
}
