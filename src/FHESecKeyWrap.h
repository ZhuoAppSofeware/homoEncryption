#pragma once

#include <nnu.h>
#include <FHE.h>

#include "Serializable.h"

class FHEPubKeyWrap : public nnu::ClassWrap<FHEPubKeyWrap>, public Serializable {
public:
    static const char * const CLASS_NAME;

    void static setupMember(v8::Handle<v8::FunctionTemplate> &tpl);
    static NAN_METHOD(ctor);

public:
    FHEPubKeyWrap(const FHEcontext& context);
    FHEPubKeyWrap(const FHEPubKey& pubKey);

private:
    virtual void read(std::istream& is);
    virtual void write(std::ostream& os);


public:
    FHEPubKey key;
};

class FHESecKeyWrap : public nnu::ClassWrap<FHESecKeyWrap>, public Serializable {
public:
    static const char * const CLASS_NAME;

    void static setupMember(v8::Handle<v8::FunctionTemplate> &tpl);
    static NAN_METHOD(ctor);

public:
    FHESecKeyWrap(const FHEcontext& context);

    NAN_METHOD(genSecKey);

private:
    virtual void read(std::istream& is);
    virtual void write(std::ostream& os);

public:
    FHESecKey key;
};