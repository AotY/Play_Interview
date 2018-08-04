#include <iostream>
#include <vector>
#include <random>
#include <set>
#include <unordered_set>
#include <ctime>
using namespace std;




class RandomizedSet {
private:
    int* arr;
    int *indexArr;
    int maxSize;
    int curSize;
    int hashVal(int val) {
        return (val * 37 * 12 ) % maxSize;
    }

public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        arr = new int[SHRT_MAX];
        indexArr = new int[SHRT_MAX];
        for (int i = 0; i < SHRT_MAX; ++i) {
            arr[i] = 0;
            indexArr[i] = -1;
        }
        maxSize = SHRT_MAX;
        curSize = 0;

        srand(time(NULL));

        set<int> datas;
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        int hashIndex = hashVal(val);
        if (arr[hashIndex] == 1) {
            return false;
        } else {
            arr[hashIndex] = 1;
            indexArr[curSize++] = hashIndex;
            return true;
        }
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        int hashIndex = hashVal(val);
        if (arr[hashIndex] == 0) {
            return false;
        } else {
            arr[hashIndex] = 0;
            curSize -- ;
            return true;
        }
    }

    /** Get a random element from the set. */
    int getRandom() {
        int randomIndex = rand() % curSize;
        return arr[randomIndex];

    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */



int main() {
    // generate a set...
    set<int> s;
    for( int i = 0; i != 10; ++i )
        s.insert(i);

    set<int>::const_iterator it(s.begin());

    // 'advance' the iterator 5 times
    advance(it,5);

    cout<<*it<<endl;
}