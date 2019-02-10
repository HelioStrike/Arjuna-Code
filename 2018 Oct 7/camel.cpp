#include <bits/stdc++.h>
using namespace std;

void get_time(int& t)
{
  string s; cin >> s;
  t = ((s[0]-'0')*10 + (s[1]-'0'))*60 + (s[3]-'0')*10 + (s[4]-'0');
}

int main()
{
  int n; cin >> n;

  vector<pair<int,int> > times;

  string s;
  for(int i = 0; i < n; i++)
  {
    times.push_back(pair<int, int>(0, 0));
    get_time(times[i].first);
    get_time(times[i].second);
  }

  int wake_time, shop_open_time, feed_time, shop_travel_time, buy_time;

  get_time(wake_time); get_time(shop_open_time); get_time(feed_time);

  cin >> shop_travel_time >> buy_time;

  for(int i = 0; i < n; i++)
  {
    if((times[i].first - wake_time >= 2*shop_travel_time + buy_time && feed_time - wake_time >= 2*shop_travel_time + buy_time && times[i].first - shop_open_time >= shop_travel_time + buy_time && feed_time - shop_open_time >= shop_travel_time + buy_time))
    {
      cout << (i+1) << '\n';
      exit(0);
    }
  }

  for(int i = 0; i < n; i++)
  {
    if((feed_time - times[i].second >= 2*shop_travel_time + buy_time && feed_time - shop_open_time >= shop_travel_time + buy_time))
    {
      cout << (i+1) << '\n';
      exit(0);
    }
  }

  cout << -1 << '\n';
}
