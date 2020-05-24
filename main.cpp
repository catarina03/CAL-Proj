#include <iostream>
#include <csignal>
#include "Utils/Utils.h"
#include "Utils/Visualization.h"
#include "src/Graph/Graph.h"
#include "src/gui.h"
#include "Application.h"

using namespace std;

int main() {
    signal(SIGINT, SIG_IGN);  //NEEDED OR ELSE IT CRASHES UBUNTU

    //ACTUAL APP

    Application application("MeetUpRider");
    startMenu(application);
    cout << "Exited Successfully! :)" << endl;


    //TESTING
    /*
    cout << "MeetUpRider" << endl;
    Graph<Coordinates> graph = mapParser("../Maps/PortoMaps/porto_strong_nodes_xy.txt", "../Maps/PortoMaps/porto_strong_edges.txt");
    //vector<Coordinates> res = graph.AStarShortestPathByID(3038, 4922);
    cout<<"returned to main"<<endl;
    graph.dijkstraShortestPathByID(27744);
    cout<<"djisktra"<<endl;
    vector<Coordinates> res = graph.getPathToByID(26781);
    cout<<"res"<<endl;
    //res.clear();
    showGraph(&graph, res);
    */
    return 0;
};
