/*
  MIT License
  
  Copyright (c) 2019 Sung Gon Kim
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
  
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
*/

#include <gtest/gtest.h>
#include <zip.h>
#include <cstdio>
#include <stdexcept>
#include "Constants.hpp"
#include "snap/zip/Archive.hpp"

class ZipArchiveTest : public ::testing::Test {
 protected:
  void SetUp() override {
    std::remove(test::zip::ZIP_FILE);
  }
};

TEST_F(ZipArchiveTest, openFailsWhenUnknownFileWithNoOptionGiven) {
  EXPECT_THROW({ snap::zip::Archive o(test::zip::ZIP_FILE); },
               std::runtime_error);
}

TEST_F(ZipArchiveTest, openOKWhenUnknownFileWithCreateOptionGiven) {
  auto flags = ZIP_CREATE | ZIP_TRUNCATE;
  EXPECT_NO_THROW({ snap::zip::Archive o(test::zip::ZIP_FILE, flags); });
}
