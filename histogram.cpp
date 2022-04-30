//histogram part works
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main(){
  ifstream in_stream;
  char fn[50];
  cout<<"Enter a filename"<<endl;
  cin>>fn;
  in_stream.open(fn);
  if(in_stream.fail()){
      cout<< "Input file opening failed.  \n";
      exit(1);
  }


//pair<int, vector<string> >(3, "Emily", "Jason", "woie");
//map<int, pair<int, vector<string> > (4, (3, "Emily", "Jason", "woie"));  //3 is number of strings in vector. 4 is the score

map<int, pair<int, vector<string> > > m;  //# represent what score each person got
//pair<int, vector<string> >(w.first, w.second);  //first represents int (# of ppl who have that score), second represents vector of strings (names of ppl w that score)
int score=0;  //create a score variable
string name;
while(in_stream>>(score)){
  getline(in_stream,name);
  //m[score]; //m[4] means 4 is the score. this is a pair of int vector strings
  //m[score].second; //use this to get vector of strings
  m[score].second.push_back(name);  //inside brackets is the first item in the pair. m[score] = w.second
  m[score].first++;
}

for(auto w:m){  //auto loop print
    cout<<w.first<<" "<<"occurs"<<" "<<(w.second.first)<<" "<<"times"<<endl;  //prints out score (1st) and name of ppl (2nd) who have score, like 6 (score) and anna (name). w.second is a pair
}   //score, # of people who got that score

cout<<endl;
/*
for(auto w:m){
  cout<<w.first;
for(int i=0;i<w.first;i++){  //auto loop print
        cout<<"x";  //prints out score (1st) and name of ppl (2nd) who have score, like 6 (score) and anna (name). w.second is a pair
}
}
*/

for(int i=1;i<=10;i++){  //HISTOGRAM PRINTING OUT X
  cout<<i;
  for(int j=0;j<m[i].first;j++){
    cout<<"x";  // "x"
}
cout<<endl;
}

cout<<endl;
/*
for(int i=1;i<=10;i++){
  if(w.first==i){  //if the score equals i
  cout<<"x";
}
} */
//asks if you want to see who got a given score
string yesNo;  //NEED HELP ON THIS PART!!!!!!!
cout<<"Do you want to see who got a given score? (type yes or no)"<<endl;
cin>>yesNo;
if(yesNo=="yes"){
cout<<"Give a score: "<<endl;
cin>>score;
for(int i=0;i<m[score].first;i++){  //first represents # of ppl who have that score
cout<<m[score].second[i]<<endl; //pair of int vector strings
}
}

/*
for(int i=1; i<=10; i++) {
  for(string name: m[i].second) {
    cout << name << " ";
  }
  cout << endl;
}
*/
/*
m[0] = map<pair<int, vector<string>> //the score 0. pair of int,vector<string>. the type is m.
    pair<int, vector<string> //the second int is the number of people who got that score (let's say 3 people got that score), the vector<string> is the names of people who got that score

*/

}

//midterm-up to inheritance? up to and including homework 5

//2nd quiz - stuff after the midterm and up to the stuff in the homework due today 11/11, mainly templates and containers
