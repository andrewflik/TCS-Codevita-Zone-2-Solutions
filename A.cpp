#include<bits/stdc++.h>
#define ll long long
using namespace std;
double solve(double n){
	double s = 0;
	for(double x=n; x >=1; x--){
		s += 1/x;
	}
	return s;
}
int main(){
	ll n;
	cin >> n;
	ll ar[n];
	for(int i=0; i<n; i++)
		cin >> ar[i];
	cout << fixed << setprecision(6) << solve(n);
}
