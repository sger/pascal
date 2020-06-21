#ifndef errors_h
#define errors_h

extern int errorCount;
extern int errorArrowFlag;
extern int errorArrowOffset;

enum AbortCode
{
    invalidCommandLineArgs = -1,
    sourceFileOpenFailed = -2,
    iFormFileOpenFailed = -3,
    assemblyFileOpenFailed = -4,
    tooManySyntaxErrors = -5,
    stackOverflow = -6,
    codeSegmentOverflow = -7,
    nestingTooDeep = -8,
    runtimeerroror = -9,
    unimplementedFeature = -10,
};

void abort(AbortCode abortCode);

enum ErrorCode
{
    errorNone,
    errorUnrecognizable,
    errorTooMany,
    errorUnexpectedEndOfFile,
    errorInvalidNumber,
    errorInvalidFraction,
    errorInvalidExponent,
    errorTooManyDigits,
    errorRealOutOfRange,
    errorIntegerOutOfRange,
    errorMissingRightParen,
    errorInvalidExpression,
    errorInvalidAssignment,
    errorMissingIdentifier,
    errorMissingColonEqual,
    errorUndefinedIdentifier,
    errorStackOverflow,
    errorInvalidStatement,
    errorUnexpectedToken,
    errorMissingSemicolon,
    errorMissingComma,
    errorMissingDO,
    errorMissingUNTIL,
    errorMissingTHEN,
    errorInvalidFORControl,
    errorMissingOF,
    errorInvalidConstant,
    errorMissingConstant,
    errorMissingColon,
    errorMissingEND,
    errorMissingTOorDOWNTO,
    errorRedefinedIdentifier,
    errorMissingEqual,
    errorInvalidType,
    errorNotATypeIdentifier,
    errorInvalidSubrangeType,
    errorNotAConstantIdentifier,
    errorMissingDotDot,
    errorIncompatibleTypes,
    errorInvalidTarget,
    errorInvalidIdentifierUsage,
    errorIncompatibleAssignment,
    errorMinGtMax,
    errorMissingLeftBracket,
    errorMissingRightBracket,
    errorInvalidIndexType,
    errorMissingBEGIN,
    errorMissingPeriod,
    errorTooManySubscripts,
    errorInvalidField,
    errorNestingTooDeep,
    errorMissingPROGRAM,
    errorAlreadyForwarded,
    errorWrongNumberOfParms,
    errorInvalidVarParm,
    errorNotARecordVariable,
    errorMissingVariable,
    errorCodeSegmentOverflow,
    errorUnimplementedFeature,
};

void displayError(ErrorCode errorCode);

#endif