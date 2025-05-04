#include <vector>
#include <algorithm>

using namespace std;

class graph_reverser
{
private:
    explicit graph_reverser()
    {
    }

public:
    static vector<int> get_reversed_order_graph(vector<int> &list_of_sorted_vertices)
    {
        reverse(list_of_sorted_vertices.begin(), list_of_sorted_vertices.end());

        return list_of_sorted_vertices;
    }
};
