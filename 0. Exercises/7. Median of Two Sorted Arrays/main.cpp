#include <iostream>
#include <vector>
#include <minmax.h>
#include <algorithm>

using namespace std;

// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int m = nums1.size(), n = nums2.size();
//         if (m > n) {
//             return findMedianSortedArrays(nums2, nums1); // make nums1 the smaller array
//         }
//         int iMin = 0, iMax = m, halfLen = (m + n + 1) / 2;
//         while (iMin <= iMax) {
//             int i = (iMin + iMax) / 2;
//             int j = halfLen - i;
//             if (i < iMax && nums2[j-1] > nums1[i]) {
//                 iMin = i + 1; // i is too small, increase i
//             } else if (i > iMin && nums1[i-1] > nums2[j]) {
//                 iMax = i - 1; // i is too big, decrease i
//             } else { // i is perfect
//                 int maxLeft = 0;
//                 if (i == 0) {
//                     maxLeft = nums2[j-1];
//                 } else if (j == 0) {
//                     maxLeft = nums1[i-1];
//                 } else {
//                     maxLeft = max(nums1[i-1], nums2[j-1]);
//                 }
//                 if ((m + n) % 2 == 1) {
//                     return maxLeft;
//                 }
//                 int minRight = 0;
//                 if (i == m) {
//                     minRight = nums2[j];
//                 } else if (j == n) {
//                     minRight = nums1[i];
//                 } else {
//                     minRight = min(nums1[i], nums2[j]);
//                 }
//                 return (maxLeft + minRight) / 2.0;
//             }
//         }
//         return 0.0;
//     }
// };


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        nums1.insert(nums1.end(), nums2.begin(), nums2.end());

        sort(nums1.begin(), nums1.end());

        if (nums1.size() % 2 == 0) return (double) (nums1[nums1.size()/2 - 1] + nums1[nums1.size()/2])/2;

        if (nums1.size() % 2 != 0) return (nums1[nums1.size()/2]);

        return 0;

    }
};


// 3 4
// 5 6 7 8 9

// 4

// 


int main(){

    Solution S;

    vector<int> v1 = {3,4};
    vector<int> v2 = {5,6,7,8,9,10,11};

    cout << S.findMedianSortedArrays(v1, v2);

    return 0;
}