//
// Created by catarina03 on 13/05/20.
//

#include "Utils.h"
#include <fstream>
#include <iostream>
#include <vector>

void showGraph(string node_path, string edge_path){
    GraphViewer *gv = new GraphViewer(600, 600, false);
    gv->createWindow(600, 600);
    gv->defineVertexColor("blue");
    gv->defineEdgeColor("black");

    string s, aux, total;
    int id = 0;
    vector<int> tmp;

    //NODES - 3 PARAMETERS TO READ
    ifstream myfile;
    myfile.open (node_path);
    if (myfile.is_open()){
        while(!myfile.eof()){
                getline(myfile, total);
                for (int j = 0; j < stoi(total); j++) {
                    getline(myfile, s);
                    for (int i = 0; i < s.size(); i++) {
                        if (i != 0) {
                            aux += s[i];
                        }
                        if (s[i] == ',') {
                            tmp.push_back(stoi(aux));
                            aux.clear();
                        }
                        if (i == s.size() - 1) {
                            tmp.push_back(stoi(aux));
                            aux.clear();
                        }
                    }
                    gv->addNode(tmp[0], tmp[1], tmp[2]);
                    gv->rearrange();
                    tmp.clear();
                }
                break;
        }
    }
    myfile.close();
    gv->rearrange();

    //EDGES - 2 PARAMETERS TO READ
    myfile.open (edge_path);
    if (myfile.is_open()){
        while(!myfile.eof()){
                getline(myfile, total);
                for (int j = 0; j < stoi(total); j++) {
                    getline(myfile, s);
                    for (int i = 0; i < s.size(); i++) {
                        if (i != 0) {
                            aux += s[i];
                        }
                        if (s[i] == ',') {
                            tmp.push_back(stoi(aux));
                            aux.clear();
                        }
                        if (i == s.size() - 1) {
                            tmp.push_back(stoi(aux));
                            aux.clear();
                        }
                    }
                    gv->addEdge(id, tmp[0], tmp[1], EdgeType::DIRECTED);
                    tmp.clear();
                    id += 1;
                }
                break;
        }
    }
    myfile.close();
    gv->rearrange();
    getchar();
}
