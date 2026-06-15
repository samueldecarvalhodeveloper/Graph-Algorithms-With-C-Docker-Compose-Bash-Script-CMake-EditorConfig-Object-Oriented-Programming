#include <vector>
#include <climits>
#include "./graph_minimum_spanning_tree_parser.cpp"

using namespace std;

class prim_minimum_spanning_tree
{
private:
    int number_of_vertices;
    vector<vector<int>> list_of_adjacent_vertices;

public:
    explicit prim_minimum_spanning_tree(const int number_of_vertices)
    {
        this->number_of_vertices = number_of_vertices;

        list_of_adjacent_vertices.resize(number_of_vertices, vector<int>(number_of_vertices, INT_MAX));
    }

    void add_edge(const int source_vertex, const int destination_vertex, const int edge_weight)
    {
        list_of_adjacent_vertices[source_vertex][destination_vertex] = edge_weight;

        list_of_adjacent_vertices[destination_vertex][source_vertex] = edge_weight;
    }

    int get_minimum_spanning_tree_weight()
    {
        vector<int> list_of_visited_vertices;
        vector<vector<int>> list_of_vertices_minimum_distance;
        vector<int> list_of_all_edge_weights(number_of_vertices, INT_MAX);

        list_of_all_edge_weights[0] = 0;

        list_of_vertices_minimum_distance.push_back({0, 0});

        return graph_minimum_spanning_tree_parser::get_parsed_graph_edges_minimum_spanning_tree_weight(
            number_of_vertices, list_of_adjacent_vertices,
            list_of_vertices_minimum_distance, list_of_visited_vertices,
            list_of_all_edge_weights);
    }
};
