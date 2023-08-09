#pragma once
#include <string>
#include <vector>

class RevisionData {

public:
	RevisionData();
	std::vector<std::string> subjects;
	std::vector<std::string> completion;

};

class SyllabusData {
public:
	SyllabusData();
	std::vector<std::string> subjects;
	std::vector<float> completion;

};

class ClassRoutine {
public:
	std::string Routine[6][8][2] = {
		{
			{"10:15 - 11:05", "Electric Circuit Theory"},
			{"10:15 - 11:05", "Electric Circuit Theory"},
			{"10:15 - 11:05", "Electric Circuit Theory"},
			{"10:15 - 11:05", "Electric Circuit Theory"},
			{"10:15 - 11:05", "Electric Circuit Theory"},
			{"10:15 - 11:05", "Electric Circuit Theory"},
			{"10:15 - 11:05", "Electric Circuit Theory"},
			{"10:15 - 11:05", "Electric Circuit Theory"},

		},
			{
			{"10:15 - 11:05", "Electronic Devices and Circuits"},
			{"10:15 - 11:05", "Electronic Devices and Circuits"},
			{"10:15 - 11:05", "Electronic Devices and Circuits"},
			{"10:15 - 11:05", "Electronic Devices and Circuits"},
			{"10:15 - 11:05", "Electronic Devices and Circuits"},
			{"10:15 - 11:05", "Electronic Devices and Circuits"},
			{"10:15 - 11:05", "Electronic Devices and Circuits"},
			{"10:15 - 11:05", "Electronic Devices and Circuits"},

		},
			{
			{"10:15 - 11:05", "Object Oriented Programming"},
			{"10:15 - 11:05", "Object Oriented Programming"},
			{"10:15 - 11:05", "Object Oriented Programming"},
			{"10:15 - 11:05", "Object Oriented Programming"},
			{"10:15 - 11:05", "Object Oriented Programming"},
			{"10:15 - 11:05", "Object Oriented Programming"},
			{"10:15 - 11:05", "Object Oriented Programming"},
			{"10:15 - 11:05", "Object Oriented Programming"},

		},
			{
			{"10:15 - 11:05", "Theory of Computation"},
			{"10:15 - 11:05", "Theory of Computation"},
			{"10:15 - 11:05", "Theory of Computation"},
			{"10:15 - 11:05", "Theory of Computation"},
			{"10:15 - 11:05", "Theory of Computation"},
			{"10:15 - 11:05", "Theory of Computation"},
			{"10:15 - 11:05", "Theory of Computation"},
			{"10:15 - 11:05", "Theory of Computation"},

		},
			{
			{"10:15 - 11:05", "Digital Logic"},
			{"10:15 - 11:05", "Digital Logic"},
			{"10:15 - 11:05", "Digital Logic"},
			{"10:15 - 11:05", "Digital Logic"},
			{"10:15 - 11:05", "Digital Logic"},
			{"10:15 - 11:05", "Digital Logic"},
			{"10:15 - 11:05", "Digital Logic"},
			{"10:15 - 11:05", "Digital Logic"},

		},
			{
			{"10:15 - 11:05", "ElectroMagnetism"},
			{"10:15 - 11:05", "ElectroMagnetism"},
			{"10:15 - 11:05", "ElectroMagnetism"},
			{"10:15 - 11:05", "ElectroMagnetism"},
			{"10:15 - 11:05", "Electric Circuit Theory"},
			{"10:15 - 11:05", "Electric Circuit Theory"},
			{"10:15 - 11:05", "Electric Circuit Theory"},
			{"10:15 - 11:05", "Electric Circuit Theory"},

		},


	};




};

