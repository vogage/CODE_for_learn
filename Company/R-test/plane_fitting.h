
//this head file is used to fitting a plane in spatial space by LSM method.

//some tips:
//the LSM method can find in:
//https://www.ilikebigbits.com/2015_03_04_plane_from_points.html

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
#include<iostream>
#include<math.h>
#include<stdio.h>
#include <fstream>//ofstream���ͷ�ļ�
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

//�����ඨ��
//class PLANE_FITTING_EXPORTS_API Rtest_var
class Rtest_var
{
private:
	string Manipulator; //������
	string Machine; //�����ͺ�
	string Normal; //����
	string Time;  //����ʱ��
	string Others; //������Ϣ

	double fre; //����Ƶ��

	Point point_zero; //ԭ��
	Point point_x;//X����
	Point point_y;//Y����
	Point point_z;//Z����

	Point point_x_inver;//X��������
	Point point_y_inver;//Y��������
	Point point_z_inver;//Z��������

	Matrix3d TranposeMatrix; //��ʼ��Ϊ��λ����

	vector<Point> axiscompen_data;//�洢��������������

	double error_axis_x;
	double error_axis_y;
	double error_axis_z;

	int mode;
	double threshold;
	double stabletime;
	double stoptime; //ͣ��ʱ��

	double alpha1;
	double alpha2;
	int divide;
	int count;
	int direc;
	string m_strAxis1; //��һ��ת��
	string m_strAxis2;//�ڶ���ת��
	string m_strAxisSel;//ѡ�����ת��
	//���������������ʽmold,�ȶ���ֵb���ȶ�ʱ��c,��ʼ�Ƕ�alpha1,���սǶ�alpha2
	//���ַ���divide���ظ�����count,��������direc,A��/C�� axis
	double A_angle_max;//A�������˶��Ƕ�


	int axis_num;
	double mutliaxis_set[15];
	//ͬ�����Ȳ���ʱ���������axis_num�����˶������ͬ���˶���

	vector<Point> data_measure;
	vector<Point> data_read;
	vector<Point> data_theory;
	vector<Point> data_fit;
	vector<Point> data_read_todeal;//�������������ݣ���ȥ��ǰ��Ĵ�������

	int cal_axis;
	double rotate_error[4];
	double syn_error[3];

public:
	//���캯���ڲ���ֵ
	Rtest_var();

	//�û���Ϣ
	void userinfor_ok(string a1, string a2, string a3, string a4, string a5);
	void userinfor_clear();
	void setsave();
	void setread();

	//ת������
	void cal_TranposeMatrix();
	void TranposeMatrix_reverse();
	Point Tran_point(Point &point_tran);
	vector<Point> Tran_data(vector<Point> &data);

	//Բ���
	void fitting_plane_by_LSM(const vector<Point> &data, Plane &fitted_plane);
	void fitting_circle_by_LSM(const vector<Point>  &data, Plane &fitted_plane, Circle &fitted_circle);
	void point_projection(const vector<Point>  &data, const Plane &fitted_plane, vector<Point>& points_in_plane);
	void calculate_circle_in_plane(const vector<Point>& points_in_plane, Circle &fitted_circle);
	void construct_A(MatrixXd& A, const vector<Point>&data, const int n, const int flag);
	void construct_B(VectorXd& b, const vector<Point> &data, const int n, const int flag);
	void save_the_res(const VectorXd& x, Plane &fitted_plane, const int flag);

	//��������
	void error_axis_compen(vector<Point> &data);

	//�켣�滮
	//���������������ʽa,�ȶ���ֵb���ȶ�ʱ��c,�ظ�����count,��������d,�����˶�������˶�e�����������������
	//void Trajectory_plan_linear(int a, double b, double c, int count, int d, int e, double axis[15]);
	void Trajectory_plan_linear(std::string szFile);
	//���������������ʽa,�ȶ���ֵb���ȶ�ʱ��c,��ʼ�Ƕ�alpha1,���սǶ�alpha2
	//���ַ���divide���ظ�����count,��������d,A��/C�� e
	void Trajectory_plan_rotate(std::string szFile);

	//���ݱ���
	void datasave(vector<Point> &data,std::string szFile);
	void dataread(std::string szFile);
	//��̬���ݱ���
	void datasave_static(vector<Point> &data, std::string szFile);

	//���ݷ���
	void error_cal(int nAxisSel);
	void rotate_error_cal(vector<Point> &data);
	void syn_error_cal(vector<Point> &data);
	void error_save(std::string szFile);
	void cal_pos_error_A(vector<Point>& data, double &y, double &z);
public:
	/*
	Point point_zero; //ԭ��
	Point point_x;//X����
	Point point_y;//Y����
	Point point_z;//Z����
	*/
	void set_axis(string strAxis1, string strAxis2, string strAxisSel);//��һ��ת�ᡢ�ڶ���ת�ᡢѡ�����ת��
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