#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int N, vector<vector<int>> directory, vector<vector<int>> query)
{
  vector<int> answer;
  vector<int> parent(N + 1, 0);
  vector<int> folder(N + 1, 0);
  int query_1,query_2;
  int length = 0;

  for (auto d : directory) {
    parent[d[1]] = d[0];
  }

  for (auto q : query) {
    query_1 = q[0];
    query_2 = q[1];

    for (int i = 1; query_1 != 0; ++i) {
      folder[query_1] = i;
      query_1 = parent[query_1];
    }

    while (query_2 != 0) {
      ++length;
      if (folder[query_2] > 0) {
        length+= folder[query_2];
        break;
      }

      query_2 = parent[query_2];
    }

    answer.push_back(length-1);
    folder = vector<int>(N+1, 0);
    length = 0;
  }
  return answer;
}

int main(void)
{
  // vector<int> answer = solution(4, {{3, 2}, {3, 1}, {3, 4}}, { {4, 2}, {3, 1}, {2, 2}});
  vector<int> answer = solution(5, {{1, 2}, {2, 5}, {1, 3}, {2, 4}}, {{1, 5}, {2, 5}, {3, 5}, {4, 5}});
  for (auto i : answer)
  {
    cout << i << endl;
  }
}


// vector<int> solution(int N, vector<vector<int>> directory, vector<vector<int>> query)
// {
//   vector<int> answer;
//   vector<int> depth(N + 1, 0);
//   vector<int> parent(N + 1, 0);
//   int query_1,query_2;
//   int length = 2;

//   for (auto d : directory) {
//     depth[d[1]] = depth[d[0]] + 1;
//     parent[d[1]] = d[0];
//   }
//   for (auto q : query) {
//     query_1 = q[0];
//     query_2 = q[1];
//     while (query_1 != query_2) {
//       if (depth[query_1] > depth[query_2]) {
//         query_1 = parent[query_1];
//       } else if (depth[query_1] < depth[query_2]) {
//         query_2 = parent[query_2];
//       } else {
//         query_2 = parent[query_2];
//         query_1 = parent[query_1];
//         ++length;
//       }
//       ++length;
//     }
//     answer.push_back(length - 1);
//     length = 2;
//   }
//   return answer;
// }

// vector<int> solution(int N, vector<vector<int>> directory, vector<vector<int>> query)
// {
//   vector<int> answer;
//   vector<int> parent(N + 1, 0);
//   vector<int> route;
//   int query_1,query_2;
//   int length = 0;

//   for (auto d : directory) {
//     parent[d[1]] = d[0];
//   }

//   for (auto q : query) {
//     query_1 = q[0];
//     query_2 = q[1];
//     while (query_1 != 0) {
//       route.push_back(query_1);
//       query_1 = parent[query_1];
//     }

//     while (query_2 != 0) {
//       ++length;
//       for (int i = 0; i < route.size(); ++i) {
//         if (query_2 == route[i]) {
//           length += i;
//           query_2 = 0;
//           break;
//         }
//       }
//       query_2 = parent[query_2];
//     }

//     answer.push_back(length);
//     route.clear();
//     length = 0;
//   }
//   return answer;
// }