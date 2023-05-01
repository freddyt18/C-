#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    /**
     * The function takes in a vector of integers and a target integer, and returns a vector of two
     * integers representing the indices of two elements in the input vector that add up to the target
     * integer.
     * 
     * @param nums A vector of integers representing the input array.
     * @param target The target integer that we are trying to find a pair of numbers that add up to it.
     * 
     * @return The function `twoSum` returns a vector of two integers representing the indices of the
     * two numbers in the input vector `nums` that add up to the target integer. If no such pair is
     * found, the function returns {-1,-1}.
     */
    vector<int> twoSum(vector<int>& nums, int target) {

        int size = nums.size();
        int starter = 0;
        int mover = 0;

        for(mover; mover < size; mover++){
            if( starter == mover ) continue;;

            if( nums[starter] + nums[mover] == target ) return {starter, mover};

            if( mover == size - 1 ){
                if( starter == size - 1 ) break;

                mover = 0;
                starter++;
            };

        };

        return {-1,-1};
    };
};

int main(){
    Solution s;
    
    vector<int> v = {2,5,5,11};

    for (int result : s.twoSum(v, 10)){
        cout << result << " ";
    }

    return 0;
};