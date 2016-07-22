
/*
* ============================================================================
*
* Author: Tatyana Vlaskin
* Course: CS 261
* Assignment 7
* Created: 11/30/2014
* File name: graph.c
* Description: graph implementation
* References:
*   1. Lecture notes
*   2. Worksheet 41
*   3. http://stackoverflow.com/questions/2978065/writing-depth-first-search-in-c
*   4. http://www.chegg.com/homework-help/questions-and-answers/include-graphh-include-include-include-include-cirlistdequeh-void-creategraph1-graph-g-ver-q4248082
*   5. piazza
*   6. https://github.com/robertkety/dataStructures
*   7. https://github.com/shawnharmsen/
*
* ============================================================================
*/


#include "graph.h"

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "cirListDeque.h"

void createGraph1(Graph* g)
{
	Vertex* firstVert;
	Vertex* secondVert;
	int i;
	srand(3);

	g->numVertices = 3;
	setupVertices(g);

	g->numEdges = 3;
	for(i = 0; i < g->numEdges; ++i)
	{
		firstVert = &g->vertexSet[i];
		secondVert = &g->vertexSet[(i+1) % g->numVertices];
		setupEdge(g, firstVert, secondVert);
	}
}

void createGraph2(Graph* g)
{
	Vertex* firstVert;
	Vertex* secondVert;
	int i;
	srand(57);

	g->numVertices = 8;
	setupVertices(g);

	g->numEdges = 10;
	for(i = 0; i < g->numEdges; ++i)
	{
		firstVert = &g->vertexSet[rand() % g->numVertices];
		secondVert = firstVert;
		while(firstVert == secondVert || isAdjacent(firstVert, secondVert))
			secondVert = &g->vertexSet[rand() % g->numVertices];

		setupEdge(g, firstVert, secondVert);
	}
}

void createGraph3(Graph* g)
{
	Vertex* firstVert;
	Vertex* secondVert;
	int i;
	srand(33);

	g->numVertices = 26;
	setupVertices(g);

	g->numEdges = 10;
	for(i = 0; i < g->numEdges; ++i)
	{
		firstVert = &g->vertexSet[rand() % g->numVertices];
		secondVert = firstVert;
		while(firstVert == secondVert || isAdjacent(firstVert, secondVert))
			secondVert = &g->vertexSet[rand() % g->numVertices];

		setupEdge(g, firstVert, secondVert);
	}
}

void createGraph4(Graph* g)
{
	Vertex* firstVert;
	Vertex* secondVert;
	int i;
	srand(9875);

	g->numVertices = 26;
	setupVertices(g);

	g->numEdges = 100;
	for(i = 0; i < g->numEdges; ++i)
	{
		firstVert = &g->vertexSet[rand() % g->numVertices];
		secondVert = firstVert;
		while(firstVert == secondVert || isAdjacent(firstVert, secondVert))
			secondVert = &g->vertexSet[rand() % g->numVertices];

		setupEdge(g, firstVert, secondVert);
	}
}

void createGraph5(Graph* g)
{
	int i, j;
	srand(9875);

	g->numVertices = 20;
	setupVertices(g);

	g->numEdges = 400;
	for(i = 0; i < g->numVertices; ++i)
		for(j = i + 1; j < g->numVertices; ++j)
			setupEdge(g, &g->vertexSet[i], &g->vertexSet[j]);
}

/* Initializes all information for the vertices in the graph
 * param: g		Graph whose vertices will be initialized
 * pre: numVertices has been initialized
 */
void setupVertices(Graph* g)
{
	int i;
	g->vertexSet = (Vertex*) malloc(g->numVertices * sizeof(Vertex));
	for(i = 0; i < g->numVertices; ++i)
	{
		g->vertexSet[i].label = 'A' + i;
		g->vertexSet[i].isVisited = 0;
		g->vertexSet[i].neighbors = (Vertex**)malloc(sizeof(Vertex*));
		g->vertexSet[i].numNeighbors = 0;
	}
}

/* Creates all the links necessary to form an edge between the two argument vertices.
 * param: g		Graph in which the vertices reside
 * param: first	Vertex from which the edge will originate
 * param: second	Vertex at which the edge terminates
 * post: all links necessary to form an edge between first and second have been completed.
 */
void setupEdge(Graph* g, Vertex* first, Vertex* second)
{
	first->numNeighbors++;
	second->numNeighbors++;
	first->neighbors = (Vertex**)realloc(first->neighbors, first->numNeighbors * sizeof(Vertex*));
	second->neighbors = (Vertex**)realloc(second->neighbors, second->numNeighbors * sizeof(Vertex*));

	first->neighbors[first->numNeighbors - 1] = second;
	second->neighbors[second->numNeighbors - 1] = first;
}

/* This function prints the graph
 * param: g		Graph to print
 */
void printGraph(Graph* g)
{
	int i, j;
	Vertex* currVert;
	printf("*****\t\t This graph has %d Vertices and %d Edges\n", g->numVertices, g->numEdges);

	/* print the vertex set */
	for(i = 0; i < g->numVertices; ++i)
	{
		currVert = &g->vertexSet[i];
		printf("%c: ", currVert->label);
		for(j = 0; j < currVert->numNeighbors - 1; ++j)
			printf("%c, ", currVert->neighbors[j]->label);
		if(currVert->numNeighbors > 0)
			printf("%c\n", currVert->neighbors[j]->label);
		else printf("\n");
	}
}

/* This function can be used to determine if two vertices are adjacent
 * param: firstVert		Vertex to check neighbors from
 * param: secondVert	Vertex to check neighbors to
 * ret:	boolean (encoded as int) indicating whether or not the vertices
 *		are adjacent (an edge exists between them)
 */
int isAdjacent(Vertex* firstVert, Vertex* secondVert)
{
	int i;
	for(i = 0; i < firstVert->numNeighbors; ++i)
		if(	firstVert->neighbors[i] == secondVert)
			return 1;
	return 0;
}

/* This function clears all the search flags in the graph
 * param: g		Graph to have its flags cleared
 * post: All vertices in the graph should have their search flags turned off
 */
void clearVisited(Graph* g)
{
	int i;
	for(i = 0; i < g->numVertices; ++i)
		g->vertexSet[i].isVisited = 0;
}

/* these two functions provide a recursive version of the depth first search.
 * feel free to use this to check your answers
 * param: g			Graph to perform the search in
 * param: source	Vertex to originate the search from
 * param: destination Vertex to stop the search from (if it is found)
 * ret: boolean indicating whether or not a path exists
 */
int DFSRecursiveHelper(Graph* g, Vertex* currVert, Vertex* destination)
{
	int i;

	currVert->isVisited = 1;
	if(currVert == destination)
		return 1;
	for(i = 0; i < currVert->numNeighbors; ++i)
		if(!currVert->neighbors[i]->isVisited)
			if(DFSRecursiveHelper(g, currVert->neighbors[i], destination))
				return 1;
	return 0;
}
int DFSRecursive(Graph* g, Vertex* source, Vertex* destination)
{
	clearVisited(g);
	return DFSRecursiveHelper(g, source, destination);
}

/* This function should return a boolean (encoded as an int) indicating
 * whether or not a path exists between the argument vertices.
 * param: g			Graph to perform the search in
 * param: source	Vertex to originate the search from
 * param: destination Vertex to stop the search from (if it is found)
 * ret: boolean indicating whether or not a path exists
 */

 /*
 From the worksheet 41:
findReachable (graph g, vertex start) {
create a set of reachable vertices, initially empty. call this r.
create a container for vertices known to be reachable. call this c
add start vertex to container c
while the container c is not empty {
      remove first entry from the container c, assign to v
      if v is not already in the set of reachable vertices r {
          add v to the reachable set r
          add the neighbors of v to the container c
      }
 }
return r
}


If a stack is used, it is termed depth first search
{
*/

int DFS(Graph* g, Vertex* source, Vertex* destination){
	/* FIXME you will write this */
    clearVisited(g);
    struct cirListDeque *stack = malloc(sizeof(struct cirListDeque));
    Vertex *current; /* current vertex is declared*/
    initCirListDeque(stack); /*Initialize deque*/
    addBackCirListDeque(stack, source); /* elements are added to the back of the queue*/
    while(!isEmptyCirListDeque(stack)){/* loop through the stack*/
        current = backCirListDeque(stack); /*add start vertex to the back of the container c*/
        removeBackCirListDeque(stack);/*remove first entry from the container c, assign to v*/
        if(current->label == destination->label)/* if its already in the container return 1*/
            return 1;
        else {
            if(!current->isVisited)/*if v is not already in the set of reachable vertices r*/
                current->isVisited = 1;/*mark as visited*/
           int i;
            for (i = 0; i < current->numNeighbors; i++){/* check neighbors and if not visited, add to stack*/
                if(current->label == destination->label) /*if the neighbors was already visited*/
                    return 1;/*return true*/
                else{
                    if(!current->neighbors[i]->isVisited) /* if the neibour was not visited*/
                        addBackCirListDeque(stack, current->neighbors[i]);/*add the neighbors of v to the container c*/
                }
            }
        }
    }
    return 0;
}

/* This function should return a boolean (encoded as an int) indicating
 * whether or not a path exists between the argument vertices.
 * param: g			Graph to perform the search in
 * param: source	Vertex to originate the search from
 * param: destination Vertex to stop the search from (if it is found)
 * ret: boolean indicating whether or not a path exists
  If a queue is used, it is termed breadth first search
 */

int BFS(Graph* g, Vertex* source, Vertex* destination){
	/* FIXME you will write this */
    clearVisited(g);
    struct cirListDeque *queue = malloc(sizeof(struct cirListDeque));
    Vertex *current;
    initCirListDeque(queue);
    addBackCirListDeque(queue, source);/* elements are added to the back of the queue*/
    while(!isEmptyCirListDeque(queue)){/* loop through the queue*/
        current = frontCirListDeque(queue);/*add start vertex to the back of the container c*/
        removeFrontCirListDeque(queue);/*remove first entry from the container c, assign to v*/
        if(current->label == destination->label)/* if its already in the container return 1*/
            return 1; /*return true*/
        else{
            if(!current->isVisited)/*if v is not already in the set of reachable vertices r*/
                current->isVisited = 1;/*mark as visited*/
            int i;
            for (i = 0; i < current->numNeighbors; i++){/* check neighbors and if not visited, add to stack*/
                if(current->label == destination->label)/*if the neighbors was already visited*/
                    return 1;/*mark as visited*/
                else{
                    if(!current->neighbors[i]->isVisited) /* if the neibour was not visited*/
                    addBackCirListDeque(queue, current->neighbors[i]);/*add the neighbors of v to the container c*/
                }
            }
        }
    }
    return 0;
}
