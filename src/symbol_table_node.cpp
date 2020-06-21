#include "symbol_table_node.h"

#include <stdio.h>
#include <string.h>

#include "list_buffer.h"
#include "common.h"
#include "types.h"

SymbolTableNode::SymbolTableNode(const char *pStr, TypeDefCode dc) : defn(dc)
{
	leftNode = NULL;
	rightNode = NULL;
	next = NULL;
	nodeIndex = 0;
	level = currentNestingLevel;
	labelIndex = ++asmLabelIndex;

	pSymbolString = new char[strlen(pStr) + 1];
	strcpy(pSymbolString, pStr);

	if (xrefFlag)
	{
		pLineNumList = new LineNumList;
	}
}

SymbolTableNode::~SymbolTableNode()
{
	void removeType(Type * &pType);

	delete leftNode;
	delete rightNode;

	delete[] pSymbolString;
	delete pLineNumList;

	removeType(pType);
}

void SymbolTableNode::print() const
{
	const int maxNamePrintWidth = 16;

	if (leftNode)
	{
		leftNode->print();
	}

	sprintf(list.text, "%*s", maxNamePrintWidth, pSymbolString);

	if (pLineNumList)
	{
		pLineNumList->print(strlen(pSymbolString) > maxNamePrintWidth, maxNamePrintWidth);
	}
	else
	{
		list.putLine();
	}

	printIdentifier();

	if (rightNode)
	{
		rightNode->print();
	}
}

void SymbolTableNode::convert(SymbolTableNode *vpNodes[])
{
	if (leftNode)
	{
		leftNode->convert(vpNodes);
	}

	vpNodes[nodeIndex] = this;

	if (rightNode)
	{
		rightNode->convert(vpNodes);
	}
}

void SymbolTableNode::printIdentifier() const
{
	switch (defn.how)
	{
	case dcConstant:
		printConstant();
		break;
	case dcType:
		printType();
		break;
	case dcVariable:
	case dcField:
		printVarOrField();
		break;

	default:
		break;
	}
}
void SymbolTableNode::printConstant() const
{
	extern ListBuffer list;
	list.putLine();
	list.putLine("Defined constant");

	if ((pType == pIntegerType) || (pType->form == fcEnum))
	{
		sprintf(list.text, "Value = %d", defn.constant.value.integer);
	}
	else if (pType == pRealType)
	{
		sprintf(list.text, "Value = %g", defn.constant.value.real);
	}
	else if (pType == pCharType)
	{
		sprintf(list.text, "Value = %c", defn.constant.value.character);
	}
	else if (pType->form == fcArray)
	{
		sprintf(list.text, "Value = '%s'", defn.constant.value.pString);
	}
	list.putLine();

	if (pType)
	{
		pType->printTypeSpec(Type::vcTerse);
	}

	list.putLine();
}

void SymbolTableNode::printVarOrField() const
{
	extern ListBuffer list;
	list.putLine();
	list.putLine(defn.how == dcVariable ? "Declared variable" : "Declared record field");

	if (pType)
	{
		pType->printTypeSpec(Type::vcTerse);
	}

	if ((defn.how == dcVariable) || (this->next))
	{
		list.putLine();
	}
}

void SymbolTableNode::printType() const
{
	list.putLine();
	list.putLine("Defined type");

	if (pType)
	{
		pType->printTypeSpec(Type::vcVerbose);
	}
	list.putLine();
}
