// 

#include <node.h>

namespace demo {

  using v8::Number;
  using v8::Local;
  using v8::FunctionCallbackInfo;
  using v8::Value;

  void Fib(const FunctionCallbackInfo<Value> &args) {
    v8::Isolate *isolate = args.GetIsolate();
    Local<v8::Context> context = isolate->GetCurrentContext();

    uint64_t num = args[0]->IntegerValue(context).ToChecked();
    uint64_t result = 0, a = 1, b = 1;
    if (num <= 2) {
      result = 1;
    } else {
      while (num-- > 2) {
        result = a + b;
        a = b;
        b = result;
      }
    }

    args.GetReturnValue().Set(Number::New(isolate, result));
  }

  void Fib2(const FunctionCallbackInfo<Value> &args) {
    v8::Isolate *isolate = args.GetIsolate();
    Local<v8::Context> context = isolate->GetCurrentContext();

    uint64_t num = args[0]->IntegerValue(context).ToChecked();
    uint64_t result = 0, a = 1, b = 1;
    if (num <= 2) {
      result = 1;
    } else {
      num -= 2;
      while (num-- > 0) {
        result = a + b;
        a = b;
        b = result;
      }
    }

    args.GetReturnValue().Set(Number::New(isolate, result));
  }

  void Init(Local<v8::Object> exports, Local<v8::Object> module) {
    NODE_SET_METHOD(exports, "fib", Fib);
    NODE_SET_METHOD(exports, "fib2", Fib2);
  }

  // 这里的 NODE_GYP_MODULE_NAME 宏就是 前面 binding.gyp 的指定的 target_name
  NODE_MODULE(NODE_GYP_MODULE_NAME, Init)

} // namespace demo