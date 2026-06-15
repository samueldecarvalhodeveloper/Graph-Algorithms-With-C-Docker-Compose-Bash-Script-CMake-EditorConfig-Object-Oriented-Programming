#include <vector>

using namespace std;

class finished_order_depth_first_searcher
{
private:
    explicit finished_order_depth_first_searcher()
    {
    }

public:
    static void execute(const int current_vertex, vector<bool> &list_of_visited_vertices,
                        const vector<vector<int>> &list_of_adjacent_vertices,
                        vector<int> &list_of_finished_order_of_vertices)
    {
        list_of_visited_vertices[current_vertex] = true;

        for (const int vertex_neighbor : list_of_adjacent_vertices[current_vertex])
        {
            if (!list_of_visited_vertices[vertex_neighbor])
                execute(vertex_neighbor, list_of_visited_vertices, list_of_adjacent_vertices,
                        list_of_finished_order_of_vertices);
        }

        list_of_finished_order_of_vertices.push_back(current_vertex);
    }
};
