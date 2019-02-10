#include <bits/stdc++.h>
#define INF 99999
#define MAXSIZE 1000
using namespace std;


void fillPrimes(vector<int> &primes, int limit)
{
    primes.push_back(2);

    int flag;
    for(int i = 3; i < limit; i++)
    {
        flag = 1;
        for(int j = 2; j <= sqrt(i); j++)
        {
            if(i%j == 0)
            {
                flag = 0;
                break;
            }
        }
        if(flag) primes.push_back(i);
    }
}

int findNextPrime(vector<int> primes, int n)
{
    for(int i = 0; i < primes.size(); i++)
    {
        if(primes[i] >= n) return primes[i];
    }
}

int findPrevPrimeForPrime(vector<int> primes, int n)
{
    for(int i = primes.size()-1; i >= 0; i--)
    {
        if(primes[i] < n) return primes[i];
    }

}

int returnNeeded(vector<int> primes, int a, int b)
{
    int np1, np2;
    np1 = findNextPrime(primes, a);
    np2 = findNextPrime(primes, b);
    if(np1 == np2) np1 = findNextPrime(primes, np1+1);
    else if(np1 < np2)
    {
        np1 = findPrevPrimeForPrime(primes, np2);
    }
    else
    {
        np2 = findPrevPrimeForPrime(primes, np1);
    }
    return ((np1 - a) + (np2 - b));    
}

int main()
{
    int n, elem; cin >> n;
    vector<int> arr; for(int i = 0; i < n; i++){ cin >> elem; arr.push_back(elem);}

    vector<int> primes; 
    fillPrimes(primes, MAXSIZE);

    //for(int i = 0; i < 10; i++) cout << primes[i] << '\n';

    int needed, mini, mini_idx, surround_mini, surround, idk;

    int tot = 0;
    for(int moves = 0; moves < n/2; moves++)
    {
        mini = returnNeeded(primes, arr[0], arr[1]);
        mini_idx = 0;
        surround_mini = INF;
        for(int i = 1; i < arr.size()-2; i++)
        {
            needed = returnNeeded(primes, arr[i], arr[i+1]);
            if(needed <= mini)
            {
                surround = returnNeeded(primes, arr[i-1], arr[i+2]); 

                if(surround < surround_mini)
                {
                    mini = needed; mini_idx = i;
                }
            }
        }

        idk = returnNeeded(primes, arr[arr.size()-2], arr[arr.size()-1]);
        if(idk < mini){ mini = idk; mini_idx = arr.size()-2;}

        tot += mini;
        arr.erase(arr.begin() + mini_idx);
        arr.erase(arr.begin() + mini_idx);
    }

    tot += n/2;
    cout << tot << '\n';
}