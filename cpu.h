#pragma once

#include "specs.h"

#define STACK_SIZE 256

class Cpu
{
public:
	void execute(int*);

protected:
	int fetch();
	void push(int);
	int pop();
	void eval(int);

private:
	int stack[STACK_SIZE];

	int registers[NUM_OF_REGISTERS];	// array holding the cpu registers
	int* instructions;

	bool running = true;
};

#define IP (registers[IP])
#define SP (registers[SP])

void Cpu::execute(int* program)
{
	SP = -1;

	instructions = program;

	while (running) {
		eval(fetch());
		IP++;	// increment for the next instruction
	}

	getchar();

	delete instructions;
}

int Cpu::fetch() {
	return instructions[IP];
}

// push a value ontop of the stack
void Cpu::push(int val) {
	stack[++SP] = val;
}

// pop the top (most recently added) value from the stack
int Cpu::pop() {
	return stack[SP--];
}

void Cpu::eval(int instr) {
	switch (instr) {
	case PSH: {
		push(instructions[++IP]);
		break;
	}
	case POP: {
		int val_popped = pop();
		printf("Popped: %d\n", val_popped);
		break;
	}
	case ADD: {
		// pop the top two values so we can add them
		int a = pop();
		int b = pop();
		push(a + b);
		break;
	}
	case SET: {
		int reg = instructions[++IP];
		registers[reg] = instructions[++IP];
		printf("Set Register '%x' to %d\n", reg, registers[reg]);
		break;
	}
	case HLT: {
		running = false;
		printf("Finished execution");
		break;
	}
	}
}