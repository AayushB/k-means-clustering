//
//  WheatKernel.h
//  K-Means-Clustering
//
//  Created by Aayush Bhandari on 5/13/14.
//  Copyright (c) 2014 Aayush Bhandari. All rights reserved.
//

#ifndef K_Means_Clustering_WheatKernel_h
#define K_Means_Clustering_WheatKernel_h

class WheatKernel
{
  
public:
    WheatKernel();
    WheatKernel( double area,
                double perimeter,
                double compactness,
                double kernelLength,
                double kernelWidth,
                double asymmetryCoeff,
                double lengthKernelGrove);
    double getArea();
    double getPerimeter();
    double getCompactness();
    double getKernelLength();
    double getKernelWidth();
    double getAsymmetryCoeff();
    double getLengthKernelGrove();
    
    void setArea(double value);
    void setPerimeter(double value);
    void setCompactness(double value);
    void setKernelLength(double value);
    void setKernelWidth(double value);
    void setAsymmetryCoeff(double value);
    void setLengthKernelGrove(double value);

private:
    double area;
    double perimeter;
    double compactness;
    double kernelLength;
    double kernelWidth;
    double asymmetryCoeff;
    double lengthKernelGrove;
};


#endif
