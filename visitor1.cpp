#include <iostream>
#include <string>
#include <algorithm>

struct PrintChar
{
	void operator()(char ch)
	{
		std::cout << ch;
	}
};

template<typename Visitor>
void hello_world(Visitor & visitor)
{
	std::string hw("Hello world!\n");
	std::for_each(hw.begin(), hw.end(), visitor);
}

int main()
{
	PrintChar print_char;
	hello_world(print_char);
	return 0;
}

