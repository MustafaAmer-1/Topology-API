#include <QtTest>

// add necessary includes here

class TopologyTest : public QObject
{
    Q_OBJECT

public:
    TopologyTest();
    ~TopologyTest();

};

TopologyTest::TopologyTest()
{

}

TopologyTest::~TopologyTest()
{

}

QTEST_APPLESS_MAIN(TopologyTest)

#include "tst_topologytest.moc"
