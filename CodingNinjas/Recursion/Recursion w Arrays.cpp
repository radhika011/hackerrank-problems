int sum(int input[], int n) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
    if(n==0) return 0;
    int remSum = sum(input+1,n-1);
    return remSum+input[0];
    
    

}




bool checkNumber(int input[], int size, int x) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
    if(size==0) return false;
    bool rem = checkNumber(input+1,size-1,x);
    return (input[0]==x)||rem;

}
