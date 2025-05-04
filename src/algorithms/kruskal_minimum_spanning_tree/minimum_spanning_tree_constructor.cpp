#include <vector>
#include "./disjoint_set_parent_vertex_finder.cpp"
#include "./union_disjoint_sets_parser.cpp"

using namespace std;

class minimum_spanning_tree_constructor
{
private:
    explicit minimum_spanning_tree_constructor()
    {
    }

public:
    static int get_parsed_graph_edges_minimum_spanning_tree_weight(const int number_of_vertices,
                                                                   vector<vector<int>>
                                                                       list_of_sorted_vertices_by_edge_weight,
                                                                   vector<int> list_of_parent_disjoint_set,
                                                                   vector<int> list_of_ranked_disjoint_set)
    {
        int minimum_spanning_tree_weight = 0;
        int number_of_edges_in_the_graph = 0;

        for (vector<int> &current_edge : list_of_sorted_vertices_by_edge_weight)
        {
            const int source_vertex = current_edge[0];
            const int destination_vertex = current_edge[1];
            const int edge_weight = current_edge[2];
            const int source_vertex_disjoint_set_parent_vertex =
                disjoint_set_parent_vertex_finder::get_disjoint_set_parent_vertex(
                    source_vertex, list_of_parent_disjoint_set);
            const int destination_vertex_disjoint_set_parent_vertex =
                disjoint_set_parent_vertex_finder::get_disjoint_set_parent_vertex(
                    destination_vertex, list_of_parent_disjoint_set);

            if (number_of_edges_in_the_graph == number_of_vertices - 1)
                break;

            if (source_vertex_disjoint_set_parent_vertex != destination_vertex_disjoint_set_parent_vertex)
            {
                minimum_spanning_tree_weight += edge_weight;
                number_of_edges_in_the_graph++;

                union_disjoint_sets_parser::union_disjoint_sets(source_vertex_disjoint_set_parent_vertex,
                                                                destination_vertex_disjoint_set_parent_vertex,
                                                                list_of_parent_disjoint_set,
                                                                list_of_ranked_disjoint_set);
            }
        }

        return minimum_spanning_tree_weight;
    }
};
