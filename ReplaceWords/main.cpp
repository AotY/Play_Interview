#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


// 字典树节点
struct TrieNode {
    TrieNode *children[26];
    bool isEnd;

    TrieNode() {
        for (int i = 0; i < 26; ++i) {
            children[i] = NULL;
        }

        isEnd = false;
    }
};

class Solution {
private:
    void insertToTrie(TrieNode *root, string &word) {
        TrieNode *tmpRoot = root;
        for (int i = 0; i < word.size(); ++i) {
            int index = word[i] - 'a';
            if (tmpRoot->children[index] == NULL)
                tmpRoot->children[index] = new TrieNode();
            tmpRoot = tmpRoot->children[index];
        }
        tmpRoot->isEnd = true;
    }


    string searchConceptWord(TrieNode *root, string &word) {

        string searchWord = "";

        string minWord = word;
        TrieNode *tmpRoot = root;
        bool isConcept = false;
        for (int i = 0; i < word.size(); ++i) {
            int index = word[i] - 'a';

            if (tmpRoot->children[index] != NULL) { //
                searchWord.push_back(word[i]);

                if (tmpRoot->children[index]->isEnd) {
                    isConcept = true;
                    if (searchWord.size() < minWord.size())
                        minWord = searchWord;
                }

                tmpRoot = tmpRoot->children[index];
            } else {
                break;
            }
        }
        if (tmpRoot->isEnd || isConcept)
            return minWord;
        else
            return word;
    }

public:
    string replaceWords(vector<string> &dict, string sentence) {

        // 1. 根据dict中的words建立字典树
        TrieNode *root = new TrieNode();
        for (int i = 0; i < dict.size(); ++i) {
            // 插入
            insertToTrie(root, dict[i]);
        }
        // replace words
        // 按空格分隔 sentence
        istringstream iis(sentence);

        vector<string> words;
        copy(
                istream_iterator<string>(iis),
                istream_iterator<string>(),
                back_inserter(words)
        );

        vector<string> resWords;
        for (int i = 0; i < words.size(); ++i) {
            resWords.push_back(searchConceptWord(root, words[i]));
        }


        string resSentence = "";
        for (int i = 0; i < resWords.size(); ++i) {
            resSentence += resWords[i];
            if (i != resWords.size() - 1)
                resSentence += " ";
        }

        return resSentence;
    }
};


int main() {
    Solution s;


    vector<string> dict = {"e", "k", "c", "harqp", "h", "gsafc", "vn", "lqp", "soy", "mr", "x", "iitgm", "sb", "oo",
                           "spj", "gwmly", "iu", "z", "f", "ha", "vds", "v", "vpx", "fir", "t", "xo", "apifm", "tlznm",
                           "kkv", "nxyud", "j", "qp", "omn", "zoxp", "mutu", "i", "nxth", "dwuer", "sadl", "pv", "w",
                           "mding", "mubem", "xsmwc", "vl", "farov", "twfmq", "ljhmr", "q", "bbzs", "kd", "kwc", "a",
                           "buq", "sm", "yi", "nypa", "xwz", "si", "amqx", "iy", "eb", "qvgt", "twy", "rf", "dc", "utt",
                           "mxjfu", "hm", "trz", "lzh", "lref", "qbx", "fmemr", "gil", "go", "qggh", "uud", "trnhf",
                           "gels", "dfdq", "qzkx", "qxw"};

    string sentence = "ikkbp miszkays wqjferqoxjwvbieyk gvcfldkiavww vhokchxz dvypwyb bxahfzcfanteibiltins ueebf lqhflvwxksi dco kddxmckhvqifbuzkhstp wc ytzzlm gximjuhzfdjuamhsu gdkbmhpnvy ifvifheoxqlbosfww mengfdydekwttkhbzenk wjhmmyltmeufqvcpcxg hthcuovils ldipovluo aiprogn nusquzpmnogtjkklfhta klxvvlvyh nxzgnrveghc mpppfhzjkbucv cqcft uwmahhqradjtf iaaasabqqzmbcig zcpvpyypsmodtoiif qjuiqtfhzcpnmtk yzfragcextvx ivnvgkaqs iplazv jurtsyh gzixfeugj rnukjgtjpim hscyhgoru aledyrmzwhsz xbahcwfwm hzd ygelddphxnbh rvjxtlqfnlmwdoezh zawfkko iwhkcddxgpqtdrjrcv bbfj mhs nenrqfkbf spfpazr wrkjiwyf cw dtd cqibzmuuhukwylrnld dtaxhddidfwqs bgnnoxgyynol hg dijhrrpnwjlju muzzrrsypzgwvblf zbugltrnyzbg hktdviastoireyiqf qvufxgcixvhrjqtna ipfzhuvgo daee r nlipyfszvxlwqw yoq dewpgtcrzausqwhh qzsaobsghgm ichlpsjlsrwzhbyfhm ksenb bqprarpgnyemzwifqzz oai pnqottd nygesjtlpala qmxixtooxtbrzyorn gyvukjpc s mxhlkdaycskj uvwmerplaibeknltuvd ocnn frotscysdyclrc ckcttaceuuxzcghw pxbd oklwhcppuziixpvihihp";
    string correctSentence = "i miszkays w gvcfldkiavww v dvypwyb bxahfzcfanteibiltins ueebf lqhflvwxksi dc k w ytzzlm gximjuhzfdjuamhsu gdkbmhpnvy i mengfdydekwttkhbzenk w h ldipovluo a nusquzpmnogtjkklfhta k nxzgnrveghc mpppfhzjkbucv c uwmahhqradjtf i z q yzfragcextvx i i j gzixfeugj rnukjgtjpim h a x h ygelddphxnbh rvjxtlqfnlmwdoezh z i bbfj mhs nenrqfkbf spfpazr w c dtd c dtaxhddidfwqs bgnnoxgyynol h dijhrrpnwjlju muzzrrsypzgwvblf z h q i daee r nlipyfszvxlwqw yoq dewpgtcrzausqwhh q i k bqprarpgnyemzwifqzz oai pnqottd nygesjtlpala q gyvukjpc s mxhlkdaycskj uvwmerplaibeknltuvd ocnn f c pxbd oklwhcppuziixpvihihp";


//    vector<string> dict = {"a", "aa", "aaa", "aaaa"};
//    string sentence = "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa";
//    string correctSentence = "a a a a a a a a bbb baba a";


    string replaceSentence = s.replaceWords(dict, sentence);
    bool res = correctSentence == replaceSentence;
    cout << correctSentence << endl;
    cout << replaceSentence << endl;
    cout << res << endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}