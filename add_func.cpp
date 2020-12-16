#include "add_funk.h"

String^ ToSystemString(string txt) {
	return gcnew String(txt.c_str());
}

string ToCommonString(String^ txt) {
	return (const char*)(Runtime::InteropServices::Marshal::StringToHGlobalAnsi(txt)).ToPointer();
}

Json::Value ReadJson() {
    Json::Value readdata;
    OpenFileDialog^ fileDg = gcnew OpenFileDialog();
    fileDg->Title = "Choose File";
    fileDg->Filter = "JSON file|*.json";
    if (fileDg->ShowDialog() == DialogResult::OK) {
        ifstream rFile;
        rFile.open(ToCommonString(fileDg->FileName));
        rFile >> readdata;
        rFile.close();
        return readdata;
    }
    return NULL;
}

void PrintJson(Json::Value& core) {
    SaveFileDialog^ fileDg = gcnew SaveFileDialog();
    fileDg->Title = "Choose File";
    if (fileDg->ShowDialog() == DialogResult::OK) {
        ofstream rFile; 

        string filePath = ToCommonString(fileDg->FileName);
        string json = ".json";
        if (filePath.length() > json.length()) {
            if (filePath.compare(filePath.length() - json.length(), json.length(), json)) {
                filePath += json;
            }
        }
        else {
            filePath += json;
        }
        rFile.open(filePath);
        rFile << core;
        rFile.close();
    }
}
