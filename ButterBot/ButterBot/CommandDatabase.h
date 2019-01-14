#pragma once
#include <sstream>
using std::string;
#include <vector>
using std::vector;
using std::getline;
#include <iostream>
#include "CommandDatabaseDefinedClasses.h"


public ref class CommandDatabaseEngine
{
	public: DefaultsLibrary *default_Library_Resources;
	public: void InitalizeDataBase();
	void GenerateObjectDetectionClass(string fileContents);
	DefaultsLibrary* GenerateDefaultClass(string fileContents);
};