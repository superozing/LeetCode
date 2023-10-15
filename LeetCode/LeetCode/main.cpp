#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

struct sLog
{
    string log;

    string source;
    bool isLetter;
};

//struct sWord

class Solution
{
public:
    string mostCommonWord(string paragraph, vector<string>& banned) 
    {
        map<string, int> wordMap;
        string wordBuf;
        size_t i = 0;
        // 65~90 -> 대
        // 97~122-> 소
        for (i = 0; i < paragraph.length(); ++i)
        {
            if (65 <= paragraph[i] && paragraph[i] <= 90)
                wordBuf += (paragraph[i] + 32);

            else if (97 <= paragraph[i] && paragraph[i] <= 122)
                wordBuf += paragraph[i];

            else if (!(65 <= paragraph[i] && paragraph[i] <= 90) && !(97 <= paragraph[i] && paragraph[i] <= 122))
            {
                auto it = wordMap.find(wordBuf);
                if (wordMap.end() == it)
                    wordMap.insert(make_pair(wordBuf, 1));
                else
                    ++(it->second);
                wordBuf.clear();
            }
        }
        if (wordBuf.length())
        {
            auto it = wordMap.find(wordBuf);
            if (wordMap.end() == it)
                wordMap.insert(make_pair(wordBuf, 1));
            else
                ++(it->second);
            wordBuf.clear();
        }
        i = 0;
        for (auto& it : wordMap)
        {
            bool flag = false;
            if (it.second > i)
            {
                if (banned.size() != 0)
                {
                    for (auto& t : banned)
                    {
                        if (it.first == t)
                        {
                            flag = true;
                        }
                    }
                    if (!flag&&it.first != "")
                    {
                        wordBuf = it.first;
                        i = it.second;
                    }
                }
                else
                {
                   wordBuf = it.first;
                    i = it.second;
                }
            }
        }
        
        return wordBuf;

    }
    vector<string> reorderLogFiles(vector<string>& logs)
    {
        map<string, sLog>   LetterLog;
        map<string, sLog>   DigitLog;
        sLog        insertLog;

        for (size_t i = 0; i < logs.size(); ++i)
        {
            
            insertLog.log.clear();
            insertLog.source.clear();

            // 1. 식별자와 로그 구분
            string sBuf = logs[i];

            insertLog.source = sBuf;

            for (size_t j = 0; j < sBuf.length() - 1; ++j)
            {
                if (sBuf[j] == ' ')
                {
                    for (size_t k = j + 1; k < sBuf.length() - 1; ++k)
                        insertLog.log += sBuf[k];
                    break;
                }
            }
            for (size_t j = 0; sBuf[j] != ' '; ++j)
                insertLog.log += sBuf[j];

            // 2. 로그가 글자 로그인지, 숫자 로그인지 구분
            if (48 <= insertLog.log[0] && insertLog.log[0] <= 57)
                DigitLog.insert(make_pair(insertLog.log, insertLog));
            else
                LetterLog.insert(make_pair(insertLog.log, insertLog));
        }

        logs.clear();

        for (map<string, sLog>::iterator it = LetterLog.begin(); it != LetterLog.end(); ++it)
            logs.push_back(it->second.source);
        for (map<string, sLog>::iterator it = DigitLog.begin(); it != DigitLog.end(); ++it)
            logs.push_back(it->second.source);

        return logs;
    }
};

int main()
{
    Solution sol;

    string s = "Bob. hIt, baLl";//"Bob";//"Bob hit a ball, the hit BALL flew far after it was hit.";
    vector<string> v;
    v.push_back("hit");
    v.push_back("bob");

    sol.mostCommonWord(s, v);

    return 0;
}