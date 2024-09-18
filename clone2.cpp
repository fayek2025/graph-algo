#include<bits/stdc++.h>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    unordered_map<Node* , Node*> visited;
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        if(visited.find(node) != visited.end()) return visited[node];
        Node* clone = new Node(node->val);
        visited[node] = clone;
        for(auto& neighbours: node->neighbors) {
            clone->neighbors.push_back(cloneGraph(neighbours));
        }
        return clone;
    }
};

// Function to print the graph
void printGraph(Node* node, unordered_set<int>& visited) {
    if (!node || visited.count(node->val)) return;
    
    visited.insert(node->val);
    cout << "Node: " << node->val << " -> Neighbors: ";
    
    for (auto& neighbor : node->neighbors) {
        cout << neighbor->val << " ";
    }
    
    cout << endl;
    
    for (auto& neighbor : node->neighbors) {
        printGraph(neighbor, visited);
    }
}

int main() {
    // Creating a test graph manually
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    
    node1->neighbors.push_back(node2);
    node1->neighbors.push_back(node4);
    
    node2->neighbors.push_back(node1);
    node2->neighbors.push_back(node3);
    
    node3->neighbors.push_back(node2);
    node3->neighbors.push_back(node4);
    
    node4->neighbors.push_back(node1);
    node4->neighbors.push_back(node3);
    
    Solution solution;
    Node* clonedGraph = solution.cloneGraph(node1);

    // Print original graph
    unordered_set<int> visited;
    cout << "Original Graph:" << endl;
    printGraph(node1, visited);

    // Print cloned graph
    visited.clear();
    cout << "\nCloned Graph:" << endl;
    printGraph(clonedGraph, visited);
    
    return 0;
}
