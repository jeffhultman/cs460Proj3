Assignment: CS460 Project 2
Authors: Boaz Cogan, Jimmie Hagle, Jeff Hultman

What works:
- Tested many of the P3 files as well as hw5. The list operations and return values are almost
identicle to the scheme values with differences on how python and scheme handle assignment of builtin
functions. Indentation and newlines are placed in the appropriate locations and hw5 was able to be run in python once
the squareRoot function was removed (since we couldnt handle the round that was used.) 


What doesn't work:
- Some issues with the Lexical analyzer led to some function calls at the end of the file simply not being
identified.
- Python and scheme have different return values from print statements which can result in different outputs.
- Python and scheme behave differently in strange cases, like isolated ifs and conditionals in which case we simply
opted for the simpler solution of just making else ifs and else statements attached to an if.
- scheme allows for standalone else statements which we converted to an impossible if followed by an else, this may not be accurate.
- there is an extra comma on lists declaration inside of a list. The code '('list? number? +) will force this issue. 


Notes:
- We have submitted the assignment with what we remember it should be called, however internal storage on people isnt as reliable as
external drives so it may be misnamed.
- This was a really fun project that really strengthened our knowledge of scheme. 
- Boaz: I 100% would not recommend that a group do this project in python. It adds a level of complexity to the project (needing to keep
careful track of spacing) that can easily go awry. Thankfully the group adhered to an agreed upon standard but if they hadnt then it would be near
impossible to find an erroneous space. This is especially true given how large the final file became.
