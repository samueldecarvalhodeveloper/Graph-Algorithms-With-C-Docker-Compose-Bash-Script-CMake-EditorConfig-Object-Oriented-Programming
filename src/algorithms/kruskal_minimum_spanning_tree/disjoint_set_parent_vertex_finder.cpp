#ifndef DISJOINT_SET_PARENT_VERTEX_FINDER_HEADER
#define DISJOINT_SET_PARENT_VERTEX_FINDER_HEADER

#include <vector>

using namespace std;

class disjoint_set_parent_vertex_finder
{
private:
    explicit disjoint_set_parent_vertex_finder()
    {
    }

public:
    static int get_disjoint_set_parent_vertex(const int current_vertex, vector<int> &list_of_parent_disjoint_set)
    {
        if (list_of_parent_disjoint_set[current_vertex] != current_vertex)
            list_of_parent_disjoint_set[current_vertex] = get_disjoint_set_parent_vertex(
                list_of_parent_disjoint_set[current_vertex], list_of_parent_disjoint_set);

        return list_of_parent_disjoint_set[current_vertex];
    }
};

#endif
