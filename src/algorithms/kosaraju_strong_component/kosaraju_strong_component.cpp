#include <vector>
#include "./finished_order_depth_first_searcher.cpp"
#include "./graph_transposor.cpp"
#include "./transposed_graph_depth_first_searcher.cpp"

using namespace std;

class kosaraju_strong_component
{
private:
    int number_of_vertices;
    vector<vector<int>> list_of_adjacent_vertices;
    vector<vector<int>> list_of_transposed_adjacent_vertices;
    vector<bool> list_of_visited_vertices;
    vector<int> list_of_finished_order_of_vertices;

public:
    explicit kosaraju_strong_component(const int number_of_vertices)
    {
        this->number_of_vertices = number_of_vertices;

        list_of_adjacent_vertices.resize(number_of_vertices);
        list_of_transposed_adjacent_vertices.resize(number_of_vertices);
        list_of_visited_vertices.resize(number_of_vertices, false);
    }

    void add_edge(const int source_vertex, const int destination_vertex)
    {
        list_of_adjacent_vertices[source_vertex].push_back(destination_vertex);
    }

    vector<vector<int>> get_list_of_strong_connected_component()
    {
        for (int current_vertex = 0; current_vertex < number_of_vertices; ++current_vertex)
        {
            if (!list_of_visited_vertices[current_vertex])
                finished_order_depth_first_searcher::execute(current_vertex, list_of_visited_vertices, list_of_adjacent_vertices,
                                                             list_of_finished_order_of_vertices);
        }

        graph_transposor::execute(number_of_vertices, list_of_adjacent_vertices, list_of_transposed_adjacent_vertices);

        return transposed_graph_depth_first_searcher::get_list_of_strong_connected_components(
            list_of_visited_vertices, list_of_finished_order_of_vertices,
            list_of_transposed_adjacent_vertices);
    }
};
