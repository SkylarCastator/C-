#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <sstream>
using std::string;
#include <vector>
using std::vector;
using std::getline;
#include <iostream>
#include <cstddef>
#include <fstream>
#include <list>
#include <map>
#include <fstream>
#include <sstream>

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
using namespace rapidjson;
#include "rapidjson/reader.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/filewritestream.h"
#include "rapidjson/error/en.h"
#include "JsonManager.h"
#include "CommandDatabaseDefinedClasses.h"


public ref class CommandDatabaseEngine {

	public :DefaultsLibrary *default_Library_Resources;

	DefaultsLibrary* GenerateDefaultClass(string fileContents) {
		const char* json = fileContents.c_str();
		Document d;
		d.Parse(json);
		DefaultsLibrary* lib;
		string s_Intro_Response = d["intro_response"].GetString();
		string s_Activate_Command = d["activate_command"].GetString();
		string s_Activate_Response = d["activate_response"].GetString();
		lib->Intro_Response = s_Intro_Response;
		lib->Activate_Command = s_Activate_Command;
		lib->Activate_Response = s_Activate_Response;
		return lib;
	}

	void GenerateObjectDetectionClass(string fileContents) {
		const char* json = fileContents.c_str();
		Document d;
		d.Parse(json);
		const Value& detectableObjects = d["detectableobjects"];
		assert(detectableObjects.IsArray());
		for (SizeType i = 0; i < detectableObjects.Size(); i++)
		{
			ObjectDetectionClass objDetection;
			const Value& objectContents = detectableObjects[detectableObjects[i]];
			assert(objectContents.IsArray());

			for (SizeType i = 0; i < objectContents.Size(); i++)
			{
				objDetection.objectName = (objectContents["name"].GetInt());
				objDetection.H_MAX = (objectContents["h_max"].GetInt());
				objDetection.H_MIN = (objectContents["h_min"].GetInt());
				objDetection.S_MAX = (objectContents["s_max"].GetInt());
				objDetection.S_MIN = (objectContents["s_min"].GetInt());
				objDetection.V_MAX = (objectContents["v_max"].GetInt());
				objDetection.V_MIN = (objectContents["v_min"].GetInt());
			}
		}
	}

	public: void InitalizeDataBase()
	{
		string jsonDefaultsDoc = returnJsonFileContents("Json_Defaults.txt");
		default_Library_Resources = GenerateDefaultClass(jsonDefaultsDoc);
	}
};


