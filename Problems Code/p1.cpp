/*
  • In this problem we used adjacency matrix to store the graph,
    Then the time complexity will be O(|V|*|V|) and It can be reduced to
    O(|E|*(log|V|)) using adjacency list and binary heap.

  • In Prim’s MST algorithm we create a MST by picking edges that have minimum
    weight one by one. To do this we maintain two sets (two arrays of vertices):-
    • a set (array) of the vertices already included in MST.
    • a set (array) of the vertices not yet included in MST.

  • The Greedy algorithm (choice) here is to pick the edge with minimum weight
    that connects the two sets (two arrays of vertices) one by one at a time.

  • |V| -> Total Number Of Vertices.
  • |E| -> Total Number Of Edges.
*/

#include <iostream>
using namespace std;

// Global variable to store number of vertices in the graph.
const int numberOfVertices = 7;
// Global variable to store starting vertex (V1).
const int startingVertex = 0;
// Global variable to store total cost (weight).
int totalCost = 0;
// Function to construct and print MST for a graph represented using prim algorithm
void primMST(int [][numberOfVertices]);
// Function to find the vertex with minimum weight, from the set of vertices not yet included in MST
int minWeight(int [], bool []);
// Function to print the constructed MST stored in constructedMST[]
void printMST(int [],int [][numberOfVertices]);


int main()
{
    int graph[][numberOfVertices] = { { 0, 2, 4, 1, 0, 0, 0 },
						              { 2, 0, 0, 3, 10, 0, 0 },
						              { 4, 0, 0, 2, 0, 5, 0 },
						              { 1, 3, 2, 0, 7, 8, 4 },
						              { 0, 10, 0, 7, 0, 0, 6 },
						              { 0, 0, 5, 8, 0, 0, 1 },
						              { 0, 0, 0, 4, 6, 1, 0 } };

	primMST(graph);
	return 0;
}

void primMST(int graph[][numberOfVertices])
{
    // Variable to Pick the vertex with minimum weight from the set of vertices not yet included in MST
    int minWeightVertex;
    // Array to store constructed MST
    int constructedMST[numberOfVertices];
    // Weights values used to pick minimum weight edge in cut
    int weights[numberOfVertices];
    // To represent set of visited vertices that included in MST
    bool mstVisitedVertices[numberOfVertices];

    // Initialize minimum weight of all Vertices as INFINITE and mark all Vertices as not included in MST.
    for (int i = 0; i < numberOfVertices; i++)
    {
        weights[i] = INT_MAX;
        mstVisitedVertices[i] = false;
    }

    // Set minimum weight of starting vertex to zero, so that this vertex is picked as first vertex.
    weights[startingVertex] = 0;
    // First node is always root of MST
    constructedMST[startingVertex] = -1;

    // The constructed MST will have V vertices
    for (int i = 0; i < numberOfVertices - 1; i++)
    {
        minWeightVertex = minWeight(weights, mstVisitedVertices);

        // Add the picked vertex to the MST Set
        mstVisitedVertices[minWeightVertex] = true;

        for (int v = 0; v < numberOfVertices; v++)
        {
            if (graph[minWeightVertex][v] != 0 && mstVisitedVertices[v] == false && graph[minWeightVertex][v] < weights[v])
            {
                constructedMST[v] = minWeightVertex;
                weights[v] = graph[minWeightVertex][v];
            }
        }
    }

    // print the constructed MST
    printMST(constructedMST, graph);
}

int minWeight(int weights[], bool MSTVertices[])
{
	int minWeight = INT_MAX, min_index;
	for (int v = 0; v < numberOfVertices; v++)
    {
        if (MSTVertices[v] == false && weights[v] < minWeight)
        {
            minWeight = weights[v];
            min_index = v;
        }
    }
	return min_index;
}

void printMST(int constructedMST[],int graph[][numberOfVertices])
{
	cout << "The Minimum Spanning Tree Is :" << endl;
	cout << "------------------------------" << endl;
	for (int i = 1; i < numberOfVertices; i++)
    {
        totalCost += graph[i][constructedMST[i]];
        cout << "V" << constructedMST[i] + 1 << " --" << graph[i][constructedMST[i]] << "--> " << "V" << i+1 << endl;
    }
    cout << "------------------------------" << endl;
    cout << "The Total Cost (Weight) = " << totalCost << endl;
}
