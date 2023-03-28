#include <vector>
#include <iostream>
using namespace std;

int totalFruit(vector<int> &fruits)
{
    vector<int> bucket;
    int fruitsLen = fruits.size(), maxTree = 0, tempMaxTree = 0;
    if (fruitsLen == 1)
        return 1;
    for (int i = 0; i < fruitsLen - 1; i++)
    {
        bucket.push_back(fruits[i]);
        if (fruits[i] == fruits[i + 1])
        {
            tempMaxTree += 1;
            maxTree = max(tempMaxTree, maxTree);
            bucket.erase(bucket.begin());
            continue;
        }
        for (int j = i + 1; j < fruitsLen; j++)
        {
            int bucketLen = bucket.size(), fruitInBucket = 0;
            for (int b = 0; b < bucketLen; b++)
            {
                if (bucket[b] == fruits[j])
                {
                    fruitInBucket = 1;
                    break;
                }
            }
            if (bucketLen < 2 && fruitInBucket == 0)
            {
                bucket.push_back(fruits[j]);
            }
            if (fruitInBucket == 0 && bucketLen == 2)
            {
                tempMaxTree = 0;
                break;
            }

            tempMaxTree++;
            maxTree = max(maxTree, tempMaxTree);
            if (j == fruitsLen - 1)
                return maxTree + 1;
        }
        bucket.clear();
    }
    return maxTree + 1;
}
int main()
{
    vector<int> fruits = {0, 0, 1, 1};
    totalFruit(fruits);
    return 0;
}