import java.util.Scanner;

//Using Eggdrop DP
//Time Complexity - O(N*M*M)

class Muffins
{
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int m=sc.nextInt();
        int n=sc.nextInt();

        int x;
        int dp[][]=new int[m+1][n+1]; 
    
        for (int i=1; i<=m; i++) 
        { 
            dp[i][1]=1; 
            dp[i][0]=0; 
        } 
    
        for (int j=1; j<=n; j++) dp[1][j]=j; 
    
        for (int i=2; i<=m; i++) 
        { 
            for (int j=2; j<=n; j++) 
            { 
                dp[i][j] = 1<<30; 
                for (int k=1; k<=j; k++) 
                { 
                    x=1+Math.max(dp[i-1][k-1],dp[i][j-k]);
                    dp[i][j]=Math.min(dp[i][j],x);
                } 
            } 
        } 
        /*
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n;j++) System.out.print(dp[i][j]+" ");
            System.out.println();
        }
        */

        System.out.println(dp[m][n]);
    }
}

/*

import java.util.Scanner;

//Optimal Strategy would be binary search until we have 2 muffins left
//Then, one muffin can be used to check a step after every sqrt(n) steps
//Last one is used to check the next sqrt(n) steps

class Muffins
{
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int m=sc.nextInt();
        int n=sc.nextInt();

        int ans=0;
        while(m>2) { n/=2; m--; ans++; }
        if(m==2) { ans+=(int)Math.sqrt(n)-1; m--; }
        if(m==1) { ans+=(int)Math.sqrt(n); }
        System.out.println(ans);
    }
}

*/