#include <vector>
#include <climits>
#include "./populate_list_of_sorted_vertices_by_edge_weight_adapter.cpp"
#include "./minimum_spanning_tree_constructor.cpp"

using namespace std;

class kruskal_minimum_spanning_tree
{
private:
    int number_of_vertices;
    vector<vector<int>> list_of_adjacent_vertices;

public:
    explicit kruskal_minimum_spanning_tree(const int number_of_vertices)
    {
        this->number_of_vertices = number_of_vertices;

        list_of_adjacent_vertices.resize(number_of_vertices, vector<int>(number_of_vertices, INT_MAX));
    }

    void add_edge(const int source_vertex, const int destination_vertex, const int edge_weight)
    {
        list_of_adjacent_vertices[source_vertex][destination_vertex] = edge_weight;

        list_of_adjacent_vertices[destination_vertex][source_vertex] = edge_weight;
    }

    int get_minimum_spanning_tree_weight()
    {
        const vector<int> list_of_ranked_disjoint_set(number_of_vertices, 0);
        vector<vector<int>> list_of_sorted_vertices_by_edge_weight;
        vector<int> list_of_parent_disjoint_set(number_of_vertices);

        for (int current_parent_disjoint_set = 0; current_parent_disjoint_set < number_of_vertices; current_parent_disjoint_set++)
            list_of_parent_disjoint_set[current_parent_disjoint_set] = current_parent_disjoint_set;

        populate_list_of_sorted_vertices_by_edge_weight_adapter::populate_list_of_sorted_vertices_by_edge_weight(
            number_of_vertices, list_of_adjacent_vertices,
            list_of_sorted_vertices_by_edge_weight);

        return minimum_spanning_tree_constructor::get_parsed_graph_edges_minimum_spanning_tree_weight(
            number_of_vertices,
            list_of_sorted_vertices_by_edge_weight,
            list_of_parent_disjoint_set,
            list_of_ranked_disjoint_set);
    }
};
