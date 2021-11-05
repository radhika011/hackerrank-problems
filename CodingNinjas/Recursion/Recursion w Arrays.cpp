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


int firstIndex(int input[], int size, int x) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
    if(size==0) return -1;
    if(input[0]==x) return 0;
    int next = firstIndex(input+1,size-1,x);
    if(next==-1) return -1;
    return 1+next;
    
}
//Simply interchanging positions of rec call and small calc
int lastIndex(int input[], int size, int x) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
    
    if(size<=0) return -1;
    int next = lastIndex(input+1,size-1,x);
     if(next==-1&&input[0]==x){
        return 0;
    }
    if(next==-1) return -1;
 	return 1+next; 
  
    

}

int allIndexes(int input[], int size, int x, int output[]) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Save all the indexes in the output array passed and return the size of output array.
     Taking input and printing output is handled automatically.
  */
	if(size==0) return -1;
    int rem = allIndexes(input+1,size-1,x,output);
    if(rem!=-1&&input[0]==x){
        for(int i = 0;i<rem;i++){
            output[i]+=1;
        }
        for(int i = rem-1;i>=0;i--){
            output[i+1] = output[i];
        }
        output[0] = 0;
        return 1+rem;
    }
    if(input[0]==x){
        output[0]= 0;
        return 1;
    }
    for(int i = 0;i<rem;i++){
            output[i]+=1;
    }
    return rem;
}





