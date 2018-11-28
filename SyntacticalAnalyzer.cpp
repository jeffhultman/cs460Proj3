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
  errors = program();
}

SyntacticalAnalyzer::~SyntacticalAnalyzer()
{
  delete lex;
}

int SyntacticalAnalyzer::any_other_token()
{
  lex->ReportFunctionEntered("Any_Other_Token", token);

  if (token == IDENT_T)
  {
    lex->ReportRuleUsed("51");
    token = lex->GetToken();
  }
  else if (token == NUMLIT_T)
  {
    lex->ReportRuleUsed("52");
    token = lex->GetToken();
  }
  else if (token == STRLIT_T)
  {
    lex->ReportRuleUsed("53");
    token = lex->GetToken();
  }
  else if (token == CONS_T)
  {
    lex->ReportRuleUsed("54");
    token = lex->GetToken();
  }
  else if (token == IF_T)
  {
    lex->ReportRuleUsed("55");
    token = lex->GetToken();
  }
  else if (token == DISPLAY_T)
  {
    lex->ReportRuleUsed("56");
    token = lex->GetToken();
  }
  else if (token == NEWLINE_T)
  {
    lex->ReportRuleUsed("57");
    token = lex->GetToken();
  }
  else if (token == LISTOP_T)
  {
    lex->ReportRuleUsed("58");
    token = lex->GetToken();
  }
  else if (token == AND_T)
  {
    lex->ReportRuleUsed("59");
    token = lex->GetToken();
  }
  else if (token == OR_T)
  {
    lex->ReportRuleUsed("60");
    token = lex->GetToken();
  }
  else if (token == NOT_T)
  {
    lex->ReportRuleUsed("61");
    token = lex->GetToken();
  }
  else if (token == DEFINE_T)
  {
    lex->ReportRuleUsed("62");
    token = lex->GetToken();
  }
  else if (token == NUMBERP_T)
  {
    lex->ReportRuleUsed("63");
    token = lex->GetToken();
  }
  else if (token == LISTP_T)
  {
    lex->ReportRuleUsed("64");
    token = lex->GetToken();
  }
  else if (token == ZEROP_T)
  {
    lex->ReportRuleUsed("65");
    token = lex->GetToken();
  }

  else if (token == NULLP_T)
  {
    lex->ReportRuleUsed("66");
    token = lex->GetToken();
  }
  else if (token == STRINGP_T)
  {
    lex->ReportRuleUsed("67");
    token = lex->GetToken();
  }
  else if (token == PLUS_T)
  {
    lex->ReportRuleUsed("68");
    token = lex->GetToken();
  }
  else if (token == MINUS_T)
  {
    lex->ReportRuleUsed("69");
    token = lex->GetToken();
  }

  else if (token == DIV_T)
  {
    lex->ReportRuleUsed("70");
    token = lex->GetToken();
  }
  else if (token == MULT_T)
  {
    lex->ReportRuleUsed("71");
    token = lex->GetToken();
  }
  else if (token == MODULO_T)
  {
    lex->ReportRuleUsed("72");
    token = lex->GetToken();
  }
  else if (token == ROUND_T)
  {
    lex->ReportRuleUsed("73");
    token = lex->GetToken();
  }

  else if (token == EQUALTO_T)
  {
    lex->ReportRuleUsed("74");
    token = lex->GetToken();
  }

  else if (token == GT_T)
  {
    lex->ReportRuleUsed("75");
    token = lex->GetToken();
  }

  else if (token == LT_T)
  {
    lex->ReportRuleUsed("76");
    token = lex->GetToken();
  }

  else if (token == GTE_T)
  {
    lex->ReportRuleUsed("77");
    token = lex->GetToken();
  }

  else if (token == LTE_T)
  {
    lex->ReportRuleUsed("78");
    token = lex->GetToken();
  }

  else if (token == COND_T)
  {
    lex->ReportRuleUsed("80");
    token = lex->GetToken();
  }
  else if (token == ELSE_T)
  {
    lex->ReportRuleUsed("81");
    token = lex->GetToken();
  }

  else if (token == LPAREN_T)
  {
    // applying rule 50
    lex->ReportRuleUsed("50");
    token = lex->GetToken();
    more_tokens();
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
    token = lex->GetToken();
    any_other_token();
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

int SyntacticalAnalyzer::action()
{
  lex->ReportFunctionEntered("Action", token);

  if (token == IF_T)
  {
    // applying rule 24
    lex->ReportRuleUsed("24");
    token = lex->GetToken();
    stmt();
    stmt();
    else_part();
  }
  else if (token == COND_T)
  {
    // applying rule 25
    lex->ReportRuleUsed("25");
    token = lex->GetToken();
    if (token == LPAREN_T)
    {
      token = lex->GetToken();
      stmt_pair_body();
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
    token = lex->GetToken();
    stmt();
  }
  else if (token == NOT_T)
  {
    lex->ReportRuleUsed("30");
    token = lex->GetToken();
    stmt();
  }

  else if (token == NUMBERP_T)
  {
    lex->ReportRuleUsed("31");
    token = lex->GetToken();
    stmt();
  }
  else if (token == LISTP_T)
  {
    lex->ReportRuleUsed("32");
    token = lex->GetToken();
    stmt();
  }
  else if (token == ZEROP_T)
  {
    lex->ReportRuleUsed("33");
    token = lex->GetToken();
    stmt();
  }
  else if (token == NULLP_T)
  {
    lex->ReportRuleUsed("34");
    token = lex->GetToken();
    stmt();
  }
  else if (token == STRINGP_T)
  {
    lex->ReportRuleUsed("35");
    token = lex->GetToken();
    stmt();
  }
  else if (token == ROUND_T)
  {
    lex->ReportRuleUsed("41");
    token = lex->GetToken();
    stmt();
  }

  else if (token == DISPLAY_T)
  {
    lex->ReportRuleUsed("48");
    token = lex->GetToken();
    stmt();
  }
  else if (token == CONS_T)
  {
    // applying rule 27
    lex->ReportRuleUsed("27");
    token = lex->GetToken();
    stmt();
    stmt();
  }
  else if (token == MODULO_T)
  {
    // applying rule 40
    lex->ReportRuleUsed("40");
    token = lex->GetToken();
    stmt();
    stmt();
  }
  else if (token == AND_T)
  {
    lex->ReportRuleUsed("28");
    token = lex->GetToken();
    stmt_list();
  }
  else if (token == OR_T)
  {
    lex->ReportRuleUsed("29");
    token = lex->GetToken();
    stmt_list();
  }

  else if (token == PLUS_T)
  {
    lex->ReportRuleUsed("36");
    token = lex->GetToken();
    stmt_list();
  }

  else if (token == MULT_T)
  {
    lex->ReportRuleUsed("39");
    token = lex->GetToken();
    stmt_list();
  }
  else if (token == EQUALTO_T)
  {
    lex->ReportRuleUsed("42");
    token = lex->GetToken();
    stmt_list();
  }
  else if (token == GT_T)
  {
    lex->ReportRuleUsed("43");
    token = lex->GetToken();
    stmt_list();
  }
  else if (token == LT_T)
  {
    lex->ReportRuleUsed("44");
    token = lex->GetToken();
    stmt_list();
  }
  else if (token == GTE_T)
  {
    lex->ReportRuleUsed("45");
    token = lex->GetToken();
    stmt_list();
  }
  else if (token == LTE_T)
  {
    lex->ReportRuleUsed("46");
    token = lex->GetToken();
    stmt_list();
  }
  else if (token == IDENT_T)
  {
    lex->ReportRuleUsed("47");
    token = lex->GetToken();
    stmt_list();
  }
  else if (token == MINUS_T)
  {
    // applying rules 37
    lex->ReportRuleUsed("37");
    token = lex->GetToken();
    stmt();
    stmt_list();
  }

  else if(token == DIV_T)
  {
    lex->ReportRuleUsed("38");
    token = lex->GetToken();
    stmt();
    stmt_list();
  }
  else if (token == NEWLINE_T)
  {
    // applying rule 49
    lex->ReportRuleUsed("49");
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

int SyntacticalAnalyzer::stmt_pair_body()
{
  lex->ReportFunctionEntered("Stmt_Pair_Body", token);

  if (token == ELSE_T)
  {
    // applying rule 23
    lex->ReportRuleUsed("23");
    token = lex->GetToken();
    stmt();
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
    stmt();
    stmt();
    if (token == RPAREN_T)
      token = lex->GetToken();
    else
    {
      lex->ReportError("'RPAREN_T' expected");
      errors++;
    }
    stmt_pair();
  }

  lex->ReportFunctionExited("Stmt_Pair_Body", token);
  return errors;
}

int SyntacticalAnalyzer::stmt_pair()
{
  lex->ReportFunctionEntered("Stmt_Pair", token);

  if (token == LPAREN_T)
  {
    // applying rule 20
    lex->ReportRuleUsed("20");
    token = lex->GetToken();
    stmt_pair_body();
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

int SyntacticalAnalyzer::else_part()
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
  stmt();

  lex->ReportFunctionExited("Else_Part", token);
  return errors;
}

int SyntacticalAnalyzer::param_list()
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
    lex->ReportRuleUsed("16");
    token = lex->GetToken();
    param_list();
  }

  lex->ReportFunctionExited("Param_List", token);
  return errors;
}

int SyntacticalAnalyzer::more_tokens()
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
  any_other_token();
  more_tokens();

  lex->ReportFunctionExited("More_Tokens", token);
  return errors;
}

int SyntacticalAnalyzer::quoted_lit()
{
  lex->ReportFunctionEntered("Quoted_Lit", token);
  // applying rule 13
  lex->ReportRuleUsed("13");
  any_other_token();

  lex->ReportFunctionExited("Quoted_Lit", token);
  return errors;
}

int SyntacticalAnalyzer::literal()
{
  lex->ReportFunctionEntered("Literal", token);

  if (token == NUMLIT_T)
  {
    // applying rule 10
    lex->ReportRuleUsed("10 ");
    token = lex->GetToken();
  }
  else if (token == STRLIT_T)
  {
    // applying rule 11
    lex->ReportRuleUsed("11");
    token = lex->GetToken();
  }
  else if (token == SQUOTE_T)
  {
    // applying rule 12
    lex->ReportRuleUsed("12");
    token = lex->GetToken();
    quoted_lit();
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

int SyntacticalAnalyzer::stmt()
{
  lex->ReportFunctionEntered("Stmt", token);

  if (token == IDENT_T)
  {
    // applying rule 8
    lex->ReportRuleUsed("8");
    token = lex->GetToken();
  }
  else if (token == LPAREN_T)
  {
    // applying rule 9
    lex->ReportRuleUsed("9");
    token = lex->GetToken();
    action();
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
    literal();
  }

  lex->ReportFunctionExited("Stmt", token);
  return errors;
}

int SyntacticalAnalyzer::stmt_list()
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
  stmt();
  stmt_list();

  lex->ReportFunctionExited("Stmt_List", token);
  return errors;
}

int SyntacticalAnalyzer::define()
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
        token = lex->GetToken();
        param_list();
        if (token == RPAREN_T)
        {
          token = lex->GetToken();
          stmt();
          stmt_list();
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

  lex->ReportFunctionExited("Define", token);
  return errors;
}

int SyntacticalAnalyzer::more_defines()
{
  lex->ReportFunctionEntered("More_Defines", token);

  if (token == IDENT_T)
  {
    // applying rule 3
    lex->ReportRuleUsed("3");
    token = lex->GetToken();
    stmt_list();
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
    define();
    if (token == LPAREN_T)
    {
      token = lex->GetToken();
      more_defines();
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

int SyntacticalAnalyzer::program()
{
  lex->ReportFunctionEntered("Program", token);

  if (token == LPAREN_T)
  {
    // applying rule 1
    lex->ReportRuleUsed("1");
    token = lex->GetToken();
    define();
    if (token == LPAREN_T)
    {
      token = lex->GetToken();
      more_defines();
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
