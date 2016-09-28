#ifndef errors_h
#define errors_h

enum ErrorCode {
	invalidCommandLineArgs = -1,
};

void abort(ErrorCode errorCode);

#endif