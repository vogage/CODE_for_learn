#include<stdio.h>
#include<vector>
#include<unordered_map>
#include<limits>
#include<algorithm>
using namespace std;
struct pair_hash
{
	template<class T1, class T2>
	std::size_t operator() (const std::pair<T1, T2>& p) const
	{
		auto h1 = std::hash<T1>{}(p.first);
		auto h2 = std::hash<T2>{}(p.second);
		return h1 ^ h2;
	}
};

//-------------------- -
//版权声明：本文为CSDN博主「一个程序渣渣的小后院」的原创文章，遵循CC 4.0 by - sa版权协议，转载请附上原文出处链接及本声明。
//原文链接：https ://blog.csdn.net/sinat_35261315/article/details/76473867

class Solution {
public:
	int maxPoints(vector<vector<int>>& points) {
	//use a hashmap to record all lines
		if (points.size() == 0 || points.size() == 1)return points.size();

		unordered_map<pair<double, double>, int,pair_hash> m;
		unordered_map<pair<double, double>, int, pair_hash>::iterator it = m.begin();
		unordered_map<pair<int, int>, int, pair_hash> m_points;
		unordered_map<pair<int, int>, int, pair_hash>::iterator it_points = m_points.begin();

	//ergodic all combined lines by points
		m_points[pair<int,int>(points[0][0],points[0][1])]++;
		for (int i = 1; i < points.size(); i++) {
			pair<int, int>i_p(points[i][0], points[i][1]);
			if (m_points.find(i_p) == m_points.end()) {
				for (auto pp:m_points) {
					vector<int> vv{ pp.first.first,pp.first.second };
				
					pair<double, double> t = get_combine_line(points[i], vv);

					m[t]++;

				}
			}
			m_points[i_p]++;
		}

		int res = 0;
	   
		for (auto k : m) {
			k.second = (1 + sqrt(8 * k.second + 1)) / 2;
			for (auto p : m_points) {
				if (p.second > 1) {
					if (thepointisinline(p.first, k.first)) {
						k.second += p.second - 1;
					}
				}
			}
			res = max(res, k.second);
		}
		for (auto k2 : m_points) {
			res = max(res, k2.second);
		}
		//number of lines transform to points
		
		return res;
	}
	bool thepointisinline(pair<int, int>p, pair<double, double>line) {
		if (line.second == numeric_limits<double>::max())return p.first == line.first;
		double res = float(line.first*p.first + line.second);

		return res == p.second;
	}



	pair<double, double> get_combine_line(vector<int>& p1, vector<int> &p2) {
		pair<double, double> res;
		double delta_x = p1[0] - p2[0];
		if (delta_x == 0) {
			res.first = p1[0];
			res.second = numeric_limits<double>::max();
		}
		else {
			res.first = (p1[1] - p2[1]) / delta_x;
			 double r1 = 0;
			double	 r2 = 0;
			if (p1[0] < p2[1]) {
				r1= p1[0] * (p2[1] / delta_x); }
			else {
				r1 = p2[1] * (p1[0] / delta_x);
			}
			if (p2[0] < p1[1]) {
				r2 =p2[0] * (p1[1] / delta_x);
			}
			else {
				r2 =p1[1] * (p2[0] / delta_x);
			}
			res.second =(float)(r1-r2);
		}
		return res;
	}
};

int main() {
	vector<vector<int>> input;
	input.push_back(vector<int>{1, 1});
	input.push_back(vector<int>{3, 2});
	input.push_back(vector<int>{5, 3});
	input.push_back(vector<int>{4, 1});
	input.push_back(vector<int>{2, 3});
	input.push_back(vector<int>{1, 4});
	Solution mysolu;
	
	vector<vector<int>>input2;
	input2.push_back(vector<int>{0, 0});
	input2.push_back(vector<int>{1, 65536});
	input2.push_back(vector<int>{65536, 0});

	vector<vector<int>>input3;
	input3.push_back(vector<int>{0, 0});
	input3.push_back(vector<int>{1, 1});
	input3.push_back(vector<int>{0, 0});

	vector<vector<int>> input4;
	input4.push_back(vector<int>{1, 1});
	input4.push_back(vector<int>{2, 2});
	input4.push_back(vector<int>{3, 3});

	vector<vector<int>> input5;
	input5.push_back(vector<int>{0, 0});
	input5.push_back(vector<int>{0, 0});

	vector<vector<int>>input6;
	input6.push_back(vector<int>{3, 1});
	input6.push_back(vector<int>{12, 3});
	input6.push_back(vector<int>{3, 1});
	input6.push_back(vector<int>{-6, -1});

	vector<vector<int>> input7;
	input7.push_back(vector<int>{0, -1});
	input7.push_back(vector<int>{0, 3});
	input7.push_back(vector<int>{0, -4});
	input7.push_back(vector<int>{0, -2});
	input7.push_back(vector<int>{0, -4});
	input7.push_back(vector<int>{0, 0});
	input7.push_back(vector<int>{0, 0});
	input7.push_back(vector<int>{0, 1});
	input7.push_back(vector<int>{0, -2});
	input7.push_back(vector<int>{0, 4});

	int res = mysolu.maxPoints(input7);
	return 0;

}