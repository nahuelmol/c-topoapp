OUT = out/out
OUTTEST = 'tests/out/out'
RESOBJ = res/out/resou.obj
RESRC = res/src/resou.rc
RESRES = res/out/resou.res

IPG = -I D:/Postgres10.23/include
LPG = -L D:/Postgres10.23/lib
LIBS = -lpq

db:
	g++ -I $(CURDIR) -o conn connect.cpp -lodbc32

rs:
	windres $(RESRC) -O coff -o $(RESRES)
	#windres res/out/resou.res -O coff -o res/out/resou.obj

compile:
	g++ $(IPG) $(LPG) -I $(CURDIR) -o $(OUT) start.cpp $(RESRES) -mwindows $(LIBS)

run: 
	out/out.exe

test:
	g++  -I $(CURDIR) -o $(OUTTEST) tests/test.cpp

runtest:
	tests/out/out.exe


ctest:
	g++ -I $(CURDIR) -o $(OUTTEST) tests/ctest.cpp

runctest:
	tests/out/out.exe

dbtest:
	g++ $(IPG) $(LPG) -I $(CURDIR) -o $(OUTTEST) tests/dbtest.cpp -lpq

dbrun:
	tests/out/out.exe
