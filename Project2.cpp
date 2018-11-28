/*******************************************************************************
* Assignment: Project 2 - Syntactic Analyzer for Scheme to C++ Translator      *
* Authors: Justin Bernard, Catherine Meyer, Jimmie Hagle                       *
* Date: Fall 2018                                                              *
* File: Project2.cpp                                                           *
*                                                                              *
* Description:                                                                 *
*******************************************************************************/

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "SetLimits.h"
#include "SyntacticalAnalyzer.h"

int main (int argc, char * argv[])
{
	if (argc < 2)
	{
		printf ("format: %s <filename>\n", argv[0]);
		exit (1);
	}

	SetLimits ();

	SyntacticalAnalyzer parse (argv[1]);

	return 0;
}
