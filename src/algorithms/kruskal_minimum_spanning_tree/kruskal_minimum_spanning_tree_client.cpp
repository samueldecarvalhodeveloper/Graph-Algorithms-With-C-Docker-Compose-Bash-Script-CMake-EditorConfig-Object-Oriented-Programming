#include <iostream>
#include "./kruskal_minimum_spanning_tree.cpp"
#include "../../constants/graphs.h"

namespace kruskal_minimum_spanning_tree_client
{
    void execute()
    {
        kruskal_minimum_spanning_tree graph(NUMBER_OF_VERTICES);

        for (vector<int> edge : GRAPH_WITH_WEIGHTS)
        {
            graph.add_edge(edge[0], edge[1], edge[2]);
        }

        int minimum_spanning_tree_weight = graph.get_minimum_spanning_tree_weight();

        cout << "Minimum Spanning Tree Weight: \"" << minimum_spanning_tree_weight << "\"";
    }
}
