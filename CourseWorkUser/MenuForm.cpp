#include "MenuForm.h"
#include "ChartForm.h"
#include "matrix.h"


using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
void main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    CourseWorkUser::MenuForm form;
    Application::Run(% form);
}

System::Void CourseWorkUser::MenuForm::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
}


System::Void CourseWorkUser::MenuForm::button6_Click(System::Object^ sender, System::EventArgs^ e)
{
    for (int i = 0; i < dataGridView1->Rows->Count; i++) {
        for (int j = 0; j < dataGridView1->Rows->Count; j++) {
            dataGridView1->Rows[i]->Cells[j]->Value = 0;
         }
    }
}

System::Void CourseWorkUser::MenuForm::radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
    int size = Convert::ToInt32(numericUpDown1->Value);
    dataGridView2->ColumnCount = 1;
    dataGridView2->RowCount = size;
    dataGridView2->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
    dataGridView2->AutoResizeColumns();
    double** Matr = new double* [size];
    for (int i = 0; i < size; i++) {
        Matr[i] = new double[size];
    }
    dataGridView1->ColumnCount = size;
    dataGridView1->RowCount = size;
    dataGridView1->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
    dataGridView1->AutoResizeColumns();
    for (int i = 0; i < size; i++) {
        dataGridView1->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
        dataGridView2->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            dataGridView1->Rows[i]->Cells[j]->Value = 0;
        }
    }
    dataGridView2->Rows[0]->Cells[0]->Value = 1;
    for (int i = 1; i < size; i++) {
        dataGridView2->Rows[i]->Cells[0]->Value = 0;
    }
}

System::Void CourseWorkUser::MenuForm::radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
    dataGridView2->Rows->Clear();
    int size = Convert::ToInt32(numericUpDown1->Value);
    double** Matr = new double* [size];
    for (int i = 0; i < size; i++) {
        Matr[i] = new double[size];
    }
    dataGridView1->ColumnCount = size;
    dataGridView1->RowCount = size;
    dataGridView1->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
    dataGridView1->AutoResizeColumns();
    for (int i = 0; i < size; i++) {
        dataGridView1->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            dataGridView1->Rows[i]->Cells[j]->Value = 0;
        }
    }
}

System::Void CourseWorkUser::MenuForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (!radioButton1->Checked && !radioButton2->Checked)MessageBox::Show("???? ?????, ??????? ????? ??????????", "???????");
    else {
        if (dataGridView1->ColumnCount != Convert::ToInt32(numericUpDown1->Value))MessageBox::Show("???? ?????, ??????? ??????????? ???????.", "???????");
        else {
            ChartForm^ form = gcnew ChartForm();
            this->Hide();
            form->Show();
            int size = Convert::ToInt32(numericUpDown1->Value);
            double** Matr = new double* [size];
            for (int i = 0; i < size; i++) {
                Matr[i] = new double[size];
            }
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    Matr[i][j] = Convert::ToDouble(dataGridView1->Rows[i]->Cells[j]->Value);
                }
            }
            if (radioButton1->Checked) {
                matrix Matrix(size);
                Matrix.setMatr(Matr);
                if (Matrix.Danilevsky()) {
                    form->printChart(Matrix.getP(), Matrix.getAreaOfRoots());
                    form->printVectors(Matrix.getVectorsX());
                    form->printSelfNumbers(Matrix.getRoot());
                    form->printStatistics(Matrix.getIterations(), Matrix.getMultiplies());
                }
                else {
                    form->Hide();
                    MenuForm^ form = gcnew MenuForm();
                    form->Show();
                }
            }
            else if (radioButton2->Checked) {
                double** vectorY0 = new double* [size];
                for (int i = 0; i < size; i++) {
                    vectorY0[i] = new double[1];
                    vectorY0[i][0] = Convert::ToDouble(dataGridView2->Rows[i]->Cells[0]->Value);
                }
                matrix Matrix(size);
                Matrix.setMatr(Matr);
                Matrix.setY0(vectorY0);
                if (Matrix.Krylov()) {
                    form->printChart(Matrix.getP(), Matrix.getAreaOfRoots());
                    form->printVectors(Matrix.getVectorsX());
                    form->printSelfNumbers(Matrix.getRoot());
                    form->printStatistics(Matrix.getIterations(), Matrix.getMultiplies());
                }
                else {
                    form->Hide();
                    MenuForm^ form = gcnew MenuForm();
                    form->Show();
                }
            }
    }
}
}

System::Void CourseWorkUser::MenuForm::dataGridView1_CellEndEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    double q;
    
    if (!Double::TryParse(Convert::ToString(dataGridView1->CurrentCell->Value), q)) {
        MessageBox::Show("? ??????? ????? ??????? ???? ?????", "???????");
        dataGridView1->CurrentCell->Value = "0";
    }
    String^ s = Convert::ToString(dataGridView1->CurrentCell->Value);
    if (s->IndexOf(',') != -1) {
        MessageBox::Show("? ??????? ????? ???? ??????? ????? . ", "???????");
        dataGridView1->CurrentCell->Value = "0";
    }
}

System::Void CourseWorkUser::MenuForm::dataGridView2_CellEndEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    double q;
    if (!Double::TryParse(Convert::ToString(dataGridView2->CurrentCell->Value), q)) {
        MessageBox::Show("? ??????? ????? ??????? ???? ?????", "???????");
        dataGridView2->CurrentCell->Value = "0";
    }
    String^ s = Convert::ToString(dataGridView2->CurrentCell->Value);
    if (s->IndexOf(',') != -1) {
        MessageBox::Show("? ??????? ????? ???? ??????? ????? . ", "???????");
        dataGridView2->CurrentCell->Value = "0";
    }
}

System::Void CourseWorkUser::MenuForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (!radioButton1->Checked && !radioButton2->Checked)MessageBox::Show("???? ?????, ??????? ????? ??????????", "???????");
    else
    if (radioButton2->Checked) {
        int size = Convert::ToInt32(numericUpDown1->Value);
        dataGridView2->ColumnCount = 1;
        dataGridView2->RowCount = size;
        dataGridView2->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
        dataGridView2->AutoResizeColumns();
        dataGridView1->ColumnCount = size;
        dataGridView1->RowCount = size;
        dataGridView1->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
        dataGridView1->AutoResizeColumns();
        for (int i = 0; i < size; i++) {
            dataGridView1->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
            dataGridView2->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
        }
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                dataGridView1->Rows[i]->Cells[j]->Value = 0;
            }
        }
        dataGridView2->Rows[0]->Cells[0]->Value = 1;
        for (int i = 1; i < size; i++) {
            dataGridView2->Rows[i]->Cells[0]->Value = 0;
        }
    }
    else if (radioButton1->Checked) {
        dataGridView2->Rows->Clear();
        int size = Convert::ToInt32(numericUpDown1->Value);
        dataGridView1->ColumnCount = size;
        dataGridView1->RowCount = size;
        dataGridView1->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
        dataGridView1->AutoResizeColumns();
        for (int i = 0; i < size; i++) {
            dataGridView1->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
        }
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                dataGridView1->Rows[i]->Cells[j]->Value = 0;
            }
        }
    }
}

System::Void CourseWorkUser::MenuForm::???????????ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MessageBox::Show("???????? ???????? ??????? ??????? ????? ????? ??-01\n??? ??. ????? ???????????\n??????? ?????. ", "??? ????????");
}

System::Void CourseWorkUser::MenuForm::??????????ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MessageBox::Show("1. ??????? ?????, ???? ?????? ????'????? ??????.\n2. ??????? ??????????? ??????????? ??????? ???????.\n3. ??????? ???????. \n4. ????????? ?????? ?????????.\n*****\n??? ?????????? ??????? ??????? ?????????? ?????? ???????? ?? ?????????????.\n???? ???? ????????? ? ???? ???? ???????? ?? ??????? ???????? ??????????.   ", "??????????");
}
