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
using namespace std;
#include "Graph.h"


class Graph
{
    int **adjMat;
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
            adjMat[nbr][i] = 1;
            adjMat[i][nbr] = 1;
            
        } while (iss);
    }
    
public:
    Graph(string fileName)
    {
        ifstream graphFile(fileName.c_str());
        if (graphFile.is_open())
        {
            string line;
            getline(graphFile, line);
            this->numVertices = getNumVertices(line);
            this->numEdges = getNumEdges(line);
            this->adjMat = new int*[this->numVertices];
            for (int i = 0; i < this->numVertices; i++)
            {
                this->adjMat[i] = new int[numVertices];
            }
            
            for(int i = 0; i < this->numVertices; i++)
            {
                getline(graphFile, line);
                updateAdjMat(line, i);
            }
        }
    }
};
