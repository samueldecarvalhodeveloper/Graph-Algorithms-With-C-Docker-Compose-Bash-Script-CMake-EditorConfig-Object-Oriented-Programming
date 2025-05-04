#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class dijkstra_shortest_path_parser
{
private:
    explicit dijkstra_shortest_path_parser()
    {
    }

public:
    static void get_shortest_path(const int number_of_vertices, vector<vector<int>> &list_of_edge_weights,
                                  const vector<vector<int>> &list_of_adjacent_vertices,
                                  vector<int> &list_of_shortest_path_weight_from_all_vertices)
    {
        if (list_of_edge_weights.empty())
            return;

        sort(list_of_edge_weights.begin(), list_of_edge_weights.end());

        const int current_vertex = list_of_edge_weights.front()[1];

        list_of_edge_weights.erase(list_of_edge_weights.begin());

        for (int destination_vertex = 0; destination_vertex < number_of_vertices; ++destination_vertex)
        {
            const int edge_weight = list_of_adjacent_vertices[current_vertex][destination_vertex];

            if (edge_weight != INT_MAX &&
                list_of_shortest_path_weight_from_all_vertices[current_vertex] != INT_MAX &&
                list_of_shortest_path_weight_from_all_vertices[current_vertex] + edge_weight <
                    list_of_shortest_path_weight_from_all_vertices[destination_vertex])
            {
                list_of_shortest_path_weight_from_all_vertices[destination_vertex] =
                    list_of_shortest_path_weight_from_all_vertices[current_vertex] + edge_weight;

                list_of_edge_weights.push_back({list_of_shortest_path_weight_from_all_vertices[destination_vertex], destination_vertex});
            }
        }

        get_shortest_path(number_of_vertices, list_of_edge_weights, list_of_adjacent_vertices,
                          list_of_shortest_path_weight_from_all_vertices);
    }
};
