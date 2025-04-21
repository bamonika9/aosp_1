#include <android-base/logging.h>
#include <binder/IServiceManager.h>
#include "ClickHal.hpp"
#include <android/hardware/click/BnClickService.h>

using android::sp;
using android::binder::Status;
using android::hardware::click::BnClickService;

class ClickServiceImpl : public BnClickService {
public:
    ClickServiceImpl() : hal() {}

    Status triggerClick() override {
        bool success = hal.triggerClick();
        return success ? Status::ok() : Status::fromExceptionCode(Status::EX_SERVICE_SPECIFIC);
    }

    Status readValue(int32_t* _aidl_return) override {
        *_aidl_return = hal.readValue();
        return Status::ok();
    }

private:
    ClickHal hal;
};

int main() {
    android::sp<ClickServiceImpl> service = new ClickServiceImpl();
    android::status_t status = android::defaultServiceManager()->addService(
        android::String16("android.hardware.click.IClickService/default"), service);
    LOG(INFO) << "ClickService registered, status: " << status;
    android::ProcessState::self()->startThreadPool();
    android::IPCThreadState::self()->joinThreadPool();
    return 0;
}
