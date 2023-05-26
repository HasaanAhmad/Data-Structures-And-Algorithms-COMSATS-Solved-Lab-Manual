#include <iostream>
#define V 4
using namespace std;
// Implements the Graph data structure by Adjacency Matrix.
void init(int graph[][V])
{
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = 0;
}
void addEdge(int graph[][V], int i, int j)
{
    graph[i][j] = 1;
    graph[i][j] = 1;
}
// print the matrix
void printAdjMatrix(int arr[][V]){
    cout<<"Adjacency Matrix: "<<endl;
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
};

 
int main(){
    int graph[V][V];
    init(graph);
    addEdge(graph,0,1);
    addEdge(graph,0,2);
    addEdge(graph,1,2);
    addEdge(graph,2,0);
    addEdge(graph,2,3);
    printAdjMatrix(graph);
    
    return 0;
}