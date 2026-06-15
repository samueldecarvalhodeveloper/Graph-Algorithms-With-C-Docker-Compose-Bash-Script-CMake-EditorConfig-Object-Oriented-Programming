#include <iostream>
#include <vector>
#include "../../constants/graphs.h"
#include "./directed_acyclic_graph_shortest_path.cpp"

using namespace std;

namespace directed_acyclic_graph_shortest_path_client
{
    void execute()
    {
        directed_acyclic_graph_shortest_path graph(NUMBER_OF_VERTICES);

        for (const vector<int> &edge : GRAPH_WITH_WEIGHTS)
        {
            graph.add_edge(edge[0], edge[1], edge[2]);
        }

        const vector<int> list_of_shortest_path_to_all_destination_vertices = graph.get_list_of_shortest_paths(
            GRAPH_WITH_WEIGHTS[0][0]);

        cout << "Shortest Path From Vertex \"" << GRAPH_WITH_WEIGHTS[0][0] << "\" To \"" << GRAPH_WITH_WEIGHTS[0][1] << "\" Is: \"" << GRAPH_WITH_WEIGHTS[0][2] << "\"";
    }
}
