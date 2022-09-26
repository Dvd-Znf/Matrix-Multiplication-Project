DESTDIR ?= /usr/bin

mmp: main.cpp
	g++ main.cpp -o mmp


install: mmp
	install mmp $(DESTDIR)/mmp


uninstall: mmp
	rm -v mmp $(DESTDIR)/mmp


clean: 
	rm mmp
