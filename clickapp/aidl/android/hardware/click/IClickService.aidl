package android.hardware.click;

/**
 * AIDL interface to communicate with Click HAL
 */
interface IClickService {
    void triggerClick();
    int readValue();
}
