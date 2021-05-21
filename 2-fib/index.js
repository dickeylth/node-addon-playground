const { fib: fibAddon, fib2: fibAddon2  } = require('./build/Release/fib.node');
function fib(num) {
  if (num <= 2) {
    return 1;
  } else {
    let result, a = 1, b = 1;
    while (num-- > 2) {
      result = a + b;
      a = b;
      b = result;
    }
    return result;
  }
}

const loopCall = (num, callFn) => {
  while (--num > 2) {
    callFn(num);
  }
}


const t4 = process.hrtime.bigint();
loopCall(64, fibAddon2);
const t5 = process.hrtime.bigint();
loopCall(64, fib);
console.log(`fibAll: ${t5 - t4}ns, jsAll: ${process.hrtime.bigint() - t5}ns`);


const t1 = process.hrtime.bigint();
console.log(fibAddon(64));
const t2 = process.hrtime.bigint();
console.log(fibAddon2(64));
const t3 = process.hrtime.bigint();
console.log(fib(64));
console.log(`fib: ${t2 - t1}ns, fib2: ${t3 - t2}ns, js: ${process.hrtime.bigint() - t3}ns`);
