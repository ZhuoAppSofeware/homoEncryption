#include "FHEContextWrap.h"

#include "CtxtWrap.h"
#include "FHESecKeyWrap.h"

#include "EncryptedArrayWrap.h"

using namespace v8;

const char * const EncryptedArrayWrap::CLASS_NAME = "EncryptedArray";

void EncryptedArrayWrap::setupMember(v8::Handle<v8::FunctionTemplate> &tpl) {
    Nan::SetPrototypeMethod(tpl, "getSize", wrapFunction<&EncryptedArrayWrap::size>);
    Nan::SetPrototypeMethod(tpl, "encrypt", wrapFunction<&EncryptedArrayWrap::encrypt>);
    Nan::SetPrototypeMethod(tpl, "decrypt", wrapFunction<&EncryptedArrayWrap::decrypt>);
}

NAN_METHOD(EncryptedArrayWrap::ctor) {
    FHEContextWrap *cw = Nan::ObjectWrap::Unwrap<FHEContextWrap>(info[0]->ToObject());

    EncryptedArrayWrap* eaw = new EncryptedArrayWrap(cw->context);
    eaw->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
}

EncryptedArrayWrap::EncryptedArrayWrap(const FHEcontext& context)
: ea(context) {

}

NAN_METHOD(EncryptedArrayWrap::size) {
    info.GetReturnValue().Set(Nan::New(static_cast<int>(ea.size())));
}

NAN_METHOD(EncryptedArrayWrap::encrypt) {
    CtxtWrap *ctxt = Nan::ObjectWrap::Unwrap<CtxtWrap>(info[0]->ToObject());
    FHEPubKeyWrap *pubkey = Nan::ObjectWrap::Unwrap<FHEPubKeyWrap>(info[1]->ToObject());

    Local<Array> arr = Local<Array>::Cast(info[2]->ToObject());
    vector<long> vec;
    vec.reserve(arr->Length());
    for (int i = 0; i < arr->Length(); i++) {
        vec.push_back(arr->Get(i)->Int32Value());
    }

    ea.encrypt(ctxt->ctxt, pubkey->key, vec);

    info.GetReturnValue().Set(info.This());
}

NAN_METHOD(EncryptedArrayWrap::decrypt) {
    CtxtWrap *ctxt = Nan::ObjectWrap::Unwrap<CtxtWrap>(info[0]->ToObject());
    FHESecKeyWrap *key = Nan::ObjectWrap::Unwrap<FHESecKeyWrap>(info[1]->ToObject());

    vector<long> vec;
    vec.reserve(ea.size());
    ea.decrypt(ctxt->ctxt, key->key, vec);

    Local<Array> arr = Nan::New<Array>(ea.size());
    for (int i = 0; i < vec.size(); i++) {
        arr->Set(i, Nan::New(static_cast<int>(vec[i])));
    }

    info.GetReturnValue().Set(arr);
}

const char * const PlaintextArrayWrap::CLASS_NAME = "PlaintextArray";

void PlaintextArrayWrap::setupMember(v8::Handle<v8::FunctionTemplate> &tpl) {
    Serializable::setupMember<PlaintextArrayWrap>(tpl);

    Nan::SetPrototypeMethod(tpl, "random", wrapFunction<&PlaintextArrayWrap::random>);
}

NAN_METHOD(PlaintextArrayWrap::ctor) {
    EncryptedArrayWrap *eaw = Nan::ObjectWrap::Unwrap<EncryptedArrayWrap>(info[0]->ToObject());

    PlaintextArrayWrap* paw = new PlaintextArrayWrap(eaw->ea);
    paw->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
}

PlaintextArrayWrap::PlaintextArrayWrap(const EncryptedArray& ea)
: pa(ea), _ea(ea) {

}

NAN_METHOD(PlaintextArrayWrap::random) {
    ::random(_ea, pa);
    info.GetReturnValue().Set(info.This());
}

void PlaintextArrayWrap::read(std::istream& is) {
    // is >> pa;
}

void PlaintextArrayWrap::write(std::ostream& os) {
    os << pa;
}