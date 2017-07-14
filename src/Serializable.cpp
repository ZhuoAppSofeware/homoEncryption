#include "Serializable.h"

using namespace std;

NAN_METHOD(Serializable::toBuffer) {
    std::ostringstream oss;
    write(oss);

    const string str = oss.str();
    char *buf = const_cast<char*>(str.c_str());

    info.GetReturnValue().Set(Nan::CopyBuffer(buf, str.size()).ToLocalChecked());
}

NAN_METHOD(Serializable::fromBuffer) {
    const char *data = node::Buffer::Data(info[0]);
    size_t size = node::Buffer::Length(info[0]);

    string str(data, size);
    std::istringstream iss(str);
    read(iss);

    info.GetReturnValue().Set(info.This());
}