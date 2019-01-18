#include <fstream>
#include <iostream>
#include <sstream>

#include <list>
#include <stack>
#include <vector>

#include <algorithm>
#include <iterator>

using nodeIndex = unsigned int;
using std::stack;

class Graph;
void printStack(Graph &graph, stack<nodeIndex> &Stack);

void printList(const std::list<nodeIndex> &results);

// Class to represent a graph
class Graph {
public:
  enum class State { UNVISITED, VISITED };

  // The Constructor
  explicit Graph(nodeIndex V) {
    this->V = V;
    adj = new std::list<nodeIndex>[V];
    states.reserve(V);
    order.reserve(V);
    for (auto i = 0; i < V; i++) {
      states[i] = State::UNVISITED;
      order[i] = -999;
    }
  }

  // Connect 2 Nodes
  void addEdge(nodeIndex v, nodeIndex w) {
    adj[v].push_back(w);
  }

  // Make a png file
  // This needs graphviz installed
  void saveAsPNG(const std::string &fname, bool showOrder = false) {
    std::stringstream ss;
    ss << "strict graph G {\nrankdir=\"LR\";\n";
    ss << "node [shape=\"box\",width=.5];\n";
    for (int i = 0; i < V; i++) {
      if (showOrder)
        ss << "  " << i << " [xlabel=\"" << order[i] << "\", label=\"" << i + 1
           << "\"]\n";
      else
        ss << "  " << i << " [label=\"" << i + 1 << "\"]\n";
      for (auto j : adj[i]) {
        int from = i < j ? i : j;
        int to = i < j ? j : i;
        ss << "  " << from << " -- " << to << "\n";
      }
    }
    ss << "}";
    std::ofstream os("graph-BFS.dot");
    os << ss.str();
    os.close();

    auto cmd = std::string("neato -Tpng graph-BFS.dot -o ") + fname;
    std::system(cmd.c_str());
  }

  // The Driver function
  std::list<nodeIndex> BFS_Sort(nodeIndex v = 0) {
    std::list<nodeIndex> visitList;
    std::fill(states.begin(), states.end(), State::UNVISITED);

    __BFS__Sort(v, visitList);

    // Number the nodes for graphviz visualization
    auto i = 1;
    for (auto it : visitList)
      order[it] = i++;

    return visitList;
  }

private:
  nodeIndex V;
  std::list<nodeIndex> *adj;
  std::vector<State> states;
  std::vector<int> order;

private:
  void __BFS__Sort(nodeIndex v, std::list<nodeIndex> &visitList) {
    states[v] = State::VISITED;
    visitList.emplace_back(v);

    for (auto node : adj[v]) {
      if (states[node] == State::UNVISITED) {
        __BFS__Sort(node, visitList);
      }
    }
  }
}; // End class Graph

// Driver program to test above functions
int main() {
  // Create a graph given in the above diagram
  Graph gg(8);

  gg.addEdge(2, 0);
  gg.addEdge(2, 1);
  gg.addEdge(2, 3);
  gg.addEdge(0, 1);
  gg.addEdge(0, 2);
  gg.addEdge(0, 3);
  gg.addEdge(1, 0);
  gg.addEdge(1, 2);
  gg.addEdge(1, 3);
  gg.addEdge(3, 0);
  gg.addEdge(3, 1);
  gg.addEdge(3, 2);
  gg.addEdge(3, 5);
  gg.addEdge(4, 5);
  gg.addEdge(4, 6);
  gg.addEdge(4, 7);
  gg.addEdge(5, 3);
  gg.addEdge(5, 4);
  gg.addEdge(5, 6);
  gg.addEdge(6, 4);
  gg.addEdge(6, 5);
  gg.addEdge(6, 7);
  gg.addEdge(7, 4);
  gg.addEdge(7, 6);

  gg.saveAsPNG("../BFS.png", false);

  auto pos = 0;

  auto results = gg.BFS_Sort(pos);
  gg.saveAsPNG("../BFS-solution.png", true);

  std::cout << "\n\nBFS Sort starting from :" << pos + 1 << "\n";
  printList(results);

  return 0;
}

void printList(const std::list<nodeIndex> &results) {
  bool first = true;
  for (auto &it : results) {
    if (!first) {
      std::cout << "->";
    }
    auto name = (int)it + 1;
    std::cout << name;
    first = false;
  }
}