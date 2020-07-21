#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    stack<int> stock;
    for (int i = 0 ; i < prices.size(); ++i) {
      while(!stock.empty() && prices[stock.top()] > prices[i]) {
        answer[stock.top()] = i - stock.top();
        stock.pop();
      }
      stock.push(i);
    }
    while (!stock.empty()) {
      answer[stock.top()] = prices.size() - stock.top() - 1;
      stock.pop();
    }
    return answer;
}