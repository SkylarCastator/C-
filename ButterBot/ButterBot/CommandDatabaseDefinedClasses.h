#pragma once
#include <sstream>
using std::string;
#include <vector>
using std::vector;
using std::getline;
#include <iostream>

class DefaultsLibrary
{
public: string Intro_Response;
public: string Activate_Command;
public: string Activate_Response;
};

class SettingsCommands
{
public:string settingName;
	   //public :std::map<char, char> responseDictionary;
};

class ObjectDetectionLibrary
{
	//public:std::list<ObjectDetectionClass> objectDetectionLibrary;
};

class ObjectDetectionClass
{
public:string objectName;
public:int H_MIN = 0;
public:int H_MAX = 256;
public:int S_MIN = 0;
public:int S_MAX = 256;
public:int V_MIN = 0;
public:int V_MAX = 256;
};