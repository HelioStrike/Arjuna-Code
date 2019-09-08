import java.util.Scanner;

//Using DP
//At any point, the extra depth is equal to the min between the max height to the left and the right
//Time Complexity - O(n)

class Quarry
{
    static int[] stringArrayToIntArray(String[] a){
        int[] b = new int[a.length];
        for(int i = 0; i < a.length; i++) b[i] = Integer.parseInt(a[i]);
        return b;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] heights = stringArrayToIntArray(sc.nextLine().split(" "));
        int n = heights.length;

        int[] dp = new int[n];
        for(int i=0; i<n; i++) dp[i]=0;
        int curr=0,ans=0;
        for(int i=0; i<n; i++) 
        {
            curr=Math.max(curr,heights[i]);
            dp[i]=curr;
        }
        
        curr=0;
        for(int i=n-1; i>=0; i--)
        {
            curr=Math.max(curr,heights[i]);
            ans+=Math.min(dp[i],curr)-heights[i];
        }
        System.out.println(ans);
    }
}