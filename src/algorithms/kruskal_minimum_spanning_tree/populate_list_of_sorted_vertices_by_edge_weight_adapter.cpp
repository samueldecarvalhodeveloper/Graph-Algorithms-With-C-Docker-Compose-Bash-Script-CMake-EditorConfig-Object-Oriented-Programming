#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class populate_list_of_sorted_vertices_by_edge_weight_adapter
{
private:
    explicit populate_list_of_sorted_vertices_by_edge_weight_adapter()
    {
    }

public:
    static void populate_list_of_sorted_vertices_by_edge_weight(const int number_of_vertices,
                                                                vector<vector<int>> &list_of_adjacent_vertices,
                                                                vector<vector<int>> &
                                                                    list_of_sorted_vertices_by_edge_weight)
    {
        for (int current_vertex = 0; current_vertex < number_of_vertices; ++current_vertex)
        {
            for (int destination_vertex = current_vertex + 1; destination_vertex < number_of_vertices; ++destination_vertex)
            {
                if (list_of_adjacent_vertices[current_vertex][destination_vertex] != INT_MAX)
                    list_of_sorted_vertices_by_edge_weight.push_back({current_vertex, destination_vertex, list_of_adjacent_vertices[current_vertex][destination_vertex]});
            }
        }

        sort(list_of_sorted_vertices_by_edge_weight.begin(), list_of_sorted_vertices_by_edge_weight.end(), [](const vector<int> &current_vertices_edge, const vector<int> &next_vertices_edge)
             { return current_vertices_edge[2] < next_vertices_edge[2]; });
    }
};
