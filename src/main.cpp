#include "CtxtWrap.h"
#include "EncryptedArrayWrap.h"
#include "FHEContextWrap.h"
#include "FHESecKeyWrap.h"

using namespace v8;
using namespace node;

NAN_MODULE_INIT(InitAll) {
    CtxtWrap::setup(target);
    EncryptedArrayWrap::setup(target);
    PlaintextArrayWrap::setup(target);
    FHEContextWrap::setup(target);
    FHEPubKeyWrap::setup(target);
    FHESecKeyWrap::setup(target);
}

NODE_MODULE(node_microbench, InitAll);