#include <iostream>
#include <vector>
#include "./topological_sort.cpp"
#include "../../constants/graphs.h"

using namespace std;

namespace topological_sort_client
{
    void execute()
    {
        topological_sort graph(NUMBER_OF_VERTICES);

        for (const vector<int> &edge : GRAPH)
        {
            graph.add_edge(edge[0], edge[1]);
        }

        const vector<int> list_of_sorted_vertices = graph.get_sorted_vertices();

        cout << "[ ";

        for (int i = 0; i < list_of_sorted_vertices.size(); i++)
        {
            if (i == list_of_sorted_vertices.size() - 1)
                cout << list_of_sorted_vertices[i];
            else
                cout << list_of_sorted_vertices[i] << ", ";
        }

        cout << " ]";
    }
}
