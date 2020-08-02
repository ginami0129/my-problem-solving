#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, sum = 0, i = 0;
    queue<int> bridge;
    vector<int> time(truck_weights.size(), 0);
    bridge.push(i);
    time[i] = 1;
    sum += truck_weights[i];
    for (answer = 2; !bridge.empty(); ++answer) {
      if (answer - time[bridge.front()] == bridge_length) {
        sum -= truck_weights[bridge.front()];
        bridge.pop();
      }
      if (i+1 < truck_weights.size() &&
          sum + truck_weights[i+1] <= weight ) {
        bridge.push(i+1);
        time[i+1] = answer;
        sum += truck_weights[i+1];
        ++i;
      }
    }
    return --answer;
}