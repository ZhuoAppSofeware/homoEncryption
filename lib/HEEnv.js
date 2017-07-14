const { FHEContext, EncryptedArray, FHESecKey, FHEPubKey } = require('../build/Release/node-helib.node');
const HEKey = require('./HEKey');

class HEEnv {
    constructor(m = 7, p = 2147483647, r = 1) {
        const me = this;

        this._context = new FHEContext(m, p, r);
        this._ea = new EncryptedArray(this._context);

        Object.assign(this, {
            get p() { return p; },
            get size() { return me._ea.getSize(); }
        });
    }

    genKey(w = 64) {
        const key = (new FHESecKey(this._context)).genSecKey(w);
        const pubKey = new FHEPubKey(null, key);
        return new HEKey(this._context, this._ea, pubKey, key);
    }

    loadKey(buf) {
        const key = (new FHESecKey(this._context)).fromBuffer(buf);
        const pubKey = new FHEPubKey(null, key);
        return new HEKey(this._context, this._ea, pubKey, key);
    }

    loadPubKey(buf) {
        const pubKey = (new FHEPubKey(this._context)).fromBuffer(buf);
        return new HEKey(this._context, this._ea, pubKey);
    }
}

module.exports = HEEnv;