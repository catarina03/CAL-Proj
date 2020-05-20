//
// Created by catarina03 on 13/05/20.
//

#include "Utils.h"

using namespace std;

double euclideanDistance(pair<double, double> p1, pair<double, double> p2) {
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}
