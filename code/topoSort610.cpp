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

// Class to represent a graph
class Graph {
public:
  enum class State { UNVISITED, VISITED };

  // The Constructor
  explicit Graph(nodeIndex V) {
    this->V = V;
    adj = new std::list<nodeIndex>[V];
    data.resize(V);
    states.resize(V);
    order.resize(V);
    for (auto i = 0; i < V; i++) {
      states[i] = State::UNVISITED;
      data[i] = std::string("n") + std::to_string(i);
      order[i] = -999;
    }
  }

  // Name a node
  void setData(nodeIndex v, std::string name) {
    data[v] = std::move(name);
  }

  // Get node Data
  std::string getNode(nodeIndex v) {
    return data[v];
  }

  // Connect 2 Nodes
  void addEdge(nodeIndex v, nodeIndex w) {
    adj[v].push_back(w);
  }

  // Make a png file
  // This needs graphviz installed
  void saveAsPNG(const std::string &fname, bool showOrder = false) {
    std::stringstream ss;
    ss << "digraph {\n";
    for (int i = 0; i < V; i++) {
      std::string label;
      if (showOrder)
        label = std::string(data[i]) + ":" + std::to_string(order[i]);
      else
        label = std::string(data[i]);
      ss << "  " << i << " [label=\"" << label << "\"]\n";

      for (auto j : adj[i]) {
        ss << "  " << i << " -> " << j << "\n";
      }
    }
    ss << "}";
    std::ofstream os("graph1.dot");
    os << ss.str();
    os.close();

    auto cmd = std::string("circo -Tpng graph1.dot -o ") + fname;
    std::system(cmd.c_str());
  }

  // The Driver function
  std::stack<nodeIndex> topo_Sort() {
    stack<nodeIndex> visitStack;
    // Mark all nodes as unvisited
    std::fill(states.begin(), states.end(), State::UNVISITED);

    for (nodeIndex i = 0; i < V; i++) {
      if (states[i] == State::UNVISITED) {
        __topo__Sort(i, visitStack);
      }
    }

    // Number the nodes for graphviz visualization
    auto tmpStack = visitStack;
    auto i = 1;
    while (!tmpStack.empty()) {
      auto it = tmpStack.top();
      tmpStack.pop();
      order[it] = i++;
    }

    return visitStack;
  }

private:
  nodeIndex V;
  std::list<nodeIndex> *adj;
  std::vector<std::string> data;
  std::vector<State> states;
  std::vector<int> order;

private:
  void __topo__Sort(nodeIndex v, stack<nodeIndex> &visitStack) {
    states[v] = State::VISITED;

    for (auto node : adj[v]) {
      if (states[node] == State::UNVISITED) {
        __topo__Sort(node, visitStack);
      }
    }
    visitStack.push(v);
  }
}; // End class Graph

void printStack(Graph &graph, stack<nodeIndex> &Stack) {
  auto copy = Stack;
  bool first = true;
  while (!copy.empty()) {
    if (!first)
      std::cout << " -> ";
    std::cout << graph.getNode(copy.top());
    copy.pop();
    first = false;
  }
  std::cout << "\n";
}

// Driver program to test above functions
int main() {
  // Create a graph given in the above diagram
  Graph courses(7);
  courses.setData(0, "SFO");
  courses.setData(1, "BOS");
  courses.setData(2, "ORD");
  courses.setData(3, "JFK");
  courses.setData(4, "DFW");
  courses.setData(5, "LAX");
  courses.setData(6, "MIA");

  courses.addEdge(1, 3);
  courses.addEdge(1, 0);
  courses.addEdge(1, 6);
  courses.addEdge(2, 4);
  courses.addEdge(3, 0);
  courses.addEdge(3, 4);
  courses.addEdge(3, 6);
  courses.addEdge(4, 0);
  courses.addEdge(4, 5);
  courses.addEdge(6, 4);
  courses.addEdge(6, 5);

  courses.saveAsPNG("../gflights.png", false);

  std::cout << "\n\nTopological Sort:\n";
  auto results = courses.topo_Sort();
  courses.saveAsPNG("../gflights-solution.png", true);
  printStack(courses, results);

  return 0;
}