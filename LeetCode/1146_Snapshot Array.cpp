#include <map>
#include <vector>

using namespace std;

class SnapshotArray {
public:

	SnapshotArray(int length) {
		arrs = vector<map<int, int>>(length, map<int, int>());
		for (int i = 0; i < length; i++) {
			arrs[i][0] = 0;
		}
		snap_cnt = 0;
	}
	int snap() {
		snap_cnt++;
		return snap_cnt - 1;
	}
	void set(int index, int value) {
		arrs[index][snap_cnt] = value;
	}
	int get(int index, int snap_id) {
		auto m = arrs[index].upper_bound(snap_id);
		if (m != arrs[index].begin()) m--;
		return m->second;
	}
private:
	int snap_cnt;
	vector<map<int, int>> arrs;
};


int main() {
	SnapshotArray snapshotArr =SnapshotArray(3); // set the length to be 3
	snapshotArr.set(0, 5);  // Set array[0] = 5
	int res1=snapshotArr.snap();  // Take a snapshot, return snap_id = 0
	snapshotArr.set(0, 6);
	int res2=snapshotArr.get(0, 0);  // Get the value of array[0] with snap_id = 0, return 5
	return 0;
}