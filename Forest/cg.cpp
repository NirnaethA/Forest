#include "cg.h"



void cg::del_node(cgNode* node)
{
	if (!node)	return;
	if (node->left)	del_node(node->left);
	if (node->right)	del_node(node->right);
	delete node;
}

void cg::diff_node(cgNode*& node)
{
	if (!node)	return;
	node = node->diffor->run();
}

void cg::find_var_node(cgNode* node, std::vector<cgNode*>& qq)
{
	if (!node)	return;
	if (cgNode::is_leaf(node)) {
		if (!node->is_const()) {
			qq.push_back(node);
		}
		return;
	}
	find_var_node(node->right, qq);
	find_var_node(node->left, qq);
}

void cg::trim_node(cgNode*& node)
{
	node = node->trimor->run();
}

double cg::compute(cgNode* node)
{
	if (!node)	return 0.0;
	if (cgNode::is_leaf(node))	return node->val;
	if (node->right)	node->val = node->func->operator()(compute(node->left), compute(node->right));
	return node->val;
}

bool cg::is_var(cgNode* node)
{
	for (size_t i = 0; i < varq.size(); ++i) {
		if (varq[i] == node)	return true;
	}
	return false;
}


void cg::find_vars()
{
	find_var_node(root, varq);
}

void cg::refresh_var(cgNode* node)
{
	if (!node)	return;
	if (cgNode::is_leaf(node)) {
		if (!node->is_const()) {
			if (!is_var(node)) {
				varq.push_back(node);
			}
		}
	}
	refresh_var(node->left);
	refresh_var(node->right);
}

cg::cg(cgNode* r) : root(r)
{
	trim_node(root);
	refresh_var(root);
}


cg::~cg()
{
	del_node(root);
// 	delete var_id;
}

cg* cg::clone()
{
	return new cg(root->clone());
}

void cg::diff(){
	Diffor::clear_delq();
	if (!root)	return;
	root = root->diffor->run();
	Diffor::clear_delq();
}

double cg::run(const std::vector<double>& vallist)
{
	if (vallist.empty()) {
		return compute(root);
	}
	if (vallist.size() != varq.size())	throw "Input independent variable values error, inconsistence.";
	for (size_t i = 0; i < varq.size(); ++i) {
		varq[i]->val = vallist[i];
	}
	return compute(root);
}

dcg* cg::diff_graph()
{
	varDiffor::clear_map();
	cgNode* r = root->clone();
	r = r->diffor->run();
	//auto m = varDiffor::get_map();
	dcg* res = new dcg(r, varDiffor::get_map());
	varDiffor::clear_map();
	return res;
}