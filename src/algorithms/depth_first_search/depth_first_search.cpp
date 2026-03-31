#include <vector>
#include "./depth_first_vertex_edges_searcher.cpp"

using namespace std;

class depth_first_search
{
public:
    int number_of_vertices;
    vector<vector<int>> list_of_adjacency_vertices;

    explicit depth_first_search(const int number_of_vertices)
    {
        this->number_of_vertices = number_of_vertices;

        list_of_adjacency_vertices.resize(number_of_vertices);
    }

    void add_edge(const int source_vertex, const int destination_vertex)
    {
        list_of_adjacency_vertices[source_vertex].push_back(destination_vertex);

        list_of_adjacency_vertices[destination_vertex].push_back(source_vertex);
    }

    vector<int> get_all_edges(const int vertex)
    {
        vector<bool> visited_vertices(number_of_vertices);
        vector<int> list_of_adjacency_vertices_from_source;

        depth_first_vertex_edges_searcher::search_vertex_all_edges(
            vertex,
            visited_vertices,
            list_of_adjacency_vertices,
            list_of_adjacency_vertices_from_source);

        return list_of_adjacency_vertices_from_source;
    }
};
