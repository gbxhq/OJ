//选择排序
vector<int> selectSort(vector<int> vt){
    int n = vt.size();
    for(int i=0;i<n;i++){
        int minNo = i; //存本轮最小数的坐标
        int minVal = vt[i]; //存本轮最小的数
        for(int j=i+1;j<n;j++){
            if(vt[j]<minVal){
                minVal = vt[j];
                minNo = j;
            }
        }
        swap(vt[i],vt[minNo]);
    }
    return vt;
}