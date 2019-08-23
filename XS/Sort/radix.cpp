//基数排序
void radix(vector<int> vt,int exp){ //得传一个最高位数进来
//   先按个位存到map
    map<int,vector<int> > m1;
    for(int i=0;i<vt.size();i++){
        m1[vt[i]%10].push_back(i);
    }
    //根据exp的位数，建一个map组。
    vector<map<int,vector<int> > > allMap;
    allMap.push_back(m1);

    for(int p=1;p<exp;p++) {
        map<int, vector<int> > tmpM;
        //遍历上一个map，存到这个map里
        for(auto it=allMap[p-1].begin();it!=allMap[p-1].end();it++){
            //取出这个数  ➗10的p次方，再取余， 并作为新map的key。vule则是it->second
            for(auto it2=it->second.begin();it2!=it->second.end();it2++){
                int x = vt[*it2];
                x = x/(pow(10,p));
                x = x%10;
                tmpM[x].push_back(*it2);
            }
        }
        allMap.push_back(tmpM);
    }

    //遍历输出（正确结果存在最后一个map里 it1就指向这个map
    for(auto it1=allMap[exp-1].begin();it1!=allMap[exp-1].end();it1++)
        //map里的value是个vector（存了对应的下标） it2就是遍历这个vector用的
        for(auto it2=it1->second.begin();it2!=it1->second.end();it2++)
            cout<<vt[*it2]<<" ";

}
