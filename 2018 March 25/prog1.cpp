#include <iostream>
#include <cmath>
using namespace std;

/*
1 Changing Street Numbers of City of Rome

The Mayor of Rome City has decided to abolish using English numerals for all Door & Street numbers in the city.
He wants to popularize Roman Numerals and to that effect he passed an order to replace all street and door numbers
with roman numerals. Roman numerals are a combination of standard symbols like (I, V, X, L, C).

The Mayor wants the roman digits be cut from rectangular brass block of standard size.
From a brass block, we can cut either 6 of (I or L) or 4 of (X or V or C) digits.
As a pilot project, he wants to try out with a few selected streets to find out total number of roman digits
needed to replace all English numbers with Roman numbers and also the number of brass blocks needed.

Write a program to read the range of street numbers i.e., start street number and end street number (in English form) and
1. Determine the total number of each roman digit i.e., total number of I’s, V’s, X’s, L’s and C’s,
need to for street numbers between start and end street number (including both).
Display the total of each roman digit in separate line followed by the total number of brass plates needed
for all roman digits.
2. For any erroneous input, display invalid input followed input values.

Sample Input :
10 15

Sample Output :
I 7
V 2
X 6
L 0
C 0
TP 5

Sample Input 2:
10 5
Sample Output 2:
invalid input 10 5
*/

main()
{
   int n1, n2; cin >> n1; cin >> n2;

    if((n1 > n2)||(n1 <= 0) || (n2 <= 0)) { cout << "invalid input " << n1 << ' ' << n2 << '\n';}

    int I_count = 0;
    int V_count = 0;
    int X_count = 0;
    int L_count = 0;
    int C_count = 0;
    int P_count = 0;

    for(int i = n1; i <= n2; i++)
    {
        int n = i;
        while(n >= 100)
        {
            C_count++; n-= 100;
        }

        if(n >= 90) { X_count++; C_count++; n-= 90;}
        if(n >= 50 ){ L_count++; n-= 50;}
        if(n >= 40) { X_count++; L_count++; n-= 40;}

        while(n >= 10)
        {
            X_count++; n-= 10;
        }

        if(n == 9) { I_count++; X_count++; n-= 9;}
        if(n >= 5){ V_count++; n-= 5;}
        if(n == 4) { I_count++; V_count++; n-= 4;}

        while(n > 0)
        {
            I_count++; n-= 1;
        }
    }

    P_count = ceil(1.0*I_count/6) + ceil(1.0*L_count/6) + ceil(1.0*X_count/4) + ceil(1.0*V_count/4) + ceil(1.0*C_count/4);

    cout << "I " << I_count << '\n';
    cout << "V " << V_count << '\n';
    cout << "X " << X_count << '\n';
    cout << "L " << L_count << '\n';
    cout << "C " << C_count << '\n';
    cout << "TP " << P_count << '\n';
}
