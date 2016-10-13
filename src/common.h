#ifndef common_h
#define common_h

extern int currentLineNumber;
extern int currentNestingLevel;

enum TokenCode {
	Dummy,
	Word,
	Number,
	Period,
	EndOfFile,
	Error,
};

#endif