#include <vector>
#include "./disjoint_set_parent_vertex_finder.cpp"

using namespace std;

class union_disjoint_sets_parser
{
private:
    explicit union_disjoint_sets_parser()
    {
    }

public:
    static void union_disjoint_sets(const int source_vertex_disjoint_set_parent_vertex,
                                    const int destination_vertex_disjoint_set_parent_vertex,
                                    vector<int> &list_of_parent_disjoint_set, vector<int> &list_of_ranked_disjoint_set)
    {
        const int source_vertex_disjoint_set_parent_vertex_parent =
            disjoint_set_parent_vertex_finder::get_disjoint_set_parent_vertex(
                source_vertex_disjoint_set_parent_vertex, list_of_parent_disjoint_set);
        const int destination_vertex_disjoint_set_parent_vertex_parent =
            disjoint_set_parent_vertex_finder::get_disjoint_set_parent_vertex(
                destination_vertex_disjoint_set_parent_vertex, list_of_parent_disjoint_set);

        if (list_of_ranked_disjoint_set[source_vertex_disjoint_set_parent_vertex_parent] < list_of_ranked_disjoint_set[destination_vertex_disjoint_set_parent_vertex_parent])
            list_of_parent_disjoint_set[source_vertex_disjoint_set_parent_vertex_parent] = destination_vertex_disjoint_set_parent_vertex_parent;
        else if (list_of_ranked_disjoint_set[source_vertex_disjoint_set_parent_vertex_parent] >
                 list_of_ranked_disjoint_set[destination_vertex_disjoint_set_parent_vertex_parent])
            list_of_parent_disjoint_set[destination_vertex_disjoint_set_parent_vertex_parent] = source_vertex_disjoint_set_parent_vertex_parent;
        else
        {
            list_of_parent_disjoint_set[destination_vertex_disjoint_set_parent_vertex_parent] =
                source_vertex_disjoint_set_parent_vertex_parent;

            list_of_ranked_disjoint_set[source_vertex_disjoint_set_parent_vertex_parent]++;
        }
    }
};
