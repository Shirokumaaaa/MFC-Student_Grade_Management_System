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
#include "Student.h"
#include "CChartDialog.h"
#include "Management.h"

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

vector<Student> stu;
management mgr;

CMFCApplication3Dlg::CMFCApplication3Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION3_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	// 读取文件
	CStdioFile file;
	CString strLine;
	if (file.Open(_T("student.txt"), CFile::modeRead))
	{
		file.ReadString(strLine);
		while (file.ReadString(strLine))
		{
			CString num, name;
			CString cplusplus, math;
			// 假设文件中的格式是：学号 姓名 C++成绩 数学成绩
			// 使用CString的Tokenize方法或sscanf_s等来解析strLine
			AfxExtractSubString(num, strLine, 0, ' ');
			AfxExtractSubString(name, strLine, 1, ' ');
			AfxExtractSubString(cplusplus, strLine, 2, ' ');
			AfxExtractSubString(math, strLine, 3, ' ');
			stu.push_back(Student(num, name, _tstof(cplusplus), _tstof(math)));
		}
		file.Close();
	}
}

// 析构函数或适当的退出点中写入文件
CMFCApplication3Dlg::~CMFCApplication3Dlg()
{
	// 写入文件
	CStdioFile file;
	if (file.Open(_T("student.txt"), CFile::modeCreate | CFile::modeWrite))
	{
		file.WriteString(_T("NUM NAME C++  MATH\n"));
		for (const auto& student : stu)
		{
			CString strLine;
			strLine.Format(_T("%s %s %.1f %.1f\n"), student.stu_num, student.stu_name, student.Cplusplus, student.Math);
			file.WriteString(strLine);
		}
		file.Close();
	}
}


//class Student {
//public:
//	CString stu_name;       //姓名
//	double usual_exam;     //平时成绩
//	double final_exam;     //期末成绩
//	CString stu_num;     //学号
//	double total_exam;     //总评成绩
//	Student(CString num, CString name, double us_ex, double fi_ex) :stu_name(name), stu_num(num), usual_exam(us_ex), final_exam(fi_ex)
//	{
//		total_exam = usual_exam * 0.4 + final_exam * 0.6;
//	}
//	void modify(CString num, CString name, double us_ex, double fi_ex)
//	{
//		stu_name = name;
//		stu_num = num;
//		usual_exam = us_ex;
//		final_exam = fi_ex;
//		total_exam = int((double)usual_exam * 0.4 + (double)final_exam * 0.6);
//	}
//	void show() {
//		
//
//		//cout << "★" << endl;
//	}
//};



// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication3Dlg 对话框



//CMFCApplication3Dlg::CMFCApplication3Dlg(CWnd* pParent /*=nullptr*/)
//	: CDialogEx(IDD_MFCAPPLICATION3_DIALOG, pParent)
//{
//	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
//}

void CMFCApplication3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON9, a);
}

BEGIN_MESSAGE_MAP(CMFCApplication3Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT5, &CMFCApplication3Dlg::OnEnChangeEdit5)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication3Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication3Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication3Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCApplication3Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCApplication3Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication3Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFCApplication3Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CMFCApplication3Dlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CMFCApplication3Dlg::OnBnClickedButton11)
	ON_EN_CHANGE(IDC_EDIT11, &CMFCApplication3Dlg::OnEnChangeEdit11)
	ON_EN_CHANGE(IDC_EDIT2, &CMFCApplication3Dlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT4, &CMFCApplication3Dlg::OnEnChangeEdit4)
END_MESSAGE_MAP()


// CMFCApplication3Dlg 消息处理程序

BOOL CMFCApplication3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication3Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication3Dlg::OnEnChangeEdit5()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

void CMFCApplication3Dlg::OnBnClickedButton10()				//查看数学成绩
{
	// TODO: 在此添加控件通知处理程序代码
	mgr.show_math(stu, this); // 调用show_math函数
}

void CMFCApplication3Dlg::OnBnClickedButton1()				 //导入成绩
{
	// TODO: 在此添加控件通知处理程序代码
	mgr.Input(stu, this); // 调用Input函数
}


void CMFCApplication3Dlg::OnBnClickedButton4()				 //查找
{
	// TODO: 在此添加控件通知处理程序代码
	mgr.Search(stu, this); // 调用Search函数
}

void CMFCApplication3Dlg::OnBnClickedButton5()			    //删除
{
	// TODO: 在此添加控件通知处理程序代码
	mgr.Delete(stu, this); // 调用Delete函数
}

void CMFCApplication3Dlg::OnBnClickedButton7()				//查看C++成绩
{
	// TODO: 在此添加控件通知处理程序代码
	mgr.show_cplusplus(stu, this); // 调用show_cplusplus函数
}

void CMFCApplication3Dlg::OnBnClickedButton6() {          //修改
	
	mgr.modify(stu, this); // 调用modify函数
}

void CMFCApplication3Dlg::OnBnClickedButton9()				//确认修改
{
	// TODO: 在此添加控件通知处理程序代码
	mgr.modify_confirm(this,stu);
}


void CMFCApplication3Dlg::OnEnChangeEdit11()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMFCApplication3Dlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMFCApplication3Dlg::OnEnChangeEdit4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

void CMFCApplication3Dlg::OnBnClickedButton8()			//查看C++成绩分析
{
	// TODO: 在此添加控件通知处理程序代码
	if (stu.size() == 0) {             //边界判断
		MessageBox(TEXT("〓 当前成绩单为空,无内容可以分析!"), TEXT("提示"), MB_OK);
		return;
	}
	double all = 0;
	unordered_map<int, int> freq;           //各个成绩段的人数和比例
	for (int i = 0; i < stu.size(); i++) {
		double tmp = stu[i].Cplusplus;
		if (tmp < 60) {
			freq[0]++;
		}
		else {
			freq[int((tmp - 60) / 10) + 1]++;
		}
		all += tmp;
	}

	CChartDialog dlg;
	dlg.setData(freq, stu);
	dlg.DoModal();
	return;
}

void CMFCApplication3Dlg::OnBnClickedButton11()			//查看数学成绩分析
{
	// TODO: 在此添加控件通知处理程序代码
	if (stu.size() == 0) {             //边界判断
		MessageBox(TEXT("〓 当前成绩单为空,无内容可以分析!"), TEXT("提示"), MB_OK);
		return;
	}
	double all = 0;
	unordered_map<int, int> freq;           //各个成绩段的人数和比例
	for (int i = 0; i < stu.size(); i++) {
		double tmp = stu[i].Math;
		if (tmp < 60) {
			freq[0]++;
		}
		else {
			freq[int((tmp - 60) / 10) + 1]++;
		}
		all += tmp;
	}

	CChartDialog dlg;
	dlg.setData(freq, stu);
	dlg.DoModal();

	return;
}