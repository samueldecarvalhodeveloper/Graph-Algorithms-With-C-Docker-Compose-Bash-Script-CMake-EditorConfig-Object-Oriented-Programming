#include <iostream>
#include "./depth_first_search.cpp"
#include "../../constants/graphs.h"

using namespace std;

namespace depth_first_search_client
{
    void execute()
    {
        depth_first_search graph(NUMBER_OF_VERTICES);

        for (vector<int> edge : GRAPH)
        {
            graph.add_edge(edge[0], edge[1]);
        }

        const vector<int> list_of_edges_from_vertex = graph.get_all_edges(GRAPH[0][0]);

        cout << "[ ";

        for (int i = 0; i < list_of_edges_from_vertex.size(); i++)
        {
            if (i == list_of_edges_from_vertex.size() - 1)
                cout << list_of_edges_from_vertex[i];
            else
                cout << list_of_edges_from_vertex[i] << ", ";
        }

        cout << " ]";
    }
}
