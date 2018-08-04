#include <iostream>
#include <vector>
#include <random>
#include <set>
#include <unordered_set>
#include <ctime>

using namespace std;


class RandomizedSet {
private:

    unordered_set<int> datas;


public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(time(NULL));
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (datas.find(val) != datas.end())
            return false;
        datas.insert(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        unordered_set<int>::const_iterator it = datas.find(val);
        if (it == datas.end())
            return false;

        datas.erase(it);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        unordered_set<int>::const_iterator it(datas.begin());
        int randomIndex = (rand()) % datas.size();
        advance(it, randomIndex);
        return *it;
    }
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