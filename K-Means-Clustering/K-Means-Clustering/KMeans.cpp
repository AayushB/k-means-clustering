//
//  KMeans.cpp
//  K-Means-Clustering
//
//  Created by Aayush Bhandari on 5/14/14.
//  Copyright (c) 2014 Aayush Bhandari. All rights reserved.
//

#include "KMeans.h"
#define MAX_ITERATIONS 5

KMeans::KMeans(vector<WheatKernel> dataInput, int k)
{
    
    this->k=k;
    
    // Initialize centroids randomly
    centroids= new WheatKernel[k];
    
    centroids= getRandomCentroids(centroids, k);
    
    int iterations=0;
    WheatKernel* oldCentroids=NULL;
    labels = nullptr;
    
    // Run the main k-means algorithm
    while(!(shouldStop(oldCentroids, centroids, iterations)))
    {
        oldCentroids=centroids;
        iterations+=1;
        
        labels= getLabels(dataInput, centroids, k);
        
        printCentroids(); cout  << endl <<endl;
        centroids=getCentroids(dataInput, labels, k);
        data=dataInput;
    }
    
}

// Function: Should Stop
// -------------
// Returns True or False if k-means is done. K-means terminates either
// because it has run a maximum number of iterations OR the centroids
// stop changing.
bool KMeans::shouldStop(WheatKernel* oldCentroids, WheatKernel* centroids, int iterations)
{
    if (iterations > (MAX_ITERATIONS-1))
    {
        return true;
    }
    
    return oldCentroids==centroids;

}



WheatKernel* KMeans::getRandomCentroids(WheatKernel* centroids, int k)
{
    
    for(int i=0; i<k ; i++)
    {
        
        rand();
        double randArea = ((float) rand() / (RAND_MAX));
        double randPerimeter = ((double) rand() / (RAND_MAX));
        double randCompactness = ((double) rand() / (RAND_MAX));
        double randKernelLength = ((double) rand() / (RAND_MAX));
        double randKernelWidth = ((double) rand() / (RAND_MAX));
        double randAsymmetryCoeff = ((double) rand() / (RAND_MAX));
        double randLengthKernelGrove = ((double) rand() / (RAND_MAX));
        
        
        (centroids+i)->setArea(randArea);
        (centroids+i)->setPerimeter(randPerimeter);
        (centroids+i)->setCompactness(randCompactness);
        (centroids+i)->setKernelLength(randKernelLength);
        (centroids+i)->setKernelWidth(randKernelWidth);
        (centroids+i)->setAsymmetryCoeff(randAsymmetryCoeff);
        (centroids+i)->setLengthKernelGrove(randLengthKernelGrove);
    }
    return centroids;
}

// Function: Get Labels
// -------------
// Returns a label for each piece of data in the dataset.
int* KMeans:: getLabels(vector<WheatKernel>data, WheatKernel* centroids, int k)
{
    labels = new int[data.size()];
    for(int i=0; i<data.size(); i++)
    {
        int minDistance=eculedianDistance(data.at(i),*(centroids));
        int desiredCentroid=0;
        for(int j=0; j<k; j++)
        {
            if (minDistance > eculedianDistance(data.at(i),*(centroids+j) ))
            {
                minDistance=eculedianDistance(data.at(i),*(centroids+j));
                desiredCentroid=j;
            }
        }
        
        *(labels+i)=desiredCentroid;
    }
    return labels;
}


// Function: Get Centroids
// -------------
// Returns k random centroids, each of dimension n.
WheatKernel* KMeans::getCentroids(vector<WheatKernel> data, int* labels, int k)
{
    WheatKernel* tempCentroids= new WheatKernel[k];
    for(int i=0; i<k; i++)
    {
        double geometricMeanArea=0;
        double geometricMeanPerimeter=0;
        double geometricMeanCompactness=0;
        double geometricMeanKernelLength=0;
        double geometricMeanKernelWidth=0;
        double geometricMeanAsymmetryCoeff=0;
        double geometricMeanLengthKernelGrove=0;
        
        int count=0;
        for(int j=0; j< data.size(); j++)
        {
            if(*(labels+j)==i)
            {
                geometricMeanArea+= log10(data.at(j).getArea());
                geometricMeanPerimeter+= log10(data.at(j).getPerimeter());
                geometricMeanCompactness+= log10(data.at(j).getCompactness());
                geometricMeanKernelLength+= log10(data.at(j).getKernelLength());
                geometricMeanKernelWidth+= log10(data.at(j).getKernelWidth());
                geometricMeanAsymmetryCoeff+= log10(data.at(j).getAsymmetryCoeff());
                geometricMeanLengthKernelGrove+= log10(data.at(j).getLengthKernelGrove());
                
                count++;
            }
        }
        
        if(count !=0)
        {
            geometricMeanArea/= count;
            geometricMeanPerimeter/= count;
            geometricMeanCompactness/= count;
            geometricMeanKernelLength/= count;
            geometricMeanKernelWidth/= count;
            geometricMeanAsymmetryCoeff/= count;
            geometricMeanLengthKernelGrove/= count;

        }
        geometricMeanArea = pow(10,geometricMeanArea);
        (tempCentroids+i)->setArea(geometricMeanArea);
        geometricMeanPerimeter = pow(10,geometricMeanPerimeter);
        (tempCentroids+i)->setPerimeter(geometricMeanPerimeter);
        geometricMeanCompactness = pow(10,geometricMeanCompactness);
        (tempCentroids+i)->setCompactness(geometricMeanCompactness);
        geometricMeanKernelLength = pow(10,geometricMeanKernelLength);
        (tempCentroids+i)->setKernelLength(geometricMeanKernelLength);
        geometricMeanKernelWidth = pow(10,geometricMeanKernelWidth);
        (tempCentroids+i)->setKernelWidth(geometricMeanKernelWidth);
        geometricMeanAsymmetryCoeff = pow(10,geometricMeanAsymmetryCoeff);
        (tempCentroids+i)->setAsymmetryCoeff(geometricMeanAsymmetryCoeff);
        geometricMeanLengthKernelGrove = pow(10,geometricMeanLengthKernelGrove);
        (tempCentroids+i)->setLengthKernelGrove(geometricMeanLengthKernelGrove);

    }
    
    centroids=tempCentroids;
    return tempCentroids;

}

//finds the distance between two kernel objects
double KMeans::eculedianDistance(WheatKernel value1, WheatKernel value2)
{
   
    return sqrt(pow((value1.getArea()-value2.getArea()),2.0)+
                pow((value1.getPerimeter()-value2.getPerimeter()),2.0)+
                pow((value1.getCompactness()-value2.getCompactness()),2.0)+
                pow((value1.getKernelLength()-value2.getKernelLength()),2.0)+
                pow((value1.getKernelWidth()-value2.getKernelWidth()),2.0)+
                pow((value1.getAsymmetryCoeff()-value2.getAsymmetryCoeff()),2.0)+
                pow((value1.getLengthKernelGrove()-value2.getLengthKernelGrove()),2.0));
}


void KMeans::printData()
{
    for (int i=0; i<data.size(); i++ )
    {
        cout << i << "# " ;
        cout << data.at(i).getArea()         << "   "
        << data.at(i).getPerimeter()         << "   "
        << data.at(i).getCompactness()       << "   "
        << data.at(i).getKernelLength()      << "   "
        << data.at(i).getKernelWidth()       << "   "
        << data.at(i).getAsymmetryCoeff()    << "   "
        << data.at(i).getLengthKernelGrove() << "   "
        <<  " " << *(labels+i) <<endl;
        
    }
}

void KMeans:: printCentroids()
{
    for(int i=0; i<k ; i++)
    {
        cout << (centroids+i)->getArea() << " ";
         cout << (centroids+i)->getPerimeter() << " ";
        cout << (centroids+i)->getCompactness() << " ";
         cout << (centroids+i)->getKernelLength() << " ";
         cout << (centroids+i)->getKernelWidth() << " ";
         cout << (centroids+i)->getAsymmetryCoeff() << " ";
         cout << (centroids+i)->getLengthKernelGrove() << endl;
        
    }
}



