#include <iostream>
#include <string>

class CoutProxy
{
public:
	void write(const std::string & str) const
	{
		std::cout << str;
	}
};

void hello_world(const CoutProxy & cout)
{
	cout.write("Hello world!\n");
}

int main()
{
	hello_world(CoutProxy());
	return 0;
}

