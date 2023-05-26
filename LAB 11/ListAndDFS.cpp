#include <iostream>
#include <stack>
#include <queue>
using namespace std;
// implimenting the graph by adjacency list
struct node{
    int data;
    node* next;
};
struct graph{
    int V;
    node** adjList;
};
node* createNode(int data){
    node* newNode = new node;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
graph* createGraph(int V){
    graph* newGraph = new graph;
    newGraph->V = V;
    newGraph->adjList = new node*[V];
    for(int i=0;i<V;i++){
        newGraph->adjList[i] = NULL;
    }
    return newGraph;
}
void addEdge(graph* Graph,int src,int dest){
    node* newNode = createNode(dest);
    newNode->next = Graph->adjList[src];
    Graph->adjList[src] = newNode;
    newNode = createNode(src);
    newNode->next = Graph->adjList[dest];
    Graph->adjList[dest] = newNode;
}
void printGraph(graph* Graph){
    for(int i=0;i<Graph->V;i++){
        node* temp = Graph->adjList[i];
        cout<<"Adjacency List of vertex "<<i<<": ";
        while(temp){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
}
// Implimenting DFS on the graph using Stacks
void DFS(graph* Graph,int src){
    stack<int> S;
    bool visited[Graph->V];
    for(int i=0;i<Graph->V;i++){
        visited[i] = false;
    }
    S.push(src);
    visited[src] = true;
    while(!S.empty()){
        int u = S.top();
        S.pop();
        cout<<u<<" ";
        node* temp = Graph->adjList[u];
        while(temp){
            if(!visited[temp->data]){
                S.push(temp->data);
                visited[temp->data] = true;
            }
            temp = temp->next;
        }
    }
}
// Implement the recursive method of DFS.
void DFSRec(graph* Graph,int src,bool visited[]){
    visited[src] = true;
    cout<<src<<" ";
    node* temp = Graph->adjList[src];
    while(temp){
        if(!visited[temp->data]){
            DFSRec(Graph,temp->data,visited);
        }
        temp = temp->next;
    }
}
// Implimenting BFS on the graph using Queue
void BFS(graph* Graph,int src){
    queue<int> Q;
    bool visited[Graph->V];
    for(int i=0;i<Graph->V;i++){
        visited[i] = false;
    }
    Q.push(src);
    visited[src] = true;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        cout<<u<<" ";
        node* temp = Graph->adjList[u];
        while(temp){
            if(!visited[temp->data]){
                Q.push(temp->data);
                visited[temp->data] = true;
            }
            temp = temp->next;
        }
    }
}




int main(){
    int V = 5;
    graph* Graph = createGraph(V);
    addEdge(Graph,0,1);
    addEdge(Graph,0,4);
    addEdge(Graph,1,2);
    addEdge(Graph,1,3);
    addEdge(Graph,1,4);
    addEdge(Graph,2,3);
    addEdge(Graph,3,4);
    printGraph(Graph);
    cout<<"DFS: ";
    DFS(Graph,0);
    cout<<endl;
    cout<<"DFS Recursive: ";
    bool visited[V];
    for(int i=0;i<V;i++){
        visited[i] = false;
    }
    DFSRec(Graph,0,visited);
    cout<<endl;
    cout<<"BFS: ";
    BFS(Graph,0);
    cout<<endl;
    
    
    
    
    return 0;
}