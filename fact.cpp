lli fact(lli n, lli r){
    if(r<0)
        return 0;
    else if(r==0)
        return 1;
    else if(r==1)
        return n%p;
    else{
        lli arr[r];
        arr[0]=n;
        for(int i=1;i<r;i++)
            arr[i]=arr[i-1]-1;
        for(int i=r;i>=2;i--){
            for(int j=0;j<r;j++){
                if(arr[j]%i==0){
                    arr[j]=arr[j]/i;
                    break;
                }
            }
        }
        lli a=1;
        for(int i=0;i<r;i++){
            a=((a%p)*(arr[i]%p))%p;
        }
        return a%p;
    }
}
