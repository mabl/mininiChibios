#ifndef WXMININI_H
#define WXMININI_H

#include <wx/wx.h>

class minIni
{
public:
  minIni(const wxString& filename) : iniFilename(filename)
    { }

  long getl(const wxString& Section, const wxString& Key, long DefValue=0)
    {
    return ini_getl(Section.utf8_str(), Key.utf8_str(), DefValue, iniFilename.utf8_str());
    }

  int geti(const wxString& Section, const wxString& Key, int DefValue=0)
    {
    return (int)ini_getl(Section.utf8_str(), Key.utf8_str(), DefValue, iniFilename.utf8_str());
    }

  wxString gets(const wxString& Section, const wxString& Key, const wxString& DefValue=wxT(""))
    {
    char buffer[INI_BUFFERSIZE];
    ini_gets(Section.utf8_str(), Key.utf8_str(), DefValue.utf8_str(), buffer, INI_BUFFERSIZE, iniFilename.utf8_str());
    wxString result = wxString::FromUTF8(buffer);
    return result;
    }

  bool put(const wxString& Section, const wxString& Key, long Value)
    {
    return ini_putl(Section.utf8_str(), Key.utf8_str(), Value, iniFilename.utf8_str());
    }

  bool put(const wxString& Section, const wxString& Key, int Value)
    {
    return ini_putl(Section.utf8_str(), Key.utf8_str(), Value, iniFilename.utf8_str());
    }

  bool put(const wxString& Section, const wxString& Key, const wxString& Value)
    {
    return ini_puts(Section.utf8_str(), Key.utf8_str(), Value.utf8_str(), iniFilename.utf8_str());
    }

private:
  wxString iniFilename;
};

#endif /* WXMININI_H */
