#ifndef INFERENCE_ENGINE_JS_BLOB_H
#define INFERENCE_ENGINE_JS_BLOB_H

#include <napi.h>

#include <inference_engine.hpp>

namespace InferenceEngineJS {
    class Blob : public Napi::ObjectWrap<Blob> {
    public:
        static Napi::Object Init(Napi::Env env, Napi::Object exports);

        static Napi::FunctionReference constructor;

        explicit Blob(const Napi::CallbackInfo &info);

        Napi::Value getDims(const Napi::CallbackInfo &info);

        void fillWithU8(const Napi::CallbackInfo &info);

        Napi::Value data(const Napi::CallbackInfo &info);

    private:

        InferenceEngine::Blob::Ptr _ieBlobPtr;

    };
}
#endif //INFERENCE_ENGINE_JS_BLOB_H
