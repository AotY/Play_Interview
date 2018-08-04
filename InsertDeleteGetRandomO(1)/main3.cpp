#include <iostream>
#include <vector>
#include <random>
#include <set>
#include <unordered_set>
#include <ctime>

using namespace std;


class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(time(0));
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (m.find(val) != m.end())
            return false;
        v.push_back(val);
        m[val] = v.size() - 1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (m.find(val) == m.end())
            return false;
        int targetIndex = m[val];
        int lastVal = v.back();
        v[targetIndex] = lastVal;
        m[lastVal] = targetIndex;
        v.pop_back();
        m.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return v[rand() % v.size()];
    }

private:
    //<key,index>
    unordered_map<int, int> m;
    vector<int> v;
};


int main() {


    RandomizedSet *obj = new RandomizedSet();
    bool param_1 = obj->insert(1);
    bool param_2 = obj->remove(2);
    bool param_3 = obj->insert(2);
    bool param_4 = obj->remove(2);
    int param_5 = obj->getRandom();
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}