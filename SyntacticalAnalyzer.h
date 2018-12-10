// CS460 Project 2
// Authors: Justin Bernard, Catherine Meyer, Jimmie Hagle


#ifndef SYN_H
#define SYN_H

#include <iostream>
#include <fstream>
#include "LexicalAnalyzer.h"
#include "CodeGenerator.h"

using namespace std;

class SyntacticalAnalyzer 
{
    public:
	SyntacticalAnalyzer (char * filename);
	~SyntacticalAnalyzer ();
	int any_other_token();
	int action();
	int stmt_pair_body();
	int stmt_pair();
	int stmt();
	int else_part();
	int param_list();
	int more_tokens();
	int quoted_lit();
	int literal();
	int stmt_list();
	int define();
	int more_defines();
	int program();
    private:
	LexicalAnalyzer * lex;
	token_type token;
	int errors;
	CodeGen * code;
};
	
#endif
