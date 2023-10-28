
CC = clang
CFLAGS = -Wall -Werror -g -fsanitize=address,undefined

.PHONY: all
all: runAdjList runAdjMatrix runArrayOfEdges

runAdjList: runGraph.c Adj_List临接表.c
	$(CC) $(CFLAGS) -o runAdjList runGraph.c Adj_List临接表.c

runAdjMatrix: runGraph.c Adj_Matrix临接矩阵.c
	$(CC) $(CFLAGS) -o runAdjMatrix runGraph.c Adj_Matrix临接矩阵.c

runArrayOfEdges: runGraph.c ArrayOfEdges.c
	$(CC) $(CFLAGS) -o runArrayOfEdges runGraph.c ArrayOfEdges.c

.PHONY: clean
clean:
	rm -f runAdjList runAdjMatrix runArrayOfEdges
