#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class graph_edges_relaxer
{
private:
    explicit graph_edges_relaxer()
    {
    }

public:
    static void relax_vertex_edges(const int number_of_vertices, const int current_vertex,
                                   const vector<vector<int>> &list_of_adjacent_vertices,
                                   vector<vector<int>> &list_of_vertices_minimum_distance,
                                   vector<int> &list_of_visited_vertices,
                                   vector<int> &list_of_all_edge_weights)
    {
        for (int destination_vertex = 0; destination_vertex < number_of_vertices; destination_vertex++)
        {
            const int weight_of_edge = list_of_adjacent_vertices[current_vertex][destination_vertex];

            if (weight_of_edge != INT_MAX &&
                find(list_of_visited_vertices.begin(), list_of_visited_vertices.end(), destination_vertex) ==
                    list_of_visited_vertices.end() &&
                weight_of_edge < list_of_all_edge_weights[destination_vertex])
            {
                list_of_all_edge_weights[destination_vertex] = weight_of_edge;

                list_of_vertices_minimum_distance.push_back({list_of_all_edge_weights[destination_vertex], destination_vertex});
            }
        }
    }
};
