#pragma once

#include "Matrixes/Matrixes.cpp"

namespace KusrsovaVisual {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for sparseDemoForm
	/// </summary>
	public ref class sparseDemoForm : public System::Windows::Forms::Form
	{
	public:
		sparseDemoForm(void)
		{
			InitializeComponent();
			AutoSize = true;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~sparseDemoForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabPage^ convToCommon;
	protected:

	protected:








	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::DataGridView^ DGconvComTo;

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::DataGridView^ DGconvComFrom;
	private: System::Windows::Forms::TabPage^ convToSparse;




	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::DataGridView^ DGconvSprTo;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridView^ DGconvSprFrom;
	private: System::Windows::Forms::TabPage^ matrixOperations;



	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;


	private: System::Windows::Forms::DataGridView^ DGoprationRezult;
	private: System::Windows::Forms::DataGridView^ DGsecondOperand;
	private: System::Windows::Forms::DataGridView^ DGfirstOperand;
	private: System::Windows::Forms::TabControl^ tabControl1;


	private: System::Windows::Forms::Button^ BtoCommon;
	private: System::Windows::Forms::Button^ BtoSparse;
	private: System::Windows::Forms::Button^ BmultMatrix;
	private: System::Windows::Forms::Button^ BaddMatrix;
	private: System::Windows::Forms::Button^ BrezultOp;
	private: System::Windows::Forms::Button^ BsecondOperand;
	private: System::Windows::Forms::Button^ BfirstOperand;



















	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		// Tab 1
		SparseMatrix<float>* t1opr1 = NULL;
		SparseMatrix<float>* t1opr2 = NULL;
		SparseMatrix<float>* t1rezt = NULL;
		bool t1firstInit = false;
		bool t1secondInit = false;
		bool t1rezultInit = false;
		// Tab 2
		CommonMatrix<float>* t2opr = NULL;
		SparseMatrix<float>* t2rez = NULL;
		bool t2oprInit = false;
		bool t2rezInit = false;
		// Tab 3
		SparseMatrix<float>* t3opr = NULL;
		CommonMatrix<float>* t3rez = NULL;
		bool t3oprInit = false;
		bool t3rezInit = false;

	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ TBfirstL;

	private: System::Windows::Forms::TextBox^ TBfirstC;

	private: System::Windows::Forms::TextBox^ TBfirstR;

	private: System::Windows::Forms::Button^ BsetFirst;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::TextBox^ TBsecondL;

	private: System::Windows::Forms::TextBox^ TBsecondC;

private: System::Windows::Forms::TextBox^ TBsecondR;

	private: System::Windows::Forms::Button^ BsetSecond;
private: System::Windows::Forms::TextBox^ TBconvLCom;

private: System::Windows::Forms::TextBox^ TBconvCCom;


private: System::Windows::Forms::TextBox^ TBconvRCom;


private: System::Windows::Forms::Button^ BsetConvCom;
private: System::Windows::Forms::Button^ BconvFileCom;





private: System::Windows::Forms::Label^ label15;
private: System::Windows::Forms::Label^ label16;
private: System::Windows::Forms::Label^ label17;
private: System::Windows::Forms::TextBox^ TBconvSprC;


private: System::Windows::Forms::TextBox^ TBconvSprR;

private: System::Windows::Forms::Button^ BsetConvSpr;
private: System::Windows::Forms::Button^ BconvFileSpr;
private: System::Windows::Forms::Label^ label19;
private: System::Windows::Forms::Label^ label20;
private: System::Windows::Forms::Button^ BconvRezCom;
private: System::Windows::Forms::Button^ BconvRezSpr;
private: System::Windows::Forms::TabPage^ mainPage;
private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
private: System::Windows::Forms::ToolStripMenuItem^ aboutRClick;


private: System::Windows::Forms::ToolStripMenuItem^ clearThisTab;
private: System::Windows::Forms::ToolStripMenuItem^ openGuide;
private: System::Windows::Forms::ToolStripMenuItem^ clearAllTabs;
private: System::Windows::Forms::ToolStripMenuItem^ returnToMain;
private: System::Windows::Forms::ToolStripMenuItem^ appInfoRClick;
private: System::Windows::Forms::MenuStrip^ menuStrip1;
private: System::Windows::Forms::ToolStripMenuItem^ guideToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ aboutUsToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ appInfoToolStripMenuItem;
private: System::Windows::Forms::PictureBox^ pictureBox1;
private: System::Windows::Forms::Button^ gotoCommonToSparse;
private: System::Windows::Forms::Button^ gotoSparseToCommon;
private: System::Windows::Forms::Button^ gotoMatrixOper;
















private: System::ComponentModel::IContainer^ components;




#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
	void ClearTabFirst();
	void ClearTabSecond();
	void ClearTabThird();
	void ShowAboutUs();
	void ShowGuides();
	void ShowAppInfo();
	void InitializeComponent(void)
		{
		this->components = (gcnew System::ComponentModel::Container());
		System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(sparseDemoForm::typeid));
		this->convToCommon = (gcnew System::Windows::Forms::TabPage());
		this->BconvRezCom = (gcnew System::Windows::Forms::Button());
		this->TBconvLCom = (gcnew System::Windows::Forms::TextBox());
		this->TBconvCCom = (gcnew System::Windows::Forms::TextBox());
		this->TBconvRCom = (gcnew System::Windows::Forms::TextBox());
		this->BsetConvCom = (gcnew System::Windows::Forms::Button());
		this->BconvFileCom = (gcnew System::Windows::Forms::Button());
		this->label15 = (gcnew System::Windows::Forms::Label());
		this->label16 = (gcnew System::Windows::Forms::Label());
		this->label17 = (gcnew System::Windows::Forms::Label());
		this->BtoCommon = (gcnew System::Windows::Forms::Button());
		this->label7 = (gcnew System::Windows::Forms::Label());
		this->DGconvComTo = (gcnew System::Windows::Forms::DataGridView());
		this->label8 = (gcnew System::Windows::Forms::Label());
		this->DGconvComFrom = (gcnew System::Windows::Forms::DataGridView());
		this->convToSparse = (gcnew System::Windows::Forms::TabPage());
		this->BconvRezSpr = (gcnew System::Windows::Forms::Button());
		this->TBconvSprC = (gcnew System::Windows::Forms::TextBox());
		this->TBconvSprR = (gcnew System::Windows::Forms::TextBox());
		this->BsetConvSpr = (gcnew System::Windows::Forms::Button());
		this->BconvFileSpr = (gcnew System::Windows::Forms::Button());
		this->label19 = (gcnew System::Windows::Forms::Label());
		this->label20 = (gcnew System::Windows::Forms::Label());
		this->BtoSparse = (gcnew System::Windows::Forms::Button());
		this->label6 = (gcnew System::Windows::Forms::Label());
		this->DGconvSprTo = (gcnew System::Windows::Forms::DataGridView());
		this->label1 = (gcnew System::Windows::Forms::Label());
		this->DGconvSprFrom = (gcnew System::Windows::Forms::DataGridView());
		this->matrixOperations = (gcnew System::Windows::Forms::TabPage());
		this->TBsecondL = (gcnew System::Windows::Forms::TextBox());
		this->TBsecondC = (gcnew System::Windows::Forms::TextBox());
		this->TBsecondR = (gcnew System::Windows::Forms::TextBox());
		this->BsetSecond = (gcnew System::Windows::Forms::Button());
		this->TBfirstL = (gcnew System::Windows::Forms::TextBox());
		this->TBfirstC = (gcnew System::Windows::Forms::TextBox());
		this->TBfirstR = (gcnew System::Windows::Forms::TextBox());
		this->BsetFirst = (gcnew System::Windows::Forms::Button());
		this->BrezultOp = (gcnew System::Windows::Forms::Button());
		this->BsecondOperand = (gcnew System::Windows::Forms::Button());
		this->BfirstOperand = (gcnew System::Windows::Forms::Button());
		this->BmultMatrix = (gcnew System::Windows::Forms::Button());
		this->BaddMatrix = (gcnew System::Windows::Forms::Button());
		this->label5 = (gcnew System::Windows::Forms::Label());
		this->label4 = (gcnew System::Windows::Forms::Label());
		this->label3 = (gcnew System::Windows::Forms::Label());
		this->DGoprationRezult = (gcnew System::Windows::Forms::DataGridView());
		this->DGsecondOperand = (gcnew System::Windows::Forms::DataGridView());
		this->DGfirstOperand = (gcnew System::Windows::Forms::DataGridView());
		this->label2 = (gcnew System::Windows::Forms::Label());
		this->label11 = (gcnew System::Windows::Forms::Label());
		this->label10 = (gcnew System::Windows::Forms::Label());
		this->label9 = (gcnew System::Windows::Forms::Label());
		this->label12 = (gcnew System::Windows::Forms::Label());
		this->label13 = (gcnew System::Windows::Forms::Label());
		this->label14 = (gcnew System::Windows::Forms::Label());
		this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
		this->mainPage = (gcnew System::Windows::Forms::TabPage());
		this->gotoCommonToSparse = (gcnew System::Windows::Forms::Button());
		this->gotoSparseToCommon = (gcnew System::Windows::Forms::Button());
		this->gotoMatrixOper = (gcnew System::Windows::Forms::Button());
		this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
		this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
		this->guideToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->aboutUsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->appInfoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
		this->aboutRClick = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->openGuide = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->appInfoRClick = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->clearThisTab = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->clearAllTabs = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->returnToMain = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->convToCommon->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGconvComTo))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGconvComFrom))->BeginInit();
		this->convToSparse->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGconvSprTo))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGconvSprFrom))->BeginInit();
		this->matrixOperations->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGoprationRezult))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGsecondOperand))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGfirstOperand))->BeginInit();
		this->tabControl1->SuspendLayout();
		this->mainPage->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
		this->menuStrip1->SuspendLayout();
		this->contextMenuStrip1->SuspendLayout();
		this->SuspendLayout();
		// 
		// convToCommon
		// 
		this->convToCommon->BackColor = System::Drawing::Color::NavajoWhite;
		this->convToCommon->Controls->Add(this->BconvRezCom);
		this->convToCommon->Controls->Add(this->TBconvLCom);
		this->convToCommon->Controls->Add(this->TBconvCCom);
		this->convToCommon->Controls->Add(this->TBconvRCom);
		this->convToCommon->Controls->Add(this->BsetConvCom);
		this->convToCommon->Controls->Add(this->BconvFileCom);
		this->convToCommon->Controls->Add(this->label15);
		this->convToCommon->Controls->Add(this->label16);
		this->convToCommon->Controls->Add(this->label17);
		this->convToCommon->Controls->Add(this->BtoCommon);
		this->convToCommon->Controls->Add(this->label7);
		this->convToCommon->Controls->Add(this->DGconvComTo);
		this->convToCommon->Controls->Add(this->label8);
		this->convToCommon->Controls->Add(this->DGconvComFrom);
		this->convToCommon->Location = System::Drawing::Point(10, 48);
		this->convToCommon->Name = L"convToCommon";
		this->convToCommon->Padding = System::Windows::Forms::Padding(3);
		this->convToCommon->Size = System::Drawing::Size(1947, 1081);
		this->convToCommon->TabIndex = 2;
		this->convToCommon->Text = L"Convert To Common Matrix";
		// 
		// BconvRezCom
		// 
		this->BconvRezCom->Enabled = false;
		this->BconvRezCom->Location = System::Drawing::Point(1495, 910);
		this->BconvRezCom->Name = L"BconvRezCom";
		this->BconvRezCom->Size = System::Drawing::Size(384, 65);
		this->BconvRezCom->TabIndex = 29;
		this->BconvRezCom->Text = L"Save to file";
		this->BconvRezCom->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
		this->BconvRezCom->UseVisualStyleBackColor = true;
		this->BconvRezCom->Click += gcnew System::EventHandler(this, &sparseDemoForm::BconvRezCom_Click);
		// 
		// TBconvLCom
		// 
		this->TBconvLCom->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->TBconvLCom->Location = System::Drawing::Point(468, 996);
		this->TBconvLCom->Name = L"TBconvLCom";
		this->TBconvLCom->Size = System::Drawing::Size(122, 68);
		this->TBconvLCom->TabIndex = 25;
		this->TBconvLCom->Text = L"5";
		// 
		// TBconvCCom
		// 
		this->TBconvCCom->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->TBconvCCom->Location = System::Drawing::Point(277, 996);
		this->TBconvCCom->Name = L"TBconvCCom";
		this->TBconvCCom->Size = System::Drawing::Size(123, 68);
		this->TBconvCCom->TabIndex = 24;
		this->TBconvCCom->Text = L"5";
		// 
		// TBconvRCom
		// 
		this->TBconvRCom->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->TBconvRCom->Location = System::Drawing::Point(93, 996);
		this->TBconvRCom->Name = L"TBconvRCom";
		this->TBconvRCom->Size = System::Drawing::Size(119, 68);
		this->TBconvRCom->TabIndex = 23;
		this->TBconvRCom->Text = L"5";
		// 
		// BsetConvCom
		// 
		this->BsetConvCom->Location = System::Drawing::Point(42, 909);
		this->BsetConvCom->Name = L"BsetConvCom";
		this->BsetConvCom->Size = System::Drawing::Size(139, 64);
		this->BsetConvCom->TabIndex = 22;
		this->BsetConvCom->Text = L"Set";
		this->BsetConvCom->UseVisualStyleBackColor = true;
		this->BsetConvCom->Click += gcnew System::EventHandler(this, &sparseDemoForm::BsetConv_Click);
		// 
		// BconvFileCom
		// 
		this->BconvFileCom->Location = System::Drawing::Point(205, 910);
		this->BconvFileCom->Name = L"BconvFileCom";
		this->BconvFileCom->Size = System::Drawing::Size(384, 65);
		this->BconvFileCom->TabIndex = 21;
		this->BconvFileCom->Text = L"Read from file";
		this->BconvFileCom->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
		this->BconvFileCom->UseVisualStyleBackColor = true;
		this->BconvFileCom->Click += gcnew System::EventHandler(this, &sparseDemoForm::BconvFile_Click);
		// 
		// label15
		// 
		this->label15->AutoSize = true;
		this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->label15->Location = System::Drawing::Point(416, 996);
		this->label15->Name = L"label15";
		this->label15->Size = System::Drawing::Size(40, 63);
		this->label15->TabIndex = 28;
		this->label15->Text = L"l";
		// 
		// label16
		// 
		this->label16->AutoSize = true;
		this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->label16->Location = System::Drawing::Point(231, 996);
		this->label16->Name = L"label16";
		this->label16->Size = System::Drawing::Size(54, 63);
		this->label16->TabIndex = 27;
		this->label16->Text = L"c";
		// 
		// label17
		// 
		this->label17->AutoSize = true;
		this->label17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->label17->Location = System::Drawing::Point(42, 996);
		this->label17->Name = L"label17";
		this->label17->Size = System::Drawing::Size(45, 63);
		this->label17->TabIndex = 26;
		this->label17->Text = L"r";
		// 
		// BtoCommon
		// 
		this->BtoCommon->BackColor = System::Drawing::Color::NavajoWhite;
		this->BtoCommon->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"BtoCommon.BackgroundImage")));
		this->BtoCommon->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
		this->BtoCommon->Enabled = false;
		this->BtoCommon->ForeColor = System::Drawing::SystemColors::ControlText;
		this->BtoCommon->Location = System::Drawing::Point(642, 398);
		this->BtoCommon->Name = L"BtoCommon";
		this->BtoCommon->Size = System::Drawing::Size(303, 201);
		this->BtoCommon->TabIndex = 13;
		this->BtoCommon->UseVisualStyleBackColor = false;
		this->BtoCommon->Click += gcnew System::EventHandler(this, &sparseDemoForm::BtoCommon_Click);
		// 
		// label7
		// 
		this->label7->AutoSize = true;
		this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->label7->Location = System::Drawing::Point(1176, 25);
		this->label7->Name = L"label7";
		this->label7->Size = System::Drawing::Size(474, 76);
		this->label7->TabIndex = 9;
		this->label7->Text = L"Convert Rezult";
		// 
		// DGconvComTo
		// 
		this->DGconvComTo->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
		this->DGconvComTo->Location = System::Drawing::Point(984, 104);
		this->DGconvComTo->Name = L"DGconvComTo";
		this->DGconvComTo->RowHeadersVisible = false;
		this->DGconvComTo->RowHeadersWidth = 102;
		this->DGconvComTo->RowTemplate->Height = 20;
		this->DGconvComTo->Size = System::Drawing::Size(895, 798);
		this->DGconvComTo->TabIndex = 8;
		// 
		// label8
		// 
		this->label8->AutoSize = true;
		this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->label8->Location = System::Drawing::Point(91, 27);
		this->label8->Name = L"label8";
		this->label8->Size = System::Drawing::Size(441, 76);
		this->label8->TabIndex = 7;
		this->label8->Text = L"Convert From";
		// 
		// DGconvComFrom
		// 
		this->DGconvComFrom->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
		this->DGconvComFrom->Location = System::Drawing::Point(39, 104);
		this->DGconvComFrom->Name = L"DGconvComFrom";
		this->DGconvComFrom->RowHeadersVisible = false;
		this->DGconvComFrom->RowHeadersWidth = 102;
		this->DGconvComFrom->RowTemplate->Height = 20;
		this->DGconvComFrom->Size = System::Drawing::Size(550, 800);
		this->DGconvComFrom->TabIndex = 1;
		// 
		// convToSparse
		// 
		this->convToSparse->BackColor = System::Drawing::Color::NavajoWhite;
		this->convToSparse->Controls->Add(this->BconvRezSpr);
		this->convToSparse->Controls->Add(this->TBconvSprC);
		this->convToSparse->Controls->Add(this->TBconvSprR);
		this->convToSparse->Controls->Add(this->BsetConvSpr);
		this->convToSparse->Controls->Add(this->BconvFileSpr);
		this->convToSparse->Controls->Add(this->label19);
		this->convToSparse->Controls->Add(this->label20);
		this->convToSparse->Controls->Add(this->BtoSparse);
		this->convToSparse->Controls->Add(this->label6);
		this->convToSparse->Controls->Add(this->DGconvSprTo);
		this->convToSparse->Controls->Add(this->label1);
		this->convToSparse->Controls->Add(this->DGconvSprFrom);
		this->convToSparse->Location = System::Drawing::Point(10, 48);
		this->convToSparse->Name = L"convToSparse";
		this->convToSparse->Padding = System::Windows::Forms::Padding(3);
		this->convToSparse->Size = System::Drawing::Size(1947, 1081);
		this->convToSparse->TabIndex = 1;
		this->convToSparse->Text = L"Convert To Sparse Matrix";
		// 
		// BconvRezSpr
		// 
		this->BconvRezSpr->Enabled = false;
		this->BconvRezSpr->Location = System::Drawing::Point(1495, 918);
		this->BconvRezSpr->Name = L"BconvRezSpr";
		this->BconvRezSpr->Size = System::Drawing::Size(384, 65);
		this->BconvRezSpr->TabIndex = 36;
		this->BconvRezSpr->Text = L"Save to file";
		this->BconvRezSpr->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
		this->BconvRezSpr->UseVisualStyleBackColor = true;
		this->BconvRezSpr->Click += gcnew System::EventHandler(this, &sparseDemoForm::BconvRezSpr_Click);
		// 
		// TBconvSprC
		// 
		this->TBconvSprC->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->TBconvSprC->Location = System::Drawing::Point(412, 920);
		this->TBconvSprC->Name = L"TBconvSprC";
		this->TBconvSprC->Size = System::Drawing::Size(123, 68);
		this->TBconvSprC->TabIndex = 32;
		this->TBconvSprC->Text = L"5";
		// 
		// TBconvSprR
		// 
		this->TBconvSprR->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->TBconvSprR->Location = System::Drawing::Point(228, 920);
		this->TBconvSprR->Name = L"TBconvSprR";
		this->TBconvSprR->Size = System::Drawing::Size(119, 68);
		this->TBconvSprR->TabIndex = 31;
		this->TBconvSprR->Text = L"5";
		// 
		// BsetConvSpr
		// 
		this->BsetConvSpr->Location = System::Drawing::Point(35, 921);
		this->BsetConvSpr->Name = L"BsetConvSpr";
		this->BsetConvSpr->Size = System::Drawing::Size(139, 64);
		this->BsetConvSpr->TabIndex = 30;
		this->BsetConvSpr->Text = L"Set";
		this->BsetConvSpr->UseVisualStyleBackColor = true;
		this->BsetConvSpr->Click += gcnew System::EventHandler(this, &sparseDemoForm::BsetConvSpr_Click);
		// 
		// BconvFileSpr
		// 
		this->BconvFileSpr->Location = System::Drawing::Point(578, 920);
		this->BconvFileSpr->Name = L"BconvFileSpr";
		this->BconvFileSpr->Size = System::Drawing::Size(347, 65);
		this->BconvFileSpr->TabIndex = 29;
		this->BconvFileSpr->Text = L"Read from file";
		this->BconvFileSpr->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
		this->BconvFileSpr->UseVisualStyleBackColor = true;
		this->BconvFileSpr->Click += gcnew System::EventHandler(this, &sparseDemoForm::BconvFileSpr_Click);
		// 
		// label19
		// 
		this->label19->AutoSize = true;
		this->label19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->label19->Location = System::Drawing::Point(366, 920);
		this->label19->Name = L"label19";
		this->label19->Size = System::Drawing::Size(54, 63);
		this->label19->TabIndex = 35;
		this->label19->Text = L"c";
		// 
		// label20
		// 
		this->label20->AutoSize = true;
		this->label20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->label20->Location = System::Drawing::Point(177, 920);
		this->label20->Name = L"label20";
		this->label20->Size = System::Drawing::Size(45, 63);
		this->label20->TabIndex = 34;
		this->label20->Text = L"r";
		// 
		// BtoSparse
		// 
		this->BtoSparse->BackColor = System::Drawing::Color::NavajoWhite;
		this->BtoSparse->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"BtoSparse.BackgroundImage")));
		this->BtoSparse->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
		this->BtoSparse->Enabled = false;
		this->BtoSparse->ForeColor = System::Drawing::SystemColors::ControlText;
		this->BtoSparse->Location = System::Drawing::Point(962, 387);
		this->BtoSparse->Name = L"BtoSparse";
		this->BtoSparse->Size = System::Drawing::Size(303, 201);
		this->BtoSparse->TabIndex = 12;
		this->BtoSparse->UseVisualStyleBackColor = false;
		this->BtoSparse->Click += gcnew System::EventHandler(this, &sparseDemoForm::BtoSparse_Click);
		// 
		// label6
		// 
		this->label6->AutoSize = true;
		this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->label6->Location = System::Drawing::Point(1361, 25);
		this->label6->Name = L"label6";
		this->label6->Size = System::Drawing::Size(474, 76);
		this->label6->TabIndex = 9;
		this->label6->Text = L"Convert Rezult";
		// 
		// DGconvSprTo
		// 
		this->DGconvSprTo->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
		this->DGconvSprTo->Location = System::Drawing::Point(1303, 104);
		this->DGconvSprTo->Name = L"DGconvSprTo";
		this->DGconvSprTo->RowHeadersVisible = false;
		this->DGconvSprTo->RowHeadersWidth = 102;
		this->DGconvSprTo->RowTemplate->Height = 20;
		this->DGconvSprTo->Size = System::Drawing::Size(576, 800);
		this->DGconvSprTo->TabIndex = 8;
		// 
		// label1
		// 
		this->label1->AutoSize = true;
		this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->label1->Location = System::Drawing::Point(232, 25);
		this->label1->Name = L"label1";
		this->label1->Size = System::Drawing::Size(441, 76);
		this->label1->TabIndex = 7;
		this->label1->Text = L"Convert From";
		this->label1->Click += gcnew System::EventHandler(this, &sparseDemoForm::label1_Click);
		// 
		// DGconvSprFrom
		// 
		this->DGconvSprFrom->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
		this->DGconvSprFrom->Location = System::Drawing::Point(35, 104);
		this->DGconvSprFrom->Name = L"DGconvSprFrom";
		this->DGconvSprFrom->RowHeadersVisible = false;
		this->DGconvSprFrom->RowHeadersWidth = 102;
		this->DGconvSprFrom->RowTemplate->Height = 20;
		this->DGconvSprFrom->Size = System::Drawing::Size(890, 800);
		this->DGconvSprFrom->TabIndex = 1;
		// 
		// matrixOperations
		// 
		this->matrixOperations->BackColor = System::Drawing::Color::DarkCyan;
		this->matrixOperations->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
		this->matrixOperations->Controls->Add(this->TBsecondL);
		this->matrixOperations->Controls->Add(this->TBsecondC);
		this->matrixOperations->Controls->Add(this->TBsecondR);
		this->matrixOperations->Controls->Add(this->BsetSecond);
		this->matrixOperations->Controls->Add(this->TBfirstL);
		this->matrixOperations->Controls->Add(this->TBfirstC);
		this->matrixOperations->Controls->Add(this->TBfirstR);
		this->matrixOperations->Controls->Add(this->BsetFirst);
		this->matrixOperations->Controls->Add(this->BrezultOp);
		this->matrixOperations->Controls->Add(this->BsecondOperand);
		this->matrixOperations->Controls->Add(this->BfirstOperand);
		this->matrixOperations->Controls->Add(this->BmultMatrix);
		this->matrixOperations->Controls->Add(this->BaddMatrix);
		this->matrixOperations->Controls->Add(this->label5);
		this->matrixOperations->Controls->Add(this->label4);
		this->matrixOperations->Controls->Add(this->label3);
		this->matrixOperations->Controls->Add(this->DGoprationRezult);
		this->matrixOperations->Controls->Add(this->DGsecondOperand);
		this->matrixOperations->Controls->Add(this->DGfirstOperand);
		this->matrixOperations->Controls->Add(this->label2);
		this->matrixOperations->Controls->Add(this->label11);
		this->matrixOperations->Controls->Add(this->label10);
		this->matrixOperations->Controls->Add(this->label9);
		this->matrixOperations->Controls->Add(this->label12);
		this->matrixOperations->Controls->Add(this->label13);
		this->matrixOperations->Controls->Add(this->label14);
		this->matrixOperations->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
		this->matrixOperations->Location = System::Drawing::Point(10, 48);
		this->matrixOperations->Name = L"matrixOperations";
		this->matrixOperations->Padding = System::Windows::Forms::Padding(3);
		this->matrixOperations->Size = System::Drawing::Size(1947, 1081);
		this->matrixOperations->TabIndex = 0;
		this->matrixOperations->Text = L"Matrix operations";
		// 
		// TBsecondL
		// 
		this->TBsecondL->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->TBsecondL->Location = System::Drawing::Point(1129, 985);
		this->TBsecondL->Name = L"TBsecondL";
		this->TBsecondL->Size = System::Drawing::Size(122, 68);
		this->TBsecondL->TabIndex = 24;
		this->TBsecondL->Text = L"5";
		// 
		// TBsecondC
		// 
		this->TBsecondC->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->TBsecondC->Location = System::Drawing::Point(938, 985);
		this->TBsecondC->Name = L"TBsecondC";
		this->TBsecondC->Size = System::Drawing::Size(123, 68);
		this->TBsecondC->TabIndex = 23;
		this->TBsecondC->Text = L"5";
		// 
		// TBsecondR
		// 
		this->TBsecondR->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->TBsecondR->Location = System::Drawing::Point(754, 985);
		this->TBsecondR->Name = L"TBsecondR";
		this->TBsecondR->Size = System::Drawing::Size(119, 68);
		this->TBsecondR->TabIndex = 22;
		this->TBsecondR->Text = L"5";
		// 
		// BsetSecond
		// 
		this->BsetSecond->Location = System::Drawing::Point(703, 898);
		this->BsetSecond->Name = L"BsetSecond";
		this->BsetSecond->Size = System::Drawing::Size(139, 64);
		this->BsetSecond->TabIndex = 21;
		this->BsetSecond->Text = L"Set";
		this->BsetSecond->UseVisualStyleBackColor = true;
		this->BsetSecond->Click += gcnew System::EventHandler(this, &sparseDemoForm::BsetSecond_Click);
		// 
		// TBfirstL
		// 
		this->TBfirstL->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->TBfirstL->Location = System::Drawing::Point(460, 985);
		this->TBfirstL->Name = L"TBfirstL";
		this->TBfirstL->Size = System::Drawing::Size(122, 68);
		this->TBfirstL->TabIndex = 17;
		this->TBfirstL->Text = L"5";
		// 
		// TBfirstC
		// 
		this->TBfirstC->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->TBfirstC->Location = System::Drawing::Point(269, 985);
		this->TBfirstC->Name = L"TBfirstC";
		this->TBfirstC->Size = System::Drawing::Size(123, 68);
		this->TBfirstC->TabIndex = 16;
		this->TBfirstC->Text = L"5";
		// 
		// TBfirstR
		// 
		this->TBfirstR->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->TBfirstR->Location = System::Drawing::Point(85, 985);
		this->TBfirstR->Name = L"TBfirstR";
		this->TBfirstR->Size = System::Drawing::Size(119, 68);
		this->TBfirstR->TabIndex = 15;
		this->TBfirstR->Text = L"5";
		// 
		// BsetFirst
		// 
		this->BsetFirst->Location = System::Drawing::Point(34, 898);
		this->BsetFirst->Name = L"BsetFirst";
		this->BsetFirst->Size = System::Drawing::Size(139, 64);
		this->BsetFirst->TabIndex = 14;
		this->BsetFirst->Text = L"Set";
		this->BsetFirst->UseVisualStyleBackColor = true;
		this->BsetFirst->Click += gcnew System::EventHandler(this, &sparseDemoForm::BsetFirst_Click);
		// 
		// BrezultOp
		// 
		this->BrezultOp->Enabled = false;
		this->BrezultOp->Location = System::Drawing::Point(1500, 899);
		this->BrezultOp->Name = L"BrezultOp";
		this->BrezultOp->Size = System::Drawing::Size(384, 65);
		this->BrezultOp->TabIndex = 13;
		this->BrezultOp->Text = L"Save to file";
		this->BrezultOp->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
		this->BrezultOp->UseVisualStyleBackColor = true;
		this->BrezultOp->Click += gcnew System::EventHandler(this, &sparseDemoForm::BrezultOp_Click);
		// 
		// BsecondOperand
		// 
		this->BsecondOperand->Location = System::Drawing::Point(868, 898);
		this->BsecondOperand->Name = L"BsecondOperand";
		this->BsecondOperand->Size = System::Drawing::Size(384, 65);
		this->BsecondOperand->TabIndex = 12;
		this->BsecondOperand->Text = L"Read from file";
		this->BsecondOperand->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
		this->BsecondOperand->UseVisualStyleBackColor = true;
		this->BsecondOperand->Click += gcnew System::EventHandler(this, &sparseDemoForm::BsecondOperand_Click);
		// 
		// BfirstOperand
		// 
		this->BfirstOperand->Location = System::Drawing::Point(197, 899);
		this->BfirstOperand->Name = L"BfirstOperand";
		this->BfirstOperand->Size = System::Drawing::Size(384, 65);
		this->BfirstOperand->TabIndex = 11;
		this->BfirstOperand->Text = L"Read from file";
		this->BfirstOperand->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
		this->BfirstOperand->UseVisualStyleBackColor = true;
		this->BfirstOperand->Click += gcnew System::EventHandler(this, &sparseDemoForm::BfirstOperand_Click);
		// 
		// BmultMatrix
		// 
		this->BmultMatrix->BackColor = System::Drawing::Color::MediumSpringGreen;
		this->BmultMatrix->Enabled = false;
		this->BmultMatrix->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 28, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->BmultMatrix->Location = System::Drawing::Point(588, 503);
		this->BmultMatrix->Name = L"BmultMatrix";
		this->BmultMatrix->Size = System::Drawing::Size(108, 109);
		this->BmultMatrix->TabIndex = 10;
		this->BmultMatrix->Text = L"x";
		this->BmultMatrix->UseVisualStyleBackColor = false;
		this->BmultMatrix->Click += gcnew System::EventHandler(this, &sparseDemoForm::BmultMatrix_Click);
		// 
		// BaddMatrix
		// 
		this->BaddMatrix->BackColor = System::Drawing::Color::MediumSpringGreen;
		this->BaddMatrix->Enabled = false;
		this->BaddMatrix->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 28, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->BaddMatrix->Location = System::Drawing::Point(588, 388);
		this->BaddMatrix->Name = L"BaddMatrix";
		this->BaddMatrix->Size = System::Drawing::Size(108, 109);
		this->BaddMatrix->TabIndex = 9;
		this->BaddMatrix->Text = L"+";
		this->BaddMatrix->UseVisualStyleBackColor = false;
		this->BaddMatrix->Click += gcnew System::EventHandler(this, &sparseDemoForm::BaddMatrix_Click);
		// 
		// label5
		// 
		this->label5->AutoSize = true;
		this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->label5->Location = System::Drawing::Point(1487, 13);
		this->label5->Name = L"label5";
		this->label5->Size = System::Drawing::Size(222, 76);
		this->label5->TabIndex = 8;
		this->label5->Text = L"Rezult";
		// 
		// label4
		// 
		this->label4->AutoSize = true;
		this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->label4->Location = System::Drawing::Point(807, 13);
		this->label4->Name = L"label4";
		this->label4->Size = System::Drawing::Size(270, 76);
		this->label4->TabIndex = 7;
		this->label4->Text = L"Matrix 2";
		// 
		// label3
		// 
		this->label3->AutoSize = true;
		this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->label3->Location = System::Drawing::Point(150, 13);
		this->label3->Name = L"label3";
		this->label3->Size = System::Drawing::Size(270, 76);
		this->label3->TabIndex = 6;
		this->label3->Text = L"Matrix 1";
		// 
		// DGoprationRezult
		// 
		this->DGoprationRezult->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
		this->DGoprationRezult->Location = System::Drawing::Point(1337, 92);
		this->DGoprationRezult->Name = L"DGoprationRezult";
		this->DGoprationRezult->RowHeadersVisible = false;
		this->DGoprationRezult->RowHeadersWidth = 102;
		this->DGoprationRezult->RowTemplate->Height = 20;
		this->DGoprationRezult->Size = System::Drawing::Size(550, 800);
		this->DGoprationRezult->TabIndex = 2;
		// 
		// DGsecondOperand
		// 
		this->DGsecondOperand->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
		this->DGsecondOperand->Location = System::Drawing::Point(702, 92);
		this->DGsecondOperand->Name = L"DGsecondOperand";
		this->DGsecondOperand->RowHeadersVisible = false;
		this->DGsecondOperand->RowHeadersWidth = 102;
		this->DGsecondOperand->RowTemplate->Height = 20;
		this->DGsecondOperand->Size = System::Drawing::Size(550, 800);
		this->DGsecondOperand->TabIndex = 1;
		// 
		// DGfirstOperand
		// 
		this->DGfirstOperand->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
		this->DGfirstOperand->Location = System::Drawing::Point(32, 92);
		this->DGfirstOperand->Name = L"DGfirstOperand";
		this->DGfirstOperand->RowHeadersVisible = false;
		this->DGfirstOperand->RowHeadersWidth = 102;
		this->DGfirstOperand->RowTemplate->Height = 20;
		this->DGfirstOperand->Size = System::Drawing::Size(550, 800);
		this->DGfirstOperand->TabIndex = 0;
		// 
		// label2
		// 
		this->label2->AutoSize = true;
		this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->label2->Location = System::Drawing::Point(1248, 445);
		this->label2->Name = L"label2";
		this->label2->Size = System::Drawing::Size(106, 113);
		this->label2->TabIndex = 5;
		this->label2->Text = L"=";
		this->label2->Click += gcnew System::EventHandler(this, &sparseDemoForm::label2_Click);
		// 
		// label11
		// 
		this->label11->AutoSize = true;
		this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->label11->Location = System::Drawing::Point(408, 985);
		this->label11->Name = L"label11";
		this->label11->Size = System::Drawing::Size(40, 63);
		this->label11->TabIndex = 20;
		this->label11->Text = L"l";
		this->label11->Click += gcnew System::EventHandler(this, &sparseDemoForm::label11_Click);
		// 
		// label10
		// 
		this->label10->AutoSize = true;
		this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->label10->Location = System::Drawing::Point(223, 985);
		this->label10->Name = L"label10";
		this->label10->Size = System::Drawing::Size(54, 63);
		this->label10->TabIndex = 19;
		this->label10->Text = L"c";
		// 
		// label9
		// 
		this->label9->AutoSize = true;
		this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->label9->Location = System::Drawing::Point(34, 985);
		this->label9->Name = L"label9";
		this->label9->Size = System::Drawing::Size(45, 63);
		this->label9->TabIndex = 18;
		this->label9->Text = L"r";
		// 
		// label12
		// 
		this->label12->AutoSize = true;
		this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->label12->Location = System::Drawing::Point(1077, 985);
		this->label12->Name = L"label12";
		this->label12->Size = System::Drawing::Size(40, 63);
		this->label12->TabIndex = 27;
		this->label12->Text = L"l";
		// 
		// label13
		// 
		this->label13->AutoSize = true;
		this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->label13->Location = System::Drawing::Point(892, 985);
		this->label13->Name = L"label13";
		this->label13->Size = System::Drawing::Size(54, 63);
		this->label13->TabIndex = 26;
		this->label13->Text = L"c";
		// 
		// label14
		// 
		this->label14->AutoSize = true;
		this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->label14->Location = System::Drawing::Point(703, 985);
		this->label14->Name = L"label14";
		this->label14->Size = System::Drawing::Size(45, 63);
		this->label14->TabIndex = 25;
		this->label14->Text = L"r";
		// 
		// tabControl1
		// 
		this->tabControl1->Controls->Add(this->mainPage);
		this->tabControl1->Controls->Add(this->matrixOperations);
		this->tabControl1->Controls->Add(this->convToSparse);
		this->tabControl1->Controls->Add(this->convToCommon);
		this->tabControl1->Location = System::Drawing::Point(0, 12);
		this->tabControl1->Name = L"tabControl1";
		this->tabControl1->SelectedIndex = 0;
		this->tabControl1->Size = System::Drawing::Size(1967, 1139);
		this->tabControl1->TabIndex = 0;
		// 
		// mainPage
		// 
		this->mainPage->BackColor = System::Drawing::Color::Indigo;
		this->mainPage->Controls->Add(this->gotoCommonToSparse);
		this->mainPage->Controls->Add(this->gotoSparseToCommon);
		this->mainPage->Controls->Add(this->gotoMatrixOper);
		this->mainPage->Controls->Add(this->pictureBox1);
		this->mainPage->Controls->Add(this->menuStrip1);
		this->mainPage->Location = System::Drawing::Point(10, 48);
		this->mainPage->Name = L"mainPage";
		this->mainPage->Size = System::Drawing::Size(1947, 1081);
		this->mainPage->TabIndex = 3;
		this->mainPage->Text = L"Main menu";
		// 
		// gotoCommonToSparse
		// 
		this->gotoCommonToSparse->BackColor = System::Drawing::Color::LightCyan;
		this->gotoCommonToSparse->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->gotoCommonToSparse->Location = System::Drawing::Point(870, 698);
		this->gotoCommonToSparse->Name = L"gotoCommonToSparse";
		this->gotoCommonToSparse->Size = System::Drawing::Size(1014, 124);
		this->gotoCommonToSparse->TabIndex = 4;
		this->gotoCommonToSparse->Text = L"Common to Sparse";
		this->gotoCommonToSparse->UseVisualStyleBackColor = false;
		this->gotoCommonToSparse->Click += gcnew System::EventHandler(this, &sparseDemoForm::gotoCommonToSparse_Click);
		// 
		// gotoSparseToCommon
		// 
		this->gotoSparseToCommon->BackColor = System::Drawing::Color::LightCyan;
		this->gotoSparseToCommon->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->gotoSparseToCommon->Location = System::Drawing::Point(870, 496);
		this->gotoSparseToCommon->Name = L"gotoSparseToCommon";
		this->gotoSparseToCommon->Size = System::Drawing::Size(1014, 124);
		this->gotoSparseToCommon->TabIndex = 3;
		this->gotoSparseToCommon->Text = L"Sparse to Common";
		this->gotoSparseToCommon->UseVisualStyleBackColor = false;
		this->gotoSparseToCommon->Click += gcnew System::EventHandler(this, &sparseDemoForm::gotoSparseToCommon_Click);
		// 
		// gotoMatrixOper
		// 
		this->gotoMatrixOper->BackColor = System::Drawing::Color::LightCyan;
		this->gotoMatrixOper->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->gotoMatrixOper->Location = System::Drawing::Point(870, 298);
		this->gotoMatrixOper->Name = L"gotoMatrixOper";
		this->gotoMatrixOper->Size = System::Drawing::Size(1014, 124);
		this->gotoMatrixOper->TabIndex = 2;
		this->gotoMatrixOper->Text = L"Matrix Operation";
		this->gotoMatrixOper->UseVisualStyleBackColor = false;
		this->gotoMatrixOper->Click += gcnew System::EventHandler(this, &sparseDemoForm::gotoMatrixOper_Click);
		// 
		// pictureBox1
		// 
		this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
		this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
		this->pictureBox1->Location = System::Drawing::Point(214, 298);
		this->pictureBox1->Name = L"pictureBox1";
		this->pictureBox1->Size = System::Drawing::Size(528, 524);
		this->pictureBox1->TabIndex = 1;
		this->pictureBox1->TabStop = false;
		this->pictureBox1->Click += gcnew System::EventHandler(this, &sparseDemoForm::pictureBox1_Click);
		// 
		// menuStrip1
		// 
		this->menuStrip1->ImageScalingSize = System::Drawing::Size(40, 40);
		this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
			this->guideToolStripMenuItem,
				this->aboutUsToolStripMenuItem, this->appInfoToolStripMenuItem
		});
		this->menuStrip1->Location = System::Drawing::Point(0, 0);
		this->menuStrip1->Name = L"menuStrip1";
		this->menuStrip1->Size = System::Drawing::Size(1947, 49);
		this->menuStrip1->TabIndex = 0;
		this->menuStrip1->Text = L"menuStrip1";
		// 
		// guideToolStripMenuItem
		// 
		this->guideToolStripMenuItem->Name = L"guideToolStripMenuItem";
		this->guideToolStripMenuItem->Size = System::Drawing::Size(121, 45);
		this->guideToolStripMenuItem->Text = L"Guide";
		this->guideToolStripMenuItem->Click += gcnew System::EventHandler(this, &sparseDemoForm::guideToolStripMenuItem_Click);
		// 
		// aboutUsToolStripMenuItem
		// 
		this->aboutUsToolStripMenuItem->Name = L"aboutUsToolStripMenuItem";
		this->aboutUsToolStripMenuItem->Size = System::Drawing::Size(162, 45);
		this->aboutUsToolStripMenuItem->Text = L"About us";
		this->aboutUsToolStripMenuItem->Click += gcnew System::EventHandler(this, &sparseDemoForm::aboutUsToolStripMenuItem_Click);
		// 
		// appInfoToolStripMenuItem
		// 
		this->appInfoToolStripMenuItem->Name = L"appInfoToolStripMenuItem";
		this->appInfoToolStripMenuItem->Size = System::Drawing::Size(156, 45);
		this->appInfoToolStripMenuItem->Text = L"App info";
		this->appInfoToolStripMenuItem->Click += gcnew System::EventHandler(this, &sparseDemoForm::appInfoToolStripMenuItem_Click);
		// 
		// contextMenuStrip1
		// 
		this->contextMenuStrip1->ImageScalingSize = System::Drawing::Size(40, 40);
		this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
			this->aboutRClick,
				this->openGuide, this->appInfoRClick, this->clearThisTab, this->clearAllTabs, this->returnToMain
		});
		this->contextMenuStrip1->Name = L"contextMenuStrip1";
		this->contextMenuStrip1->Size = System::Drawing::Size(379, 292);
		this->contextMenuStrip1->Opening += gcnew System::ComponentModel::CancelEventHandler(this, &sparseDemoForm::contextMenuStrip1_Opening);
		// 
		// aboutRClick
		// 
		this->aboutRClick->Name = L"aboutRClick";
		this->aboutRClick->Size = System::Drawing::Size(378, 48);
		this->aboutRClick->Text = L"About Us";
		this->aboutRClick->Click += gcnew System::EventHandler(this, &sparseDemoForm::infoRClick_Click);
		// 
		// openGuide
		// 
		this->openGuide->Name = L"openGuide";
		this->openGuide->Size = System::Drawing::Size(378, 48);
		this->openGuide->Text = L"Guide";
		this->openGuide->Click += gcnew System::EventHandler(this, &sparseDemoForm::openGuide_Click);
		// 
		// appInfoRClick
		// 
		this->appInfoRClick->Name = L"appInfoRClick";
		this->appInfoRClick->Size = System::Drawing::Size(378, 48);
		this->appInfoRClick->Text = L"App Info";
		this->appInfoRClick->Click += gcnew System::EventHandler(this, &sparseDemoForm::appInfoRClick_Click);
		// 
		// clearThisTab
		// 
		this->clearThisTab->Name = L"clearThisTab";
		this->clearThisTab->Size = System::Drawing::Size(378, 48);
		this->clearThisTab->Text = L"Clear Tab";
		this->clearThisTab->Click += gcnew System::EventHandler(this, &sparseDemoForm::clearThisTab_Click);
		// 
		// clearAllTabs
		// 
		this->clearAllTabs->Name = L"clearAllTabs";
		this->clearAllTabs->Size = System::Drawing::Size(378, 48);
		this->clearAllTabs->Text = L"Clear All";
		this->clearAllTabs->Click += gcnew System::EventHandler(this, &sparseDemoForm::clearAllTabs_Click);
		// 
		// returnToMain
		// 
		this->returnToMain->Name = L"returnToMain";
		this->returnToMain->Size = System::Drawing::Size(378, 48);
		this->returnToMain->Text = L"Return to Main Menu";
		this->returnToMain->Click += gcnew System::EventHandler(this, &sparseDemoForm::returnToMain_Click);
		// 
		// sparseDemoForm
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(16, 31);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(1979, 1186);
		this->ContextMenuStrip = this->contextMenuStrip1;
		this->Controls->Add(this->tabControl1);
		this->MainMenuStrip = this->menuStrip1;
		this->Name = L"sparseDemoForm";
		this->Text = L"sparseDemoForm";
		this->convToCommon->ResumeLayout(false);
		this->convToCommon->PerformLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGconvComTo))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGconvComFrom))->EndInit();
		this->convToSparse->ResumeLayout(false);
		this->convToSparse->PerformLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGconvSprTo))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGconvSprFrom))->EndInit();
		this->matrixOperations->ResumeLayout(false);
		this->matrixOperations->PerformLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGoprationRezult))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGsecondOperand))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGfirstOperand))->EndInit();
		this->tabControl1->ResumeLayout(false);
		this->mainPage->ResumeLayout(false);
		this->mainPage->PerformLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
		this->menuStrip1->ResumeLayout(false);
		this->menuStrip1->PerformLayout();
		this->contextMenuStrip1->ResumeLayout(false);
		this->ResumeLayout(false);

	}
#pragma endregion
private: 
	System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) { }
	System::Void label9_Click(System::Object^ sender, System::EventArgs^ e) { }
	System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) { }
	System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) { }
	System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) { }
	System::Void label11_Click(System::Object^ sender, System::EventArgs^ e) { }
	System::Void contextMenuStrip1_Opening(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) { }
	System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) { }

	System::Void BtoCommon_Click(System::Object^ sender, System::EventArgs^ e);
	System::Void BtoSparse_Click(System::Object^ sender, System::EventArgs^ e);
	System::Void BaddMatrix_Click(System::Object^ sender, System::EventArgs^ e);
	System::Void BmultMatrix_Click(System::Object^ sender, System::EventArgs^ e);
	System::Void BsecondOperand_Click(System::Object^ sender, System::EventArgs^ e);
	System::Void BfirstOperand_Click(System::Object^ sender, System::EventArgs^ e);
	System::Void BrezultOp_Click(System::Object^ sender, System::EventArgs^ e);
	System::Void BsetSecond_Click(System::Object^ sender, System::EventArgs^ e);
	System::Void BsetFirst_Click(System::Object^ sender, System::EventArgs^ e);
	System::Void BconvFile_Click(System::Object^ sender, System::EventArgs^ e);
	System::Void BsetConv_Click(System::Object^ sender, System::EventArgs^ e);
	System::Void BconvFileSpr_Click(System::Object^ sender, System::EventArgs^ e);
	System::Void BsetConvSpr_Click(System::Object^ sender, System::EventArgs^ e);
	System::Void BconvRezCom_Click(System::Object^ sender, System::EventArgs^ e);
	System::Void BconvRezSpr_Click(System::Object^ sender, System::EventArgs^ e);
	System::Void infoRClick_Click(System::Object^ sender, System::EventArgs^ e);
	System::Void openGuide_Click(System::Object^ sender, System::EventArgs^ e);
	System::Void clearThisTab_Click(System::Object^ sender, System::EventArgs^ e);
	System::Void clearAllTabs_Click(System::Object^ sender, System::EventArgs^ e);
	System::Void returnToMain_Click(System::Object^ sender, System::EventArgs^ e);
	System::Void appInfoRClick_Click(System::Object^ sender, System::EventArgs^ e);
	System::Void guideToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	System::Void aboutUsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	System::Void appInfoToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	System::Void gotoSparseToCommon_Click(System::Object^ sender, System::EventArgs^ e);
	System::Void gotoMatrixOper_Click(System::Object^ sender, System::EventArgs^ e);
	System::Void gotoCommonToSparse_Click(System::Object^ sender, System::EventArgs^ e);
	System::Void BbackTab3_Click(System::Object^ sender, System::EventArgs^ e);
	System::Void BbackTab2_Click(System::Object^ sender, System::EventArgs^ e);
	System::Void BbackTab1_Click(System::Object^ sender, System::EventArgs^ e);
};
}
