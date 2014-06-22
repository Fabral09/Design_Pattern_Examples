#include <iostream>

class HelloWorld
{
	HelloWorld() { }
	HelloWorld(const HelloWorld&);
public:
	void output()
	{
		std::cout << "Hello world!" << std::endl;
	}
	static HelloWorld & get()
	{
		static HelloWorld singleton;
		return singleton;
	}
};

void hello_world()
{
	HelloWorld::get().output();
}

int main()
{
	hello_world();
	return 0;
}

