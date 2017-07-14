#pragma once

#include <sstream>
#include <nnu.h>

class Serializable {
public:
    template<class T> static void setupMember(v8::Handle<v8::FunctionTemplate>& tpl) {
        Nan::SetPrototypeMethod(tpl, "toBuffer", nnu::wrapFunction<T, Serializable, &Serializable::toBuffer>);
        Nan::SetPrototypeMethod(tpl, "fromBuffer", nnu::wrapFunction<T, Serializable, &Serializable::fromBuffer>);
    }

    virtual NAN_METHOD(toBuffer);
    virtual NAN_METHOD(fromBuffer);

protected:
    virtual void read(std::istream& is) = 0;
    virtual void write(std::ostream& os) = 0;
};