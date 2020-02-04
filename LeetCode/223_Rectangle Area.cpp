#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int left_down_x = max(E, A);
		int left_down_y = max(F, B);
		int right_up_x = min(G, C);
		int right_up_y = min(D, H);
		int area1 = (C - A)*(D - B);
		int area2 = (H - F)*(G - E);
		int area3 = 0;
		if ((E - A)*(E - C)*(G - A)*(G - C) > 0 || (F - B)*(F - D)*(H - B)*(H - D) > 0){
			area3 = 0;
		}else {
			area3 = (right_up_x - left_down_x)*(right_up_y - left_down_y);
		}
		return area1 + area2 - area3;
	}
};

class Solution2 {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int left = max(A, E), right = max(min(C, G), left);
		int bottom = max(B, F), top = max(min(D, H), bottom);
		return (C - A)*(D - B) - (right - left)*(top - bottom) + (G - E)*(H - F);
	}
};

int main() {
	Solution mysolu;
	//A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2
	//-2 -2 2 2 3 3 4 4
	int res = mysolu.computeArea(-2, -2, 2, 2, 3, 3, 4, 4);

	return 0;
}