#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        int starter = 0;
        vector<vector<int>> result;

        for (vector undirectional : connections){
            bool found = find(undirectional.begin(), undirectional.end(), starter) != undirectional.end();

            if(found){
                for(int each : undirectional){
                    if(each == starter) continue;

                    if(each == starter + 1){
                        starter = each;
                    }

                }
            }
        }


        if(starter < n-1){
            for (vector undirectional : connections){
                bool found = find(undirectional.begin(), undirectional.end(), starter-1) != undirectional.end();

                if(found){
                    for(int each : undirectional){
                        if (each == starter) continue;

                        if (each == starter+1){
                            result.push_back(undirectional);
                        }
                    }
                }
            }
        }

        if(connections.size() == 1){
            return connections;
        }

        return result;
    }
};


int main(){

    Solution s;

    vector<vector<int>> con = {
        {0,1},
        {1,2},
        {2,0},
        {1,3},
        {3,4},
        {4,5},
        {5,3}
    };

    // vector<vector<int>> con = {
    //     {0,1}
    // };

    for(vector x : s.criticalConnections(6, con)){
        for(int y : x){
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}