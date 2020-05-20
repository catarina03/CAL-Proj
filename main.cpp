#include <iostream>
#include <csignal>
#include "Utils/Utils.h"
#include "Utils/Visualization.h"
#include "src/Graph/Graph.h"
#include "src/gui.h"

using namespace std;

int main() {
    signal(SIGINT, SIG_IGN);  //NEEDED OR ELSE IT CRASHES UBUNTU

    startMenu();
    Graph<Coordinates> graph = mapParser("../Maps/GridGraphs/16x16/nodes.txt", "../Maps/GridGraphs/16x16/edges.txt");


    //Dijkstra
    /*
    graph.dijkstraShortestPathByID(0);
    //vector<Coordinates> path = graph.getPathTo(make_pair(300, 600)); //Works in 4x4 and 8x8

    vector<Coordinates> path = graph.getPathTo(make_pair(333, 222)); //Works in 4x4 and 8x8 and 16x16

    showGraph(&graph, path);
     */

    //A*
    //16x16
    Coordinates orig = make_pair(0, 0);
    Coordinates dest = make_pair(333, 222);
    vector<Coordinates> result = graph.AStarShortestPathByInfo(orig, dest);
    showGraph(&graph, result);

    return 0;
};
