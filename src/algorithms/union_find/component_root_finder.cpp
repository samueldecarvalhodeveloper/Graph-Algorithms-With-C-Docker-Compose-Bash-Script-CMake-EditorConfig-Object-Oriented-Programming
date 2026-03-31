#include <vector>

using namespace std;

class component_root_finder
{
private:
    explicit component_root_finder()
    {
    }

public:
    static int get_component_root(int element_index, vector<int> list_of_parent_identifiers)
    {
        if (element_index == list_of_parent_identifiers[element_index])
            return element_index;

        list_of_parent_identifiers[element_index] = get_component_root(list_of_parent_identifiers[element_index], list_of_parent_identifiers);

        return list_of_parent_identifiers[element_index];
    }
};
