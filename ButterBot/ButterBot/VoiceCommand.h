#pragma once
#define _CRT_SECURE_NO_WARNINGS
using namespace System;
using namespace System::Speech::Recognition;
#include "CommandDatabase.h" 


public ref class RecognitionEngine
{
public:	SpeechRecognitionEngine^sRecognize;
	Boolean b_speechActivated;
	public:void ListenForCommand();
	void RespondToAction(System::String^response);
	public:void IntroductionOnStart(CommandDatabaseEngine^ database);
	void sRecognize_SpeechRecognized(System::Object ^sender, System::Speech::Recognition::SpeechRecognizedEventArgs^ e);
};