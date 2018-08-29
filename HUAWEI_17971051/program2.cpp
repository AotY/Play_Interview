#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>

using namespace std;

// 开发一个简单错误记录功能小模块，能够记录出错的代码所在的文件名称和行号。

/*
 *
 *  处理:
    1.记录最多8条错误记录，对相同的错误记录(即文件名称和行号完全匹配) 只记录一条，错误计数增加；
    (文件所在的目录不同，文件名和行号相同也要合并)
    2.超过16个字符的文件名称，只记录文件的最后有效16个字符；
    (如果文件名不同，而只是文件名的后16个字符和行号相同，也不要合并)
    3.输入的文件可能带路径，记录文件名称不能带路径

    输入描述:
    一行或多行字符串。每行包括带路径文件名称，行号，以空格隔开。
    文件路径为windows格式
    如：E:\V1R2\product\fpgadrive.c 1325

    输出描述:
    将所有的记录统计并将结果输出，格式：
    文件名代码行数数目，一个空格隔开，如: fpgadrive.c 1325 1
    结果根据数目从多到少排序，数目相同的情况下，按照输入第一次出现顺序排序。
    如果超过8条记录，则只输出前8条记录.
    如果文件名的长度超过16个字符，则只输出后16个字符

 */

struct FileInfo {
    string name; // 文件名
    int lineNo;  // 行号
    int count; // 次数
    int mergeIndex; // 第一次出现次数

    FileInfo(string _name, int _lineNo, int _count, int _mergeIndex) : name(_name), lineNo(_lineNo), count(_count),
                                                                       mergeIndex(_mergeIndex) {};
    FileInfo() {};

};

// 结果根据数目从多到少排序，数目相同的情况下，按照输入第一次出现顺序排序。
bool fileCompare(const FileInfo &f1, const FileInfo &f2) {
    if (f1.count == f2.count) {
        return f1.mergeIndex < f2.mergeIndex;
    }

    return f1.count > f2.count;
}


int main() {

    vector<FileInfo> files;

    int lineNo;
    string line;

    string fileName;
    string filePath;
    // <fileName, lineNo> index
    map<pair<string, int>, int> indexMap;

    while (getline(cin, line)) {

//        cin >> lineNo;
        if (line == "")
            break;

        if (files.size() == 8) {
            break;
        }

        // path, lineNo
        istringstream iss(line);

        string token;
        int count = 0;
        while (getline(iss, token, ' ')) {
            if (count == 0) {
                filePath = token;
            } else if (count == 1) {
                stringstream geek(token);
                geek >> lineNo;
            }
            count ++;
        }

        istringstream iss2(filePath);
        while (getline(iss2, token, '\\')) {
            fileName = token;
        }


        pair<string, int> fl = make_pair(fileName, lineNo);

        if (indexMap.find(fl) == indexMap.end()) { // 没有出现
            indexMap.insert(make_pair(fl, files.size()));
            FileInfo fileInfo;
            fileInfo.name = fileName;
            fileInfo.count = 1;
            fileInfo.lineNo = lineNo;
            fileInfo.mergeIndex = files.size();
            files.push_back(fileInfo);
        } else {
            files[indexMap[fl]].count++;
        }
    }

    // 排序

    sort(files.begin(), files.end(), fileCompare);


    // 如果文件名的长度超过16个字符

    for (int i = 0; i < files.size(); ++i) {
        FileInfo fileInfo = files[i];
        int nameSize = fileInfo.name.size();
        if (nameSize > 16) {
            cout << fileInfo.name.substr(nameSize - 16, 16) << " ";
        } else {
            cout << fileInfo.name << " ";
        }

        cout << fileInfo.lineNo << " ";
        cout << fileInfo.count << endl;

    }

    return 0;
}



/*
输入例子1:

E:\V1R2\product\fpgadrive.c 1325
E:\V1R2\product\fpgadrive.c 1325
E:\V1R2\product\fpgadrive.c 1325
E:\V1R2\product\fpgadrive.c 1325

输出例子1:

fpgadrive.c 1325 1
*/