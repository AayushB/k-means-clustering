//
//  KMeans.h
//  K-Means-Clustering
//
//  Created by Aayush Bhandari on 5/14/14.
//  Copyright (c) 2014 Aayush Bhandari. All rights reserved.
//

#ifndef K_Means_Clustering_KMeans_h
#define K_Means_Clustering_KMeans_h

#include "WheatKernel.h"
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

class KMeans
{
public:
    KMeans(vector<WheatKernel> data, int k);
    void printData();
    void printCentroids();
private:
    WheatKernel* centroids; //stores the centorids
    int* labels; //stores the coressponding labels to data 0 ,1 ,2
    vector<WheatKernel> data;
    int k;

    bool shouldStop(WheatKernel* oldCentroids, WheatKernel* centroids, int iterations);
    WheatKernel* getRandomCentroids(WheatKernel* centroids, int k);
    int* getLabels(vector<WheatKernel>data, WheatKernel* centroids, int k);
    WheatKernel* getCentroids(vector<WheatKernel> data, int* labels, int k);
    double eculedianDistance(WheatKernel value1, WheatKernel value2);
    
   
    
};

#endif
