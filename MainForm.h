#include "UltrahapticsManger.h"

#pragma once

namespace UltrahapticsStandalone {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form, IUltrahapticsListener
	{
	public:
		UltrahapticsManger^ ultrahapticsMan;

		MainForm(void)
		{
			InitializeComponent();

			ultrahapticsMan = gcnew UltrahapticsManger();
			
			txtGlassAngle->Text = "" + ultrahapticsMan->glassAngle;
			txtPivotToUltrahapics->Text = "" + ultrahapticsMan->height_PivotToUltrahaptics;
			txtPivotToModel->Text = "" + ultrahapticsMan->height_PivotToModelBottom;
			txtUltrahapticsToGlass->Text = "" + ultrahapticsMan->baseDistanceFromGlass;
			txtModelToGlass->Text = "" + ultrahapticsMan->modelDistanceFromGlass;
			txtModelWidth->Text = "" + ultrahapticsMan->modelWidth;
			txtModelLength->Text = "" + ultrahapticsMan->modelLength;
			txtFreq->Text = "" + ultrahapticsMan->frequency;
			txtIntensity->Text = "" + ultrahapticsMan->intensity;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::CheckBox^  chkEnable;
	private: System::Windows::Forms::GroupBox^  groupBox1;

	private: System::Windows::Forms::Label^  label1;


	private: System::Windows::Forms::Label^  label6;


	private: System::Windows::Forms::Label^  label5;


	private: System::Windows::Forms::Label^  label4;


	private: System::Windows::Forms::Label^  label3;


	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  txtGlassAngle;
	private: System::Windows::Forms::GroupBox^  groupBox2;


	private: System::Windows::Forms::Label^  label9;


	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::NumericUpDown^  txtModelToGlass;

	private: System::Windows::Forms::NumericUpDown^  txtUltrahapticsToGlass;
	private: System::Windows::Forms::NumericUpDown^  txtPivotToModel;
	private: System::Windows::Forms::NumericUpDown^  txtPivotToUltrahapics;
	private: System::Windows::Forms::NumericUpDown^  txtModelLength;
	private: System::Windows::Forms::NumericUpDown^  txtModelWidth;
	private: System::Windows::Forms::NumericUpDown^  txtIntensity;
	private: System::Windows::Forms::NumericUpDown^  txtFreq;
	private: System::Windows::Forms::Label^  lblServerError;

	

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
			this->chkEnable = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->txtModelToGlass = (gcnew System::Windows::Forms::NumericUpDown());
			this->txtUltrahapticsToGlass = (gcnew System::Windows::Forms::NumericUpDown());
			this->txtPivotToModel = (gcnew System::Windows::Forms::NumericUpDown());
			this->txtPivotToUltrahapics = (gcnew System::Windows::Forms::NumericUpDown());
			this->txtModelLength = (gcnew System::Windows::Forms::NumericUpDown());
			this->txtModelWidth = (gcnew System::Windows::Forms::NumericUpDown());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->txtGlassAngle = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->txtIntensity = (gcnew System::Windows::Forms::NumericUpDown());
			this->txtFreq = (gcnew System::Windows::Forms::NumericUpDown());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->lblServerError = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->txtModelToGlass))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->txtUltrahapticsToGlass))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->txtPivotToModel))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->txtPivotToUltrahapics))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->txtModelLength))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->txtModelWidth))->BeginInit();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->txtIntensity))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->txtFreq))->BeginInit();
			this->SuspendLayout();
			// 
			// chkEnable
			// 
			this->chkEnable->AutoSize = true;
			this->chkEnable->Location = System::Drawing::Point(23, 13);
			this->chkEnable->Name = L"chkEnable";
			this->chkEnable->Size = System::Drawing::Size(151, 17);
			this->chkEnable->TabIndex = 0;
			this->chkEnable->Text = L"Enable UltraHaptics Matrix";
			this->chkEnable->UseVisualStyleBackColor = true;
			this->chkEnable->CheckedChanged += gcnew System::EventHandler(this, &MainForm::chkEnable_CheckedChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->txtModelToGlass);
			this->groupBox1->Controls->Add(this->txtUltrahapticsToGlass);
			this->groupBox1->Controls->Add(this->txtPivotToModel);
			this->groupBox1->Controls->Add(this->txtPivotToUltrahapics);
			this->groupBox1->Controls->Add(this->txtModelLength);
			this->groupBox1->Controls->Add(this->txtModelWidth);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(12, 36);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(326, 183);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Positions (mm)";
			// 
			// txtModelToGlass
			// 
			this->txtModelToGlass->DecimalPlaces = 1;
			this->txtModelToGlass->Location = System::Drawing::Point(194, 150);
			this->txtModelToGlass->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, 0 });
			this->txtModelToGlass->Name = L"txtModelToGlass";
			this->txtModelToGlass->Size = System::Drawing::Size(120, 20);
			this->txtModelToGlass->TabIndex = 16;
			// 
			// txtUltrahapticsToGlass
			// 
			this->txtUltrahapticsToGlass->DecimalPlaces = 1;
			this->txtUltrahapticsToGlass->Location = System::Drawing::Point(194, 124);
			this->txtUltrahapticsToGlass->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, 0 });
			this->txtUltrahapticsToGlass->Name = L"txtUltrahapticsToGlass";
			this->txtUltrahapticsToGlass->Size = System::Drawing::Size(120, 20);
			this->txtUltrahapticsToGlass->TabIndex = 15;
			// 
			// txtPivotToModel
			// 
			this->txtPivotToModel->DecimalPlaces = 1;
			this->txtPivotToModel->Location = System::Drawing::Point(194, 98);
			this->txtPivotToModel->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, 0 });
			this->txtPivotToModel->Name = L"txtPivotToModel";
			this->txtPivotToModel->Size = System::Drawing::Size(120, 20);
			this->txtPivotToModel->TabIndex = 14;
			// 
			// txtPivotToUltrahapics
			// 
			this->txtPivotToUltrahapics->DecimalPlaces = 1;
			this->txtPivotToUltrahapics->Location = System::Drawing::Point(194, 72);
			this->txtPivotToUltrahapics->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, 0 });
			this->txtPivotToUltrahapics->Name = L"txtPivotToUltrahapics";
			this->txtPivotToUltrahapics->Size = System::Drawing::Size(120, 20);
			this->txtPivotToUltrahapics->TabIndex = 13;
			// 
			// txtModelLength
			// 
			this->txtModelLength->DecimalPlaces = 1;
			this->txtModelLength->Location = System::Drawing::Point(194, 44);
			this->txtModelLength->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, 0 });
			this->txtModelLength->Name = L"txtModelLength";
			this->txtModelLength->Size = System::Drawing::Size(120, 20);
			this->txtModelLength->TabIndex = 12;
			// 
			// txtModelWidth
			// 
			this->txtModelWidth->DecimalPlaces = 1;
			this->txtModelWidth->Location = System::Drawing::Point(194, 20);
			this->txtModelWidth->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, 0 });
			this->txtModelWidth->Name = L"txtModelWidth";
			this->txtModelWidth->Size = System::Drawing::Size(120, 20);
			this->txtModelWidth->TabIndex = 5;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(11, 152);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(152, 13);
			this->label6->TabIndex = 10;
			this->label6->Text = L"Distance From Model To Glass";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(11, 126);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(172, 13);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Distance From Ultrahapics to Glass";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(11, 100);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(175, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Height From Pivot To Model Bottom";
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(11, 74);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(166, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Height From Pivot To Ultrahaptics";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(11, 48);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(72, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Model Length";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(11, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(67, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Model Width";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(216, 14);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(63, 13);
			this->label7->TabIndex = 2;
			this->label7->Text = L"Glass Angle";
			// 
			// txtGlassAngle
			// 
			this->txtGlassAngle->Location = System::Drawing::Point(285, 10);
			this->txtGlassAngle->Name = L"txtGlassAngle";
			this->txtGlassAngle->Size = System::Drawing::Size(74, 20);
			this->txtGlassAngle->TabIndex = 3;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->txtIntensity);
			this->groupBox2->Controls->Add(this->txtFreq);
			this->groupBox2->Controls->Add(this->label10);
			this->groupBox2->Controls->Add(this->label9);
			this->groupBox2->Controls->Add(this->label8);
			this->groupBox2->Location = System::Drawing::Point(344, 36);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(168, 87);
			this->groupBox2->TabIndex = 4;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Ultrahaptics Controls";
			// 
			// txtIntensity
			// 
			this->txtIntensity->DecimalPlaces = 1;
			this->txtIntensity->Location = System::Drawing::Point(69, 46);
			this->txtIntensity->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, 0 });
			this->txtIntensity->Name = L"txtIntensity";
			this->txtIntensity->Size = System::Drawing::Size(93, 20);
			this->txtIntensity->TabIndex = 7;
			// 
			// txtFreq
			// 
			this->txtFreq->DecimalPlaces = 1;
			this->txtFreq->Location = System::Drawing::Point(69, 20);
			this->txtFreq->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, 0 });
			this->txtFreq->Name = L"txtFreq";
			this->txtFreq->Size = System::Drawing::Size(63, 20);
			this->txtFreq->TabIndex = 6;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(138, 22);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(20, 13);
			this->label10->TabIndex = 5;
			this->label10->Text = L"Hz";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(6, 51);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(46, 13);
			this->label9->TabIndex = 3;
			this->label9->Text = L"Intensity";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(6, 22);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(57, 13);
			this->label8->TabIndex = 0;
			this->label8->Text = L"Frequency";
			// 
			// lblServerError
			// 
			this->lblServerError->AutoSize = true;
			this->lblServerError->Location = System::Drawing::Point(366, 14);
			this->lblServerError->Name = L"lblServerError";
			this->lblServerError->Size = System::Drawing::Size(0, 13);
			this->lblServerError->TabIndex = 5;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(705, 282);
			this->Controls->Add(this->lblServerError);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->txtGlassAngle);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->chkEnable);
			this->Name = L"MainForm";
			this->Text = L"Ultrahaptics";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::MainForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->txtModelToGlass))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->txtUltrahapticsToGlass))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->txtPivotToModel))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->txtPivotToUltrahapics))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->txtModelLength))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->txtModelWidth))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->txtIntensity))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->txtFreq))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:


		//delegate void UpdateDelegate();
		virtual void hapticsChange();
		
		void updateAllControlValues()
		{
			txtGlassAngle->Text = "" + ultrahapticsMan->glassAngle;
			lblServerError->Text = "" + ultrahapticsMan->serverError;

			try
			{
				ultrahapticsMan->modelWidth = Double::Parse(txtModelWidth->Text);
			}
			catch (Exception^) {}

			try
			{
				ultrahapticsMan->modelLength = Double::Parse(txtModelLength->Text);
			}
			catch (Exception^) {}


			try
			{
				ultrahapticsMan->frequency = Double::Parse(txtFreq->Text);
			}
			catch (Exception^) {}

			try
			{
				ultrahapticsMan->intensity = Double::Parse(txtIntensity->Text);
			}
			catch (Exception^) {}

			try
			{
				ultrahapticsMan->modelDistanceFromGlass = Double::Parse(txtModelToGlass->Text);
			}
			catch (Exception^) {}

			try
			{
				ultrahapticsMan->baseDistanceFromGlass = Double::Parse(txtUltrahapticsToGlass->Text);
			}
			catch (Exception^) {}

			try
			{
				ultrahapticsMan->height_PivotToUltrahaptics = Double::Parse(txtPivotToUltrahapics->Text);
			}
			catch (Exception^) {}

			try
			{
				ultrahapticsMan->height_PivotToModelBottom = Double::Parse(txtPivotToModel->Text);
			}
			catch (Exception^) {}


		}



	private: System::Void MainForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
	{
		delete ultrahapticsMan;
	}
	private: System::Void chkEnable_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
	{
		ultrahapticsMan->emitterEnabled = chkEnable->Checked;
	}
	private: System::Void label9_Click(System::Object^  sender, System::EventArgs^  e)
	{
		updateAllControlValues();
	}

	private: System::Void textBox7_TextChanged(System::Object^  sender, System::EventArgs^  e)
	{
		updateAllControlValues();
	}

	private: System::Void txtModelWidth_TextChanged(System::Object^  sender, System::EventArgs^  e)
	{
		updateAllControlValues();
	}

	private: System::Void txtModelLength_TextChanged(System::Object^  sender, System::EventArgs^  e)
	{
		updateAllControlValues();
	}

	private: System::Void txtPivotToUltrahapics_TextChanged(System::Object^  sender, System::EventArgs^  e)
	{
		updateAllControlValues();
	}

	private: System::Void txtPivotToModel_TextChanged(System::Object^  sender, System::EventArgs^  e)
	{
		updateAllControlValues();
	}

	private: System::Void txtUltrahapticsToGlass_TextChanged(System::Object^  sender, System::EventArgs^  e)
	{
		updateAllControlValues();
	}

	private: System::Void txtModelToGlass_TextChanged(System::Object^  sender, System::EventArgs^  e)
	{
		updateAllControlValues();
	}

	private: System::Void txtFreq_TextChanged(System::Object^  sender, System::EventArgs^  e)
	{
		updateAllControlValues();
	}
private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e)
{
	ultrahapticsMan->addListener(this);
}
};
}
