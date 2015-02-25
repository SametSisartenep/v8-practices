CC=clang++
INCLUDE=-I../../../..
LIBS=../../obj.target/third_party/icu/libicudata.a ../../obj.target/third_party/icu/libicui18n.a ../../obj.target/third_party/icu/libicuuc.a ../../obj.target/tools/gyp/libv8_base.a ../../obj.target/tools/gyp/libv8_libbase.a ../../obj.target/tools/gyp/libv8_libplatform.a ../../obj.target/tools/gyp/libv8_snapshot.a
CFLAGS=-Wl,--start-group $(LIBS) -Wl,--end-group -lrt -pthread

helloworld: hello_world.cc
	$(CC) $(INCLUDE) hello_world.cc -o hello_world $(CFLAGS)
