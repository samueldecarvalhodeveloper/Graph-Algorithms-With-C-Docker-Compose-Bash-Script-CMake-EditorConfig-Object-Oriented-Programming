#include <vector>
#include <climits>

using namespace std;

class bellman_ford_shortest_path
{
private:
    int number_of_vertices;
    vector<vector<int>> list_of_adjacent_vertices;

public:
    explicit bellman_ford_shortest_path(const int number_of_vertices)
    {
        this->number_of_vertices = number_of_vertices;

        list_of_adjacent_vertices.resize(number_of_vertices, vector<int>(number_of_vertices, INT_MAX));
    }

    void add_edge(const int source_vertex, const int destination_vertex, const int edge_weight)
    {
        list_of_adjacent_vertices[source_vertex][destination_vertex] = edge_weight;
    }

    vector<int> get_list_of_shortest_paths(const int source_vertex)
    {
        vector<int> list_of_shortest_path_weight_from_all_vertices(number_of_vertices, INT_MAX);

        list_of_shortest_path_weight_from_all_vertices[source_vertex] = 0;

        for (int current_vertex = 0; current_vertex < number_of_vertices - 1; current_vertex++)
            for (int current_destination_vertex = 0; current_destination_vertex < number_of_vertices; current_destination_vertex++)
                if (list_of_adjacent_vertices[current_vertex][current_destination_vertex] != INT_MAX)
                {
                    const int edge_weight = list_of_adjacent_vertices[current_vertex][current_destination_vertex];

                    if (list_of_shortest_path_weight_from_all_vertices[current_vertex] != INT_MAX &&
                        list_of_shortest_path_weight_from_all_vertices[current_vertex] + edge_weight <
                            list_of_shortest_path_weight_from_all_vertices[current_destination_vertex])
                        list_of_shortest_path_weight_from_all_vertices[current_destination_vertex] =
                            list_of_shortest_path_weight_from_all_vertices[current_vertex] + edge_weight;
                }

        return list_of_shortest_path_weight_from_all_vertices;
    }
};
