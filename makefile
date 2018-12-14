P2.out : Project2.o SetLimits.o LexicalAnalyzer.o SyntacticalAnalyzer.o CodeGenerator.o
	g++ -g -o P2.out Project2.o SetLimits.o LexicalAnalyzer.o SyntacticalAnalyzer.o CodeGenerator.o

Project2.o : Project2.cpp SetLimits.h SyntacticalAnalyzer.h
	g++ -g -c Project2.cpp

SetLimits.o : SetLimits.cpp SetLimits.h
	g++ -g -c SetLimits.cpp

LexicalAnalyzer.o : LexicalAnalyzer.cpp LexicalAnalyzer.h
	g++ -g -c LexicalAnalyzer.cpp

SyntacticalAnalyzer.o : SyntacticalAnalyzer.cpp SyntacticalAnalyzer.h LexicalAnalyzer.h
	g++ -g -c SyntacticalAnalyzer.cpp

CodeGenerator.o : CodeGenerator.cpp CodeGenerator.h LexicalAnalyzer.h
	g++ -g -c CodeGenerator.cpp

run:
	cat P3T5.ss
	./P2.out P3T5.ss
	cat P3T5.py
run1:
	cat P3T6.ss
	./P2.out P3T6.ss
	cat P3T6.py

test:
	cat P3T3-1.ss
	./P2.out P3T3-1.ss
	cat P3T3-1.py

clean : 
	rm -f *.o P2.out *.gch *~ *.p2 *.lst *.dbg rm P3T*.py

submit : Project2.cpp LexicalAnalyzer.h LexicalAnalyzer.cpp SyntacticalAnalyzer.h SyntacticalAnalyzer.cpp CodeGenerator.cpp CodeGenerator.h objectFunctionality.py makefile README.txt
	rm -rf P3T3py
	mkdir P3T3py
	cp CodeGenerator.cpp P3T3py
	cp CodeGenerator.h P3T3py
	cp objectFunctionality.py P3T3py
	cp Project2.cpp P3T3py
	cp LexicalAnalyzer.h P3T3py
	cp LexicalAnalyzer.cpp P3T3py
	cp SyntacticalAnalyzer.h P3T3py
	cp SyntacticalAnalyzer.cpp P3T3py
	cp makefile P3T3py
	cp README.txt P3T3py
	tar cfvz P3T3py.tgz P3T3py
	cp P3T3py.tgz ~tiawatts/cs460drop
