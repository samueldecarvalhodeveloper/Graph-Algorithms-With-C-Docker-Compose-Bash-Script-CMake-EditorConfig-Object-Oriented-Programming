#include <vector>
#include <climits>
#include "./connected_vertices_finder.cpp"
#include "./topologically_sorted_graph_processor.cpp"
using namespace std;

class directed_acyclic_graph_shortest_path
{
private:
    int number_of_vertices;
    vector<vector<int>> list_of_adjacent_vertices;

public:
    explicit directed_acyclic_graph_shortest_path(const int number_of_vertices)
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
        vector<int> list_of_topologically_sorted_vertices;
        vector<bool> list_of_visited_vertices(number_of_vertices, false);

        list_of_shortest_path_weight_from_all_vertices[source_vertex] = 0;

        for (int current_vertex = 0; current_vertex < number_of_vertices; current_vertex++)
            if (!list_of_visited_vertices[current_vertex])
                connected_vertices_finder::find_all_connected_vertices(current_vertex, number_of_vertices,
                                                                       list_of_adjacent_vertices,
                                                                       list_of_visited_vertices,
                                                                       list_of_topologically_sorted_vertices);

        topologically_sorted_graph_processor::execute(number_of_vertices, list_of_adjacent_vertices,
                                                      list_of_shortest_path_weight_from_all_vertices,
                                                      list_of_topologically_sorted_vertices);

        return list_of_shortest_path_weight_from_all_vertices;
    }
};
