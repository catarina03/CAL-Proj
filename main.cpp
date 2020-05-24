#include <iostream>
#include <csignal>
#include <chrono>
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
    Graph<Coordinates> graph = mapParser("../Maps/PenafielMaps/penafiel_full_nodes_xy.txt", "../Maps/PenafielMaps/penafiel_full_edges.txt");
    cout << "returned to main" << endl;
    vector<Graph<Coordinates>> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(graph);
    }
    long count = 0;
    vector<int> res;

    for (int i = 0; i < 10; i++) {
        auto start = std::chrono::high_resolution_clock::now();
        res = v[i].bfs(8438);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        cout << (double) duration.count() << endl;
        count += duration.count();
        res.clear();
    }

    double avg = count/10;
    cout << "[Average] - " << avg << endl;

    return 0;
};
