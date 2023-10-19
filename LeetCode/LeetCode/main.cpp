#include "헤더.h"

struct sLog
{
    string log;

    string source;
    bool isLetter;
};


class Solution
{
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        bool flag = false;
        vector<vector<string>> vReturn;
        for (size_t j = 0; j < strs.size(); ++j)
        {
            string sSource = strs[j];
            string sBuf = "";
            string vBuf = "";
            set<char> setSort;
           
            
            // 1. 문자열을 정렬해서 
            if (sSource != "")
            {
                for (size_t i = 0; i < sSource.size(); ++i)
                    setSort.insert(sSource[i]);
            
                for (auto& it : setSort)
                {
                    sBuf += it;
                }
                setSort.clear();
            }

            
            flag = false;
            
            // 정렬한 문자열이 이미 있는 문자열인가?를 확인
            for (auto& it : vReturn)
            {
                setSort.clear();

                if (sSource != "")
                {
                    for (size_t i = 0; i < it[0].size(); ++i)
                        setSort.insert(it[0][i]);

                    for (auto& it : setSort)
                    {
                        vBuf += it;
                    }

                    setSort.clear();
                }
               
                // 2. 만약 있는 문자열이라면 
                if (vBuf == sBuf)
                {
                    // 해당 벡터에 넣기
                    it.push_back(sSource);
                    flag = true;
                    break;
                }
            }
            // 3. 만약 없는 문자열이라면 
            if (!flag)
            {
                // 새로운 set를 만들어 
                vector<string> vNewstr;
                vNewstr.push_back(sSource);
                // 그 set에 넣기
                vReturn.push_back(vNewstr);
            }

        }
        
        return vReturn;
    }

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

//int main()
//{
//    Solution sol;
//
//    //string s = "Bob. hIt, baLl";//"Bob";//"Bob hit a ball, the hit BALL flew far after it was hit.";
//    vector<string> v;
//    //"eat", "tea", "tan", "ate", "nat", "bat"
//    v.push_back("eat");
//    v.push_back("tea");
//    v.push_back("tan");
//    v.push_back("ate");
//    v.push_back("nat");
//    v.push_back("bat");
//
//    //sol.mostCommonWord(s, v);
//    sol.groupAnagrams(v);
//
//    return 0;
//}