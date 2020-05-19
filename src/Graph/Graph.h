/*
 * Graph.h
 */
#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <queue>
#include <list>
#include <climits>
#include <cmath>
#include <stack>
#include <algorithm>
#include "MutablePriorityQueue.h"

using namespace std;

typedef pair<double, double> Coordinates;
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
	friend class Graph<T>;
	friend class Vertex<T>;
};

template <class T>
Edge<T>::Edge(Vertex<T> *d, double w): dest(d), weight(w) {}

template<class T>
Vertex<T>* Edge<T>::getDest() const {
    return this->dest;
}


/*************************** Graph  **************************/

template <class T>
class Graph {
	vector<Vertex<T> *> vertexSet;    // vertex set
    vector<vector<double>> v_distance;      //Floyd Warshal matrix
    vector<vector<T>> path; //Floyd Warshal return path


public:
	Vertex<T> *findVertexByInfo(const T &in) const;
	Vertex<T> *findVertexByID(const int id) const;
	bool addVertex(const int given_id, const T &in);
    bool addEdgeByID(const int sourc, const int dest, double w);
	bool addEdge(const T &sourc, const T &dest, double w);
	int getNumVertex() const;
	vector<Vertex<T> *> getVertexSet() const;

	//FP04

    vector<T> dfs (const T &origin, const T &dest);
    int dfsVisit(Vertex<T> *origin, Vertex<T> *dest, vector<T> *res);

    // Fp05 - single source
	void unweightedShortestPath(const T &s);    //TODO...
	void dijkstraShortestPath(const T &s);
    void dijkstraShortestPathByID(const int s);
	void bellmanFordShortestPath(const T &s);   //TODO...
	vector<T> getPathTo(const T &dest) const;   //TODO...

	// Fp05 - all pairs
	void floydWarshallShortestPath();   //TODO...
	vector<T> getfloydWarshallPath(const T &origin, const T &dest) const;   //TODO...

	void filterGraph();

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
Vertex<T> * Graph<T>::findVertexByID(const int id) const {
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



/**************** All Pairs Shortest Path  ***************/

template<class T>
void Graph<T>::floydWarshallShortestPath() { //DONE?
	// TODO

    // Distance initialization
    for (int i = 0; i < this->vertexSet.size(); i++) {
        vector<double> tmp;
        vector<int> tmp2;
        for (int j = 0; j < this->vertexSet.size(); j++) {
            tmp.push_back(10000000);
            tmp2.push_back(-1);
            if (i == j) {
                tmp[j] = 0;
                tmp2[j] = i;
            }
            else
                for (auto& w : this->vertexSet[i]->adj)
                    if (w.dest == this->vertexSet[j]) {
                        tmp[j] = w.weight;
                        tmp2[j] = i;
                    }

        }
        this->v_distance.push_back(tmp);
        this->path.push_back(tmp2);
    }


    for (int k = 1; k < this->vertexSet.size(); k++) {
        for (int i = 0; i < this->vertexSet.size(); i++)
            for (int j = 0; j < this->vertexSet.size(); j++) {
                if (this->v_distance[i][j] > this->v_distance[i][k] + this->v_distance[k][j]) {
                    this->v_distance[i][j] = this->v_distance[i][k] + this->v_distance[k][j];
                    this->path[i][j] = k;
                }
            }
    }

	/*
	vector<vector<double>> v_distance;
	vector<vector<int>> v_path;
	for (unsigned i = 0; i < vertexSet.size(); i++){
	    vector<double> aux_d;
	    vector<int> aux_p;
        for (unsigned j = 0; j < vertexSet.size(); j++){
            v_distance[i].push_back(INT_MAX);
            v_path[i].push_back(-1);
            if (i == j){
                v_distance[i][j] = 0;
                v_path[i][j] = i; //O path é o próprio
            }
            else{
                for (auto v: vertexSet[i]->adj){
                    if (v.dest == vertexSet[j]){
                        v_distance[i][j] = v.weight;
                        v_path[i][j] = i;
                    }
                }
            }
        }
	}
    for (unsigned k = 0; k < vertexSet.size(); k++){
        for (unsigned i = 0; i < vertexSet.size(); i++){
            for (unsigned j = 0; j < vertexSet.size(); j++){
                if (v_distance[i][k] + v_distance[k][j] < v_distance[i][j]) {
                    v_distance[i][j] = v_distance[i][k] + v_distance[k][j];
                    v_path[i][j] = k;
                }
            }
        }
    }

    for (int i = 0; i < v_distance.size(); i++){
            this->v_distance.push_back(v_distance[i]);
            this->path.push_back(v_path[i]);
    }
    */
}

template<class T>
vector<T> Graph<T>::getfloydWarshallPath(const T &orig, const T &dest) const{
	/*
	Vertex<T> origin = findVertex(orig);
	Vertex<T> destination = findVertex(dest);



    vector<T> res;
	// TODO
	return res;
	 */

    vector<T> res;
    Vertex<T> *v = findVertex(dest);
    int i, j;
    for (i = 0; i < this->vertexSet.size(); i++)
        if (orig == this->vertexSet[i]->info)
            break;
    for (j = 0; j < this->vertexSet.size(); j++)
        if (dest == this->vertexSet[j]->info)
            break;

    if (i < j) {
        stack<int> stack;
        int path = j;
        stack.push(j);
        while (path != i) {
            path = this->path[i][path];
            stack.push(path);
        }
        while (!stack.empty()) {
            res.push_back(this->vertexSet[stack.top()]->info);
            stack.pop();
        }
    }
    else {
        int path = i;
        res.push_back(this->vertexSet[i]->info);
        while (path != j) {
            path = this->path[path][j];
            res.push_back(this->vertexSet[path]->info);
        }
    }
    return res;
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


#endif /* GRAPH_H_ */
