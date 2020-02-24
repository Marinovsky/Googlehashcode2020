#include <bits/stdc++.h>


using namespace std;

#define all(v) (v).begin(), (v).end()
ifstream cinn("input.txt");ofstream coutt("output.txt");

struct librarie{
    int N;
    int T;
    int M;
    vector<int> books;
    int quality;
    vector<int> scaned;
    int index;
} lib;


stack<librarie> Convert(librarie v[], int L){
    stack<librarie> v1;
    for(int i=0;i<L;i++){
        v1.push(v[i]);
    }
    return v1;

}

int score[1000005];


int main(){
    int B,L,D, temp;
    cinn>>B>>L>>D;
    int D1=D;
    librarie libraries[L];
    stack<librarie> priorty;
    vector<librarie> libs_used;
    map<int, int> hash;

    for(int i=0; i<B;i++){
        cinn>>temp;
        score[i]=temp;
        hash[i]=0;
    }
    for(int i=0; i<L;i++){
        cinn>>libraries[i].N>>libraries[i].T>>libraries[i].M;
        libraries[i].quality=(D1-libraries[i].T)*libraries[i].M;
        libraries[i].books=vector<int>(libraries[i].N);
        for(int j=0; j<libraries[i].N;j++){
            cinn>>libraries[i].books[j];

        }
        sort(all(libraries[i].books),[](const int &a, const int &b){
                return score[a]>score[b];
        });
        libraries[i].index=i;
    }

    sort(libraries, libraries+L,[](const librarie &a, const librarie &b){
                return a.T*b.N*b.M>b.T*a.N*a.M;
         });

    priorty=Convert(libraries, L);

    while(!priorty.empty()){
        lib=priorty.top();
        D1-=lib.T;
        if(D1<=0){
            break;
        }
        temp=D1*lib.M;
        if(temp>lib.books.size()){
            temp=lib.books.size();
        }
        for(int i=0;i<lib.books.size();i++){
            if(temp>0){
                if(hash[lib.books[i]]==0){
                    hash[lib.books[i]]++;
                    lib.scaned.push_back(lib.books[i]);
                    temp--;
                }
            }else{
                break;
            }
        }
        if(lib.scaned.size()!=0){
            libs_used.push_back(lib);
        }
        priorty.pop();

    }
    coutt<<libs_used.size()<<endl;

    for(int j=0; j<libs_used.size();j++){

        coutt<<libs_used[j].index<<" "<<libs_used[j].scaned.size()<<endl;
        for(auto c: libs_used[j].scaned){
            coutt<<c<<" ";
        }

        coutt<<"\n";
    }

    return 0;
}
