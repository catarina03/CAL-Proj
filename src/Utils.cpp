//
// Created by catarina03 on 13/05/20.
//

#include "Utils.h"

//#include <Graph.h>

void createGraph(GraphViewer *gv,int width, int height){
    gv->createWindow(width, height);
    gv->defineVertexColor("blue");
    gv->defineEdgeColor("black");
}

void addNodestoGraph(GraphViewer *gv, vector<int>*tmp){
    int min_x=0;
    int min_y=0;
    for(int i=0;i<tmp->size();i+=3){
        if (tmp->at(i+1)<min_x){
            min_x=tmp->at(i+1);
        }
        if (tmp->at(i+2)<min_y){
            min_x=tmp->at(i+2);
        }
    }
    for(int i=0; i<tmp->size();i++){
        tmp->at(i)-=(min(min_x,min_y));
    }
    for(int i=0;i<tmp->size();i+=3){
        gv->addNode(tmp->at(i), tmp->at(i+1), tmp->at(i+2));
    }
    gv->rearrange();
    tmp->clear();

    gv->rearrange();
}

void addEdgestoGraph(GraphViewer *gv, vector<int>*tmp){

    for(int i=0;i<tmp->size();i+=3){
        gv->addEdge(tmp->at(i), tmp->at(i+1), tmp->at(i+2), EdgeType::DIRECTED);
    }
    gv->rearrange();
    tmp->clear();

    gv->rearrange();
}

void graphNodes(const string& node_path, vector<int>*tmp) {
    string s, aux, total;
    int id = 0;

    //NODES - 3 PARAMETERS TO READ
    ifstream myfile;
    myfile.open(node_path);
    if (myfile.is_open()) {
        while (!myfile.eof()) {
            getline(myfile, total);
            for (int j = 0; j < stoi(total); j++) {
                getline(myfile, s);
                for (int i = 0; i < s.size(); i++) {
                    if (i != 0) {
                        aux += s[i];
                    }
                    if (s[i] == ',') {
                        tmp->push_back(stoi(aux));
                        aux.clear();
                    }
                    if (i == s.size() - 1) {
                        tmp->push_back(stoi(aux));
                        aux.clear();

                    }
                }/*
                    gv->addNode(tmp[0], tmp[1], tmp[2]);
                    gv->rearrange();
                    tmp.clear();
                    */
            }
            break;
        }
    }
    myfile.close();

}


void graphEdges(const string& edge_path,vector<int>*tmp){
    //EDGES - 2 PARAMETERS TO READ
    string s, aux, total;
    int id=0;
    ifstream myfile;

    myfile.open (edge_path);
    if (myfile.is_open()){
        while(!myfile.eof()){
                getline(myfile, total);
                for (int j = 0; j < stoi(total); j++) {
                    getline(myfile, s);
                    tmp->push_back(id);
                    for (int i = 0; i < s.size(); i++) {
                        if (i != 0) {
                            aux += s[i];
                        }
                        if (s[i] == ',') {
                            tmp->push_back(stoi(aux));
                            aux.clear();
                        }
                        if (i == s.size() - 1) {
                            tmp->push_back(stoi(aux));
                            aux.clear();
                        }
                    }
                    /*gv->addEdge(id, tmp[0], tmp[1], EdgeType::DIRECTED);
                    tmp.clear();*/
                    id += 1;
                }
                break;
        }
    }
    myfile.close();

    //gv->rearrange();

}

void showGraph(GraphViewer *gv, const string& node_path, const string& edge_path,vector<int>*tmp) {
    graphNodes(node_path, tmp);
    addNodestoGraph(gv, tmp);
    graphEdges(edge_path,tmp);
    addEdgestoGraph(gv,tmp);
}
