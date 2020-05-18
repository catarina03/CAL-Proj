#include <iostream>
#include <csignal>
#include "src/Utils.h"
#include "src/Graph/Graph.h"

int main() {
    signal(SIGINT, SIG_IGN);  //NEEDED OR ELSE IT CRASHES UBUNTU

    std::cout << "Welcome to MeetUpRider!" << std::endl;

    Graph<Coordinates> graph = mapParser("../Maps/GridGraphs/16x16/nodes.txt", "../Maps/GridGraphs/16x16/edges.txt");
    //showGraph(&graph);
    graph.dijkstraShortestPathByID(0);
    //vector<Coordinates> path = graph.getPathTo(make_pair(300, 600)); //Works in 4x4 and 8x8
    vector<Coordinates> path = graph.getPathTo(make_pair(333, 222)); //Works in 16x16
    showGraph(&graph, path);
    return 0;
};
