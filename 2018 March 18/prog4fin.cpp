#include <iostream>
using namespace std;


main()
{
    int cases;
    cin >> cases;

    int num, temp;
    float med, sum, n;
    while(cases--)
    {
        sum = 0;
        cin >> num;

        //storing street numbers
        int arr[num];
        for(int i = 0; i < num; i++)
        {
            cin >> arr[i];
        }

        //bubble sorting street numbers
        for(int i = 0; i < num; i++)
        {
            for(int j = 0; j < num-i-1; j++)
            {
                if(arr[j] > arr[j+1])
                {
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }

        //calculating median
        if(num%2)
        {
            med = arr[num/2];
        }
        else
        {
            med = ((arr[num/2]+arr[num/2-1])/2);
        }

        //finding sum(abs(arr[i]-median))
        for(int i = 0; i < num; i++)
        {
            n = (arr[i]-med);
            if(n < 0)
            {
                n = -n;
            }
            sum += n;
        }
        //printing out sum
        cout << sum << '\n';
    }
}
