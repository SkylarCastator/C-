#define _CRT_SECURE_NO_WARNINGS
#include <sstream>
using std::string;
#include <vector>
using std::vector;
#include <iostream>
#include "Vision.h"
#include "VoiceCommand.h"
#include "FaceDetection.h"
#include "CommandDatabase.h"

int main(int argc, char* argv[])
{
	CommandDatabaseEngine^commandDataBase = gcnew CommandDatabaseEngine;
	commandDataBase->InitalizeDataBase();
	RecognitionEngine^engine = gcnew RecognitionEngine;
	engine->IntroductionOnStart(commandDataBase);
	InitializeCamera();
	engine->ListenForCommand();

	while (1) 
	{
		VisionDectionLoop();
	}

	return 0;
}