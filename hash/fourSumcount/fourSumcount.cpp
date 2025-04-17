#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public: 
        //input four vectors
        int fourSumCount(vector<int>&A, vector<int>&B, vector<int>&C, vector<int>&D) {
            //key is a + b, value is the time of a+b
            unordered_map<int, int> umap;
            for (int a : A) {
                for(int b : B){
                    umap[a+b]++;
                }
            }
            int count = 0;
            for (int c : C) {
                for (int d : D) {
                    if (umap.find(0 - c - d) != umap.end()) {
                        count += umap[0 - c - d];
                    }
                }
            }
            return count;
        }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> A = {1, 2};
    vector<int> B = {-1, -2};
    vector<int> C = {-1, 2};
    vector<int> D = {0, 2};
    
    int result = solution.fourSumCount(A, B, C, D);
    cout << "Test Case 1 Result: " << result << endl; // Expected output: 2

    // Test case 2
    vector<int> A2 = {0, 0};
    vector<int> B2 = {0, 0};
    vector<int> C2 = {0, 0};
    vector<int> D2 = {0, 0};
    
    result = solution.fourSumCount(A2, B2, C2, D2);
    cout << "Test Case 2 Result: " << result << endl; // Expected output: 16

    // Test case 3 (empty arrays)
    vector<int> A3 = {};
    vector<int> B3 = {};
    vector<int> C3 = {};
    vector<int> D3 = {};
    
    result = solution.fourSumCount(A3, B3, C3, D3);
    cout << "Test Case 3 Result: " << result << endl; // Expected output: 0

    return 0;
}
