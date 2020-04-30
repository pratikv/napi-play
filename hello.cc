#include <string>
#include <napi.h>

Napi::String TestMethod(const Napi::CallbackInfo& info)
{
    auto env = info.Env();
    return Napi::String::New(env, "Returning this string");
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
    exports.Set(
        Napi::String::New(env, "hello"),
        Napi::Function::New(env, TestMethod));

    return exports;
}

NODE_API_MODULE(hello,Init);