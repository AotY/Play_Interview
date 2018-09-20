#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <sstream>

using namespace std;


struct Log {
    string time;
    int hostId;
    string logText;
};

vector<int> searchByHostId(vector<Log> &logs, int hostId){
    vector<int> res ;
    for (int i = 0; i < logs.size(); ++i) {
        if (logs[i].hostId == hostId) {
            res.push_back(i);
        }
    }
    return res;
}

int searchByWord(vector<Log> &logs, string &word){
    for (int i = 0; i < logs.size(); ++i) {
        if (logs[i].logText.find(word) != string::npos)
            return i;
    }
    return -1;
}

int main() {
    int N;
    cin >> N;
    vector<Log> logs = vector<Log>(N);

    for (int i = 0; i < N; ++i) {
        Log log;
//        string line ;
//        getline(cin, line);
//
//        istringstream buf(line);
//        istream_iterator<string> beg(buf), end;
//        vector<std::string> tokens(beg, end);
//
//        log.time = tokens[0];
//        stringstream geek(tokens[1]);
//        geek >> log.hostId;
//        log.logText = tokens[2];

        cin >> log.time;
        cin >> log.hostId;
        cin >> log.logText;

        logs[i] = log;
    }
    
    int T;
    cin >> T;

    for (int i = 0; i < T; ++i) {

        int k;
        cin >> k;

        string queryWord;
        int queryHostId = -1;
        int queryBeforeNum = -1;
        int queryAfterNum = -1;

        for (int j = 0; j < k; ++j) {
            string command;
            cin >> command;

            if (command == "--search") {
                cin >> queryWord;
            } else if (command == "--hostid") {
                cin >> queryHostId;
            } else if (command == "--before") {
                cin >> queryBeforeNum;
            } else {
                cin >> queryAfterNum;
            }
        }


        vector<int> idResults;
        bool isId = false;
        if (queryHostId != -1) {
            idResults = searchByHostId(logs, queryHostId);
            isId = true;
            if (idResults.size() == 0) {
                cout << "ERROR" << endl;
                continue;
            }
        }

        int resIndex = -1;
        // by queryWord
        if (isId) { //
            for (int j = 0; j < idResults.size(); ++j) {
                if (logs[idResults[j]].logText.find(queryWord) != string::npos) {
                    resIndex = idResults[j];
                    break;
                }
            }

            if (resIndex == -1) {
                cout << "ERROR" << endl;
                continue;
            }

        } else {
            resIndex = searchByWord(logs, queryWord);
            if (resIndex == -1) {
                cout << "ERROR" << endl;
                continue;
            }
        }


        // resIndex log
        cout << logs[resIndex].logText << endl;

        // 输出 before num
        if (queryBeforeNum != -1) {
            int startIndex = resIndex - queryBeforeNum;
            if (startIndex < 0)
                startIndex = 0;
            for (int j = startIndex; j < resIndex; ++j) {
                cout << logs[j].logText << endl;
            }
        }

        // 输出 after num
        if (queryAfterNum != -1) {
            int endIndex = resIndex + queryAfterNum;
            if (endIndex > logs.size())
                endIndex = logs.size();

            for (int j = resIndex; j < endIndex; ++j) {
                cout << logs[j].logText << endl;
            }
        }

    }

    return 0;
}