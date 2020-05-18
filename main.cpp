#include <iostream>
#include <csignal>
#include "src/Utils.h"
#include "src/Graph/Graph.h"

int main() {
    signal(SIGINT, SIG_IGN);  //NEEDED OR ELSE IT CRASHES UBUNTU

    std::cout << "Hello world" << std::endl;

    Graph<Coordinates> graph = mapParser("../Maps/GridGraphs/16x16/nodes.txt", "../Maps/GridGraphs/16x16/edges.txt");
    vector<Coordinates> path=graph.dfs(make_pair(0,0),make_pair(37,111));
    //TODO:make bfs work with showGrapth ->some problem with the vector
    //showGraph(&graph, path);
    return 0;
};