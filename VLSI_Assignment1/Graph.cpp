//
//  Graph.cpp
//  VLSI_Assignment1
//
//  Created by Vijay Karthik on 8/30/12.
//  Copyright (c) 2012 Vijay Karthik. All rights reserved.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include "Graph.h"
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;
typedef Matrix<double, Dynamic, Dynamic> Mat2D;

class Graph
{
    Mat2D * adjMat;
    int numVertices;
    int numEdges;
    
    int getNumVertices(string line)
    {
        istringstream iss(line);
        string sub;
        iss >> sub;
        return atoi(sub.c_str());
    }
    
    int getNumEdges(string line)
    {
        istringstream iss(line);
        string sub;
        iss >> sub;
        iss >> sub;
        return atoi(sub.c_str());
    }
    
    void updateAdjMat(string line, int i)
    {
        istringstream iss(line);
        do {
            string sub;
            iss >> sub;
            int nbr = atoi(sub.c_str());
            (*adjMat)(nbr,i) = 1;
            (*adjMat)(i, nbr) = 1;
            
        } while (iss);
    }
    
public:
    
    void Partitioner(double imbalance)
    {
       // omp_set_num_threads(4);
        // setNbThreads(4); // 4 Threads
        // cout << nbThreads(4) <<endl;
        SelfAdjointEigenSolver<Mat2D> eigensolver(*adjMat);
        if (eigensolver.info() != Success) abort();
        cout << "Eigenvalues" << endl;
        cout << eigensolver.eigenvalues();
        cout << endl << "Eigenvectors" << endl;
        cout << eigensolver.eigenvectors();
    }
    
    Graph(string fileName)
    {
        ifstream graphFile(fileName.c_str());
        if (graphFile.is_open())
        {
            string line;
            getline(graphFile, line);
            this->numVertices = getNumVertices(line);
            this->numEdges = getNumEdges(line);
            this->adjMat = new Mat2D(this->numVertices + 1, this->numVertices + 1);
            
            for(int i = 0; i < this->numVertices; i++)
            {
                getline(graphFile, line);
                updateAdjMat(line, i);
            }
        }
    }
};


