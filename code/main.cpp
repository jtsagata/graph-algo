#include "DGraph.h"
#include <fstream>
#include <iostream>

int main() {
  DGraph g(4);
  g.nameNode(0, std::string("Start"));
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);

  std::ofstream os("graph1.dot");
  os << g.toGraphViz();
  os.close();
  std::system("dot -Tpng graph1.dot -o ../grpah1.png");

  g.DFS();

  return 0;
}