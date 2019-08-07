LD := ld
CC := gcc
AR := ar
STRIP := strip

CFLAGS   += -I. -I./include -I./src 
LDFLAGS  += -fPIC -L./libs -pthread -lm 


TOOL_SRC := $(shell find . -name "*.c")
TOOL_OBJ := $(patsubst %.c, %.o, ${TOOL_SRC})

#SRC_LIB := $(shell find $(LIB_DIR) -name "*.a")

all:test_stack_balance test_stack_sort test_stack_post test_list_reverse test_maxDepth test_kmax test_dis test_anc

#test_tool:$(TOOL_OBJ) 
#	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
#	$(STRIP) -S $@


test_stack_balance:stack_balance.o stackar.o
	 $(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)


test_stack_sort:stack_sort.o stackar.o
	 $(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

test_stack_post:stack_postFix.o stackar.o
	 $(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

test_list_reverse: list_reverse.o list.o
	 $(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) 

test_list_depu: list_depu.o list.o
	 $(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

test_maxDepth: tree_maxDepth.o tree.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

test_kmax: tree_kmax.o tree.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

test_dis: tree_dis.o tree.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

test_anc: tree_anc.o tree.o
	 $(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -rf $(TOOL_OBJ) test_tool test_stack_balance test_stack_sort test_stack_post test_list_reverse test_maxDepth test_kmax test_dis test_anc test_list_depu

.PHONY:all clean
