#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Cow {
  int seniority;
  int arrival;
  int time;
  bool finished;
    int index;
    bool added;
  bool operator <(const Cow &other) const {
    return (this->seniority < other.seniority);
  }
};

/*struct CowCompare
{
   // int seniority1 =
bool operator <(const Cow &other) const {
    int seniority1 = this->seniority;
    int seniority2 = other.seniority;
    return (seniority1 < seniority2);
  }
};*/


    bool bySeniority(const Cow &first, const Cow &second) {
  return (first.seniority < second.seniority);
}

// return true if first < second
// return false otherwise


// return true if first < second
// return false otherwise
bool byArrival(const Cow &first, const Cow &second) {
  return (first.arrival < second.arrival);
//    || (first.arrival == second.arrival && first.seniority < second.seniority);
}


int main() {
 ifstream fin("convention2.in");
 ofstream fout("convention2.out");
  int n;
  fin >> n;
  Cow cows[n];
  for(int i = 0; i < n; i++){
    fin >> cows[i].arrival;
    fin >> cows[i].time;
    cows[i].seniority = n - i;
    cows[i].finished = false;
  }
  sort(cows, cows + n, byArrival); // quicksort or introsort O(N*log(N))


  for(int i = 0; i < n; i++){
   // cout << cows[i].seniority << " " << cows[i].arrival << " " << cows[i].time <<endl;
    cows[i].index = i;
    cows[i].added = false;
  }

//  && !cows[x].added
  int counter = 0;
  int nextcow = 0;
  int result = 0;
  int endtime = cows[0].arrival;
  int totalcow = n;
  priority_queue <Cow> pq;
  int highestS = -1;
  int highestI = 0;
  for (int i = 0; i < n; i++) {
        cows[nextcow].finished = true;
    endtime = endtime + cows[nextcow].time;
   // cout << "i= " << i << endl;
//cout << endtime << " " << nextcow << endl;
    int x = nextcow;
     //  cout << "next cow = " << nextcow << endl;
    x++;
   // cout << x << " " << endtime << " " << start[x] << endl;
   // cout << finished[4] << endl;
  // cout << start[4] << endl;

    while(x<totalcow && endtime>=cows[x].arrival){
        // putting the waiting cows into the vector
     //   cout << "hello" << endl;
        if(!cows[x].finished && !cows[x].added){
  //    cout << "added to q: " <<  x << endl;
        pq.push(cows[x]);
        cows[x].added = true;
        if(cows[x].seniority > highestS){
            highestS = cows[x].seniority;
            highestI = x;
        }
        //cout << x << endl;

       }
       x++;

    }
    nextcow = x;
    if(!pq.empty()){
  //  cout << "top arrival time: " << pq.top().arrival << endl;
   cows[pq.top().index].finished = true;
  // cout << cows[highestI].finished << endl;
    int wait = endtime - pq.top().arrival;
    nextcow = pq.top().index;
   //Cow a = pq.top();
   // pq.pop();
  //  a.finished = true;

   // pq.push(a);
  //  cout << "top arrival time: " << pq.top().finished << endl;
   // pq.top().finished = true;
    pq.pop();
   // cout << wait << endl;
    if(wait > result){
        result = wait;
    }
  /*  cout << "vector: " << endl;
    for(int j=0; j <vect.size(); j++){
        cout << vect.at(j) << " ";
    }
    cout << endl;
*//*
while(cows[highestI].finished){
        cout << highestI << endl;
    highestI++;
}
*/
//nextcow = highestI;
    }
    else{
     //  cout << cows[nextcow].finished << " index: " << nextcow << endl;
        while(cows[nextcow].finished){
      //          cout << "finished: " << nextcow << endl;
        nextcow++;
        }
        endtime = cows[nextcow].arrival;

    }
    //cout << nextcow << endl;
  }
  fout << result << endl;
  return 0;
}
