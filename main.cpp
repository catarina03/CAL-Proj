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
    /*
    Application application("MeetUpRider");
    startMenu(application);
    cout << "Exited Successfully! :)" << endl;
    */

    //TESTING
    cout << "MeetUpRider" << endl;
    cout << "Loading..." << endl;
    Graph<Coordinates> graph = mapParser("../Maps/PenafielMaps/penafiel_full_nodes_xy.txt", "../Maps/PenafielMaps/penafiel_full_edges.txt");
    //vector<Coordinates> res = graph.AStarShortestPathByID(3038, 4922);
    cout<<"returned to main"<<endl;
    vector<int> res = graph.stronglyConnectedDFS(1);
    Graph<Coordinates> new_graph = graph;
    new_graph.filterGraph(res);

    //graph.dijkstraShortestPathByID(8923); //27744 - Porto, 7100 - Penafiel, 8923 - Espinho
    //cout<<"djisktra"<<endl;
    //vector<Coordinates> res = graph.getPathToByID(4777); //26781 - Porto, 426 - Penafiel, 4777 - Espinho
    cout<<"res"<<endl;
    res.clear();
    showGraphbyID(&new_graph, res);
    cout << "Exited sucessfully" << endl;

    return 0;
};
