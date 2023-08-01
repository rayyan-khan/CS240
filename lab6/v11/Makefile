querypatient: main.o agematch.o readpatientrec.o purduematch.o minmaxagematch.o
	gcc -o querypatient main.o agematch.o readpatientrec.o purduematch.o minmaxagematch.o
main.o: main.c header.h
	gcc -c main.c header.h
agematch.o: agematch.c header.h 
	gcc -c agematch.c header.h
readpatientrec.o: readpatientrec.c header.h 
	gcc -c readpatientrec.c header.h
purduematch.o: purduematch.c header.h
	gcc -c purduematch.c header.h
minmaxagematch.o: minmaxagematch.c header.h
	gcc -c minmaxagematch.c header.h