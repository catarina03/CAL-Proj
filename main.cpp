#include <iostream>
#include <Utils.h>
//#include <Graph.h>

int main() {
    GraphViewer *gv = new GraphViewer(600, 600, false);
    vector<int>tmp;
    createGraph(gv); //creates window and default option for graph
    std::cout << "Hello world" << std::endl;
    showGraph(gv,"../Maps/GridGraphs/16x16/nodes.txt", "../Maps/GridGraphs/16x16/edges.txt", &tmp);
    //showGraph(gv,"../Maps/PortugalMaps/Aveiro/nodes_lat_lon_aveiro.txt", "../Maps/PortugalMaps/Aveiro/edges_aveiro.txt", &tmp);
    //showGraph(gv,"../Maps/PortugalMaps/Portugal/nodes_lat_lon_portugal.txt", "../Maps/PortugalMaps/Portugal/edges_portugal.txt", &tmp);

    getchar();
};
