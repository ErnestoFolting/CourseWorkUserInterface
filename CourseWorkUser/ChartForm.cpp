#include "ChartForm.h"
#include "MenuForm.h"
#include "Root.h"
#include <string>

using namespace std;
System::Void CourseWorkUser::ChartForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    MenuForm^ form = gcnew MenuForm();
    this->Hide();
    form->Show();
}
System::Void CourseWorkUser::ChartForm::printVectors(std::vector<double**> vec) {
    dataGridView1->ColumnCount = vec.size();
    dataGridView1->RowCount = vec.size();
    dataGridView1->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
    dataGridView1->AutoResizeColumns();
    for (int i = 0; i < vec.size(); i++) {
        dataGridView1->Columns[i]->HeaderCell->Value = "X" + Convert::ToString(i + 1);
    }
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec.size(); j++) {
            dataGridView1->Rows[i]->Cells[j]->Value = vec[i][j][0];
        }
    }
}
System::Void CourseWorkUser::ChartForm::printSelfNumbers(Root roots) {
    string selfNumbers;
    for (int i = 0; i < roots.getNum(); i++) {
        selfNumbers += "L" + to_string(i + 1) + ": " + to_string(real(roots.getMas()[i])) + "  ";
    }
    String^ s = gcnew System::String(selfNumbers.c_str());
    label5->Text = s;
}
System::Void CourseWorkUser::ChartForm::printStatistics(int iterations,int multiplies) {
    string iterationsStr = to_string(iterations);
    String^ s = gcnew System::String(iterationsStr.c_str());
    label7->Text = s;
    string multipliesStr = to_string(multiplies);
    String^ s2 = gcnew System::String(multipliesStr.c_str());
    label9->Text = s2;
}
System::Void CourseWorkUser::ChartForm::printChart(std::vector<double> vec,std::vector<double>areaOfRoots)
{
    double min = areaOfRoots[0];
    double max = areaOfRoots[0];
    for (int i = 0; i < areaOfRoots.size(); i++) {
        if (areaOfRoots[i] < min) min = areaOfRoots[i];
        if (areaOfRoots[i] > max) max = areaOfRoots[i];
    }
    chart1->Series[0]->Points->Clear();
    string function =  + "y = x^" + to_string(vec.size()) + " ";
    for (int i = 0; i < vec.size(); i++) {
        if (i < vec.size() - 1 && -1 * vec[i + 1] > 0) {
            function += to_string(-1 * vec[i]) + "x^" + to_string(vec.size() - i - 1) + "+";
        }
        else {
            function += to_string(-1 * vec[i]) + "x^" + to_string(vec.size() - i - 1) + " ";
        }
    }
    String^ s = gcnew System::String(function.c_str());
    label2->Text = s;
    for (int x = round(min)-1; x <= round(max)+1; x++) {
        double sum = 0;
        for (int i = 0; i < vec.size(); i++) {
            sum += (-1)*(vec[i] * pow(x, vec.size() - i - 1));
        }
        sum += pow(x, vec.size());
        double y = sum;
        chart1->Series[0]->Points->AddXY(x, y);
    }
}

