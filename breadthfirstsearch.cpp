// Eric Miguel
// CSC-321
#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <limits>
using namespace std;

// Vertex Colors
enum vertex_color { WHITE, GRAY, BLACK };
// Adjacency List representation
typedef std::map<char, std::vector<char>> adj_list;
// Colors map
std::map<char, vertex_color> color;
// Parents map
std::map<char, char> parent;
// Distance map
std::map<char, int> distances;
// Infinity Constant
const int INF = std::numeric_limits<int>::infinity();

// Breadth-First Search
void bfs(adj_list& graph, char root) {
    // Set up BFS parameters
    for (const auto& [node, _] : graph) {
        color[node] = WHITE;
        parent[node] = '\0'; // Null character
        distances[node] = INF;
    }
    color[root] = GRAY;
    distances[root] = 0;

    // Declare a new queue
    deque<char> q;
    q.push_back(root);
    cout << "BFS from: " << root << endl;

    while (!q.empty()) {
        const auto node = q.front(); // Remove from FIFO Queue
        q.pop_front();
        cout << node << " ";
        for (const auto& adj : graph[node]) {
            if (color[adj] == WHITE) {
                color[adj] = GRAY;
                distances[adj] = distances[node] + 1;
                parent[adj] = node;
                q.push_back(adj);
            }
        }
        color[node] = BLACK;
    }
    cout << endl << endl;
}

int main() {
    // Creating the graph
    adj_list graph = {
        {'s', {'a', 'b'}},
        {'a', {'s', 'd'}},
        {'b', {'s', 'c'}},
        {'c', {'b', 'e'}},
        {'d', {'a', 'e'}},
        {'e', {'c', 'd'}}
    };
    // Calling the BFS algorithm
    bfs(graph, 's');
    cout << "Results" << endl;
    cout << "Parents: " << endl;
    for (const auto& [node, _] : graph) {
        cout << node << ": " << parent[node] << endl;
    }
    cout << endl;
    cout << "Distances: " << endl;
    for (const auto& [node, _] : graph) {
        cout << node << ": " << distances[node] << endl;
    }
}