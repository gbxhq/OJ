//# 归并
void Merge(vector<int> &vt,int i1,int j1,int i2,int j2){
    vector<int >tmp;
    int i=i1;
    while (i1<=j1&&i2<=j2){
        if(vt[i1]<=vt[i2]){
            tmp.push_back(vt[i1]);
            i1++;
        } else{
            tmp.push_back(vt[i2]);
            i2++;
        }
    }
    while (i1<=j1){
        tmp.push_back(vt[i1]);
        i1++;
    }
    while (i2<=j2){
        tmp.push_back(vt[i2]);
        i2++;
    }
//    showVt(tmp);
//    copy(tmp.begin(),tmp.end(),vt.begin()+i1-1);  怎么用copy方法赋值呢。肯定是vt.begin这里定位不对
    for(auto x:tmp){  //改用了遍历赋值的方法。
        vt[i++]=x;
    }
    showVt(vt);
}
void mergeSort(vector<int> &vt,int i,int j){
    if(i<j){
        int mid= (i+j)/2;
        mergeSort(vt,i,mid);
        mergeSort(vt,mid+1,j);
        if(i<=mid&&mid+1<=j)
            Merge(vt,i,mid,mid+1,j);
    }
}
