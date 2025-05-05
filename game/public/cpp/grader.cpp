#include "game.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, x, y;
int finish = 0;
int fir = 1;
vector< int > S

int play(int i){
	if(finish){
		cout << "Wrong Answer" << endl;
		cout << "You do not end the game after play() return 0" << endl;
		finish = 1;
		return 0;
	}

	cout << "play(" << i << ")" << endl;
	if(!fir && i == 0){
		cout << "Wrong Answer" << endl;
		cout << "You use play(0) in not first turn" << endl;
		finish = 1;
		return 0;
	}
	if(!count(S.begin(), S.end(), abs(i))){
		cout << "Wrong Answer" << endl;
		cout << abs(i) << " not found in S" << endl;
		finish = 1;
		return 0;
	}
	if(i < 0) x -= -i;
	else y -= i;
	cout << "king at (" << x << "," << y << ")" << endl;
	if(x < 1 || y < 1){
		cout << "Wrong Answer" << endl;
		cout << "Invalid operator" << endl;
		finish = 1;
		return 0;
	}
	if(x == 1 && y == 1){
		cout << "OK" << endl;
		cout << "Your program Win" << endl;
		finish = 1;
		return 0;
	}

	int ret;
	assert(cin >> ret);
	assert(count(S.begin(), S.end(), abs(ret)));
	if(ret < 0) x -= -ret;
	if(ret > 0) y -= ret;
	assert(x > 0 && y > 0);
	if(x == 1 && y == 1){
		cout << "Wrong Answer" << endl;
		cout << "Your program Lose" << endl;
		finish = 1;
		return 0;
	}
	fir = 0;
	return ret;
}
int main() {
	assert(cin >> n >> x >> y);
	S = vector< int >(n);
	for(int i = 0; i < n; ++i) assert(cin >> S[i]);
	game(x, y, S);
	if(!finish){
		cout << "Wrong Answer" << endl;
		cout << "You end the game before play() return 0";
	}
}
