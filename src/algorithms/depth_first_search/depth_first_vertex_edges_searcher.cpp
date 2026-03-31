#include <vector>

using namespace std;

class depth_first_vertex_edges_searcher
{
private:
    explicit depth_first_vertex_edges_searcher()
    {
    }

public:
    static void search_vertex_all_edges(
        const int current_vertex,
        vector<bool> &list_of_visited_vertices,
        vector<vector<int>> &list_of_adjacency_vertices,
        vector<int> &list_of_adjacency_vertices_from_source)
    {
        list_of_visited_vertices[current_vertex] = true;

        list_of_adjacency_vertices_from_source.push_back(current_vertex);

        for (const int neighbor_vertex : list_of_adjacency_vertices[current_vertex])
        {
            if (!list_of_visited_vertices[neighbor_vertex])
                search_vertex_all_edges(
                    neighbor_vertex,
                    list_of_visited_vertices,
                    list_of_adjacency_vertices,
                    list_of_adjacency_vertices_from_source);
        }
    }
};
