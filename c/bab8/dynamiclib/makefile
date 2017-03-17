hfcal.o: hfcal.c hfcal.h
	gcc -fPIC -I. -c hfcal.c -o hfcal.o
libhfcal.so: hfcal.o
	gcc -shared hfcal.o -o libhfcal.so
ellitical: hfcal.o libhfcal.so hfcal.h
	gcc ellitical.c -I. -L. -lhfcal -o ellitical
