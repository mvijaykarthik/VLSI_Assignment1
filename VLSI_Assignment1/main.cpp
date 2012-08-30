//
//  main.cpp
//  VLSI_Assignment1
//
//  Created by Vijay Karthik on 8/30/12.
//  Copyright (c) 2012 Vijay Karthik. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <Eigen/Sparse>
#include "Graph.cpp"
using namespace Eigen;
using namespace std;

int main(int argc, const char * argv[])
{

    Matrix2f A;
    A << 1, 2, 2, 3;
    cout << "Here is the matrix A:\n" << A << endl;
    SelfAdjointEigenSolver<Matrix2f> eigensolver(A);
    if (eigensolver.info() != Success) abort();
    cout << "The eigenvalues of A are:\n" << eigensolver.eigenvalues() << endl;
    cout << "Here's a matrix whose columns are eigenvectors of A \n"
    << "corresponding to these eigenvalues:\n"
    << eigensolver.eigenvectors() << endl;
    // insert code here...
    Graph g("/Volumes/Files/Programs/gh.txt");
    std::cout << "Hello, World!\n";
    g.Partitioner(0);
    return 0;
}

