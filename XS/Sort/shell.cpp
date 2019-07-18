//希尔排序
void shellInsert(vector<int> &vt, int k){
    int n = vt.size();
    for(int i=k;i<n;i++){
        int x = vt[i];
        int j;
        for(j=i-k;j>=0&&vt[j]>x;j-=k){
            vt[j+k]=vt[j]; //后移
        }
        vt[j+k]=x;
    }
}
vector<int> shellSort(vector<int> vt){
    int delta[3] = {5,3,1};
    for(int i=0;i<3;i++)
        shellInsert(vt,delta[i]);
    return vt;
}