#ifndef CODE_DGRAPH_H
#define CODE_DGRAPH_H

#include <string>
#include <vector>
#include <list>

class DGraph {
public:
    enum States{};

    explicit DGraph(int V);
    void addEdge(int v, int w);
    void nameNode(int v, std::string name);
    std::string toGraphViz();

    void DFS();
    void DFS_impl(int v, bool *visited);

private:
    // Number of vertices
    int V;
    // Pointer to an array of adjacency lists
    std::list<int> *adj;
    // Node data
    std::vector<std::string> names;
};


#endif //CODE_DGRAPH_H
