#pragma once

//Libraries Used
#include <iostream> //Input/Output Stream For Console
#include <string>   //For String
#include <fstream>  //File Stream 
#include <vector>   //Changable Index Structure
#include <Windows.h>//For System Commands
#include <algorithm>//Easy Sorting For Arrays/Vectors ...
#include <iomanip>  //For Outputting With Given Precision
#include <cmath>    //Easy Math Functions
#include <stdio.h>  //Standart Input/Output For Given Types
#include <conio.h>  //For Getting Key Presses
#include <ctime>    //For Gettig Real Time
#include <filesystem>
#include <mmsystem.h>
#include <Mmsystem.h>
#include <mciapi.h>
#pragma comment(lib, "Winmm.lib")

using namespace std;//Standart Namespace
namespace fs = filesystem;


string ext(string path)
{
	ifstream CFile(path); //Checking/Reading File
	bool opened = CFile.is_open(); //bool For Checking
	if (opened) // If Available
	{
		string ext = ""; //Set Extension To Nothing
		size_t size = path.size(); //Get Size Of Path
		size_t lastPos = size;     //Get LastPos(Will Be Used Later)
		char letter;               //Letter For Given Position
		bool ThereIsDot = false;   //Check If There Is Format
		for (size_t i = 0; i < size; i++) //Loop To Extract Chars
		{
			letter = path[i]; //Get Char On Given Index
			if (letter == '.') //If Symbol Is Dot 
			{
				lastPos = i; //Starting Index Of Format
				ThereIsDot = true; //There Is Format
			}
		}
		if (ThereIsDot) //If Format Is Given
		{
			for (size_t i = lastPos; i < size; i++) //Loop For Format Chars
			{
				letter = path[i]; //Get Char On Given Index
				ext += letter; //Get Format 
			}
			return ext; //Give Extension Of File
		}
		else
		{
			return "ERROR"; //Give ERROR If There Is No Extension
		}
	}
	else
	{
		return "ERROR"; //Give ERROR If File Not Opened
	}
}

string lower(string input)
{
	size_t size = input.size();//Get Size Of String
	char symbol; // Char For Every Index
	string ans = ""; //Set Answer to Empty String
	for (size_t i = 0; i < size; i++) //Loop To Extract String
	{
		symbol = tolower(input[i]); //Set Char To It's Lowercase
		ans += symbol; //Add It To Answer String
	}
	return ans;//Give Answer
}

string getName(string target)
{
	size_t size = target.size();
	char symbol;
	size_t lastPos = size;
	string result;
	for (size_t i = 0; i < size; i++)
	{
		symbol = target[i];
		if (symbol == '/')
		{
			lastPos = i;
		}
	}
	for (size_t i = lastPos + 1; i < size; i++)
	{
		symbol = target[i];
		if (symbol == '.')
		{
			break;
		}
		result += symbol;
	}
	return result;
}