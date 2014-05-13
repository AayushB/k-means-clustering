//
//  WheatKernel.cpp
//  K-Means-Clustering
//
//  Created by Aayush Bhandari on 5/13/14.
//  Copyright (c) 2014 Aayush Bhandari. All rights reserved.
//

#include "WheatKernel.h"

WheatKernel::WheatKernel()
{
    //add stuff later
}

WheatKernel:: WheatKernel( double area,
                          double perimeter,
                          double compactness,
                          double kernelLength,
                          double kernelWidth,
                          double asymmetryCoeff,
                          double lengthKernelGrove)
{
    this->area=area;
    this->perimeter=perimeter;
    this->compactness=compactness;
    this->kernelWidth=kernelWidth;
    this->kernelLength=kernelLength;
    this->asymmetryCoeff=asymmetryCoeff;
    this->lengthKernelGrove=lengthKernelGrove;
}

double WheatKernel::getArea()
{
    return area;
}

double WheatKernel::getAsymmetryCoeff()
{
    return asymmetryCoeff;
}

double WheatKernel::getCompactness()
{
    return compactness;
}

double WheatKernel::getKernelLength()
{
    return kernelLength;
}

double WheatKernel::getKernelWidth()
{
    return kernelWidth;
}

double WheatKernel::getLengthKernelGrove()
{
    return lengthKernelGrove;
}

double WheatKernel::getPerimeter()
{
    return perimeter;
}