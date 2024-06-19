// CChartDialog.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication3.h"
#include "afxdialogex.h"
#include "CChartDialog.h"


// CChartDialog 对话框

IMPLEMENT_DYNAMIC(CChartDialog, CDialogEx)

CChartDialog::CChartDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CChartDialog::~CChartDialog()
{
}

void CChartDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CChartDialog, CDialogEx)
    ON_WM_PAINT()
    ON_BN_CLICKED(IDOK, &CChartDialog::OnBnClickedOk)
END_MESSAGE_MAP()

void CChartDialog::OnPaint()
{
    CPaintDC dc(this); // device context for painting

    CRect rect;
    GetClientRect(&rect);  // 获取对话框的客户区大小

    int barWidth = rect.Width() / 5 - 10;  // 减少10像素的间隔
    int maxHeight = rect.Height() * 0.8;  // 减少20%的偏移量

    // 创建新的字体
    CFont font;
    font.CreatePointFont(120, _T("Arial"), &dc);  // 字体大小为12点
    CFont* def_font = dc.SelectObject(&font);

    for (int i = 0; i < 5; i++) {
        int height = (freq[i] / double(stu.size())) * maxHeight;
        dc.FillSolidRect(i * (barWidth + 10) + 5, maxHeight - height, barWidth, height, RGB(0, 200, 200));

        // 绘制区间
        CString range;
        if (i == 0) {
            range.Format(_T("0 - 60"));
        }
        else {
            range.Format(_T("%d - %d"), i * 10 + 50, i * 10 + 60);
        }
        dc.TextOut(i * (barWidth + 10) + 5, maxHeight + 5, range);

        // 绘制人数
        CString count;
        count.Format(_T("%d"), freq[i]);
        dc.TextOut(i * (barWidth + 10) + 5, maxHeight - height - 15, count);
    }

    // 恢复默认字体
    dc.SelectObject(def_font);
}




// CChartDialog 消息处理程序


void CChartDialog::OnBnClickedOk()
{
    // TODO: 在此添加控件通知处理程序代码
    CDialogEx::OnOK();
}
