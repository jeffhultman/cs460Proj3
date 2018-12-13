// CS460 Project 2
// Authors: Jimmie Hagle, Boaz Cogan, Justin Bernard


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

int SyntacticalAnalyzer::any_other_token(int tabs, string ret)
{
  lex->ReportFunctionEntered("Any_Other_Token", token);

  if (token == IDENT_T)
  {
    lex->ReportRuleUsed("51");
    code -> WriteCode(0, "\"");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code -> WriteCode(0, "\"");
  }
  else if (token == NUMLIT_T)
  {
    lex->ReportRuleUsed("52");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
  }
  else if (token == STRLIT_T)
  {
    code -> WriteCode(0, "\"");
    lex->ReportRuleUsed("53");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code -> WriteCode(0, "\"");
  }
  else if (token == CONS_T)
  {
    code -> WriteCode(0, "\"");
    lex->ReportRuleUsed("54");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code -> WriteCode(0, "\"");
  }
  else if (token == IF_T)
  {
    code -> WriteCode(0, "\"");
    lex->ReportRuleUsed("55");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code -> WriteCode(0, "\"");
  }
  else if (token == DISPLAY_T)
  {
    code -> WriteCode(0, "\"");
    lex->ReportRuleUsed("56");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code -> WriteCode(0, "\"");
  }
  else if (token == NEWLINE_T)
  {
    code -> WriteCode(0, "\"");
    lex->ReportRuleUsed("57");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code -> WriteCode(0, "\"");
  }
  else if (token == LISTOP_T)
  {
    code -> WriteCode(0, "\"");
    lex->ReportRuleUsed("58");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code -> WriteCode(0, "\"");
  }
  else if (token == AND_T)
  {
    code -> WriteCode(0, "\"");
    lex->ReportRuleUsed("59");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code -> WriteCode(0, "\"");
  }
  else if (token == OR_T)
  {
    code -> WriteCode(0, "\"");
    lex->ReportRuleUsed("60");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code -> WriteCode(0, "\"");
  }
  else if (token == NOT_T)
  {
    code -> WriteCode(0, "\"");
    lex->ReportRuleUsed("61");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code -> WriteCode(0, "\"");
  }
  else if (token == DEFINE_T)
  {
    code -> WriteCode(0, "\"");
    lex->ReportRuleUsed("62");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code -> WriteCode(0, "\"");
  }
  else if (token == NUMBERP_T)
  {
    code -> WriteCode(0, "\"");
    lex->ReportRuleUsed("63");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code -> WriteCode(0, "\"");
  }
  else if (token == LISTP_T)
  {
    code -> WriteCode(0, "\"");
    lex->ReportRuleUsed("64");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code -> WriteCode(0, "\"");
  }
  else if (token == ZEROP_T)
  {
    code -> WriteCode(0, "\"");
    lex->ReportRuleUsed("65");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code -> WriteCode(0, "\"");
  }

  else if (token == NULLP_T)
  {
    code -> WriteCode(0, "\"");
    lex->ReportRuleUsed("66");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code -> WriteCode(0, "\"");
  }
  else if (token == STRINGP_T)
  {
    code -> WriteCode(0, "\"");
    lex->ReportRuleUsed("67");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code -> WriteCode(0, "\"");
  }
  else if (token == PLUS_T)
  {
    code -> WriteCode(0, "\"");
    lex->ReportRuleUsed("68");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code -> WriteCode(0, "\"");
  }
  else if (token == MINUS_T)
  {
    code -> WriteCode(0, "\"");
    lex->ReportRuleUsed("69");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code -> WriteCode(0, "\"");
  }

  else if (token == DIV_T)
  {
    code -> WriteCode(0, "\"");
    lex->ReportRuleUsed("70");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code -> WriteCode(0, "\"");
  }
  else if (token == MULT_T)
  {
    code -> WriteCode(0, "\"");
    lex->ReportRuleUsed("71");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code -> WriteCode(0, "\"");
  }
  else if (token == MODULO_T)
  {
    code -> WriteCode(0, "\"");
    lex->ReportRuleUsed("72");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code -> WriteCode(0, "\"");
  }
  else if (token == ROUND_T)
  {
    code -> WriteCode(0, "\"");
    lex->ReportRuleUsed("73");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code -> WriteCode(0, "\"");
  }

  else if (token == EQUALTO_T)
  {
    code -> WriteCode(0, "\"");
    lex->ReportRuleUsed("74");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code -> WriteCode(0, "\"");
  }

  else if (token == GT_T)
  {
    code -> WriteCode(0, "\"");
    lex->ReportRuleUsed("75");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code -> WriteCode(0, "\"");
  }

  else if (token == LT_T)
  {
    code -> WriteCode(0, "\"");
    lex->ReportRuleUsed("76");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code -> WriteCode(0, "\"");
  }

  else if (token == GTE_T)
  {
    code -> WriteCode(0, "\"");
    lex->ReportRuleUsed("77");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code -> WriteCode(0, "\"");
  }

  else if (token == LTE_T)
  {
    code -> WriteCode(0, "\"");
    lex->ReportRuleUsed("78");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code -> WriteCode(0, "\"");
  }

  else if (token == COND_T)
  {
    code -> WriteCode(0, "\"");
    lex->ReportRuleUsed("80");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code -> WriteCode(0, "\"");
  }
  else if (token == ELSE_T)
  {
    code -> WriteCode(0, "\"");
    lex->ReportRuleUsed("81");
    code -> WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code -> WriteCode(0, "\"");
  }

  else if (token == LPAREN_T)
  {
    // applying rule 50
    lex->ReportRuleUsed("50");
    code -> WriteCode(0, " ");
    token = lex->GetToken();
    more_tokens(tabs, ret);
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
    code -> WriteCode(0, "[");
    code -> WriteCode(0, "\"quote\", ");
    token = lex->GetToken();
    any_other_token( tabs, ret);
    code -> WriteCode(0, "]");
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

int SyntacticalAnalyzer::action(int tabs, string ret)
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
	  stmt(0, "", ret);
	  code -> WriteCode(0, ":\n");
	  tabs++;
	  stmt(tabs, "", ret);
	  tabs--;
	  code -> WriteCode(0, "\n");
	  else_part(tabs, ret);
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
		  stmt_pair_body(tabs, ret);
		}
	      else
		stmt_pair_body(tabs, ret);
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
	  stmt(tabs, "", ret);
	  code -> WriteCode(0, ") ");
	}
      else if (token == NOT_T)
	{
	  lex->ReportRuleUsed("30");
	  code -> WriteCode(tabs, lex->GetLexeme() + " ");
	  token = lex->GetToken();
	  stmt(tabs, "", ret);
	}

      else if (token == NUMBERP_T)
	{
	  lex->ReportRuleUsed("31");
	  code -> WriteCode(tabs, "numberp(");
	  token = lex->GetToken();
	  stmt(tabs, "", ret);
	  code -> WriteCode(tabs,") ");
	}
      else if (token == LISTP_T)
	{
	  lex->ReportRuleUsed("32");
	  token = lex->GetToken();
	  code -> WriteCode(tabs, "listp(");
	  stmt(tabs, "", ret);
	  code -> WriteCode(tabs, ") ");
	}
      else if (token == ZEROP_T)
	{
	  lex->ReportRuleUsed("33");
	  token = lex->GetToken();
	  code -> WriteCode(tabs, "zerop(");
	  stmt(tabs, "", ret);
	  code -> WriteCode(tabs, ")");
	}
      else if (token == NULLP_T)
	{
	  lex->ReportRuleUsed("34");
	  token = lex->GetToken();
	  code -> WriteCode(tabs, "nullp(");
	  stmt(tabs, "", ret);
	  code -> WriteCode(tabs, ")");
	}
      else if (token == STRINGP_T)
	{
	  lex->ReportRuleUsed("35");
	  token = lex->GetToken();
	  code -> WriteCode(tabs, "stringp(");
	  stmt(tabs, "", ret);
	  code -> WriteCode(tabs, ")");
	}
      else if (token == ROUND_T)
	{
	  lex->ReportRuleUsed("41");
	  code -> WriteCode(tabs, "round(");
	  token = lex->GetToken();
	  stmt(tabs, "", ret);
	  code -> WriteCode(tabs, ")");
	}
      
      else if (token == DISPLAY_T)
	{
	  lex->ReportRuleUsed("48");
	  code -> WriteCode(tabs, "print(");
	  token = lex->GetToken();
	  stmt(tabs, "", ret);
	  code -> WriteCode(0, ") ");
	}
      else if (token == CONS_T)
	{
	  // applying rule 27
	  lex->ReportRuleUsed("27");
	  code -> WriteCode(tabs, lex->GetLexeme() + "(");
	  token = lex->GetToken();
	  stmt(0, "", ret);
	  code -> WriteCode(0, ",");
	  stmt(0, "", ret);
	  code -> WriteCode(0, ")");
	}
      else if (token == MODULO_T)
	{
	  // applying rule 40
	  lex->ReportRuleUsed("40");
	  token = lex->GetToken();
	  stmt(tabs, "", ret);
	  code -> WriteCode(0, "%");
	  stmt(0, "%", ret);
	}
      else if (token == AND_T)
	{
	  lex->ReportRuleUsed("28");
	  token = lex->GetToken();
	  stmt(tabs, "", ret);
	  code -> WriteCode(0, " and ");
	  stmt_list(0, "and", ret);
	}
      else if (token == OR_T)
	{
	  lex->ReportRuleUsed("29");
	  token = lex->GetToken();
	  stmt(tabs, "", ret);
	  code -> WriteCode(0, " or ");
	  stmt_list(0, "or", ret);
	}
      
      else if (token == PLUS_T)
	{
	  lex->ReportRuleUsed("36");
	  token = lex->GetToken();
	  stmt(tabs, "", ret);
	  code -> WriteCode(0, "+");
	  stmt_list(0, "+", ret);
	}

      else if (token == MULT_T)
	{
	  lex->ReportRuleUsed("39");
	  token = lex->GetToken();
	  stmt(tabs, "", ret);
	  code -> WriteCode(0, "*");
	  stmt_list(0, "*", ret);
	}
      else if (token == EQUALTO_T)
	{
	  lex->ReportRuleUsed("42");
	  token = lex->GetToken();
	  code -> WriteCode(tabs, "(");
	  stmt(0,"", ret);
	  code -> WriteCode(0, ")");
	  code -> WriteCode(0, "==(");
	  stmt_list(0, "==", ret);
	  code -> WriteCode(0, ")");
	}
      else if (token == GT_T)
	{
	  lex->ReportRuleUsed("43");
	  token = lex->GetToken();
	  code -> WriteCode(tabs, "(");
	  stmt(0, "", ret);
	  code -> WriteCode(0, ")>(");
	  stmt_list(0, ">", ret);
	  code -> WriteCode(0, ")");
	}
      else if (token == LT_T)
	{
	  lex->ReportRuleUsed("44");
	  token = lex->GetToken();
	  code -> WriteCode(tabs, "(");
	  stmt(0, "", ret);
	  code -> WriteCode(0, ")");
	  code -> WriteCode(0, "<(");
	  stmt_list(0, "<", ret);
	  code -> WriteCode(0, ")");
	}
      else if (token == GTE_T)
	{
	  lex->ReportRuleUsed("45");
	  token = lex->GetToken();
	  code -> WriteCode(tabs, "(");
	  stmt(0, "", ret);
	  code -> WriteCode(0, ")>=(");
	  stmt_list(0, ">=", ret);
	  code -> WriteCode(0, ")");
	}
      else if (token == LTE_T)
	{
	  lex->ReportRuleUsed("46");
	  token = lex->GetToken();
	  code -> WriteCode(tabs, "(");
	  stmt(0, "", ret);
	  code -> WriteCode(0, ")<=(");
	  stmt_list(0, "<=", ret);
	  code -> WriteCode(0, ")");
	}
      else if (token == IDENT_T)
	{
	  lex->ReportRuleUsed("47");
	  code -> WriteCode(tabs, lex->GetLexeme());
	  code -> WriteCode(0, "(");
	  token = lex->GetToken();
	  stmt_list(tabs, "", ret);
	  code -> WriteCode(tabs, ")");
	}
      else if (token == MINUS_T)
	{
	  // applying rules 37
	  lex->ReportRuleUsed("37");
	  token = lex->GetToken();
	  stmt(tabs, "", ret);
	  code -> WriteCode(0, "-");
	  stmt_list(0, "-", ret);
	}
      
      else if(token == DIV_T)
	{
	  lex->ReportRuleUsed("38");
	  token = lex->GetToken();
	  stmt(tabs, "", ret);
	  code -> WriteCode(0, "/");
	  stmt_list(0, "/", ret);
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
	  stmt(0, "", ret);
	  code -> WriteCode(0, ":\n");
	  tabs++;
	  stmt(tabs, "", ret);
	  tabs--;
	  code -> WriteCode(0, "\n");
	  else_part(tabs, ret);
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
                  stmt_pair_body(tabs, ret);
                }
              else
		stmt_pair_body(tabs, ret);
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
	  stmt(0, "", ret);
	  code -> WriteCode(0, ") ");
	}
      else if (token == NOT_T)
	{
	  lex->ReportRuleUsed("30");
	  code -> WriteCode(tabs, lex->GetLexeme() + " ");
	  token = lex->GetToken();
	  stmt(tabs, "", ret);
	}

      else if (token == NUMBERP_T)
	{
	  lex->ReportRuleUsed("31");
	  token = lex->GetToken();
	  code -> WriteCode(tabs, "numberp(");
	  stmt(tabs, "", ret);
	  code -> WriteCode(tabs, ")");
	}
      else if (token == LISTP_T)
	{
	  lex->ReportRuleUsed("32");
	  token = lex->GetToken();
	  code -> WriteCode(tabs, "listp(");
	  stmt(tabs, "", ret);
	  code -> WriteCode(tabs, ")");
	}
      else if (token == ZEROP_T)
	{
	  lex->ReportRuleUsed("33");
	  token = lex->GetToken();
	  code -> WriteCode(tabs, "zerop(");
	  stmt(tabs, "", ret);
	  code -> WriteCode(tabs, ")");
	}
      else if (token == NULLP_T)
	{
	  lex->ReportRuleUsed("34");
	  token = lex->GetToken();
	  code -> WriteCode(tabs, "nullp(");
	  stmt(tabs, "", ret);
	  code -> WriteCode(tabs, ")");
	}
      else if (token == STRINGP_T)
	{
	  lex->ReportRuleUsed("35");
	  token = lex->GetToken();
	  code -> WriteCode(tabs, "stringp(");
	  stmt(tabs, "", ret);
	  code -> WriteCode(tabs, ")");
	}
      else if (token == ROUND_T)
	{
	  lex->ReportRuleUsed("41");
	  code -> WriteCode(tabs, "round(");
	  token = lex->GetToken();
	  stmt(tabs, "", ret);
	  code -> WriteCode(tabs, ")");
	}
      
      else if (token == DISPLAY_T)
	{
	  lex->ReportRuleUsed("48");
	  code -> WriteCode(tabs, "print(");
	  token = lex->GetToken();
	  stmt(tabs, "", ret);
	  code -> WriteCode(0, ") ");
	}
      else if (token == CONS_T)
	{
	  // applying rule 27
	  lex->ReportRuleUsed("27");
	  code -> WriteCode(tabs, lex->GetLexeme() + "(");
	  token = lex->GetToken();
	  stmt(0, "", ret);
    code -> WriteCode(0, ",");
	  stmt(0, "", ret);
	  code -> WriteCode(0, ")");
	}
      else if (token == MODULO_T)
	{
	  // applying rule 40
	  lex->ReportRuleUsed("40");
	  token = lex->GetToken();
	  stmt(tabs, "", ret);
	  code -> WriteCode(0, "%");
	  stmt(0, "%", ret);
	}
      else if (token == AND_T)
	{
	  lex->ReportRuleUsed("28");
	  token = lex->GetToken();
	  stmt(tabs, "", ret);
	  code -> WriteCode(0, " and ");
	  stmt_list(0, "and", ret);
	}
      else if (token == OR_T)
	{
	  lex->ReportRuleUsed("29");
	  token = lex->GetToken();
	  stmt(tabs, "", ret);
	  code -> WriteCode(0, " or ");
	  stmt_list(0, "or", ret);
	}
      
      else if (token == PLUS_T)
	{
	  lex->ReportRuleUsed("36");
	  token = lex->GetToken();
	  stmt(tabs, "", ret);
	  code -> WriteCode(0, "+");
	  stmt_list(0, "+", ret);
	}

      else if (token == MULT_T)
	{
	  lex->ReportRuleUsed("39");
	  token = lex->GetToken();
	  stmt(tabs, "", ret);
	  code -> WriteCode(0, "*");
	  stmt_list(0, "*", ret);
	}
      else if (token == EQUALTO_T)
	{
	  lex->ReportRuleUsed("42");
	  token = lex->GetToken();
	  code -> WriteCode(tabs, "(");
	  stmt(0,"",ret);
	  code -> WriteCode(0, ")");
	  code -> WriteCode(0, "==(");
	  stmt_list(0, "==", ret);
	  code -> WriteCode(0, ")");
	}
      else if (token == GT_T)
	{
	  lex->ReportRuleUsed("43");
	  token = lex->GetToken();
	  code -> WriteCode(tabs, "(");
	  stmt(0, "", ret);
	  code -> WriteCode(0, ")>(");
	  stmt_list(0, ">", ret);
	  code -> WriteCode(0, ")");
	}
      else if (token == LT_T)
	{
	  lex->ReportRuleUsed("44");
	  token = lex->GetToken();
	  code -> WriteCode(tabs, "(");
	  stmt(0, "", ret);
	  code -> WriteCode(0, ")");
	  code -> WriteCode(0, "<(");
	  stmt_list(0, "<", ret);
	  code -> WriteCode(0, ")");
	}
      else if (token == GTE_T)
	{
	  lex->ReportRuleUsed("45");
	  token = lex->GetToken();
	  code -> WriteCode(tabs, "(");
	  stmt(0, "", ret);
	  code -> WriteCode(0, ")>=(");
	  stmt_list(0, ">=", ret);
	  code -> WriteCode(0, ")");
	}
      else if (token == LTE_T)
	{
	  lex->ReportRuleUsed("46");
	  token = lex->GetToken();
	  code -> WriteCode(tabs, "(");
	  stmt(0, "", ret);
	  code -> WriteCode(0, ")<=(");
	  stmt_list(0, "<=", ret);
	  code -> WriteCode(0, ")");
	}
      else if (token == IDENT_T)
	{
	  lex->ReportRuleUsed("47");
	  code -> WriteCode(tabs, lex->GetLexeme());
	  code -> WriteCode(0, "(");
	  token = lex->GetToken();
	  stmt_list(tabs, "", ret);
	  code -> WriteCode(0, ")");
	}
      else if (token == MINUS_T)
	{
	  // applying rules 37
	  lex->ReportRuleUsed("37");
	  token = lex->GetToken();
	  stmt(tabs, "", ret);
	  code -> WriteCode(0, "-");
	  stmt_list(0, "-", ret);
	}
      
      else if(token == DIV_T)
	{
	  lex->ReportRuleUsed("38");
	  token = lex->GetToken();
	  stmt(tabs, "", ret);
	  code -> WriteCode(0, "/");
	  stmt_list(0, "/", ret);
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

int SyntacticalAnalyzer::stmt_pair_body(int tabs, string ret)
{
  lex->ReportFunctionEntered("Stmt_Pair_Body", token);

  if (token == ELSE_T)
  {
    // applying rule 23
    lex->ReportRuleUsed("23");
    code -> WriteCode(tabs, lex->GetLexeme() + ":\n");
    token = lex->GetToken();
    tabs++;
    stmt(tabs, "", ret);
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
    stmt(0, "", ret);
    code -> WriteCode(0, ":\n");

    tabs++;
    stmt(tabs, "", ret);
    tabs--;
    if (token == RPAREN_T)
      token = lex->GetToken();
    else
    {
      lex->ReportError("'RPAREN_T' expected");
      errors++;
    }

    code -> WriteCode(0, "\n");
    stmt_pair(tabs, ret);
  }

  lex->ReportFunctionExited("Stmt_Pair_Body", token);
  return errors;
}

int SyntacticalAnalyzer::stmt_pair(int tabs, string ret)
{
  lex->ReportFunctionEntered("Stmt_Pair", token);

  if (token == LPAREN_T)
  {
    // applying rule 20
    lex->ReportRuleUsed("20");
    token = lex->GetToken();
    code -> WriteCode(0, "\n");
    stmt_pair_body(tabs, ret);
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

int SyntacticalAnalyzer::else_part(int tabs, string ret)
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
  stmt(tabs, "", ret);
  tabs--;
  code -> WriteCode(0, "\n");

  lex->ReportFunctionExited("Else_Part", token);
  return errors;
}

int SyntacticalAnalyzer::param_list(int tabs, string ret)
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
    param_list(tabs, ret);
  }

  lex->ReportFunctionExited("Param_List", token);
  return errors;
}

int SyntacticalAnalyzer::more_tokens(int tabs, string ret)
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
  any_other_token(tabs, ret);
  code -> WriteCode(0, " ");
  more_tokens(tabs, ret);

  lex->ReportFunctionExited("More_Tokens", token);
  return errors;
}

int SyntacticalAnalyzer::quoted_lit(int tabs, string ret)
{
  lex->ReportFunctionEntered("Quoted_Lit", token);
  // applying rule 13
  lex->ReportRuleUsed("13");
  any_other_token(tabs, ret);

  lex->ReportFunctionExited("Quoted_Lit", token);
  return errors;
}

int SyntacticalAnalyzer::literal(int tabs, string ret)
{
  lex->ReportFunctionEntered("Literal", token);
  int listFlag = 0;
  if (token == NUMLIT_T)
  {
    // applying rule 10
    lex->ReportRuleUsed("10");
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
    token = lex->GetToken();
    if (token == LPAREN_T)
    {
      listFlag++;
      code -> WriteCode(tabs, "[");
    }
    else
<<<<<<< HEAD
      code -> WriteCode(tabs, "\"");
    quoted_lit(tabs, ret);
=======
      code -> WriteCode(tabs, "");
    quoted_lit(tabs);
>>>>>>> eb0273beca3e384b5927c91557ee85f41f40493b
    if (listFlag)
      code -> WriteCode(0, "]");
    else
      code -> WriteCode(0, "");
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

int SyntacticalAnalyzer::stmt(int tabs, string act, string ret)
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
    action(tabs, ret);
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
    literal(tabs, ret);
  }

  lex->ReportFunctionExited("Stmt", token);
  return errors;
}

int SyntacticalAnalyzer::stmt_list(int tabs, string act, string ret)
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
  stmt(tabs, act, ret);
  stmt_list(tabs, act, ret);

  lex->ReportFunctionExited("Stmt_List", token);
  return errors;
}

int SyntacticalAnalyzer::define(int tabs)
{
  lex->ReportFunctionEntered("Define", token);

  string ret = "";

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
        param_list(tabs, ret);
        if (token == RPAREN_T)
        {
          code -> WriteCode(0, "): \n");
          tabs++;
          token = lex->GetToken();
<<<<<<< HEAD
	  code -> WriteCode(tabs, "\n");
          stmt(tabs, "", ret);
	  //code -> WriteCode(tabs, "\n");
          stmt_list(tabs, "", ret);
	  //code -> WriteCode(tabs, "\n");
	  tabs--;
=======
	        code -> WriteCode(0, "\n");
          stmt(tabs);
	        //code -> WriteCode(tabs, "\n");
          stmt_list(tabs);
	        //code -> WriteCode(tabs, "\n");
	        tabs--;
>>>>>>> 23dd0e703a4c7c692e828aa7d8c288377f217053
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

<<<<<<< HEAD
  code -> WriteCode(tabs + 1, "return\n");
=======
  code -> WriteCode(0, "\n");
>>>>>>> 23dd0e703a4c7c692e828aa7d8c288377f217053
  lex->ReportFunctionExited("Define", token);
  return errors;
}

int SyntacticalAnalyzer::more_defines(int tabs)
{
  lex->ReportFunctionEntered("More_Defines", token);

  string ret = "";
  if (token == IDENT_T)
  {
    // applying rule 3
    lex->ReportRuleUsed("3");
    code -> WriteCode(tabs, lex->GetLexeme()+"(");
    token = lex->GetToken();
<<<<<<< HEAD
<<<<<<< HEAD
    stmt_list(tabs, "", ret);
    code->WriteCode(0,")");
=======
    
    stmt_list(tabs);
    code -> WriteCode(tabs, ")\n");
>>>>>>> 23dd0e703a4c7c692e828aa7d8c288377f217053
=======
    stmt_list(tabs, "");
    code->WriteCode(0,")\n");
>>>>>>> eb0273beca3e384b5927c91557ee85f41f40493b
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
