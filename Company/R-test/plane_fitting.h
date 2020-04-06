
//this head file is used to fitting a plane in spatial space by LSM method.

//some tips:
//the LSM method can find in:
//https://www.ilikebigbits.com/2015_03_04_plane_from_points.html

//this file also used a third Library Eigen for some matrix manuplation
//http://eigen.tuxfamily.org/index.php?title=Main_Page
//  1.将相应文件复制到根目录(eigen3.3.7文件夹）
//  2.在项目的属性中包含该目录（右键项目-属性；包含目录（头文件）；库目录）
//  3.在cpp中包含相应头文件，使用其命名空间（using namespace Eigen;）
//  4.Include中的内容可能与相应文件目录不一致，需要仔细阅读相应文档。（#include<Eigen/Dense>）

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
#include<iostream>
#include<math.h>
#include<stdio.h>
#include <fstream>//ofstream类的头文件
#include<vector>
#include <string>
#include <cstdlib>
#include <ctime>

#include<Eigen/Dense>
#include <Eigen/LU>
using namespace Eigen;

//#ifdef PLANE_FITTING_EXPORTS
//#define PLANE_FITTING_EXPORTS_API _declspec(dllexport)
//#else
//#define PLANE_FITTING_EXPORTS_API _declspec(dllimport)
//#endif

using namespace std;
//paramters (include: data Point, circle parameter, the fitted plane)
#define M_PI 3.14159265358979323846
//collection data of point
struct Point
{
	double x;    //x coordinate
	double y;		//y coordinate
	double z;		//z coordinate
	unsigned int id;  //serial number

	Point()
	{
		x = 0, y = 0, z = 0, id = 0;
	}

	Point(double _x, double _y, double _z, unsigned int _id = 0)
	{
		x = _x, y = _y, z = _z;
		id = _id;
	}

	Point operator=(const Point& si)
	{
		x = si.x, y = si.y, z = si.z;
		id = si.id;
		return *this;
	}
};

struct Circle
{
	double x;		//x coordinate of circle center
	double y;		//y coordinate of circle center
	double z;		//z coordinate of circle center
	double r;		//radius of circle

	Circle operator=(const Circle& si)
	{
		x = si.x, y = si.y, z = si.z;
		r = si.r;
		return *this;
	}
};

//the fitting plane
struct Plane
{
	// a point in plane
	double x;
	double y;
	double z;

	// normal vector of plane
	double v_x;
	double v_y;
	double v_z;

	//equation of plane
	double A;
	double B;
	double C;
	double D;

	Plane operator=(const Plane& si)
	{
		x = si.x, y = si.y, z = si.z;
		v_x = si.v_x, v_y = si.v_y, v_z = si.v_z;
		A = si.A, B = si.B, C = si.C, D = si.D;
		return *this;
	}
};

//参数类定义
//class PLANE_FITTING_EXPORTS_API Rtest_var
class Rtest_var
{
private:
	string Manipulator; //操作者
	string Machine; //机床型号
	string Normal; //法向
	string Time;  //测量时间
	string Others; //其他信息

	double fre; //采样频率

	Point point_zero; //原点
	Point point_x;//X坐标
	Point point_y;//Y坐标
	Point point_z;//Z坐标

	Point point_x_inver;//X负向坐标
	Point point_y_inver;//Y负向坐标
	Point point_z_inver;//Z负向坐标

	Matrix3d TranposeMatrix; //初始化为单位矩阵

	vector<Point> axiscompen_data;//存储轴线误差测量数据

	double error_axis_x;
	double error_axis_y;
	double error_axis_z;

	int mode;
	double threshold;
	double stabletime;
	double stoptime; //停顿时间

	double alpha1;
	double alpha2;
	int divide;
	int count;
	int direc;
	string m_strAxis1; //第一旋转轴
	string m_strAxis2;//第二旋转轴
	string m_strAxisSel;//选择的旋转轴
	//输入参数：测量方式mold,稳定阈值b，稳定时间c,起始角度alpha1,最终角度alpha2
	//划分分数divide，重复次数count,正反方向direc,A轴/C轴 axis
	double A_angle_max;//A轴最大可运动角度


	int axis_num;
	double mutliaxis_set[15];
	//同步精度测量时定义参数；axis_num单轴运动或多轴同步运动；

	vector<Point> data_measure;
	vector<Point> data_read;
	vector<Point> data_theory;
	vector<Point> data_fit;
	vector<Point> data_read_todeal;//初步处理后的数据，即去除前后的触发数据

	int cal_axis;
	double rotate_error[4];
	double syn_error[3];

public:
	//构造函数内部赋值
	Rtest_var();

	//用户信息
	void userinfor_ok(string a1, string a2, string a3, string a4, string a5);
	void userinfor_clear();
	void setsave();
	void setread();

	//转换矩阵
	void cal_TranposeMatrix();
	void TranposeMatrix_reverse();
	Point Tran_point(Point &point_tran);
	vector<Point> Tran_data(vector<Point> &data);

	//圆拟合
	void fitting_plane_by_LSM(const vector<Point> &data, Plane &fitted_plane);
	void fitting_circle_by_LSM(const vector<Point>  &data, Plane &fitted_plane, Circle &fitted_circle);
	void point_projection(const vector<Point>  &data, const Plane &fitted_plane, vector<Point>& points_in_plane);
	void calculate_circle_in_plane(const vector<Point>& points_in_plane, Circle &fitted_circle);
	void construct_A(MatrixXd& A, const vector<Point>&data, const int n, const int flag);
	void construct_B(VectorXd& b, const vector<Point> &data, const int n, const int flag);
	void save_the_res(const VectorXd& x, Plane &fitted_plane, const int flag);

	//轴线误差补偿
	void error_axis_compen(vector<Point> &data);

	//轨迹规划
	//输入参数：测量方式a,稳定阈值b，稳定时间c,重复次数count,正反方向d,单轴运动或多轴运动e，各轴区间参数数组
	//void Trajectory_plan_linear(int a, double b, double c, int count, int d, int e, double axis[15]);
	void Trajectory_plan_linear(std::string szFile);
	//输入参数：测量方式a,稳定阈值b，稳定时间c,起始角度alpha1,最终角度alpha2
	//划分分数divide，重复次数count,正反方向d,A轴/C轴 e
	void Trajectory_plan_rotate(std::string szFile);

	//数据保存
	void datasave(vector<Point> &data,std::string szFile);
	void dataread(std::string szFile);
	//静态数据保存
	void datasave_static(vector<Point> &data, std::string szFile);

	//数据分析
	void error_cal(int nAxisSel);
	void rotate_error_cal(vector<Point> &data);
	void syn_error_cal(vector<Point> &data);
	void error_save(std::string szFile);
	void cal_pos_error_A(vector<Point>& data, double &y, double &z);
public:
	/*
	Point point_zero; //原点
	Point point_x;//X坐标
	Point point_y;//Y坐标
	Point point_z;//Z坐标
	*/
	void set_axis(string strAxis1, string strAxis2, string strAxisSel);//第一旋转轴、第二旋转轴、选择的旋转轴
	void set_point_zero(Point& pt);
	void set_point_x(Point& pt);
	void set_point_y(Point& pt);
	void set_point_z(Point& pt);

	void set_point_x_inver(Point& pt);
	void set_point_y_inver(Point& pt);
	void set_point_z_inver(Point& pt);

	void set_path_design(int _mode, double _threshold,double _stabletime, double _delaytime);

	/*
	double alpha1,double alpha2,int divide,int count,int direc
	*/
	void set_rotate_param(double _alpha1, double _alpha2, int _divide, int _count, int _direc);
	void set_sync_param(int _axis_num, double _mutliaxis_set[15]);

	void GetTranposeMatrix(Matrix3d &_trix);
	void GetReadData(vector<Point>& vecPt);

	void GetRotate_error(vector<double>& vecErr);
	void GetAxisError1(int &_cal_axis,double _rotate_error[4],double _syn_error[3]);

	void GetData_theory(vector<Point>& vecData);
	void GetData_fit(vector<Point>& vecData);

	void save_try(vector<Point>& data_read);
};

/*
//fitting function
//the mian function of this file
extern "C" Rtest_API void fitting_plane_by_LSM(const vector<Point> &data, Plane &fitted_plane);
//                                      <----------input--------------><--------output------>
extern "C" Rtest_API void fitting_circle_by_LSM(const vector<Point> &data, Plane &fitted_plane, Circle &fitted_circle);
//                                      <----------input------------------------------------><--------output------>


//some auxiliary function
//not need in API
void construct_A(MatrixXd &A,const vector<Point> &data, const int n);
void construct_B(VectorXd &b,const vector<Point> &data, const int n);
void save_the_res(const VectorXd &x, Plane &fitted_plane);

void point_projection(const vector<Point> &data, const Plane &fitted_plane, vector<Point>& points_in_plane);
void calculate_circle_in_plane(const vector<Point> & points_in_plane, Circle &fitted_circle);
*/