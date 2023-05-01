#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int prev1 = 2, prev2 = 1;
        int curr = 0;
        for (int i = 3; i <= n; i++) {
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
};

int main() {
    Solution s;
    cout << s.climbStairs(10) << endl;
    return 0;
}
