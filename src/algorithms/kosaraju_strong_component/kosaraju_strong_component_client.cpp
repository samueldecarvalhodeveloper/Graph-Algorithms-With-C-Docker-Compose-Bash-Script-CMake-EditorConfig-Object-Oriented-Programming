#include <iostream>
#include <vector>
#include "../../constants/graphs.h"
#include "./kosaraju_strong_component.cpp"

using namespace std;

namespace kosaraju_strong_component_client
{
    void execute()
    {
        kosaraju_strong_component graph(NUMBER_OF_VERTICES);

        for (const vector<int> edge : GRAPH)
        {
            graph.add_edge(edge[0], edge[1]);
        }

        vector<vector<int>> list_of_strong_connected_components = graph.get_list_of_strong_connected_component();

        cout << "[ ";

        for (int i = 0; i < list_of_strong_connected_components.size(); ++i)
        {
            cout << "[ ";

            for (int j = 0; j < list_of_strong_connected_components[i].size(); ++j)
            {
                if (j == list_of_strong_connected_components[i].size() - 1)
                    cout << list_of_strong_connected_components[i][j];
                else
                    cout << list_of_strong_connected_components[i][j] << ", ";
            }

            if (i == list_of_strong_connected_components.size() - 1)
                cout << " ]";
            else
                cout << " ], ";
        }

        cout << " ]";
    }
}
