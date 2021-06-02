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
private: System::Windows::Forms::Button^ button2;
private: System::Windows::Forms::MenuStrip^ menuStrip1;
private: System::Windows::Forms::ToolStripMenuItem^ проПрограмуToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ інструкціяToolStripMenuItem;


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
		this->button2 = (gcnew System::Windows::Forms::Button());
		this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
		this->проПрограмуToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->інструкціяToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
		this->menuStrip1->SuspendLayout();
		this->SuspendLayout();
		// 
		// button3
		// 
		this->button3->BackColor = System::Drawing::SystemColors::Control;
		this->button3->Font = (gcnew System::Drawing::Font(L"Oswald", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->button3->ForeColor = System::Drawing::SystemColors::ControlText;
		this->button3->Location = System::Drawing::Point(12, 470);
		this->button3->Name = L"button3";
		this->button3->Size = System::Drawing::Size(75, 36);
		this->button3->TabIndex = 1;
		this->button3->Text = L"Вихід";
		this->button3->UseVisualStyleBackColor = false;
		this->button3->Click += gcnew System::EventHandler(this, &MenuForm::button3_Click);
		// 
		// label1
		// 
		this->label1->AutoSize = true;
		this->label1->Font = (gcnew System::Drawing::Font(L"Oswald", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->label1->Location = System::Drawing::Point(46, 52);
		this->label1->Name = L"label1";
		this->label1->Size = System::Drawing::Size(111, 32);
		this->label1->TabIndex = 3;
		this->label1->Text = L"Розмірність";
		this->label1->Click += gcnew System::EventHandler(this, &MenuForm::label1_Click);
		// 
		// numericUpDown1
		// 
		this->numericUpDown1->Location = System::Drawing::Point(68, 87);
		this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
		this->numericUpDown1->MaximumSize = System::Drawing::Size(75, 0);
		this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
		this->numericUpDown1->MinimumSize = System::Drawing::Size(75, 0);
		this->numericUpDown1->Name = L"numericUpDown1";
		this->numericUpDown1->Size = System::Drawing::Size(75, 20);
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
		this->dataGridView1->Location = System::Drawing::Point(193, 51);
		this->dataGridView1->Name = L"dataGridView1";
		this->dataGridView1->Size = System::Drawing::Size(360, 343);
		this->dataGridView1->TabIndex = 5;
		this->dataGridView1->CellEndEdit += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MenuForm::dataGridView1_CellEndEdit);
		// 
		// button6
		// 
		this->button6->Font = (gcnew System::Drawing::Font(L"Oswald", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->button6->Location = System::Drawing::Point(52, 353);
		this->button6->Name = L"button6";
		this->button6->Size = System::Drawing::Size(105, 41);
		this->button6->TabIndex = 7;
		this->button6->Text = L"Очистити";
		this->button6->UseVisualStyleBackColor = true;
		this->button6->Click += gcnew System::EventHandler(this, &MenuForm::button6_Click);
		// 
		// radioButton1
		// 
		this->radioButton1->AutoSize = true;
		this->radioButton1->Font = (gcnew System::Drawing::Font(L"Oswald", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->radioButton1->Location = System::Drawing::Point(143, 452);
		this->radioButton1->Name = L"radioButton1";
		this->radioButton1->Size = System::Drawing::Size(135, 31);
		this->radioButton1->TabIndex = 8;
		this->radioButton1->TabStop = true;
		this->radioButton1->Text = L"Данилевського";
		this->radioButton1->UseVisualStyleBackColor = true;
		this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &MenuForm::radioButton1_CheckedChanged);
		// 
		// radioButton2
		// 
		this->radioButton2->AutoSize = true;
		this->radioButton2->Font = (gcnew System::Drawing::Font(L"Oswald", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->radioButton2->Location = System::Drawing::Point(470, 452);
		this->radioButton2->Name = L"radioButton2";
		this->radioButton2->Size = System::Drawing::Size(88, 31);
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
		this->dataGridView2->Location = System::Drawing::Point(600, 153);
		this->dataGridView2->Name = L"dataGridView2";
		this->dataGridView2->Size = System::Drawing::Size(100, 214);
		this->dataGridView2->TabIndex = 9;
		this->dataGridView2->CellEndEdit += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MenuForm::dataGridView2_CellEndEdit);
		// 
		// label2
		// 
		this->label2->Font = (gcnew System::Drawing::Font(L"Oswald", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->label2->Location = System::Drawing::Point(580, 93);
		this->label2->Name = L"label2";
		this->label2->Size = System::Drawing::Size(137, 57);
		this->label2->TabIndex = 10;
		this->label2->Text = L"Стартовий вектор     (для Крилова)";
		// 
		// button1
		// 
		this->button1->BackColor = System::Drawing::SystemColors::ActiveCaption;
		this->button1->Font = (gcnew System::Drawing::Font(L"Oswald", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->button1->Location = System::Drawing::Point(284, 428);
		this->button1->Name = L"button1";
		this->button1->Size = System::Drawing::Size(180, 55);
		this->button1->TabIndex = 11;
		this->button1->Text = L"Обчислити";
		this->button1->UseVisualStyleBackColor = false;
		this->button1->Click += gcnew System::EventHandler(this, &MenuForm::button1_Click);
		// 
		// button2
		// 
		this->button2->Font = (gcnew System::Drawing::Font(L"Oswald", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->button2->Location = System::Drawing::Point(52, 113);
		this->button2->Name = L"button2";
		this->button2->Size = System::Drawing::Size(105, 60);
		this->button2->TabIndex = 12;
		this->button2->Text = L"Оновити розмірність";
		this->button2->UseVisualStyleBackColor = true;
		this->button2->Click += gcnew System::EventHandler(this, &MenuForm::button2_Click);
		// 
		// menuStrip1
		// 
		this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
			this->проПрограмуToolStripMenuItem,
				this->інструкціяToolStripMenuItem
		});
		this->menuStrip1->Location = System::Drawing::Point(0, 0);
		this->menuStrip1->Name = L"menuStrip1";
		this->menuStrip1->Size = System::Drawing::Size(754, 24);
		this->menuStrip1->TabIndex = 13;
		this->menuStrip1->Text = L"menuStrip1";
		// 
		// проПрограмуToolStripMenuItem
		// 
		this->проПрограмуToolStripMenuItem->Name = L"проПрограмуToolStripMenuItem";
		this->проПрограмуToolStripMenuItem->Size = System::Drawing::Size(99, 20);
		this->проПрограмуToolStripMenuItem->Text = L"Про програму";
		this->проПрограмуToolStripMenuItem->Click += gcnew System::EventHandler(this, &MenuForm::проПрограмуToolStripMenuItem_Click);
		// 
		// інструкціяToolStripMenuItem
		// 
		this->інструкціяToolStripMenuItem->Name = L"інструкціяToolStripMenuItem";
		this->інструкціяToolStripMenuItem->Size = System::Drawing::Size(75, 20);
		this->інструкціяToolStripMenuItem->Text = L"Інструкція";
		this->інструкціяToolStripMenuItem->Click += gcnew System::EventHandler(this, &MenuForm::інструкціяToolStripMenuItem_Click);
		// 
		// MenuForm
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(754, 518);
		this->Controls->Add(this->button2);
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
		this->Controls->Add(this->menuStrip1);
		this->MainMenuStrip = this->menuStrip1;
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
		this->menuStrip1->ResumeLayout(false);
		this->menuStrip1->PerformLayout();
		this->ResumeLayout(false);
		this->PerformLayout();

	}
#pragma endregion
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e); // кнопка виходу 
private: System::Void MenuForm_Load(System::Object^ sender, System::EventArgs^ e) {} 
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e); // кнопка очистки матриць
private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e); // вибір метода Крилова
private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e); // вибір метода Данилевського
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e); // кнока обчислити 
private: System::Void dataGridView1_CellEndEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e); // основна матриця
private: System::Void dataGridView2_CellEndEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e); // стартовий вектор для метода Крилова
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e){}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e); // кнопка оновлення розмірності матриці
private: System::Void проПрограмуToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e); // вивід повідомлення про програму
private: System::Void інструкціяToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e); // вивід короткої інструкції користувача
};
}
