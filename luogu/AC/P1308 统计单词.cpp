#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main(){

    string target,article;
    getline(cin,target);
    getline(cin,article);

    transform(target.begin(),target.end(),target.begin(),::tolower);
    transform(article.begin(),article.end(),article.begin(),::tolower);

    int cnt = 0, first = 0;

    istringstream is(article);
    string word;
//    int i=0;
    while (is >> word){
        if(word == target){
            cnt++;
        }
//        i += word.size() + 1;
    }
    target = " "+target+" ";
    article = " "+article+" ";

    if(cnt){
        cout << cnt <<" "<< article.find(target);
    } else{
        cout << -1;
    }
    return 0;
}