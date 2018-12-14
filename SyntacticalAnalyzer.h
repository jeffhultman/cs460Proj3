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
	int any_other_token(int tabs, string ret);
	int action(int tabs, string ret);
	int stmt_pair_body(int tabs, string ret);
	int stmt_pair(int tabs, string ret);
	int stmt(int tabs, string act, string ret);
	int else_part(int tabs, string ret);
	int param_list(int tabs, string ret);
	int more_tokens(int tabs, string ret);
	int quoted_lit(int tabs, string ret);
	int literal(int tabs, string ret);
	int stmt_list(int tabs, string act, string ret);
	int define(int tabs);
	int more_defines(int tabs);
	int program(int tabs);
    private:
	LexicalAnalyzer * lex;
	token_type token;
	int errors;
	CodeGen * code;
	int flag = 0;
	int buildingStatement;
};
	
#endif
