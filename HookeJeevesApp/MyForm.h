#pragma once
# include "hooke.hpp"
#include <sstream>

namespace HookeJeevesApp {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Threading;
    using namespace System::Globalization;
    using namespace System::Drawing;

    const int kMaxN = 100;
    double f(double x[], int nvars);
    double tempA[kMaxN][kMaxN] = {0};
    double tempB[kMaxN] = { 0 };

    /// <summary>
    /// Summary for MyForm
    /// </summary>
    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
            Thread::CurrentThread->CurrentUICulture = gcnew CultureInfo("ru-RU");
            InitializeComponent();
            dataNotFilled->Visible = false;
            NEquat->Value = 3;
            equationsCountChabged();
            initializeGrids(); // comment if don't need init values

            //
            //TODO: Add the constructor code here
            //
        }

    public: void initializeGrids()
    {
        A->Rows[0]->Cells[0]->Value = "2"; A->Rows[0]->Cells[1]->Value = "-1"; A->Rows[0]->Cells[2]->Value = "1";
        A->Rows[1]->Cells[0]->Value = "3"; A->Rows[1]->Cells[1]->Value = "2"; A->Rows[1]->Cells[2]->Value = "-5";
        A->Rows[2]->Cells[0]->Value = "1"; A->Rows[2]->Cells[1]->Value = "3"; A->Rows[2]->Cells[2]->Value = "-2";
        b->Rows[0]->Cells[0]->Value = "0";
        b->Rows[1]->Cells[0]->Value = "1";
        b->Rows[2]->Cells[0]->Value = "4";
        X0->Rows[0]->Cells[0]->Value = "0";
        X0->Rows[0]->Cells[1]->Value = "0";
        X0->Rows[0]->Cells[2]->Value = "0";
    }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Button^  button1;
    private: System::Windows::Forms::DataGridView^  b;
    private: System::Windows::Forms::NumericUpDown^  NEquat;



    private: System::Windows::Forms::Label^  label1;
    private: System::Windows::Forms::Label^  label2;
    private: System::Windows::Forms::NumericUpDown^  Iters;

    private: System::Windows::Forms::Label^  label3;
    private: System::Windows::Forms::TextBox^  Eps;

    private: System::Windows::Forms::TextBox^  Step;

    private: System::Windows::Forms::Label^  label4;
    private: System::Windows::Forms::GroupBox^  groupBox1;
    private: System::Windows::Forms::GroupBox^  groupBox2;

    private: System::Windows::Forms::Label^  label5;
    private: System::Windows::Forms::DataGridView^  X;
    private: System::Windows::Forms::TextBox^  ResIters;



    private: System::Windows::Forms::Label^  label9;
    private: System::Windows::Forms::Label^  label8;
    private: System::Windows::Forms::Label^  dataNotFilled;

    private: System::Windows::Forms::Label^  label6;
    private: System::Windows::Forms::DataGridView^  A;
    private: System::Windows::Forms::TextBox^  textBox1;
    private: System::Windows::Forms::Label^  label7;
    private: System::Windows::Forms::DataGridView^  X0;

    private: System::Windows::Forms::Label^  label10;

    protected:

    private:
        /// <summary>
        /// Required designer variable.
        /// </summary>
        System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->b = (gcnew System::Windows::Forms::DataGridView());
            this->NEquat = (gcnew System::Windows::Forms::NumericUpDown());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->Iters = (gcnew System::Windows::Forms::NumericUpDown());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->Eps = (gcnew System::Windows::Forms::TextBox());
            this->Step = (gcnew System::Windows::Forms::TextBox());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
            this->X0 = (gcnew System::Windows::Forms::DataGridView());
            this->label10 = (gcnew System::Windows::Forms::Label());
            this->A = (gcnew System::Windows::Forms::DataGridView());
            this->label9 = (gcnew System::Windows::Forms::Label());
            this->label8 = (gcnew System::Windows::Forms::Label());
            this->dataNotFilled = (gcnew System::Windows::Forms::Label());
            this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->ResIters = (gcnew System::Windows::Forms::TextBox());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->X = (gcnew System::Windows::Forms::DataGridView());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->b))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NEquat))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Iters))->BeginInit();
            this->groupBox1->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->X0))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A))->BeginInit();
            this->groupBox2->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->X))->BeginInit();
            this->SuspendLayout();
            // 
            // button1
            // 
            resources->ApplyResources(this->button1, L"button1");
            this->button1->Name = L"button1";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
            // 
            // b
            // 
            this->b->AllowUserToAddRows = false;
            this->b->AllowUserToDeleteRows = false;
            this->b->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            resources->ApplyResources(this->b, L"b");
            this->b->Name = L"b";
            this->b->RowTemplate->Height = 24;
            this->b->EditingControlShowing += gcnew System::Windows::Forms::DataGridViewEditingControlShowingEventHandler(this, &MyForm::A_EditingControlShowing);
            this->b->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::Eps_KeyPress);
            // 
            // NEquat
            // 
            resources->ApplyResources(this->NEquat, L"NEquat");
            this->NEquat->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
            this->NEquat->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            this->NEquat->Name = L"NEquat";
            this->NEquat->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
            this->NEquat->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDown1_ValueChanged);
            // 
            // label1
            // 
            resources->ApplyResources(this->label1, L"label1");
            this->label1->Name = L"label1";
            // 
            // label2
            // 
            resources->ApplyResources(this->label2, L"label2");
            this->label2->Name = L"label2";
            // 
            // Iters
            // 
            resources->ApplyResources(this->Iters, L"Iters");
            this->Iters->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
            this->Iters->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
            this->Iters->Name = L"Iters";
            this->Iters->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5000, 0, 0, 0 });
            // 
            // label3
            // 
            resources->ApplyResources(this->label3, L"label3");
            this->label3->Name = L"label3";
            // 
            // Eps
            // 
            resources->ApplyResources(this->Eps, L"Eps");
            this->Eps->Name = L"Eps";
            this->Eps->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::Eps_KeyPress);
            // 
            // Step
            // 
            resources->ApplyResources(this->Step, L"Step");
            this->Step->Name = L"Step";
            this->Step->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::Eps_KeyPress);
            // 
            // label4
            // 
            resources->ApplyResources(this->label4, L"label4");
            this->label4->Name = L"label4";
            // 
            // groupBox1
            // 
            this->groupBox1->Controls->Add(this->X0);
            this->groupBox1->Controls->Add(this->label10);
            this->groupBox1->Controls->Add(this->A);
            this->groupBox1->Controls->Add(this->label9);
            this->groupBox1->Controls->Add(this->label8);
            this->groupBox1->Controls->Add(this->dataNotFilled);
            this->groupBox1->Controls->Add(this->b);
            this->groupBox1->Controls->Add(this->Step);
            this->groupBox1->Controls->Add(this->label4);
            this->groupBox1->Controls->Add(this->NEquat);
            this->groupBox1->Controls->Add(this->Eps);
            this->groupBox1->Controls->Add(this->label1);
            this->groupBox1->Controls->Add(this->label3);
            this->groupBox1->Controls->Add(this->Iters);
            this->groupBox1->Controls->Add(this->label2);
            resources->ApplyResources(this->groupBox1, L"groupBox1");
            this->groupBox1->Name = L"groupBox1";
            this->groupBox1->TabStop = false;
            // 
            // X0
            // 
            this->X0->AllowUserToAddRows = false;
            this->X0->AllowUserToDeleteRows = false;
            this->X0->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            resources->ApplyResources(this->X0, L"X0");
            this->X0->Name = L"X0";
            this->X0->RowTemplate->Height = 24;
            this->X0->EditingControlShowing += gcnew System::Windows::Forms::DataGridViewEditingControlShowingEventHandler(this, &MyForm::A_EditingControlShowing);
            this->X0->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::Eps_KeyPress);
            // 
            // label10
            // 
            resources->ApplyResources(this->label10, L"label10");
            this->label10->Name = L"label10";
            // 
            // A
            // 
            this->A->AllowUserToAddRows = false;
            this->A->AllowUserToDeleteRows = false;
            this->A->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            resources->ApplyResources(this->A, L"A");
            this->A->Name = L"A";
            this->A->RowTemplate->Height = 24;
            this->A->EditingControlShowing += gcnew System::Windows::Forms::DataGridViewEditingControlShowingEventHandler(this, &MyForm::A_EditingControlShowing);
            this->A->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::Eps_KeyPress);
            // 
            // label9
            // 
            resources->ApplyResources(this->label9, L"label9");
            this->label9->Name = L"label9";
            // 
            // label8
            // 
            resources->ApplyResources(this->label8, L"label8");
            this->label8->Name = L"label8";
            // 
            // dataNotFilled
            // 
            resources->ApplyResources(this->dataNotFilled, L"dataNotFilled");
            this->dataNotFilled->BackColor = System::Drawing::SystemColors::Control;
            this->dataNotFilled->ForeColor = System::Drawing::Color::Red;
            this->dataNotFilled->Name = L"dataNotFilled";
            // 
            // groupBox2
            // 
            this->groupBox2->Controls->Add(this->label7);
            this->groupBox2->Controls->Add(this->textBox1);
            this->groupBox2->Controls->Add(this->label6);
            this->groupBox2->Controls->Add(this->ResIters);
            this->groupBox2->Controls->Add(this->label5);
            this->groupBox2->Controls->Add(this->X);
            resources->ApplyResources(this->groupBox2, L"groupBox2");
            this->groupBox2->Name = L"groupBox2";
            this->groupBox2->TabStop = false;
            // 
            // label7
            // 
            resources->ApplyResources(this->label7, L"label7");
            this->label7->Name = L"label7";
            // 
            // textBox1
            // 
            resources->ApplyResources(this->textBox1, L"textBox1");
            this->textBox1->Name = L"textBox1";
            // 
            // label6
            // 
            resources->ApplyResources(this->label6, L"label6");
            this->label6->Name = L"label6";
            // 
            // ResIters
            // 
            resources->ApplyResources(this->ResIters, L"ResIters");
            this->ResIters->Name = L"ResIters";
            // 
            // label5
            // 
            resources->ApplyResources(this->label5, L"label5");
            this->label5->Name = L"label5";
            // 
            // X
            // 
            this->X->AllowUserToAddRows = false;
            this->X->AllowUserToDeleteRows = false;
            this->X->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            resources->ApplyResources(this->X, L"X");
            this->X->Name = L"X";
            this->X->RowTemplate->Height = 24;
            this->X->EditingControlShowing += gcnew System::Windows::Forms::DataGridViewEditingControlShowingEventHandler(this, &MyForm::A_EditingControlShowing);
            this->X->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::Eps_KeyPress);
            // 
            // MyForm
            // 
            resources->ApplyResources(this, L"$this");
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->Controls->Add(this->groupBox2);
            this->Controls->Add(this->groupBox1);
            this->Controls->Add(this->button1);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->Name = L"MyForm";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->b))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NEquat))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Iters))->EndInit();
            this->groupBox1->ResumeLayout(false);
            this->groupBox1->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->X0))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A))->EndInit();
            this->groupBox2->ResumeLayout(false);
            this->groupBox2->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->X))->EndInit();
            this->ResumeLayout(false);

        }
#pragma endregion
    private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
        if (!allDataIsFilled()) return;

        CultureInfo ^culture = gcnew CultureInfo("en-GB");
        //CultureInfo::CreateSpecificCulture("en-GB");

        int VARS = A->RowCount;
        for (int i = 0; i < VARS; i++)
        {
            for (int j = 0; j < VARS; j++)
                if (A->Rows[i]->Cells[j]->Value && A->Rows[i]->Cells[j]->Value->ToString() != "")
                {
                    tempA[i][j] = System::Double::Parse(A->Rows[i]->Cells[j]->Value->ToString(), culture);
                }
        }

        for (int i = 0; i < VARS; i++)
            if (b->Rows[i]->Cells[0]->Value && b->Rows[i]->Cells[0]->Value->ToString() != "")
            {
                tempB[i] = System::Double::Parse(b->Rows[i]->Cells[0]->Value->ToString(), culture);
            }

        button1->Enabled = false;
        double	*startpt = new double[VARS], *endpt = new double[VARS];
        for (int i = 0; i < VARS; i++)
            startpt[i] = System::Double::Parse(X0->Rows[0]->Cells[i]->Value->ToString(), culture);

        ResIters->Text = System::Convert::ToString(hooke(VARS, startpt, endpt, System::Double::Parse(Step->Text, culture), System::Double::Parse(Eps->Text, culture), System::Int32::Parse(Iters->Text, culture), &f));
        outputX(endpt, VARS);
        textBox1->Text = System::Convert::ToString(f(endpt,VARS));
        delete [] startpt;
        delete[] endpt;
        button1->Enabled = true;
    }
    private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
    }
    private: System::Void numericUpDown1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
        equationsCountChabged();
    }


#pragma region User methods
    public: void outputX(double x[], int nvars)
    {
        X->Rows->Clear();
        X->ColumnCount = 1;
        for (int i = 0; i < nvars; i++)
            X->Rows->Add(System::Convert::ToString(x[i]));
        X->Refresh();
    }

    public: void updateAllGrids(int count)
    {
        A->ColumnHeadersVisible = false;
        A->RowHeadersVisible = false;
        b->ColumnHeadersVisible = false;
        b->RowHeadersVisible = false;
        X->ColumnHeadersVisible = false;
        X->RowHeadersVisible = false;
        X0->ColumnHeadersVisible = false;
        X0->RowHeadersVisible = false;

        A->Rows->Clear();
        A->ColumnCount = count;
        for (int i = 0; i < count; i++)
            A->Rows->Add();
        A->Refresh();

        b->Rows->Clear();
        b->ColumnCount = 1;
        for (int i = 0; i < count; i++)
            b->Rows->Add();
        b->Refresh();

        X->Rows->Clear();
        X->ColumnCount = 1;
        for (int i = 0; i < count; i++)
            X->Rows->Add();
        X->Refresh();

        X0->Rows->Clear();
        X0->ColumnCount = count;
        X0->Rows->Add();
        X0->Refresh();
    }

    public: bool allDataIsFilled()
    {
        bool dataFilled = true;
        int count = A->RowCount;

        for (int i = 0; i < count; i++)
        {
            for (int j = 0; j < count; j++)
                if (A->Rows[i]->Cells[j]->Value == nullptr || A->Rows[i]->Cells[j]->Value->ToString() == "")
                {
                    dataFilled = false;
                    break;
                }
        }

        for (int i = 0; i < count && dataFilled; i++)
        {
            for (int j = 0; j < 1; j++)
                if (b->Rows[i]->Cells[j]->Value == nullptr || b->Rows[i]->Cells[j]->Value->ToString() == "")
                {
                    dataFilled = false;
                    break;
                }
        }

        for (int i = 0; i < 1 && dataFilled; i++)
        {
            for (int j = 0; j < count; j++)
                if (X0->Rows[i]->Cells[j]->Value == nullptr || X0->Rows[i]->Cells[j]->Value->ToString() == "")
                {
                    dataFilled = false;
                    break;
                }
        }

        if (Eps->Text == "" || Step->Text == "")
            dataFilled = false;

        dataNotFilled->Visible = !dataFilled;
        return dataFilled;
    }

    public: void equationsCountChabged() {
        updateAllGrids((int)this->NEquat->Value);
    }
#pragma endregion
    private: System::Void Eps_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
        if (!System::Char::IsControl(e->KeyChar) && !System::Char::IsDigit(e->KeyChar) &&
            (e->KeyChar != '.') && (e->KeyChar != 'e') && (e->KeyChar != 'E')
            && (e->KeyChar != '-') && (e->KeyChar != '+'))
        {
            e->Handled = true;
        }

        if (sender->GetType()->ToString()->CompareTo(("TextBox")))
        {
            TextBox ^sndr = (TextBox^)sender;
            // only allow one decimal point
            if ((e->KeyChar == '.') && sndr && ((sndr)->Text->IndexOf('.') > -1))
            {
                e->Handled = true;
            }
        }
    }
private: System::Void A_EditingControlShowing(System::Object^  sender, System::Windows::Forms::DataGridViewEditingControlShowingEventArgs^  e) {
    DataGridViewTextBoxEditingControl ^tb = (DataGridViewTextBoxEditingControl^)e->Control;
    tb->KeyPress += gcnew KeyPressEventHandler(this, &MyForm::Eps_KeyPress);

    e->Control->KeyPress += gcnew KeyPressEventHandler(this, &MyForm::Eps_KeyPress);
}
};

    double f(double x[], int nvars)
    {
        double sum = 0;
        for (int i = 0; i < nvars; i++)
        {
            double eq = 0;
            for (int j = 0; j < nvars; j++)
            {
                eq += tempA[i][j] * x[j];
                double tA = tempA[i][j];
                double tx = x[j];
                tx;
            }
            double tb = tempB[i];
            eq -= tempB[i];
            sum += Math::Pow(eq, 2.0);  // or  Math::Abs(eq);
        }
        
        return sum;
    }
}
