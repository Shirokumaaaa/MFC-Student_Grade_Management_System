#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "pch.h"
#include "framework.h"
#include "MFCApplication3.h"
#include "MFCApplication3Dlg.h"
#include "afxdialogex.h"

#include <iostream>
#include <windows.h>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <ctime>
#include <vector>
#include <unordered_map>
#include<sstream>

class Student {
public:
	CString stu_name;       //����
	double Cplusplus;     //ƽʱ�ɼ�
	double Math;     //��ĩ�ɼ�
	CString stu_num;     //ѧ��

	Student() {};

	Student(CString num, CString name, double cplusplus, double math)
	{
		stu_name = name;
		stu_num = num;
		Cplusplus = cplusplus;
		Math = math;
	}
	
	void modify(CString num, CString name, double cplusplus, double math)
	{
		stu_name = name;
		stu_num = num;
		Cplusplus = cplusplus;
		Math = math;
	}
};