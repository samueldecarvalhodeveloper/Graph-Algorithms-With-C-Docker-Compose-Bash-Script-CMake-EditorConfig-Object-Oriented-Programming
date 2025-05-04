#include <vector>

using namespace std;

class graph_transposor
{
private:
    explicit graph_transposor()
    {
    }

public:
    static void execute(const int number_of_vertices, const vector<vector<int>> &list_of_adjacent_vertices,
                        vector<vector<int>> &list_of_transposed_adjacent_vertices)
    {
        for (int current_vertex = 0; current_vertex < number_of_vertices; ++current_vertex)
            for (const int vertex_neighbor : list_of_adjacent_vertices[current_vertex])
                list_of_transposed_adjacent_vertices[vertex_neighbor].push_back(current_vertex);
    }
};
