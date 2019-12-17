#include"VCS_compensation.h"
#include<math.h>
#include<sstream>
#include<fstream>


void VCS::initial_AC_test_trajectory(float Astart, float Aend, float Cstart, float Cend, int numA, int numC) {
	float a, c;
	
	for (int i = 0; i < numA; i++) {
		a = Astart + i * (Aend - Astart) / (numA - 1);
		for (int j = 0; j < numC; j++) {
			if (i % 2 == 1) {
				 c = Cend - j * (Cend - Cstart) / (numC - 1);
			}
			else {
				 c = Cstart + j * (Cend - Cstart) / (numC - 1);
			}
			vector<float> ac;
			ac.push_back(a);
			ac.push_back(c);
			AC.push_back(ac);
		}
	}
	return;
}

void VCS::read_test_error() {
	
	ifstream in("error.txt");
	vector<float> er(3,0);
	while (!in.eof()) {
		in >> er[0] >> er[1] >> er[2];
		AC_error.push_back(er);
	}

	//最后一行读了两遍
	AC_error.pop_back();
	return;
}

void VCS::read_compensation_NC_code() {
	ifstream in("NC.txt");
	Point p;
	while (!in.eof()) {
		in >> p.origin_NC.X >> p.origin_NC.Y >> p.origin_NC.Z >> p.origin_NC.A >> p.origin_NC.C;
		AC_compensation.push_back(p);
	}
	AC_compensation.pop_back();
	return;
}

void VCS::calculate_the_compensation_trajectory() {

	for (int i = 0; i < AC_compensation.size(); i++) {
		float A = AC_compensation[i].origin_NC.A;
		float C = AC_compensation[i].origin_NC.C;

		vector<float> AC_need_compensation;
		AC_need_compensation.push_back(A);
		AC_need_compensation.push_back(C);

		vector<vector<float>> AC_element(4,vector<float>());
		vector<vector<float>> AC_element_error(4,vector<float>());
		find_AC_brick(AC_need_compensation, AC_element, AC_element_error);

		vector<float> xyz_error(3,0);
		get_AC_test_error(AC_element, AC_element_error, AC_need_compensation, xyz_error);

		AC_compensation[i].Err_x = xyz_error[0];
		AC_compensation[i].Err_y = xyz_error[1];
		AC_compensation[i].Err_z = xyz_error[2];

		AC_compensation[i].new_NC.A = AC_compensation[i].origin_NC.A;
		AC_compensation[i].new_NC.C = AC_compensation[i].origin_NC.C;
		AC_compensation[i].new_NC.X = AC_compensation[i].origin_NC.X - xyz_error[0];
		AC_compensation[i].new_NC.Y = AC_compensation[i].origin_NC.Y - xyz_error[1];
		AC_compensation[i].new_NC.Z = AC_compensation[i].origin_NC.Z - xyz_error[2];
		
	}
	return;
}



void VCS::find_AC_brick( vector<float>& AC_need_compensation,Array& AC_element, Array& AC_element_error){

	int n = AC.size();
	for (int i = 0; i <4; i++) {
		AC_element[i] = AC[i];
	}
	float at = AC_need_compensation[0];
	float ct = AC_need_compensation[1];
	if (ct < 0) ct = ct + 360;

	for (int i = 0; i < n; i++) {
		float a = AC[i][0];
		float c = AC[i][1];
		vector<float> er = AC_error[i];
		float r_temp = pow(a - at, 2) + pow(c - ct, 2);

		if (a <= at) {
			if (c <= ct) {//left-down position
				float r_origin = pow(AC_element[0][0] - at, 2) + pow(AC_element[0][1] - ct, 2);
				if (r_temp < r_origin) {
					AC_element[0][0] = a;
					AC_element[0][1] = c;
					AC_element_error[0] = er;
				}				
			}
			else {//left_up position
				float r_origin = pow(AC_element[1][0] - at, 2) + pow(AC_element[1][1] - ct, 2);
				if (r_temp < r_origin) {
					AC_element[1][0] = a;
					AC_element[1][1] = c;
					AC_element_error[1] = er;
				}
			}
		}
		else {
			if (c >= ct) {//right-up position
				float r_origin = pow(AC_element[2][0] - at, 2) + pow(AC_element[2][1] - ct, 2);
				if (r_temp < r_origin) {
					AC_element[2][0] = a;
					AC_element[2][1] = c;
					AC_element_error[2] = er;
				}
			}
			else {//right-down position
				float r_origin = pow(AC_element[3][0] - at, 2) + pow(AC_element[3][1] - ct, 2);
				if (r_temp < r_origin) {
					AC_element[3][0] = a;
					AC_element[3][1] = c;
					AC_element_error[3] = er;
				}
			}
		}
	}
}


void VCS::get_AC_test_error(Array& AC_element, Array& AC_element_error, vector<float> &AC_need_compensation,vector<float>& xyz_error) {
	float mean_a = (AC_element[0][0] + AC_element[2][0]) / 2;
	float mean_c = (AC_element[0][1] + AC_element[1][1]) / 2;
	float m = (AC_element[2][0] - AC_element[0][0]) / 2;
	float n = (AC_element[1][1] - AC_element[0][1]) / 2;
   
	float A = AC_need_compensation[0];
	float C = AC_need_compensation[1];
	if (C < 0) C = C + 360;
	float t = (C - mean_c) / n;
	float s = (A - mean_a) / m;
	
	for (int i = 0; i < 4; i++) {
		float tj = (AC_element[i][1] - mean_c) / n;
		float sj = (AC_element[i][0] - mean_a) / m;
		float Nj = (1 + t * tj)*(1 + s * sj) / 4;
		for (int j = 0; j < xyz_error.size(); j++) {
			xyz_error[j] =xyz_error[j] + AC_element_error[i][j] * Nj;
		}
	}

}