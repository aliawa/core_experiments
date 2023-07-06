mygzip: mygzip.c
	gcc -g mygzip.c -o mygzip

pipe_ls_wc: pipe_ls_wc.o
	$(CC) -g -o $@ $^
