//
// Created by catarina03 on 18/05/20.
//

#ifndef CAL_PROJ_VISUALIZATION_H
#define CAL_PROJ_VISUALIZATION_H

#include "GraphViewer/graphviewer.h"
#include "Utils.h"
#include "Graph/Graph.h"
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>


//DISPLAY GRAPH
void createGraph(GraphViewer *gv,int width=800, int height=800);
void addNodestoGraph(GraphViewer *gv, vector<int>*tmp);
void addEdgestoGraph(GraphViewer *gv, vector<int>*tmp);
void graphNodes(const string& node_path,vector<int>*tmp);
void graphEdges(const string& edge_path,vector<int>*tmp);
void showFullGraph(GraphViewer *gv, const string& node_path, const string& edge_path,vector<int>*tmp);


//template<class T>
void showGraph(Graph<Coordinates> *graph, vector<Coordinates> &res, vector<int> &poi);

//PARSE GRID MAP
void nodeParser(const string& node_path, Graph<Coordinates> *graph);
void edgeParser(const string& edge_path, Graph<Coordinates> *graph);
Graph<Coordinates> mapParser(const string& node_path, const string& edge_path);

#endif //CAL_PROJ_VISUALIZATION_H
