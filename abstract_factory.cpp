#include <iostream>
#include <string>
#include <memory>

class Message
{
public:
	virtual ~Message() { }
	virtual std::string get_message()=0;
};

class MessageFactory
{
public:
	virtual ~MessageFactory() { }
	virtual std::auto_ptr<Message> create_message() const=0;
};

class HelloWorldMessage : public Message
{
public:
	std::string get_message()
	{
		return "Hello world!";
	}
};

class GoodbyeMessage : public Message
{
public:
	std::string get_message()
	{
		return "Goodbye my friend";
	}
};


class HelloWorldFactory : public MessageFactory
{
public:
	std::auto_ptr<Message> create_message() const
	{
		return std::auto_ptr<Message>(new HelloWorldMessage());
	}
};

class GoodbyeFactory : public MessageFactory
{
public:
	std::auto_ptr<Message> create_message() const
	{
		return std::auto_ptr<Message>(new GoodbyeMessage());
	}
};

void hello_world(const MessageFactory & factory)
{
	std::auto_ptr<Message> message = factory.create_message();
	std::cout << message->get_message() << std::endl;
}

int main()
{
	hello_world(HelloWorldFactory());
	hello_world(GoodbyeFactory());
	return 0;
}

