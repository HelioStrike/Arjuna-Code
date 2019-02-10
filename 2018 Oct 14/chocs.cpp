#include <bits/stdc++.h>
#define INF 99999
using namespace std;


int canFall(map<int, int> &fallen, int pos)
{
    return (fallen.find(pos) != fallen.end());
}

int allFallen(map<int, int> &fallen)
{
    return fallen.empty();
}

int rec(map<int, int> &posnh, map<int, int> &fallen, int toppling, int curr_pos)
{
    if(allFallen(fallen))
    {
        return 0;
    }

    if(toppling)
    {
        pair<int, int> toppled = *posnh.find(curr_pos);
        
        int mini = INF;
        int curr;
        if(canFall(fallen, curr_pos + toppled.second))
        {
            fallen.erase(curr_pos + toppled.second);
            curr = rec(posnh, fallen, toppling, curr_pos + toppled.second);
            fallen.insert(pair<int, int> (curr_pos + toppled.second, 0));

            if(curr < mini) mini = curr;
        }

        if(canFall(fallen, curr_pos - toppled.second))
        {
            fallen.erase(curr_pos - toppled.second);
            curr = rec(posnh, fallen, toppling, curr_pos - toppled.second);
            fallen.insert(pair<int, int> (curr_pos - toppled.second, 0));

            if(curr < mini) mini = curr;
        }

        if(mini == INF)
        {
            return rec(posnh, fallen, 0, 0);
        }

        return mini;
    }
    else
    {
        map<int, int>::iterator it;
        pair<int, int> curr_elem;
        pair<int, int> mini_elem;
        int mini = INF;
        int curr;
        for(it = posnh.begin(); it != posnh.end(); it++)
        {
            curr_elem = *it;

            if(canFall(fallen, curr_elem.first))
            {
                fallen.erase(curr_elem.first);
                curr = rec(posnh, fallen, 1, curr_elem.first);
                fallen.insert(pair<int, int> (curr_elem.first, 0));
                if(1 + curr < mini)
                {
                    mini_elem = curr_elem;
                    mini = 1 + curr;
                }
            }
        }

        //cout << "Pushed: " << mini_elem.first << '\n';

        return mini;
    }
}

int main()
{
    int n, pos, h; cin >> n;

    map<int, int> posnh;
    map<int, int> fallen;

    for(int i = 0; i < n; i++)
    {
        cin >> pos;
        cin >> h;
        posnh.insert(pair<int, int> (pos, h));
        fallen.insert(pair<int, int> (pos, 0));
    }

    int ans = rec(posnh, fallen, 0, 0);
    cout << ans << '\n';

    return 0;
}