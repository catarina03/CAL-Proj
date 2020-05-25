//
// Created by catarina03 on 18/05/20.
//

#include "Visualization.h"

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

void showFullGraph(GraphViewer *gv, const string& node_path, const string& edge_path,vector<int>*tmp) {
    graphNodes(node_path, tmp);
    addNodestoGraph(gv, tmp);
    graphEdges(edge_path,tmp);
    addEdgestoGraph(gv,tmp);
}

//template<class T>
void showGraph(Graph<Coordinates> *graph, vector<Coordinates> &res){
    GraphViewer *gv = new GraphViewer(600, 600, false);
    createGraph(gv);

    int id = 0;
    vector<Vertex<Coordinates> *> vertexSet = graph->getVertexSet();
    if (res.empty()){
        for (auto v : vertexSet){
            gv->addNode(v->getID(), v->getInfo().first, v->getInfo().second);
            gv->setVertexLabel(v->getID(), to_string(v->getID()));
        }
        for (auto v : vertexSet){
            for (auto e : v->getOutgoing()){
                gv->addEdge(id, v->getID(), e.getDest()->getID(), EdgeType::DIRECTED);
                id++;
            }
        }
    }
    else{
        for (Vertex<Coordinates>* v : vertexSet){
            gv->addNode(v->getID(), v->getInfo().first, v->getInfo().second);
            gv->setVertexLabel(v->getID(), to_string(v->getID()));
            if (find(res.begin(), res.end(), v->getInfo()) != res.end()){
                gv->setVertexColor(v->getID(), "red");
            }
        }
        for (auto v : vertexSet){
            for (auto e : v->getOutgoing()){
                gv->addEdge(id, v->getID(), e.getDest()->getID(), EdgeType::DIRECTED);
                if (find(res.begin(), res.end(), v->getInfo()) != res.end() && find(res.begin(), res.end(), e.getDest()->getInfo()) != res.end()){
                    gv->setEdgeColor(id, "red");
                    gv->setEdgeThickness(id, 15);
                }
                id++;
            }
        }
        Vertex<Coordinates>* v1 = graph->findVertexByInfo(res[0]);
        Vertex<Coordinates>* v2 = graph->findVertexByInfo(res[res.size()-1]);
        gv->setVertexColor(v1->getID(), "green");
        gv->setVertexColor(v2->getID(), "green");

    }

    gv->rearrange();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    //getchar();
    gv->closeWindow();

}


void nodeParser(const string& node_path, Graph<Coordinates> *graph) {
    string s, aux, total;
    vector<int> tmp;

    //NODES - 3 PARAMETERS TO READ
    ifstream myfile;
    myfile.open(node_path);
    if (myfile.is_open()) {
        while (!myfile.eof()) {
            getline(myfile, total);
            for (int j = 0; j < stoi(total); j++) {
                getline(myfile, s);
                for (unsigned long i = 0; i < s.size(); i++) {
                    //if (s[i]=='.')
                      //  continue;

                    if (s[i] == ',') {
                        tmp.push_back(stoi(aux));
                        aux.clear();
                    }
                    else {
                        if (i == s.size() - 1) {
                            tmp.push_back(stoi(aux));
                            aux.clear();
                        }
                        else {
                            if (i != 0) {
                                aux += s[i];
                            }
                        }
                    }
                }
                for(auto i:graph->getVertexSet()){
                    if (i->getInfo()==make_pair(tmp.at(1), tmp.at(2))){
                        graph->duplicate_nodes.push_back(make_pair(i->getID(),tmp.at(0)));
                        break;
                    }
                }
                graph->addVertex(tmp.at(0), make_pair(tmp.at(1), tmp.at(2)));
                tmp.clear();
            }
            break;
        }
    }
    myfile.close();
}

void edgeParser(const string& edge_path, Graph<Coordinates> *graph){
    //EDGES - 2 PARAMETERS TO READ
    string s, aux, total;
    vector<int> tmp;
    ifstream myfile;

    myfile.open (edge_path);
    if (myfile.is_open()){
        while(!myfile.eof()){
            getline(myfile, total);
            for (int j = 0; j < stoi(total); j++) {
                getline(myfile, s);
                //tmp->push_back(id);
                for (int i = 0; i < s.size(); i++) {

                    if (s[i] == ',') {
                        tmp.push_back(stoi(aux));
                        aux.clear();
                    }
                    else {
                        if (i == s.size() - 1) {
                            tmp.push_back(stoi(aux));
                            aux.clear();
                        }
                        else {
                            if (i != 0) {
                                aux += s[i];
                            }
                        }
                    }
                }

                for (auto i:graph->duplicate_nodes){
                    if (tmp.at(0)==i.second){
                        tmp[0]=i.first;
                    }
                    if (tmp.at(1)==i.second){
                        tmp[1]=i.first;
                    }
                }

                double result = euclideanDistance(graph->findVertexByID(tmp.at(0))->getInfo(), graph->findVertexByID(tmp.at(1))->getInfo());


                graph->addEdgeByID(tmp.at(0), tmp.at(1), result);
                tmp.clear();
            }
            break;
        }
    }
    myfile.close();

}

Graph<Coordinates> mapParser(const string& node_path, const string& edge_path){
    Graph<Coordinates> graph;
    nodeParser(node_path, &graph);
    edgeParser(edge_path, &graph);
    return graph;

}

