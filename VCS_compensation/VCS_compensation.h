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
	int num;// ���
};

struct Point { //x y z error and cooresponding NC code
	float Err_x=0;
	float Err_y=0;
	float Err_z=0;
	NC_code origin_NC;//����ǰ���ش���
	NC_code new_NC;//���������ش���
	int num;//���
};

typedef vector<vector<float>> Array;



class VCS {
public:
	void initial_AC_test_trajectory(float Astart, float Aend, float Cstart, float Cend, int numA, int numC);		
	/**
		Input:
		#1 Astart: A��켣��ʼ��
		#2 Aend: A��켣������
		#3 Cstart: C��켣��ʼ��
		#4 Cend: C��켣������
		#5 numA: A��켣ȡ������
		#6 numC: C��켣ȡ������
     ------------------------------------------------------------------------------------	----------------------------------	
		Output:
		#1 AC_test: ���ɵļ��켣

	*/
	void read_test_error();
	/*
	   Output:
	   1# AC_error: �������
	   tip: ��ȡ����������ļ���ע������켣���Ӧ
	*/

	void read_compensation_NC_code();
	/*
	    Output:
		1# AC_compensation: �����켣
		tip����ȡ��Ҫ������NC����
	*/
	void calculate_the_compensation_trajectory();
	/**
	Input:
	#1 AC_compensation.origin_NC

	Output: 
	#1 AC_compensation.new_NC
	 tip:�ú������������㲹��������ع켣
	*/

private:


	void find_AC_brick(vector<float>& AC_need_compensation, Array& AC_element,Array& AC_element_error);
	/**
		Input:
		#1 AC : ���켣
		#2 AC_error:������
		-------------------------------------------------------------------------------------------------------------------
		#3 AC_need_compensation:���貹���켣λ��
	   Output:
	    #1 AC_element: ��Ӧ�����λ��
		#2 AC_element����Ӧ����λ�õ����

		tip:�������������������Ҫ��������ת��λ�����ڵ�������Щ�����ɼ��켣�ĸ�����ת�����ڵĿռ�λ����ɣ�
		������ȡ���������ĸ������Ǿ������貹��λ��������ĸ����λ�á�
	*/


		void get_AC_test_error(Array& AC_element,Array& AC_element_error, vector<float> &AC_need_compensation,
			vector<float>& xyz_error);
	/**
	    Input:
		#1 AC_element: ���λ�ö�Ӧ������
		#2 AC_element_error: �����϶�Ӧ��������
		#3 AC_need_compensation: �������켣λ��
		Output:
		#1 xyz_error: ����Ĳ������

		tip:��������Ǹ�����ȡ���������켣����Ӧ�������
	*/
	
private:
	Array AC; //���켣
	Array AC_error;//������
	
	vector<Point> AC_compensation;//�����켣����Ӧ���
	
};