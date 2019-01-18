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
      if (showOrder)
        ss << "  " << i << " [label=\"" << data[i] << "\", xlabel=\""
           << order[i] << "\"]\n";
      else
        ss << "  " << i << " [label=\"" << data[i] << "\"]\n";
      for (auto j : adj[i]) {
        ss << "  " << i << " -> " << j << "\n";
      }
    }
    ss << "}";
    std::ofstream os("graph1.dot");
    os << ss.str();
    os.close();

    auto cmd = std::string("dot -Tpng graph1.dot -o ") + fname;
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
  Graph courses(9);
  courses.setData(0, "LA15");
  courses.setData(1, "LA31");
  courses.setData(2, "LA16");
  courses.setData(3, "LA32");
  courses.setData(4, "LA127");
  courses.setData(5, "LA141");
  courses.setData(6, "LA22");
  courses.setData(7, "LA169");
  courses.setData(8, "LA126");

  courses.addEdge(0, 1);
  courses.addEdge(0, 2);
  courses.addEdge(1, 3);
  courses.addEdge(2, 3);
  courses.addEdge(2, 4);
  courses.addEdge(2, 5);
  courses.addEdge(6, 5);
  courses.addEdge(6, 8);
  courses.addEdge(6, 7);
  courses.addEdge(3, 7);

  courses.saveAsPNG("../gcourses.png", false);

  std::cout << "\n\nTopological Sort:\n";
  auto results = courses.topo_Sort();
  courses.saveAsPNG("../gcourses-solution.png", true);
  printStack(courses, results);

  return 0;
}