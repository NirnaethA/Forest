#pragma once
#include "Trimor.h"
struct expTrimor :
	public Trimor
{
public:
	expTrimor(cgNode* pp);
	~expTrimor();

	Trimor* clone(cgNode* pp);
	cgNode* run();
};

