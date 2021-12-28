#include <QtTest>

// add necessary includes here
#include "Device.h"
#include "Resistor.h"
#include "ElectronicObject.h"

class DevicesTest : public QObject
{
Q_OBJECT
public:
    DevicesTest();
    ~DevicesTest();
private:
    Resistor* resistor;
private slots:
    void resistor_test();
};

DevicesTest::DevicesTest(){
    resistor = new Resistor();
}

DevicesTest::~DevicesTest(){
    delete resistor;
}

void DevicesTest::resistor_test() {
    QCOMPARE(resistor->getId(), "0");
    resistor = new Resistor(5154, 6654, 653);
    QCOMPARE(resistor->getDefault(), 5154);
    QCOMPARE(resistor->getMin(), 6654);
    QCOMPARE(resistor->getMax(), 653);
    QVERIFY_EXCEPTION_THROWN(resistor->setId("0"), IdException);
}

QTEST_APPLESS_MAIN(DevicesTest)

#include "tst_devices.moc"
