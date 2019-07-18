//给紫玉写的处理文件求值的

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>  //文件流库函数
#include <math.h>
#include <numeric>

#define N 5  //保留小数点后多少位在这里设置
#define URL "/Users/ixsim/Desktop/data.txt" //在这里改文件路径

using namespace std;

template <typename T>
void showVt(vector<T> vt){
    int n = vt.size();
    for(int i=0;i<n;i++)
        cout <<fixed<< setprecision(N) << vt[i] << "\t";
    cout<<"\n";
}

class Group{
public:
    vector<double > act;
    vector<double > one;
    vector<double > mla;
    vector<double > two;

    vector<double > avg;
    vector<double > delta;
//    vector<double > std;
    vector<double > dd;
    vector<double > rq;

    void setAvg();
    void setDelta();
//    void setStd();
    void setDd();
    void setRq();
};
Group A,B,C,D;
double getAvg(vector<double> vt){
    double sum = 0.0;
    int n=vt.size();
    for(double x:vt){
        sum += x;
    }
    return sum/n;
}

//double getStd(vector<double> vt){
//
//    double mean =  getAvg(vt); //均值
//
//    double accum  = 0.0;
//    std::for_each (std::begin(vt), std::end(vt), [&](const double d) {
//        accum  += (d-mean)*(d-mean);
//    });
//    return accum/vt.size();
//}

void Group::setAvg() {
    this->avg.push_back(getAvg(this->act));
    this->avg.push_back(getAvg(this->one));
    this->avg.push_back(getAvg(this->mla));
    this->avg.push_back(getAvg(this->two));
}

//void Group::setStd() {
//    this->std.push_back(getStd(this->act));
//    this->std.push_back(getStd(this->one));
//    this->std.push_back(getStd(this->mla));
//    this->std.push_back(getStd(this->two));
//}

void Group::setDelta() {
    this->delta.push_back(this->avg[1]-this->avg[0]);
    this->delta.push_back(this->avg[2]-this->avg[0]);
    this->delta.push_back(this->avg[3]-this->avg[0]);
}

void Group::setDd() {
    for(int j=0;j<3;j++) {
        this->dd.push_back(this->delta[j] - A.delta[j]);
    }
}

void Group::setRq() {
    for(int j=0;j<3;j++) {
        this->rq.push_back(1/(pow(2,this->dd[j])));
    }
}



int main() {
    ifstream infile;   //输入流
    ofstream outfile;   //输出流

    infile.open(URL, ios::in);

    if(!infile.is_open ())
        cout << "Open file failure" << endl;

    //读入数据
    vector<double > data;
    while (!infile.eof())            // 若未到文件结束一直循环
    {
        double x=0;
        infile >>x;
        data.push_back(x);
    }
    infile.close();   //48个数读完了，关闭文件

    cout << "|A\t\t\t\t\t\t|B\t\t\t\t\t\t|C\t\t\t\t\t\t|D\n|";
    for(int i=0,m=1;i<48;i++){
        cout << fixed << setprecision(N)<< data[i] << "\t";

        if(m%2==0)
            cout <<"|";
        if(i==23)
            cout << "\n|--------";
        if(m==8){
            cout <<"\n|";
            m=0;
        }
        m++;
    }

    for(int i=0,j=0;i<3;i++){
        A.act.push_back(data[j++]); A.one.push_back(data[j++]);
        B.act.push_back(data[j++]); B.one.push_back(data[j++]);
        C.act.push_back(data[j++]); C.one.push_back(data[j++]);
        D.act.push_back(data[j++]); D.one.push_back(data[j++]);
    }

    for(int i=0,j=24;i<3;i++){
        A.mla.push_back(data[j++]); A.two.push_back(data[j++]);
        B.mla.push_back(data[j++]); B.two.push_back(data[j++]);
        C.mla.push_back(data[j++]); C.two.push_back(data[j++]);
        D.mla.push_back(data[j++]); D.two.push_back(data[j++]);
    }


    //计算ABCD的Delta
    A.setAvg();
    B.setAvg();
    C.setAvg();
    D.setAvg();
//    A.setStd();
//    B.setStd();
//    C.setStd();
//    D.setStd();
    A.setDelta();
    B.setDelta();
    C.setDelta();
    D.setDelta();


    //求最后9个dd
    A.setDd();
    B.setDd();
    C.setDd();
    D.setDd();
    //求最后9个rq
    A.setRq();
    B.setRq();
    C.setRq();
    D.setRq();

    cout<<"delDelta(B-A):\n";
    showVt(B.dd);
    cout<<"rq:\n";
    showVt(B.rq);cout<<"\n";

    cout<<"delDelta(C-A):\n";
    showVt(C.dd);
    cout<<"rq:\n";
    showVt(C.rq);cout<<"\n";

    cout<<"delDelta(D-A):\n";
    showVt(D.dd);
    cout<<"rq:\n";
    showVt(D.rq);

}