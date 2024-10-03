package Hacktoberfest2024.arrays;


public class kadanesAlgo {
    public static void main(String[] args) {
        int num[] = {-1,2,-6,-1,-3};
        maxSum(num);
    }
    public static void maxSum(int num[]) {
        int maxSum = Integer.MIN_VALUE;
        int currSum = 0;
        int largest = Integer.MIN_VALUE;
        
        if (negaArry(num)==0) {
            for (int i = 0; i < num.length; i++) {
                if (num[i]>largest) {
                    largest = num[i];
                }
            }
            System.out.println("Max sum is " + largest);
        }else{
            for (int i = 0; i < num.length; i++) {
                currSum += num[i];
                if (currSum < 0) {
                    currSum = 0;
                }
                maxSum = Math.max(currSum,maxSum);
            }
            System.out.println("Max sum is " + maxSum);
        }
    }
    
    public static int negaArry(int num []) {
            int neg = 0;
            for (int i = 0; i < num.length; i++) {
                if (num[i]>0) {
                    neg = -1;
                
                }
            }
            return neg;
    }
    }

