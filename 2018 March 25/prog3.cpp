#include <iostream>
#include <vector>
using namespace std;

/*
3 Annual Day Celebration

Akshara International School has started preparations for this year’s annual day celebrations.
All students of the school are divided into four color groups: Red, White, Green and Blue.
To begin the dance rehearsals, all the students were asked to assemble in the playground and
chose their dance partners from any color group. A student can have only one dance partner.
Most of the students have chosen their partners from other color groups and a few from the same color group.
Dance pairs are represented by first letter of their color group.
For example, White and Red pair shall be represented as W R.
The dance master selects some random dance-pairs of students and asks his assistants to form circles
with those selected pairs. The rules to form the circle are as follows:
1. A circle can have a minimum of 2 dance-pairs.
2. In a circle, two adjacent dance-pairs shall have students from a common color group i.e.,
[y, W] can be paired with [W, x] only. ‘x’,’y’ can be any other color.
3. To implement rule-2 (above), positions of students within a pair can be interchanged i.e.,
[R, W] needs [W, x]. If we have [G, W] then the positions of students can be swapped to [W, G]
so that [R, W] and [W, G] can be linked.

To help assistants, write a program to accept the total number dance-pairs
and the dance-pairs in each line and do the following:
1. Determine if they can form a circle (by applying rules mentioned above)
with the set of dance-pairs selected by the master.
The output can be true in the first line followed by the dancing-pairs one in each line sorted in the
descending order otherwise just print false
2. For any erroneous input, display invalid input followed by input values.

Sample Input :
5
B G
G R
R W
W B
R R
Sample Output :
true
W R
R R
R G
G B
B W

Sample Input 2 :
4
G R
R W
W B
R R
Sample Output 2:
false

Sample Input 3 :
-5
Sample Output 3 :
invalid input -5
*/

int doItUtil(vector<string> pairs, vector<string> *fin, int num, int visited[])
{
    if(fin->size()==pairs.size())
    {
        if(fin->front()[0]==fin->back()[1]) { return 1;}
        return 0;
    }

    char temp;

    for(int i = 0; i < num; i++)
    {
        if(visited[i]==0&&(fin->back()[1]==pairs[i][0]))
        {
            fin->push_back(pairs[i]);
            visited[i] = 1;
            if(doItUtil(pairs, fin, num, visited)) { return 1;}
            fin->pop_back();
            visited[i] = 0;
        }

        temp = pairs[i][0];
        pairs[i][0] = pairs[i][1];
        pairs[i][1] = temp;

         if(visited[i]==0&&(fin->back()[1]==pairs[i][0]))
        {
            fin->push_back(pairs[i]);
            visited[i] = 1;
            if(doItUtil(pairs, fin, num, visited)) { return 1;}
            fin->pop_back();
            visited[i] = 0;
        }

        temp = pairs[i][0];
        pairs[i][0] = pairs[i][1];
        pairs[i][1] = temp;
    }


    return 0;
}

int doIt(vector<string> pairs, int num)
{
    int visited[num];
    for(int i = 0; i < num; i++) { visited[i] = 0;}

    vector<string> fin;
    char temp;
    int yes = 0;
    string tempstr;

    for(int i = 0; i < num; i++)
    {
        fin.push_back(pairs[i]);
        visited[i] = 1;
        if(doItUtil(pairs, &fin, num, visited))
        {
            cout << "true" << '\n';
            for(int j = 0; j < fin.size(); j++)
            {
                cout << fin[j][0] << ' ' << fin[j][1] << '\n';
            }
            yes = 1;
            break;

        }
        fin.pop_back();
        visited[i] = 0;

        temp = pairs[i][0];
        pairs[i][0] = pairs[i][1];
        pairs[i][1] = temp;

        fin.push_back(pairs[i]);
        visited[i] = 1;
        if(doItUtil(pairs, &fin, num, visited))
        {
            cout << "true" << '\n';
            for(int j = 0; j < fin.size(); j++)
            {
                cout << fin[j][0] << ' ' << fin[j][1] << '\n';
            }
            yes = 1;
            break;

        }
        fin.pop_back();
        visited[i] = 0;

        temp = pairs[i][0];
        pairs[i][0] = pairs[i][1];
        pairs[i][1] = temp;
    }

    if(!yes) { cout << "false" << '\n';}
}

main()
{
    int num;
    cin >> num;

    if(num > 1)
    {
        vector<string> pairs;
        char c1, c2;

        for(int i = 0; i < num; i++)
        {
            string inp;
            cin >> c1;
            cin >> c2;

            if(c1 > c2) { inp.push_back(c1); inp.push_back(c2);}
            else { inp.push_back(c2); inp.push_back(c1);}
            /*inp.push_back(c1);
            inp.push_back(c2);*/
            pairs.push_back(inp);
        }

        string tempstr;

        for(int i = 0; i < pairs.size(); i++)
        {
            for(int j = 0; j < pairs.size()-i-1; j++)
            {
                if(pairs[j][0]==pairs[j][1])
                {
                    if(pairs[j][1]<pairs[j+1][1])
                    {
                        tempstr = pairs[j+1];
                        pairs[j+1] = pairs[j];
                        pairs[j] = tempstr;
                    }
                }

                if(pairs[j][0]<pairs[j+1][0])
                {
                    tempstr = pairs[j+1];
                    pairs[j+1] = pairs[j];
                    pairs[j] = tempstr;
                }

            }
        }

       doIt(pairs, num);
    }
    else
    {
        cout << "invalid input " << num << '\n';
    }
}
