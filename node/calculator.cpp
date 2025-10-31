#include <napi.h>
#include "../include/calculator.h"

// Create a calculator object
Calculator calc;

Napi::Number PerformOperation(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3 || !info[0].IsNumber() || !info[1].IsString() || !info[2].IsNumber()) {
        Napi::TypeError::New(env, "Expected arguments: number, string, number").ThrowAsJavaScriptException();
        return Napi::Number::New(env, 0);
    }

    double a = info[0].As<Napi::Number>().DoubleValue();
    char op = info[1].As<Napi::String>().Utf8Value()[0];
    double b = info[2].As<Napi::Number>().DoubleValue();

    double result = calc.performOperation(op, a, b);
    return Napi::Number::New(env, result);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set("performOperation", Napi::Function::New(env, PerformOperation));
    return exports;
}

NODE_API_MODULE(calculator, Init)
