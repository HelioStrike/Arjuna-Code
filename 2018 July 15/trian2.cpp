#include <iostream>
#include <string.h>
#include <cstdlib>
using namespace std;

int selections(int n, int r)
{
    int out = 1;
    for(int i = 0; i < r; i++) { out *= (n-i); out/= (i+1);}

    return out;
}

int stoint(char* cp)
{
    int tot = 0;
    int pos = 0;

    while(cp[pos] != '\0')
    {
        tot = 10*tot + cp[pos] - 48;
        pos++;
    }

    return tot;
}

main() {
    int n; cin >> n;
    int angle;
    int angle_counts[180]; memset(angle_counts, 0, sizeof(angle_counts));
    char inp[1000]; cin >> inp;
    char save[1000]; strcpy(save, inp);
    char *token = strtok(inp, ",");

    int m = 0;
    while(token != NULL)
    {
        angle = stoint(token);
        if(angle <= -90 || angle > 90)
        {
            cout << "Invalid Input Angles " << save << '\n';
            exit(1);
        }

        angle_counts[angle+89]++;
        token = strtok(NULL, ",");
        m++;
    }

    if(m != n) { cout << "Invalid Input N " << n << '\n'; exit(1);}

    int ans = selections(n, 3);
    for(int i = 0; i < 180; i++)
    {
        if(angle_counts[i] > 1) { ans -= (n-angle_counts[i])*selections(n, 2); }
        if(angle_counts[i] > 2) { ans -= selections(n, 3); }
    }
    cout << ans << '\n';
}
