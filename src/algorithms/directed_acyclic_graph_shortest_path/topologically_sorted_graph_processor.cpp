#include <vector>
#include <climits>

using namespace std;

class topologically_sorted_graph_processor
{
private:
    explicit topologically_sorted_graph_processor()
    {
    }

public:
    static void execute(const int number_of_vertices, const vector<vector<int>> &list_of_adjacent_vertices,
                        vector<int> &list_of_shortest_path_weight_from_all_vertices,
                        vector<int> &list_of_topologically_sorted_vertices)
    {
        if (list_of_topologically_sorted_vertices.empty())
            return;

        const int current_vertex = list_of_topologically_sorted_vertices.back();

        list_of_topologically_sorted_vertices.pop_back();

        if (list_of_shortest_path_weight_from_all_vertices[current_vertex] != INT_MAX)
            for (int current_destination_vertex = 0; current_destination_vertex < number_of_vertices; current_destination_vertex++)
                if (list_of_adjacent_vertices[current_vertex][current_destination_vertex] != INT_MAX)
                {
                    const int edge_weight = list_of_adjacent_vertices[current_vertex][current_destination_vertex];

                    list_of_shortest_path_weight_from_all_vertices[current_destination_vertex] = min(
                        list_of_shortest_path_weight_from_all_vertices[current_vertex] + edge_weight,
                        list_of_shortest_path_weight_from_all_vertices[current_destination_vertex]);
                }

        execute(number_of_vertices, list_of_adjacent_vertices,
                list_of_shortest_path_weight_from_all_vertices,
                list_of_topologically_sorted_vertices);
    }
};
