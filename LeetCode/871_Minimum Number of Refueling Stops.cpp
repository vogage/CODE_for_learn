#include<vector>
#include<queue>

using namespace std;

class Car {
public:
    Car(int _pos, int _cur, int _fuel, int _dist) :cur_pos(_pos),cur_miles(_cur), fuel(_fuel), dist(_dist) {}
    int cur_miles;
    int cur_pos;
    int fuel;
    int dist;
    int can_reach_target = fuel + cur_miles;
};

class Solution {
public:
    int minRefuelStops(int target, int startFuel,vector<vector<int>>& stations){ 
        priority_queue<int> pq;
        int n = stations.size();
        int stationIndex = 0;
        int fuelstock = 0;
        pq.push(startFuel);
        int stationCount = 0;
        while (!pq.empty()) {
            int temp = pq.top();
            pq.pop();
            fuelstock += temp;
            if (fuelstock >= target) return stationCount;
            while (stationIndex < n && stations[stationIndex][0] <= fuelstock) {
                pq.push(stations[stationIndex][1]);
                stationIndex++;
            }
            stationCount++;
        }

        return -1;
    }
};

int main() {
    Solution mysolu;
    int target = 100;
    int startFuel = 10;
   vector<vector<int>> stations = { {10, 60},{20, 30},{30, 30},{60, 40} };
   
   int target1 = 1000;
   int startFuel1 = 36;
   vector<vector<int>>stations1 = { {7, 13}, {10, 11},
  {12, 31}, {22, 14}, {32, 26}, {38, 16}, {50, 8}, {54, 13},{75, 4},
 {85, 2}, {88, 35},{90, 9},{96, 35},{103, 16},{115, 33},{121, 6},
       {123, 1}, {138, 2}, {139, 34}, {145, 30}, {149, 14}, {160, 21},
       {167, 14}, {188, 7}, {196, 27}, {248, 4}, {256, 35}, {262, 16},
 {264, 12}, {283, 23}, {297, 15}, {307, 25}, {311, 35},
{316, 6}, {345, 30}, {348, 2}, {354, 21}, {360, 10}, {362, 28},
{363, 29}, {367, 7}, {370, 13}, {402, 6}, {410, 32}, {447, 20},
{453, 13}, {454, 27}, {468, 1}, {470, 8}, {471, 11}, {474, 34},
{486, 13}, {490, 16}, {495, 10}, {527, 9}, {533, 14}, {553, 36},
{554, 23}, {605, 5}, {630, 17}, {635, 30}, {640, 31}, {646, 9},
{647, 12}, {659, 5}, {664, 34}, {667, 35}, {676, 6}, {690, 19},
{709, 10}, {721, 28}, {734, 2}, {742, 6}, {772, 22}, {777, 32},
{778, 36}, {794, 7}, {812, 24}, {813, 33}, {815, 14}, {816, 21},
{824, 17}, {826, 3}, {838, 14}, {840, 8}, {853, 29}, {863, 18},
{867, 1}, {881, 27}, {886, 27}, {894, 26}, {917, 3}, {953, 6},
{956, 3}, {957, 28}, {962, 33}, {967, 35}, {972, 34}, {984, 8},
{987, 12} };
   
   int target2 = 100;
   int startFuel2 = 1;
   vector<vector<int>> stations2 = { {10, 100}};
   int target3 = 100;
   int  startFuel3 = 50;
   vector<vector<int>> stations3 = { {25, 30} };

   int target4 = 1000;
   int startFuel4 = 299;
   vector<vector<int>> stations4 = { {13, 21}, {26, 115}, {100, 47}, {225, 99}, {299, 141},
   {444, 198}, {608, 190}, {636, 157}, {647, 255}, {841, 123} };

   
   int res = mysolu.minRefuelStops(target4, startFuel4, stations4);
    return 0;
}