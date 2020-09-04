#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n,int m)
{
	int answer = 0;
    bool flag = false;
    for (int i = 1; ; ++i) {
        flag = (i % m == 0) ? true : false;
        if (flag == false) {
            --n;
        }
        if (flag == true && n == 0) n = 1;
        if (flag == false && n == 0) {
            answer = i;
            break;
        }
    }
	return answer;
}