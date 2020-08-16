#include<bits/stdc++.h>
using namespace std;

string nameForNumber(int num) {
  if (num > 100)
     return "greater 100";
  if(num == 0)
    return "zero";
  if (num == 100) 
    return "hundred";

  const string kSpecialCases[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
  if (10 <= num && num <= 19) {
    return kSpecialCases[num - 10];
  }

  const string kOnesPlaces[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
  const string kTensPlaces[] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
  if (num < 10) {
    return kOnesPlaces[num - 1];
  } else if (num % 10 == 0) {
    return kTensPlaces[num / 10 - 2];
  } else {
    return kTensPlaces[num / 10 - 2] + " " + kOnesPlaces[num % 10 - 1];
  }
}

int find(string s){
    int cv = 0;
    for(unsigned int i=0; i<s.length(); i++){
        if(s[i] == ' ')
            continue;
        if(s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u')
            cv++;
    }
    return cv;
}
bool check(vector<pair<int, int>> &v, pair<int, int> p){
    for(auto it = v.begin(); it!=v.end(); it++){ 
        if(it->first == p.first && it->second == p.second) 
            return true; 
    } 
    return false;
}
int totalPairs(int ar[], int n, int k){
    int count = 0;

    vector<pair<int, int>> v;

    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++){ 
            if(ar[i]+ar[j] == k ) 
                count++; 
        }
    }
    return count;
}

int main()
{
    //for(int i=0; i<=110; i++)
      //  cout << nameForNumber(i) << endl;
    int n;
    cin >> n;
    int ar[n], cVowels = 0;
    for(int i=0; i<n; i++){
        cin >> ar[i];
        cVowels += find(nameForNumber(ar[i]));
    }
    //cout << cVowels << endl;
    int ans = totalPairs(ar, n, cVowels);
    if(ans > 100)
        cout << "greater 100";
    else
        cout << nameForNumber(ans);
}
