#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int canCompleteCircuit (vector<int>& gas, vector<int>& cost) {
            int curSum = 0;
            int min = INT_MAX;
            for (int i = 0; i < gas.size(); i++) {
                int rest = gas[i] - cost[i];
                curSum += rest;
                if (curSum < min) {
                    min = curSum;
                }
            }

            //可以理解成拆成了三个局部,以min为界,0到min为负值,min到resutl为总剩余油,result到结尾为大正,带上大正就能cover掉负值
            if (curSum < 0) return -1;
            if (min >= 0) return 0;
            for (int i = gas.size() - 1; i >= 0; i--) {
                int rest = gas[i] - cost[i];
                min += rest;
                if (min >= 0) return i;
            }
        return -1;
        }
};

int main() {
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    Solution sol;
    int result = sol.canCompleteCircuit(gas, cost);
    cout << result << endl;
    return 0;
}
