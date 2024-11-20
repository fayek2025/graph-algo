#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cassert>

using namespace std;

const long long MAX_NODES = 3e5;
const long long MAX_EDGES = 5e5;
const double EPSILON = 1e-9;

long long inDegree[MAX_NODES], outDegree[MAX_NODES];
vector<long long> graph[MAX_NODES];
double probabilities[MAX_EDGES];

int main() {
    long long nodes, edges, startNode;
    cin >> nodes >> edges >> startNode;

    assert(nodes <= MAX_NODES && edges <= MAX_EDGES && startNode <= nodes);
    startNode--;

    for (long long i = 0; i < edges; i++) {
        long long u, v;
        cin >> u >> v;
        u--, v--;

        graph[u].push_back(v);
        inDegree[v]++;
        outDegree[u]++;
    }

    probabilities[startNode] = 1.0;

    queue<long long> processingQueue;
    for (long long i = 0; i < nodes; i++) {
        if (inDegree[i] == 0) {
            processingQueue.push(i);
        }
    }

    while (!processingQueue.empty()) {
        long long currentNode = processingQueue.front();
        processingQueue.pop();

        for (auto neighbor : graph[currentNode]) {
            probabilities[neighbor] += probabilities[currentNode] / outDegree[currentNode];
            inDegree[neighbor]--;

            if (inDegree[neighbor] == 0) {
                processingQueue.push(neighbor);
            }
        }
    }

    double maxProbability = 0.0;
    vector<long long> resultNodes;

    for (long long i = 0; i < nodes; i++) {
        if (outDegree[i] == 0 && probabilities[i] > maxProbability) {
            maxProbability = probabilities[i];
        }
    }

    for (long long i = 0; i < nodes; i++) {
        if (outDegree[i] == 0 && fabs(probabilities[i] - maxProbability) <= EPSILON) {
            resultNodes.push_back(i + 1);
        }
    }

    for (long long node : resultNodes) {
        cout << node << " ";
    }
    cout << "\n";

    return 0;
}
