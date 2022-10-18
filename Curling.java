import java.util.*;

class Solution{
    public static int calculate(int Rs,int Rh,int N,int[][] arr1,int M,int[][] arr2){
        int count=0;
        long area1=(Rs+Rh)*(Rs+Rh);
        for(int i=0;i<N;i++){
            int x1=arr1[i][0];
            int y1=arr1[i][1];
            long area2=x1*x1+y1*y1;
            if(area2<=area1){
                boolean add=true;
                for(int j=0;j<M;j++){
                    int x2=arr2[j][0];
                    int y2=arr2[j][1];
                    long area3=x2*x2+y2*y2;
                    add=add&(area2<area3);
                }
                if(add)
                    count++;
            }
        }
        return count;
    }
    public static String solve(int Rs,int Rh,int N,int M,int[][] arr1,int[][] arr2){
        int x=calculate(Rs,Rh,N,arr1,M,arr2);
        if(M==0)
            return String.valueOf(x)+" 0";
        int y=calculate(Rs,Rh,M,arr2,N,arr1);
        if(x>y)
            return String.valueOf((x-y))+" 0";
        else
            return "0 "+String.valueOf((y-x));
    }
    public static void main(String[] agrs){
        Scanner sc=new Scanner(System.in);
        int testCase=sc.nextInt(),x=1;
        for(int test=1;test<=testCase;test++){
            int Rs=sc.nextInt();
            int Rh=sc.nextInt();
            int N=sc.nextInt();
            int[][] arr1=new int[N][2];
            for(int i=0;i<N;i++){
                arr1[i][0]=Math.abs(sc.nextInt());
                arr1[i][1]=Math.abs(sc.nextInt());
            }
            int M=sc.nextInt();
            int[][] arr2=new int[M][2];
            for(int i=0;i<M;i++){
                arr2[i][0]=sc.nextInt();
                arr2[i][1]=sc.nextInt();
            }
            String ans=solve(Rs,Rh,N,M,arr1,arr2);
            System.out.println("Case #"+test+": "+ans);
        }
    }
}