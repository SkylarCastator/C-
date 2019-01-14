#define _CRT_SECURE_NO_WARNINGS
using namespace System;
using namespace System::Collections;
using namespace System::Data;
using namespace System::Speech::Synthesis;
using namespace System::Speech::Recognition;
using namespace System::Threading;
#include "CommandDatabase.h"

	public ref class RecognitionEngine{
	public:	SpeechRecognitionEngine^sRecognize;// = gcnew SpeechRecognitionEngine();
						 //DefaultsLibrary *defaultSettings;
						 Boolean b_speechActivated = false;

						 public : void IntroductionOnStart(CommandDatabaseEngine^ database)
						 {
							 //string jsonDefaults = returnJsonFileContents("Json_Defaults.txt");
							// defaultSettings = GenerateDefaultClass(jsonDefaults);

							 sRecognize = gcnew SpeechRecognitionEngine();
							 string phrase = database->default_Library_Resources->Intro_Response;//"hello I am a robot with simple commands. say woba laaba dubdub to activate command listening.";
							 PromptBuilder^pBuilder = gcnew PromptBuilder();
							 pBuilder->ClearContent();
							 String^ final = gcnew String(phrase.c_str());
							 pBuilder->AppendText(final);
							 SpeechSynthesizer^synth = gcnew SpeechSynthesizer();
							 synth->Speak(pBuilder);
						 }

						 void RespondToAction(System::String^response)
						 {
							 PromptBuilder^pBuilder = gcnew PromptBuilder();
							 pBuilder->ClearContent();
							 pBuilder->AppendText(response);
							 SpeechSynthesizer^synth = gcnew SpeechSynthesizer();
							 synth->Speak(pBuilder);
						 }

						public : void ListenForCommand() {
							 Choices^sList = gcnew Choices();
							 //Access current menu and generate commands based on menu command list


							 array<String^>^ sCommands = gcnew array<String^>{ "hello", "pass butter", "thank you", "movie", "exit", "woba laaba dubdub " };
							 sList->Add(sCommands);

							 Grammar^gr = gcnew Grammar(gcnew GrammarBuilder(sList));
							 try
							 {
								  sRecognize->RequestRecognizerUpdate();
								  sRecognize->LoadGrammar(gr);
								  sRecognize->SpeechRecognized += gcnew System::EventHandler<SpeechRecognizedEventArgs^>(this, &RecognitionEngine::sRecognize_SpeechRecognized);
								  sRecognize->SetInputToDefaultAudioDevice();
								  sRecognize->RecognizeAsync(RecognizeMode::Multiple);
							 }
							 catch (InvalidOperationException^ e)
							 {
								 return;
							 }
						 }

						 void sRecognize_SpeechRecognized(System::Object ^sender, System::Speech::Recognition::SpeechRecognizedEventArgs^ e)
						 {
							 if (!b_speechActivated)
							 {
								 if (e->Result->Text == "woba laaba dubdub")
								 {
									 b_speechActivated = true;
									 RespondToAction("What is my purpose?");
								 }
							 }
							 else
							 {
								 System::String^response = "";
								 if (e->Result->Text == "exit")
								 {

								 }
								 else if (e->Result->Text == "hello")
								 {
									 response = "hello, what is my purpose?";
								 }
								 else if (e->Result->Text == "pass butter")
								 {
									 response = "Oooh God";
								 }
								 else if (e->Result->Text == "movie")
								 {
									 response = "I am not programmed for friendship.";
								 }
								 else if (e->Result->Text == "thank you")
								 {
									 response = "You are welcome";
								 }
								 else
								 {
									 response = e->Result->Text->ToString();
								 }
								 
								 RespondToAction(response);
								 b_speechActivated = false;
							 }
						 }
	};


	