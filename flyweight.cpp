#include <iostream>
#include <string>
#include <algorithm>

class Character
{
	char ch;
public:
	Character(char c) : ch(c) { }
	void output() const { std::cout << ch; }
};

struct OutputChar
{
	void operator()(char ch) const
	{
		Character(ch).output();
	}
};

void hello_world(const std::string & message)
{
	std::for_each(message.begin(), message.end(), OutputChar());
}

int main()
{
	hello_world("Hello world!\n");
	return 0;
}

