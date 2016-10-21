#ifndef errors_h
#define errors_h

extern int errorCount;

enum AbortCode {
	invalidCommandLineArgs = -1,
	sourceFileOpenFailed = -2,
	iFormFileOpenFailed = -3,
	assemblyFileOpenFailed = -4,
	tooManySyntaxErrors = -5,
	stackOverflow = -6,
	codeSegmentOverflow = -7,
	nestingTooDeep = -8,
	runtimeError = -9,
	unimplementedFeature = -10,
};

void abort(AbortCode errorCode);

enum ErrorCode {
	errorNone,
	errorUnexpectedEndOfFile,
	errorUnrecognizable
};

void displayError(ErrorCode errorCode);

#endif