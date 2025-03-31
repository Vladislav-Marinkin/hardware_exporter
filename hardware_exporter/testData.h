#pragma once

#ifndef TESTDATA_H
#define TESTDATA_H

#include <string>

class testData
{
public:
    std::string getSsacliControllerTestData() const;
    std::string getLSIControllerTestData() const;
    std::string getSsacliDiskTestData() const;
    std::string getLSIDiskTestData() const;

    std::string getAdaptecTestData() const;

    std::string getFanDriveData() const;

private:
    std::string ssacli;
};

#endif // TESTDATA_H