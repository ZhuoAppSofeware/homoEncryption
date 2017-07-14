#include "FHEContextWrap.h"

using namespace v8;

const char * const FHEContextWrap::CLASS_NAME = "FHEContext";

void FHEContextWrap::setupMember(v8::Handle<v8::FunctionTemplate> &tpl) {
    Serializable::setupMember<FHEContextWrap>(tpl);
}

NAN_METHOD(FHEContextWrap::ctor) {
    unsigned long m = info[0]->Uint32Value();
    unsigned long p = info[1]->Uint32Value();
    unsigned long r = info[2]->Uint32Value();

    vector<long> gens, ords;

    Local<Array> gensArr = Local<Array>::Cast(info[3]);
    for (uint32_t i = 0; i < gensArr->Length(); i++) {
        gens.push_back(gensArr->Get(i)->Int32Value());
    }

    Local<Array> ordsArr = Local<Array>::Cast(info[4]);
    for (uint32_t i = 0; i < ordsArr->Length(); i++) {
        gens.push_back(ordsArr->Get(i)->Int32Value());
    }

    FHEContextWrap* paw = new FHEContextWrap(m, p, r, gens, ords);
    paw->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
}

FHEContextWrap::FHEContextWrap(unsigned long m, unsigned long p, unsigned long r, const vector<long>& gens, const vector<long>& ords)
: context(m, p, r, gens, ords) {
    buildModChain(context, 5, 2);
}

void FHEContextWrap::read(std::istream& is) {
    is >> context;
}


void FHEContextWrap::write(std::ostream& os) {
    os << context;
}