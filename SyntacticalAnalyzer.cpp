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
  buildingStatement = 0;
  errors = program(tabs);
}

SyntacticalAnalyzer::~SyntacticalAnalyzer()
{
  delete lex;
  delete code;
}

int SyntacticalAnalyzer::any_other_token(int tabs, string ret)
{
  // Most likely from a string literal or list, will write to the python file
  // file as the intended type.
  lex->ReportFunctionEntered("Any_Other_Token", token);

  if (token == IDENT_T)
  {
    //A statement being built means that we are in the middle of the line
    // and dont want to place an assignment operator. If a statement is not being
    // built then the return value can be overridden with the current statement.
    if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
    buildingStatement++;
    lex->ReportRuleUsed("51");
    code->WriteCode(0, "\"");
    code->WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code->WriteCode(0, "\"");
    buildingStatement--;
  }
  // Each token check will handle a type of token in a similar way.
  else if (token == NUMLIT_T)
  {
    if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
    // We just started a statement so everything until we see until we finish this
    // statement will be part of this statement.
    buildingStatement++;
    lex->ReportRuleUsed("52");
    code->WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    // Now the statement is over, this one may not have been all that exciting but later
    // ones will be, see the comment over those lines for an explination.
    buildingStatement--;
  }
  else if (token == STRLIT_T)
  {
    if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
    buildingStatement++;
    code->WriteCode(0, "\"");
    lex->ReportRuleUsed("53");
    code->WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code->WriteCode(0, "\"");
    buildingStatement--;
  }
  else if (token == CONS_T)
  {
    // Note that at this point, all operators are being
    // interpreted as strings, not the operator theyre named after.
    if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
    buildingStatement++;
    code->WriteCode(0, "\"");
    lex->ReportRuleUsed("54");
    code->WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code->WriteCode(0, "\"");
    buildingStatement--;
  }
  else if (token == IF_T)
  {
    if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
    buildingStatement++;
    code->WriteCode(0, "\"");
    lex->ReportRuleUsed("55");
    code->WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code->WriteCode(0, "\"");
    buildingStatement--;
  }
  else if (token == DISPLAY_T)
  {
    if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
    buildingStatement++;
    code->WriteCode(0, "\"");
    lex->ReportRuleUsed("56");
    code->WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code->WriteCode(0, "\"");
    buildingStatement--;
  }
  else if (token == NEWLINE_T)
  {
    if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
    buildingStatement++;
    code->WriteCode(0, "\"");
    lex->ReportRuleUsed("57");
    code->WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code->WriteCode(0, "\"");
    buildingStatement--;
  }
  else if (token == LISTOP_T)
  {
    if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
    buildingStatement++;
    code->WriteCode(0, "\"");
    lex->ReportRuleUsed("58");
    code->WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code->WriteCode(0, "\"");
    buildingStatement--;
  }
  else if (token == AND_T)
  {
    if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
    buildingStatement++;
    code->WriteCode(0, "\"");
    lex->ReportRuleUsed("59");
    code->WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code->WriteCode(0, "\"");
    buildingStatement--;
  }
  else if (token == OR_T)
  {
    if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
    buildingStatement++;
    code->WriteCode(0, "\"");
    lex->ReportRuleUsed("60");
    code->WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code->WriteCode(0, "\"");
    buildingStatement--;
  }
  else if (token == NOT_T)
  {
    if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
    buildingStatement++;
    code->WriteCode(0, "\"");
    lex->ReportRuleUsed("61");
    code->WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code->WriteCode(0, "\"");
    buildingStatement--;
  }
  else if (token == DEFINE_T)
  {
    if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
    buildingStatement++;
    code->WriteCode(0, "\"");
    lex->ReportRuleUsed("62");
    code->WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code->WriteCode(0, "\"");
    buildingStatement--;
  }
  else if (token == NUMBERP_T)
  {
    if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
    buildingStatement++;
    code->WriteCode(0, "\"");
    lex->ReportRuleUsed("63");
    code->WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code->WriteCode(0, "\"");
    buildingStatement--;
  }
  else if (token == LISTP_T)
  {
    if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
    buildingStatement++;
    code->WriteCode(0, "\"");
    lex->ReportRuleUsed("64");
    code->WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code->WriteCode(0, "\"");
    buildingStatement--;
  }
  else if (token == ZEROP_T)
  {
    if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
    buildingStatement++;
    code->WriteCode(0, "\"");
    lex->ReportRuleUsed("65");
    code->WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code->WriteCode(0, "\"");
    buildingStatement--;
  }

  else if (token == NULLP_T)
  {
    if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
    buildingStatement++;
    code->WriteCode(0, "\"");
    lex->ReportRuleUsed("66");
    code->WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code->WriteCode(0, "\"");
    buildingStatement--;
  }
  else if (token == STRINGP_T)
  {
    if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
    buildingStatement++;
    code->WriteCode(0, "\"");
    lex->ReportRuleUsed("67");
    code->WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code->WriteCode(0, "\"");
    buildingStatement--;
  }
  else if (token == PLUS_T)
  {
    if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
    buildingStatement++;
    code->WriteCode(0, "\"");
    lex->ReportRuleUsed("68");
    code->WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code->WriteCode(0, "\"");
    buildingStatement--;
  }
  else if (token == MINUS_T)
  {
    if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
    buildingStatement++;
    code->WriteCode(0, "\"");
    lex->ReportRuleUsed("69");
    code->WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code->WriteCode(0, "\"");
    buildingStatement--;
  }

  else if (token == DIV_T)
  {
    if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
    buildingStatement++;
    code->WriteCode(0, "\"");
    lex->ReportRuleUsed("70");
    code->WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code->WriteCode(0, "\"");
    buildingStatement--;
  }
  else if (token == MULT_T)
  {
    if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
    buildingStatement++;
    code->WriteCode(0, "\"");
    lex->ReportRuleUsed("71");
    code->WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code->WriteCode(0, "\"");
    buildingStatement--;
  }
  else if (token == MODULO_T)
  {
    if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
    buildingStatement++;
    code->WriteCode(0, "\"");
    lex->ReportRuleUsed("72");
    code->WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code->WriteCode(0, "\"");
    buildingStatement--;
  }
  else if (token == ROUND_T)
  {
    if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
    buildingStatement++;
    code->WriteCode(0, "\"");
    lex->ReportRuleUsed("73");
    code->WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code->WriteCode(0, "\"");
    buildingStatement--;
  }

  else if (token == EQUALTO_T)
  {
    if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
    buildingStatement++;
    code->WriteCode(0, "\"");
    lex->ReportRuleUsed("74");
    code->WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code->WriteCode(0, "\"");
    buildingStatement--;
  }

  else if (token == GT_T)
  {
    if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
    buildingStatement++;
    code->WriteCode(0, "\"");
    lex->ReportRuleUsed("75");
    code->WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code->WriteCode(0, "\"");
    buildingStatement--;
  }

  else if (token == LT_T)
  {
    if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
    buildingStatement++;
    code->WriteCode(0, "\"");
    lex->ReportRuleUsed("76");
    code->WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code->WriteCode(0, "\"");
    buildingStatement--;
  }

  else if (token == GTE_T)
  {
    if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
    buildingStatement++;
    code->WriteCode(0, "\"");
    lex->ReportRuleUsed("77");
    code->WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code->WriteCode(0, "\"");
    buildingStatement--;
  }

  else if (token == LTE_T)
  {
    if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
    buildingStatement++;
    code->WriteCode(0, "\"");
    lex->ReportRuleUsed("78");
    code->WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code->WriteCode(0, "\"");
    buildingStatement--;
  }

  else if (token == COND_T)
  {
    if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
    buildingStatement++;
    code->WriteCode(0, "\"");
    lex->ReportRuleUsed("80");
    code->WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code->WriteCode(0, "\"");
    buildingStatement--;
  }
  else if (token == ELSE_T)
  {
    if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
    buildingStatement++;
    code->WriteCode(0, "\"");
    lex->ReportRuleUsed("81");
    code->WriteCode(0, lex->GetLexeme());
    token = lex->GetToken();
    code->WriteCode(0, "\"");
    buildingStatement--;
  }

  else if (token == LPAREN_T)
  {
    // here is an exciting case, as before a statement is being built.
    if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
    buildingStatement++;
    // applying rule 50
    lex->ReportRuleUsed("50");
    code->WriteCode(0, " ");
    token = lex->GetToken();
    // Note at this point more tokens is being called, it will not have return
    // statements since anything it does is still part of this statement.
    more_tokens(tabs, ret);
    if (token == RPAREN_T)
      token = lex->GetToken();
    else
    {
      lex->ReportError("'RPAREN_T' expected");
      errors++;
    }
    buildingStatement--;
  }
  else if (token == SQUOTE_T)
  {
    // A single quote normally denotes a list, however inside of a list it behaves strangely.
    // This is a special case to handle specifically that case.
    if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
    buildingStatement++;
    // applying rule 79
    lex->ReportRuleUsed("79");
    code->WriteCode(0, "[");
    code->WriteCode(0, "\"quote\", ");
    token = lex->GetToken();
    any_other_token(tabs, ret);
    code->WriteCode(0, "]");
    buildingStatement--;
  }
  else
  {
    lex->ReportError("'" + lex->GetLexeme() + "' unexpected");
    errors++;
    token = lex->GetToken();
  }
  if (token != RPAREN_T)
      code->WriteCode(0, ",");
  lex->ReportFunctionExited("Any_Other_Token", token);
  return errors;
}

int SyntacticalAnalyzer::action(int tabs, string ret)
{
  // Action is nearly identicle to the Lparen segment of the any other token
  // function. The main difference is that the output statements and operations
  // will do something and not be interpreted as strings. 
  /*****************************************************************************/
  //Note that action is split into two parts, Actions with a conditional that have an else
  // and actions that do not have the else. Given this implementation there is a huge block of code
  // That is nearly identicle to the code below. This can certainly be optimized and reduced but simple has
  // not been.
  int tempTabs = tabs;
  lex->ReportFunctionEntered("Action", token);
  if (flag == 0)
  {
    flag = 1;
    if (token == IF_T)
    {
      // any statement thats part of the if should not override the returnValue.
      // applying rule 24
      buildingStatement++;
      lex->ReportRuleUsed("24");
      code->WriteCode(tabs, lex->GetLexeme() + " ");
      token = lex->GetToken();
      stmt(0, "", ret);
      code->WriteCode(0, ":\n");
      buildingStatement--;
      // Because we are converting to python, we have to carefully watch over our tabs.
      tabs++;
      stmt(tabs, "", ret);
      tabs--;
      code->WriteCode(0, "\n");
      else_part(tabs, ret);
      code->WriteCode(0, "\n");
    }
    else if (token == COND_T)
    {
      // applying rule 25
      //Conditionals were treated as seperate if statements, not elif statements.
      lex->ReportRuleUsed("25");
      token = lex->GetToken();
      if (token == LPAREN_T)
      {
        token = lex->GetToken();
        if (token == ELSE_T)
        {
          //In scheme, having a else statement by itself is valid, to address this, we've
          // decided to have an impossible to enter if statement.
          code->WriteCode(tabs, "if (0):\n");
          code->WriteCode(tabs + 1, "0\n");
          stmt_pair_body(tabs, ret);
        }
        else
          stmt_pair_body(tabs, ret);
        code->WriteCode(0, "\n");
      }
      else
      {
        lex->ReportError("'LPAREN_T' expected");
        errors++;
      }
    }
    else if (token == LISTOP_T)
    {
      //There is an included file for python that allows for listoperations. Since
      // nearly all of the if blocks below are nearly identicle or use repeating logic
      // new comments will only be provided for those with new logic.
      lex->ReportRuleUsed("26");
      if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
      buildingStatement++;
      code->WriteCode(tabs, "listop('" + lex->GetLexeme() + "',");
      token = lex->GetToken();
      stmt(tabs, "", ret);
      code->WriteCode(0, ") ");
      buildingStatement--;
    }
    else if (token == NOT_T)
    {
      if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
      buildingStatement++;
      lex->ReportRuleUsed("30");
      code->WriteCode(tabs, lex->GetLexeme() + " ");
      token = lex->GetToken();
      stmt(tabs, "", ret);
      buildingStatement--;
    }

    else if (token == NUMBERP_T)
    {
      if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
      buildingStatement++;
      lex->ReportRuleUsed("31");
      code->WriteCode(tabs, "numberp(");
      token = lex->GetToken();
      stmt(tabs, "", ret);
      code->WriteCode(tabs, ") ");
      buildingStatement--;
    }
    else if (token == LISTP_T)
    {
      if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
      buildingStatement++;
      lex->ReportRuleUsed("32");
      token = lex->GetToken();
      code->WriteCode(tabs, "listp(");
      stmt(tabs, "", ret);
      code->WriteCode(tabs, ") ");
      buildingStatement--;
    }
    else if (token == ZEROP_T)
    {
      if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
      buildingStatement++;
      lex->ReportRuleUsed("33");
      token = lex->GetToken();
      code->WriteCode(tabs, "zerop(");
      stmt(tabs, "", ret);
      code->WriteCode(tabs, ")");
      buildingStatement--;
    }
    else if (token == NULLP_T)
    {
      if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
      buildingStatement++;
      lex->ReportRuleUsed("34");
      token = lex->GetToken();
      code->WriteCode(tabs, "nullp(");
      stmt(tabs, "", ret);
      code->WriteCode(tabs, ")");
      buildingStatement--;
    }
    else if (token == STRINGP_T)
    {
      if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
      buildingStatement++;
      lex->ReportRuleUsed("35");
      token = lex->GetToken();
      code->WriteCode(tabs, "stringp(");
      stmt(tabs, "", ret);
      code->WriteCode(tabs, ")");
      buildingStatement--;
    }
    else if (token == ROUND_T)
    {
      if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
      buildingStatement++;
      lex->ReportRuleUsed("41");
      code->WriteCode(tabs, "round(");
      token = lex->GetToken();
      stmt(tabs, "", ret);
      code->WriteCode(tabs, ")");
      buildingStatement--;
    }

    else if (token == DISPLAY_T)
    {
      //Python's print behaves similarly to display
      if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
      buildingStatement++;
      lex->ReportRuleUsed("48");
      code->WriteCode(tabs, "print(");
      token = lex->GetToken();
      stmt(tabs, "", ret);
      code->WriteCode(0, ") ");
      buildingStatement--;
    }
    else if (token == CONS_T)
    {
      if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
      buildingStatement++;
      // applying rule 27
      lex->ReportRuleUsed("27");
      code->WriteCode(tabs, lex->GetLexeme() + "(");
      token = lex->GetToken();
      stmt(0, "", ret);
      code->WriteCode(0, ",");
      stmt(0, "", ret);
      code->WriteCode(0, ")");
      buildingStatement--;
    }
    else if (token == MODULO_T)
    {
      if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
      buildingStatement++;
      // applying rule 40
      lex->ReportRuleUsed("40");
      token = lex->GetToken();
      stmt(tabs, "", ret);
      code->WriteCode(0, "%");
      stmt(0, "%", ret);
      buildingStatement--;
    }
    else if (token == AND_T)
    {
      if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
      buildingStatement++;
      lex->ReportRuleUsed("28");
      token = lex->GetToken();
      stmt(tabs, "", ret);
      code->WriteCode(0, " and ");
      stmt_list(0, "and", ret);
      buildingStatement--;
    }
    else if (token == OR_T)
    {
      if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
      buildingStatement++;
      lex->ReportRuleUsed("29");
      token = lex->GetToken();
      stmt(tabs, "", ret);
      code->WriteCode(0, " or ");
      stmt_list(0, "or", ret);
      buildingStatement--;
    }

    else if (token == PLUS_T)
    {
      if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
      buildingStatement++;
      lex->ReportRuleUsed("36");
      token = lex->GetToken();
      stmt(tabs, "", ret);
      code->WriteCode(0, "+");
      stmt_list(0, "+", ret);
      buildingStatement--;
    }

    else if (token == MULT_T)
    {
      if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
      buildingStatement++;
      lex->ReportRuleUsed("39");
      token = lex->GetToken();
      stmt(tabs, "", ret);
      code->WriteCode(0, "*");
      stmt_list(0, "*", ret);
      buildingStatement--;
    }
    else if (token == EQUALTO_T)
    {
      if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
      buildingStatement++;
      lex->ReportRuleUsed("42");
      token = lex->GetToken();
      code->WriteCode(tabs, "(");
      stmt(0, "", ret);
      code->WriteCode(0, ")");
      code->WriteCode(0, "==(");
      stmt_list(0, "==", ret);
      code->WriteCode(0, ")");
      buildingStatement--;
    }
    else if (token == GT_T)
    {
      if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
      buildingStatement++;
      lex->ReportRuleUsed("43");
      token = lex->GetToken();
      code->WriteCode(tabs, "(");
      stmt(0, "", ret);
      code->WriteCode(0, ")>(");
      stmt_list(0, ">", ret);
      code->WriteCode(0, ")");
      buildingStatement--;
    }
    else if (token == LT_T)
    {
      if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
      buildingStatement++;
      lex->ReportRuleUsed("44");
      token = lex->GetToken();
      code->WriteCode(tabs, "(");
      stmt(0, "", ret);
      code->WriteCode(0, ")");
      code->WriteCode(0, "<(");
      stmt_list(0, "<", ret);
      code->WriteCode(0, ")");
      buildingStatement--;
    }
    else if (token == GTE_T)
    {
      if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
      buildingStatement++;
      lex->ReportRuleUsed("45");
      token = lex->GetToken();
      code->WriteCode(tabs, "(");
      stmt(0, "", ret);
      code->WriteCode(0, ")>=(");
      stmt_list(0, ">=", ret);
      code->WriteCode(0, ")");
      buildingStatement--;
    }
    else if (token == LTE_T)
    {
      if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
      buildingStatement++;
      lex->ReportRuleUsed("46");
      token = lex->GetToken();
      code->WriteCode(tabs, "(");
      stmt(0, "", ret);
      code->WriteCode(0, ")<=(");
      stmt_list(0, "<=", ret);
      code->WriteCode(0, ")");
      buildingStatement--;
    }
    else if (token == IDENT_T)
    {
      if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
      buildingStatement++;
      lex->ReportRuleUsed("47");
      code->WriteCode(tabs, lex->GetLexeme());
      code->WriteCode(0, "(");
      token = lex->GetToken();
      stmt_list(tabs, "", ret);
      code->WriteCode(tabs, ")");
      buildingStatement--;
    }
    else if (token == MINUS_T)
    {
      if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
      buildingStatement++;
      // applying rules 37
      lex->ReportRuleUsed("37");
      token = lex->GetToken();
      stmt(tabs, "", ret);
      code->WriteCode(0, "-");
      stmt_list(0, "-", ret);
      buildingStatement--;
    }

    else if (token == DIV_T)
    {
      if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
      buildingStatement++;
      lex->ReportRuleUsed("38");
      token = lex->GetToken();
      stmt(tabs, "", ret);
      code->WriteCode(0, "/");
      stmt_list(0, "/", ret);
      buildingStatement--;
    }
    else if (token == NEWLINE_T)
    {
      //An empty print statement behaves the same as newline in scheme
      if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
      buildingStatement++;
      // applying rule 49
      lex->ReportRuleUsed("49");
      code->WriteCode(tabs, "print('')");
      token = lex->GetToken();
      buildingStatement--;
    }
    else
    {
      lex->ReportError("'" + lex->GetLexeme() + "' unexpected");
      errors++;
      token = lex->GetToken();
    }
    // reset the tabs to their original value, set a flag for dealing with if
    // statements, and write a newline.
    code->WriteCode(tabs, "\n");
    flag = 0;
    tabs = tempTabs;
    lex->ReportFunctionExited("Action", token);
    return errors;
  }
  else
  {
    if (token == IF_T)
    {
      buildingStatement++;
      // applying rule 24
      lex->ReportRuleUsed("24");
      code->WriteCode(tabs, lex->GetLexeme() + " ");
      token = lex->GetToken();
      stmt(0, "", ret);
      code->WriteCode(0, ":\n");
      buildingStatement--;
      tabs++;
      stmt(tabs, "", ret);
      tabs--;
      code->WriteCode(0, "\n");
      else_part(tabs, ret);
      code->WriteCode(0, "\n");
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
          code->WriteCode(tabs, "if (0):\n");
          code->WriteCode(tabs + 1, "0\n");
          stmt_pair_body(tabs, ret);
        }
        else
        {
          stmt_pair_body(tabs, ret);
        }
        //tabs--;
        code->WriteCode(0, "\n");
      }
      else
      {
        lex->ReportError("'LPAREN_T' expected");
        errors++;
      }
    }
    else if (token == LISTOP_T)
    {
      if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
      buildingStatement++;
      lex->ReportRuleUsed("26");
      code->WriteCode(tabs, "listop('" + lex->GetLexeme() + "',");
      token = lex->GetToken();
      stmt(0, "", ret);
      code->WriteCode(0, ") ");
      buildingStatement--;
    }
    else if (token == NOT_T)
    {
      if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
      buildingStatement++;
      lex->ReportRuleUsed("30");
      code->WriteCode(tabs, lex->GetLexeme() + " ");
      token = lex->GetToken();
      stmt(tabs, "", ret);
      buildingStatement--;
    }

    else if (token == NUMBERP_T)
    {
      if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
      buildingStatement++;
      lex->ReportRuleUsed("31");
      token = lex->GetToken();
      code->WriteCode(tabs, "numberp(");
      stmt(tabs, "", ret);
      code->WriteCode(tabs, ")");
      buildingStatement--;
    }
    else if (token == LISTP_T)
    {
      if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
      buildingStatement++;
      lex->ReportRuleUsed("32");
      token = lex->GetToken();
      code->WriteCode(tabs, "listp(");
      stmt(tabs, "", ret);
      code->WriteCode(tabs, ")");
      buildingStatement--;
    }
    else if (token == ZEROP_T)
    {
      if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
      buildingStatement++;
      lex->ReportRuleUsed("33");
      token = lex->GetToken();
      code->WriteCode(tabs, "zerop(");
      stmt(tabs, "", ret);
      code->WriteCode(tabs, ")");
      buildingStatement--;
    }
    else if (token == NULLP_T)
    {
      if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
      buildingStatement++;
      lex->ReportRuleUsed("34");
      token = lex->GetToken();
      code->WriteCode(tabs, "nullp(");
      stmt(tabs, "", ret);
      code->WriteCode(tabs, ")");
      buildingStatement--;
    }
    else if (token == STRINGP_T)
    {
      if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
      buildingStatement++;
      lex->ReportRuleUsed("35");
      token = lex->GetToken();
      code->WriteCode(tabs, "stringp(");
      stmt(tabs, "", ret);
      code->WriteCode(tabs, ")");
      buildingStatement--;
    }
    else if (token == ROUND_T)
    {
      if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
      buildingStatement++;
      lex->ReportRuleUsed("41");
      code->WriteCode(tabs, "round(");
      token = lex->GetToken();
      stmt(tabs, "", ret);
      code->WriteCode(tabs, ")");
      buildingStatement--;
    }

    else if (token == DISPLAY_T)
    {
      if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
      buildingStatement++;
      lex->ReportRuleUsed("48");
      code->WriteCode(tabs, "print(");
      token = lex->GetToken();
      stmt(tabs, "", ret);
      code->WriteCode(0, ") ");
      buildingStatement--;
    }
    else if (token == CONS_T)
    {
      if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
      buildingStatement++;
      // applying rule 27
      lex->ReportRuleUsed("27");
      code->WriteCode(tabs, lex->GetLexeme() + "(");
      token = lex->GetToken();
      stmt(0, "", ret);
      code->WriteCode(0, ",");
      stmt(0, "", ret);
      code->WriteCode(0, ")");
      buildingStatement--;
    }
    else if (token == MODULO_T)
    {
      if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
      buildingStatement++;
      // applying rule 40
      lex->ReportRuleUsed("40");
      token = lex->GetToken();
      stmt(tabs, "", ret);
      code->WriteCode(0, "%");
      stmt(0, "%", ret);
      buildingStatement--;
    }
    else if (token == AND_T)
    {
      if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
      buildingStatement++;
      lex->ReportRuleUsed("28");
      token = lex->GetToken();
      stmt(tabs, "", ret);
      code->WriteCode(0, " and ");
      stmt_list(0, "and", ret);
      buildingStatement--;
    }
    else if (token == OR_T)
    {
      if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
      buildingStatement++;
      lex->ReportRuleUsed("29");
      token = lex->GetToken();
      stmt(tabs, "", ret);
      code->WriteCode(0, " or ");
      stmt_list(0, "or", ret);
      buildingStatement--;
    }

    else if (token == PLUS_T)
    {
      if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
      buildingStatement++;
      lex->ReportRuleUsed("36");
      token = lex->GetToken();
      stmt(tabs, "", ret);
      code->WriteCode(0, "+");
      stmt_list(0, "+", ret);
      buildingStatement--;
    }

    else if (token == MULT_T)
    {
      if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
      buildingStatement++;
      lex->ReportRuleUsed("39");
      token = lex->GetToken();
      stmt(tabs, "", ret);
      code->WriteCode(0, "*");
      stmt_list(0, "*", ret);
      buildingStatement--;
    }
    else if (token == EQUALTO_T)
    {
      if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
      buildingStatement++;
      lex->ReportRuleUsed("42");
      token = lex->GetToken();
      code->WriteCode(tabs, "(");
      stmt(0, "", ret);
      code->WriteCode(0, ")");
      code->WriteCode(0, "==(");
      stmt_list(0, "==", ret);
      code->WriteCode(0, ")");
      buildingStatement--;
    }
    else if (token == GT_T)
    {
      if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
      buildingStatement++;
      lex->ReportRuleUsed("43");
      token = lex->GetToken();
      code->WriteCode(tabs, "(");
      stmt(0, "", ret);
      code->WriteCode(0, ")>(");
      stmt_list(0, ">", ret);
      code->WriteCode(0, ")");
      buildingStatement--;
    }
    else if (token == LT_T)
    {
      if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
      buildingStatement++;
      lex->ReportRuleUsed("44");
      token = lex->GetToken();
      code->WriteCode(tabs, "(");
      stmt(0, "", ret);
      code->WriteCode(0, ")");
      code->WriteCode(0, "<(");
      stmt_list(0, "<", ret);
      code->WriteCode(0, ")");
      buildingStatement--;
    }
    else if (token == GTE_T)
    {
      if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
      buildingStatement++;
      lex->ReportRuleUsed("45");
      token = lex->GetToken();
      code->WriteCode(tabs, "(");
      stmt(0, "", ret);
      code->WriteCode(0, ")>=(");
      stmt_list(0, ">=", ret);
      code->WriteCode(0, ")");
      buildingStatement--;
    }
    else if (token == LTE_T)
    {
      if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
      buildingStatement++;
      lex->ReportRuleUsed("46");
      token = lex->GetToken();
      code->WriteCode(tabs, "(");
      stmt(0, "", ret);
      code->WriteCode(0, ")<=(");
      stmt_list(0, "<=", ret);
      code->WriteCode(0, ")");
      buildingStatement--;
    }
    else if (token == IDENT_T)
    {
      if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
      buildingStatement++;
      lex->ReportRuleUsed("47");
      code->WriteCode(tabs, lex->GetLexeme());
      code->WriteCode(0, "(");
      token = lex->GetToken();
      stmt_list(tabs, "", ret);
      code->WriteCode(0, ")");
      buildingStatement--;
    }
    else if (token == MINUS_T)
    {
      if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
      buildingStatement++;
      // applying rules 37
      lex->ReportRuleUsed("37");
      token = lex->GetToken();
      stmt(tabs, "", ret);
      code->WriteCode(0, "-");
      stmt_list(0, "-", ret);
      buildingStatement--;
    }

    else if (token == DIV_T)
    {
      if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
      buildingStatement++;
      lex->ReportRuleUsed("38");
      token = lex->GetToken();
      stmt(tabs, "", ret);
      code->WriteCode(0, "/");
      stmt_list(0, "/", ret);
      buildingStatement--;
    }
    else if (token == NEWLINE_T)
    {
      if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
      buildingStatement++;
      // applying rule 49
      lex->ReportRuleUsed("49");
      code->WriteCode(tabs, "print('')");
      token = lex->GetToken();
      buildingStatement--;
    }
    else
    {
      lex->ReportError("'" + lex->GetLexeme() + "' unexpected");
      errors++;
      token = lex->GetToken();
    }
    tabs = tempTabs;
    lex->ReportFunctionExited("Action", token);
    return errors;
  }
}

int SyntacticalAnalyzer::stmt_pair_body(int tabs, string ret)
{
  // This block of code is specific for if elif and else statements.
  lex->ReportFunctionEntered("Stmt_Pair_Body", token);

  if (token == ELSE_T)
  {
    //pretty much just writes and else to the python file.
    // applying rule 23
    lex->ReportRuleUsed("23");
    code->WriteCode(tabs, lex->GetLexeme() + ":\n");
    token = lex->GetToken();
    tabs++;
    stmt(tabs, "", ret);
    tabs--;
    code->WriteCode(0, "\n");
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
    // its some form of if and should be treated accordingly.
    // applying rule 22
    lex->ReportRuleUsed("22");
    buildingStatement++;
    code->WriteCode(tabs, "if ");
    stmt(0, "", ret);
    code->WriteCode(0, ":\n");
    buildingStatement--;
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

    code->WriteCode(0, "\n");
    stmt_pair(tabs, ret);
  }

  lex->ReportFunctionExited("Stmt_Pair_Body", token);
  return errors;
}

int SyntacticalAnalyzer::stmt_pair(int tabs, string ret)
{
  //more statement operations. Handles which rule belonging to statement pair should be
  // taken; 20 or 21.
  lex->ReportFunctionEntered("Stmt_Pair", token);

  if (token == LPAREN_T)
  {
    // applying rule 20
    lex->ReportRuleUsed("20");
    token = lex->GetToken();
    code->WriteCode(0, "\n");
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
  // concludes an if statement either with or without an else depending on the rule.
  if (token == RPAREN_T)
  {
    // applying rule 19
    lex->ReportRuleUsed("19");
    lex->ReportFunctionExited("Else_Part", token);
    return errors;
  }
  // applying rule 18
  lex->ReportRuleUsed("18");

  code->WriteCode(tabs, "else:\n");
  tabs++;
  stmt(tabs, "", ret);
  tabs--;
  code->WriteCode(0, "\n");

  lex->ReportFunctionExited("Else_Part", token);
  return errors;
}

int SyntacticalAnalyzer::param_list(int tabs, string ret)
{
  // handles lists of paramaters in the calling or declaration of
  // functions.
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
    code->WriteCode(0, lex->GetLexeme());
    lex->ReportRuleUsed("16");
    token = lex->GetToken();
    if (token != RPAREN_T)
      code->WriteCode(0, ", ");
    param_list(tabs, ret);
  }

  lex->ReportFunctionExited("Param_List", token);
  return errors;
}

int SyntacticalAnalyzer::more_tokens(int tabs, string ret)
{
  //handles the more token rules.
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
  code->WriteCode(0, " ");
  more_tokens(tabs, ret);

  lex->ReportFunctionExited("More_Tokens", token);
  return errors;
}

int SyntacticalAnalyzer::quoted_lit(int tabs, string ret)
{
  //Applies rule 13 and just calls any_other_token
  lex->ReportFunctionEntered("Quoted_Lit", token);
  // applying rule 13
  lex->ReportRuleUsed("13");
  any_other_token(tabs, ret);

  lex->ReportFunctionExited("Quoted_Lit", token);
  return errors;
}

int SyntacticalAnalyzer::literal(int tabs, string ret)
{
  // Handles the literal rule, Non list literals are just written as is.
  lex->ReportFunctionEntered("Literal", token);
  int listFlag = 0;
  if (token == NUMLIT_T)
  {
    // applying rule 10
    if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
    buildingStatement++;
    lex->ReportRuleUsed("10");
    code->WriteCode(tabs, lex->GetLexeme());
    token = lex->GetToken();
    buildingStatement--;
  }
  else if (token == STRLIT_T)
  {
    
    // applying rule 11
    if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
    buildingStatement++;
    lex->ReportRuleUsed("11");
    code->WriteCode(tabs, lex->GetLexeme());
    token = lex->GetToken();
    buildingStatement--;
  }
  else if (token == SQUOTE_T)
  {
    //List literals have special handling, they look different in Python so a [] needs
    // to be written. Also identification needs to be provided for whether a statement is being
    // built.
    // applying rule 12
    if (buildingStatement == 0)
      {
        code->WriteCode(tabs, "returnValue=");
        tabs = 0;
      }
    buildingStatement++;
    lex->ReportRuleUsed("12");
    token = lex->GetToken();
    if (token == LPAREN_T)
    {
      listFlag++;
      code->WriteCode(tabs, "[");
    }
    else
      code->WriteCode(tabs, "");
    quoted_lit(tabs, ret);
    if (listFlag)
      code->WriteCode(0, "]");
    else
      code->WriteCode(0, "");
    buildingStatement--;
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
  // Constructs a statement. Statments include literals, any operation, or logic.
  lex->ReportFunctionEntered("Stmt", token);

  if (token == IDENT_T)
  {
    // applying rule 8
    lex->ReportRuleUsed("8");
    code->WriteCode(tabs, lex->GetLexeme());
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
  // Identifies how many statements there are in a function and handles their construction.
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
  //Handles the definition of a function. It may look complicated, but most of
  // it is either walking over tokens or calling other functions.
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
        code->WriteCode(tabs, "def " + lex->GetLexeme() + "(");
        token = lex->GetToken();
        param_list(tabs, ret);
        if (token == RPAREN_T)
        {
          code->WriteCode(0, "):");
          tabs++;
          token = lex->GetToken();
          code->WriteCode(tabs, "\n");
          // Every function has a return value in Scheme.
          code->WriteCode(tabs, "returnValue = None\n");
          stmt(tabs, "", ret);
          //code -> WriteCode(tabs, "\n");
          stmt_list(tabs, "", ret);
          //code -> WriteCode(tabs, "\n");
          tabs--;
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
  code->WriteCode(tabs + 1, "return returnValue\n");
  lex->ReportFunctionExited("Define", token);
  return errors;
}

int SyntacticalAnalyzer::more_defines(int tabs)
{
  // Determines whether a function is being declared or called and handles the 
  // appropriate rule.
  lex->ReportFunctionEntered("More_Defines", token);

  string ret = "";
  if (token == IDENT_T)
  {
    buildingStatement++;
    // applying rule 3
    lex->ReportRuleUsed("3");
    code->WriteCode(tabs, lex->GetLexeme() + "(");
    token = lex->GetToken();
    stmt_list(tabs, "", ret);
    //code->WriteCode(0, ")");
    stmt_list(tabs, "", ret);
    code->WriteCode(0, ")\n");
    if (token == RPAREN_T)
    {
      token = lex->GetToken();
    }
    else
    {
      lex->ReportError("'RPAREN_T' expected");
      errors++;
    }
    buildingStatement--;
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
  // ensures that there is at least one define in program and calls the functions
  // to handle them.
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
