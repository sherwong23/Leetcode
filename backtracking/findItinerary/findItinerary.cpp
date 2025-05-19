#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

class Solution {
private:
unordered_map<string, map<string, int>> targets;

bool backtracking(int ticketNum, vector<string>& result) {
    if (result.size() == ticketNum + 1) {
        return true;
    }

    //查找targets中起始地是result的最后一项,每一个target开始遍历
    for (pair<const string, int>& target : targets[result[result.size() - 1]]) {
        //还有票才开始遍历
        if (target.second > 0 ) {
            
            result.push_back(target.first);
            target.second--;
            //如果后面的遍历都返回了true则一层层返回去,最后退出
            if (backtracking(ticketNum, result)) return true;
            
            result.pop_back();
            target.second++;
        }
    }
    return false;
}

public:
vector<string> findItinerary(vector<vector<string>>& tickets) {
    targets.clear();
    vector<string> result;
    //可能有多张同样的机票 可能有同一起始地飞往不同地方的机票
    for (const vector<string>& vec : tickets) {
        targets[vec[0]][vec[1]]++;
    }
    result.push_back("JFK");
    backtracking(tickets.size(), result);
    return result;
}
};

int main() {
    vector<vector<string>> tickets = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
    Solution sol;
    vector<string> result = sol.findItinerary(tickets);
    for (auto& aiport : result) {
        cout << "[ ";
        cout << aiport << " ";
        cout << "]";
    }
    cout << endl;
    return 0;
}

