
//this head file is used to fitting a plane in spatial space by LSM method.

//some tips:
//the LSM method can find in:
//https://www.ilikebigbits.com/2015_03_04_plane_from_points.html

//the sphere fitting method is coming from Leo Dorst (L.Dorst@uva.nl)<Least Squares Fitting of Spatial Circles>)

//this file also used a third Library Eigen for some matrix manuplation
//http://eigen.tuxfamily.org/index.php?title=Main_Page
//  1.����Ӧ�ļ����Ƶ���Ŀ¼(eigen3.3.7�ļ��У�
//  2.����Ŀ�������а�����Ŀ¼���Ҽ���Ŀ-���ԣ�����Ŀ¼��ͷ�ļ�������Ŀ¼��
//  3.��cpp�а�����Ӧͷ�ļ���ʹ���������ռ䣨using namespace Eigen;��
//  4.Include�е����ݿ�������Ӧ�ļ�Ŀ¼��һ�£���Ҫ��ϸ�Ķ���Ӧ�ĵ�����#include<Eigen/Dense>��

/*****************************************************************
Autor: Qian dehou, Chen zaozao
Version:1.0
Date:2019-4-10
********************************************************************/
#pragma once
#ifndef  PLANE_FITTING_H_
#define PLANE_FITTING_H_H
#endif // ! PLANE_FITTING_H_

//#include"stdafx.h"
#include<vector>
#include<Eigen/Dense>

using namespace std;
using namespace Eigen;
//paramters (include: data Point, circle parameter, the fitted plane)

//collection data of point
struct Point
{
	double x;    //x coordinate
	double y;		//y coordinate
	double z;		//z coordinate
	unsigned int id;  //serial number  
};

struct Circle {
	double x;		// x coordinate of circle center
	double y;		//y coordinate of circle center
	double z;		//z coordinate of circle center
	double r;		//radius of circle
};

//the fitting plane
struct Plane {
	// a point in plane
		double x;
		double y;
		double z;
	
	// normal vector of plane
		double v_x;
		double v_y;
		double v_z;

	//equation of plane
		//Ax+By+Cz=D
		double A;
		double B;
		double C;
		double D;
};

//the fitting sphere
struct Sphere {
	double x;		// x coordinate of circle center
	double y;		// y coordinate of circle center
	double z;		// z coordinate of circle center
	double r;		// sphere circle
};

//fitting function
//the mian function of this file
void fitting_plane_by_LSM(const vector<Point> &data, Plane &fitted_plane);
//                                      <----------input--------------><--------output------>
void fitting_circle_by_LSM(const vector<Point> &data, Plane &fitted_plane, Circle &fitted_circle);
//                                      <----------input------------------------------------><--------output------>
void fitting_sphere_by_LSM(const vector<Point> &data, vector<Sphere> &fitted_sphere);
//                                      <----------input--------------------><-------------output------>
void fitting_circle_in_spatial_space(const vector<Point> &data, Plane &fitted_spatial_circle);
//                                      <----------input------------------------><-------------output------>



//some auxiliary function
//not need in API
void construct_A(MatrixXd& A, const vector<Point> &data, const int n);
void construct_B(VectorXd& b, const vector<Point> &data, const int n);
void save_the_res(const VectorXd&  x, Plane &fitted_plane);




void point_projection(const vector<Point> &data, const Plane &fitted_plane, vector<Point>& points_in_plane);
void calculate_circle_in_plane(const vector<Point> & points_in_plane, Circle &fitted_circle);
void put_data_in_matrix_D(const vector<Point>&data, MatrixXd &D);
void cal_matrix_P(const MatrixXd &D, const int n, MatrixXd &P);
void save_the_res_of_fitted_sphere(const VectorXcd &min_vector, vector< Sphere> &fitted_sphere);
void calculate_the_fitted_plane_by_fitted_shphere(const vector<Sphere>& fitted_sphere, Plane &fitted_plane);
void construct_P(const vector<Point> &data, MatrixXd &P);



void cal_A_rtcp_deviation(const vector<double>& angle, const vector<Point> &data, vector<double> &res);
	//                                       <------------input-----------------------------------------><--------output------>
	//Input ��
	//angle: A���˶�ʱ���������Ӧ��A���˶��Ƕ�
	//data: A���˶����ýǶ�ʱ����������
//**************************************************************************************************************************
	//ע�⣺A��ֻȡĩ�ˣ�����-90���90�㣩���������㣬��Ȼ���ھ��������ԣ���A��0�����һ��кܴ�ƫ��
//**************************************************************************************************************************
