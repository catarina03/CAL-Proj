/*
 * Graph.h
 */
#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <queue>
#include <list>
#include <climits>
#include <cfloat>
#include <cmath>
#include <stack>
#include <algorithm>
#include "MutablePriorityQueue.h"
#include "Utils/Utils.h"

using namespace std;

template <class T> class Edge;
template <class T> class Graph;
template <class T> class Vertex;

#define INF std::numeric_limits<double>::max()

/************************* Vertex  **************************/

template <class T>
class Vertex {
    int id;
	T info;						// content of the vertex
	vector<Edge<T> > outgoing;		// outgoing edges
    vector<Edge<T> > incoming;		// incoming edges
	
	double dist = 0;
	Vertex<T> *path = NULL;
	int queueIndex = 0; 		// required by MutablePriorityQueue

	bool visited = false;		// auxiliary field
	bool processing = false;	// auxiliary field

	void addEdge(Vertex<T> *dest, double w);

public:
	Vertex(T in);
	Vertex(int given_id, T in);
	int getID() const;
	void setID(int id);
	T getInfo() const;
	double getDist() const;
	Vertex *getPath() const;
	vector<Edge<T> > getOutgoing() const;

	bool operator<(Vertex<T> & vertex) const; // // required by MutablePriorityQueue
	friend class Graph<T>;
	friend class MutablePriorityQueue<Vertex<T>>;
};


template <class T>
Vertex<T>::Vertex(T in): info(in) {}

template<class T>
Vertex<T>::Vertex(int given_id, T in): id(given_id), info(in) {}

/*
 * Auxiliary function to add an outgoing edge to a vertex (this),
 * with a given destination vertex (d) and edge weight (w).
 */

template <class T>
int Vertex<T>::getID() const { return id; }

template <class T>
void Vertex<T>::setID(int given_id) { this->id = given_id; }

template <class T>
void Vertex<T>::addEdge(Vertex<T> *d, double w) {
	outgoing.push_back(Edge<T>(d, w));
}

template <class T>
bool Vertex<T>::operator<(Vertex<T> & vertex) const {
	return this->dist < vertex.dist;
}

template <class T>
T Vertex<T>::getInfo() const {
	return this->info;
}

template <class T>
double Vertex<T>::getDist() const {
	return this->dist;
}

template <class T>
Vertex<T> *Vertex<T>::getPath() const {
	return this->path;
}

template <class T >
vector<Edge<T> > Vertex<T>::getOutgoing() const {
    return this->outgoing;
}

/********************** Edge  ****************************/

template <class T>
class Edge {
	Vertex<T> * dest;      // destination vertex
	double weight;         // edge weight
public:
	Edge(Vertex<T> *d, double w);
	Vertex<T>* getDest() const;
	double getWeight() const;
	friend class Graph<T>;
	friend class Vertex<T>;
};

template <class T>
Edge<T>::Edge(Vertex<T> *d, double w): dest(d), weight(w) {}

template<class T>
Vertex<T>* Edge<T>::getDest() const {
    return this->dest;
}

template<class T>
double Edge<T>::getWeight() const { return this->weight; }



/*************************** Graph  **************************/

template <class T>
class Graph {
	vector<Vertex<T> *> vertexSet;    // vertex set
    double ** v_distance = nullptr;//floyd-warshall
    int **path = nullptr;

public:
    vector<T>duplicate_nodes;
	Vertex<T> *findVertexByInfo(const T &in) const;
	Vertex<T> *findVertexByID(int id) const;
	bool addVertex(const int given_id, const T &in);
	bool removeVertex(const Vertex<T> *vertex);
    bool addEdgeByID(const int sourc, const int dest, double w);
	bool addEdge(const T &sourc, const T &dest, double w);
	bool removeEdge(const Vertex<T> *orig, const Vertex<T> *dest);
	int getNumVertex() const;
	vector<Vertex<T> *> getVertexSet() const;

    vector<T> nearestNeighbour(const T &origin, const T &destiny);

    int nearestNeighbourAux(Vertex<T> *origin, Vertex<T> *dest, vector<T> *res);

	//FP04

	vector<int> stronglyConnectedDFS(const int orig);
    void genericDFSByID(Vertex<T>* vertex, vector<int> &ids);
    vector<T> dfs(const T &origin, const T &dest);
    int dfsVisit(Vertex<T> *origin, Vertex<T> *dest, vector<T> *res);
    void filterGraph(vector<int> nodes);

    // Fp05 - single source
	void unweightedShortestPath(const T &s);    //TODO...
	void dijkstraShortestPath(const T &s);
    void dijkstraShortestPathByID(const int s);
    vector<T> AStarShortestPathByInfo(const T &orig, const T &dest);
    vector<T> AStarShortestPathByID(const int orig, const int dest);
    void bellmanFordShortestPath(const T &s);   //TODO...
	vector<T> getPathTo(const T &dest) const;
	vector<T> getPathToByID(const int dest) const;

	// Fp05 - all pairs
	void floydWarshallShortestPath();   //TODO...
	vector<T> getfloydWarshallPath(const T &origin, const T &dest) const;   //TODO...
};


template <class T>
int Graph<T>::getNumVertex() const {
	return vertexSet.size();
}

template <class T>
vector<Vertex<T> *> Graph<T>::getVertexSet() const {
	return vertexSet;
}

/*
 * Auxiliary function to find a vertex with a given content.
 */
template <class T>
Vertex<T> * Graph<T>::findVertexByInfo(const T &in) const {
	for (auto v : vertexSet)
		if (v->info == in)
			return v;
	return NULL;
}

template <class T>
Vertex<T> * Graph<T>::findVertexByID(int id) const {
    for (auto i:duplicate_nodes){
        if (id==i.second){
            id=i.first;
        }
    }
    for (auto v : vertexSet)
        if (v->id == id)
            return v;
    return NULL;
}

/*
 *  Adds a vertex with a given content or info (in) to a graph (this).
 *  Returns true if successful, and false if a vertex with that content already exists.
 */
template <class T>
bool Graph<T>::addVertex(const int given_id, const T &in) {
	if ( findVertexByInfo(in) != NULL)
		return false;
	vertexSet.push_back(new Vertex<T>(given_id, in));
	return true;
}

template<class T>
bool Graph<T>::removeVertex(const Vertex<T> *vertex){
    if (find(vertexSet.begin(), vertexSet.end(), vertex) == vertexSet.end())
        return false; //Not in the graph
    else{
        vertexSet.erase(find(vertexSet.begin(), vertexSet.end(), vertex));
        return true;
    }
}

/*
 * Adds an edge to a graph (this), given the contents of the source and
 * destination vertices and the edge weight (w).
 * Returns true if successful, and false if the source or destination vertex does not exist.
 */
template <class T>
bool Graph<T>::addEdge(const T &sourc, const T &dest, double w) {
	auto v1 = findVertexByInfo(sourc);
	auto v2 = findVertexByInfo(dest);
	if (v1 == NULL || v2 == NULL)
		return false;
	v1->addEdge(v2,w);
	return true;
}

template <class T>
bool Graph<T>::addEdgeByID(const int sourc, const int dest, double w) {
    auto v1 = findVertexByID(sourc);
    auto v2 = findVertexByID(dest);
    if (v1 == NULL || v2 == NULL)
        return false;
    v1->addEdge(v2,w);
    return true;
}

template<class T>
bool Graph<T>::removeEdge(const Vertex<T> *orig, const Vertex<T> *dest){
    if(find(vertexSet.begin(), vertexSet.end(), orig) == vertexSet.end() || find(vertexSet.begin(), vertexSet.end(), dest) == vertexSet.end())
        return false;
    for (Edge<T> e : orig->outgoing){
        if (e.dest == dest){
            vector<Edge<T>> edgeVector = orig->outgoing;
            edgeVector.erase(find(orig->outgoing.begin(), orig->outgoing.end(), e));
        }
    }
    return true;
}

template <class T>
void deleteMatrix(T **m, int n) {
    if (m != nullptr) {
        for (int i = 0; i < n; i++)
            if (m[i] != nullptr)
                delete [] m[i];
        delete [] m;
    }
}


/**************** Single Source Shortest Path algorithms ************/

template<class T>
void Graph<T>::unweightedShortestPath(const T &orig) {  //DONE
    for(Vertex<T>* vertex: vertexSet){  //Resets path
        vertex->dist=INT_MAX;
        vertex->path=NULL;
    }

    Vertex<T> * origin = findVertex(orig);
    origin->dist=0;

    queue<Vertex<T>*> toBeProcessed;
    toBeProcessed.push(origin);

    while (!toBeProcessed.empty()) {
        auto v = toBeProcessed.front();
        toBeProcessed.pop();
        for (auto adjacent : v->adj) {
            if (adjacent.dest->dist == INT_MAX) {
                adjacent.dest->dist = v->dist + 1;
                adjacent.dest->path = v;
                toBeProcessed.push(adjacent.dest);
            }
        }
    }
}


template<class T>
void Graph<T>::dijkstraShortestPath(const T &origin) { //DONE
	for (Vertex<T> * vertex : vertexSet) {
	    vertex->dist = INT_MAX;
	    vertex->path = NULL;
	    vertex->visited = false;
	}

	Vertex<T> * orig = findVertexByInfo(origin);
	orig->dist = 0;
	orig->visited = true;
	MutablePriorityQueue<Vertex<T> > q;
	q.insert(orig);
	Vertex<T> * min;

	while(!q.empty()){
	    min = q.extractMin();
	    for (Edge<T> adj : min->adj){
	        if (adj.dest->dist > min->dist + adj.weight) {
	            adj.dest->dist = min->dist + adj.weight;
	            adj.dest->path = min;
	            if (adj.dest->visited){
	                q.decreaseKey(adj.dest);
	            }
	            else{
	                q.insert(adj.dest);
	                adj.dest->visited = true;
	            }
	        }
	    }
	}
}


template<class T>
void Graph<T>::dijkstraShortestPathByID(const int origin) { //DONE
    for (Vertex<T> * vertex : vertexSet) {
        vertex->dist = INT_MAX;
        vertex->path = NULL;
        vertex->visited = false;
    }

    Vertex<T> * orig = findVertexByID(origin);
    orig->dist = 0;
    orig->visited = true;
    MutablePriorityQueue<Vertex<T> > q;
    q.insert(orig);
    Vertex<T> * min;

    while(!q.empty()){
        min = q.extractMin();
        for (Edge<T> adj : min->outgoing){
            if (adj.dest->dist > min->dist + adj.weight) {
                adj.dest->dist = min->dist + adj.weight;
                adj.dest->path = min;
                if (adj.dest->visited){
                    q.decreaseKey(adj.dest);
                }
                else{
                    q.insert(adj.dest);
                    adj.dest->visited = true;
                }
            }
        }
    }
}

template <class T>
vector<T> Graph<T>::AStarShortestPathByInfo(const T &origin, const T &destination) {
    MutablePriorityQueue<Vertex<T> > q;
    for (Vertex<T> * vertex : vertexSet) {
        vertex->dist = INT_MAX;
        vertex->path = NULL;
        //q.insert(vertex);
    }
    Vertex<T>* orig = findVertexByInfo(origin);
    Vertex<T>* dest = findVertexByInfo(destination);
    orig->dist = euclideanDistance(orig->getInfo(), dest->info);
    q.insert(orig);
    Vertex<T>* v;

    while(!q.empty()){
        v = q.extractMin();
        if (v == dest){
            break;
        }
        for (Edge<T> e : v->getOutgoing()){
            double f = v->dist - euclideanDistance(v->info, dest->info) + e.weight + euclideanDistance(e.dest->info, dest->info);
            if (e.dest->dist > f){
                double d = e.dest->dist;
                e.dest->dist = f;
                e.dest->path = v;
                if (d == INT_MAX){
                    q.insert(e.dest);
                }
                else{
                    q.decreaseKey(e.dest);
                }
            }
        }
    }


    vector<T> res;
    res.push_back(dest->info);
    v = dest;
    while (v->path != NULL){
        res.push_back(v->path->info);
        v = v->path;
    }
    reverse(res.begin(), res.end());
    return res;
}


template <class T>
vector<T> Graph<T>::AStarShortestPathByID(const int origin, const int destination) {
    MutablePriorityQueue<Vertex<T> > q;
    for (Vertex<T> * vertex : vertexSet) {
        vertex->dist = INT_MAX;
        vertex->path = NULL;
        //q.insert(vertex);
    }
    Vertex<T>* orig = findVertexByID(origin);
    Vertex<T>* dest = findVertexByID(destination);
    orig->dist = euclideanDistance(orig->getInfo(), dest->info);
    q.insert(orig);
    Vertex<T>* v;

    while(!q.empty()){
        v = q.extractMin();
        if (v == dest){
            break;
        }
        for (Edge<T> e : v->getOutgoing()){
            double f = v->dist - euclideanDistance(v->info, dest->info) + e.weight + euclideanDistance(e.dest->info, dest->info);
            if (e.dest->dist > f){
                double d = e.dest->dist;
                e.dest->dist = f;
                e.dest->path = v;
                if (d == INT_MAX){
                    q.insert(e.dest);
                }
                else{
                    q.decreaseKey(e.dest);
                }
            }
        }
    }


    vector<T> res;
    res.push_back(dest->info);
    v = dest;
    while (v->path != NULL){
        res.push_back(v->path->info);
        v = v->path;
    }
    reverse(res.begin(), res.end());
    return res;
}


template<class T>
void Graph<T>::bellmanFordShortestPath(const T &orig) {

	for (auto vertex : vertexSet){
	    vertex->dist = INT_MAX;
	    vertex->path = NULL;
	}
	Vertex<T> *origin = findVertex(orig);
	origin->dist = 0;
	for (int i = 0; i < vertexSet.size() - 1; i++){
	    for (auto vertex: vertexSet){
	        for (Edge<T> edge: vertex->adj){
	            if (edge.dest->dist > vertex->dist + edge.weight){
                    edge.dest->dist = vertex->dist + edge.weight;
                    edge.dest->path = vertex;
	            }
	        }
	    }
	}
    for (auto vertex: vertexSet){
        for (Edge<T> edge: vertex->adj){
            if (edge.dest->dist > vertex->dist + edge.weight){
                cout << "There are cycle of negative weight" << endl;
            }
        }
    }
}


template<class T>
vector<T> Graph<T>::getPathTo(const T &dest) const{  //DONE
	vector<T> res;

	Vertex<T> * destination = findVertexByInfo(dest);
	res.push_back(destination->info);

	while (destination->getPath() != NULL){
	    res.push_back(destination->getPath()->getInfo());
	    destination = destination->getPath();
	}

	reverse(res.begin(), res.end());

	return res;
}

template<class T>
vector<T> Graph<T>::getPathToByID(const int dest) const{  //DONE
    vector<T> res;

    Vertex<T> * destination = findVertexByID(dest);
    res.push_back(destination->info);

    while (destination->getPath() != NULL){
        res.push_back(destination->getPath()->getInfo());
        destination = destination->getPath();
    }

    reverse(res.begin(), res.end());

    return res;
}



/**************** All Pairs Shortest Path  ***************/

template<class T>
void Graph<T>::floydWarshallShortestPath() {
    unsigned n = vertexSet.size();
    deleteMatrix(v_distance, n);
    deleteMatrix(path, n);
    v_distance = new double *[n];
    path = new int *[n];

    for (unsigned i = 0; i < n; i++) {
        v_distance[i] = new double[n];
        path[i] = new int[n];
        for (unsigned j = 0; j < n; j++) {
            v_distance[i][j] = i == j? 0 : INF;
            path[i][j] = -1;
        }
        for (auto e : vertexSet[i]->outgoing) {
            int j = findVertexByInfo(e.dest->info)->getID();
            v_distance[i][j] = e.weight;
            path[i][j] = i;
        }
    }
    for(unsigned k = 0; k < n; k++)
        for(unsigned i = 0; i < n; i++)
            for(unsigned j = 0; j < n; j++) {
                if(v_distance[i][k] == INF || v_distance[k][j] == INF)
                    continue; // avoid overflow
                int val = v_distance[i][k] + v_distance[k][j];
                if (val < v_distance[i][j]) {
                    v_distance[i][j] = val;
                    path[i][j] = path[k][j];
                }
            }

}


template<class T>
vector<T> Graph<T>::getfloydWarshallPath(const T &orig, const T &dest) const{
    vector<T> res;
    int i = findVertexByInfo(orig)->getID();
    int j = findVertexByInfo(dest)->getID();
    if (i == -1 || j == -1 || v_distance[i][j] == INF) // missing or disconnected
        return res;
    for ( ; j != -1; j = path[i][j])
        res.push_back(vertexSet[j]->info);
    reverse(res.begin(), res.end());
    return res;
}

/*
 * Cálculo da CFC a partir de um ponto (ponto de origem do condutor for example)
 */
template <class T>
vector<int> Graph<T>::stronglyConnectedDFS(const int orig){
    vector<int> res;
    for (auto v : vertexSet) {
        v->visited = false;
    }
    Vertex<T>* o = findVertexByID(orig);
    genericDFSByID(o, res);
    return res;
}

template <class T>
void Graph<T>::genericDFSByID(Vertex<T>* vertex, vector<int> &ids){
    vertex->visited = true;
    stack<Vertex<T>*> s;
    s.push(vertex);
    if(find(ids.begin(), ids.end(), vertex->id) == ids.end()){
        ids.push_back(vertex->getID());
    }
    while(!s.empty()){
        Vertex<T>* v = s.top();
        s.pop();
        for (auto e : v->outgoing){
            Vertex<T>* dest = e.dest;
            if (!dest->visited){
                s.push(dest);
                if(find(ids.begin(), ids.end(), dest->id) == ids.end()){
                    ids.push_back(dest->id);
                }
                dest->visited = true;
            }
        }
    }
}


template<class T>
vector<T> Graph<T>::dfs(const T &origin, const T &dest) {
    vector<T> path;
    for (auto i:vertexSet){
        i->visited=false;
    }

    dfsVisit(this->findVertexByInfo(origin), this->findVertexByInfo(dest), &path);
    return path;
}

template<class T>
int Graph<T>::dfsVisit(Vertex<T> *origin, Vertex<T> *dest, vector<T> *res){
    origin->visited=true;
    res->push_back(origin->info);
    if (origin->info==dest->info){
        return 0;
    }
    int count=0;
    for (auto & e : origin->outgoing) {
        auto w = e.dest;
        if ( ! w->visited) {
            count++;
            if (dfsVisit(w, dest, res) != 0) {
                origin->visited = true;
                count = 0;

            } else {
                return 0;
            }
        }
    }
    if (count==0){
        res->erase(res->end());
        return -1;
    }
}

template <class T>
void Graph<T>::filterGraph(vector<int> nodes){
    for (Vertex<T>* v : vertexSet){
        if (find(nodes.begin(), nodes.end(), v) == nodes.end()){
            for (Edge<T> e : v->outgoing){
                removeEdge(v, e.dest);
            }
            removeVertex(v);
        }
    }
}

template<class T>
vector<T> Graph<T>::nearestNeighbour(const T &origin, const T &destiny){
    auto orig=findVertexByInfo(origin);
    auto dest=findVertexByInfo(destiny);
    vector<T>path;

    for (auto w:this->vertexSet){
        w->visited=false;
    }
    nearestNeighbourAux(orig, dest, &path);
    return path;
}

template<class T>
int Graph<T>::nearestNeighbourAux(Vertex<T> *origin, Vertex<T> *dest, vector<T> *res){
    while(origin->info!=dest->info){
        origin->visited=true;
        res->push_back(origin->info);
        auto shortest_path=origin->outgoing[0];
        for (auto w:origin->outgoing){
            if (w.weight<shortest_path.weight){
                if(!(w.dest->visited)) {
                    shortest_path = w;
                }
            }
        }
        origin=shortest_path.dest;
        if (origin->visited){
            return -1;
        }
    }
}

#endif /* GRAPH_H_ */
