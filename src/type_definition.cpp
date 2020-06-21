#include "type_definition.h"

TypeDefinition::~TypeDefinition()
{
    switch (how)
    {
    case dcProgram:
    case dcProcedure:
    case dcFunction:

        break;

    default:
        break;
    }
}