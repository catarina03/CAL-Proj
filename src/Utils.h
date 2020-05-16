//
// Created by catarina03 on 13/05/20.
//

#ifndef CAL_PROJ_UTILS_H
#define CAL_PROJ_UTILS_H

#include "../src/GraphViewer/graphviewer.h"
#include <fstream>
#include <iostream>
#include <vector>

void createGraph(GraphViewer *gv,int width=800, int height=800);
void addNodestoGraph(GraphViewer *gv, vector<int>*tmp);
void addEdgestoGraph(GraphViewer *gv, vector<int>*tmp);
void graphNodes(const string& node_path,vector<int>*tmp);
void graphEdges(const string& edge_path,vector<int>*tmp);
void showGraph(GraphViewer *gv, const string& node_path, const string& edge_path,vector<int>*tmp);

#endif //CAL_PROJ_UTILS_H
