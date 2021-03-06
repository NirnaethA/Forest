#pragma once
#include "cg.h"
#include <map>

class varNode;
class dcg :
	public cg
{
private:
	std::map<cgNode*, varNode*> dvars;
public:
	dcg(cgNode*, const std::map<cgNode*, varNode*>&);
	virtual ~dcg();

	double single_var(cgNode* node, const std::vector<double>& vallist);
};

