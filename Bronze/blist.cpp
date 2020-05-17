#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int timings[1000];
int main(){

ifstream fin("blist.in");
ofstream fout("blist.out");
int n;
fin >> n;
int start[n];
int ending[n];
int buckets[n];
for(int i = 0; i <n; i++){
    fin >> start[i];
    fin >> ending[i];
    fin >> buckets[i];
}



for(int i = 0; i <n; i++){
    timings[start[i]] = buckets[i];
  //  cout << timings[start[i]] << endl;
    timings[ending[i]] = (-1*buckets[i]);
    //cout << timings[ending[i]] << endl;
}

int maxi = INT_MIN;
int total = 0;
for(int i = 0; i < 1000; i++){
    total = total + timings[i];
    if(total > maxi){
        maxi = total;
    }
}


fout << maxi << endl;






}
