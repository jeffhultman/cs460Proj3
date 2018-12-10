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
	int any_other_token(int tabs);
	int action(int tabs);
	int stmt_pair_body(int tabs);
	int stmt_pair(int tabs);
	int stmt(int tabs);
	int else_part(int tabs);
	int param_list(int tabs);
	int more_tokens(int tabs);
	int quoted_lit(int tabs);
	int literal(int tabs);
	int stmt_list(int tabs);
	int define(int tabs);
	int more_defines(int tabs);
	int program(int tabs);
    private:
	LexicalAnalyzer * lex;
	token_type token;
	int errors;
	CodeGen * code;
};
	
#endif
