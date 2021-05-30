#pragma once
#include"Functions.h"
class Exception {
protected:
	string text, source, dateTime;
	int line;
public:
	Exception(const string& text, const int line, const string source, const string& dateTime) {
		this->text = text;
		this->line = line;
		this->source = source;
		this->dateTime = dateTime;
	}
	void printMsg() const {
		mySetColor(4, 0);
		cout << "******* Exception Info *******" << endl;
		cout << "Text: " << text << endl;
		cout << "Date Time: " << dateTime;
		cout << "Line: " << line << endl;
		cout << "Source: " << source << endl;
		mySetColor(7, 0);
	}
};

