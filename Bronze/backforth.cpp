#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){

ifstream fin("backforth.in");
ofstream fout("backforth.out");
vector <int> first;
vector <int> second;

for(int i = 0; i < 10; i++){
    int x;
    fin >> x;
    first.push_back(x);
}
for(int i = 0; i < 10; i++){
    int x;
    fin >> x;
    second.push_back(x);
}
vector <int> vals;
int a,b,c,d;
int t = 0;
//vector <int> first;
//vector <int> second;
// first.size()
/*   for(int u = 0; u < second.size(); u++){
                    cout << second.at(u) << endl;
                    }
                    for(int u = 0; u < first.size(); u++){
                    cout << first.at(u) << endl;
                    }*/
for(int i = 0; i < first.size(); i++){
    a = first.at(i);
    //cout << a << endl;
    second.push_back(a);
    if(i!=0){
    first.erase(first.begin()+(i));
    }
    else{
        first.erase(first.begin()+0);
    }
    for(int j = 0; j < second.size(); j++){
            b = second.at(j);
            first.push_back(b);
            if(j!=0){
            second.erase(second.begin()+(j));
            }
            else{
                second.erase(second.begin()+0);
            }

        for(int h = 0; h < first.size(); h++){
            c = first.at(h);
            second.push_back(c);
            if(h!=0){
            first.erase(first.begin()+(h));
            }
            else{
                first.erase(first.begin()+0);
            }
            for(int g = 0; g < second.size(); g++){
                d = second.at(g);
                t = 1000 - a + b - c + d;
                bool checker = true;
                for(int f = 0; f < vals.size(); f++){
                    if(vals.at(f)==t){
                        checker = false;
                    }
                }
                if(checker){
                    vals.push_back(t);
              //   cout << t << " " << a << " " << b << " " << c << " " << d << " " << endl;
               //   cout << i << " " << j << " " << h << " " << g << endl;
                }
                checker = true;
                /*
                first.clear();
                second.clear();
                for(int e = 0; e < 10; e++){
        first.push_back(origfirst.at(e));
      //  cout << origfirst.at(e) << " ";
        second.push_back(origsecond.at(e));
       // cout << origsecond.at(e) << endl;
                }
            }*/
        }
        if(h!=0){
         first.insert(first.begin()+(h),c);
        }
        else{
            first.insert(first.begin()+0, c);
        }
      //   second.erase(second.begin()+(second.size()-2));
      second.pop_back();
    //  cout << "reached 3" << endl;

    }
    if(j!=0){
          second.insert(second.begin()+(j),b);
        }
        else{
             second.insert(second.begin()+0,b);
        }
   // second.insert(second.begin()+(j),b);
   // first.erase(first.begin()+(first.size()-2));
   first.pop_back();
 //  cout << "reached 2" << endl;

}
 if(i!=0){
          first.insert(first.begin()+(i),a);
        }
        else{
             first.insert(first.begin()+0,a);
        }
   // first.insert(first.begin()+(i-1),a);
  //  second.erase(second.begin()+(second.size()-2));
    second.pop_back();
   // cout << "reached 1" << endl;
}

fout << vals.size() << endl;
/* 1 1 1 1 1 1 1 1 1 2
5 5 5 5 5 5 5 5 5 5 */


}
