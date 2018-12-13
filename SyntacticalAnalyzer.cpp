// CS460 Project 2
// Authors: Justin Bernard, Catherine Meyer, Jimmie Hagle


#include <iostream>
#include <iomanip>
#include <fstream>
#include "SyntacticalAnalyzer.h"

using namespace std;

SyntacticalAnalyzer::SyntacticalAnalyzer(char *filename)
{
  lex = new LexicalAnalyzer(filename);
  errors = 0;
  token = lex->GetToken();
  code = new CodeGen(filename);
  int tabs = 0;
  errors = program(tabs);
}

SyntacticalAnalyzer::~SyntacticalAnalyzer()
{
  delete lex;
  delete code;
}

int SyntacticalAnalyzer::any_other_token(int tabs)
{
  lex->ReportFunctionEntered("Any_Other_Token", token);

  if (token == IDENT_T)
  {
    lex->ReportRuleUsed("51");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
  }
  else if (token == NUMLIT_T)
  {
    lex->ReportRuleUsed("52");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
  }
  else if (token == STRLIT_T)
  {
    lex->ReportRuleUsed("53");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
  }
  else if (token == CONS_T)
  {
    lex->ReportRuleUsed("54");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
  }
  else if (token == IF_T)
  {
    lex->ReportRuleUsed("55");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
  }
  else if (token == DISPLAY_T)
  {
    lex->ReportRuleUsed("56");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
  }
  else if (token == NEWLINE_T)
  {
    lex->ReportRuleUsed("57");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
  }
  else if (token == LISTOP_T)
  {
    lex->ReportRuleUsed("58");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
  }
  else if (token == AND_T)
  {
    lex->ReportRuleUsed("59");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
  }
  else if (token == OR_T)
  {
    lex->ReportRuleUsed("60");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
  }
  else if (token == NOT_T)
  {
    lex->ReportRuleUsed("61");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
  }
  else if (token == DEFINE_T)
  {
    lex->ReportRuleUsed("62");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
  }
  else if (token == NUMBERP_T)
  {
    lex->ReportRuleUsed("63");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
  }
  else if (token == LISTP_T)
  {
    lex->ReportRuleUsed("64");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
  }
  else if (token == ZEROP_T)
  {
    lex->ReportRuleUsed("65");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
  }

  else if (token == NULLP_T)
  {
    lex->ReportRuleUsed("66");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
  }
  else if (token == STRINGP_T)
  {
    lex->ReportRuleUsed("67");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
  }
  else if (token == PLUS_T)
  {
    lex->ReportRuleUsed("68");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
  }
  else if (token == MINUS_T)
  {
    lex->ReportRuleUsed("69");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
  }

  else if (token == DIV_T)
  {
    lex->ReportRuleUsed("70");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
  }
  else if (token == MULT_T)
  {
    lex->ReportRuleUsed("71");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
  }
  else if (token == MODULO_T)
  {
    lex->ReportRuleUsed("72");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
  }
  else if (token == ROUND_T)
  {
    lex->ReportRuleUsed("73");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
  }

  else if (token == EQUALTO_T)
  {
    lex->ReportRuleUsed("74");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
  }

  else if (token == GT_T)
  {
    lex->ReportRuleUsed("75");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
  }

  else if (token == LT_T)
  {
    lex->ReportRuleUsed("76");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
  }

  else if (token == GTE_T)
  {
    lex->ReportRuleUsed("77");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
  }

  else if (token == LTE_T)
  {
    lex->ReportRuleUsed("78");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
  }

  else if (token == COND_T)
  {
    lex->ReportRuleUsed("80");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
  }
  else if (token == ELSE_T)
  {
    lex->ReportRuleUsed("81");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
  }

  else if (token == LPAREN_T)
  {
    // applying rule 50
    lex->ReportRuleUsed("50");
    code -> WriteCode(0, " ");
    token = lex->GetToken();
    more_tokens(tabs);
    if (token == RPAREN_T)
      token = lex->GetToken();
    else
    {
      lex->ReportError("'RPAREN_T' expected");
      errors++;
    }
  }
  else if (token == SQUOTE_T)
  {
    // applying rule 79
    lex->ReportRuleUsed("79");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    any_other_token( tabs);
  }
  else
  {
    lex->ReportError("'" + lex->GetLexeme() + "' unexpected");
    errors++;
    token = lex->GetToken();
  }

  lex->ReportFunctionExited("Any_Other_Token", token);
  return errors;
}

int SyntacticalAnalyzer::action(int tabs)
{
  lex->ReportFunctionEntered("Action", token);
  if (flag == 0)
    {
      flag = 1;
      if (token == IF_T)
	{
	  // applying rule 24
	  lex->ReportRuleUsed("24");
	  code -> WriteCode(tabs, lex->GetLexeme()+ " ");
	  token = lex->GetToken();
	  stmt(0, "");
	  code -> WriteCode(0, ":\n");
	  tabs++;
	  stmt(tabs, "");
	  tabs--;
	  code -> WriteCode(0, "\n");
	  else_part(tabs);
	  code -> WriteCode(0, "\n");
	}
      else if (token == COND_T)
	{
	  // applying rule 25
	  lex->ReportRuleUsed("25");
	  //code -> WriteCode(tabs, "if ");
	  token = lex->GetToken();
	  if (token == LPAREN_T)
	    {
	      token = lex->GetToken();
	      //tabs++;
	      if (token == ELSE_T)
		{
		  code -> WriteCode(tabs, "if (0):\n");
		  code -> WriteCode(tabs + 1, "0\n");
		  stmt_pair_body(tabs);
		}
	      else
		stmt_pair_body(tabs);
	      //tabs--;
	      code -> WriteCode(0, "\n");
	    }
	  else
	    {
	      lex->ReportError("'LPAREN_T' expected");
	      errors++;
	    }
	}
      else if (token == LISTOP_T)
	{
	  lex->ReportRuleUsed("26");
	  code -> WriteCode(tabs, "listop('"+lex->GetLexeme() + "',");
	  token = lex->GetToken();
	  stmt(tabs, "");
	  code -> WriteCode(0, ") ");
	}
      else if (token == NOT_T)
	{
	  lex->ReportRuleUsed("30");
	  code -> WriteCode(tabs, lex->GetLexeme() + " ");
	  token = lex->GetToken();
	  stmt(tabs, "");
	}

      else if (token == NUMBERP_T)
	{
	  lex->ReportRuleUsed("31");
	  code -> WriteCode(tabs, "numberp(");
	  token = lex->GetToken();
	  stmt(tabs, "");
	  code -> WriteCode(tabs,") ");
	}
      else if (token == LISTP_T)
	{
	  lex->ReportRuleUsed("32");
	  token = lex->GetToken();
	  code -> WriteCode(tabs, "listp(");
	  stmt(tabs, "");
	  code -> WriteCode(tabs, ") ");
	}
      else if (token == ZEROP_T)
	{
	  lex->ReportRuleUsed("33");
	  token = lex->GetToken();
	  code -> WriteCode(tabs, "zerop(");
	  stmt(tabs, "");
	  code -> WriteCode(tabs, ")");
	}
      else if (token == NULLP_T)
	{
	  lex->ReportRuleUsed("34");
	  token = lex->GetToken();
	  code -> WriteCode(tabs, "nullp(");
	  stmt(tabs, "");
	  code -> WriteCode(tabs, ")");
	}
      else if (token == STRINGP_T)
	{
	  lex->ReportRuleUsed("35");
	  token = lex->GetToken();
	  code -> WriteCode(tabs, "stringp(");
	  stmt(tabs, "");
	  code -> WriteCode(tabs, ")");
	}
      else if (token == ROUND_T)
	{
	  lex->ReportRuleUsed("41");
	  token = lex->GetToken();
	  stmt(tabs, "");
	}
      
      else if (token == DISPLAY_T)
	{
	  lex->ReportRuleUsed("48");
	  code -> WriteCode(tabs, "print(");
	  token = lex->GetToken();
	  stmt(tabs, "");
	  code -> WriteCode(0, ") ");
	}
      else if (token == CONS_T)
	{
	  // applying rule 27
	  lex->ReportRuleUsed("27");
	  code -> WriteCode(tabs, lex->GetLexeme() + "(");
	  token = lex->GetToken();
	  stmt(0, "");
	  stmt(0, "");
	  code -> WriteCode(0, ")");
	}
      else if (token == MODULO_T)
	{
	  // applying rule 40
	  lex->ReportRuleUsed("40");
	  token = lex->GetToken();
	  stmt(tabs, "");
	  code -> WriteCode(0, "%");
	  stmt(0, "%");
	}
      else if (token == AND_T)
	{
	  lex->ReportRuleUsed("28");
	  token = lex->GetToken();
	  stmt(tabs, "");
	  code -> WriteCode(0, " and ");
	  stmt_list(0, "and");
	}
      else if (token == OR_T)
	{
	  lex->ReportRuleUsed("29");
	  token = lex->GetToken();
	  stmt(tabs, "");
	  code -> WriteCode(0, " and ");
	  stmt_list(0, "and");
	}
      
      else if (token == PLUS_T)
	{
	  lex->ReportRuleUsed("36");
	  token = lex->GetToken();
	  stmt(tabs, "");
	  code -> WriteCode(0, "+");
	  stmt_list(0, "+");
	}

      else if (token == MULT_T)
	{
	  lex->ReportRuleUsed("39");
	  token = lex->GetToken();
	  stmt(tabs, "");
	  code -> WriteCode(tabs, "*");
	  stmt_list(tabs, "*");
	}
      else if (token == EQUALTO_T)
	{
	  lex->ReportRuleUsed("42");
	  token = lex->GetToken();
	  code -> WriteCode(tabs, "(");
	  stmt(0,"");
	  code -> WriteCode(0, ")");
	  code -> WriteCode(0, "==(");
	  stmt_list(0, "==");
	  code -> WriteCode(0, ")");
	}
      else if (token == GT_T)
	{
	  lex->ReportRuleUsed("43");
	  token = lex->GetToken();
	  code -> WriteCode(tabs, "(");
	  stmt(0, "");
	  code -> WriteCode(0, ")>(");
	  stmt_list(0, ">");
	  code -> WriteCode(0, ")");
	}
      else if (token == LT_T)
	{
	  lex->ReportRuleUsed("44");
	  token = lex->GetToken();
	  code -> WriteCode(tabs, "(");
	  stmt(0, "");
	  code -> WriteCode(0, ")");
	  code -> WriteCode(0, "<(");
	  stmt_list(0, "<");
	  code -> WriteCode(0, ")");
	}
      else if (token == GTE_T)
	{
	  lex->ReportRuleUsed("45");
	  token = lex->GetToken();
	  code -> WriteCode(tabs, "(");
	  stmt(0, "");
	  code -> WriteCode(0, ")>=(");
	  stmt_list(0, ">=");
	  code -> WriteCode(0, ")");
	}
      else if (token == LTE_T)
	{
	  lex->ReportRuleUsed("46");
	  token = lex->GetToken();
	  code -> WriteCode(tabs, "(");
	  stmt(0, "");
	  code -> WriteCode(0, ")<=(");
	  stmt_list(0, "<=");
	  code -> WriteCode(0, ")");
	}
      else if (token == IDENT_T)
	{
	  lex->ReportRuleUsed("47");
	  code -> WriteCode(tabs, lex->GetLexeme());
	  token = lex->GetToken();
	  stmt_list(tabs, "");
	}
      else if (token == MINUS_T)
	{
	  // applying rules 37
	  lex->ReportRuleUsed("37");
	  token = lex->GetToken();
	  stmt(tabs, "");
	  code -> WriteCode(0, "-");
	  stmt_list(0, "-");
	}
      
      else if(token == DIV_T)
	{
	  lex->ReportRuleUsed("38");
	  token = lex->GetToken();
	  stmt(tabs, "");
	  code -> WriteCode(0, "/");
	  stmt_list(0, "/");
	}
      else if (token == NEWLINE_T)
	{
	  // applying rule 49
	  lex->ReportRuleUsed("49");
	  code -> WriteCode(tabs, "print('')");
	  token = lex->GetToken();
	}
      else
	{
	  lex->ReportError("'" + lex->GetLexeme() + "' unexpected");
	  errors++;
	  token = lex->GetToken();
	}
      code -> WriteCode(tabs, "\n");
      flag = 0;

      lex->ReportFunctionExited("Action", token);
      return errors;
    }
  else
    {
      if (token == IF_T)
	{
	  // applying rule 24
	  lex->ReportRuleUsed("24");
	  code -> WriteCode(tabs, lex->GetLexeme()+ " ");
	  token = lex->GetToken();
	  stmt(0, "");
	  code -> WriteCode(0, ":\n");
	  tabs++;
	  stmt(tabs, "");
	  tabs--;
	  code -> WriteCode(0, "\n");
	  else_part(tabs);
	  code -> WriteCode(0, "\n");
	}
      else if (token == COND_T)
	{
	  // applying rule 25
	  lex->ReportRuleUsed("25");
	  //code -> WriteCode(tabs, "if ");
	  token = lex->GetToken();
	  if (token == LPAREN_T)
	    {
	      token = lex->GetToken();
	      //tabs++;
	      if (token == ELSE_T)
                {
		  code -> WriteCode(tabs, "if (0):\n");
                  code -> WriteCode(tabs + 1, "0\n");
                  stmt_pair_body(tabs);
                }
              else
		stmt_pair_body(tabs);
	      //tabs--;
	      code -> WriteCode(0, "\n");
	    }
	  else
	    {
	      lex->ReportError("'LPAREN_T' expected");
	      errors++;
	    }
	}
      else if (token == LISTOP_T)
	{
	  lex->ReportRuleUsed("26");
	  code -> WriteCode(tabs, "listop('"+lex->GetLexeme() + "',");
	  token = lex->GetToken();
	  stmt(0, "");
	  code -> WriteCode(0, ") ");
	}
      else if (token == NOT_T)
	{
	  lex->ReportRuleUsed("30");
	  code -> WriteCode(tabs, lex->GetLexeme() + " ");
	  token = lex->GetToken();
	  stmt(tabs, "");
	}

      else if (token == NUMBERP_T)
	{
	  lex->ReportRuleUsed("31");
	  token = lex->GetToken();
	  code -> WriteCode(tabs, "numberp(");
	  stmt(tabs, "");
	  code -> WriteCode(tabs, ")");
	}
      else if (token == LISTP_T)
	{
	  lex->ReportRuleUsed("32");
	  token = lex->GetToken();
	  code -> WriteCode(tabs, "listp(");
	  stmt(tabs, "");
	  code -> WriteCode(tabs, ")");
	}
      else if (token == ZEROP_T)
	{
	  lex->ReportRuleUsed("33");
	  token = lex->GetToken();
	  code -> WriteCode(tabs, "zerop(");
	  stmt(tabs, "");
	  code -> WriteCode(tabs, ")");
	}
      else if (token == NULLP_T)
	{
	  lex->ReportRuleUsed("34");
	  token = lex->GetToken();
	  code -> WriteCode(tabs, "nullp(");
	  stmt(tabs, "");
	  code -> WriteCode(tabs, ")");
	}
      else if (token == STRINGP_T)
	{
	  lex->ReportRuleUsed("35");
	  token = lex->GetToken();
	  code -> WriteCode(tabs, "stringp(");
	  stmt(tabs, "");
	  code -> WriteCode(tabs, ")");
	}
      else if (token == ROUND_T)
	{
	  lex->ReportRuleUsed("41");
	  token = lex->GetToken();
	  stmt(tabs, "");
	}
      
      else if (token == DISPLAY_T)
	{
	  lex->ReportRuleUsed("48");
	  code -> WriteCode(tabs, "print(");
	  token = lex->GetToken();
	  stmt(tabs, "");
	  code -> WriteCode(0, ") ");
	}
      else if (token == CONS_T)
	{
	  // applying rule 27
	  lex->ReportRuleUsed("27");
	  code -> WriteCode(tabs, lex->GetLexeme() + "(");
	  token = lex->GetToken();
	  stmt(0, "");
	  stmt(0, "");
	  code -> WriteCode(0, ")");
	}
      else if (token == MODULO_T)
	{
	  // applying rule 40
	  lex->ReportRuleUsed("40");
	  token = lex->GetToken();
	  stmt(tabs, "");
	  code -> WriteCode(0, "%");
	  stmt(0, "%");
	}
      else if (token == AND_T)
	{
	  lex->ReportRuleUsed("28");
	  token = lex->GetToken();
	  stmt(tabs, "");
	  code -> WriteCode(0, " and ");
	  stmt_list(0, "and");
	}
      else if (token == OR_T)
	{
	  lex->ReportRuleUsed("29");
	  token = lex->GetToken();
	  stmt(tabs, "");
	  code -> WriteCode(0, " and ");
	  stmt_list(0, "and");
	}
      
      else if (token == PLUS_T)
	{
	  lex->ReportRuleUsed("36");
	  token = lex->GetToken();
	  stmt(tabs, "");
	  code -> WriteCode(0, "+");
	  stmt_list(0, "+");
	}

      else if (token == MULT_T)
	{
	  lex->ReportRuleUsed("39");
	  token = lex->GetToken();
	  stmt(tabs, "");
	  code -> WriteCode(tabs, "*");
	  stmt_list(tabs, "*");
	}
      else if (token == EQUALTO_T)
	{
	  lex->ReportRuleUsed("42");
	  token = lex->GetToken();
	  code -> WriteCode(tabs, "(");
	  stmt(0,"");
	  code -> WriteCode(0, ")");
	  code -> WriteCode(0, "==(");
	  stmt_list(0, "==");
	  code -> WriteCode(0, ")");
	}
      else if (token == GT_T)
	{
	  lex->ReportRuleUsed("43");
	  token = lex->GetToken();
	  code -> WriteCode(tabs, "(");
	  stmt(0, "");
	  code -> WriteCode(0, ")>(");
	  stmt_list(0, ">");
	  code -> WriteCode(0, ")");
	}
      else if (token == LT_T)
	{
	  lex->ReportRuleUsed("44");
	  token = lex->GetToken();
	  code -> WriteCode(tabs, "(");
	  stmt(0, "");
	  code -> WriteCode(0, ")");
	  code -> WriteCode(0, "<(");
	  stmt_list(0, "<");
	  code -> WriteCode(0, ")");
	}
      else if (token == GTE_T)
	{
	  lex->ReportRuleUsed("45");
	  token = lex->GetToken();
	  code -> WriteCode(tabs, "(");
	  stmt(0, "");
	  code -> WriteCode(0, ")>=(");
	  stmt_list(0, ">=");
	  code -> WriteCode(0, ")");
	}
      else if (token == LTE_T)
	{
	  lex->ReportRuleUsed("46");
	  token = lex->GetToken();
	  code -> WriteCode(tabs, "(");
	  stmt(0, "");
	  code -> WriteCode(0, ")<=(");
	  stmt_list(0, "<=");
	  code -> WriteCode(0, ")");
	}
      else if (token == IDENT_T)
	{
	  lex->ReportRuleUsed("47");
	  code -> WriteCode(tabs, lex->GetLexeme());
	  token = lex->GetToken();
	  stmt_list(tabs, "");
	}
      else if (token == MINUS_T)
	{
	  // applying rules 37
	  lex->ReportRuleUsed("37");
	  token = lex->GetToken();
	  stmt(tabs, "");
	  code -> WriteCode(0, "-");
	  stmt_list(0, "-");
	}
      
      else if(token == DIV_T)
	{
	  lex->ReportRuleUsed("38");
	  token = lex->GetToken();
	  stmt(tabs, "");
	  code -> WriteCode(0, "/");
	  stmt_list(0, "/");
	}
      else if (token == NEWLINE_T)
	{
	  // applying rule 49
	  lex->ReportRuleUsed("49");
	  code -> WriteCode(tabs, "print('')");
	  token = lex->GetToken();
	}
      else
	{
	  lex->ReportError("'" + lex->GetLexeme() + "' unexpected");
	  errors++;
	  token = lex->GetToken();
	}
      
      lex->ReportFunctionExited("Action", token);
      return errors;
    }
}

int SyntacticalAnalyzer::stmt_pair_body(int tabs)
{
  lex->ReportFunctionEntered("Stmt_Pair_Body", token);

  if (token == ELSE_T)
  {
    // applying rule 23
    lex->ReportRuleUsed("23");
    code -> WriteCode(tabs, lex->GetLexeme() + ":\n");
    token = lex->GetToken();
    tabs++;
    stmt(tabs, "");
    tabs--;
    code -> WriteCode(0, "\n");
    if (token == RPAREN_T)
      token = lex->GetToken();
    else
    {
      lex->ReportError("'RPAREN_T' expected");
      errors++;
    }
  }
  else
  {
    // applying rule 22
    lex->ReportRuleUsed("22");
    code -> WriteCode(tabs, "if ");
    stmt(0, "");
    code -> WriteCode(0, "\n");
    tabs++;
    stmt(tabs, "");
    tabs--;
    if (token == RPAREN_T)
      token = lex->GetToken();
    else
    {
      lex->ReportError("'RPAREN_T' expected");
      errors++;
    }
    code -> WriteCode(0, "\n");
    stmt_pair(tabs);
  }

  lex->ReportFunctionExited("Stmt_Pair_Body", token);
  return errors;
}

int SyntacticalAnalyzer::stmt_pair(int tabs)
{
  lex->ReportFunctionEntered("Stmt_Pair", token);

  if (token == LPAREN_T)
  {
    // applying rule 20
    lex->ReportRuleUsed("20");
    token = lex->GetToken();
    code -> WriteCode(0, "\n");
    stmt_pair_body(tabs);
  }
  else if (token == RPAREN_T)
  {
    // applying rule 21
    lex->ReportRuleUsed("21");
    lex->ReportFunctionExited("Stmt_Pair", token);
    return errors;
  }

  lex->ReportFunctionExited("Stmt_Pair", token);
  return errors;
}

int SyntacticalAnalyzer::else_part(int tabs)
{
  lex->ReportFunctionEntered("Else_Part", token);

  if (token == RPAREN_T)
  {
    // applying rule 19
    lex->ReportRuleUsed("19");
    lex->ReportFunctionExited("Else_Part", token);
    return errors;
  }
  // applying rule 18
  lex->ReportRuleUsed("18");
  
  code -> WriteCode(tabs, "else:\n");
  tabs++;
  stmt(tabs, "");
  tabs--;
  code -> WriteCode(0, "\n");

  lex->ReportFunctionExited("Else_Part", token);
  return errors;
}

int SyntacticalAnalyzer::param_list(int tabs)
{
  lex->ReportFunctionEntered("Param_List", token);
  
  if (token == RPAREN_T)
  {
    // applying rule 17
    lex->ReportRuleUsed("17");
    lex->ReportFunctionExited("Param_List", token);
    return errors;
  }
  else if (token == IDENT_T)
  {
    // applying rule 16
    code -> WriteCode(0, lex->GetLexeme());
    lex->ReportRuleUsed("16");
    token = lex->GetToken();
    if(token != RPAREN_T)
      code -> WriteCode(0, ", ");
    param_list(tabs);
  }

  lex->ReportFunctionExited("Param_List", token);
  return errors;
}

int SyntacticalAnalyzer::more_tokens(int tabs)
{
  lex->ReportFunctionEntered("More_Tokens", token);

  if (token == RPAREN_T)
  {
    // applying rule 15
    lex->ReportRuleUsed("15");
    lex->ReportFunctionExited("More_Tokens", token);
    return errors;
  }
  // applying rule 14
  lex->ReportRuleUsed("14");
  any_other_token(tabs);
  code -> WriteCode(0, " ");
  more_tokens(tabs);

  lex->ReportFunctionExited("More_Tokens", token);
  return errors;
}

int SyntacticalAnalyzer::quoted_lit(int tabs)
{
  lex->ReportFunctionEntered("Quoted_Lit", token);
  // applying rule 13
  lex->ReportRuleUsed("13");
  any_other_token(tabs);

  lex->ReportFunctionExited("Quoted_Lit", token);
  return errors;
}

int SyntacticalAnalyzer::literal(int tabs)
{
  lex->ReportFunctionEntered("Literal", token);

  if (token == NUMLIT_T)
  {
    // applying rule 10
    lex->ReportRuleUsed("10 ");
    code -> WriteCode(tabs, lex->GetLexeme());
    token = lex->GetToken();
  }
  else if (token == STRLIT_T)
  {
    // applying rule 11
    lex->ReportRuleUsed("11");
    code -> WriteCode(tabs, lex->GetLexeme());
    token = lex->GetToken();
  }
  else if (token == SQUOTE_T)
  {
    // applying rule 12
    lex->ReportRuleUsed("12");
    code -> WriteCode(tabs, "\"");
    token = lex->GetToken();
    quoted_lit(tabs);
    code -> WriteCode(0, "\"");
  }
  else
  {
    lex->ReportError("'" + lex->GetLexeme() + "' unexpected");
    errors++;
    token = lex->GetToken();
  }

  lex->ReportFunctionExited("Literal", token);
  return errors;
}

int SyntacticalAnalyzer::stmt(int tabs, string act)
{
  lex->ReportFunctionEntered("Stmt", token);

  if (token == IDENT_T)
  {
    // applying rule 8
    lex->ReportRuleUsed("8");
    code -> WriteCode(tabs, lex->GetLexeme());
    token = lex->GetToken();
  }
  else if (token == LPAREN_T)
  {
    // applying rule 9
    lex->ReportRuleUsed("9");
    token = lex->GetToken();
    action(tabs);
    if (token == RPAREN_T)
      token = lex->GetToken();
    else
    {
      lex->ReportError("'RPAREN_T' expected");
      errors++;
    }
  }
  else
  {
    // applying rule 7
    lex->ReportRuleUsed("7");
    literal(tabs);
  }

  lex->ReportFunctionExited("Stmt", token);
  return errors;
}

int SyntacticalAnalyzer::stmt_list(int tabs, string act)
{
  lex->ReportFunctionEntered("Stmt_List", token);

  if (token == RPAREN_T)
  {
    // applying rule 6
    lex->ReportRuleUsed("6");
    lex->ReportFunctionExited("Stmt_List", token);
    return errors;
  }
  // applying rule 5
  lex->ReportRuleUsed("5");
  stmt(tabs, act);
  stmt_list(tabs, act);

  lex->ReportFunctionExited("Stmt_List", token);
  return errors;
}

int SyntacticalAnalyzer::define(int tabs)
{
  lex->ReportFunctionEntered("Define", token);

  if (token == DEFINE_T)
  {
    // applying rule 4
    lex->ReportRuleUsed("4");
    token = lex->GetToken();
    if (token == LPAREN_T)
    {
      token = lex->GetToken();
      if (token == IDENT_T)
      {
	code -> WriteCode(tabs, "def " + lex->GetLexeme() + "(");
        token = lex->GetToken();
        param_list(tabs);
        if (token == RPAREN_T)
        {
	  code -> WriteCode(tabs, "): \n");
	  tabs++;
          token = lex->GetToken();
	  code -> WriteCode(tabs, "\n");
          stmt(tabs, "");
	  //code -> WriteCode(tabs, "\n");
          stmt_list(tabs, "");
	  //code -> WriteCode(tabs, "\n");
	  tabs--;
          if (token == RPAREN_T)
            token = lex->GetToken();
          else
          {
            lex->ReportError("'RPAREN_T' expected");
            errors++;
          }
        }
        else
        {
          lex->ReportError("'RPAREN_T' expected");
          errors++;
        }
      }
      else
      {
        lex->ReportError("'IDENT_T' expected");
        errors++;
      }
    }
    else
    {
      lex->ReportError("'LPAREN_T' expected");
      errors++;
    }
  }
  else
  {
    lex->ReportError("'DEFINE_T' expected");
    errors++;
  }

  code -> WriteCode(tabs, "\n");
  lex->ReportFunctionExited("Define", token);
  return errors;
}

int SyntacticalAnalyzer::more_defines(int tabs)
{
  lex->ReportFunctionEntered("More_Defines", token);

  if (token == IDENT_T)
  {
    // applying rule 3
    lex->ReportRuleUsed("3");
    code -> WriteCode(tabs, lex->GetLexeme()+"(");
    token = lex->GetToken();
    stmt_list(tabs, "");
    code->WriteCode(0,")");
    if (token == RPAREN_T)
    {
      token = lex->GetToken();
    }
    else
    {
      lex->ReportError("'RPAREN_T' expected");
      errors++;
    }
  }
  else
  {
    // applying rule 2
    lex->ReportRuleUsed("2");
    define(tabs);
    if (token == LPAREN_T)
    {
      token = lex->GetToken();
      more_defines(tabs);
    }
    else
    {
      lex->ReportError("'LPAREN_T' expected");
      errors++;
    }
  }

  lex->ReportFunctionExited("More_Defines", token);
  return errors;
}

int SyntacticalAnalyzer::program(int tabs)
{
  lex->ReportFunctionEntered("Program", token);

  if (token == LPAREN_T)
  {
    // applying rule 1
    lex->ReportRuleUsed("1");
    token = lex->GetToken();
    define(tabs);
    if (token == LPAREN_T)
    {
      token = lex->GetToken();
      more_defines(tabs);
      if (token == EOF_T)
      {
        lex->ReportFunctionExited("Program", token);
        return errors;
      }
      else
      {
        lex->ReportError("'EOF_T' expected");
        errors++;
      }
    }
    else
    {
      lex->ReportError("'LPAREN_T' expected");
      errors++;
    }
  }
  else
  {
    lex->ReportError("'LPAREN_T' expected");
    errors++;
  }

  lex->ReportFunctionExited("Program", token);
  return errors;
}
