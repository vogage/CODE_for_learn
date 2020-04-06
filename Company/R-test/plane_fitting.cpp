#include "plane_fitting.h"
#include "plane_fitting.h"
#include"plane_fitting.h"

//plane fitting
void Rtest_var::fitting_plane_by_LSM(const vector<Point> &data, Plane &fitted_plane)
{
	//                                       <------------input-----------><--------output------>
	/*
	int n;  //the amount of Points
	if (data.back().id == data.size()) {
		n = data.size();
	}
	else {
		cout << "数据点序号与总数据点数目不符" << endl;
		return;
	}
	*/

	int n;
	n = data.size();
	//Ax=b
	MatrixXd A(n, 3);
	VectorXd x;
	VectorXd b(n);

	//judge the x,y,z
	//then chose the appropriate plane parameter
	//the aim of this part is to reduce rounding error when the value near zero
	double x_mean = 0, y_mean = 0, z_mean = 0;

	for(int i = 0; i < n; i++)
	{
		x_mean += data[i].x / n;
		y_mean += data[i].y / n;
		z_mean += data[i].z / n;
	}

	double x_square = 0, y_square = 0, z_square = 0;

	for(int i = 0; i < n; i++)
	{
		x_square += pow(data[i].x - x_mean, 2) / n;
		y_square += pow(data[i].y - y_mean, 2) / n;
		z_square += pow(data[i].z - z_mean, 2) / n;
	}

	int flag = 1;

	// 1 present the x_mean=0
	if(x_square < y_square && x_square < z_square)
	{
		flag = 1;
	}

	if(y_square < z_square && y_square < x_square)
	{
		flag = 2;
	}

	if(z_square < x_square && z_square < y_square)
	{
		flag = 3;
	}


	//step1 construct A
	construct_A(A, data, n, flag);

	//step2 construct b
	construct_B(b, data, n, flag);

	//solve the equation： ATAx=ATb or Ax=b
	x = A.colPivHouseholderQr().solve(b);
	cout << "x:" << endl;
	cout << x << endl;

	//save in the form of plane struct;
	save_the_res(x, fitted_plane, flag);

	return;
}

void Rtest_var::fitting_circle_by_LSM(const vector<Point>  &data, Plane &fitted_plane, Circle &fitted_circle)
{

	//step1: Points projection onto the fitting plane
	vector<Point> points_in_plane;
	point_projection(data, fitted_plane, points_in_plane);
	calculate_circle_in_plane(points_in_plane, fitted_circle);
	return;
}

void Rtest_var::point_projection(const vector<Point>  &data, const Plane &fitted_plane, vector<Point>& points_in_plane)
{
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

	for(int i = 0; i < n; i++)
	{
		Vector3d interest_point;
		interest_point(0) = data[i].x;
		interest_point(1) = data[i].y;
		interest_point(2) = data[i].z;
		Vector3d diff_interest_and_origin = interest_point - origin;
		double dis = diff_interest_and_origin.dot(plane_normal_vector);
		Vector3d project_point = interest_point - dis * plane_normal_vector;
		cout << "project_point:" << endl;
		cout << project_point << endl;

		//save result
		Point p_temp;
		p_temp.x = project_point(0);
		p_temp.y = project_point(1);
		p_temp.z = project_point(2);
		p_temp.id = data[i].id;
		points_in_plane.push_back(p_temp);

	}
}

void Rtest_var::calculate_circle_in_plane(const vector<Point>& points_in_plane, Circle &fitted_circle)
{
	int n = points_in_plane.size();
	double mean_x = 0;
	double mean_y = 0;
	double mean_z = 0;
	double mean_r = 0;

	for(int i = 0; i < n; i++)
	{
		mean_x += points_in_plane[i].x / n;
		mean_y += points_in_plane[i].y / n;
		mean_z += points_in_plane[i].z / n;
	}

	double n_devide = sqrt(n);

	for(int i = 0; i < n; i++)
	{
		mean_r += (pow(points_in_plane[i].x - mean_x, 2) + pow(points_in_plane[i].y - mean_y, 2) + pow(points_in_plane[i].z - mean_z, 2)) / n;
	}

	mean_r = sqrt(mean_r);
	cout << "the fitted circle:" << endl;
	cout << "mean_x: " << mean_x << "        mean_y: " << mean_y << "          mean_z: " << mean_z << "            mean_r: " << mean_r << endl;
	fitted_circle.x = mean_x;
	fitted_circle.y = mean_y;
	fitted_circle.z = mean_z;
	fitted_circle.r = mean_r;
}

void Rtest_var::construct_A(MatrixXd& A, const vector<Point>&data, const int n, const int flag)
{
	//mean_square_x is min
	if(flag == 1)
	{
		for(int i = 0; i < n; i++)
		{
			A(i, 0) = 1;
			A(i, 1) = data[i].y;
			A(i, 2) = data[i].z;
		}

		cout << "mean_square_x is min" << endl;
	}
	//mean_square_y is min
	else if(flag == 2)
	{
		for(int i = 0; i < n; i++)
		{
			A(i, 0) = data[i].x;
			A(i, 1) = 1;
			A(i, 2) = data[i].z;
		}

		cout << "mean_square_y is min" << endl;
	}
	//mean_square_z is min
	else if(flag == 3)
	{
		for(int i = 0; i < n; i++)
		{
			A(i, 0) = data[i].x;
			A(i, 1) = data[i].y;
			A(i, 2) = 1;
		}

		cout << "mean_square_z is min" << endl;
	}

	cout << "A:" << endl;
	cout << A << endl;

	return;
}

void Rtest_var::construct_B(VectorXd& b, const vector<Point> &data, const int n, const int flag)
{
	if(flag == 1)
	{
		for(int i = 0; i < n; i++)
		{
			b(i) = -data[i].x;
		}
	}
	else if(flag == 2)
	{
		for(int i = 0; i < n; i++)
		{
			b(i) = -data[i].y;
		}
	}
	else if(flag == 3)
	{
		for(int i = 0; i < n; i++)
		{
			b(i) = -data[i].z;
		}
	}

	cout << "b:" << endl;
	cout << b << endl;
	return;
}

void Rtest_var::save_the_res(const VectorXd& x, Plane &fitted_plane, const int flag)
{
	//step1
	//judge the format of plane equation : Ax+By+Cz+D=0

	VectorXd normal_temp(3);

	//mean_square_x is min
	if(flag == 1)
	{
		normal_temp(0) = 1;
		normal_temp(1) = x(1);
		normal_temp(2) = x(2);

		//plane equation : Ax+By+Cz+D=0
		fitted_plane.A = 1;
		fitted_plane.B = x(0);
		fitted_plane.C = x(1);
		fitted_plane.D = x(2);
	}
	else if(flag == 2)
	{
		//mean_square_y is min
		normal_temp(0) = x(0);
		normal_temp(1) = 1;
		normal_temp(2) = x(2);

		//plane equation : Ax+By+Cz+D=0
		fitted_plane.A = x(0);
		fitted_plane.B = 1;
		fitted_plane.C = x(1);
		fitted_plane.D = x(2);
	}
	else if(flag == 3)
	{
		//mean_square_z is min
		normal_temp(0) = x(0);
		normal_temp(1) = x(1);
		normal_temp(2) = 1;

		//plane equation : Ax+By+Cz+D=0
		fitted_plane.A = x(0);
		fitted_plane.B = x(1);
		fitted_plane.C = 1;
		fitted_plane.D = x(2);
	}

	normal_temp = normal_temp.normalized();
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

Rtest_var::Rtest_var()
{
	Manipulator = "none"; //操作者
	Machine = "none"; //机床型号
	Normal = "none"; //法向
	Time = "none";  //测量时间
	Others = "none"; //其他信息


	fre = 40; //采样频率

	point_zero = { 0, 0, 0, 0 }; //原点
	point_x = { 0, 0, 0, 0 }; //X坐标
	point_y = { 0, 0, 0, 0 }; //Y坐标
	point_z = { 0, 0, 0, 0 }; //Z坐标

	point_x_inver = { 0, 0, 0, 0 }; //X坐标
	point_y_inver = { 0, 0, 0, 0 }; //Y坐标
	point_z_inver = { 0, 0, 0, 0 }; //Z坐标

	TranposeMatrix = Eigen::Matrix3d::Identity(); //初始化为单位矩阵

	vector<Point> axiscompen_data;//存储轴线误差测量数据

	error_axis_x = 0;
	error_axis_y = 0;
	error_axis_z = 0;

	mode = 1;
	threshold = 2;
	stabletime = 3;
	stoptime = 5;

	alpha1 = 0;
	alpha2 = 90;
	divide = 10;
	count = 3;
	direc = 1;
	m_strAxis1 = "A";
	m_strAxis2 = "C";
	m_strAxisSel = "A";//m默认的选择的旋转轴为A
	A_angle_max = 90;



	axis_num = 1;
	//同步精度测量时定义参数；axis_num单轴运动或多轴同步运动；
	mutliaxis_set[0] = 0;
	mutliaxis_set[1] = 5;
	mutliaxis_set[2] = 10;
	mutliaxis_set[3] = 0;
	mutliaxis_set[4] = 5;
	mutliaxis_set[5] = 10;
	mutliaxis_set[6] = 0;
	mutliaxis_set[7] = 5;
	mutliaxis_set[8] = 10;
	mutliaxis_set[9] = 0;
	mutliaxis_set[10] = 10;
	mutliaxis_set[11] = 10;
	mutliaxis_set[12] = 0;
	mutliaxis_set[13] = 10;
	mutliaxis_set[14] = 10;

	cal_axis = 0;
	rotate_error[0] = 0;
	rotate_error[1] = 0;
	rotate_error[2] = 0;
	rotate_error[3] = 0;
	syn_error[0] = 0;
	syn_error[1] = 0;
	syn_error[2] = 0;
}

//用户信息
void Rtest_var::userinfor_ok(string a1, string a2, string a3, string a4, string a5)
{
	Manipulator = a1; //操作者
	Machine = a2; //机床型号
	Normal = a3; //法向
	Time = a4;  //测量时间
	Others = a5; //其他信息
}

void Rtest_var::userinfor_clear()
{
	Manipulator = "none"; //操作者
	Machine = "none"; //机床型号
	Normal = "none"; //法向
	Time = "none";  //测量时间
	Others = "none"; //其他信息
}

void Rtest_var::setsave()
{
	ofstream mycout("Set.txt");
	mycout << Manipulator << endl;
	mycout << Machine << endl;
	mycout << Normal << endl;
	mycout << Time << endl;
	mycout << Others << endl;
	mycout << point_zero.x << ' ' << point_zero.y << ' ' << point_zero.z << ' ' << point_zero.id << endl;
	mycout << point_x.x << ' ' << point_x.y << ' ' << point_x.z << ' ' << point_x.id << endl;
	mycout << 1 << ' ' << 2 << ' ' << 3 << ' ' << 4 << endl;
	mycout << 5 << ' ' << 6 << ' ' << 7 << ' ' << 8 << endl;
	mycout << point_y.x << ' ' << point_y.y << ' ' << point_y.z << ' ' << point_y.id << endl;
	mycout << point_z.x << ' ' << point_z.y << ' ' << point_z.z << ' ' << point_z.id << endl;

	mycout << TranposeMatrix << endl;

	mycout << error_axis_x << ' ' << error_axis_y << ' ' << error_axis_z << endl;

	mycout.close();
}

void Rtest_var::setread()
{
	ifstream myin("Set.txt");
	myin >> Manipulator;
	myin >> Machine;
	myin >> Normal;
	myin >> Time;
	myin >> Others;
	myin >> point_zero.x >> point_zero.y >> point_zero.z >> point_zero.id ;
	myin >> point_x.x >> point_x.y >> point_x.z >> point_x.id ;
	myin >> point_y.x >> point_y.y >> point_y.z >> point_y.id;
	myin >> point_z.x >> point_z.y >> point_z.z >> point_z.id ;
	double a1, a2, a3, b1, b2, b3, c1, c2, c3;
	myin >> a1 >> a2 >> a3;
	myin >> b1 >> b2 >> b3;
	myin >> c1 >> c2 >> c3;
	TranposeMatrix << a1, a2, a3,
	               b1, b2, b3,
	               c1, c2, c3;
	myin >> error_axis_x >> error_axis_y >> error_axis_z;

	myin.close();

}

//转换矩阵
//计算转换矩阵
void Rtest_var::cal_TranposeMatrix()
{

	double dis;	//标定时机床每次移动的距离
	dis = 1;
	Matrix3d M_machine;	//机床运动得到的矩阵
	M_machine << dis, 0, 0,
	          0, dis, 0,
	          0, 0, dis;


	Matrix3d M_sensor;	//传感器数据得到的矩阵
	M_sensor(0, 0) = (point_x.x - point_x_inver.x) / 2;
	M_sensor(1, 0) = (point_x.y - point_x_inver.y) / 2;
	M_sensor(2, 0) = (point_x.z - point_x_inver.z) / 2;
	M_sensor(0, 1) = (point_y.x - point_y_inver.x) / 2;
	M_sensor(1, 1) = (point_y.y - point_y_inver.y) / 2;
	M_sensor(2, 1) = (point_y.z - point_y_inver.z) / 2;
	M_sensor(0, 2) = (point_z.x - point_z_inver.x) / 2;
	M_sensor(1, 2) = (point_z.y - point_z_inver.y) / 2;
	M_sensor(2, 2) = (point_z.z - point_z_inver.z) / 2;

	Matrix3d inv_M_sensor;
	inv_M_sensor = M_sensor.inverse();	//求传感器数据得到的矩阵逆

	Matrix3d TranMatrix;
	TranMatrix = M_machine * inv_M_sensor;

	TranposeMatrix = TranMatrix;

}

//转换矩阵重置为零矩阵
void Rtest_var::TranposeMatrix_reverse()
{
	TranposeMatrix << 1, 0, 0, 0, 1, 0, 0, 0, 1;
	point_zero = { 0, 0, 0, 0 }; //原点
	point_x = { 0, 0, 0, 0 }; //X坐标
	point_y = { 0, 0, 0, 0 }; //Y坐标
	point_z = { 0, 0, 0, 0 }; //Z坐标

	point_x_inver = { 0, 0, 0, 0 }; //X坐标
	point_y_inver = { 0, 0, 0, 0 }; //Y坐标
	point_z_inver = { 0, 0, 0, 0 }; //Z坐标
}

//输入转换矩阵，零点，新的数据
Point Rtest_var::Tran_point(Point &point_tran)
{
	Vector3d point_vec(point_tran.x - point_zero.x, point_tran.y - point_zero.y, point_tran.z - point_zero.z);
	Vector3d point_aftertran;
	point_aftertran = TranposeMatrix * point_vec;
	Point Point_aftertran;
	Point_aftertran.x = point_aftertran(0, 0);
	Point_aftertran.y = point_aftertran(1, 0);
	Point_aftertran.z = point_aftertran(2, 0);
	Point_aftertran.id = point_tran.id;
	return Point_aftertran;
}

vector<Point> Rtest_var::Tran_data(vector<Point> &data)
{
	int n = data.size();

	for(int i = 0; i < n; i++)
	{
		Vector3d tran_point;
		tran_point(0) = data[i].x - point_zero.x;
		tran_point(1) = data[i].y - point_zero.y;
		tran_point(2) = data[i].z - point_zero.z;
		tran_point = TranposeMatrix * tran_point;
		data[i].x = tran_point(0);
		data[i].y = tran_point(1);
		data[i].z = tran_point(2);
	}
	return data;
}

//轴线误差补偿
void Rtest_var::error_axis_compen(vector<Point> &data)
{
	data = Tran_data(data);
	Plane p;
	p.v_x = 0;

	Circle fitted_circle;
	fitting_plane_by_LSM(data, p);
	fitting_circle_by_LSM(data, p, fitted_circle);
	error_axis_x = fitted_circle.x;
	error_axis_y = fitted_circle.y;
	error_axis_z = fitted_circle.z;
}

//轨迹规划
//输入参数：测量方式a,稳定阈值b，稳定时间c,起始角度alpha1,最终角度alpha2
//划分分数divide，重复次数count,正反方向d,A轴/C轴 e
void Rtest_var::Trajectory_plan_rotate(std::string szFile)
{
	int a = mode;
	double b = threshold;
	double c = stabletime;
	//double alpha1;
	//double alpha2, int divide, int count
	int d = direc;	
	int e;
	if (strcmp(m_strAxis1.c_str(),m_strAxisSel.c_str())==0)
	{
		e = 0;
	}
	else
	{
		e = -1;
	}
	//画图用数据

	double rotate_alpha1;
	vector<double> rotate_alpha;

	for(int rotate_count = 0; rotate_count <= divide; rotate_count++)
	{
		rotate_alpha1 = alpha1 + (alpha2 - alpha1) * rotate_count;
		rotate_alpha.push_back(rotate_alpha1);
	}

	//画图程序
	ofstream mycout(szFile.c_str());
	int i;
	int Serial = 1;
	int j;
	double deltaalpha;

	//静态测量
	if(a == 0)
	{
		deltaalpha = (alpha2 - alpha1) / divide;

		//正反向重复
		for(j = 0; j < count; j++)
		{
			//判读正向或反向
			if(j % 2 == 0)
			{
				//正向时且为A轴
				if(e == 0)
				{
					for(i = 0; i < divide + 1; i++)
					{
						mycout << 'N' << Serial << ' ' << m_strAxis1 << (alpha1 + i * deltaalpha) << ' ' << m_strAxis2 << 0 << endl;
						Serial++;

						if(Serial == 2)
						{
							mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
							Serial++;
						}
						else
						{
							mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << stoptime << endl;
							Serial++;
						}
					}
					cout << endl << endl;
				}
				else
				{
					for(i = 0; i < divide + 1; i++)
					{
						mycout << 'N' << Serial << ' ' << m_strAxis1 << 0 << ' ' << m_strAxis2 << (alpha1 + i * deltaalpha) << endl;
						Serial++;

						if(Serial == 2)
						{
							mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
							Serial++;
						}
						else
						{
							mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << stoptime << endl;
							Serial++;
						}
					}
					cout << endl << endl;
				}
			}
			else
			{
				if(d == 0)
				{
					//正向时且为A轴
					if(e == 0)
					{
						for(i = 0; i < divide + 1; i++)
						{
							mycout << 'N' << Serial << ' ' << m_strAxis1 << (alpha1 + i * deltaalpha) << ' ' << m_strAxis2 << 0 << endl;
							Serial++;

							if(Serial == 2)
							{
								mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
								Serial++;
							}
							else
							{
								mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << stoptime << endl;
								Serial++;
							}
						}
						cout << endl << endl;
					}
					else
					{
						for(i = 0; i < divide + 1; i++)
						{
							mycout << 'N' << Serial << ' ' << m_strAxis1 << 0 << ' ' << m_strAxis2 << (alpha1 + i * deltaalpha) << endl;
							Serial++;

							if(Serial == 2)
							{
								mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
								Serial++;
							}
							else
							{
								mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << stoptime << endl;
								Serial++;
							}
						}
						cout << endl << endl;
					}
				}
				else
				{
					//正向时且为A轴
					if(e == 0)
					{
						for(i = 0; i < divide + 1; i++)
						{
							mycout << 'N' << Serial << ' ' << m_strAxis1 << (alpha2 - i * deltaalpha) << ' ' << m_strAxis2 << 0 << endl;
							Serial++;

							if(Serial == 2)
							{
								mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
								Serial++;
							}
							else
							{
								mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << stoptime << endl;
								Serial++;
							}
						}
						cout << endl << endl;
					}
					else
					{
						for(i = 0; i < divide + 1; i++)
						{
							mycout << 'N' << Serial << ' ' << m_strAxis1 << 0 << ' ' << m_strAxis2 << (alpha2 - i * deltaalpha) << endl;
							Serial++;

							if(Serial == 2)
							{
								mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
								Serial++;
							}
							else
							{
								mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << stoptime << endl;
								Serial++;
							}
						}
						cout << endl << endl;
					}
				}
			}
		}
	}
	//动态测量
	else
	{
		for(j = 0; j < count; j++)
		{
			if(j % 2 == 0)
			{
				if(e == 0)
				{
					for(double alpha = alpha1; alpha < alpha2; alpha = alpha + 0.1)
					{
						mycout << 'N' << Serial << ' ' << m_strAxis1 << alpha << ' ' << m_strAxis2 << 0 << endl;
						Serial++;
					}
					cout << endl << endl;
				}
				else
				{
					for(double alpha = alpha1; alpha < alpha2; alpha = alpha + 0.1)
					{
						mycout << 'N' << Serial << ' ' << m_strAxis1 << 0 << ' ' << m_strAxis2 << alpha << endl;
						Serial++;
					}
					cout << endl << endl;
				}
			}
			else
			{
				if(d == 0)
				{
					//正向时且为A轴
					if(e == 0)
					{
						for(double alpha = alpha1; alpha < alpha2; alpha = alpha + 0.1)
						{
							mycout << 'N' << Serial << ' ' << m_strAxis1 << alpha << ' ' << m_strAxis2 << 0 << endl;
							Serial++;
						}

						cout << endl << endl;
					}
					else
					{
						for(double alpha = alpha1; alpha < alpha2; alpha = alpha + 0.1)
						{
							mycout << 'N' << Serial << ' ' << m_strAxis1 << 0 << ' ' << m_strAxis2 << alpha << endl;
							Serial++;
						}
						cout << endl << endl;
					}
				}
				else
				{
					if(e == 0)
					{
						for(double alpha = alpha2; alpha > alpha1; alpha = alpha - 0.1)
						{
							mycout << 'N' << Serial << ' ' << m_strAxis1 << alpha << ' ' << m_strAxis2 << 0 << endl;
							Serial++;
						}
						cout << endl << endl;
					}
					else
					{
						for(double alpha = alpha2; alpha > alpha1; alpha = alpha - 0.1)
						{
							mycout << 'N' << Serial << ' ' << m_strAxis1 << 0 << ' ' << m_strAxis2 << alpha << endl;
							Serial++;
						}
						cout << endl << endl;
					}
				}
			}
		}
	}
	mycout << 'N' << Serial << ' ' << m_strAxis1 << 0 << ' ' << m_strAxis2 << 0 << endl;
	mycout.close();
}

void Rtest_var::Trajectory_plan_linear(std::string szFile)
{
	int a = mode;
	double b = threshold;
	double c = stabletime;

	//int divide, int count
	int d = direc;
	int e = axis_num;
	double axis[15];

	for(int axis_setnum = 0; axis_setnum < 15; axis_setnum++)
	{
		axis[axis_setnum] = mutliaxis_set[axis_setnum];
	}

	ofstream mycout(szFile.c_str());
	int i;
	int j;
	int Serial = 1;

	double x_min = axis[0];
	double x_max = axis[1];
	double x_div = axis[2];
	double y_min = axis[3];
	double y_max = axis[4];
	double y_div = axis[5];
	double z_min = axis[6];
	double z_max = axis[7];
	double z_div = axis[8];
	double A_min = axis[9];
	double A_max = axis[10];
	double A_div = axis[11];
	double C_min = axis[12];
	double C_max = axis[13];
	double C_div = axis[14];

	vector<Point> data;
	Point p;

	if(e == 0)
	{
		for(double x = x_min + 0.1; x < x_max + 0.1; x = x + 0.1)
		{
			p.x = x;
			p.y = y_min;
			p.z = z_min;
			p.id = 1;
			data.push_back(p);
		}

		for(double y = y_min + 0.1; y < y_max + 0.1; y = y + 0.1)
		{
			p.x = x_max;
			p.y = y;
			p.z = z_min;
			p.id = 1;
			data.push_back(p);
		}

		for(double z = z_min + 0.1; z < z_max + 0.1; z = z + 0.1)
		{
			p.x = x_max;
			p.y = y_max;
			p.z = z;
			p.id = 1;
			data.push_back(p);
		}
	}
	else
	{
		for(i = 1; i < x_div + 1; i++)
		{
			p.x = x_min + (x_max - x_min) / x_div * (i - 1);
			p.y = y_min + (y_max - y_min) / y_div * (i - 1);
			p.z = z_min + (z_max - z_min) / z_div * (i - 1);
			p.id = 1;
			data.push_back(p);
		}
	}

	//单轴运动
	if(e == 0)
	{
		//静态测量
		if(a == 0)
		{
			//正反向重复
			for(j = 0; j < count; j++)
			{
				//判读正向或反向
				if(j % 2 == 0)
				{
					mycout << 'N' << Serial << ' ' << 'X' << x_min << ' ';
					mycout << 'Y' << y_min << ' ';
					mycout << 'Z' << z_min << ' ';
					mycout << m_strAxis1 << A_min << ' ';
					mycout << m_strAxis2 << C_min << ' ' << endl;
					Serial++;
					mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
					Serial++;

					//X轴
					for(i = 1; i < x_div + 1; i++)
					{
						mycout << 'N' << Serial << ' ' << 'X' << (x_min + (x_max - x_min) / x_div * i) << ' ';
						mycout << 'Y' << y_min << ' ';
						mycout << 'Z' << z_min << ' ';
						mycout << m_strAxis1 << A_min << ' ';
						mycout << m_strAxis2 << C_min << ' ' << endl;
						Serial++;

						if(Serial == 3)
						{
							mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
							Serial++;
						}
						else
						{
							mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << stoptime << endl;
							Serial++;
						}

					}

					//y轴
					for(i = 1; i < y_div + 1; i++)
					{
						mycout << 'N' << Serial << ' ' << 'X' << x_max << ' ';
						mycout << 'Y' << (y_min + (y_max - y_min) / y_div * i) << ' ';
						mycout << 'Z' << z_min << ' ';
						mycout << m_strAxis1 << A_min << ' ';
						mycout << m_strAxis2 << C_min << ' ' << endl;
						Serial++;

						if(Serial == 3)
						{
							mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
							Serial++;
						}
						else
						{
							mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << stoptime << endl;
							Serial++;
						}

					}

					//z轴
					for(i = 1; i < y_div + 1; i++)
					{
						mycout << 'N' << Serial << ' ' << 'X' << x_max << ' ';
						mycout << 'Y' << y_max << ' ';
						mycout << 'Z' << (z_min + (z_max - z_min) / z_div * i) << ' ';
						mycout << m_strAxis1 << A_min << ' ';
						mycout << m_strAxis2 << C_min << ' ' << endl;
						Serial++;

						if(Serial == 3)
						{
							mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
							Serial++;
						}
						else
						{
							mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << stoptime << endl;
							Serial++;
						}

					}

					//A轴
					for(i = 1; i < A_div + 1; i++)
					{
						mycout << 'N' << Serial << ' ' << 'X' << x_max << ' ';
						mycout << 'Y' << y_max << ' ';
						mycout << 'Z' << z_max << ' ';
						mycout << m_strAxis1 << (A_min + (A_max - A_min) / A_div * i) << ' ';
						mycout << m_strAxis2 << C_min << ' ' << endl;
						Serial++;

						if(Serial == 3)
						{
							mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
							Serial++;
						}
						else
						{
							mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << stoptime << endl;
							Serial++;
						}

					}

					//c轴
					for(i = 1; i < C_div + 1; i++)
					{
						mycout << 'N' << Serial << ' ' << 'X' << x_max << ' ';
						mycout << 'Y' << y_max << ' ';
						mycout << 'Z' << z_max << ' ';
						mycout << m_strAxis1 << A_max << ' ';
						mycout << m_strAxis2 << (C_min + (C_max - C_min) / C_div * i) << ' ' << endl;
						Serial++;

						if(Serial == 3)
						{
							mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
							Serial++;
						}
						else
						{
							mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << stoptime << endl;
							Serial++;
						}

					}

					cout << endl << endl;

				}

				else
				{
					if(d == 0)
					{
						mycout << 'N' << Serial << ' ' << 'X' << x_min << ' ';
						mycout << 'Y' << y_min << ' ';
						mycout << 'Z' << z_min << ' ';
						mycout << m_strAxis1 << A_min << ' ';
						mycout << m_strAxis2 << C_min << ' ' << endl;
						Serial++;
						mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
						Serial++;

						//X轴
						for(i = 1; i < x_div + 1; i++)
						{
							mycout << 'N' << Serial << ' ' << 'X' << (x_min + (x_max - x_min) / x_div * i) << ' ';
							mycout << 'Y' << y_min << ' ';
							mycout << 'Z' << z_min << ' ';
							mycout << m_strAxis1 << A_min << ' ';
							mycout << m_strAxis2 << C_min << ' ' << endl;
							Serial++;

							if(Serial == 3)
							{
								mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
								Serial++;
							}
							else
							{
								mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << stoptime << endl;
								Serial++;
							}

						}

						//y轴
						for(i = 1; i < y_div + 1; i++)
						{
							mycout << 'N' << Serial << ' ' << 'X' << x_max << ' ';
							mycout << 'Y' << (y_min + (y_max - y_min) / y_div * i) << ' ';
							mycout << 'Z' << z_min << ' ';
							mycout << m_strAxis1 << A_min << ' ';
							mycout << m_strAxis2 << C_min << ' ' << endl;
							Serial++;

							if(Serial == 3)
							{
								mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
								Serial++;
							}
							else
							{
								mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << stoptime << endl;
								Serial++;
							}

						}

						//z轴
						for(i = 1; i < y_div + 1; i++)
						{
							mycout << 'N' << Serial << ' ' << 'X' << x_max << ' ';
							mycout << 'Y' << y_max << ' ';
							mycout << 'Z' << (z_min + (z_max - z_min) / z_div * i) << ' ';
							mycout << m_strAxis1 << A_min << ' ';
							mycout << m_strAxis2 << C_min << ' ' << endl;
							Serial++;

							if(Serial == 3)
							{
								mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
								Serial++;
							}
							else
							{
								mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << stoptime << endl;
								Serial++;
							}

						}

						//A轴
						for(i = 1; i < A_div + 1; i++)
						{
							mycout << 'N' << Serial << ' ' << 'X' << x_max << ' ';
							mycout << 'Y' << y_max << ' ';
							mycout << 'Z' << z_max << ' ';
							mycout << m_strAxis1 << (A_min + (A_max - A_min) / A_div * i) << ' ';
							mycout << m_strAxis2 << C_min << ' ' << endl;
							Serial++;

							if(Serial == 3)
							{
								mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
								Serial++;
							}
							else
							{
								mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << stoptime << endl;
								Serial++;
							}

						}

						//c轴
						for(i = 1; i < C_div + 1; i++)
						{
							mycout << 'N' << Serial << ' ' << 'X' << x_max << ' ';
							mycout << 'Y' << y_max << ' ';
							mycout << 'Z' << z_max << ' ';
							mycout << m_strAxis1 << A_max << ' ';
							mycout << m_strAxis2 << (C_min + (C_max - C_min) / C_div * i) << ' ' << endl;
							Serial++;

							if(Serial == 3)
							{
								mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
								Serial++;
							}
							else
							{
								mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << stoptime << endl;
								Serial++;
							}

						}

						cout << endl << endl;
					}
					else
					{
						mycout << 'N' << Serial << ' ' << 'X' << x_max << ' ';
						mycout << 'Y' << y_max << ' ';
						mycout << 'Z' << z_max << ' ';
						mycout << m_strAxis1 << A_max << ' ';
						mycout << m_strAxis2 << C_max << ' ' << endl;
						Serial++;
						mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
						Serial++;

						//C轴
						for(i = 1; i < C_div + 1; i++)
						{
							mycout << 'N' << Serial << ' ' << 'X' << x_max << ' ';
							mycout << 'Y' << y_max << ' ';
							mycout << 'Z' << z_max << ' ';
							mycout << m_strAxis1 << A_max << ' ';
							mycout << m_strAxis2 << (C_max - (C_max - C_min) / C_div * i) << ' ' << endl;
							Serial++;

							if(Serial == 3)
							{
								mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
								Serial++;
							}
							else
							{
								mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << stoptime << endl;
								Serial++;
							}

						}

						//A轴
						for(i = 1; i < A_div + 1; i++)
						{
							mycout << 'N' << Serial << ' ' << 'X' << x_max << ' ';
							mycout << 'Y' << y_max << ' ';
							mycout << 'Z' << z_max << ' ';
							mycout << m_strAxis1 << (A_max - (A_max - A_min) / A_div * i) << ' ';
							mycout << m_strAxis2 << C_min << ' ' << endl;
							Serial++;

							if(Serial == 3)
							{
								mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
								Serial++;
							}
							else
							{
								mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << stoptime << endl;
								Serial++;
							}

						}

						//z轴
						for(i = 1; i < z_div + 1; i++)
						{
							mycout << 'N' << Serial << ' ' << 'X' << x_max << ' ';
							mycout << 'Y' << y_max << ' ';
							mycout << 'Z' << (z_max - (z_max - z_min) / z_div * i) << ' ';
							mycout << m_strAxis1 << A_min << ' ';
							mycout << m_strAxis2 << C_min << ' ' << endl;
							Serial++;

							if(Serial == 3)
							{
								mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
								Serial++;
							}
							else
							{
								mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << stoptime << endl;
								Serial++;
							}

						}

						//y轴
						for(i = 1; i < y_div + 1; i++)
						{
							mycout << 'N' << Serial << ' ' << 'X' << x_max << ' ';
							mycout << 'Y' << (y_max - (y_max - y_min) / y_div * i) << ' ';
							mycout << 'Z' << z_min << ' ';
							mycout << m_strAxis1 << A_min << ' ';
							mycout << m_strAxis2 << C_min << ' ' << endl;
							Serial++;

							if(Serial == 3)
							{
								mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
								Serial++;
							}
							else
							{
								mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << stoptime << endl;
								Serial++;
							}

						}

						//x轴
						for(i = 1; i < x_div + 1; i++)
						{
							mycout << 'N' << Serial << ' ' << 'X' << (x_max - (x_max - x_min) / x_div * i) << ' ';
							mycout << 'Y' << y_min << ' ';
							mycout << 'Z' << z_min << ' ';
							mycout << m_strAxis1 << A_min << ' ';
							mycout << m_strAxis2 << C_min << ' ' << endl;
							Serial++;

							if(Serial == 3)
							{
								mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
								Serial++;
							}
							else
							{
								mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << stoptime << endl;
								Serial++;
							}

						}

						cout << endl << endl;
					}

				}

			}
		}
		//动态测量
		else
		{
			//正反向重复
			for(j = 0; j < count; j++)
			{
				//判读正向或反向
				if(j % 2 == 0)
				{
					mycout << 'N' << Serial << ' ' << 'X' << x_min << ' ';
					mycout << 'Y' << y_min << ' ';
					mycout << 'Z' << z_min << ' ';
					mycout << m_strAxis1 << A_min << ' ';
					mycout << m_strAxis2 << C_min << ' ' << endl;
					Serial++;
					mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
					Serial++;

					//X轴
					for(double x = x_min + 0.1; x < x_max + 0.02; x = x + 0.1)
					{
						mycout << 'N' << Serial << ' ' << 'X' << x << ' ';
						mycout << 'Y' << y_min << ' ';
						mycout << 'Z' << z_min << ' ';
						mycout << m_strAxis1 << A_min << ' ';
						mycout << m_strAxis2 << C_min << ' ' << endl;
						Serial++;

						if(Serial == 3)
						{
							mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
							Serial++;
						}
						else
						{
							mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << stoptime << endl;
							Serial++;
						}

					}

					//y轴
					for(double y = y_min + 0.1; y < y_max + 0.02; y = y + 0.1)
					{
						mycout << 'N' << Serial << ' ' << 'X' << x_max << ' ';
						mycout << 'Y' << y << ' ';
						mycout << 'Z' << z_min << ' ';
						mycout << m_strAxis1 << A_min << ' ';
						mycout << m_strAxis2 << C_min << ' ' << endl;
						Serial++;

						if(Serial == 3)
						{
							mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
							Serial++;
						}
						else
						{
							mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << stoptime << endl;
							Serial++;
						}

					}

					//z轴
					for(double z = z_min + 0.1; z < z_max + 0.02; z = z + 0.1)
					{
						mycout << 'N' << Serial << ' ' << 'X' << x_max << ' ';
						mycout << 'Y' << y_max << ' ';
						mycout << 'Z' << z << ' ';
						mycout << m_strAxis1 << A_min << ' ';
						mycout << m_strAxis2 << C_min << ' ' << endl;
						Serial++;

						if(Serial == 3)
						{
							mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
							Serial++;
						}
						else
						{
							mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << stoptime << endl;
							Serial++;
						}

					}

					//A轴
					for(double A = A_min + 0.1; A < A_max + 0.02; A = A + 0.1)
					{
						mycout << 'N' << Serial << ' ' << 'X' << x_max << ' ';
						mycout << 'Y' << y_max << ' ';
						mycout << 'Z' << z_max << ' ';
						mycout << m_strAxis1 << A << ' ';
						mycout << m_strAxis2 << C_min << ' ' << endl;
						Serial++;

						if(Serial == 3)
						{
							mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
							Serial++;
						}
						else
						{
							mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << stoptime << endl;
							Serial++;
						}

					}

					//c轴
					for(double C = C_min + 0.1; C < C_max + 0.02; C = C + 0.1)
					{
						mycout << 'N' << Serial << ' ' << 'X' << x_max << ' ';
						mycout << 'Y' << y_max << ' ';
						mycout << 'Z' << z_max << ' ';
						mycout << m_strAxis1 << A_max << ' ';
						mycout << m_strAxis2 << C << ' ' << endl;
						Serial++;

						if(Serial == 3)
						{
							mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
							Serial++;
						}
						else
						{
							mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << stoptime << endl;
							Serial++;
						}

					}

					cout << endl << endl;

				}

				else
				{
					if(d == 0)
					{
						mycout << 'N' << Serial << ' ' << 'X' << x_min << ' ';
						mycout << 'Y' << y_min << ' ';
						mycout << 'Z' << z_min << ' ';
						mycout << m_strAxis1 << A_min << ' ';
						mycout << m_strAxis2 << C_min << ' ' << endl;
						Serial++;
						mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
						Serial++;

						//X轴
						for(double x = x_min + 0.1; x < x_max + 0.02; x = x + 0.1)
						{
							mycout << 'N' << Serial << ' ' << 'X' << x << ' ';
							mycout << 'Y' << y_min << ' ';
							mycout << 'Z' << z_min << ' ';
							mycout << m_strAxis1 << A_min << ' ';
							mycout << m_strAxis2 << C_min << ' ' << endl;
							Serial++;

							if(Serial == 3)
							{
								mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
								Serial++;
							}
							else
							{
								mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << stoptime << endl;
								Serial++;
							}

						}

						//y轴
						for(double y = y_min + 0.1; y < y_max + 0.02; y = y + 0.1)
						{
							mycout << 'N' << Serial << ' ' << 'X' << x_max << ' ';
							mycout << 'Y' << y << ' ';
							mycout << 'Z' << z_min << ' ';
							mycout << m_strAxis1 << A_min << ' ';
							mycout << m_strAxis2 << C_min << ' ' << endl;
							Serial++;

							if(Serial == 3)
							{
								mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
								Serial++;
							}
							else
							{
								mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << stoptime << endl;
								Serial++;
							}

						}

						//z轴
						for(double z = z_min + 0.1; z < z_max + 0.02; z = z + 0.1)
						{
							mycout << 'N' << Serial << ' ' << 'X' << x_max << ' ';
							mycout << 'Y' << y_max << ' ';
							mycout << 'Z' << z << ' ';
							mycout << m_strAxis1 << A_min << ' ';
							mycout << m_strAxis2 << C_min << ' ' << endl;
							Serial++;

							if(Serial == 3)
							{
								mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
								Serial++;
							}
							else
							{
								mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << stoptime << endl;
								Serial++;
							}

						}

						//A轴
						for(double A = A_min + 0.1; A < A_max + 0.02; A = A + 0.1)
						{
							mycout << 'N' << Serial << ' ' << 'X' << x_max << ' ';
							mycout << 'Y' << y_max << ' ';
							mycout << 'Z' << z_max << ' ';
							mycout << m_strAxis1 << A << ' ';
							mycout << m_strAxis2 << C_min << ' ' << endl;
							Serial++;

							if(Serial == 3)
							{
								mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
								Serial++;
							}
							else
							{
								mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << stoptime << endl;
								Serial++;
							}

						}

						//c轴
						for(double C = C_min + 0.1; C < C_max + 0.02; C = C + 0.1)
						{
							mycout << 'N' << Serial << ' ' << 'X' << x_max << ' ';
							mycout << 'Y' << y_max << ' ';
							mycout << 'Z' << z_max << ' ';
							mycout << m_strAxis1 << A_max << ' ';
							mycout << m_strAxis2 << C << ' ' << endl;
							Serial++;

							if(Serial == 3)
							{
								mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
								Serial++;
							}
							else
							{
								mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << stoptime << endl;
								Serial++;
							}

						}

						cout << endl << endl;
					}
					else
					{
						mycout << 'N' << Serial << ' ' << 'X' << x_max << ' ';
						mycout << 'Y' << y_max << ' ';
						mycout << 'Z' << z_max << ' ';
						mycout << m_strAxis1 << A_max << ' ';
						mycout << m_strAxis2 << C_max << ' ' << endl;
						Serial++;
						mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
						Serial++;

						//C轴
						for(double C = C_max - 0.1; C > C_min - 0.02; C = C - 0.1)
						{
							mycout << 'N' << Serial << ' ' << 'X' << x_max << ' ';
							mycout << 'Y' << y_max << ' ';
							mycout << 'Z' << z_max << ' ';
							mycout << m_strAxis1 << A_max << ' ';
							mycout << m_strAxis2 << C << ' ' << endl;
							Serial++;

							if(Serial == 3)
							{
								mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
								Serial++;
							}
							else
							{
								mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << stoptime << endl;
								Serial++;
							}

						}

						//A轴
						for(double A = A_max - 0.1; A > A_min - 0.02; A = A - 0.1)
						{
							mycout << 'N' << Serial << ' ' << 'X' << x_max << ' ';
							mycout << 'Y' << y_max << ' ';
							mycout << 'Z' << z_max << ' ';
							mycout << m_strAxis1 << A << ' ';
							mycout << m_strAxis2 << C_min << ' ' << endl;
							Serial++;

							if(Serial == 3)
							{
								mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
								Serial++;
							}
							else
							{
								mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << stoptime << endl;
								Serial++;
							}

						}

						//z轴
						for(double z = z_max - 0.1; z > z_min - 0.02; z = z - 0.1)
						{
							mycout << 'N' << Serial << ' ' << 'X' << x_max << ' ';
							mycout << 'Y' << y_max << ' ';
							mycout << 'Z' << z << ' ';
							mycout << m_strAxis1 << A_min << ' ';
							mycout << m_strAxis2 << C_min << ' ' << endl;
							Serial++;

							if(Serial == 3)
							{
								mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
								Serial++;
							}
							else
							{
								mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << stoptime << endl;
								Serial++;
							}

						}

						//y轴
						for(double y = y_max - 0.1; y > y_min - 0.02; y = y - 0.1)
						{
							mycout << 'N' << Serial << ' ' << 'X' << x_max << ' ';
							mycout << 'Y' << y << ' ';
							mycout << 'Z' << z_min << ' ';
							mycout << m_strAxis1 << A_min << ' ';
							mycout << m_strAxis2 << C_min << ' ' << endl;
							Serial++;

							if(Serial == 3)
							{
								mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
								Serial++;
							}
							else
							{
								mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << stoptime << endl;
								Serial++;
							}

						}

						//x轴
						for(double x = x_max - 0.1; x > x_min - 0.02; x = x - 0.1)
						{
							mycout << 'N' << Serial << ' ' << 'X' << x << ' ';
							mycout << 'Y' << y_min << ' ';
							mycout << 'Z' << z_min << ' ';
							mycout << m_strAxis1 << A_min << ' ';
							mycout << m_strAxis2 << C_min << ' ' << endl;
							Serial++;

							if(Serial == 3)
							{
								mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
								Serial++;
							}
							else
							{
								mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << stoptime << endl;
								Serial++;
							}

						}

						cout << endl << endl;
					}

				}

			}
		}
	}



	//多轴运动
	else
	{
		//静态测量
		if(a == 0)
		{
			//正反向重复
			for(j = 0; j < count; j++)
			{
				//判读正向或反向
				if(j % 2 == 0)
				{
					mycout << 'N' << Serial << ' ' << 'X' << x_min << ' ';
					mycout << 'Y' << y_min << ' ';
					mycout << 'Z' << z_min << ' ';
					mycout << m_strAxis1 << A_min << ' ';
					mycout << m_strAxis2 << C_min << ' ' << endl;
					Serial++;
					mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
					Serial++;

					//X轴
					for(i = 1; i < x_div + 1; i++)
					{
						mycout << 'N' << Serial << ' ' << 'X' << (x_min + (x_max - x_min) / x_div * i) << ' ';
						mycout << 'Y' << (y_min + (y_max - y_min) / y_div * i) << ' ';
						mycout << 'Z' << (z_min + (z_max - z_min) / z_div * i) << ' ';
						mycout << m_strAxis1 << (A_min + (A_max - A_min) / A_div * i) << ' ';
						mycout << m_strAxis2 << (C_min + (C_max - C_min) / C_div * i) << ' ' << endl;
						Serial++;

						if(Serial == 3)
						{
							mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
							Serial++;
						}
						else
						{
							mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << stoptime << endl;
							Serial++;
						}

					}

					cout << endl << endl;

				}

				else
				{
					if(d == 0)
					{
						mycout << 'N' << Serial << ' ' << 'X' << x_min << ' ';
						mycout << 'Y' << y_min << ' ';
						mycout << 'Z' << z_min << ' ';
						mycout << m_strAxis1 << A_min << ' ';
						mycout << m_strAxis2 << C_min << ' ' << endl;
						Serial++;
						mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
						Serial++;

						//X轴
						for(i = 1; i < x_div + 1; i++)
						{
							mycout << 'N' << Serial << ' ' << 'X' << (x_min + (x_max - x_min) / x_div * i) << ' ';
							mycout << 'Y' << (y_min + (y_max - y_min) / y_div * i) << ' ';
							mycout << 'Z' << (z_min + (z_max - z_min) / z_div * i) << ' ';
							mycout << m_strAxis1 << (A_min + (A_max - A_min) / A_div * i) << ' ';
							mycout << m_strAxis2 << (C_min + (C_max - C_min) / C_div * i) << ' ' << endl;
							Serial++;

							if(Serial == 3)
							{
								mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
								Serial++;
							}
							else
							{
								mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << stoptime << endl;
								Serial++;
							}

						}

						cout << endl << endl;

					}
					else
					{
						mycout << 'N' << Serial << ' ' << 'X' << x_max << ' ';
						mycout << 'Y' << y_max << ' ';
						mycout << 'Z' << z_max << ' ';
						mycout << m_strAxis1 << A_max << ' ';
						mycout << m_strAxis2 << C_max << ' ' << endl;
						Serial++;
						mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
						Serial++;

						//C轴
						for(i = 1; i < C_div + 1; i++)
						{
							mycout << 'N' << Serial << ' ' << 'X' << (x_max - (x_max - x_min) / x_div * i) << ' ';
							mycout << 'Y' << (y_max - (y_max - y_min) / y_div * i) << ' ';
							mycout << 'Z' << (z_max - (z_max - z_min) / z_div * i) << ' ';
							mycout << m_strAxis1 << (A_max - (A_max - A_min) / A_div * i) << ' ';
							mycout << m_strAxis2 << (C_max - (C_max - C_min) / C_div * i) << ' ' << endl;
							Serial++;

							if(Serial == 3)
							{
								mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
								Serial++;
							}
							else
							{
								mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << stoptime << endl;
								Serial++;
							}

						}

						cout << endl << endl;
					}

				}

			}
		}


		//动态测量
		else
		{
			//正反向重复
			for(j = 0; j < count; j++)
			{
				//判读正向或反向
				if(j % 2 == 0)
				{
					mycout << 'N' << Serial << ' ' << 'X' << x_min << ' ';
					mycout << 'Y' << y_min << ' ';
					mycout << 'Z' << z_min << ' ';
					mycout << m_strAxis1 << A_min << ' ';
					mycout << m_strAxis2 << C_min << ' ' << endl;
					Serial++;
					mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
					Serial++;
					mycout << 'N' << Serial << ' ' << 'X' << x_max << ' ';
					mycout << 'Y' << y_max << ' ';
					mycout << 'Z' << z_max << ' ';
					mycout << m_strAxis1 << A_max << ' ';
					mycout << m_strAxis2 << C_max << ' ' << endl;
					Serial++;
					mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
					Serial++;
				}

				else
				{
					if(d == 0)
					{
						mycout << 'N' << Serial << ' ' << 'X' << x_min << ' ';
						mycout << 'Y' << y_min << ' ';
						mycout << 'Z' << z_min << ' ';
						mycout << m_strAxis1 << A_min << ' ';
						mycout << m_strAxis2 << C_min << ' ' << endl;
						Serial++;
						mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
						Serial++;
						mycout << 'N' << Serial << ' ' << 'X' << x_max << ' ';
						mycout << 'Y' << y_max << ' ';
						mycout << 'Z' << z_max << ' ';
						mycout << m_strAxis1 << A_max << ' ';
						mycout << m_strAxis2 << C_max << ' ' << endl;
						Serial++;
						mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
						Serial++;

						cout << endl << endl;
					}
					else
					{
						mycout << 'N' << Serial << ' ' << 'X' << x_max << ' ';
						mycout << 'Y' << y_max << ' ';
						mycout << 'Z' << z_max << ' ';
						mycout << m_strAxis1 << A_max << ' ';
						mycout << m_strAxis2 << C_max << ' ' << endl;
						Serial++;
						mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
						Serial++;
						mycout << 'N' << Serial << ' ' << 'X' << x_min << ' ';
						mycout << 'Y' << y_min << ' ';
						mycout << 'Z' << z_min << ' ';
						mycout << m_strAxis1 << A_min << ' ';
						mycout << m_strAxis2 << C_min << ' ' << endl;
						Serial++;
						mycout << 'N' << Serial << ' ' << 'G' << '0' << '4' << ' ' << 'F' << '5' << endl;
						Serial++;
						cout << endl << endl;
					}

				}

			}
		}
	}
	mycout.close();
}

//----------------------------------------------------------------------
void Rtest_var::save_try(vector<Point>& data_read) {
	for (auto p : data_read) {
		p.x = p.x / 2;
		p.y = p.y / 2;
		p.z = p.z / 2;
	}
	datasave(data_read, "ooo");
	error_cal(0);

	
}
//数据保存
void Rtest_var::datasave(vector<Point> &data, std::string szFile)
{
	vector<Point> dataraw = data;
	vector<Point> datadeal;
	datadeal = Tran_data(data);
	int n = datadeal.size();
	//--------------------------------------------------------------------
	//Autor: Qian dehou
	//Version : 1.0
	//Date : 2020 - 3 - 26

	bool judge1 = false; //Z轴抬起至上方1mm位置
	bool judge2 = false; //Z轴伸长至0点
	bool judge3 = false; //Z轴抬起至上方1mm位置
	//--------------------------------------------------------
	//	fre = 40; //采样频率
	// F=200；//机床进给
	//抬起或伸长产生采样点数：(1/200)*60*40=12
	//经过阈值之后的采样点数：12*0.6=7.2
	//------------------------------------------------------------
	int freq = 40; //采样频率40个点每秒
	int cut_num_points = freq * 1;//过渡时间1秒，往后或往前40个点
	//增加初始值偏差以解决R-test装置弹出时零点偏差的问题
	double initial_x = 0;
	double initial_y = 0;
	double initial_z = 0;
	// Qiandehou  2020-03-26 
	//-------------------------------------------------------------------------------------------

	int start_num0 = 0;
	int start_num = 0;
	int end_num = 0;

	double thre_clarify = 0.8;
	//判断起始结束
	for (int serial = 0; serial < n-5; serial++)
	{
		if (judge1==false&&data[serial].z > thre_clarify)
		{
				//判断之前7个点是否都小于阈值
				//容许波动为0.1
				bool flag = true;
				for (int i = 1; i <= 7; i++) {
					if (serial - i < 0 || data[serial - i].z > thre_clarify + 0.1) {
						flag = false;
					}
				}
				//判断之后5个点是否都大于阈值
				//容许波动为0.1
				for (int i = 1; i <= 5; i++) {
					if (serial + i >= data.size() || data[serial + i].z < thre_clarify - 0.1) {
						flag = false;
					}
				}
				if (judge1 == false&&flag==true)
				{
					judge1 = true; //机床Z轴抬起
					start_num0 = serial+cut_num_points;
				}
		}

		if (judge1 == true&&judge2==false)
		{
			if ((data[serial].z < thre_clarify))
			{
				//判断之后7个点是否都小于阈值
				//容许波动为0.1
				bool flag = true;
				for (int i = 1; i <= 7; i++) {
					if(serial+i>data.size()||data[serial+i].z>thre_clarify+0.1){
						flag = false;
					}
				}
				//判断之前5个点是否都大于阈值
				//容许波动为0.1
				for (int i = 1; i <= 5; i++) {
					if (serial-i<0||data[serial - i].z < thre_clarify - 0.1) {
						flag = false;
					}
				}

				if (judge2 == false&&flag==true)
				{
					judge2 = true; //机床Z轴落下
					start_num = serial + cut_num_points; //获取机床运动数据起始采集位置					
				}
			}
		}
		if (judge1==true&&judge2==true&&judge3==false)
		{
			if (data[serial].z > thre_clarify)
			{
				//判断之前7个点是否都小于阈值
				//容许波动为0.1
				bool flag = true;
				for (int i = 1; i <= 7; i++) {
					if (serial - i < 0 || data[serial - i].z > thre_clarify + 0.1) {
						flag = false;
					}
				}
				//判断之后5个点是否都大于阈值
				//容许波动为0.1
				for (int i = 1; i <= 5; i++) {
					if (serial + i >= data.size() || data[serial + i].z < thre_clarify - 0.1) {
						flag = false;
					}
				}
				if (flag == false) {
					judge3 = true; //机床Z轴再次抬起
					end_num = serial - cut_num_points;
				}
			}
		}

	}


	//减去测量数据中的初始零点偏差
	int total_num = start_num0 - fre * 2 + 1;
	for (int i = fre; i < start_num0 - fre; i++) {
		initial_x += data[i].x / total_num;
		initial_y += data[i].y / total_num;
		initial_z += data[i].z / total_num;
	}
	for (int i = 0; i < data.size(); i++) {
		data[i].x -= initial_x;
		data[i].y -= initial_y;
		data[i].z -= initial_z;
	}
	//----------------------------------------------------------------------------------------------------
	ofstream mycout("temp_linear_res.txt");

	for (int i = start_num; i < end_num; i++)
	{
		data_read_todeal.push_back(data[i]);//储存处理后的数据
		mycout << data[i].x << ' ' << data[i].y << ' ' << data[i].z << ' ' << data[i].id << endl;
	}
	mycout.close();
}

//静态数据保存
void Rtest_var::datasave_static(vector<Point> &data, std::string szFile)
{
	vector<Point> dataraw = data;
	vector<Point> datadeal;
	datadeal = Tran_data(data);
	int n = datadeal.size();

	//int judge1 = 0;
	//int judge2 = 0;
	//int judge3 = 0;

	//double start_num = 0;
	//double end_num = 0;

	//double thre_clarify = 0.3;
	////判断起始结束
	//for (int serial = 0; serial < n - 5; serial++)
	//{
	//	if (data[serial].z > thre_clarify)
	//	{
	//		if (judge1 == 0)
	//		{
	//			judge1 = 1;
	//		}
	//	}
	//	if (judge1 == 1)
	//	{
	//		if ((data[serial].z < thre_clarify) && (data[serial + 1].z < thre_clarify) && (data[serial + 2].z < thre_clarify))
	//		{
	//			if (judge2 == 0)
	//			{
	//				judge2 = 1;
	//			}
	//		}
	//	}
	//	if (judge1 == 1)
	//	{
	//		if (judge2 == 1)
	//		{
	//			if (data[serial].z < data[serial + 1].z)
	//			{
	//				start_num = serial + 10;
	//				break;
	//			}
	//		}
	//	}

	//}
	//for (double serial2 = start_num; serial2 < n - 5; serial2++)
	//{

	//	if (judge3 == 0)
	//	{
	//		if (abs(data[serial2].z) >thre_clarify)
	//		{
	//			judge3 = 1;
	//			end_num = serial2;
	//		}
	//	}
	//}
	//--------------------------------------------------------------------
    //Autor: Qian dehou
	//Version : 1.0
	//Date : 2020 - 3 - 26
	bool judge1 = false; //Z轴抬起至上方1mm位置
	bool judge2 = false; //Z轴伸长至0点
	bool judge3 = false; //Z轴抬起至上方1mm位置
	//--------------------------------------------------------
	//	fre = 40; //采样频率
	// F=200；//机床进给
	//抬起或伸长产生采样点数：(1/200)*60*40=12
	//经过阈值之后的采样点数：12*0.6=7.2
	//------------------------------------------------------------
	int start_num0 = 0;
	int start_num = 0;
	int end_num = 0;

	int thre_clarify = 0.6;
	//判断起始结束
	for (int serial = 0; serial < n - 5; serial++)
	{
		if (judge1 == false && data[serial].z > thre_clarify)
		{
			//判断之前7个点是否都小于阈值
			//容许波动为0.1
			bool flag = true;
			for (int i = 1; i <= 7; i++) {
				if (serial - i < 0 || data[serial - i].z > thre_clarify + 0.1) {
					flag = false;
				}
			}
			//判断之后5个点是否都大于阈值
			//容许波动为0.1
			for (int i = 1; i <= 5; i++) {
				if (serial + i >= data.size() || data[serial + i].z < thre_clarify - 0.1) {
					flag = false;
				}
			}
			if (judge1 == false && flag == true)
			{
				judge1 = true; //机床Z轴抬起
				start_num0 = serial;
			}
		}

		if (judge1 == true)
		{
			if ((data[serial].z < thre_clarify))
			{
				//判断之后7个点是否都小于阈值
				//容许波动为0.1
				bool flag = true;
				for (int i = 1; i <= 7; i++) {
					if (serial + i > data.size() || data[serial + i].z > thre_clarify + 0.1) {
						flag = false;
					}
				}
				//判断之前5个点是否都大于阈值
				//容许波动为0.1
				for (int i = 1; i <= 5; i++) {
					if (serial - i < 0 || data[serial - i].z < thre_clarify - 0.1) {
						flag = false;
					}
				}

				if (judge2 == false && flag == true)
				{
					judge2 = true; //机床Z轴落下
					start_num = serial + 10; //获取机床运动数据起始采集位置
					break;
				}
			}
		}
	}

	for (int serial2 = start_num; serial2 < n - 5; serial2++)
	{
		if (judge3 == false)
		{
			if (abs(data[serial2].z) < thre_clarify)
			{
				//判断之前7个点是否都小于阈值
				//容许波动为0.1
				bool flag = true;
				for (int i = 1; i <= 7; i++) {
					if (serial2 - i < 0 || data[serial2 - i].z > thre_clarify + 0.1) {
						flag = false;
					}
				}
				//判断之后5个点是否都大于阈值
				//容许波动为0.1
				for (int i = 1; i <= 5; i++) {
					if (serial2 + i >= data.size() || data[serial2 + i].z < thre_clarify - 0.1) {
						flag = false;
					}
				}
				if (flag == false) {
					judge3 = true; //机床Z轴再次抬起
					end_num = serial2 - 10;
				}
			}
		}


	}

	//----------------------------------------------------------------------------------------------

	double judgenum = fre*stabletime;  //阈值时间对应采样点数

	//----------------------------------------------------------------------------------------
	//增加初始值偏差以解决R-test装置弹出时零点偏差的问题
	double initial_x = 0;
	double initial_y = 0;
	double initial_z = 0;
	// Qiandehou  2020-03-26 
	//-------------------------------------------------------------------------------------------
	double ave_x = 0;
	double ave_y = 0;
	double ave_z = 0;

	double delta_x = 0;
	double delta_y = 0;
	double delta_z = 0;

	double maxdelta_x = 0; double maxdelta_y = 0; double maxdelta_z = 0;

	double serial3 = 0;

	int judge_outnum= fre*5/2;

	int sign1 = 0;
	int sign2 = 0;
	int sign3 = 0;

	//减去测量数据中的初始零点偏差
	int total_num = start_num0 - fre * 2 + 1;
	for (int i = fre; i < start_num0 - fre; i++) {
		initial_x += data[i].x / total_num;
		initial_y += data[i].y / total_num;
		initial_z += data[i].z / total_num;
	}
	
	for (int i = 0; i < data.size();i++) {
		data[i].x -= initial_x;
		data[i].y -= initial_y;
		data[i].z -= initial_z;
	}

	//这里是截取的有效数据部分（动态的连续点数据）
	ofstream mycout1("temp_linear_unchoose.txt");
	for (int i = start_num;i <end_num; i++)
	{
		mycout1 << data[i].x << ' ' << data[i].y << ' ' << data[i].z << ' ' << data[i].id << endl;
	}

	mycout1.close();


	//这里是静态取点的结果
	ofstream mycout("temp_linear_choose.txt");
	for (double serial2 = start_num; serial2 <end_num - judgenum - 5; )
	{
		ave_x = 0;
		ave_y = 0;
		ave_z = 0;
		maxdelta_x = 0; maxdelta_y = 0; maxdelta_z = 0;

		for (serial3 = serial2; serial3 <serial2 + judgenum; serial3++)
		{
			ave_x = ave_x + data[serial3].x;
			ave_y = ave_y + data[serial3].y;
			ave_z = ave_z + data[serial3].z;

		}
		//judgenum 这些点内，xyz方向的平均值
		ave_x = ave_x / judgenum;
		ave_y = ave_y / judgenum;
		ave_z = ave_z / judgenum;


		for (serial3 = serial2; serial3 <serial2 + judgenum; serial3++)
		{
			//judge num在这些点内，xyz方向的值与平均值之差
			delta_x = abs(data[serial3].x - ave_x);
			delta_y = abs(data[serial3].y - ave_y);
			delta_z = abs(data[serial3].z - ave_z);

			//记录其各个方向最大平均值之差
			if ((delta_x > maxdelta_x) || (delta_y > maxdelta_y) || (delta_z > maxdelta_z))
			{
				maxdelta_x = delta_x; maxdelta_y = delta_y; maxdelta_z = delta_z;

			}
		}

		if ((threshold > maxdelta_x) && (threshold > maxdelta_y) && (threshold > maxdelta_z))
		{//如果这些值与其均值之差均小于阈值threshold
		 //则将其写入
	    //--------------------------------------------------------------------------------------------------------------
		//	mycout << ave_x << ' ' << ave_y << ' ' << ave_z << ' ' << data[serial2].id << endl;
	    //--------------------------------------------------------------------------------------------------------------    

			for (double k = serial2 + judgenum; k < end_num - judge_outnum-1; k++)
			{//分析下一段judgenum个数点的情况

				//X
				for (int h = k; h < k + judge_outnum; h++)
				{
					if (abs(data[h].x - ave_x) > threshold)
					{//该点与上一段均值比较，若大于该均值，则计数+1
						sign1++;
					}
					
				}

				if (sign1 > judge_outnum - 5)
				{//基本大于上一段均值，且插值超过阈值的点数
				//之差小于阈值的少于5个点
					sign1 = 1;
				}
				else
				{
					sign1 = 0;
				}



				//Y
				for (int h = k; h < k + judge_outnum; h++)
				{
					if (abs(data[h].y - ave_y) > threshold)
					{
						sign2++;
					}

				}
				if (sign2 > judge_outnum - 5)
				{
					sign2 = 1;
				}
				else
				{
					sign2 = 0;
				}

				//Z
				for (int h = k; h < k + judge_outnum; h++)
				{
					if (abs(data[h].z - ave_z) > threshold)
					{
						sign3++;
					}

				}
				if (sign3 > judge_outnum - 5)
				{
					sign3 = 1;
				}
				else
				{
					sign3 = 0;
				}




				if ((sign1 > 0) || (sign2 > 0) || (sign3 > 0))
				{
					serial2 = k;
					break;
				}
				else
				{
					serial2++;
					sign1 = 0;
					sign2 = 0;
					sign3 = 0;
				}

			}
		}
		else
		{
			serial2++;
		}
	}

	mycout.close();

}


void Rtest_var::dataread(std::string szFile)
{
	
	
	ifstream myin(szFile.c_str());

	
	Point data;
	vector<Point> Data_Measure;

	while(!myin.eof())            // 这里的判断修改一下，直接判断文件结尾
	{
		myin >> data.x >> data.y >> data.z >> data.id;

		if(myin.eof())
			break;

		Data_Measure.push_back(data);
	}

	data_read = Data_Measure;
	save_try(Data_Measure);
}

//数据分析
void Rtest_var::error_cal(int nAxisSel)
{
	cal_axis = nAxisSel;
	if(cal_axis == 0)
	{
		rotate_error_cal(data_read_todeal);
	}
	else
	{
		syn_error_cal(data_read_todeal);
	}
}

void Rtest_var::rotate_error_cal(vector<Point> &data)
{
	Plane p;
	p.v_x = 0;

	Circle fitted_circle1;

	Point point_theory;//理论坐标
	Point point_fit;//拟合坐标

	data_fit.clear();
	data_theory.clear();
	double rotate_count;

	fitting_plane_by_LSM(data, p);

	Matrix3d TranposeMatrix_fit; //初始化为单位矩阵
	TranposeMatrix_fit(0, 0) = 0;
	TranposeMatrix_fit(1, 0) = -p.v_z;
	TranposeMatrix_fit(2, 0) = -p.v_y;
	TranposeMatrix_fit(0, 1) = p.v_z*p.v_z - p.v_y*p.v_y;
	TranposeMatrix_fit(1, 1) = p.v_x*p.v_y;
	TranposeMatrix_fit(2, 1) = -p.v_x*p.v_z;
	TranposeMatrix_fit(0, 2) = p.v_x;
	TranposeMatrix_fit(1, 2) = p.v_y;
	TranposeMatrix_fit(2, 2) = p.v_z;


	if (m_strAxisSel == "A") {
	

		double dis_error1;
		double dis_error2;
		double degree_error1 = acos(abs(p.v_z));//y轴角度误差
		double degree_error2 = acos(abs(p.v_y));//z轴角度误差
		cal_pos_error_A(data, dis_error1, dis_error2);


		double r = sqrt(dis_error1*dis_error1 + dis_error2 * dis_error2);
		Vector3d vec3d;
		Vector3d vec_fit;    
		for (rotate_count = -A_angle_max; rotate_count <= A_angle_max; rotate_count = rotate_count + 1) {
			point_theory.x = 0;
			point_theory.y =r*sin(rotate_count / 180 * 3.1415926);
			point_theory.z = r*cos(rotate_count / 180 * 3.1415926);
			point_theory.id ++;

			vec3d = Eigen::Vector3d(point_theory.y, point_theory.z, point_theory.x);
			vec_fit = TranposeMatrix_fit * vec3d;

			point_fit.x = vec_fit(0, 0);
			point_fit.y = vec_fit(1, 0);
			point_fit.z = vec_fit(2, 0);
			point_fit.id ++;


			data_fit.push_back(point_fit);
			data_theory.push_back(point_theory);
		}


	}
	else {
		//m_strAxisSel == "C"


	   //fitting_plane_by_LSM(data, p);
		fitting_circle_by_LSM(data, p, fitted_circle1);
		double degree_error1;
		double degree_error2;
		double dis_error1;
		double dis_error2;

		//Point point_theory;//理论坐标
		//Point point_fit;//拟合坐标

		//data_fit.clear();
		//data_theory.clear();
		//double rotate_count;

		//Matrix3d TranposeMatrix_fit; //初始化为单位矩阵
		//TranposeMatrix_fit(0, 0) = 0;
		//TranposeMatrix_fit(1, 0) = -p.v_z;
		//TranposeMatrix_fit(2, 0) = -p.v_y;
		//TranposeMatrix_fit(0, 1) = p.v_z*p.v_z - p.v_y*p.v_y;
		//TranposeMatrix_fit(1, 1) = p.v_x*p.v_y;
		//TranposeMatrix_fit(2, 1) = -p.v_x*p.v_z;
		//TranposeMatrix_fit(0, 2) = p.v_x;
		//TranposeMatrix_fit(1, 2) = p.v_y;
		//TranposeMatrix_fit(2, 2) = p.v_z;

		Vector3d vec3d;
		Vector3d vec_fit;
		for (rotate_count = 0; rotate_count <= 360; rotate_count = rotate_count + 3)
		{
			point_theory.x = 0;
			point_theory.y = fitted_circle1.r*sin(rotate_count / 180 * 3.1415926);
			point_theory.z = fitted_circle1.r*cos(rotate_count / 180 * 3.1415926);
			point_theory.id ++;

			vec3d = Eigen::Vector3d(point_theory.y, point_theory.z, point_theory.x);
			vec_fit = TranposeMatrix_fit * vec3d;

			point_fit.x = vec_fit(0, 0);
			point_fit.y = vec_fit(1, 0);
			point_fit.z = vec_fit(2, 0);
			point_fit.id++;


			data_fit.push_back(point_fit);

		}


		if ((abs(p.v_x) > abs(p.v_y)) & (abs(p.v_x) > abs(p.v_z)))
		{
			degree_error1 = asin((p.v_z));//y轴角度误差
			degree_error2 = asin((p.v_y));//z轴角度误差
			dis_error1 = fitted_circle1.y;//y轴位置误差
			dis_error2 = fitted_circle1.z;//z轴位置误差

			for (rotate_count = 0; rotate_count <= 360; rotate_count = rotate_count + 3)
			{
				point_theory.x = 0;
				point_theory.y = fitted_circle1.r*sin(rotate_count / 180 * 3.1415926);
				point_theory.z = fitted_circle1.r*cos(rotate_count / 180 * 3.1415926);
				point_theory.id = 0;
				data_theory.push_back(point_theory);

			}
		}
		else if ((abs(p.v_y) > abs(p.v_x)) & (abs(p.v_y) > abs(p.v_z)))
		{
			degree_error1 = asin((p.v_x));//z轴角度误差
			degree_error2 = asin((p.v_z));//x轴角度误差
			dis_error1 = fitted_circle1.x;//x轴位置误差
			dis_error2 = fitted_circle1.z;//z轴位置误差
			for (rotate_count = 0; rotate_count <= 360; rotate_count = rotate_count + 3)
			{
				point_theory.y = 0;
				point_theory.x = fitted_circle1.r*sin(rotate_count / 180 * 3.1415926);
				point_theory.z = fitted_circle1.r*cos(rotate_count / 180 * 3.1415926);
				point_theory.id = 0;
				data_theory.push_back(point_theory);

			}
		}
		else
		{
			degree_error1 = asin((p.v_y));//x轴角度误差
			degree_error2 = asin((p.v_x));//y轴角度误差

			dis_error1 = fitted_circle1.x;//x轴位置误差
			dis_error2 = fitted_circle1.y;//y轴位置误差

			for (rotate_count = 0; rotate_count <= 360; rotate_count = rotate_count + 3)
			{
				point_theory.z = 0;
				point_theory.x = fitted_circle1.r*sin(rotate_count / 180 * 3.1415926);
				point_theory.y = fitted_circle1.r*cos(rotate_count / 180 * 3.1415926);
				point_theory.id = 0;
				data_theory.push_back(point_theory);

			}
		}

		rotate_error[0] = dis_error1;
		rotate_error[1] = dis_error2;
		rotate_error[2] = degree_error1;
		rotate_error[3] = degree_error2;
	}
		//数据输出
		ofstream mycout_measure("measuredata.txt");
		int n_measure = data.size();
		for (double serial2 = 0; serial2 < n_measure - 5; serial2++)
		{
			mycout_measure << data[serial2].x << ' ' << data[serial2].y << ' ' << data[serial2].z << ' ' << data[serial2].id << endl;
		}

		mycout_measure.close();

		//拟合数据
		//data_fit.clear();
		//data_theory.clear();
		ofstream mycout_fit("data_fit.txt");
		int n_fit = data_fit.size();
		for (double serial2 = 0; serial2 < n_fit - 5; serial2++)
		{
			mycout_fit << data_fit[serial2].x << ' ' << data_fit[serial2].y << ' ' << data_fit[serial2].z << ' ' << data_fit[serial2].id << endl;
		}

		mycout_fit.close();

		//理论数据
		ofstream mycout_theory("data_theory.txt");
		int n_theory = data_theory.size();
		for (double serial2 = 0; serial2 < n_theory - 5; serial2++)
		{
			mycout_theory << data_theory[serial2].x << ' ' << data_theory[serial2].y << ' ' << data_theory[serial2].z << ' ' << data_theory[serial2].id << endl;
		}

		mycout_theory.close();
	

}

void Rtest_var::syn_error_cal(vector<Point> &data)
{
	int n = data.size();
	double max_x_error = 0;
	double max_y_error = 0;
	double max_z_error = 0;

	for(int i = 0; i < n; i++)
	{
		if(abs(data[i].x) > max_x_error)
		{
			max_x_error = abs(data[i].x);
		}

		if(abs(data[i].y) > max_y_error)
		{
			max_y_error = abs(data[i].y);
		}

		if(abs(data[i].z) > max_z_error)
		{
			max_z_error = abs(data[i].z);
		}
	}

	syn_error[0] = max_x_error;
	syn_error[1] = max_y_error;
	syn_error[2] = max_z_error;
}

void Rtest_var::error_save(std::string szFile)
{
	ofstream mycout(szFile.c_str());

	if(cal_axis == 0)
	{
		Plane p;
		p.v_x = 0;

		Circle fitted_circle;
		if (m_strAxisSel == "C") {
			fitting_plane_by_LSM(data_read, p);
			fitting_circle_by_LSM(data_read, p, fitted_circle);
			double degree_error1;
			double degree_error2;
			double dis_error1;
			double dis_error2;

			if ((abs(p.v_x) > abs(p.v_y)) & (abs(p.v_x) > abs(p.v_z)))
			{
				degree_error1 = acos(abs(p.v_z));//y轴角度误差
				degree_error2 = acos(abs(p.v_y));//z轴角度误差
				dis_error1 = fitted_circle.y;//y轴位置误差
				dis_error2 = fitted_circle.z;//z轴位置误差
				mycout << "C轴误差:" << endl;
				mycout << "y轴角度误差:" << degree_error1 << endl;
				mycout << "z轴角度误差:" << degree_error2 << endl;
				mycout << "y轴位置误差:" << dis_error1 << endl;
				mycout << "z轴位置误差:" << dis_error2 << endl;
			}
			else if ((abs(p.v_y) > abs(p.v_x)) & (abs(p.v_y) > abs(p.v_z)))
			{
				degree_error1 = acos(abs(p.v_x));//z轴角度误差
				degree_error2 = acos(abs(p.v_z));//x轴角度误差
				dis_error1 = fitted_circle.x;//x轴位置误差
				dis_error2 = fitted_circle.z;//z轴位置误差
				mycout << "C轴误差:" << endl;
				mycout << "z轴角度误差:" << degree_error1 << endl;
				mycout << "x轴角度误差:" << degree_error2 << endl;
				mycout << "z轴位置误差:" << dis_error2 << endl;
				mycout << "x轴位置误差:" << dis_error1 << endl;
			}
			else
			{
				degree_error1 = acos(abs(p.v_x));//y轴角度误差
				degree_error2 = acos(abs(p.v_y));//x轴角度误差
				dis_error1 = fitted_circle.x;//x轴位置误差
				dis_error2 = fitted_circle.y;//y轴位置误差
				mycout << "C轴误差:" << endl;
				mycout << "y轴角度误差:" << degree_error1 << endl;
				mycout << "x轴角度误差:" << degree_error2 << endl;
				mycout << "y轴位置误差:" << dis_error2 << endl;
				mycout << "x轴位置误差:" << dis_error1 << endl;
			}
		}
		else {//m_strAxisSel == "A"
			fitting_plane_by_LSM(data_read_todeal, p);
		
			double dis_error1;
			double dis_error2;
			double degree_error1 = acos(abs(p.v_z));//y轴角度误差
			double degree_error2 = acos(abs(p.v_y));//z轴角度误差
			cal_pos_error_A(data_read_todeal, dis_error1, dis_error2);





			mycout << "A轴误差:" << endl;
			mycout << "y轴角度误差:" << degree_error1 << endl;
			mycout << "z轴角度误差:" << degree_error2 << endl;
			mycout << "y轴位置误差:" << dis_error1 << endl;
			mycout << "z轴位置误差:" << dis_error2 << endl;

		}
	}
	else
	{//同步误差
		int n = data_read.size();
		double max_x_error = 0;
		double max_y_error = 0;
		double max_z_error = 0;

		for(int i = 0; i < n; i++)
		{
			if(abs(data_read[i].x) > max_x_error)
			{
				max_x_error = abs(data_read[i].x);
			}

			if(abs(data_read[i].y) > max_y_error)
			{
				max_y_error = abs(data_read[i].y);
			}

			if(abs(data_read[i].z) > max_z_error)
			{
				max_z_error = abs(data_read[i].z);
			}
		}
		mycout << "同步误差:" << endl;
		mycout << "x轴方向最大误差:" << max_x_error << endl;
		mycout << "y轴方向最大误差:" << max_y_error << endl;
		mycout << "z轴方向最大误差:" << max_z_error << endl;
	}
}

void Rtest_var::cal_pos_error_A(vector<Point>& data, double &y0, double &z0) {
	//step1 找出其最高位置与最低位置误差
	pair<pair<double,double>,int> global_y_max_id (pair<double,double>(-1, 0),0);
	pair<pair<double,double>,int> global_y_min_id (pair<double,double>(1, 0),0);

	//以Y为标准，Y方向为正负两个方向，Z方向为两个正方向
	for (int i =6; i < data.size()-6; i++) {
	     //消除噪点影响
		//去掉一个最大，一个最小，滑动平均
		pair<double, int> max_y(data[i].y,data[i].id);
		pair<double, int> min_y(data[i].y, data[i].id);
		pair<double, double> y_max_pos(0,0);//y值正最大的之后，点的yz误差值
		pair<double, double> y_min_pos(0,0);//y值负最小之后，点的yz误差值
		for (int j = i - 6; j < i + 6; j++) {
			if (max_y.first < data[j].y) {
				max_y.first = data[j].y;
				max_y.second = data[j].id;
			}
			if (min_y.first > data[j].y) {
				min_y.first = data[j].y;
				min_y.second = data[j].id;
			}

		}
		for (int j = i - 6; j < i + 6; j++) {
			if (data[j].id != max_y.second&&data[j].id!=min_y.second) {//除去一个最大值，一个最小值
				y_max_pos.first+=data[j].y/10;
				y_max_pos.second += data[j].z/10;
				
				y_min_pos.first += data[j].y/10;
				y_min_pos.second += data[j].z/10;
			}
		}
		if (global_y_max_id.first.first < y_max_pos.first) {
			global_y_max_id.first.first = y_max_pos.first;
			global_y_max_id.first.second = y_max_pos.second;
			global_y_max_id.second = max_y.second;
		}
		if (global_y_min_id.first.first > y_min_pos.first) {
			global_y_min_id.first.first = y_min_pos.first;
			global_y_min_id.first.second = y_min_pos.second;
			global_y_min_id.second = min_y.second;

		}
	}	


	double A;
	if (global_y_max_id.second > global_y_min_id.second) {
		//判断90°位置与-90°位置（A_angle_max)
		//先运动至90°位置，然后运动至-90°位置（A_angle_max)
		A = A_angle_max;

	}
	else {
		A = -A_angle_max;
	}
	double y = global_y_max_id.first.first;
	double z = global_y_max_id.first.second;
	//计算公式
	// -0.5*Y - (SIN(A*PI() / 180)*Z) / (2 * (1 - COS(A*PI() / 180)))
	//-(SIN(A*PI() / 180)*Y) / (2 * (1 - COS(A*PI() / 180))) + 0.5*Z

	double y1 = -0.5*y - (sin(A*M_PI / 180)*z) / (2 * (1 - cos(A*M_PI / 180)));
	double z1 = -(sin(A*M_PI / 180)*y) / (2 * (1 - cos(A*M_PI / 180))) + 0.5*z;

	y = global_y_min_id.first.first;
    z = global_y_min_id.first.second;

	A = -A;
	double y2 = -0.5*y - (sin(A*M_PI / 180)*z) / (2 * (1 - cos(A*M_PI / 180)));
	double z2 = -(sin(A*M_PI / 180)*y) / (2 * (1 - cos(A*M_PI / 180))) + 0.5*z;

	y0 = (y1+ y2) / 2;
	z0 = (z1+ z2) / 2;
}










void Rtest_var::set_axis(string strAxis1, string strAxis2, string strAxisSel)
{
	m_strAxis1 = strAxis1;
	m_strAxis2 = strAxis2;
	m_strAxisSel = strAxisSel;
}

void Rtest_var::set_point_zero(Point& pt)
{
	point_zero = pt;
}

void Rtest_var::set_point_x(Point& pt)
{
	point_x = pt;
}

void Rtest_var::set_point_y(Point& pt)
{
	point_y = pt;
}

void Rtest_var::set_point_z(Point& pt)
{
	point_z = pt;
}

void Rtest_var::set_point_x_inver(Point& pt)
{
	point_x_inver = pt;
}

void Rtest_var::set_point_y_inver(Point& pt)
{
	point_y_inver = pt;
}

void Rtest_var::set_point_z_inver(Point& pt)
{
	point_z_inver = pt;
}

void Rtest_var::set_path_design(int _mode, double _threshold, double _stabletime, double _delaytime)
{
	mode = _mode;
	threshold = _threshold;
	stabletime = _stabletime;
	stoptime = _delaytime;
}

void Rtest_var::set_rotate_param(double _alpha1, double _alpha2, int _divide, int _count, int _direc)
{
	alpha1 = _alpha1, alpha2 = _alpha2, divide = _divide, count = _count, direc = _direc;
}

void Rtest_var::set_sync_param(int _axis_num, double _mutliaxis_set[15])
{
	axis_num = _axis_num;
	for (int i=0;i<15;i++)
	{
		mutliaxis_set[i] = _mutliaxis_set[i];
	}
}

void Rtest_var::GetTranposeMatrix(Matrix3d &_trix)
{
	_trix = TranposeMatrix;
}

void Rtest_var::GetReadData(vector<Point>& vecPt)
{
	vecPt = data_read;
}

void Rtest_var::GetRotate_error(vector<double>& vecErr)
{
	vecErr.clear();
	for (int i = 0; i < 4; i++)
	{
		vecErr.push_back(rotate_error[i]);
	}	
}

void Rtest_var::GetAxisError1(int &_cal_axis, double _rotate_error[4], double _syn_error[3])
{
	_cal_axis = cal_axis;
	for (int i = 0; i < 4; i++)
	{
		_rotate_error[i] = rotate_error[i];
	}

	for (int i = 0; i < 3; i++)
	{
		_syn_error[i] = syn_error[i];
	}
}

void Rtest_var::GetData_theory(vector<Point>& vecData)
{
	vecData = data_theory;
}

void Rtest_var::GetData_fit(vector<Point>& vecData)
{
	vecData = data_fit;
}