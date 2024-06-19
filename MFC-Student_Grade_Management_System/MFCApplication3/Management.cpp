#pragma once
#include<bits/stdc++.h>
#include"pch.h"
#include<vector>
#include "Student.h"
#include "Management.h"

using namespace std;

void management::show_math(vector<Student>& stu, CMFCApplication3Dlg* dlg)
{
	if (stu.size() == 0) {             //�߽��ж�
		dlg->MessageBox(TEXT("�� ��ǰ�ɼ���Ϊ��,�����ݿ��Բ鿴!"), TEXT("��ʾ"), MB_OK);
		return;
	}
	std::sort(stu.begin(), stu.end(), [](const Student& a, const Student& b) {
		return a.Math > b.Math;
		});
	CString tmp;
	for (int i = 0; i < stu.size(); i++) {
		//ע������Ӹ�_T
		tmp.Format(tmp + _T("--------\n������:%s\n��ѧ��:%s\n����ѧ�ɼ�:%.2lf\n"), stu[i].stu_name, stu[i].stu_num, stu[i].Math);
	}
	dlg->MessageBox(tmp, TEXT("��ѧ�ɼ���"), MB_OK);

	return;
}

void management::show_cplusplus(vector<Student>& stu, CMFCApplication3Dlg* dlg)
{
	if (stu.size() == 0) {             //�߽��ж�
		dlg->MessageBox(TEXT("��ǰ�ɼ���Ϊ��,�����ݿ��Բ鿴!"), TEXT("��ʾ"), MB_OK);
		return;
	}
	std::sort(stu.begin(), stu.end(), [](const Student& a, const Student& b) {
		return a.Cplusplus > b.Cplusplus;
		});
	CString tmp;
	for (int i = 0; i < stu.size(); i++) {
		//ע������Ӹ�_T
		tmp.Format(tmp + _T("-------------------\n����:%s\nѧ��:%s\nC++�ɼ�:%.2lf\n"), stu[i].stu_name, stu[i].stu_num, stu[i].Cplusplus);
	}
	dlg->MessageBox(tmp, TEXT("C++�ɼ���"), MB_OK);
}

void management::Input(vector<Student>& stu, CMFCApplication3Dlg* dlg)
{
	CString stu_name;
	dlg->GetDlgItemText(IDC_EDIT2, stu_name);   //��ȡ�༭������

	CString stu_num;
	dlg->GetDlgItemText(IDC_EDIT3, stu_num);   //��ȡ�༭������
	CString math;
	dlg->GetDlgItemText(IDC_EDIT4, math);   //��ȡ�༭������
	CString cplusplus;
	dlg->GetDlgItemText(IDC_EDIT5, cplusplus);   //��ȡ�༭������

	if (stu_name == "" && stu_num == "" && math == "" && cplusplus == "") {             //�߽��ж�
		dlg->MessageBox(TEXT("�� ���������δ��д���!"), TEXT("��ʾ"), MB_OK);
		return;
	}

	//ע����ν�CStingתΪfloat
	Student tmp_stu(stu_num, stu_name, atof(CT2A(cplusplus.GetBuffer())), atof(CT2A(math.GetBuffer())));
	stu.push_back(tmp_stu);

	(*dlg).MessageBox(TEXT("����ɹ���"), TEXT("��ʾ"), MB_OK);			//������Ϣ��

	//��ձ༭��
	CString text3;
	text3 = "";
	dlg->GetDlgItem(IDC_EDIT2)->SetWindowText(text3); //���ñ༭������
	dlg->GetDlgItem(IDC_EDIT3)->SetWindowText(text3); //���ñ༭������
	dlg->GetDlgItem(IDC_EDIT4)->SetWindowText(text3); //���ñ༭������
	dlg->GetDlgItem(IDC_EDIT5)->SetWindowText(text3); //���ñ༭������

	return;
}

void management::Search(vector<Student>& stu, CMFCApplication3Dlg* dlg)
{
	CString text;
	dlg->GetDlgItemText(IDC_EDIT6, text);   //��ȡ�༭������

	if (text == "") {             //�߽��ж�
		(*dlg).MessageBox(TEXT("��δ��дҪ��ѯ�˵�ѧ��!"), TEXT("��ʾ"), MB_OK);
		return;
	}

	int isfind = 0;     //������¼�Ƿ��ҵ�
	for (int i = 0; i < stu.size(); i++) {
		if (stu[i].stu_num == text) {
			CString tmp;
			//ע������Ӹ�_T
			tmp.Format(_T("����:%s\nѧ��:%s\n��ѧ�ɼ�:%.2lf\nC++�ɼ�:%.2lf"), stu[i].stu_name, stu[i].stu_num, stu[i].Math, stu[i].Cplusplus);
			dlg->MessageBox(tmp, TEXT("�ɼ���"), MB_OK);
			isfind = 1;
			return;
		}
	}
	if (isfind == 0) {
		dlg->MessageBox(TEXT("δ�ڳɼ������ҵ���ѧ�ţ�"), TEXT("��ʾ"), MB_OK);
	}

	CString text3;
	text3 = "";
	dlg->GetDlgItem(IDC_EDIT6)->SetWindowText(text3); //���ñ༭������

	return;
}

void management::Delete(vector<Student>& stu, CMFCApplication3Dlg* dlg)
{
	CString text;
	dlg->GetDlgItemText(IDC_EDIT6, text);   //��ȡ�༭������
	if (text == "") {             //�߽��ж�
		dlg->MessageBox(TEXT("��δ��дҪɾ���˵�ѧ��!"), TEXT("��ʾ"), MB_OK);
		return;
	}

	int isfind = 0;
	if (stu.size() == 0) {             //�߽��ж�
		dlg->MessageBox(TEXT("��ǰ�ɼ���Ϊ��,�����ݿ���ɾ��!"), TEXT("��ʾ"), MB_OK);
		return;
	}
	for (int i = 0; i < stu.size(); i++) {
		if (stu[i].stu_num == text) {
			isfind = 1;

			if (dlg->MessageBox(TEXT("��ȷ���Ƿ�ɾ����"), TEXT("��ʾ"), MB_YESNO) == IDYES) {
				stu.erase(stu.begin() + i);
			}
			else {
				dlg->MessageBox(TEXT("ɾ��ʧ�ܣ�"), TEXT("��ʾ"), MB_OK);
			}
		}
	}

	if (isfind == 0) {
		cout << "δ�ڳɼ������ҵ���ѧ�ţ�" << endl;
	}

	CString text3;
	text3 = "";
	dlg->GetDlgItem(IDC_EDIT6)->SetWindowText(text3); //���ñ༭������

	return;
}

void management::modify(vector<Student>& stuList, CMFCApplication3Dlg* dlg) 
{
	CString stuNum;
	dlg->GetDlgItemText(IDC_EDIT7, stuNum); // ��ȡ�༭������
	if (stuNum == "") {
		dlg->MessageBox(TEXT("�� ��δ��дҪ�޸��˵�ѧ��!"), TEXT("��ʾ"), MB_OK);
		return;
	}

	if (stuList.empty()) {
		dlg->MessageBox(TEXT("�� ��ǰ�ɼ���Ϊ��,�����ݿ����޸�!"), TEXT("��ʾ"), MB_OK);
		return;
	}

	bool isFound = false;
	for (auto& student : stuList) {
		if (student.stu_num == stuNum) {
			isFound = true;
			// ��������Ŀؼ�
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
		dlg->MessageBox(TEXT("�� δ�ڳɼ������ҵ���ѧ�ţ�"), TEXT("��ʾ"), MB_OK);
	}
}

void management::modify_confirm(CMFCApplication3Dlg* dlg, vector<Student>& stu)
{
	CString text;
	dlg->GetDlgItemText(IDC_EDIT7, text);   //��ȡ�༭������


	int isfind = 0;
	if (stu.size() == 0) {             //�߽��ж�
		dlg->MessageBox(TEXT("�� ��ǰ�ɼ���Ϊ��,�����ݿ����޸�!"), TEXT("��ʾ"), MB_OK);
		return;
	}
	CString stu_name;
	dlg->GetDlgItemText(IDC_EDIT10, stu_name);	  //��ȡ�༭������
	CString stu_num;
	dlg->GetDlgItemText(IDC_EDIT7, stu_num);		  //��ȡ�༭������
	CString math;
	dlg->GetDlgItemText(IDC_EDIT11, math);   //��ȡ�༭������
	CString cplusplus;
	dlg->GetDlgItemText(IDC_EDIT12, cplusplus);   //��ȡ�༭������
	if (stu_name == "" && stu_num == "" && math == "" && cplusplus == "") {             //�߽��ж�
		dlg->MessageBox(TEXT("�� ���������δ��д���!"), TEXT("��ʾ"), MB_OK);
		return;
	}
	for (int i = 0; i < stu.size(); i++) {
		if (stu[i].stu_num == text) {


			//ע����ν�CStingתΪfloat
			stu[i].modify(stu_num, stu_name, atof(CT2A(math.GetBuffer())), atof(CT2A(cplusplus.GetBuffer())));


			dlg->MessageBox(TEXT("�޸ĳɹ���"), TEXT("��ʾ"), MB_OK);			//������Ϣ��

			//��ձ༭��
			CString text3;
			text3 = "";
			dlg->GetDlgItem(IDC_EDIT7)->SetWindowText(text3); //���ñ༭������
			dlg->GetDlgItem(IDC_EDIT10)->SetWindowText(text3); //���ñ༭������
			dlg->GetDlgItem(IDC_EDIT11)->SetWindowText(text3); //���ñ༭������
			dlg->GetDlgItem(IDC_EDIT12)->SetWindowText(text3); //���ñ༭������


			//��������Ŀؼ�
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