#pragma once
#include"Common.h"
#include "ISource.h"

class Source : public ISource
{
private:
	TupleVec tupV;

public:
	//hardcode the values...
	Source();
	
	TupleVec getData() const override;

};

