// 

#include <node.h>

namespace demo {

  using v8::Number;
  using v8::Local;
  using v8::FunctionCallbackInfo;
  using v8::Value;

  void Add(const FunctionCallbackInfo<Value> &args) {
    v8::Isolate *isolate = args.GetIsolate();
    Local<v8::Context> context = isolate->GetCurrentContext();

    Local<Number> a = (args[0]->ToNumber(context)).ToLocalChecked();
    Local<Number> b = (args[1]->ToNumber(context)).ToLocalChecked();
    args.GetReturnValue().Set(a->Value() + b->Value());
  }

  void Sum(const FunctionCallbackInfo<Value> &args) {
    v8::Isolate *isolate = args.GetIsolate();
    Local<v8::Context> context = isolate->GetCurrentContext();

    double sum = 0;
    for (int i = 0;i < args.Length();i++) {
      sum += (args[i]->ToNumber(context)).ToLocalChecked()->Value();
    }
    args.GetReturnValue().Set(sum);
  }

  void Init(v8::Local<v8::Object> exports) {
    NODE_SET_METHOD(exports, "add", Add);
    NODE_SET_METHOD(exports, "sum", Sum);
  }

  // 这里的 NODE_GYP_MODULE_NAME 宏就是 前面 binding.gyp 的指定的 target_name
  NODE_MODULE(NODE_GYP_MODULE_NAME, Init)

} // namespace demo