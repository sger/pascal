#ifndef ABORT_CODE_H
#define ABORT_CODE_H

enum AbortCode {
    invalidCommandLineArgs = -1,
    sourceFileOpenFailed = -2,
    iFormFileOpenFailed = -3,
    assemplyFileOpenFailed = -4,
    tooManySyntaxErrors = -5,
    stackOverFlow = -6,
    codeSegmentOverflow = -7,
    nestingTooDeep = -8,
    runtimeError = -9,
    unimplementedFeature = -10
};

void abortTranslation(AbortCode abortCode);

#endif
