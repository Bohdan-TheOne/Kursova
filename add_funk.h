#ifndef THIS_PROJ
#define THIS_PROJ

#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include "json/json.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace std;

String^ ToSystemString(string txt);
string ToCommonString(String^ txt);

Json::Value ReadJson();
void PrintJson(Json::Value& core);

#endif

