#include "stdafx.h"

namespace WISP_FILE
{
CBinaryFileWriter::CBinaryFileWriter()
    : WISP_DATASTREAM::CDataWriter()
{
}

CBinaryFileWriter::~CBinaryFileWriter()
{
    Close();
}

bool CBinaryFileWriter::Open(const string &path)
{
    WISPFUN_DEBUG("c2_f1");
    bool result = false;

    {
        fopen_s(&m_File, path.c_str(), "wb");
        result = (m_File != NULL);
    }

    return result;
}

bool CBinaryFileWriter::Open(const wstring &path)
{
    WISPFUN_DEBUG("c2_f2");
    bool result = false;

    {
        _wfopen_s(&m_File, path.c_str(), L"wb");
        result = (m_File != NULL);
    }

    return result;
}

void CBinaryFileWriter::Close()
{
    WISPFUN_DEBUG("c2_f3");
    WriteBuffer();

    if (m_File != NULL)
    {
        fclose(m_File);
        m_File = NULL;
    }
}

void CBinaryFileWriter::WriteBuffer()
{
    WISPFUN_DEBUG("c2_f4");
    if (m_File != NULL && m_Data.size() > 0)
    {
        fwrite(&m_Data[0], m_Data.size(), 1, m_File);
        m_Data.clear();
    }
}

}; // namespace WISP_FILE
