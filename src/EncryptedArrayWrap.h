#pragma once

#include <nnu.h>
#include <EncryptedArray.h>

#include "Serializable.h"

class EncryptedArrayWrap : public nnu::ClassWrap<EncryptedArrayWrap> {
public:
    static const char * const CLASS_NAME;

    void static setupMember(v8::Handle<v8::FunctionTemplate> &tpl);
    static NAN_METHOD(ctor);

public:
    EncryptedArrayWrap(const FHEcontext& context);

    NAN_METHOD(size);
    NAN_METHOD(encrypt);
    NAN_METHOD(decrypt);

public:
    EncryptedArray ea;
};

class PlaintextArrayWrap : public nnu::ClassWrap<PlaintextArrayWrap>, public Serializable {
public:
    static const char * const CLASS_NAME;

    void static setupMember(v8::Handle<v8::FunctionTemplate> &tpl);
    static NAN_METHOD(ctor);

public:
    PlaintextArrayWrap(const EncryptedArray& ea);

    NAN_METHOD(random);

public:
    NewPlaintextArray pa;

private:
    virtual void read(std::istream& is);
    virtual void write(std::ostream& os);

private:
    const EncryptedArray& _ea;
};