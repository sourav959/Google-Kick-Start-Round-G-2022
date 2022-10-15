import java.util.*;

class Solution{
    static long calcSum(int[] inpArr,int i,int j){
        if(inpArr[i]<0)
            return 0;
        long sum=0;
        for(;i<j;i++){
            sum+=inpArr[i];
            if(sum<0)
                return 0;
        }
        return sum;
    }
    public static long solve(int[] inpArr,int n){
        long ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<=n;j++){
                ans+=calcSum(inpArr,i,j);
            }
        }
        return ans;
    }
    public static void main(String[] agrs){
        Scanner sc=new Scanner(System.in);
        int testcase=sc.nextInt();
        for(int test=1;test<=testcase;test++){
            int n=sc.nextInt();
            int[] inpArr=new int[n];
            for(int i=0;i<n;i++)
                inpArr[i]=sc.nextInt();
            long ans=solve(inpArr,n);
            System.out.println("Case #"+test+": "+ans);
        }
    }
}