#pragma once
#include<bits/stdc++.h>
#include<vector>
#include "Student.h"

using namespace std;

class management {
public:
    void show_math(vector<Student>& stu, CMFCApplication3Dlg* dlg);

    void show_cplusplus(vector<Student>& stu, CMFCApplication3Dlg* dlg);

    void Input(vector<Student>& stuList, CMFCApplication3Dlg* dlg);

    void Search(vector<Student>& stu, CMFCApplication3Dlg* dlg);

    void Delete(vector<Student>& stuList, CMFCApplication3Dlg* dlg);

    void modify(vector<Student>& stuList, CMFCApplication3Dlg* dlg);

    void modify_confirm(CMFCApplication3Dlg* dlg, vector<Student>& stu);
};