#include <iostream>
#include <csignal>
#include "src/Utils.h"
#include "src/Graph/Graph.h"

int main() {
    signal(SIGINT, SIG_IGN);  //NEEDED OR ELSE IT CRASHES UBUNTU

    std::cout << "Hello world" << std::endl;

    Graph<Coordinates> graph = mapParser("../Maps/GridGraphs/8x8/nodes.txt", "../Maps/GridGraphs/8x8/edges.txt");
    showGraph(&graph);
    return 0;
};
