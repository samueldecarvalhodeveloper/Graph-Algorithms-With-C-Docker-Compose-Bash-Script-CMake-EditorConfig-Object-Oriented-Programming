#include <vector>
#include <climits>
#include "./dijkstra_shortest_path_parser.cpp"

using namespace std;

class dijkstra_shortest_path
{
private:
    int number_of_vertices;
    vector<vector<int>> list_of_adjacent_vertices;

public:
    explicit dijkstra_shortest_path(const int number_of_vertices)
    {
        this->number_of_vertices = number_of_vertices;

        list_of_adjacent_vertices.resize(number_of_vertices, vector<int>(number_of_vertices, INT_MAX));
    }

    void add_edge(const int source_vertex, const int destination_vertex, const int edge_weight)
    {
        list_of_adjacent_vertices[source_vertex][destination_vertex] = edge_weight;
    }

    vector<int> get_list_of_shortest_paths(int source_vertex)
    {
        vector<vector<int>> list_of_edge_weights;
        vector<int> list_of_shortest_path_weight_from_all_vertices(number_of_vertices, INT_MAX);

        list_of_shortest_path_weight_from_all_vertices[source_vertex] = 0;

        list_of_edge_weights.push_back({0, source_vertex});

        dijkstra_shortest_path_parser::get_shortest_path(number_of_vertices, list_of_edge_weights,
                                                         list_of_adjacent_vertices,
                                                         list_of_shortest_path_weight_from_all_vertices);

        return list_of_shortest_path_weight_from_all_vertices;
    }
};
