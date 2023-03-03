#pragma once
// In the C and C++ programming languages, #pragma once is a 
// non-standard but widely supported preprocessor directive designed to cause 
// the current source file to be included only once in a single compilation. 
// Thus, #pragma once serves the same purpose as #include guards, 
// but with several advantages, including: less code, avoiding name clashes, 
// and improved compile speed.
// See the Wikipedia article for further details.


using namespace std;
// MyString.h
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
	// in order to do sorting of MyString object, we need to compare two such strings
	//    so we need to overload operators > and >= for two MyString objects
	//    do this using strcmp()    https://www.tutorialspoint.com/strcmp-in-c-cplusplus
	operator char* () { return text; }; // see p. 117 of Pohl, maybe add more
	char* get_text(void) { return text; }
	~MyString() { delete[] text; }  //  destructor
	// The delete operator deallocates memory and calls the destructor for a single object 
	// created with new.
	// The delete[] operator deallocates memoryand calls destructors for an array of objects 
	// created with new[].
	void print(void);

};
MyString::MyString() {  // default constructor
	// cout << "inside MyString default constructor" << endl;
	strSize = 30;
	// Dynamically allocate the correct amount of memory.
	text = new char[strSize];
	// If the allocation succeeds, copy the initialization string.
	if (text)
		strcpy_s(text, strSize, " ");
}
MyString::MyString(char* ch) {
	// cout << "inside MyString char* constructor" << endl;
	strSize = strlen(ch) + 1;  	// add 1 for the trailing '\0'
	text = new char[strSize];
	if (text) { strcpy_s(text, strSize, ch); }
}
MyString::MyString(const char s[]) {
	// used to create a string, e.g., for "Gertrude Stein"
	// cout << "inside MyString const char[] constructor" << endl;
	strSize = strlen(s) + 1;
	text = new char[strSize];
	if (text) { strcpy_s(text, strSize, s); }
}
MyString::MyString(const MyString& str) {
	// cout << "inside MyString const MyString& str constructor" << endl;
	strSize = 1 + strlen(str.text);
	text = new char[strSize];
	if (text) strcpy_s(text, strSize, str.text);
}
const MyString& MyString::operator=(const MyString& str) {
	// cout << "inside MyString operator=(const MyString& str)" << endl;
	delete[] text;
	strSize = str.strSize;
	text = new char[1 + strSize];
	strcpy_s(text, strSize, str.text);
	return (*this);
}
int MyString::operator==(const MyString& str) {
	// cout << "inside MyString operator ==" << endl;
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
	// cout << "inside MyString operator !=" << endl;
	if (*this == str) { cout << "strings match" << endl;  return 0; }
	else { return 1; }
}
void MyString::print(void) {
	cout << text;
}

