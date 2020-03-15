#pragma once
#include "Common.h"
class ISource
{
public:
	TupleVec virtual getData() const = 0;
};


