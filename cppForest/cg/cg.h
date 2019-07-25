//
// Created by anarion on 7/7/19.
//

#ifndef CPPFOREST_CG_H
#define CPPFOREST_CG_H

#include "../cgNode/cgNode.h"
#include "../cgNode/rootNode.h"

class cg {
    friend class FixedPointRootFinder;
protected:
    cgNode* _root;
public:
    explicit cg(cgNode* root);
    explicit cg(cg* graph);
    virtual ~cg();
    virtual cg* clone();

    virtual void compute();
    cgNode* get_result();
};

#endif //CPPFOREST_CG_H
