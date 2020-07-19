#include <string>
#include <vector>

using namespace std;

int dfs(vector<int> numbers, int index ,int target, int num) {
    if (index == numbers.size()) {
        return (num == target ? 1 : 0);
    } else {
        return dfs(numbers, index+1, target, num+numbers[index]) +
               dfs(numbers, index+1, target, num-numbers[index]);
    }
}