#include "include/v8.h"
#include "include/libplatform/libplatform.h"

using namespace v8;

int main ( int argc, char *argv[] ) {
  // Initialize V8
  V8::InitializeICU();
  Platform *platform = platform::CreateDefaultPlatform();
  V8::InitializePlatform(platform);
  V8::Initialize();

  // Create a new Isolate and make it the current one.
  Isolate *isolate = Isolate::New();
  {
    Isolate::Scope isolate_scope(isolate);

    // Create a stack-allocated handle scope
    HandleScope handle_scope(isolate);

    // Create a new context
    Local<Context> context = Context::New(isolate);

    // Enter the context for compiling and running the 'hello_world' script.
    Context::Scope context_scope(context);

    // Create a String containing the Javascript source code.
    Local<String> source = String::NewFromUtf8(isolate, "'Hello' + ' World!'");

    // Compile the source code.
    Local<Script> script = Script::Compile(source);

    // Run the script to get the result.
    Local<Value> result = script->Run();

    // Convert the result to a UTF8 string and print it.
    String::Utf8Value utf8(result);
    printf("%s\n", *utf8);
  }

  // Dispose the Isolate and tear down V8
  isolate->Dispose();
  V8::Dispose();
  V8::ShutdownPlatform();
  delete platform;
  return 0;
}
