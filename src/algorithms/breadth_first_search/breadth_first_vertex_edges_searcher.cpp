#include <vector>
#include "./neighbor_vertex_verifier.cpp"

using namespace std;

class breadth_first_vertex_edges_searcher
{
private:
    explicit breadth_first_vertex_edges_searcher()
    {
    }

public:
    static void search_vertex_all_edges(
        const int current_vertex,
        vector<bool> &list_of_visited_vertices,
        const vector<vector<int>> &list_of_adjacency_vertices,
        vector<int> &list_of_adjacency_vertices_from_source)
    {
        vector<int> list_of_vertices_to_explore;

        list_of_visited_vertices[current_vertex] = true;

        list_of_adjacency_vertices_from_source.push_back(current_vertex);

        list_of_vertices_to_explore.push_back(current_vertex);

        for (int current_vertex_being_processed_index = 0; current_vertex_being_processed_index < list_of_vertices_to_explore.size(); ++current_vertex_being_processed_index)
        {
            const int vertex_being_processed = list_of_vertices_to_explore[current_vertex_being_processed_index];

            neighbor_vertex_verifier::verify_neighbors_vertices(
                vertex_being_processed,
                list_of_visited_vertices,
                list_of_adjacency_vertices,
                list_of_adjacency_vertices_from_source,
                list_of_vertices_to_explore);
        }
    }
};
