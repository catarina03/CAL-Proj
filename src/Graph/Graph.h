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
	
	double dist = 0;
	Vertex<T> *path = NULL;
	int queueIndex = 0; 		// required by MutablePriorityQueue

	bool visited = false;		// auxiliary field
	bool processing = false;	// auxiliary field
	bool connected=false;       //auxiliary bfs

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
    bool addEdgeByID(const int sourc, const int dest, double w);
	bool addEdge(const T &sourc, const T &dest, double w);
	int getNumVertex() const;
	vector<Vertex<T> *> getVertexSet() const;

    vector<T> nearestNeighbour(const T &origin, const T &destiny);
    int nearestNeighbourAux(Vertex<T> *origin, Vertex<T> *dest, vector<T> *res);

	//FP04
    vector<Coordinates> bfs (const int &origin);
    void BfsConectedGraph(const int &origin);

    void DFSConnectedGraph(Vertex<T>* vertex, vector<int> &ids);
    vector<int> dfsVector(const int orig);
    vector<T> dfs(const T &origin, const T &dest);
    int dfsVisit(Vertex<T> *origin, Vertex<T> *dest, vector<T> *res);

    // Fp05 - single source
	void unweightedShortestPath(const T &s);    //TODO...
	void dijkstraShortestPath(const T &s);
    void dijkstraShortestPathByID(const int s);
    vector<T> AStarShortestPathByInfo(const T &orig, const T &dest);
    vector<T> AStarShortestPathByID(const int orig, const int dest);
	vector<T> getPathTo(const T &dest) const;
	vector<T> getPathToByID(const int dest) const;

	// Fp05 - all pairs
	void floydWarshallShortestPath();
	vector<T> getfloydWarshallPath(const T &origin, const T &dest) const;
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
	for(int i=0;i<vertexSet.size();i++){
	    if (vertexSet[i]->id==given_id){
	        return false;
	    }
	}
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
    }
    Vertex<T>* orig = findVertexByID(origin);
    Vertex<T>* dest = findVertexByID(destination);
    Vertex<T>* v;
    orig->dist = euclideanDistance(orig->getInfo(), dest->info);
    q.insert(orig);

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
 * Muda o grafo
 */
template <class T>
void Graph<T>::DFSConnectedGraph(Vertex<T>* origin, vector<int> &ids){
    Vertex<T>* vertex = findVertexByID(origin);
    if (vertex == NULL)
        return;
    for (auto v : vertexSet) {
        v->visited = false;
    }
    vertex->visited = true;
    stack<Vertex<T>*> s;
    s.push(vertex);

    while(!s.empty()){
        Vertex<T>* v = s.top();
        s.pop();
        for (auto e : v->outgoing){
            Vertex<T>* dest = e.dest;
            if (!dest->visited){
                s.push(dest);
                dest->visited = true;
            }
        }
    }
    for(auto i=vertexSet.begin();i!=vertexSet.end();i++){
        if (!((*i)->visited)){
            vertexSet.erase(i);
            i--;
        }
    }
}


/*
 * Returns the vector with the SCC vertex ids
 */
template <class T>
vector<int> Graph<T>::dfsVector(const int orig){
    vector<int> ids;
    Vertex<T>* vertex = findVertexByID(orig);
    if (vertex == NULL){
        return ids;
    }
    for (auto v : vertexSet) {
        v->visited = false;
    }
    vertex->visited = true;
    stack<Vertex<T>*> s;
    s.push(vertex);

    while(!s.empty()){
        Vertex<T>* v = s.top();
        s.pop();
        ids.push_back(v->id);
        for (auto e : v->outgoing){
            Vertex<T>* dest = e.dest;
            if (!dest->visited){
                s.push(dest);
                dest->visited = true;
            }
        }
    }
    return ids;
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

template<class T>
vector<Coordinates> Graph<T>::bfs(const int &origin) {
    vector<Coordinates> res;
    auto s = findVertexByID(origin);
    if (s == NULL)
        return res;
    queue<Vertex<T> *> q;
    for (auto v : vertexSet)
        v->visited = false;
    q.push(s);
    s->visited = true;
    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        res.push_back(v->info);
        for (auto & e : v->outgoing) {
            auto w = e.dest;
            if ( ! w->visited ) {
                q.push(w);
                w->visited = true;
            }
        }
    }
    return res;
}

template<class T>
void Graph<T>::BfsConectedGraph(const int &origin) {
    //Graph<Coordinates>res;

    auto s = findVertexByID(origin);
    if (s == NULL)
        return;
    queue<Vertex<T> *> q;
    for (auto v : vertexSet)
        v->visited = false;
    q.push(s);
    s->visited = true;
    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        //res.addVertex(v->id,v->info);
        for (auto & e : v->outgoing) {
            auto w = e.dest;
            //res.addVertex(w->id,w->info);
            //res.addEdgeByID(v->id,w->id,e.weight);
            if ( ! w->visited ) {
                q.push(w);
                w->visited = true;
            }
        }
    }
    for(auto i=vertexSet.begin();i!=vertexSet.end();i++){
        if (!((*i)->visited)){
            vertexSet.erase(i);
            i--;
        }
    }
    return;
}
/*
template <class T>
vector<int> Graph<T>::nearestPOI(vector<int> &poi){
    vector<int> tempStorage;
    vector<int> res;
    //Vertex<T> v1, v2;
    int counter;
    //Vertex<T> *orig = findVertexByID(poi[0]);

    */
    /*
    for(unsigned int i = 0; i < poi.size()-1; i++){
        tempStorage = AStarShortestPathByID(poi.at(i), poi.at(i+1));
        for(unsigned int j = 0; j < tempStorage.size(); j++){
            res.push_back(tempStorage.at(j));
        }
        tempStorage.clear();
    }
    for (int i = 0; i < res.size()-1; i++){
        v1 = findVertexByID(res[i]);
        v2 = findVertexByID(res[i+1]);
        for (Edge<T> e : v1.outgoing){
            if (v2 == e.getDest()){
                counter += e.getWeight();
            }
        }
    }

    for(unsigned int i = 0; i < poi.size()-1; i++){
        tempStorage = AStarShortestPathByID(orig, poi.at(i));
        int counter2;
        for (int i = 0; i < tempStorage.size()-1; i++){
            v1 = findVertexByID(res[i]);
            v2 = findVertexByID(res[i+1]);
            for (Edge<T> e : v1.outgoing){
                if (v2 == e.getDest()){
                    counter2 += e.getWeight();
                }
            }
        }
    }
    */
    /*
    int count = INT_MAX, tmp = 0;

    Vertex<T> v1 = findVertexByID(poi[0]);
    for (int i = 0; i < poi.size() - 1; i++) {
        for (int j = 1; j < poi.size() - 1; j++) {
            if (find(res.begin(), res.end(), v1.getID()) != res.end()) {
                Vertex<T> v2 = findVertexByID(poi[j]);
                tmp = euclideanDistance(v1.getInfo(), v2.getInfo());
                if (tmp < count && ) {
                    v1 = v2;
                }
            }
        }
        res.push_back(v1.id);
        tmp = INT_MAX;
    }
    res.push_back()


}*/

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

/*
template<class T>
vector<int> Graph<T>::twoOptSwap(const vector<int> &ord, const int &i, const int &k) {
    vector<int> new_ord;

    for (int c = 0; c < i; c++) {
        new_ord.push_back(ord.at(c));
    }

    for (int c = k; c >= i; c--) {
        new_ord.push_back(ord.at(c));
    }

    for (int c = k + 1; c < ord.size(); c++) {
        new_ord.push_back(ord.at(c));
    }

    return new_ord;
}

template<class T>
vector<T> Graph<T>::twoOptHeuristic(vector<int> &ord, vector<T> &path) {
    int improve = 0;
    vector<T> optimalPath = path;

    while (improve < 20) {
        for (int i = 1; i < ord.size() - 2; i++) {
            for (int k = i + 1; k < ord.size() - 1; k++) {
                vector<T> newPath = buildPath(twoOptSwap(ord, i, k));
                if (newPath.getLength() < optimalPath.getLength()) {
                    improve = 0;
                    optimalPath = newPath;
                }
            }
        }
        improve++;
    }

    return optimalPath;
}
*/



#endif /* GRAPH_H_ */
