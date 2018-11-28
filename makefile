P2.out : Project2.o SetLimits.o LexicalAnalyzer.o SyntacticalAnalyzer.o
	g++ -g -o P2.out Project2.o SetLimits.o LexicalAnalyzer.o SyntacticalAnalyzer.o

Project2.o : Project2.cpp SetLimits.h SyntacticalAnalyzer.h
	g++ -g -c Project2.cpp

SetLimits.o : SetLimits.cpp SetLimits.h
	g++ -g -c SetLimits.cpp

LexicalAnalyzer.o : LexicalAnalyzer.cpp LexicalAnalyzer.h
	g++ -g -c LexicalAnalyzer.cpp

SyntacticalAnalyzer.o : SyntacticalAnalyzer.cpp SyntacticalAnalyzer.h LexicalAnalyzer.h
	g++ -g -c SyntacticalAnalyzer.cpp

clean : 
	rm *.o P2.out *.gch *~ *.p2 *.lst *.dbg

submit : Project2.cpp LexicalAnalyzer.h LexicalAnalyzer.cpp SyntacticalAnalyzer.h SyntacticalAnalyzer.cpp makefile README.txt
	rm -rf TeamYP2
	mkdir TeamYP2
	cp Project2.cpp TeamYP2
	cp LexicalAnalyzer.h TeamYP2
	cp LexicalAnalyzer.cpp TeamYP2
	cp SyntacticalAnalyzer.h TeamYP2
	cp SyntacticalAnalyzer.cpp TeamYP2
	cp makefile TeamYP2
	cp README.txt TeamYP2
	tar cfvz TeamYP2.tgz TeamYP2
	cp TeamYP2.tgz ~tiawatts/cs460drop
