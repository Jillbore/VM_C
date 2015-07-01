#pragma once

#include <unordered_map>

typedef	enum {
	A, B,				// General 
	IP,					// Instruction Pointer
	SP,					// Stack Pointer
	NUM_OF_REGISTERS
} Registers;

typedef enum {
	PSH,
	POP,
	ADD,
	SET,
	HLT
} InstructionSet;

static std::unordered_map<std::string, int> cpuMap =
{
	{ "PSH", InstructionSet::PSH },
	{ "POP", InstructionSet::POP },
	{ "ADD", InstructionSet::ADD },
	{ "SET", InstructionSet::SET },
	{ "HLT", InstructionSet::HLT },
	{ "A", Registers::A },
	{ "B", Registers::B },
};