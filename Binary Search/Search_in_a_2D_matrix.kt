class Solution {
    fun searchMatrix(matrix: Array<IntArray>, target: Int): Boolean 
    {
        var row=0
        var low=0
        var mid=0
        var high=matrix[0].size-1
        
        while(row<matrix.size){
            
            mid=(high-low)/2+low
            
            if(matrix[row][mid]==target){
                return true
            }
            else if(matrix[row][mid]<target){
                low=mid+1
            }
            else{
                high=mid-1
            }
            
            if(high<low){
                row++
                low=0
                high=matrix[0].size-1
            }
            
        }
        return false
    }
}