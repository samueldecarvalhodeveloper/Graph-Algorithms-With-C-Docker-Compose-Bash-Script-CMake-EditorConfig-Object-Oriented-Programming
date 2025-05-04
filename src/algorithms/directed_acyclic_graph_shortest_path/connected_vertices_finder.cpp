#include <vector>
#include <climits>

using namespace std;

class connected_vertices_finder
{
private:
    explicit connected_vertices_finder()
    {
    }

public:
    static void find_all_connected_vertices(const int current_vertex, const int number_of_vertices,
                                            const vector<vector<int>> &list_of_adjacent_vertices,
                                            vector<bool> &list_of_visited_vertices,
                                            vector<int> &list_of_topologically_sorted_vertices)
    {
        list_of_visited_vertices[current_vertex] = true;

        for (int current_destination_vertex = 0; current_destination_vertex < number_of_vertices; current_destination_vertex++)
            if (list_of_adjacent_vertices[current_vertex][current_destination_vertex] != INT_MAX && !list_of_visited_vertices[current_destination_vertex])
                find_all_connected_vertices(current_destination_vertex, number_of_vertices, list_of_adjacent_vertices, list_of_visited_vertices,
                                            list_of_topologically_sorted_vertices);

        list_of_topologically_sorted_vertices.push_back(current_vertex);
    }
};
