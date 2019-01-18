#include "DGraph.h"
#include <cassert>
#include <sstream>

#include <iostream>

DGraph::DGraph(int V) {
  this->V = V;
  adj = new std::list<int>[V];
  names.reserve(static_cast<unsigned long>(V));
  for (int i = 0; i < V; i++) {
    nameNode(i, std::to_string(i));
  }
}

void DGraph::addEdge(int v, int w) {
  adj[v].push_back(w);
}

void DGraph::nameNode(int v, std::string name) {
  assert(v <= V);
  names[v] = std::move(name);
}

std::string DGraph::toGraphViz() {
  std::stringstream ss;
  ss << "digraph {\n";
  for (int i = 0; i < V; i++) {
    ss << "  " << i << " [label=\"" << names[i] << "\"]\n";
    for (auto j : adj[i]) {
      ss << "  " << i << " -> " << j << "\n";
    }
  }
  ss << "}";
  return std::move(ss.str());
}

void DGraph::DFS() {
  bool *visited = new bool[V];
  for (int i = 0; i < V; i++)
    visited[i] = false;

  for (int i = 0; i < V; i++)
    if (visited[i] == false)
      DFS_impl(i, visited);
}

void DGraph::DFS_impl(int v, bool *visited) {
  // Mark the current node as visited and print it
  visited[v] = true;
  std::cout << v << " ";

  // Recur for all the vertices adjacent to this vertex
  std::list<int>::iterator i;
  for (i = adj[v].begin(); i != adj[v].end(); ++i)
    if (!visited[*i])
      DFS_impl(*i, visited);
}
