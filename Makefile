OUT = out/out
RESOBJ = res/out/resou.obj
RESRC = res/src/resou.rc

rs:
	windres -i $(RESRC) -o res/out/resou.res
	windres -i res/out/resou.res -o res/out/resou.obj

compile:
	g++ -I $(CURDIR) -o $(OUT) $(RESOBJ) start.cpp

run: 
	out/out.exe