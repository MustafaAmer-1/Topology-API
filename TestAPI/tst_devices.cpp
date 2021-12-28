#include <QtTest>

// add necessary includes here
#include "Device.h"
#include "Resistor.h"

class DevicesTest : public QObject
{
Q_OBJECT
public:
    DevicesTest();
    ~DevicesTest();
private:
    Device* device;
    Resistor* resistor;
private slots:
    void device_test();
    void resistor_test();
};

DevicesTest::DevicesTest(){
    device = new Device();
    resistor = new Resistor();
}

DevicesTest::~DevicesTest(){
    delete device;
    delete resistor;
}

void DevicesTest::device_test(){
    device = new Device(5154, 6654, 653);
    QCOMPARE(device->getDefault(), 5154);
    QCOMPARE(device->getMin(), 6654);
    QCOMPARE(device->getMax(), 653);
}

void DevicesTest::resistor_test() {
    resistor = new Resistor(5154, 6654, 653);
    QCOMPARE(resistor->getDefault(), 5154);
    QCOMPARE(resistor->getMin(), 6654);
    QCOMPARE(resistor->getMax(), 653);
}

QTEST_APPLESS_MAIN(DevicesTest)

#include "tst_devices.moc"
