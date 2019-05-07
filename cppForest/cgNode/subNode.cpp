//
// Created by a on 2019/5/7.
//

#include "subNode.h"
double subNode::compute(double n1, double n2) {
    return n1 - n2;
}

cgNode *subNode::trim() {
    _left = _left->trim();
    _right = _right->trim();
    if (_right->is_n_node(0)) {
        return change_this(_left);
    }
//    else if (_left->is_identical(_right)){
//        return change_this(new mulNode(_parent, _lr, _left, new constNode(this, true, 2)));
//    }
    return this;
}

cgNode *subNode::diff() {
    _left = _left->diff();
    _right = _right->diff();
    return this;
}

cgNode *subNode::clone(cgNode* parent) {
    cgNode* p = new subNode(parent, _lr, nullptr, nullptr);
    p->_left = _left->clone(p);
    p->_right = _right->clone(p);
    return p;
}

subNode::subNode(cgNode *parent, bool lr, cgNode *left, cgNode *right) : cgNode(parent, lr, left, right, 0) {}