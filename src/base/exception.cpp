// ASEPRITE base library
// Copyright (C) 2001-2013  David Capello
//
// This source file is distributed under a BSD-like license, please
// read LICENSE.txt for more information.

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "base/exception.h"

#include <cstdio>
#include <cstdarg>

namespace base {

using namespace std;

Exception::Exception() throw()
{
}

Exception::Exception(const char* format, ...) throw()
{
  try {
    if (!strchr(format, '%')) {
      m_msg = format;
    }
    else {
      va_list ap;
      va_start(ap, format);

      char buf[1024];           // TODO warning buffer overflow
      vsprintf(buf, format, ap);
      m_msg = buf;

      va_end(ap);
    }
  }
  catch (...) {
    // No throw
  }
}

Exception::Exception(const std::string& msg) throw()
{
  try {
    m_msg = msg;
  }
  catch (...) {
    // No throw
  }
}

Exception::~Exception() throw()
{
}

void Exception::setMessage(const char* msg) throw()
{
  try {
    m_msg = msg;
  }
  catch (...) {
    // No throw
  }
}

const char* Exception::what() const throw()
{
  return m_msg.c_str();
}

} // namespace base
