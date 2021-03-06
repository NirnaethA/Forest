#pragma once

#include "Functor.h"
#include "Diffor.h"
#include "Trimor.h"

class Diffor;
class nullDiffor;
class cgNode
{
	friend class addDiffor;
	friend class subDiffor;
	friend class mulDiffor;
	friend class divDiffor;
	friend class expDiffor;
	friend class lnDiffor;
	friend class Trimor;
	friend class addTrimor;
	friend class subTrimor;
	friend class mulTrimor;
	friend class divTrimor;
	friend class expTrimor;
	friend class lnTrimor;
	friend class cg;
private:
	static cgNode* clone_node(cgNode* node);
protected:
	cgNode* left;
	cgNode* right;
	Functor* func;
	Diffor* diffor;
	Trimor* trimor;
	double val;
public:
	cgNode(cgNode* l, cgNode* r, Functor* f, Diffor* d, Trimor* t, const double& v);
	virtual ~cgNode();


	virtual cgNode* clone();
	static bool is_leaf(cgNode*);
	void set_val(const double& d);
	virtual bool is_const();
};



#include "varNode.h"
#include "constNode.h"
#include "addNode.h"
#include "subNode.h"
#include "mulNode.h"
#include "divNode.h"
#include "expNode.h"
#include "lnNode.h"
#include "nullNode.h"
