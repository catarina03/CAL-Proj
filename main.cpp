#include <iostream>
#include <Utils.h>

int main() {
    std::cout << "Hello world" << std::endl;
    //showGraph("../Maps/GridGraphs/4x4/nodes.txt", "../Maps/GridGraphs/4x4/edges.txt");
    showGraph("../Maps/PortugalMaps/Aveiro/nodes_x_y_aveiro.txt", "../Maps/PortugalMaps/Aveiro/edges_aveiro.txt");
};
