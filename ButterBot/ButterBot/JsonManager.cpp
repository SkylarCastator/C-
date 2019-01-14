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


template <typename Writer>
void display(Writer& writer);
template <typename Document>
void changeDom(Document& d);

string returnJsonFileContents(string filePath)
{
	std::ifstream fileStream(filePath);

	return string((std::istreambuf_iterator<char>(fileStream)),
		(std::istreambuf_iterator<char>()));
}

void WriteFile(string fileLocation, string fileContentsToWrite)
{
	std::ofstream out("test", std::ofstream::out);

	if (!out) {
		std::cout << "Cannot open output file.\n";
	}

	char *cstr = new char[fileContentsToWrite.length() + 1];
	strcpy(cstr, fileContentsToWrite.c_str());

	double num = 100.45;

	out.write((char *)&num, sizeof(double));
	out.write(cstr, strlen(cstr));

	out.close();
}

void changeDom(Document& d) {
	Value& node = d["hello"];
	node.SetString("c++");

	d["f"] = true;
	d["t"].SetBool(false);
}
template <typename Writer>
void display(Writer& writer) {
	/*
	writer.StartObject();
	writer.String("hello");
	writer.String("world");
	writer.String("t");
	writer.Bool(true);
	writer.String("f");
	writer.Bool(false);
	writer.String("n");
	writer.Null();
	writer.String("i");
	writer.Uint(123);
	writer.String("pi");
	writer.Double(3.1416);
	writer.String("a");
	writer.StartArray();
	for (unsigned i = 0; i < 4; i++)
		writer.Uint(i);
	writer.EndArray();
	writer.EndObject
	*/
}


//void InstatiateJsonManager() {
	/*StringBuffer s;
	Document d;
	PrettyWriter<StringBuffer> writer(s);
	display(writer);
	std::cout << "Before Manupulation\n" << s.GetString() << std::endl;
	d.Parse(s.GetString());
	changeDom(d);
	s.Clear();   // clear the buffer to prepare for a new json document
	writer.Reset(s);  // resetting writer for a fresh json doc
	d.Accept(writer); // writing parsed document to buffer
	std::cout << "After Manupulation\n" << s.GetString() << std::endl;*/
//}

//-------------------------------------------------------------------------------

