#pragma once

#include <nnu.h>
#include <Ctxt.h>

#include "Serializable.h"

class CtxtWrap : public nnu::ClassWrap<CtxtWrap>, public Serializable {
public:
    static const char * const CLASS_NAME;

    void static setupMember(v8::Handle<v8::FunctionTemplate> &tpl);
    static NAN_METHOD(ctor);

public:
    CtxtWrap(const FHEPubKey& pubKey);

    NAN_METHOD(add);
    NAN_METHOD(sub);
    NAN_METHOD(mul);
    NAN_METHOD(rotate);

private:
    virtual void read(std::istream& is);
    virtual void write(std::ostream& os);

public:
    Ctxt ctxt;
};