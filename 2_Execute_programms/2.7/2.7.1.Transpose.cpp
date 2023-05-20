int** transpose(const int* const* m, unsigned rows, unsigned cols)
{
    int ** n = new int*[cols];
    n[0] = new int[rows*cols];
    
    for(int i = 1;i != cols ;i++)
    {n[i]=n[i-1]+rows;}
    
  for(int k=0;k<cols;k++){
      for(int q=0;q<rows;q++){
          n[k][q] = m[q][k];
      }
  }
    return n;
} 