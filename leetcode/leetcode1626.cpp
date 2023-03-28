#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int bestTeamScore(vector<int> &scores, vector<int> &ages)
{
    int playerNum = ages.size();
    vector<pair<int, int>> ageScorePair(playerNum);
    vector<int> dp(playerNum, 0);
    int maxScore = 0;

    for (int i = 0; i < playerNum; i++)
    {
        ageScorePair[i].first = ages[i];
        ageScorePair[i].second = scores[i];
    }

    sort(ageScorePair.begin(), ageScorePair.end(), [](pair<int, int> a, pair<int, int> b)
         { return a.first == b.first ? a.second < b.second : a.first < b.first; });

    for (int i = 0; i < playerNum; i++)
    {
        dp[i] = ageScorePair[i].second;
        maxScore = max(dp[i], maxScore);
    }

    for (int i = 0; i < playerNum; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (ageScorePair[i].second >= ageScorePair[j].second)
            {
                    dp[i] = max(dp[i],dp[j]+ageScorePair[i].second);
            }
        }
        maxScore = max(dp[i], maxScore);
    }

    return maxScore;
}

int main()
{
    vector<int> score = {4,5,6,5};//5546
    vector<int> age = {2,1,2,1};
    int ans = bestTeamScore(score, age);
    return 0;
}