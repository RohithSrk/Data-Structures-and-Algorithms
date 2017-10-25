#include <stdio.h>
#include <stdlib.h>

#define MAX 15

int diGraph = 0;

struct Vertex {
    char label;
    int visited;
};
typedef struct Vertex vertex;

//stack variables
int stack[MAX];

int top = -1;

//graph variables

//array of vertices
struct Vertex *lstVertices[MAX];

//adjacency matrix
int adjMatrix[MAX][MAX];

//vertex count
int vertexCount = 0;

//stack functions

void push(int item) {
    stack[++top] = item;
}

int pop() {
    return stack[top--];
}

int peek() {
    return stack[top];
}

int isStackEmpty() {
    return top == -1;
}

//graph functions

//add vertex to the vertex list
void addVertex(char label) {
    vertex* v = (vertex *) malloc(sizeof(vertex));
    v->label = label;
    v->visited = 0;
    lstVertices[vertexCount++] = v;
}

//add edge to edge array
void addEdge(int start, int end) {
    adjMatrix[start][end] = 1;

    if(!diGraph)
        adjMatrix[end][start] = 1;
}

//display the vertex
void displayVertex(int vertexIndex) {
    printf("%c ", lstVertices[vertexIndex]->label);
}

//get the adjacent unvisited vertex
int getAdjUnvisitedVertex(int vertexIndex) {
    int i;

    for (i = 0; i < vertexCount; i++) {
        if (adjMatrix[vertexIndex][i] == 1 && lstVertices[i]->visited == 0) {
            return i;
        }
    }

    return -1;
}

void depthFirstSearch(int startVertexIndex) {
    int i;

    //mark chosen first vertex as visited
    lstVertices[startVertexIndex]->visited = 1;

    //display the vertex
    displayVertex(startVertexIndex);

    //push vertex index in stack
    push(startVertexIndex);

    while (!isStackEmpty()) {
        //get the unvisited vertex of vertex which is at top of the stack
        int unvisitedVertex = getAdjUnvisitedVertex(peek());

        //no adjacent vertex found
        if (unvisitedVertex == -1) {
            pop();
        } else {
            lstVertices[unvisitedVertex]->visited = 1;
            displayVertex(unvisitedVertex);
            push(unvisitedVertex);
        }
    }

    //stack is empty, search is complete, reset the visited flag
    for (i = 0; i < vertexCount; i++) {
        lstVertices[i]->visited = 0;
    }
}

int main() {
    int i, j, startVertexIndex;

    // set adjacency matrix to 0
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++)
            adjMatrix[i][j] = 0;
    }

    // Set Graph as directed (1) or not (0).
    diGraph = 0;

    addVertex('A');   // 0
    addVertex('B');   // 1
    addVertex('C');   // 2
    addVertex('D');   // 3
    addVertex('E');   // 4

    // Select the vertex index to visit first.
    startVertexIndex = 2; // C

    addEdge(0, 1);    // A - B
    addEdge(0, 2);    // A - C
    addEdge(0, 3);    // A - D
    addEdge(1, 4);    // B - E
    addEdge(2, 4);    // C - E
    addEdge(3, 4);    // D - E

    printf("Depth First Search: ");

    depthFirstSearch(startVertexIndex);

    return 0;
}

/*
    A
   /|\
  / | \
 /  |  \
B  (C)  D
 \  |  /
  \ | /
   \|/
    E

A Graph with start vertex C:
Output:
Depth First Search: C A B E D
*/