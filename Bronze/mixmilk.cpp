#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){

ifstream fin("mixmilk.in");
ofstream fout("mixmilk.out");
int firstC, first;
int secondC, second;
int thirdC, third;
fin >> firstC;
fin >> first;
fin >> secondC;
fin >> second;
fin >> thirdC ;
fin >> third;


for(int i = 0; i < 33; i++){
    if((first+second)<= secondC){
        second = second + first;
        first = 0;
    }
    else{
        first = (first+second)-secondC;
        second = secondC;

    }
    if((second+third)<= thirdC){
        third = second + third;
        second = 0;
    }
    else{
        second = (third+second)-thirdC;
        third = thirdC;

    }
    if((first+third)<= firstC){
        first = third + first;
        third = 0;
    }
    else{
        third = (first+third)-firstC;
        first = firstC;

    }
}

if((first+second)<= secondC){
        second = second + first;
        first = 0;
    }
    else{
        first = (first+second)-secondC;
        second = secondC;

    }

fout << first << endl;
fout << second << endl;
fout << third << endl;








}
