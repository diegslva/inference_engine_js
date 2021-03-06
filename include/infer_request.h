#ifndef INFERENCE_ENGINE_JS_INFER_REQUEST_H
#define INFERENCE_ENGINE_JS_INFER_REQUEST_H

#include <napi.h>

#include <inference_engine.hpp>

namespace InferenceEngineJS {
    class InferRequest : public Napi::ObjectWrap<InferRequest> {
    public:
        static Napi::Object Init(Napi::Env env, Napi::Object exports);

        static Napi::FunctionReference constructor;

        explicit InferRequest(const Napi::CallbackInfo &info);

        Napi::Value getBlob(const Napi::CallbackInfo &info);

        void infer(const Napi::CallbackInfo &info);

        void  setCompletionCallback(const Napi::CallbackInfo &info);

        void startAsync(const Napi::CallbackInfo &info);

    private:

        InferenceEngine::InferRequest::Ptr _inferRequestPtr;
        
        Napi::ThreadSafeFunction _threadSafeFunction;
    };
}


#endif //INFERENCE_ENGINE_JS_INFER_REQUEST_H
