//
//  main.cpp
//  K-Means-Clustering
//
//  Created by Aayush Bhandari on 4/26/14.
//  Copyright (c) 2014 Aayush Bhandari. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstreAM>
#include "WheatKernel.h"
using namespace std;



void loadObjects(vector<WheatKernel> value)
{
    string filename="/Users/Aayush/Desktop/GitHubFolders/k-means-clustering/K-Means-Clustering/K-Means-Clustering/seeds_dataset.txt";
    ifstream file;
    file.open(filename.c_str());
    if(file.fail())
    {
        cout << "sorry the file could not be opened";
    }
    double valueFromFile;
    while (file >> valueFromFile)
    {
        double area=valueFromFile;
        file >> valueFromFile;
        double perimeter=valueFromFile;
        file >> valueFromFile;
        double compactness=valueFromFile;
        file >> valueFromFile;
        double kernelLength=valueFromFile;
        file >> valueFromFile;
        double kernelWidth=valueFromFile;
        file >> valueFromFile;
        double assymetryCoefficient=valueFromFile;
        file >> valueFromFile;
        double kernelGroove=valueFromFile;
        file >> valueFromFile; // takes care of extra value
        WheatKernel *wk = new WheatKernel(area, perimeter, compactness, kernelLength, kernelWidth,
                                          assymetryCoefficient, kernelGroove);
        value.push_back(*wk);
    }
    
    file.close();
    
}

int main()
{
    vector<WheatKernel> objects;
    loadObjects(objects);
    
}

