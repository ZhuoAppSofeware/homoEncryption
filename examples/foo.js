const { HEEnv } = require('../');

const env = new HEEnv();
const key = env.genKey();

const c1 = key.encrypt([1, 2, 3, 4, 5, 6]);
const c2 = key.encrypt([2, 3, 4, 5, 6, 7]);

c1.add(c2);

const c1Buf = c1.toBuffer();
console.log(c1Buf.toString());

console.log(key.decrypt(c1));
console.log(key.decrypt(c1Buf));

c1.sub(c2);
console.log(key.decrypt(c1));

c1.mul(c2);
console.log(key.decrypt(c1));

c1.rotate(2);
console.log(key.decrypt(c1));