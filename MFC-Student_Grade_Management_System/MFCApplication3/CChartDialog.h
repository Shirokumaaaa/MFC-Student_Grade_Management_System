#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "afxdialogex.h"
#include "Student.h"
#include<vector>

using namespace std;


// CChartDialog 对话框

class CChartDialog : public CDialogEx
{
    DECLARE_DYNAMIC(CChartDialog)

public:
    afx_msg void OnPaint();
    CChartDialog(CWnd* pParent = nullptr);   // 标准构造函数
    virtual ~CChartDialog();

    unordered_map<int, int> freq;
    vector<Student> stu;

    void setData(unordered_map<int, int> freq, vector<Student> stu)
    {
        this->freq = freq;
        this->stu = stu;
        //Invalidate();  // 强制对话框重绘
    }

    // 对话框数据
#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_DIALOG1 };
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

    DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedOk();
};
