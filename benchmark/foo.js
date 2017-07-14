const { HEEnv } = require('../');


suite('all', function () {
    const env = new HEEnv();
    const key = env.genKey();

    bench('key gen', function () { env.genKey() });
    bench('encrypt', function () { key.encrypt([1, 2, 3, 4, 5, 6]); });

    bench('encrypt & decrypt', function () {
         const ctxt = key.encrypt([1, 2, 3, 4, 5, 6]);
         key.decrypt(ctxt);
    });

    bench('encrypt & decrypt buffer', function () {
         const buf = key.encrypt([1, 2, 3, 4, 5, 6]).toBuffer();
         key.decrypt(buf);
    });
});