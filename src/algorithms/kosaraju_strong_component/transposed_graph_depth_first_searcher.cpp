#include <vector>
#include <algorithm>
#include "./transposed_adjacent_vertex_depth_first_searcher.cpp"

using namespace std;

class transposed_graph_depth_first_searcher
{
private:
    explicit transposed_graph_depth_first_searcher()
    {
    }

public:
    static vector<vector<int>> get_list_of_strong_connected_components(vector<bool> &list_of_visited_vertices,
                                                                       vector<int> &list_of_finished_order_of_vertices,
                                                                       const vector<vector<int>> &
                                                                           list_of_transposed_adjacent_vertices)
    {
        vector<vector<int>> list_of_strong_connected_components;

        fill(list_of_visited_vertices.begin(), list_of_visited_vertices.end(), false);

        reverse(list_of_finished_order_of_vertices.begin(), list_of_finished_order_of_vertices.end());

        for (const int current_vertex : list_of_finished_order_of_vertices)
        {
            if (!list_of_visited_vertices[current_vertex])
            {
                vector<int> strong_component_vertices;

                transposed_adjacent_vertex_depth_first_searcher::execute(
                    current_vertex, strong_component_vertices, list_of_visited_vertices,
                    list_of_transposed_adjacent_vertices);

                list_of_strong_connected_components.push_back(strong_component_vertices);
            }
        }

        return list_of_strong_connected_components;
    }
};
