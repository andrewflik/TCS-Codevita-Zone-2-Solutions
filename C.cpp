/*
********************

*....c.............*

*...c..............*

*c.................*

*.............a....*

*c.c...............*

*.a................*

*...........c......*

********************
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int hits = 0, totalPeople = 0, infectedPeople = 0;
char city[9][21];
pair<int, int> graph[9][21];
vector<pair<int, int>> visited;
bool checkBound(int x, int y){
	if((x <= 8 and y <= 20) and (x >= 0 and y >= 0))
		return true;
	return false;
}
void solve(int x, int y, int px, int py){
	if(hits >= 2)
		return;
	visited.push_back(graph[x][y]);
	if(city[x][y] == '*'){
		hits++;
		// Try n ReEnter
		if(checkBound(x+1, y-1) and (px!=x+1 or py!=y-1))
			solve(x+1, y-1, x, y);
		else if(checkBound(x+1, y+1) and (px!=x+1 or py!=y+1))
			solve(x+1, y+1, x, y);
		else if(checkBound(x-1, y+1) and (px!=x-1 or py!=y+1))
			solve(x-1, y+1, x, y);	//ds
		else
			solve(x-1, y-1, x, y);
	}
	if(city[x][y] == 'a'){	// Anti
		infectedPeople++;
		city[x][y] = '-';
		if(px < x and py > y)	// I
			solve(x+1, y+1, x, y);
		else if(px < x and py < y)	// II
			solve(x-1, y+1, x, y);
		else if(px > x and py < y)
			solve(x-1, y-1, x, y);
		else						// IV
			solve(x+1, y-1, x, y);
	}
	else if(city[x][y] == 'c'){	// Clock
		infectedPeople++;
		city[x][y] = '-';
		if(px < x and py > y)	// I
			solve(x-1, y-1, x, y);
		else if(px < x and py < y)	// II
			solve(x+1, y-1, x, y);
		else if(px > x and py < y)
			solve(x+1, y+1, x, y);
		else						// IV
			solve(x-1, y+1, x, y);
	}
	else{
		// Follow the last line
		if(px+1 == x and py+1 == y)
			solve(x+1, y+1, px+1, py+1);
		else if(px-1 == x and py+1 == y)
			solve(x-1, y+1, px-1, py+1);
		else if(px-1 == x and py-1 == y)
			solve(x-1, y-1, px-1, py-1);
		else
			solve(x+1, y-1, px+1, py-1);
	}
}
int main(){
	// Init Graph
	int r = 8, c = 0;
	for(int i=0; i<9; i++, r--){
		c = 0;
		for(int j=0; j<20; j++, c++)
			graph[i][j] = {r, c}; 
	}
//	for(int i=0; i<9; i++, r--){
//		for(int j=0; j<21; j++, c++)
//			cout << "("<< graph[i][j].first << "," << graph[i][j].second << ")" << " " ; 
//		cout << endl;
//	}

	// INPUT MATRIX

	for(int i=0; i<9; i++){
		for(int j=0; j<20; j++){
			cin >> city[i][j];
			if(city[i][j] == 'a' or city[i][j] == 'c')
				totalPeople++;
		}
	}
	/*
	for(int i=0; i<8; i++){
		for(int j=0; j<20; j++){
			cout << "("<< i << "," << j << ") "<<city[i][j] << " ";
			//cout << city[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	*/

	// Traverse the VIRUS Trajectory
	solve(7, 1, 8, 0);	// Give it a starting POINT
	cout << 0 << " " << 0 << endl;
	for(pair<int, int> x: visited)
		cout << x.second << " " << x.first << endl;
		for(int i=0; i<9; i++){
		for(int j=0; j<20; j++){
			cout << city[i][j];
		}
		cout << endl;
	}
	cout << "safe=" << totalPeople - infectedPeople << endl;
	cout << "infected=" << infectedPeople;
}
