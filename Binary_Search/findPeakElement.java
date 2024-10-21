import java.util.Scanner;

class findPeakElement {

    public static int findPeakElement(int[] nums) {
        if(nums.length == 1){
            return 0;
        }

        int i = 0;
        int j = nums.length-1;

        while(i<=j){
            int mid = (i+j)/2;

            if(mid == 0){
                if(nums[mid] > nums[mid+1]){
                    return mid;
                }else{
                    i = mid+1;
                }
            }else if(mid == nums.length-1){
                if(nums[mid] > nums[mid-1]){
                    return mid;
                }else{
                    j = mid-1;
                }
            }else if(nums[mid] > nums[mid-1]){
                if(nums[mid] > nums[mid+1]){
                    return mid;
                }else{
                    i = mid+1;
                }
            }else{
                j = mid-1;
            }
        }

        return -1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        int result = findPeakElement(arr);

        System.out.println(result);
        
    }
}