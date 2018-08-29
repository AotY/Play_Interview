#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <cassert>

using namespace std;

// 使用优先队列

class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        vector<int> results;

        int n = nums.size();

        assert(k > 0);

        unordered_map<int, int> freqMap;
        for (int i = 0; i < nums.size(); i++)
            freqMap[nums[i]]++;

        assert(k <= freqMap.size());

        // 维护k的元素，<频率， 元素>
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> freqQueue;

        for (unordered_map<int, int>::iterator it = freqMap.begin();
             it != freqMap.end(); it++) {

            // 如果当前元素的频率大于队首元素的频率，将优先队列中的队首元素出队
            if (freqQueue.size() == k) {
                if (it->second > freqQueue.top().first) {
                    freqQueue.pop();
                    freqQueue.push(make_pair(it->second, it->first));
                }
            } else {
                freqQueue.push(make_pair(it->second, it->first));
            }
        }

        while (!freqQueue.empty()) {
            results.push_back(freqQueue.top().second);
            freqQueue.pop();
        }

        return results;
    }
};

int main() {

    Solution s;
    vector<int> nums = {1, 1, 1, 2, 2, 1, 3, 3, 3, 3, 3};

    int k = 2;
    vector<int> results = s.topKFrequent(nums, k);
    for (int i = 0; i < k; ++i) {
        cout << results[i] << " ";
    }
    cout << endl;
    return 0;
}