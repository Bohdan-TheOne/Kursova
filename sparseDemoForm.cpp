#include "sparseDemoForm.h"

int counter = 0;
using namespace KusrsovaVisual;

[System::STAThreadAttribute]
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew sparseDemoForm);
    return 0;
}

//  ------ OTHER FUNCTIONS --------------------


void KusrsovaVisual::sparseDemoForm::ShowAboutUs() {
    string header = "About Us";
    string msg = "Creator : Chepeliuk Bohdan\nGroup : PZ-22\nFeedback : 555-555-555";
    MessageBox::Show(ToSystemString(msg), ToSystemString(header), MessageBoxButtons::OK);
}
void KusrsovaVisual::sparseDemoForm::ShowGuides() {
    string header = "App manual";
    string msg = "Follow this link to view guide";
    string link = "https://github.com/Bohdan-TheOne/Kursova-Manual/blob/master/README.md";
    if (MessageBox::Show(ToSystemString(msg + "\n" + link), ToSystemString(header), 
        MessageBoxButtons::YesNo,
        MessageBoxIcon::Asterisk) == System::Windows::Forms::DialogResult::Yes) {
        System::Diagnostics::Process::Start(ToSystemString(link));
    }
}
void KusrsovaVisual::sparseDemoForm::ShowAppInfo() {
    string header = "App Information";
    string msg = "This app is designed to perform operations on matrices. The user is able to \
make input from keyboard and from file. Operations include addition, multiplying and converting \
matrixes from coomon view to sparse and vise-versa. User can seve opration rezult to file. All \
files are in Json format.";
    MessageBox::Show(ToSystemString(msg), ToSystemString(header), MessageBoxButtons::OK);
}

void KusrsovaVisual::sparseDemoForm::ClearTabFirst() {
    DGfirstOperand->Columns->Clear();
    DGsecondOperand->Columns->Clear();
    DGoprationRezult->Columns->Clear();
    BaddMatrix->Enabled = false;
    BmultMatrix->Enabled = false;
    BrezultOp->Enabled = false;
    if (t1firstInit) {
        delete t1opr1;
        t1firstInit = false;
    }
    if (t1secondInit) {
        delete t1opr2;
        t1secondInit = false;
    }
    if (t1rezultInit) {
        delete t1rezt;
        t1rezultInit = false;
    }
}
void KusrsovaVisual::sparseDemoForm::ClearTabSecond() {
    DGconvSprFrom->Columns->Clear();
    DGconvSprTo->Columns->Clear();
    BtoSparse->Enabled = false;
    BconvRezSpr->Enabled = false;
    if (t2oprInit) {
        delete t2opr;
        t2oprInit = false;
    }
    if (t2rezInit) {
        delete t2rez;
        t2rezInit = false;
    }
}
void KusrsovaVisual::sparseDemoForm::ClearTabThird() {
    DGconvComFrom->Columns->Clear();
    DGconvComTo->Columns->Clear();
    BtoCommon->Enabled = false;
    BconvRezCom->Enabled = false;
    if (t3oprInit) {
        delete t3opr;
        t3oprInit = false;
    }
    if (t3rezInit) {
        delete t3rez;
        t3rezInit = false;
    }
}


//  ------ CONTEXT MENU STRIP -----------------

System::Void KusrsovaVisual::sparseDemoForm::infoRClick_Click(System::Object^ sender, System::EventArgs^ e) {
    ShowAboutUs();
    return System::Void();
}

System::Void KusrsovaVisual::sparseDemoForm::appInfoRClick_Click(System::Object^ sender, System::EventArgs^ e) {
    ShowAppInfo();
    return System::Void();
}

System::Void KusrsovaVisual::sparseDemoForm::openGuide_Click(System::Object^ sender, System::EventArgs^ e) {
    ShowGuides();
    return System::Void();
}

System::Void KusrsovaVisual::sparseDemoForm::clearThisTab_Click(System::Object^ sender, System::EventArgs^ e) {
    switch (tabControl1->SelectedIndex) {
        case 1: {
            ClearTabFirst();
            break;
        }
        case 2: {
            ClearTabSecond();
            break;
        }
        case 3: {
            ClearTabThird();
            break;
        }
        default :
            break;
    }
    return System::Void();
}

System::Void KusrsovaVisual::sparseDemoForm::clearAllTabs_Click(System::Object^ sender, System::EventArgs^ e) {
    ClearTabFirst();
    ClearTabSecond();
    ClearTabThird();
    return System::Void();
}

System::Void KusrsovaVisual::sparseDemoForm::returnToMain_Click(System::Object^ sender, System::EventArgs^ e) {
    tabControl1->SelectedIndex = 0;
}

//  ------ MAIN MENU TAB ----------------------

System::Void KusrsovaVisual::sparseDemoForm::guideToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    ShowGuides();
    return System::Void();
}

System::Void KusrsovaVisual::sparseDemoForm::aboutUsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    ShowAboutUs();
    return System::Void();
}

System::Void KusrsovaVisual::sparseDemoForm::appInfoToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    ShowAppInfo();
    return System::Void();
}

System::Void KusrsovaVisual::sparseDemoForm::gotoMatrixOper_Click(System::Object^ sender, System::EventArgs^ e) {
    tabControl1->SelectedIndex = 1;
    return System::Void();
}

System::Void KusrsovaVisual::sparseDemoForm::gotoSparseToCommon_Click(System::Object^ sender, System::EventArgs^ e) {
    tabControl1->SelectedIndex = 2;
    return System::Void();
}

System::Void KusrsovaVisual::sparseDemoForm::gotoCommonToSparse_Click(System::Object^ sender, System::EventArgs^ e) {
    tabControl1->SelectedIndex = 3;
    return System::Void();
}


//  ------ MATRIX OPERATIONS TAB --------------

System::Void KusrsovaVisual::sparseDemoForm::BfirstOperand_Click(System::Object^ sender, System::EventArgs^ e) {
    Json::Value readdata = ReadJson();
    SparseMatrix<float> newSparse;
    newSparse.JsonDeserialise(readdata);
    Matrixes::IODataGrid::PrintSparseToDG(DGfirstOperand, newSparse);
    t1opr1 = new SparseMatrix<float>(newSparse); 
    t1firstInit = true;
    if (t1secondInit) {
        BaddMatrix->Enabled = true;
        BmultMatrix->Enabled = true;
    }
    return System::Void();
}

System::Void KusrsovaVisual::sparseDemoForm::BsecondOperand_Click(System::Object^ sender, System::EventArgs^ e) {
    Json::Value readdata = ReadJson();
    SparseMatrix<float> newSparse;
    newSparse.JsonDeserialise(readdata);
    Matrixes::IODataGrid::PrintSparseToDG(DGsecondOperand, newSparse);
    t1opr2 = new SparseMatrix<float>(newSparse);
    t1secondInit = true;
    if (t1firstInit) {
        BaddMatrix->Enabled = true;
        BmultMatrix->Enabled = true;
    }
    return System::Void();
}

System::Void KusrsovaVisual::sparseDemoForm::BsetFirst_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        int rowCount = Convert::ToInt32(TBfirstR->Text);
        int colCount = Convert::ToInt32(TBfirstC->Text);
        int lenth = Convert::ToInt32(TBfirstL->Text);
        if (rowCount <= 0 || colCount <= 0 || lenth <= 0) {
            throw ExeptionMtr("Wrong Data", "Parameters have to be bigger than zero");
            return System::Void();
        }
        if (lenth > rowCount* colCount) {
            throw ExeptionMtr("Wrong Data", "Lenth can`t be less bigger than max amount of elements");
            return System::Void();
        }
        t1opr1 = new SparseMatrix<float>(rowCount, colCount);
        int col = 0, row = 0;
        for (int i = 0; i < lenth; ++i) {
            t1opr1->insert(SparseMatrixNode<float>(row, col, 1));
            ++col;
            if (col >= colCount) {
                col = 0;
                ++row;
            }
        }
        t1firstInit = true;
        if (t1secondInit) {
            BaddMatrix->Enabled = true;
            BmultMatrix->Enabled = true;
        }
        Matrixes::IODataGrid::PrintSparseToDG(DGfirstOperand, *t1opr1);
    }
    catch (const ExeptionMtr & excpt) {
        excpt.ShowException();
    }
    catch (...) {
        ExeptionMtr("Error", "Something went wrong").ShowException();
    }
    return System::Void();
}

System::Void KusrsovaVisual::sparseDemoForm::BsetSecond_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        int rowCount = Convert::ToInt32(TBsecondR->Text);
        int colCount = Convert::ToInt32(TBsecondC->Text);
        int lenth = Convert::ToInt32(TBsecondL->Text);
        if (rowCount <= 0 || colCount <= 0 || lenth <= 0) {
            throw ExeptionMtr("Wrong Data", "Parameters have to be bigger than zero");
        }
        if (lenth > rowCount* colCount) {
            throw ExeptionMtr("Wrong Data", "Lenth can`t be less bigger than max amount of elements");
        }
        t1opr2 = new SparseMatrix<float>(rowCount, colCount);
        int col = 0, row = 0;
        for (int i = 0; i < lenth; ++i) {
            t1opr2->insert(SparseMatrixNode<float>(row, col, 1));
            ++col;
            if (col >= colCount) {
                col = 0;
                ++row;
            }
        }
        t1secondInit = true;
        if (t1firstInit) {
            BaddMatrix->Enabled = true;
            BmultMatrix->Enabled = true;
        }
        Matrixes::IODataGrid::PrintSparseToDG(DGsecondOperand, *t1opr2);
    }
    catch (const ExeptionMtr& excpt) {
        excpt.ShowException();
    }
    catch (...){
        ExeptionMtr("Error", "Something went wrong").ShowException();
    }
    return System::Void();
}

System::Void KusrsovaVisual::sparseDemoForm::BaddMatrix_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        if (!(t1firstInit && t1secondInit)) {
            throw ExeptionMtr("Uninitialised Data", "Initialise matrixes before this step");
        }
        if (t1opr1->GetRowCount() != t1opr2->GetRowCount() ||
            t1opr1->GetColCount() != t1opr2->GetColCount()) {
            throw ExeptionMtr("Wrong Data", "Matrixes must be the same size to add");
        }
        Matrixes::IODataGrid::ReadSparseFormDG(DGfirstOperand, *t1opr1);
        Matrixes::IODataGrid::ReadSparseFormDG(DGsecondOperand, *t1opr2);
        t1rezt = new SparseMatrix<float>(*t1opr1 + *t1opr2);
        t1rezultInit = true;
        BrezultOp->Enabled = true;
        Matrixes::IODataGrid::PrintSparseToDG(DGoprationRezult, *t1rezt);
    }
    catch (const ExeptionMtr & excpt) {
        excpt.ShowException();
    }
    catch (...) {
        ExeptionMtr("Error", "Something went wrong").ShowException();
    }
    return System::Void();
}

System::Void KusrsovaVisual::sparseDemoForm::BmultMatrix_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        if (!(t1firstInit && t1secondInit)) {
            throw ExeptionMtr("Uninitialised Data", "Initialise matrixes before this step");
        }
        if (t1opr1->GetColCount() != t1opr2->GetRowCount()) {
            throw ExeptionMtr("Wrong Data", "Matrixes of this size cannot be multiplied");
        }
        Matrixes::IODataGrid::ReadSparseFormDG(DGfirstOperand, *t1opr1);
        Matrixes::IODataGrid::ReadSparseFormDG(DGsecondOperand, *t1opr2);
        t1rezt = new SparseMatrix<float>(*t1opr1 * *t1opr2);
        t1rezultInit = true;
        BrezultOp->Enabled = true;
        Matrixes::IODataGrid::PrintSparseToDG(DGoprationRezult, *t1rezt);
    }
    catch (const ExeptionMtr & excpt) {
        excpt.ShowException();
    }
    catch (...) {
        ExeptionMtr("Error", "Something went wrong").ShowException();
    }
    return System::Void();
}

System::Void KusrsovaVisual::sparseDemoForm::BrezultOp_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        if (!t1rezultInit) {
            throw ExeptionMtr("Uninitialised Data", "There is no rezult yet");
        }
        Json::Value printdata;
        Matrixes::IODataGrid::ReadSparseFormDG(DGoprationRezult, *t1rezt);
        t1rezt->JsonSerialise(printdata);
        PrintJson(printdata);
        return System::Void();
    }
    catch (const ExeptionMtr & excpt) {
        excpt.ShowException();
    }
    catch (...) {
        ExeptionMtr("Error", "Something went wrong").ShowException();
    }
    return System::Void();
}

System::Void KusrsovaVisual::sparseDemoForm::BbackTab1_Click(System::Object^ sender, System::EventArgs^ e) {
    tabControl1->SelectedIndex = 0;
    return System::Void();
}

//  ------ CONVERT TO SPARSE TAB --------------

System::Void KusrsovaVisual::sparseDemoForm::BsetConvSpr_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        int rowCount = Convert::ToInt32(TBconvSprR->Text);
        int colCount = Convert::ToInt32(TBconvSprC->Text);
        if (rowCount <= 0 || colCount <= 0) {
            throw ExeptionMtr("Wrong Data", "Parameters must be bigger than zero");
        }
        t2opr = new CommonMatrix<float>(rowCount, colCount);
        t2oprInit = true;
        BtoSparse->Enabled = true;
        Matrixes::IODataGrid::PrintCommonToDG(DGconvSprFrom, *t2opr);
    }
    catch (const ExeptionMtr & excpt) {
        excpt.ShowException();
    }
    catch (...) {
        ExeptionMtr("Error", "Something went wrong").ShowException();
    }
    return System::Void();
}

System::Void KusrsovaVisual::sparseDemoForm::BconvFileSpr_Click(System::Object^ sender, System::EventArgs^ e) {
    Json::Value readdata = ReadJson();
    CommonMatrix<float> newCommon;
    newCommon.JsonDeserialise(readdata);
    Matrixes::IODataGrid::PrintCommonToDG(DGconvSprFrom, newCommon);
    t2opr = new CommonMatrix<float>(newCommon);
    t2oprInit = true;
    BtoSparse->Enabled = true;
    return System::Void();
}

System::Void KusrsovaVisual::sparseDemoForm::BtoSparse_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        if (!t2oprInit) {
            throw ExeptionMtr("Uninitialised Data", "Matrix has not been initialised");
        }
        Matrixes::IODataGrid::ReadCommonFormDG(DGconvSprFrom, *t2opr);
        t2rez = new SparseMatrix<float>(Matrixes::Convert::ToSparse(*t2opr));
        t2rezInit = true;
        BconvRezSpr->Enabled = true;
        Matrixes::IODataGrid::PrintSparseToDG(DGconvSprTo, *t2rez);
    }
    catch (const ExeptionMtr & excpt) {
        excpt.ShowException();
    }
    catch (...) {
        ExeptionMtr("Error", "Something went wrong").ShowException();
    }
    return System::Void();
}

System::Void KusrsovaVisual::sparseDemoForm::BconvRezSpr_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        if (!t2rezInit) {
            throw ExeptionMtr("Uninitialised Data", "There is no rezult yet");
        }
        Json::Value printdata;
        Matrixes::IODataGrid::ReadSparseFormDG(DGconvSprTo, *t2rez);
        t2rez->JsonSerialise(printdata);
        PrintJson(printdata);
        return System::Void();
    }
    catch (const ExeptionMtr & excpt) {
        excpt.ShowException();
    }
    catch (...) {
        ExeptionMtr("Error", "Something went wrong").ShowException();
    }
    return System::Void();
}

System::Void KusrsovaVisual::sparseDemoForm::BbackTab2_Click(System::Object^ sender, System::EventArgs^ e) {
    tabControl1->SelectedIndex = 0;
    return System::Void();
}

//  ------ CONVERT TO COMMON TAB --------------

System::Void KusrsovaVisual::sparseDemoForm::BsetConv_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        int rowCount = Convert::ToInt32(TBconvRCom->Text);
        int colCount = Convert::ToInt32(TBconvCCom->Text);
        int lenth = Convert::ToInt32(TBconvLCom->Text);
        if (rowCount <= 0 || colCount <= 0 || lenth <= 0) {
            throw ExeptionMtr("Wrong Data", "Parameters have to be bigger than zero");
        }
        if (lenth > rowCount* colCount) {
            throw ExeptionMtr("Wrong Data", "Lenth can`t be less bigger than max amount of elements");
        }
        t3opr = new SparseMatrix<float>(rowCount, colCount);
        int col = 0, row = 0;
        for (int i = 0; i < lenth; ++i) {
            t3opr->insert(SparseMatrixNode<float>(row, col, 1));
            ++col;
            if (col >= colCount) {
                col = 0;
                ++row;
            }
        }
        t3oprInit = true;
        BtoCommon->Enabled = true;
        Matrixes::IODataGrid::PrintSparseToDG(DGconvComFrom, *t3opr);
    }
    catch (const ExeptionMtr & excpt) {
        excpt.ShowException();
    }
    catch (...) {
        ExeptionMtr("Error", "Something went wrong").ShowException();
    }
    return System::Void();
}

System::Void KusrsovaVisual::sparseDemoForm::BconvFile_Click(System::Object^ sender, System::EventArgs^ e) {
    Json::Value readdata = ReadJson();
    SparseMatrix<float> newSparse;
    newSparse.JsonDeserialise(readdata);
    Matrixes::IODataGrid::PrintSparseToDG(DGconvComFrom, newSparse);
    t3opr = new SparseMatrix<float>(newSparse);
    t3oprInit = true;
    BtoCommon->Enabled = true;
    return System::Void();
}

System::Void KusrsovaVisual::sparseDemoForm::BtoCommon_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        if (!t3oprInit) {
            throw ExeptionMtr("Uninitialised Data", "Matrix has not been initialised");
        }
        Matrixes::IODataGrid::ReadSparseFormDG(DGconvComFrom, *t3opr);
        t3rez = new CommonMatrix<float>(Matrixes::Convert::ToCommon(*t3opr));
        t3rezInit = true;
        BconvRezCom->Enabled = true;
        Matrixes::IODataGrid::PrintCommonToDG(DGconvComTo, *t3rez);
    }
    catch (const ExeptionMtr & excpt) {
        excpt.ShowException();
    }
    catch (...) {
        ExeptionMtr("Error", "Something went wrong").ShowException();
    }
    return System::Void();
}

System::Void KusrsovaVisual::sparseDemoForm::BconvRezCom_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        if (!t3rezInit) {
            throw ExeptionMtr("Uninitialised Data", "There is no rezult yet");
        }
        Json::Value printdata;
        Matrixes::IODataGrid::ReadCommonFormDG(DGconvComTo, *t3rez);
        t3rez->JsonSerialise(printdata);
        PrintJson(printdata);
        return System::Void();
    }
    catch (const ExeptionMtr & excpt) {
        excpt.ShowException();
    }
    catch (...) {
        ExeptionMtr("Error", "Something went wrong").ShowException();
    }
    return System::Void();
}

System::Void KusrsovaVisual::sparseDemoForm::BbackTab3_Click(System::Object^ sender, System::EventArgs^ e) {
    tabControl1->SelectedIndex = 0;
    return System::Void();
}
