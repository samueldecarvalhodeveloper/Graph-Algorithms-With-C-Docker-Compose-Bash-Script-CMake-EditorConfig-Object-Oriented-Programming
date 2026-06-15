#include <vector>
#include "./vertices_transversor.cpp"
#include "./graph_reverser.cpp"

using namespace std;

class topological_sort
{
private:
    int number_of_vertices;
    vector<vector<int>> list_of_adjacency_vertices;

public:
    explicit topological_sort(const int total_vertices)
    {
        this->number_of_vertices = total_vertices;
        list_of_adjacency_vertices.resize(total_vertices);
    }

    void add_edge(const int source_vertex, const int destination_vertex)
    {
        list_of_adjacency_vertices[source_vertex].push_back(destination_vertex);
    }

    vector<int> get_sorted_vertices()
    {
        vector<bool> list_of_visited_vertices(number_of_vertices, false);
        vector<int> list_of_sorted_vertices;

        vertices_transversor::traverse_all_vertices(number_of_vertices, list_of_visited_vertices,
                                                    list_of_adjacency_vertices,
                                                    list_of_sorted_vertices);

        return graph_reverser::get_reversed_order_graph(list_of_sorted_vertices);
    }
};
