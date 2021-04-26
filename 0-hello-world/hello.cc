#include <node.h>

namespace demo {

  void Method(const v8::FunctionCallbackInfo<v8::Value> &args) {
    v8::Isolate *isolate = args.GetIsolate();
    args.GetReturnValue().Set(
      v8::String::NewFromUtf8(
        isolate, "Hello World", v8::NewStringType::kNormal
      ).ToLocalChecked()
    );
  }

  void Init(v8::Local<v8::Object> exports) {
    NODE_SET_METHOD(exports, "hello", Method);
  }

  // 这里的 NODE_GYP_MODULE_NAME 宏就是 前面 binding.gyp 的指定的 target_name
  NODE_MODULE(NODE_GYP_MODULE_NAME, Init)

} // namespace demo