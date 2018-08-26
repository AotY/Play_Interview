#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <multiset>

using namespace std;

struct Data {
    int f, i, x;

    Data() {}

    Data(int f_, int i_, int x_) : f(f_), i(i_), x(x_) {}

    bool operator < (const Data &that) const {
        if (f != that.f)
            return f > that.f;
        if (i != that.i)
            return i > that.i;
    }
};

class FreqStack {
    multiset <Data> stk;

    map<int, int> cnt;

    int top = 0;

public:
    FreqStack() {

    }

    void push(int x) {
        int c = ++cnt[x];

        stk.insert(Data(c, top++, x));
    }

    int pop() {
        if (stk.empty())
            return -1;

        auto it = stk.begin();

        int x = it->x;

        stk.erase(it);

        --cnt[x];

        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 */


int main() {

    FreqStack obj;

    obj.push(5);
    obj.push(3);

    cout << obj.pop() << endl;
    cout << obj.pop() << endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}