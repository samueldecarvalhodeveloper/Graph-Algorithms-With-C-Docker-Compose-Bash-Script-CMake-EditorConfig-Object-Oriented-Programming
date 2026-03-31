#include <vector>
#include <algorithm>
#include "./smallest_edge_weight_finder.cpp"
#include "./graph_edges_relaxer.cpp"

using namespace std;

class graph_minimum_spanning_tree_parser
{
private:
    explicit graph_minimum_spanning_tree_parser()
    {
    }

public:
    static int get_parsed_graph_edges_minimum_spanning_tree_weight(
        const int number_of_vertices,
        const vector<vector<int>> &list_of_adjacent_vertices,
        vector<vector<int>> &list_of_vertices_minimum_distance,
        vector<int> &list_of_visited_vertices,
        vector<int> &list_of_all_edge_weights,
        int minimum_spanning_tree_weight = 0)
    {
        if (list_of_vertices_minimum_distance.empty())
            return minimum_spanning_tree_weight;

        const int vertex_with_smallest_weight = smallest_edge_weight_finder::get_edge_with_smallest_weight(list_of_vertices_minimum_distance);
        int current_vertex = list_of_vertices_minimum_distance[vertex_with_smallest_weight][1];

        list_of_vertices_minimum_distance.erase(
            list_of_vertices_minimum_distance.begin() + vertex_with_smallest_weight);

        if (find(list_of_visited_vertices.begin(), list_of_visited_vertices.end(), current_vertex) !=
            list_of_visited_vertices.end())
            return get_parsed_graph_edges_minimum_spanning_tree_weight(
                number_of_vertices, list_of_adjacent_vertices,
                list_of_vertices_minimum_distance, list_of_visited_vertices,
                list_of_all_edge_weights, minimum_spanning_tree_weight);

        list_of_visited_vertices.push_back(current_vertex);

        minimum_spanning_tree_weight += list_of_all_edge_weights[current_vertex];

        graph_edges_relaxer::relax_vertex_edges(
            number_of_vertices, current_vertex, list_of_adjacent_vertices,
            list_of_vertices_minimum_distance, list_of_visited_vertices,
            list_of_all_edge_weights);

        return get_parsed_graph_edges_minimum_spanning_tree_weight(
            number_of_vertices, list_of_adjacent_vertices,
            list_of_vertices_minimum_distance, list_of_visited_vertices,
            list_of_all_edge_weights, minimum_spanning_tree_weight);
    }
};
