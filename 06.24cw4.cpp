#include <iostream>
#include <string>
#include <regex>
using namespace std;

class Text {
protected:
	string text;
public:
	Text(string text) {
		this->text = text;
	}
	virtual void print()=0;
	virtual ~Text() {
	}
};

class HTMLText: public Text {
public:
	HTMLText(string text) :
			Text(text) {
	}
	void print() override {
		cout << text << endl;
	}
};

class PlainText: public Text {
public:
	PlainText(string text) :
			Text(text) {
	}
	void print() override {
		std::stringstream result;
		regex_replace(std::ostream_iterator<char>(result), text.begin(),
				text.end(), regex("<[A-Za-z/]*>"), "");
		std::cout << result.str();
		cout << endl;
	}
};

int main() {
	string str = "<i>Hello</i> <b>world</b>!";
	HTMLText ht(str);
	PlainText pt(str);
	ht.print();
	pt.print();
	return 0;
}
