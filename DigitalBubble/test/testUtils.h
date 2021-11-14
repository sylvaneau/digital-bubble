#ifndef TestUtils_h
#define TestUtils_h

/*************************************
 *            TestResult
 ************************************/

class TestResult
{
    public:
    TestResult(String testName);
    TestResult(String testName, String actual, String expected);

    String getTestName();
    bool isSuccess();
    String getActual();
    String getExpected();
    
  private:
    String _testName;
    bool _success;
    String _actual;
    String _expected;
};

TestResult::TestResult(String testName)
{
    _testName = testName;
    _success = true;
}

TestResult::TestResult(String testName, String actual, String expected)
{
    _testName = testName;
    _success = false;

    _actual = actual;
    _expected = expected;
}

String TestResult::getTestName()
{
    return _testName;
}

bool TestResult::isSuccess()
{
    return _success;
}

String TestResult::getActual()
{
    return _actual;
}

String TestResult::getExpected()
{
    return _expected;
}

/*************************************
 *             Asserts
 ************************************/

TestResult AssertEquals(String callerName, double actual, double expected)
{
    if (actual == expected)
        return TestResult(callerName);
    else
        return TestResult(callerName, String(actual), String(expected));
}

TestResult AssertSuccess(String callerName)
{
    return TestResult(callerName);
}

TestResult AssertFaillure(String callerName, String actual, String expected)
{
    return TestResult(callerName, actual, expected);
}

/*************************************
 *            Test Runner
 ************************************/

void runTest(TestResult (*testFunc)())
{
    TestResult result = testFunc();

    Serial.print("* ");
    Serial.print(result.getTestName());

    if (result.isSuccess())
    {
        Serial.println(": OK.");
    }
    else
    {
        Serial.println(": Fail!");
        Serial.print("__Expected: ");
        Serial.println(result.getExpected());
        Serial.print("__Actual: ");
        Serial.println(result.getActual());
    }
}

#endif