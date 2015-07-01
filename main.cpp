#include "cpu.h"
#include "parser.h"


int main(int argc, char* argv[])
{
	std::string file = "input.txt";

	//int program[] = {
	//	PSH, 5,
	//	PSH, 6,
	//	ADD,
	//	POP,
	//	SET, A, 2,
	//	HLT
	//};

	//std::vector<int> p;

	Cpu c;
	c.execute(&parse(file)[0]);
}
