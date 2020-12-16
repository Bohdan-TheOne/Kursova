#ifndef MY_EXCEPTION
#define MY_EXEPTION

#include "add_funk.h"

class ExeptionMtr : public exception
{
public:
	ExeptionMtr();
	ExeptionMtr(string _head, string _msg);
	~ExeptionMtr();

	void ShowException() const;

private:
	string msg;
	string header;
};

#endif