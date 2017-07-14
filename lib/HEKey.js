const { FHESecKey, FHEPubKey, Ctxt } = require('../build/Release/node-helib.node');

class HEKey {
    constructor(context, ea, pubkey, key) {
        this._context = context;
        this._ea = ea;
        this._pubKey = pubkey;
        this._key = key;
    }

    encrypt(arr) {
        const ctxt = new Ctxt(this._pubKey);
        this._ea.encrypt(ctxt, this._pubKey, arr);

        return ctxt;
    }

    decrypt(ctxt) {
        if (Buffer.isBuffer(ctxt)) {
            ctxt = (new Ctxt(this._pubKey)).fromBuffer(ctxt);
        }
        
        return this._ea.decrypt(ctxt, this._key);
    }
}

module.exports = HEKey;