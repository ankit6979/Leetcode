#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int garbageCollection(vector<string> &garbage, vector<int> &travel)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int pGarbage = 0, mGarbage = 0, gGarbage = 0;
        int pDistance = 0, mDistance = 0, gDistance = 0;
        bool pHouseStop, mHouseStop, gHouseStop;
        for (int house = 0; house < garbage.size(); house++)
        {
            pHouseStop = false, mHouseStop = false, gHouseStop = false;
            for (int garbages = 0; garbages < garbage[house].size(); garbages++)
            {
                if (garbage[house][garbages] == 'M')
                {
                    mGarbage++;
                    mHouseStop = true;
                }
                if (garbage[house][garbages] == 'P')
                {
                    pGarbage++;
                    pHouseStop = true;
                }
                if (garbage[house][garbages] == 'G')
                {
                    gGarbage++;
                    gHouseStop = true;
                }
            }
            if (house > 0)
            {
                pDistance += travel[house - 1];
                mDistance += travel[house - 1];
                gDistance += travel[house - 1];
                if (mHouseStop)
                {
                    mGarbage += mDistance;
                    mDistance = 0;
                }
                if (pHouseStop)
                {
                    pGarbage += pDistance;
                    pDistance = 0;
                }
                if (gHouseStop)
                {
                    gGarbage += gDistance;
                    gDistance = 0;
                }
            }
        }
        return mGarbage + pGarbage + gGarbage;
    }
};