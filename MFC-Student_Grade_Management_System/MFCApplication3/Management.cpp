#pragma once
#include<bits/stdc++.h>
#include"pch.h"
#include<vector>
#include "Student.h"
#include "Management.h"

using namespace std;

void management::show_math(vector<Student>& stu, CMFCApplication3Dlg* dlg)
{
	if (stu.size() == 0) {             //边界判断
		dlg->MessageBox(TEXT("〓 当前成绩单为空,无内容可以查看!"), TEXT("提示"), MB_OK);
		return;
	}
	std::sort(stu.begin(), stu.end(), [](const Student& a, const Student& b) {
		return a.Math > b.Math;
		});
	CString tmp;
	for (int i = 0; i < stu.size(); i++) {
		//注意这里加个_T
		tmp.Format(tmp + _T("--------\n⊕姓名:%s\n⊕学号:%s\n⊕数学成绩:%.2lf\n"), stu[i].stu_name, stu[i].stu_num, stu[i].Math);
	}
	dlg->MessageBox(tmp, TEXT("数学成绩单"), MB_OK);

	return;
}

void management::show_cplusplus(vector<Student>& stu, CMFCApplication3Dlg* dlg)
{
	if (stu.size() == 0) {             //边界判断
		dlg->MessageBox(TEXT("当前成绩单为空,无内容可以查看!"), TEXT("提示"), MB_OK);
		return;
	}
	std::sort(stu.begin(), stu.end(), [](const Student& a, const Student& b) {
		return a.Cplusplus > b.Cplusplus;
		});
	CString tmp;
	for (int i = 0; i < stu.size(); i++) {
		//注意这里加个_T
		tmp.Format(tmp + _T("-------------------\n姓名:%s\n学号:%s\nC++成绩:%.2lf\n"), stu[i].stu_name, stu[i].stu_num, stu[i].Cplusplus);
	}
	dlg->MessageBox(tmp, TEXT("C++成绩单"), MB_OK);
}

void management::Input(vector<Student>& stu, CMFCApplication3Dlg* dlg)
{
	CString stu_name;
	dlg->GetDlgItemText(IDC_EDIT2, stu_name);   //获取编辑框内容

	CString stu_num;
	dlg->GetDlgItemText(IDC_EDIT3, stu_num);   //获取编辑框内容
	CString math;
	dlg->GetDlgItemText(IDC_EDIT4, math);   //获取编辑框内容
	CString cplusplus;
	dlg->GetDlgItemText(IDC_EDIT5, cplusplus);   //获取编辑框内容

	if (stu_name == "" && stu_num == "" && math == "" && cplusplus == "") {             //边界判断
		dlg->MessageBox(TEXT("〓 输入框内容未填写完毕!"), TEXT("提示"), MB_OK);
		return;
	}

	//注意如何将CSting转为float
	Student tmp_stu(stu_num, stu_name, atof(CT2A(cplusplus.GetBuffer())), atof(CT2A(math.GetBuffer())));
	stu.push_back(tmp_stu);

	(*dlg).MessageBox(TEXT("导入成功！"), TEXT("提示"), MB_OK);			//弹出信息框

	//清空编辑框
	CString text3;
	text3 = "";
	dlg->GetDlgItem(IDC_EDIT2)->SetWindowText(text3); //设置编辑框内容
	dlg->GetDlgItem(IDC_EDIT3)->SetWindowText(text3); //设置编辑框内容
	dlg->GetDlgItem(IDC_EDIT4)->SetWindowText(text3); //设置编辑框内容
	dlg->GetDlgItem(IDC_EDIT5)->SetWindowText(text3); //设置编辑框内容

	return;
}

void management::Search(vector<Student>& stu, CMFCApplication3Dlg* dlg)
{
	CString text;
	dlg->GetDlgItemText(IDC_EDIT6, text);   //获取编辑框内容

	if (text == "") {             //边界判断
		(*dlg).MessageBox(TEXT("还未填写要查询人的学号!"), TEXT("提示"), MB_OK);
		return;
	}

	int isfind = 0;     //用来记录是否找到
	for (int i = 0; i < stu.size(); i++) {
		if (stu[i].stu_num == text) {
			CString tmp;
			//注意这里加个_T
			tmp.Format(_T("姓名:%s\n学号:%s\n数学成绩:%.2lf\nC++成绩:%.2lf"), stu[i].stu_name, stu[i].stu_num, stu[i].Math, stu[i].Cplusplus);
			dlg->MessageBox(tmp, TEXT("成绩单"), MB_OK);
			isfind = 1;
			return;
		}
	}
	if (isfind == 0) {
		dlg->MessageBox(TEXT("未在成绩表中找到该学号！"), TEXT("提示"), MB_OK);
	}

	CString text3;
	text3 = "";
	dlg->GetDlgItem(IDC_EDIT6)->SetWindowText(text3); //设置编辑框内容

	return;
}

void management::Delete(vector<Student>& stu, CMFCApplication3Dlg* dlg)
{
	CString text;
	dlg->GetDlgItemText(IDC_EDIT6, text);   //获取编辑框内容
	if (text == "") {             //边界判断
		dlg->MessageBox(TEXT("还未填写要删除人的学号!"), TEXT("提示"), MB_OK);
		return;
	}

	int isfind = 0;
	if (stu.size() == 0) {             //边界判断
		dlg->MessageBox(TEXT("当前成绩单为空,无内容可以删除!"), TEXT("提示"), MB_OK);
		return;
	}
	for (int i = 0; i < stu.size(); i++) {
		if (stu[i].stu_num == text) {
			isfind = 1;

			if (dlg->MessageBox(TEXT("请确认是否删除？"), TEXT("提示"), MB_YESNO) == IDYES) {
				stu.erase(stu.begin() + i);
			}
			else {
				dlg->MessageBox(TEXT("删除失败！"), TEXT("提示"), MB_OK);
			}
		}
	}

	if (isfind == 0) {
		cout << "未在成绩表中找到该学号！" << endl;
	}

	CString text3;
	text3 = "";
	dlg->GetDlgItem(IDC_EDIT6)->SetWindowText(text3); //设置编辑框内容

	return;
}

void management::modify(vector<Student>& stuList, CMFCApplication3Dlg* dlg) 
{
	CString stuNum;
	dlg->GetDlgItemText(IDC_EDIT7, stuNum); // 获取编辑框内容
	if (stuNum == "") {
		dlg->MessageBox(TEXT("〓 还未填写要修改人的学号!"), TEXT("提示"), MB_OK);
		return;
	}

	if (stuList.empty()) {
		dlg->MessageBox(TEXT("〓 当前成绩单为空,无内容可以修改!"), TEXT("提示"), MB_OK);
		return;
	}

	bool isFound = false;
	for (auto& student : stuList) {
		if (student.stu_num == stuNum) {
			isFound = true;
			// 启用下面的控件
			CWnd* pWnd = dlg->GetDlgItem(IDC_EDIT10);
			pWnd->EnableWindow(TRUE);
			pWnd = dlg->GetDlgItem(IDC_EDIT11);
			pWnd->EnableWindow(TRUE);
			pWnd = dlg->GetDlgItem(IDC_EDIT12);
			pWnd->EnableWindow(TRUE);
			pWnd = dlg->GetDlgItem(IDC_BUTTON9);
			pWnd->EnableWindow(TRUE);
			break;
		}
	}
	if (!isFound) {
		dlg->MessageBox(TEXT("〓 未在成绩表中找到该学号！"), TEXT("提示"), MB_OK);
	}
}

void management::modify_confirm(CMFCApplication3Dlg* dlg, vector<Student>& stu)
{
	CString text;
	dlg->GetDlgItemText(IDC_EDIT7, text);   //获取编辑框内容


	int isfind = 0;
	if (stu.size() == 0) {             //边界判断
		dlg->MessageBox(TEXT("〓 当前成绩单为空,无内容可以修改!"), TEXT("提示"), MB_OK);
		return;
	}
	CString stu_name;
	dlg->GetDlgItemText(IDC_EDIT10, stu_name);	  //获取编辑框内容
	CString stu_num;
	dlg->GetDlgItemText(IDC_EDIT7, stu_num);		  //获取编辑框内容
	CString math;
	dlg->GetDlgItemText(IDC_EDIT11, math);   //获取编辑框内容
	CString cplusplus;
	dlg->GetDlgItemText(IDC_EDIT12, cplusplus);   //获取编辑框内容
	if (stu_name == "" && stu_num == "" && math == "" && cplusplus == "") {             //边界判断
		dlg->MessageBox(TEXT("〓 输入框内容未填写完毕!"), TEXT("提示"), MB_OK);
		return;
	}
	for (int i = 0; i < stu.size(); i++) {
		if (stu[i].stu_num == text) {


			//注意如何将CSting转为float
			stu[i].modify(stu_num, stu_name, atof(CT2A(math.GetBuffer())), atof(CT2A(cplusplus.GetBuffer())));


			dlg->MessageBox(TEXT("修改成功！"), TEXT("提示"), MB_OK);			//弹出信息框

			//清空编辑框
			CString text3;
			text3 = "";
			dlg->GetDlgItem(IDC_EDIT7)->SetWindowText(text3); //设置编辑框内容
			dlg->GetDlgItem(IDC_EDIT10)->SetWindowText(text3); //设置编辑框内容
			dlg->GetDlgItem(IDC_EDIT11)->SetWindowText(text3); //设置编辑框内容
			dlg->GetDlgItem(IDC_EDIT12)->SetWindowText(text3); //设置编辑框内容


			//禁用下面的控件
			CWnd* pWnd = dlg->GetDlgItem(IDC_EDIT10);
			pWnd->EnableWindow(FALSE);
			pWnd = dlg->GetDlgItem(IDC_EDIT11);
			pWnd->EnableWindow(FALSE);
			pWnd = dlg->GetDlgItem(IDC_EDIT12);
			pWnd->EnableWindow(FALSE);
			pWnd = dlg->GetDlgItem(IDC_BUTTON9);
			pWnd->EnableWindow(FALSE);
		}
	}
}