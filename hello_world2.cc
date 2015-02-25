#include "include/v8.h"
#include "include/libplatform/libplatform.h"

using namespace v8;

int main ( int argc, char *argv[] ) {
  V8::InitializeICU();
  Platform *platform = platform::CreateDefaultPlatform();
  V8::InitializePlatform(platform);
  V8::Initialize();

  Isolate *isolate = Isolate::New();
  {
    Isolate::Scope isolate_scope(isolate);
    HandleScope handle_scope(isolate);

    Local<Context> context = Context::New(isolate);
    Context::Scope context_scope(context);

    Local<String> source = String::NewFromUtf8(isolate, "1 + 2");
    Local<Script> script = Script::Compile(source);
    Local<Value> result = script->Run();

    String::Utf8Value utf8(result);
    printf("%s\n", *utf8);
  }

  isolate->Dispose();
  V8::Dispose();
  V8::ShutdownPlatform();
  delete platform;
  return 0;
}
