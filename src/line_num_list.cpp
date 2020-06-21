#include "line_num_list.h"

#include "list_buffer.h"

LineNumList::~LineNumList()
{
	while (head)
	{
		LineNumNode *pNode = head;
		head = head->next;
		delete pNode;
	}
}

void LineNumList::update()
{
	if (tail && (tail->number == currentLineNumber))
	{
		return;
	}

	tail->next = new LineNumNode;
	tail = tail->next;
}

void LineNumList::print(int newLineFlag, int indent) const
{
	const int maxLineNumberPrintWidth = 4;
	const int maxLineNumbersPerLine = 10;

	int n;
	LineNumNode *pNode;
	char *plt = &list.text[strlen(list.text)];

	n = newLineFlag ? 0 : maxLineNumbersPerLine;

	for (pNode = head; pNode; pNode = pNode->next)
	{
		if (n == 0)
		{
			list.putLine();
			sprintf(list.text, "%*s", indent, " ");
			plt = &list.text[indent];
			n = maxLineNumbersPerLine;
		}

		sprintf(plt, "%*d", maxLineNumberPrintWidth, pNode->number);
		plt += maxLineNumberPrintWidth;
		--n;
	}
	list.putLine();
}