#include <vector>

using namespace std;

class smallest_edge_weight_finder
{
private:
    explicit smallest_edge_weight_finder()
    {
    }

public:
    static int get_edge_with_smallest_weight(const vector<vector<int>> &list_of_vertices_minimum_distance)
    {
        int vertex_with_smallest_weight = 0;

        for (int current_vertex = 1; current_vertex < list_of_vertices_minimum_distance.size(); current_vertex++)
        {
            if (list_of_vertices_minimum_distance[current_vertex][0] < list_of_vertices_minimum_distance[vertex_with_smallest_weight][0])
                vertex_with_smallest_weight = current_vertex;
        }

        return vertex_with_smallest_weight;
    }
};
