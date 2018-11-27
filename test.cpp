

int kthSmallest(int arr[], int l, int r, int k) {

    if(k >= 0 && k<- r-l +1 ) {
        int n = r - l + 1; 
        int i, median[(r-l+4)/5];  

        for(i=0;i<n/5;i++) {
            median[i] = FindMedian(arr + l + 5*i , 5); 
        } 

        if(5*i < n) {
            median[i] = FindMedian(arr + l + 5*i, n%5); 
            i++ 
        }

        int medOfMed;
        if ( i == 1) medOfMed = median[i-1]; 
        else medOfMed = kthSmallest(median, 0 , i - 1 , i / 2  ); 

        int pos = Partition(arr, l , r , medOfMed);
        if(pos - l  ==  k - 1  ) return arr[pos]; // mistake pos - l = k -1 why???  pos에서 -

        if(pos- l < k-1 ) kthSmallest(arr, pos + 1 + l , r , k -(pos - l) -1); //l을 계속 더해주는지 아닌지에 대한 생각을  
        else kthSmallest(arr, l ,pos -1 , k ) // 

    }
    //역시 rendomized sleection에서도 다르네 . 

}


void quickSortIterative (int arr[], int l, int h) 
     
     int stack[h-l+1];
     int top = -1; 
     
     stack[++top] = l;
     stack[++top] = h;
     
     while(top>=0 ) {
         h = stack[top--];
         l = stack [top--];

         int p = Partition(arr, l, h);

         if( p-1 > l ) 
     }

}