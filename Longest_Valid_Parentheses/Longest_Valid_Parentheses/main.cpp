//
//  main.cpp
//  Longest_Valid_Parentheses
//
//  Created by 李佳 on 15/10/14.
//  Copyright © 2015年 LiJia. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s)
    {
        size_t longestValidLength = 0;
        map<size_t, size_t> countMap;
        
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == ')') //找到一个右括号 找到能与之匹配的左括号(最近的还没有匹配的  如果被匹配了为空格)
            {
                size_t findPos = s.find_last_of("(", i, 1);
                if (findPos != std::string::npos)
                {
                    size_t curLength = i - findPos + 1;
                    ////看看有无相连的
                    if (findPos > 0 && s[findPos - 1] == '1')
                    {
                        size_t lastLength = countMap[findPos - 1];
                        curLength += lastLength;
                    }
                    
                    if (curLength > longestValidLength)
                    {
                        longestValidLength = curLength;
                    }
                    
                    s[findPos] = ' ';
                    s[i] = '1';
                    countMap.insert(make_pair(i, curLength));
                }
            }
        }
        return (int)longestValidLength;
    }
};

int main(int argc, const char * argv[])
{
    Solution* pSol = new Solution;
    int result = pSol->longestValidParentheses("(())(())())");
    printf("longestValidParentheses -- %d\n", result);
    return 0;
}
