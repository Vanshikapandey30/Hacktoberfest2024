public class MirrorTriangle {

        public static void main(String[] args) {
            int n = 5;
            for(int row = 1; row < 2*n; row++){
                  // no of spaces
                  int ColSpaces = row > n ? 2*n - row - 1:row - 1;
                  for(int s = 1; s <= ColSpaces; s++){
                      System.out.print(" ");
                  }
                //printing *
                int ColPattern = row > n ? row -n+1:n - row + 1;
                for(int c = 1; c <= ColPattern; c++){
                    System.out.print("* ");
                }
              
                System.out.println();
            }
           
      
            
        }
        
    
}
