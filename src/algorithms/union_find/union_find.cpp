#include <vector>
#include "./component_root_finder.cpp"

using namespace std;

class union_find
{
private:
    vector<int> list_of_parent_identifiers;
    vector<int> component_sizes;
    int total_components;

public:
    explicit union_find(const int number_of_elements)
    {
        total_components = number_of_elements;

        list_of_parent_identifiers.resize(number_of_elements);
        component_sizes.resize(number_of_elements, 1);

        for (int element_index = 0; element_index < number_of_elements; element_index++)
            list_of_parent_identifiers[element_index] = element_index;
    }

    bool is_element_connected_to_element(const int first_element_index, const int second_element_index)
    {
        return component_root_finder::get_component_root(first_element_index, list_of_parent_identifiers) ==
               component_root_finder::get_component_root(second_element_index, list_of_parent_identifiers);
    }

    void union_components(const int first_element_index, const int second_element_index)
    {
        const int first_component_root = component_root_finder::get_component_root(first_element_index, list_of_parent_identifiers);
        const int second_component_root = component_root_finder::get_component_root(second_element_index, list_of_parent_identifiers);

        if (first_component_root == second_component_root)
            return;

        if (component_sizes[first_component_root] < component_sizes[second_component_root])
        {
            list_of_parent_identifiers[first_component_root] = second_component_root;

            component_sizes[second_component_root] += component_sizes[first_component_root];
        }
        else
        {
            list_of_parent_identifiers[second_component_root] = first_component_root;

            component_sizes[first_component_root] += component_sizes[second_component_root];
        }

        total_components--;
    }

    int get_total_number_of_components()
    {
        return total_components;
    }
};
