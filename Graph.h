#ifndef AGENTPROJECT_GRAPH_H
#define AGENTPROJECT_GRAPH_H

#include <utility>
#include <vector>
#include <queue>
#include "Map.h"

class Graph {
private:
    class Node{
    public:
        Node(std::pair<int, int> data, int targs = -1, std::vector<Node*> child_list = {})
                : location(std::move(data)){};

        int cost = 1;
        int actionData = 0;
        int cpt = 0;
        std::vector<std::pair<int, int>> targets;
        Node* parent = nullptr;

        int g = 0;
        int h = 0;
        int f = 0;

        std::pair<int, int> location;
        std::vector<Node*> children;

        Node& operator=(const Node& old_node){

            location = old_node.location;
            children = old_node.children;
            parent = old_node.parent;
            actionData = old_node.actionData;
            cost = old_node.cost;

            g = old_node.g;
            h = old_node.h;
            f = old_node.f;

            return *this;
        }

        bool operator<(const Node& nd) const{
            return cost < nd.cost;
        };
    };

    int learning_rate;
    Map * map;

public:
    typedef Node * node;
    //node root;

    Graph(int, std::pair<int, int>, Map*); // Constructor
    ~Graph();

    std::vector<node> Astar(std::pair<int, int>, std::vector<std::pair<int, int>>);
    std::vector<node> BFS (std::pair<int, int>);

    int getDistance(std::pair<int, int>, std::pair<int, int>);

    void expandNode(node, std::vector<node>&);

    bool isNodeUnvisited(std::pair<int, int>, std::vector<node>&, node);

    void buildNode(std::pair<int, int>, node);

    std::vector<std::vector<int>> generateScores(int&);

    int getClosestDust(std::pair<int, int>, std::vector<std::pair<int, int>>);

    bool betterNode(node, std::vector<node> &);
    int cellScore(std::pair<int, int> loc);
};


#endif //AGENTPROJECT_GRAPH_H
