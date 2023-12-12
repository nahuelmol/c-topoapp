OUT = out/out
RESOBJ = res/out/resou.obj
RESRC = res/src/resou.rc
RESRES = res/out/resou.res

db:
	g++ -I $(CURDIR) -o conn connect.cpp -lodbc32

rs:
	windres $(RESRC) -O coff -o $(RESRES)
	#windres res/out/resou.res -O coff -o res/out/resou.obj

compile:
	g++ -I $(CURDIR) -o $(OUT) start.cpp $(RESRES) -mwindows

run: 
	out/out.exe