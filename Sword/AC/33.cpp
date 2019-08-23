//输入一个正整数数组，把数组里所有数字拼接起来排成一个数，
// 打印能拼接出的所有数字中最小的一个。
// 例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//int getSmall(vector<string> vt, int i, int j){//返回更小的string的下标
//    string a = vt[i],b = vt[j];
//    //用最后一位补齐
//    int longestLen = a.length()>b.length()? a.length():b.length();
//    a += string(longestLen-a.length(),a[a.length()-1]);
//
//    b += string(longestLen-b.length(),b[b.length()-1]);
//
//    return a<b? i:j;
//}//看了书，发现根本不用补齐。两个串拼接一下就好了。

int getSmall(vector<string> vt, int i, int j){
    string a = vt[i]+vt[j];
    string b = vt[j]+vt[i];
    return a<b?i:j;
}//书上的比较字符串的方法。

string PrintMinNumber(vector<int> numbers) {
    vector<string> vt; //int To string ,save in vector
    int longestLen = 0;
    for (int i = 0; i < numbers.size(); ++i) {//int转string春如vector
        string tmp = to_string(numbers[i]);
        if(tmp.length()>longestLen)
            longestLen = tmp.length();
        vt.push_back(tmp);
    }

//    for(int i=0;i<vt.size();i++){//行不通的方法：遍历所有的数，用char:'9'+1 补齐他们到一样长
//        int len = vt[i].length();
//        if(len<longestLen)
//            vt[i] += string(longestLen-len,'9'+1);
//    }

    string ans;
    while (!vt.empty()){
        int bestNo = 0;
        for(int i=1;i<vt.size();i++){
            bestNo = getSmall(vt,bestNo,i);
        }
        string bestStr = vt[bestNo];
        vt.erase(vt.begin()+bestNo);
        ans += bestStr;
    }
//    auto it = find(ans.begin(),ans.end(),'9'+1); //删除补齐符号
//    while (it!=ans.end()){
//        ans.erase(it);
//        it = find(ans.begin(),ans.end(),'9'+1);
//    }
    return ans;
}

int main(){
    vector<int> input{3,32,321};
    cout << PrintMinNumber(input);

    return 0;

}