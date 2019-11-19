// Example program
#include <iostream>
#include <string>
#include <map>
#include <iterator>
using namespace std;

void dup(string&);

int main()
{
   // map<char, int>::iterator it;
 // map<char, int> lib;
 // lib.insert(pair<char,int>('c', 1) );
//  lib.insert(pair<char,int>('d', 3) );
//  it = lib.find('d');
  
 // cout << it->second << endl;
 // (it->second)++;
 // cout << it->second;
 
 string x;
cout << "Enter the string you wish to test for DUPLICATES: ";
cin >> x;
 dup(x);
  
}

void dup(string &in){
 
 if(in.length() < 1) return;
 
     //this will store everything we have passed
 map<char, int> index;
 map<char, int>::iterator it;
 
 //outer loop will provide characters to test
 for(int i = 0; i < in.length(); i++){
  
    it = index.find(in[i]);
    
    if((it->first) == in[i]){
    
      //if char is found in index, inc the count
      (it->second)++;
    
    } else{
    
      //otherwise add the char to the index
      index.insert(pair<char, int>(in[i], 1));
    
    }
   
 }
 
 //output
 it = index.begin();
 for(int i = 0; i < index.size(); i++){
     
     if((it->second) > 1) cout << it->first << " was duplicated " << it->second << " times." << endl;
     it++;
     
 }
    
}
