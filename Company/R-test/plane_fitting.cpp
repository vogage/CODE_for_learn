// plane_fitting.cpp : 定义 DLL 应用程序的导出函数。
//
//#include "stdafx.h"

#define _USE_MATH_DEFINES
#include"plane_fitting.h"
#include<iostream>
#include<math.h>




void fitting_plane_by_LSM(const vector<Point> &data, Plane &fitted_plane){
//                                       <------------input-----------><--------output------>

	int n;  //the amount of Points
	if (data.back().id == data.size()) {
		n = data.size();
	}
	else {
		cout << "数据点序号与总数据点数目不符" << endl;
		return;
	}



	//Ax=b
	MatrixXd A(n, 3); VectorXd x; VectorXd b(n);

	//step1 construct A
	construct_A(A, data,n);

	//step2 construct b
	construct_B(b, data, n);
	
	//solve the equation： ATAx=ATb or Ax=b
	x = A.colPivHouseholderQr().solve(b);
	cout << "x:" << endl;
	cout << x << endl;

	//save in the form of plane struct;
	save_the_res(x, fitted_plane);

	return;
}

void fitting_circle_in_spatial_space(const vector<Point> &data, Plane &fitted_spatial_circle) {
	MatrixXd P(10,10);
	construct_P(data, P);
}

void construct_P(const vector<Point> &data, MatrixXd &P) {
	
	MatrixXd Pi(3, 3);
	MatrixXd I(3,3);

	//I is identity matrix
	for (int i = 0; i < 3; i++) { I(i, i) = 1; }
	int n = data.size();
	for (int i = 0; i < n; i++) {
		MatrixXd Pi_cross(3, 3);
		Pi(0, 0) = 0; Pi(0, 1) = -data[i].z; Pi(0, 2) = data[i].y;
		Pi(1, 0) = data[i].z; Pi(1, 1) = 0; Pi(1, 2) = -data[i].x;
		Pi(2, 0) = -data[i].y; Pi(2, 1) = data[i].x; Pi(2, 2) = 0;


	}
}
void fitting_circle_by_LSM(const vector<Point>  &data, Plane &fitted_plane,Circle &fitted_circle){

	//step1: Points projection onto the fitting plane
	vector<Point> points_in_plane;
	point_projection(data, fitted_plane, points_in_plane);

	calculate_circle_in_plane(points_in_plane, fitted_circle);
	return;
}

void fitting_sphere_by_LSM(const vector<Point> &data, vector<Sphere> &fitted_sphere) {
	//step1: Put the N point data pi in a data matrix[D]
	int n = data.size();
	MatrixXd D(5, n);
	put_data_in_matrix_D(data,D);

	//step2: calculate the matrix P
	//[P] = [D] [D]T [M]=N,
	MatrixXd P(5, 5);
	cal_matrix_P(D,n,P);
	//step3: Solve the eigenproblem for[P]
	EigenSolver<MatrixXd> eigen_vector(P);


	//this function calculate is complex value vector!!!!

	cout << "The  eigenvector of the  matrix P: " << endl;
	cout << eigen_vector.eigenvectors() << endl;
	cout << "The eigenvalues of the  matrix P: " << endl;
	cout << eigen_vector.eigenvalues() << endl;

	VectorXcd min_vector = eigen_vector.eigenvectors().col(4);
	cout << "The miniest eigenvector of the  matrix P: " << endl;
	cout << min_vector << endl;

	VectorXcd min_vector2 = eigen_vector.eigenvectors().col(3);
	//step4: nomalize the second miniest eigen_vector and save in the form of plane struct;

	save_the_res_of_fitted_sphere(min_vector, fitted_sphere);
	save_the_res_of_fitted_sphere(min_vector2, fitted_sphere);

	return;
} 

void calculate_the_fitted_plane_by_fitted_shphere(const vector<Sphere>& fitted_sphere, Plane &fitted_plane) {
	Sphere s1 = fitted_sphere[0];
	Sphere s2 = fitted_sphere[1];
	Plane p;
//calculate the insert plane
	p.A = -2 * (s1.x - s2.x);
	p.B = -2 * (s1.y - s2.y);
	p.C = -2 * (s1.z - s2.z);
	p.D = pow(s1.r, 2) - pow(s2.r, 2) - pow(s1.x, 2) + pow(s2.x, 2) - pow(s1.y, 2) + pow(s2.y, 2) - pow(s1.z, 2) + pow(s2.z, 2);

//plane normal vector
	Vector3d vn;
	vn(0) = p.A;
	vn(1) = p.B;
	vn(2) = p.C;
	vn.normalize();
	p.v_x = vn(0);
	p.v_y = vn(1);
	p.v_z = vn(2);
	cout << "plane normal vector :" << endl;
	cout << vn << endl;
	double left = p.A*p.v_x*s1.x + p.B*p.v_y*s1.y + p.C*p.v_z*s1.z;
	double right = p.D - p.A*s1.x - p.B*s1.y + p.C*s1.z;
	double t = right / left;
	Circle c;
	c.x = s1.x + p.v_x*t;
	c.y = s1.y + p.v_y*t;
	c.z = s1.z + p.v_z*t;
	c.r = sqrt(pow(s1.r, 2) - pow(c.x - s1.x, 2) - pow(c.y - s1.y, 2) - pow(c.z - s1.z, 2));
	cout << "the fitted circle" << endl;
	cout << "    x:" << c.x << "    y:" << c.y << "    z:" << c.z << "    z:" << c.z << endl;

}



void save_the_res_of_fitted_sphere(const VectorXcd &min_vector, vector< Sphere> &fitted_sphere) {
	Sphere s;
	double invide_param = min_vector(3).real();
	s.x = min_vector(0).real() / invide_param;
	s.y = min_vector(1).real() / invide_param;
	s.z = min_vector(2).real() / invide_param;
	double squart_norm_of_sphere_center = pow(s.x, 2) + pow(s.y, 2) + pow(s.z, 2);
	double x_end = min_vector(4).real() / invide_param;
	s.r = sqrt( squart_norm_of_sphere_center-2*x_end);
	fitted_sphere.push_back(s);
	cout << endl;
	cout << "the fitted plane: " << endl;
	cout << "   x :" << s.x << "   y :" << s.y << "   z :" << s.z << "   r :" << s.r << endl;
	return;

}
void cal_matrix_P(const MatrixXd &D,const int n,MatrixXd &P) {
	//[P] = [D] [D]T [M]=N,
	MatrixXd M(5,5);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			M(i, j) = 0;
		}
	}
	//I 3x3
	for (int i = 0; i < 3; i++) { M(i, i) = 1; }
	M(4, 3) = -1; M(3, 4) = -1;
	P = D * (D.transpose())*M / n;
	cout << "M:     " << endl;
	cout << M << endl;
	cout << "P:     " << endl;
	cout << P << endl;

}


void put_data_in_matrix_D(const vector<Point>&data,MatrixXd &D) {
	int n = data.size();	
	for (int i = 0; i < n; i++) {
		D(0, i) = data[i].x;
		D(1, i) = data[i].y;
		D(2, i) = data[i].z;
		D(3, i) = 1;
		D(4, i) = (pow(data[i].x, 2) + pow(data[i].y, 2) + pow(data[i].z, 2)) / 2;
	}
	cout << "D:     " << endl;
	cout << D << endl;

}




void point_projection(const vector<Point>  &data, const Plane &fitted_plane,vector<Point>& points_in_plane) {
	//method 1
	Vector3d origin;
	origin(0) = fitted_plane.x; 
	origin(1) = fitted_plane.y; 
	origin(2) = fitted_plane.z;

	Vector3d plane_normal_vector;
	plane_normal_vector(0) = fitted_plane.v_x;
	plane_normal_vector(1) = fitted_plane.v_y;
	plane_normal_vector(2) = fitted_plane.v_z;
	
	//calculate the projection
	int n = data.size();
	for (int i = 0; i < n; i++) {
		Vector3d interest_point;
		interest_point(0) = data[i].x;
		interest_point(1) = data[i].y;
		interest_point(2) = data[i].z;
		Vector3d diff_interest_and_origin= interest_point - origin;
		double dis = diff_interest_and_origin.dot(plane_normal_vector);
		Vector3d project_point = interest_point - dis * plane_normal_vector;
		cout << "project_point:" << endl;
		cout << project_point<<endl;

		//save result
		Point p_temp;
		p_temp.x=project_point(0);
		p_temp.y = project_point(1);
		p_temp.z = project_point(2);
		p_temp.id= data[i].id;
		points_in_plane.push_back(p_temp);

	}
}

void calculate_circle_in_plane(const vector<Point>& points_in_plane, Circle &fitted_circle) {
	int n = points_in_plane.size();
	double mean_x=0;
	double mean_y=0;
	double mean_z=0;
	double mean_r=0;
	for (int i = 0; i < n; i++) {
		mean_x += points_in_plane[i].x / n;
		mean_y += points_in_plane[i].y / n;
		mean_z += points_in_plane[i].z / n;
	}
	double n_devide = sqrt(n);
	for (int i = 0; i < n; i++) {
		mean_r += (pow(points_in_plane[i].x - mean_x,2)  + pow(points_in_plane[i].y - mean_y,2)  +pow (points_in_plane[i].y - mean_y, 2)) / n;
	}
	mean_r = sqrt(mean_r);
	cout << "the fitted circle:" << endl;
	cout << "mean_x: " << mean_x << "        mean_y: " << mean_y << "          mean_z: " << mean_z << "            mean_r: " << mean_r << endl;
}

void construct_A( MatrixXd& A, const vector<Point>&data, const int n) {
	for (int i = 0; i < n; i++) {
		A(i, 0) = data[i].x;
		A(i, 1) = data[i].y;
		A(i, 2) = 1;
	}
	cout << "A:" << endl;
	cout << A<<endl;

	return;
}


void construct_B(VectorXd& b, const vector<Point> &data, const int n) {
	for (int i = 0; i < n; i++) {
		b (i)= -data[i].z;
	}
	cout << "b:" << endl;
	cout << b<<endl;
	return;
}

void save_the_res(const VectorXd& x, Plane &fitted_plane) {
	
	VectorXd normal_temp(3);
	normal_temp(0) = x(0);
	normal_temp(1) = x(1);
	normal_temp(2) = 1;

	//plane equation : Ax+By+Cz=D
	fitted_plane.A = x(0);
	fitted_plane.B = x(1);
	fitted_plane.C = 1;
	fitted_plane.D = x(2);


	normal_temp=normal_temp.normalized();
	//plane normal vector
	fitted_plane.v_x = normal_temp(0);
	fitted_plane.v_y = normal_temp(1);
	fitted_plane.v_z = normal_temp(2);
	cout << "normal_temp" << endl;
	cout << normal_temp << endl;

	//a point in plane
	fitted_plane.x = 0;
	fitted_plane.y = 0;
	fitted_plane.z = -x(2);
	cout << "a point in plane:" << endl;
	cout << fitted_plane.x << "," << fitted_plane.y << "," << fitted_plane.z << endl;

}

void cal_A_rtcp_deviation(const vector<double>& angle, const vector<Point> &data,vector<double> &res) {
	//                                       <------------input-----------------------------------------><--------output------>
	//Input ：
	//angle: A轴运动时，测量点对应的A轴运动角度
	//data: A轴运动到该角度时，所测的误差
//**************************************************************************************************************************
	//注意：A轴只取末端（比如-90°和90°）附近几个点，不然由于矩阵奇异性，在A轴0°左右会有很大偏差
//**************************************************************************************************************************
	
	if (angle.size() != data.size()) { cout << "wrong data"<<endl; return; }
	vector<double> ang = angle;
	for (int i = 0; i < ang.size(); i++) {
		ang[i] = ang[i] * M_PI / 180;//角度换算为弧度
	}

	VectorXd deviation(2); //所测的差值
	MatrixX2d R(2,2);//A轴换算旋转矩阵
	VectorXd Deflection(data.size());//摆偏 ：对应于Y方向
	VectorXd Swing(data.size());// 摆长：对应于Z方向
	
	for (int i = 0; i < data.size(); i++) {
		//step 1 Calculate the Matrix
		
		R(0, 0) = cos(ang[i]) - 1;	
		R (0,1)=-sin(ang[i]);
		R (1,0)= sin(ang[i]);
		R (1,1)=cos(ang[i]) - 1.0;

		//step 2
		deviation(0) = data[i].y;
		deviation(1) = data[i].z;

		//step 3
		deviation = R.inverse()*deviation;

	//	double D= deviation(0);
	//	double S= deviation(1);
		Deflection(i) = deviation(0);
		Swing(i)= deviation(1);
		

	}
	res.push_back(Deflection.mean()); // res[1] 摆偏差值
	res.push_back(Swing.mean());// res[2] 摆长差值


}