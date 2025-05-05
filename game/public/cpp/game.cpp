#include "game.h"

void game(int x, int y, const std::vector<int> S){
	int n = S.size();
	
	while(x != 1 && y != 1){
		int ret = play(x > y ? -1 : 1);
		if(ret < 0) x -= -ret;
		else if(ret > 0) y -= ret;
		else return;
	}
}
