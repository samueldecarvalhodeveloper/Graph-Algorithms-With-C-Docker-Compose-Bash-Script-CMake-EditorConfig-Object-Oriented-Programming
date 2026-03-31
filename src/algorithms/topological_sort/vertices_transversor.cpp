#include <vector>
#include "./topological_sort_depth_first_searcher.cpp"

using namespace std;

class vertices_transversor
{
private:
    explicit vertices_transversor()
    {
    }

public:
    static void traverse_all_vertices(const int number_of_vertices, vector<bool> &list_of_visited_vertices,
                                      const vector<vector<int>> &list_of_adjacency_vertices,
                                      vector<int> &list_of_sorted_vertices)
    {
        for (int current_vertex = 0; current_vertex < number_of_vertices; current_vertex++)
            if (!list_of_visited_vertices[current_vertex])
                topological_sort_depth_first_searcher::execute(current_vertex, list_of_visited_vertices,
                                                               list_of_adjacency_vertices,
                                                               list_of_sorted_vertices);
    }
};
