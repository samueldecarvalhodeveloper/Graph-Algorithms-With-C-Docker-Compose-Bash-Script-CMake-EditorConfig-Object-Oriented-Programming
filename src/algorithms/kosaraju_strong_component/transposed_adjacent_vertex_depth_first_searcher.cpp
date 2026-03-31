#include <vector>

using namespace std;

class transposed_adjacent_vertex_depth_first_searcher
{
private:
    explicit transposed_adjacent_vertex_depth_first_searcher()
    {
    }

public:
    static void execute(const int current_vertex, vector<int> &strong_component_vertices,
                        vector<bool> &list_of_visited_vertices,
                        const vector<vector<int>> &list_of_transposed_adjacent_vertices)
    {
        list_of_visited_vertices[current_vertex] = true;

        strong_component_vertices.push_back(current_vertex);

        for (const int vertex_neighbor : list_of_transposed_adjacent_vertices[current_vertex])
        {
            if (!list_of_visited_vertices[vertex_neighbor])
                execute(vertex_neighbor, strong_component_vertices,
                        list_of_visited_vertices,
                        list_of_transposed_adjacent_vertices);
        }
    }
};
