#ifndef GRAPHS_HEADER
#define GRAPHS_HEADER

#include <vector>

using namespace std;

const vector<vector<int>> GRAPH = {
    {0, 1}, {0, 2}, {1, 3}, {2, 4}, {3, 5}, {4, 6}, {5, 7}, {6, 8}, {7, 9}, {8, 10}, {9, 11}, {10, 12}, {11, 13}, {12, 14}, {13, 15}, {14, 16}, {15, 17}, {16, 18}, {17, 19}, {18, 19}};

const int NUMBER_OF_VERTICES = GRAPH.size();

const vector<vector<int>> GRAPH_WITH_WEIGHTS = {
    {0, 1, 5}, {0, 2, 3}, {1, 3, 6}, {2, 4, 2}, {3, 5, 8}, {4, 6, 7}, {5, 7, 4}, {6, 8, 9}, {7, 9, 1}, {8, 10, 5}, {9, 11, 2}, {10, 12, 3}, {11, 13, 10}, {12, 14, 6}, {13, 15, 4}, {14, 16, 2}, {15, 17, 5}, {16, 18, 3}, {17, 19, 8}, {18, 19, 1}};

#endif
