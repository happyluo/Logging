// **********************************************************************
//
// Copyright (c) 2010-2014 Bernard Luo. All rights reserved.
//
// <Email: luo (dot) xiaowei (at) hotmail (dot) com>
//
// **********************************************************************

#include <Logging/LoggerUtil.h>
#include <Logging/Logger.h>

using namespace std;

LOGGING_BEGIN

string
LoggerOutputBase::Str() const
{
    return m_strstream.str();
}

ostringstream&
LoggerOutputBase::Strstream()
{
    return m_strstream;
}

LoggerOutputBase&
operator <<(LoggerOutputBase& out, std::ios_base& (*val)(std::ios_base&))
{
    out.Strstream() << val;
    return out;
}

LoggerOutputBase& 
operator <<(LoggerOutputBase& out, std::ostream& (*val)(std::ostream&))
{
    out.Strstream() << val;
    return out;
}

LoggerOutputBase&
operator <<(LoggerOutputBase& out, const std::exception& ex)
{
    out.Strstream() << ex.what();
    return out;
}

Trace::Trace(const LoggerPtr& logger, const string& category) :
    m_logger(logger),
    m_category(category)
{
}

Trace::~Trace()
{
    Flush();
}

void
Trace::Flush()
{
    string s = Strstream().str();
    if (!s.empty())
    {
        m_logger->Trace(m_category, s);
    }
    Strstream().str("");
}

LOGGING_END
