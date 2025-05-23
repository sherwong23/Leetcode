#include <iostream>
#include <vector>
using namespace std;

class Solution {
    static bool cmp(int a, int b) {
        return abs(a) > abs(b);
    }

    public:
    int largestSum (vector<int>& A, int K) {
        sort(A.begin(), A.end(), cmp);
        for (int i = 0; i < A.size(); i++) {
            if (A[i] < 0 && K > 0) {
                A[i] *= -1;
                K--;
            }
        }
        //不需要考虑k=0的情况
        if (K % 2 == 1) A[A.size() - 1] *= -1;
        int result = 0;
        for (int a : A) result += a;
        return result;
    }
};

int main () {
    vector<int> A = {2,-3,-1,5,-4};
    Solution sol;
    int sum = sol.largestSum(A, 2);
    cout << sum << endl;
    return 0;
}


