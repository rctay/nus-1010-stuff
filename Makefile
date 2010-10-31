CC=gcc
CFLAGS=-Wall
EXE=.exe
SOURCE=nemo.c

TEST_EXPECTED=exp
TEST_ACTUAL=actual
TEST_INPUT=input
TEST_CMP=diff

all: test

a.exe: $(SOURCE)
	$(CC) $(CFLAGS) $(SOURCE)

$(TEST_ACTUAL): a$(EXE) $(TEST_INPUT)
	@echo "Collecting output..."
	cat $(TEST_INPUT) \
	| ./a.exe 2>&1 \
	| tr -d "\r" \
	> $(TEST_ACTUAL)

test: a$(EXE) $(TEST_ACTUAL) $(TEST_INPUT) $(TEST_EXPECTED)
	@echo "Comparing..."
	@$(TEST_CMP) -u $(TEST_ACTUAL) $(TEST_EXPECTED) \
		&& echo "pass!"
