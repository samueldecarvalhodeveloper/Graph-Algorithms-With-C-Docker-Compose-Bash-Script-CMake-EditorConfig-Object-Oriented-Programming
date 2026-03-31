#include <iostream>

#include "./algorithms/union_find/union_find_client.cpp"
#include "./algorithms/depth_first_search/depth_first_search_client.cpp"
#include "./algorithms/breadth_first_search/breadth_first_search_client.cpp"
#include "./algorithms/topological_sort/topological_sort_client.cpp"
#include "./algorithms/kosaraju_strong_component/kosaraju_strong_component_client.cpp"
#include "./algorithms/prim_minimum_spanning_tree/prim_minimum_spanning_tree_client.cpp"
#include "./algorithms/kruskal_minimum_spanning_tree/kruskal_minimum_spanning_tree_client.cpp"
#include "./algorithms/dijkstra_shortest_path/dijkstra_shortest_path_client.cpp"
#include "./algorithms/directed_acyclic_graph_shortest_path/directed_acyclic_graph_shortest_path_client.cpp"
#include "./algorithms/bellman_ford_shortest_path/bellman_ford_shortest_path_client.cpp"

using namespace std;

int main()
{
    cout << "Union-Find Search:" << endl
         << endl;

    union_find_client::execute();

    cout << endl
         << endl;

    cout << "Depth-First Search:" << endl
         << endl;

    depth_first_search_client::execute();

    cout << endl
         << endl;

    cout << "Breadth-First Search:" << endl
         << endl;

    breadth_first_search_client::execute();

    cout << endl
         << endl;

    cout << "Topological Sort:" << endl
         << endl;

    topological_sort_client::execute();

    cout << endl
         << endl;

    cout << "Kosaraju Strong Component:" << endl
         << endl;

    kosaraju_strong_component_client::execute();

    cout << endl
         << endl;

    cout << "Prim Minimum Spanning Tree:" << endl
         << endl;

    prim_minimum_spanning_tree_client::execute();

    cout << endl
         << endl;

    cout << "Kruskal Minimum Spanning Tree:" << endl
         << endl;

    kruskal_minimum_spanning_tree_client::execute();

    cout << endl
         << endl;

    cout << "Dijkstra Shortest Path:" << endl
         << endl;

    dijkstra_shortest_path_client::execute();

    cout << endl
         << endl;

    cout << "Directed Acyclic Graph Shortest Path:" << endl
         << endl;

    directed_acyclic_graph_shortest_path_client::execute();

    cout << endl;
    cout << endl;

    cout << "Bellman-Ford Graph Shortest Path:" << endl
         << endl;

    bellman_ford_shortest_path_client::execute();

    return 0;
}
