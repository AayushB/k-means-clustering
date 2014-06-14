/**
 * Statement of Purpose:
 *
 * Aayush Bhandari
 * 910186009
 * aayushb@mail.sfsu.edu
 * Xcode Version 4.6.2 (4H1003)
 * May 16th, 2014
 * Copyright (c) 2014 Aayush Bhandari. All rights reserved.
 *
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "WheatKernel.h"
#include "KMeans.h"
using namespace std;

//**************************************************************
//                Functions for generating normalized values
//**************************************************************



void normalizeArea(vector<WheatKernel>& objects)
{
    
    double min = 0, max = 0, range = 0, normalizedValue = 0;
    
    min = objects.at(0).getArea();
    max = objects.at(0).getArea();
    
    for (int i = 0; i < objects.size(); i++)
    {
        if (objects.at(i).getArea() < min)
        {
            min = objects.at(i).getArea();
        }
        if (objects.at(i).getArea() > max)
        {
            max = objects.at(i).getArea();
        }
    }
    
    range = max - min;
    
    for (int i = 0; i < objects.size(); i++)
    {
        normalizedValue = (objects.at(i).getArea() - min)/range;
        objects.at(i).setArea(normalizedValue);
    }
}

void normalizePerimeter(vector<WheatKernel>& objects)
{
    
    double min = 0, max = 0, range = 0, normalizedValue = 0;
    
    min = objects.at(0).getPerimeter();
    max = objects.at(0).getPerimeter();
    
    for (int i = 0; i < objects.size(); i++)
    {
        if (objects.at(i).getPerimeter() < min)
        {
            min = objects.at(i).getPerimeter();
        }
        if (objects.at(i).getPerimeter() > max)
        {
            max = objects.at(i).getPerimeter();
        }
    }
    
    range = max - min;
    
    for (int i = 0; i < objects.size(); i++)
    {
        normalizedValue = (objects.at(i).getPerimeter() - min)/range;
        objects.at(i).setPerimeter(normalizedValue);
    }
}

void normalizeCompactness(vector<WheatKernel>& objects)
{
    
    double min = 0, max = 0, range = 0, normalizedValue = 0;
    
    min = objects.at(0).getCompactness();
    max = objects.at(0).getCompactness();
    
    for (int i = 0; i < objects.size(); i++)
    {
        if (objects.at(i).getCompactness() < min)
        {
            min = objects.at(i).getCompactness();
        }
        if (objects.at(i).getCompactness() > max)
        {
            max = objects.at(i).getCompactness();
        }
    }
    
    range = max - min;
    
    for (int i = 0; i < objects.size(); i++)
    {
        normalizedValue = (objects.at(i).getCompactness() - min)/range;
        objects.at(i).setCompactness(normalizedValue);
    }
}

void normalizeKernelLength(vector<WheatKernel>& objects)
{
    
    double min = 0, max = 0, range = 0, normalizedValue = 0;
    
    min = objects.at(0).getKernelLength();
    max = objects.at(0).getKernelLength();
    
    for (int i = 0; i < objects.size(); i++)
    {
        if (objects.at(i).getKernelLength() < min)
        {
            min = objects.at(i).getKernelLength();
        }
        if (objects.at(i).getKernelLength() > max)
        {
            max = objects.at(i).getKernelLength();
        }
    }
    
    range = max - min;
    
    for (int i = 0; i < objects.size(); i++)
    {
        normalizedValue = (objects.at(i).getKernelLength() - min)/range;
        objects.at(i).setKernelLength(normalizedValue);
    }
}

void normalizeKernelWidth(vector<WheatKernel>& objects)
{
    
    double min = 0, max = 0, range = 0, normalizedValue = 0;
    
    min = objects.at(0).getKernelWidth();
    max = objects.at(0).getKernelWidth();
    
    for (int i = 0; i < objects.size(); i++)
    {
        if (objects.at(i).getKernelWidth() < min)
        {
            min = objects.at(i).getKernelWidth();
        }
        if (objects.at(i).getKernelWidth() > max)
        {
            max = objects.at(i).getKernelWidth();
        }
    }
    
    range = max - min;
    
    for (int i = 0; i < objects.size(); i++)
    {
        normalizedValue = (objects.at(i).getKernelWidth() - min)/range;
        objects.at(i).setKernelWidth(normalizedValue);
    }
}

void normalizeAsymmetryCoeff(vector<WheatKernel>& objects)
{
    
    double min = 0, max = 0, range = 0, normalizedValue = 0;
    
    min = objects.at(0).getAsymmetryCoeff();
    max = objects.at(0).getAsymmetryCoeff();
    
    for (int i = 0; i < objects.size(); i++)
    {
        if (objects.at(i).getAsymmetryCoeff() < min)
        {
            min = objects.at(i).getAsymmetryCoeff();
        }
        if (objects.at(i).getAsymmetryCoeff() > max)
        {
            max = objects.at(i).getAsymmetryCoeff();
        }
    }
    
    range = max - min;
    
    for (int i = 0; i < objects.size(); i++)
    {
        normalizedValue = (objects.at(i).getAsymmetryCoeff() - min)/range;
        objects.at(i).setAsymmetryCoeff(normalizedValue);
    }
}

void normalizeLengthKernelGrove(vector<WheatKernel>& objects)
{
    
    double min = 0, max = 0, range = 0, normalizedValue = 0;
    
    min = objects.at(0).getLengthKernelGrove();
    max = objects.at(0).getLengthKernelGrove();
    
    for (int i = 0; i < objects.size(); i++)
    {
        if (objects.at(i).getLengthKernelGrove() < min)
        {
            min = objects.at(i).getLengthKernelGrove();
        }
        if (objects.at(i).getLengthKernelGrove() > max)
        {
            max = objects.at(i).getLengthKernelGrove();
        }
    }
    
    range = max - min;
    
    for (int i = 0; i < objects.size(); i++)
    {
        normalizedValue = (objects.at(i).getLengthKernelGrove() - min)/range;
        objects.at(i).setLengthKernelGrove(normalizedValue);
    }
}



//**************************************************************
//                Loading the data from our file
//**************************************************************
void loadObjects(vector<WheatKernel>& value)
{
    string filename;
    cout << "Please enter the file address for your seed file: " ;
    cin >> filename;
    
    //string filename="/Users/Aayush/Desktop/GitHubFolders/k-means-clustering/K-Means-Clustering/K-Means-Clustering/seeds_dataset.txt";
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


//**************************************************************
//                              main
//**************************************************************

int main()
{
    srand(time(NULL));
    vector<WheatKernel> objects;
    loadObjects(objects); //loading values from the file
    //normalizing the vectors
    normalizeArea(objects);
    normalizePerimeter(objects);
    normalizeCompactness(objects);
    normalizeKernelLength(objects);
    normalizeKernelWidth(objects);
    normalizeAsymmetryCoeff(objects);
    normalizeLengthKernelGrove(objects);
    
    //Instantiating kMeans object
    KMeans kmeans( objects, 3);
    
    kmeans.printData(); // printing the data with label at the end
}

