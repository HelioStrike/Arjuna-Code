import java.util.Scanner;

//Each time we're finding subarray with least cost and merging it
//Time Complexity - O(n)

class Guavas
{
    static int[] stringArrayToIntArray(String[] a){
        int[] b = new int[a.length];
        for(int i = 0; i < a.length; i++) b[i] = Integer.parseInt(a[i]);
        return b;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] groups = stringArrayToIntArray(sc.nextLine().split(" "));
        int n = groups.length;
        int k = sc.nextInt();

        if((n-1)%(k-1) != 0)
        {
            System.out.println(-1);
            System.exit(0);
        }

        int l,r,c,curr,best,ans=0;
        int[] temp = new int[n];
        while(n!=1)
        {
            curr=0; l=0; r=k-1;
            for(int i=0;i<k;i++) curr+=groups[i];
            best=curr;

            for(int i=k;i<n;i++) 
            {
                curr+=groups[i]-groups[i-k];
                if(curr<best)
                {
                    best=curr;
                    l=i-k+1; r=i;
                }
            }
            ans+=best;

            c=curr=0;
            for(int i=0;i<l;i++) { temp[c]=groups[i]; c++; }
            for(int i=l;i<=r;i++) curr+=groups[i];
            temp[c]=curr; c++;
            for(int i=r+1;i<n;i++) { temp[c]=groups[i]; c++; }

            for(int i=0;i<c;i++) groups[i]=temp[i];
            n=c;
        }
        System.out.println(ans);
    }
}