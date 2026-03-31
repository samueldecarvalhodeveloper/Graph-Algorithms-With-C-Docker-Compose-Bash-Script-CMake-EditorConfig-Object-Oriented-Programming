#include <vector>

using namespace std;

class topological_sort_depth_first_searcher
{
private:
    explicit topological_sort_depth_first_searcher()
    {
    }

public:
    static void execute(const int current_vertex, vector<bool> &list_of_visited_vertices,
                        const vector<vector<int>> &list_of_adjacency_vertices,
                        vector<int> &list_of_sorted_vertices)
    {
        list_of_visited_vertices[current_vertex] = true;

        for (const int adjacent_vertex : list_of_adjacency_vertices[current_vertex])
        {
            if (!list_of_visited_vertices[adjacent_vertex])
                execute(adjacent_vertex, list_of_visited_vertices, list_of_adjacency_vertices,
                        list_of_sorted_vertices);
        }

        list_of_sorted_vertices.push_back(current_vertex);
    }
};
