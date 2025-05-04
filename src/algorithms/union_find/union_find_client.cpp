#include <iostream>
#include "./union_find.cpp"
#include "../../constants/graphs.h"

using namespace std;

namespace union_find_client
{
    void execute()
    {
        union_find graph(NUMBER_OF_VERTICES);

        for (vector<int> component : GRAPH)
        {
            graph.union_components(component[0], component[1]);
        }

        cout << "Number Connected Components: \""
             << graph.get_total_number_of_components() << "\"" << endl
             << endl;

        cout << "Is Component \"" << GRAPH[0][0] << "\" Connected To Component \"" << GRAPH[0][1] << "\"? "
             << (graph.is_element_connected_to_element(GRAPH[0][0], GRAPH[0][1]) ? "\"Yes\"" : "\"No\"");
    }
}
