// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Include this file to access Graph representation implemented using an
// Adjacency Matrix.
#ifndef GRMATH
#define GRMATH

#include <stdio.h>
#include <ctype.h>
#include <assert.h>
// Used by the mark array
#define UNVISITED 0
#define VISITED 1

#include "graph.h"

// Implementation for the adjacency matrix representation
class Graphm : public Graph
{
private:
    int numVertex, numEdge; // Store number of vertices, edges
    double **matrix;           // Pointer to adjacency matrix
    double *mark;              // Pointer to mark array
public:
    Graphm(int numVert)     // Constructor
    {
        Init(numVert);
    }

    ~Graphm()         // Destructor
    {
        delete [] mark; // Return dynamically allocated memory
        for (int i = 0; i < numVertex; i++)
            delete [] matrix[i];
        delete [] matrix;
    }

    void Init(int n)   // Initialize the graph
    {
        int i;
        numVertex = n;
        numEdge = 0;
        mark = new double[n];     // Initialize mark array
        for (i = 0; i < numVertex; i++)
            mark[i] = UNVISITED;
        matrix = (double**) new double*[numVertex]; // Make matrix
        for (i = 0; i < numVertex; i++)
            matrix[i] = new double[numVertex];
        for (i = 0; i < numVertex; i++) // Initialize to 0 weights
            for (int j = 0; j < numVertex; j++)
                matrix[i][j] = 0;
    }

    int n()
    {
        return numVertex;    // Number of vertices
    }
    int e()
    {
        return numEdge;    // Number of edges
    }

    // Return first neighbor of "v"
    int first(int v)
    {
        for (int i = 0; i < numVertex; i++)
            if (matrix[v][i] != 0) return i;
        return numVertex;           // Return n if none
    }

    // Return v's next neighbor after w
    int next(int v, int w)
    {
        for(int i = w + 1; i < numVertex; i++)
            if (matrix[v][i] != 0)
                return i;
        return numVertex;           // Return n if none
    }

    // Set edge (v1, v2) to "wt"
    void setEdge(int v1, int v2, double wt)
    {
//   Assert(wt>0, "Illegal weight value");
        assert(wt > 0);
        if (matrix[v1][v2] == 0) numEdge++;
        matrix[v1][v2] = wt;
    }

    void delEdge(int v1, int v2)   // Delete edge (v1, v2)
    {
        if (matrix[v1][v2] != 0) numEdge--;
        matrix[v1][v2] = 0;
    }

    bool isEdge(int i, int j) // Is (i, j) an edge?
    {
        return matrix[i][j] != 0;
    }

    double weight(int v1, int v2)
    {
        return matrix[v1][v2];
    }
    double getMark(int v)
    {
        return mark[v];
    }
    void setMark(int v, double val)
    {
        mark[v] = val;
    }

    int getInDegree(int v)   // 求顶点v的入度
    {
        int result = 0;

        //............... 在此行以下插入补充代码
        for(int i=0;i<numVertex;i++)
		if(isEdge(i,v)) result++; 
        //............... 在此行以上插入补充代码
        return result;
    }

    int getOutDegree(int v)    // 求顶点v的出度
    {
        int result = 0;
        //............... 在此行以下插入补充代码
        for(int i=0;i<numVertex;i++)
		if(isEdge(v,i)) result++; 
        //............... 在此行以上插入补充代码
        return result;
    }
};
# endif // GRMATH
