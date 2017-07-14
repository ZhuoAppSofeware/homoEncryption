#pragma once

#include <nnu.h>
#include <FHEContext.h>

#include "Serializable.h"

class FHEContextWrap : public nnu::ClassWrap<FHEContextWrap>, public Serializable {
public:
    static const char * const CLASS_NAME;

    void static setupMember(v8::Handle<v8::FunctionTemplate> &tpl);
    static NAN_METHOD(ctor);

public:
    FHEContextWrap(
        unsigned long m, unsigned long p, unsigned long r,
        const vector<long>& gens = vector<long>(), 
        const vector<long>& ords = vector<long>()
    );

private:
    virtual void read(std::istream& is);
    virtual void write(std::ostream& os);

public:
    FHEcontext context;
};