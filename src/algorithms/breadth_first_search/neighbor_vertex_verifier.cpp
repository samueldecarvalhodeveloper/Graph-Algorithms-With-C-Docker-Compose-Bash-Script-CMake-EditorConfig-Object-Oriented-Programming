#include <vector>

using namespace std;

class neighbor_vertex_verifier
{
private:
    explicit neighbor_vertex_verifier()
    {
    }

public:
    static void verify_neighbors_vertices(
        const int vertex_being_processed,
        vector<bool> &list_of_visited_vertices,
        const vector<vector<int>> &list_of_adjacency_vertices,
        vector<int> &list_of_adjacency_vertices_from_source,
        vector<int> &list_of_vertices_to_explore)
    {
        for (const int neighbor_vertex : list_of_adjacency_vertices[vertex_being_processed])
        {
            if (!list_of_visited_vertices[neighbor_vertex])
            {
                list_of_visited_vertices[neighbor_vertex] = true;

                list_of_adjacency_vertices_from_source.push_back(neighbor_vertex);

                list_of_vertices_to_explore.push_back(neighbor_vertex);
            }
        }
    }
};
