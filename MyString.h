#pragma once

using namespace std;
class MyString {
private:
	char* text;
	int  strSize;
public:
	MyString();  // default constructor
	MyString(char* ch);  // constructor
	MyString(const char name[]);
	MyString(const MyString& str); // copy constructor
	const MyString& operator=(const MyString& str); // assignment operator
	int operator==(const MyString& str);
	int operator!=(const MyString& str);
	operator char* () { return text; }; 
	char* get_text(void) { return text; }
	~MyString() { delete[] text; }  //  destructor
	void print(void);

};
MyString::MyString() {  // default constructor
	strSize = 30;
	text = new char[strSize];
	if (text)
		strcpy_s(text, strSize, " ");
}
MyString::MyString(char* ch) {
	strSize = strlen(ch) + 1;  	// add 1 for the trailing '\0'
	text = new char[strSize];
	if (text) { strcpy_s(text, strSize, ch); }
}
MyString::MyString(const char s[]) {
	strSize = strlen(s) + 1;
	text = new char[strSize];
	if (text) { strcpy_s(text, strSize, s); }
}
MyString::MyString(const MyString& str) {
	strSize = 1 + strlen(str.text);
	text = new char[strSize];
	if (text) strcpy_s(text, strSize, str.text);
}
const MyString& MyString::operator=(const MyString& str) {
	delete[] text;
	strSize = str.strSize;
	text = new char[1 + strSize];
	strcpy_s(text, strSize, str.text);
	return (*this);
}
int MyString::operator==(const MyString& str) {
	if (strSize != str.strSize) { cout << "no match " << endl;  return 0; }
	else {
		for (int i = 0; i < strSize; i++) {
			if (text[i] != str.text[i]) { cout << "no match " << endl; return 0; }
		}
	}
	cout << "yes match " << endl;
	return 1;
}
int MyString::operator!=(const MyString& str) {
	if (*this == str) { cout << "strings match" << endl;  return 0; }
	else { return 1; }
}
void MyString::print(void) {
	cout << text;
}

