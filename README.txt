Assignment: CS460 Project 2
Authors: Jimmie Hagle, Catherine Meyer, Justin Bernard

What works:
- Tested many of the P2 Test Files and most seem to parse correctly, use
  the correct rules, and find the correct errors where applicable.


What doesn't work:
- Not all the P2 test files come up 100% correct, two of which are Y4P2.ss
  and T4P2.ss.
  
  For Y4P2.ss, the issues begin when the "and" is read in on line 6.  In the
  Y4P2.p2 file, your program reports entering into Stmt() with "AND_T" and
  then using Rule 9...  This is a bit confusing because...your program appears
  to skip right on by the two LPAREN_T and one RPAREN_T that follow, and go
  straight to evaluating the IDENT_T "main".  Additionally, the .p2 file seems
  to report whitespace as errors as well, which also seems strange.
  
  Ultimately, we made a lot of attempts to match your output with this file but
  just couldn't get there.  We suspect that (if it's not an error with your program,
  or something specific about the project spec that wasn't mentioned we needed to
  handle) the issue has to do with us needing to advance the token by placing
  token=lex->GetToken() somewhere within functions where a token being read
  in doesn't match anything that is expected.  Perhaps with the right combination
  of these statements, we'd find a way to detect the 8 errors and skip straight to
  the "main" as your .p2 file seems to do.


Notes:
- 11/26/2018 (~1pm): Re-submitted project with correct "TeamYP2" naming standard.  Project
  was originally submitted on time as "YP2."  All files in submission are the exact same with
  the exception of a modified makefile (to account for the changed submission name) and the
  addition of this text to the README.
