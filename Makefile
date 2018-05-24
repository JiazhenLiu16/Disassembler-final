# A simple makefile

GCC=gcc -Wall -Wextra -Wpedantic -Wformat -Wshadow -Wredundant-decls \
    -Wstrict-prototypes
# Can also use -Wtraditional or -Wmissing-prototypes

#all:	disUtil

#  Switch to the following alternative version of the "all" target
#  when you're ready to program the disassembler project.

 all:	disUtil disassembler

disUtil:	disassembler.h \
    		printFuncs.h \
    		process_arguments.h \
		process_arguments.c \
    		verifyMIPSInstruction.c \
		binToDec.c \
		printDebug.c \
		printError.c \
		disUtilDriver.c
		$(GCC) process_arguments.c verifyMIPSIns truction.c binToDec.c \
		    printDebug.c printError.c disUtilDriver.c -o disUtil

# The assembler will probably have other source files in addition to these.
disassembler:	disassembler.h \
    		printFuncs.h \
    		process_arguments.h \
		process_arguments.c \
    		verifyMIPSInstruction.c \
		binToDec.c \
		getRegName.c \
		printDebug.c \
		printError.c \
		disassembler.c
		$(GCC) process_arguments.c verifyMIPSInstruction.c binToDec.c \
		    getRegName.c \
		    printDebug.c printError.c disassembler.c -o disassembler

alyce:	disUtil alyceMain.c
	$(GCC) process_arguments.c verifyMIPSInstruction.c binToDec.c \
	    printDebug.c printError.c alyceMain.c -o disUtil

clean: 
	rm -rf *.o disUtil disassembler
