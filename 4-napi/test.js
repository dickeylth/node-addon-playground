const { sayHello } = require('node-gyp-build')(__dirname);
// require('./build/Release/exposeFunction');
const result = sayHello("Conan");
console.log(result);