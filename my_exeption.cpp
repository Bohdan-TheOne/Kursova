#include "my_exeption.h"

ExeptionMtr::ExeptionMtr() : exception() {

}

ExeptionMtr::ExeptionMtr(string _head, string _msg) : exception(_msg.c_str()) {
	header = _head;
	msg = _msg;
}

ExeptionMtr::~ExeptionMtr()
{
}

void ExeptionMtr::ShowException() const {
	MessageBox::Show(ToSystemString(msg), ToSystemString(header), MessageBoxButtons::OK);
}