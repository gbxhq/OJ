//虽然AC。我代码太烂。千万不要参考！去看题解。
//#include <iostream>
//
//using namespace std;
//int n;
//string s[100];
//int check[100][100];
//
//string target="yizhong";
//
//void confirm(int i,int j,int dirction){
//    string a;
//    int x=i,y=j,l=0;
//    switch (dirction){
//        case 0://上
//            for (;i>=0;i--) {
//                a+=s[i][j];
//                if(a.size()==7&&a==target){
//                    for (;x>=0;x--) {
//                        check[x][y]=1;
//                        l++;
//                        if(l==7)
//                            break;
//                    }
//                    break;
//                }
//            }
//            break;
//        case 1://下
//            for (;i<n;i++) {
//                a+=s[i][j];
//                if(a.size()==7&&a==target){
//                    for (;x<n;x++) {
//                        check[x][y]=1;
//                        l++;
//                        if(l==7)
//                            break;
//                    }
//                    break;
//                }
//            }
//            break;
//        case 2://左
//            for (;j<n;j++) {
//                a+=s[i][j];
//                if(a.size()==7&&a==target){
//                    for (;y<n;y++) {
//                        check[x][y]=1;
//                        l++;
//                        if(l==7)
//                            break;
//                    }
//                    break;
//                }
//            }
//            break;
//        case 3://右
//            for (;j>=0;j--) {
//                a+=s[i][j];
//                if(a.size()==7&&a==target){
//                    for (;y>=0;y--) {
//                        check[x][y]=1;
//                        l++;
//                        if(l==7)
//                            break;
//                    }
//                    break;
//                }
//            }
//
//            break;
//        case 4://左上
//            for (;i>=0&&j>=0;i--,j--) {
//                a+=s[i][j];
//                if(a.size()==7&&a==target){
//                    for (;x>=0&&y>=0;x--,y--) {
//                        check[x][y]=1;
//                        l++;
//                        if(l==7)
//                            break;
//                    }
//                    break;
//                }
//            }
//            break;
//        case 5://左下
//            for (;i<n&&j>=0;i++,j--) {
//                a+=s[i][j];
//                if(a.size()==7&&a==target){
//                    for (;x<n&&y>=0;x++,y--) {
//                        check[x][y]=1;
//                        l++;
//                        if(l==7)
//                            break;
//                    }
//                    break;
//                }
//            }
//            break;
//        case 6://右上
//            for (;i>=0&&j<n;i--,j++) {
//                a+=s[i][j];
//                if(a.size()==7&&a==target){
//                    for (;x>=0&&y<n;x--,y++) {
//                        check[x][y]=1;
//                        l++;
//                        if(l==7)
//                            break;
//                    }
//                    break;
//                }
//            }
//            break;
//        case 7://右下
//            for (;i<n&&j<n;i++,j++) {
//                a+=s[i][j];
//                if(a.size()==7&&a==target){
//                    for (;x<n&&y<n;x++,y++) {
//                        check[x][y]=1;
//                        l++;
//                        if(l==7)
//                            break;
//                    }
//                    break;
//                }
//            }
//            break;
//    }
//}
//
//int main(){
//    cin>>n;
//    for (int i = 0; i < n; ++i) {
//        cin>>s[i];
//    }
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j) {
//            if(s[i][j]=='y')
//                for (int k = 0; k < 8; ++k) {
//                    confirm(i,j,k);
//                }
//        }
//    }
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j) {
//            if(check[i][j])
//                cout<<s[i][j];
//            else
//                cout<<'*';
//        }
//        cout<<"\n";
//    }
//    return 0;
//}