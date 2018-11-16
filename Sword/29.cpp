//解法一
void partion(vector<int> &vt,int i,int j,int k) {
    int ii=i,jj=j;//backup
    int x = vt[i];
    if(i>j)
        return;
    while (i<j){
        while (vt[j]>x&&i<j){
            j--;
        }
        if(i<j){
            vt[i] = vt[j];
            i++;
        }
        while (vt[i]<x&&i<j){
            i++;
        }
        if(i<j){
            vt[j] = vt[i];
            j--;
        }
    }
    vt[i] = x;
    if(i<k-1){
        partion(vt,i+1,jj,k-i-1);
    }
    if(i>k-1){
        partion(vt,ii,i-1, k);
    }
}

int func(vector<int> vt){
    int n = vt.size();
    if(n==0)
        return 0;
    if(n==1)
        return vt[0];
    int k = n/2;
    partion(vt,0,n-1,k);
    int nok=vt[k-1];
    int num = 0;
    for(auto x:vt){
        if(x==nok)
            num++;
    }
    if(num>=n/2)
        return nok;
    else
        return 0;
}
//还有摩尔投票法。我就不写了比较简单。