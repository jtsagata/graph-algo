#include <fstream>
#include <iostream>
#include <sstream>

#include <list>
#include <stack>
#include <vector>

#include <algorithm>
#include <iterator>

using nodeIndex = unsigned int;

// Class to represent a graph
class Graph {
public:
  explicit Graph(nodeIndex V) {
    this->V = V;
    adj = new std::list<nodeIndex>[V];
    data.resize(V);
    for (auto i = 0; i < V; i++) {
      data[i] = std::string("n") + std::to_string(i);
    }
  }

  void setData(nodeIndex v, std::string name) {
    data[v] = std::move(name);
  }

  std::string getNode(nodeIndex v) {
    return data[v];
  }

  void addEdge(nodeIndex v, nodeIndex w) {
    adj[v].push_back(w);
  }

  void saveAsPNG(const std::string &fname) {
    std::stringstream ss;
    ss << "digraph {\n";
    for (int i = 0; i < V; i++) {
      ss << "  " << i << " [label=\"" << data[i] << "\"]\n";
      for (auto j : adj[i]) {
        ss << "  " << i << " -> " << j << "\n";
      }
    }
    ss << "}";
    std::ofstream os("trans.dot");
    os << ss.str();
    os.close();

    auto cmd = std::string("dot -Tpng trans.dot -o ") + fname;
    std::system(cmd.c_str());
  }

  int isConnected(nodeIndex i, nodeIndex j) {
    auto connections = adj[i];
    bool found = (std::find(connections.begin(), connections.end(), j) !=
                  connections.end());
    if (found)
      return 1;
    return 0;
  }

  void transitiveCloure() {
    // reach[][] will be the DP matrix, each element
    // will have the shortest distance between pairs.
    int reach[V][V];

    for (nodeIndex i = 0; i < V; i++)
      for (nodeIndex j = 0; j < V; j++)
        reach[i][j] = isConnected(i, j);

    // For algorithm look at page 636 of Cormen (greek version)
    for (auto k = 0; k < V; k++)
      // Pick all vertices as source
      for (auto i = 0; i < V; i++)
        // Pick all vertices as destination
        for (auto j = 0; j < V; j++) {
//          reach[i][j] =
//              isConnected(i, j) || (isConnected(i, k) && isConnected(k, j));
            reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
        }

    // Print table in latex format
    std::cout << "\t&";
    for (nodeIndex j = 0; j < V; j++)
      std::cout << data[j] << "\t&";
    std::cout << "\\\\\n";
    std::cout << "\\hline\\hline\n";

    for (nodeIndex i = 0; i < V; i++) {
      std::cout << data[i] << "\t&";
      for (nodeIndex j = 0; j < V; j++)
        std::cout << reach[i][j] << "\t\t&";
      std::cout << "\\\\\n";
    }


    // TODO: Create a copy constructor.
    // Create a new graph
    Graph gtrans(V);
    for(auto l=0; l<V; l++){
      gtrans.setData(l,getNode(l));
    }

    for (auto i = 0; i < V; i++)
      for (auto j = 0; j < V; j++)
        if (reach[i][j] )
          gtrans.addEdge(i,j);

    // Print the transitive graph
    gtrans.saveAsPNG("../gflight-trans.png");
  }

private:
  nodeIndex V;
  std::list<nodeIndex> *adj;
  std::vector<std::string> data;
}; // End class Graph

// Driver program to test above functions
int main() {
  Graph g(4);

  Graph flights(7);
  flights.setData(0, "SFO");
  flights.setData(1, "BOS");
  flights.setData(2, "ORD");
  flights.setData(3, "JFK");
  flights.setData(4, "DFW");
  flights.setData(5, "LAX");
  flights.setData(6, "MIA");

  flights.addEdge(1, 3);
  flights.addEdge(1, 6);
  flights.addEdge(2, 4);
  flights.addEdge(3, 0);
  flights.addEdge(3, 4);
  flights.addEdge(3, 6);
  flights.addEdge(4, 2);
  flights.addEdge(4, 5);
  flights.addEdge(5, 2);
  flights.addEdge(6, 4);
  flights.addEdge(6, 5);

  flights.saveAsPNG("../gflight.png");
  flights.transitiveCloure();

  return 0;
}