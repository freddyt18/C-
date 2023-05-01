#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int result = 0;

        map<char, int> conversion_rate = {
            {'M', 1000},
            {'D', 500},
            {'C', 100},
            {'L', 50},
            {'X', 10},
            {'V', 5},
            {'I', 1}
        };
  
        for (int i = 0; i < s.length(); i++) {
            int current = conversion_rate[s[i]];
            int next = (i+1 < s.length()) ? conversion_rate[s[i+1]] : 0;

            if (current < next) {
                result -= current;
            } else {
                result += current;
            }
        }

        return result;
    }
};



int main(){

    Solution s;

    cout << s.romanToInt("III");

    return 0;
}