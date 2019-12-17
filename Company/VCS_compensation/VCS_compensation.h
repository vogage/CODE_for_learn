#pragma once
#include<vector>

using namespace std;

struct NC_code {// machine tool NC code X Y Z A B C
	float X=0;
	float Y=0;
	float Z=0;
	float A=0;
	float B=0;
	float C=0;
	int num;// 序号
};

struct Point { //x y z error and cooresponding NC code
	float Err_x=0;
	float Err_y=0;
	float Err_z=0;
	NC_code origin_NC;//补偿前数控代码
	NC_code new_NC;//补偿后数控代码
	int num;//序号
};

typedef vector<vector<float>> Array;



class VCS {
public:
	void initial_AC_test_trajectory(float Astart, float Aend, float Cstart, float Cend, int numA, int numC);		
	/**
		Input:
		#1 Astart: A轴轨迹起始点
		#2 Aend: A轴轨迹结束点
		#3 Cstart: C轴轨迹起始点
		#4 Cend: C轴轨迹结束点
		#5 numA: A轴轨迹取点数量
		#6 numC: C轴轨迹取点数量
     ------------------------------------------------------------------------------------	----------------------------------	
		Output:
		#1 AC_test: 生成的检测轨迹

	*/
	void read_test_error();
	/*
	   Output:
	   1# AC_error: 测量误差
	   tip: 读取检测的误差结果文件，注意与检测轨迹相对应
	*/

	void read_compensation_NC_code();
	/*
	    Output:
		1# AC_compensation: 补偿轨迹
		tip：读取需要补偿的NC代码
	*/
	void calculate_the_compensation_trajectory();
	/**
	Input:
	#1 AC_compensation.origin_NC

	Output: 
	#1 AC_compensation.new_NC
	 tip:该函数是用来计算补偿后的数控轨迹
	*/

private:


	void find_AC_brick(vector<float>& AC_need_compensation, Array& AC_element,Array& AC_element_error);
	/**
		Input:
		#1 AC : 检测轨迹
		#2 AC_error:检测误差
		-------------------------------------------------------------------------------------------------------------------
		#3 AC_need_compensation:所需补偿轨迹位置
	   Output:
	    #1 AC_element: 对应网格的位置
		#2 AC_element：对应网格位置的误差

		tip:这个函数是用来发现所要补偿的旋转轴位置所在的网格，这些网格由检测轨迹的各个旋转轴所在的空间位置组成，
		最终提取的网格其四个顶点是距离所需补偿位置最近的四个检测位置。
	*/


		void get_AC_test_error(Array& AC_element,Array& AC_element_error, vector<float> &AC_need_compensation,
			vector<float>& xyz_error);
	/**
	    Input:
		#1 AC_element: 检测位置对应的网格
		#2 AC_element_error: 网格上对应各点的误差
		#3 AC_need_compensation: 待补偿轨迹位置
		Output:
		#1 xyz_error: 输出的补偿误差

		tip:这个函数是根据所取的网格计算轨迹的相应补偿误差
	*/
	
private:
	Array AC; //检测轨迹
	Array AC_error;//检测误差
	
	vector<Point> AC_compensation;//补偿轨迹及对应误差
	
};