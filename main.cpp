#include <iostream>
#include <csignal>
#include <chrono>
#include "Utils/Utils.h"
#include "Utils/Visualization.h"
#include "src/Graph/Graph.h"
#include "src/gui.h"
#include "Application.h"

using namespace std;

int test(){
    cout << "Loading..." << endl;
    Graph<Coordinates> graph = mapParser("../Maps/PortoMaps/porto_strong_nodes_xy.txt", "../Maps/PortoMaps/porto_strong_edges.txt");
    cout << "returned to main" << endl;

    vector<Graph<Coordinates>> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(graph);
    }
    long count = 0;

    for (int i = 0; i < 10; i++) {

        auto start = std::chrono::high_resolution_clock::now();
        v[i].dijkstraShortestPathByID(43005); //43005 - Porto, 7929 - Penafiel, 12338 - Espinho
        auto mid = std::chrono::high_resolution_clock::now();
        vector<Coordinates> res = v[i].getPathToByID(53578); //53578 - Porto, 5033 - Penafiel, 13589 - Espinho
        //vector<Coordinates> res = v[i].AStarShortestPathByID(43005, 53578);
        auto stop = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        auto durationDijkstra = std::chrono::duration_cast<std::chrono::microseconds>(mid - start);
        auto durationPath = std::chrono::duration_cast<std::chrono::microseconds>(stop - mid);
        cout << (double) duration.count() << endl;
        cout << (double) durationDijkstra.count() << endl;
        cout << (double) durationPath.count() << endl;
        count += duration.count();
        res.clear();
    }
    double avg = count/10;
    cout << "[Average] - " << avg << endl;

    return 0;
}


int main() {
    signal(SIGINT, SIG_IGN);  //NEEDED OR ELSE IT CRASHES UBUNTU

    cout << "MeetUpRider" << endl;

    //ACTUAL APP
    Application application("MeetUpRider");
    startMenu(application);
    cout << "Exited Successfully! :)" << endl;

    return 0;
};
