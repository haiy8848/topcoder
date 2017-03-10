#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Permatchd2 {
public:
  int fix(vector<string>& graph);

private:
  vector<int> visited_;
  int connected(vector<string>& graph, int node);
};

int Permatchd2::connected(vector<string>& graph, int node)
{
  int sum = 0;
  bool found = true;
  visited_[node] = 1;
  string neighbors = graph[node];

  while (found) {
    for (int i = 0; i < neighbors.size(); i++) {
      if (neighbors[i] == 'Y') {
        sum++;
        if (visited_[i] == 0)
          visited_[i] = -1;
      }
    }
    // move to next neighbor node
    found = false;
    for (int i = 0; i < visited_.size(); i++) {
      if (visited_[i] == -1) {
        found = true;
        visited_[i] = 1;
        neighbors = graph[i];
        break;
      }
    }
  }
  return sum >> 1;
}

int
Permatchd2::fix(vector<string>& graph)
{
  // init visited flags
  visited_.clear();
  for (int i = 0; i < graph.size(); i++) {
    visited_.push_back(0);
  }

  int total = 0;
  int even = 0;
  int odd = 0;
  for (int i = 0; i < visited_.size(); i++) {
    if (visited_[i] == 0) {
      visited_[i] = 1;
      // calculate # of edges of connected component
      int edges = connected(graph, i);
      total += edges;
      if (edges & 1)
        odd++;
      else
        even++;
    }
  }

  if (even > 0)
    return odd;
  int all = graph.size() * (graph.size() - 1) / 2;
  if ((total + odd) <= all)
    return odd;
  return -1;
}

int main()
{
  vector<string> graph;
  graph.push_back("NYNNNN");
  graph.push_back("YNNNNN");
  graph.push_back("NNNYNN");
  graph.push_back("NNYNNN");
  graph.push_back("NNNNNY");
  graph.push_back("NNNNYN");

  Permatchd2 solver;
  cout << "Fix: " << solver.fix(graph) << endl;

  return 0;
}
