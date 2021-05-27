#pragma once

namespace CourseWorkUser {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MenuForm
	/// </summary>
public ref class MenuForm : public System::Windows::Forms::Form
{
public:
	MenuForm(void)
	{
		InitializeComponent();
		//
		//TODO: добавьте код конструктора
		//
	}

protected:
	/// <summary>
	/// Освободить все используемые ресурсы.
	/// </summary>
	~MenuForm()
	{
		if (components)
		{
			delete components;
		}
	}


private: System::Windows::Forms::Button^ button3;

private: System::Windows::Forms::Label^ label1;
private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
private: System::Windows::Forms::DataGridView^ dataGridView1;

private: System::Windows::Forms::Button^ button6;
private: System::Windows::Forms::RadioButton^ radioButton1;
private: System::Windows::Forms::RadioButton^ radioButton2;
private: System::Windows::Forms::DataGridView^ dataGridView2;
private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::Button^ button1;


protected:

private:
	/// <summary>
	/// Обязательная переменная конструктора.
	/// </summary>
	System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
	/// <summary>
	/// Требуемый метод для поддержки конструктора — не изменяйте 
	/// содержимое этого метода с помощью редактора кода.
	/// </summary>
	void InitializeComponent(void)
	{
		this->button3 = (gcnew System::Windows::Forms::Button());
		this->label1 = (gcnew System::Windows::Forms::Label());
		this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
		this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
		this->button6 = (gcnew System::Windows::Forms::Button());
		this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
		this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
		this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
		this->label2 = (gcnew System::Windows::Forms::Label());
		this->button1 = (gcnew System::Windows::Forms::Button());
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
		this->SuspendLayout();
		// 
		// button3
		// 
		this->button3->Location = System::Drawing::Point(335, 470);
		this->button3->Name = L"button3";
		this->button3->Size = System::Drawing::Size(75, 23);
		this->button3->TabIndex = 1;
		this->button3->Text = L"Вихід";
		this->button3->UseVisualStyleBackColor = true;
		this->button3->Click += gcnew System::EventHandler(this, &MenuForm::button3_Click);
		// 
		// label1
		// 
		this->label1->AutoSize = true;
		this->label1->Location = System::Drawing::Point(73, 173);
		this->label1->Name = L"label1";
		this->label1->Size = System::Drawing::Size(67, 13);
		this->label1->TabIndex = 3;
		this->label1->Text = L"Розмірність";
		// 
		// numericUpDown1
		// 
		this->numericUpDown1->Location = System::Drawing::Point(76, 189);
		this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
		this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
		this->numericUpDown1->Name = L"numericUpDown1";
		this->numericUpDown1->Size = System::Drawing::Size(64, 20);
		this->numericUpDown1->TabIndex = 4;
		this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
		// 
		// dataGridView1
		// 
		this->dataGridView1->AllowUserToAddRows = false;
		this->dataGridView1->AllowUserToDeleteRows = false;
		this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::DisplayedCells;
		this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::DisplayedCells;
		this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
		this->dataGridView1->ColumnHeadersVisible = false;
		this->dataGridView1->Location = System::Drawing::Point(187, 12);
		this->dataGridView1->Name = L"dataGridView1";
		this->dataGridView1->Size = System::Drawing::Size(360, 343);
		this->dataGridView1->TabIndex = 5;
		this->dataGridView1->CellEndEdit += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MenuForm::dataGridView1_CellEndEdit);
		// 
		// button6
		// 
		this->button6->Location = System::Drawing::Point(76, 305);
		this->button6->Name = L"button6";
		this->button6->Size = System::Drawing::Size(75, 23);
		this->button6->TabIndex = 7;
		this->button6->Text = L"Очистити";
		this->button6->UseVisualStyleBackColor = true;
		this->button6->Click += gcnew System::EventHandler(this, &MenuForm::button6_Click);
		// 
		// radioButton1
		// 
		this->radioButton1->AutoSize = true;
		this->radioButton1->Location = System::Drawing::Point(119, 476);
		this->radioButton1->Name = L"radioButton1";
		this->radioButton1->Size = System::Drawing::Size(105, 17);
		this->radioButton1->TabIndex = 8;
		this->radioButton1->TabStop = true;
		this->radioButton1->Text = L"Данилевського";
		this->radioButton1->UseVisualStyleBackColor = true;
		this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &MenuForm::radioButton1_CheckedChanged);
		// 
		// radioButton2
		// 
		this->radioButton2->AutoSize = true;
		this->radioButton2->Location = System::Drawing::Point(534, 476);
		this->radioButton2->Name = L"radioButton2";
		this->radioButton2->Size = System::Drawing::Size(68, 17);
		this->radioButton2->TabIndex = 8;
		this->radioButton2->TabStop = true;
		this->radioButton2->Text = L"Крилова";
		this->radioButton2->UseVisualStyleBackColor = true;
		this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &MenuForm::radioButton2_CheckedChanged);
		// 
		// dataGridView2
		// 
		this->dataGridView2->AllowUserToAddRows = false;
		this->dataGridView2->AllowUserToDeleteRows = false;
		this->dataGridView2->AllowUserToResizeColumns = false;
		this->dataGridView2->AllowUserToResizeRows = false;
		this->dataGridView2->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::DisplayedCells;
		this->dataGridView2->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::DisplayedCells;
		this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
		this->dataGridView2->ColumnHeadersVisible = false;
		this->dataGridView2->Location = System::Drawing::Point(594, 114);
		this->dataGridView2->Name = L"dataGridView2";
		this->dataGridView2->Size = System::Drawing::Size(100, 214);
		this->dataGridView2->TabIndex = 9;
		this->dataGridView2->CellEndEdit += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MenuForm::dataGridView2_CellEndEdit);
		// 
		// label2
		// 
		this->label2->Location = System::Drawing::Point(591, 75);
		this->label2->Name = L"label2";
		this->label2->Size = System::Drawing::Size(106, 36);
		this->label2->TabIndex = 10;
		this->label2->Text = L"Стартовий вектор       (для Крилова)";
		// 
		// button1
		// 
		this->button1->Location = System::Drawing::Point(279, 380);
		this->button1->Name = L"button1";
		this->button1->Size = System::Drawing::Size(180, 55);
		this->button1->TabIndex = 11;
		this->button1->Text = L"Обчислити";
		this->button1->UseVisualStyleBackColor = true;
		this->button1->Click += gcnew System::EventHandler(this, &MenuForm::button1_Click);
		// 
		// MenuForm
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(754, 518);
		this->Controls->Add(this->button1);
		this->Controls->Add(this->label2);
		this->Controls->Add(this->dataGridView2);
		this->Controls->Add(this->radioButton2);
		this->Controls->Add(this->radioButton1);
		this->Controls->Add(this->button6);
		this->Controls->Add(this->dataGridView1);
		this->Controls->Add(this->numericUpDown1);
		this->Controls->Add(this->label1);
		this->Controls->Add(this->button3);
		this->MaximizeBox = false;
		this->MaximumSize = System::Drawing::Size(770, 557);
		this->MinimumSize = System::Drawing::Size(770, 557);
		this->Name = L"MenuForm";
		this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
		this->Text = L"Пошук";
		this->Load += gcnew System::EventHandler(this, &MenuForm::MenuForm_Load);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
		this->ResumeLayout(false);
		this->PerformLayout();

	}
#pragma endregion
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void MenuForm_Load(System::Object^ sender, System::EventArgs^ e) {}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void dataGridView1_CellEndEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
private: System::Void dataGridView2_CellEndEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
};
}
