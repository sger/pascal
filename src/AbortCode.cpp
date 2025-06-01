#include <array>
#include <iostream>

#include "AbortCode.h"

static const std::array<const char*, 11> abortMessage = {nullptr,
                                                         "Invalid command line arguments",
                                                         "Failed to open source file",
                                                         "Failed to open intermediate form file",
                                                         "Failed to open assembly file",
                                                         "Too many syntax errors",
                                                         "Stack overflow",
                                                         "Code segment overflow",
                                                         "Nesting too deep",
                                                         "Runtime error",
                                                         "Unimplemented feature"};

void abortTranslation(AbortCode abortCode)
{
    std::cerr << "*** Fatal translator error: " << abortMessage[-abortCode] << std::endl;

    exit(abortCode);
}