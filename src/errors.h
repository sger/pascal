#ifndef errors_h
#define errors_h

extern int errorCount;

enum ErrorCode {
	invalidCommandLineArgs = -1,
	sourceFileOpenFailed = -2,
};

void abort(ErrorCode errorCode);

#endif