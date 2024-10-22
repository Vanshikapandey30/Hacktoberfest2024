def print_diagonals(matrix, r, c, k): #r is the number of rows, c is the number of columns, k is the centre element of diagonal to print
  row = 0   #Sets the row of centre element of the diagonal to be printed equal to 0.
  column = 0    #Sets the column of centre element of the diagonal to be printed equal to 0.
  
  #Finding the row and column of element equal to k
  for i in range(r):    #Access the rows of the matrix
    for j in range(c):  #Access the columns of the matrix
      if matrix[i][j] == k: #Find the element equal to k
        row = i  #Store the row of element equal to k
        column = j #Store the column of element equal to k
        break   #Breaks the loop as soon as it finds the row and cloumn of element equal to k
  i, j = row, column #Sets the row and column of element equal to k equal to i and j respectively.
  
  # Main Diagonal & Anti-Diagonal
  while i > 0 and j > 0:
    i -= 1
    j -= 1
  while i < r and j < c:
    print(matrix[i][j], end = ' ')
    i += 1
    j += 1
  print()
  i, j = row, column
  while i > 0 and j < c-1:
    i -= 1
    j += 1
  while i <= r - 1 and j >= 0:
    print(matrix[i][j], end = ' ')
    i += 1
    j -= 1
    
# Sample Input
row = 3
column = 3
matrix = [[1, 2, 3],
          [4, 5, 6],
          [7, 8, 9]]
K = 7
# Usage
print_diagonals(matrix, row, column, K)