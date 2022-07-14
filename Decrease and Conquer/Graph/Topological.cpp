#include <iostream>
#include <list>
#include <vector>
#include <queue>

class Graph {
    int numOfVertices; // number of vertices
    std::list<int>* adj; // Pointer to the adjacency list // Linked list

public:
    // Constructor
    Graph(int numOfVertices);

    //Adding manually edges to the Graph
    void addEdge(int w, int vertex);

    //Topological sort function
    void topSort();
};

Graph::Graph(int numOfVertices) {
    this->numOfVertices = numOfVertices;
    adj = new std::list<int>[numOfVertices]; // creating a linked list in heap
}

void Graph::addEdge(int w, int vertex) {
    adj[w].push_back(vertex); // Adding vertices to the list
}

void Graph::topSort() {
    // Store vertices as in degree and initialize it 0 for all
     std::vector<int> inDegree(numOfVertices, 0);

     // Traversing all adj lists
     for(int i =0; i<numOfVertices;++i)
       // Iterates over vertices in the adjacency list
        for(int &itr : adj[i]){
            inDegree[itr]++;
        };

     //creating queue to enqueue all vertices with 0
     std::queue<int> zeroQueue;
     for(int i = 0 ; i < numOfVertices; i++)
     {
         if(inDegree[i] == 0){
             zeroQueue.push(i);
         }
     }
     //Visited vertex counter
     // topological order storage

     std::vector<int> topOrderStorage;
     int count = 0;

     while(!zeroQueue.empty())
     {
         int vertex = zeroQueue.front(); // extracting from queue
         zeroQueue.pop();
         topOrderStorage.push_back(vertex); // Adding to the topological order;

         for (int &itr: adj[vertex])
         {
             if (--inDegree[itr] == 0)
                 zeroQueue.push(itr);
         }
         count++;
     }
     //Cycle Detection
     if(count != numOfVertices)
         std::cout<<"Can't perform topological sort due to cycle" << std::endl;

     // Print result
     for(int elements : topOrderStorage)
     {
         std::cout << elements << " " << std::endl;
     }
}

int main()
{
    Graph graph(9);
    graph.addEdge(0,6);
    graph.addEdge(1,2);
    graph.addEdge(1,4);
    graph.addEdge(1,6);
    graph.addEdge(3,0);
    graph.addEdge(3,4);
    graph.addEdge(5,1);
    graph.addEdge(7,0);
    graph.addEdge(7,1);


    graph.topSort(); // Perform topological sort



}