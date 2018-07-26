import java.util.Scanner;
import java.util.Random;

class Mergesort
{

 int arr[];
 void merge(int l,int m,int r)
 {
     int n1=m-l+1;
     int n2=r-m;
     int L[] = new int[n1];
     int R[] = new int[n2];
     for(int i=0;i<n1;i++)
        L[i] = arr[l+i];
     for(int j=0;j<n2;j++)
        R[j]=arr[m+1+j];

     int i=0,j=0;
     int k=l;
     while(i<n1 && j<n2)
     {
         if(L[i]<=R[j])
         {
             arr[k]=L[i];
             i++;
         }
         else
         {
             arr[k]=R[j];
             j++;
         }
         k++;
     }
     while(i<n1)
     {
         arr[k]=L[i];
         k++;
         i++;

     }
     while(j<n2)
     {
         arr[k]=R[j];
         k++;
         j++;
     }
 }

 void sort(int l, int r,int x)
 {

     if(l<r)
     {
         int m=(l+r)/2;
         System.out.print("LEFT PARTITION " + x + " - ");
         print(l,m);
         //System.out.print("\t\t\t");
                  sort(l,m,x+1);
                  System.out.print("RIGHT PARTITION " + x + " - ");
         print(m+1,r);

         sort(m+1,r,x+1);
         merge(l,m,r);
         System.out.println("MERGING PROCESS "+x+" - ");
         print(l,r);
     }
 }

 void print(int l,int r)
 {
    for(int i=l;i<=r;i++)
        System.out.print(arr[i] + " ");
    System.out.println();
 }

 public static void main(String arrg[])
 {
     System.out.println("ENTER NUMBERS 1. MANUALLY? 2. AUTOMATED? - ");
     Scanner sc=new Scanner(System.in);
     Random rd = new Random();
     int q=sc.nextInt();
     System.out.println("PLEASE ENTER THE NUMBER OF NODES - ");
     int n=sc.nextInt();
     Mergesort ms=new Mergesort();
     ms.arr=new int[n];
     switch(q)
     {
  case 1:
    for(int i=0;i<n;i++)
        ms.arr[i]=sc.nextInt();
    break;
  case 2 :
      for(int i=0;i<n;i++)
        ms.arr[i]=rd.nextInt()%500;
      break;

     }

     System.out.println("INPUT ARRAY - ");
     ms.print(0,ms.arr.length-1);
     ms.sort(0,ms.arr.length-1,1);
     System.out.println("SORTED ARRAY - ");
     ms.print(0,ms.arr.length-1);


 }
}
