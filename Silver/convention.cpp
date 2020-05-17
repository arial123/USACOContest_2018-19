#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,m,c;

bool canDo(int t, int prefixSum[]){

  int space = c;
  int index = 0;
  int currentMax = 0;

  int buses = 0;
  while(index <n){

    while(index < n && space > 0){
        if(space == c){
            currentMax = 0;
            index++;
            space--;
        }
        else{
            if((currentMax + prefixSum[index])>t){
                break;
            }
            else{
                currentMax = currentMax + prefixSum[index];
                index++;
                space--;
            }
        }


    }

    buses++;

    space = c;



}
if(buses > m){
        //cout << "false" << endl;
    return false;
}


return true;


}
int main(){

ifstream fin("convention.in");
ofstream fout("convention.out");
fin >> n;
fin >> m;
fin >> c;
int arrival[n];
for(int i = 0; i < n; i++){
    fin >> arrival[i];
}

sort(arrival, arrival+n);
if(n == (m*c)){
int maxi = INT_MIN;
int index = 0;
for(int i = 0; i < m; i++){
    int counter = 1;
    int first = arrival[index];

    int last = 0;
    while(counter < c && index<n){
        index++;
        counter++;

    }
    if(index == n){
        last = arrival[index-1];
    }
    else{
    last = arrival[index];
    }
    if((last-first)>maxi){
        maxi = last-first;
    }
    index++;


}
fout << maxi << endl;
return 0;
}
else{
int prefixSum[n];
for(int i = 0; i < n; i++){
    if(i==0){
        prefixSum[i] = 0;
    }
    else{
        prefixSum[i] = arrival[i]-arrival[i-1];
    }

  }



int upper = arrival[n-1]-arrival[0];
int lower = 0;
int result = 0;

while(lower < upper){
    int mid = (lower+upper)/2;

    if(upper-lower == 1){
        result = upper;
        break;
    }
    if(canDo(mid, prefixSum)){

        upper = mid;
    }
    else{

        lower = mid;
    }
}

fout << result << endl;
return 0;
}
}
