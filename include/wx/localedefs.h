///////////////////////////////////////////////////////////////////////////////
// Name:        wx/localedefs.h
// Purpose:     Definitions of common locale-related constants and structs.
// Author:      Vadim Zeitlin
// Created:     2021-07-31 (extracted from wx/intl.h)
// Copyright:   (c) 2021 Vadim Zeitlin <vadim@wxwidgets.org>
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef _WX_LOCALEDEFS_H_
#define _WX_LOCALEDEFS_H_

// ----------------------------------------------------------------------------
// wxLayoutDirection: used by wxWindow, wxDC etc
// ----------------------------------------------------------------------------

// Note that this one must be available even when wxUSE_INTL == 0 as it's used
// outside of locale code too.

enum wxLayoutDirection
{
    wxLayout_Default,
    wxLayout_LeftToRight,
    wxLayout_RightToLeft
};

#if wxUSE_INTL

#include "wx/string.h"

// ----------------------------------------------------------------------------
// wxLocaleCategory: the category of locale settings
// ----------------------------------------------------------------------------

enum wxLocaleCategory
{
    // (any) numbers
    wxLOCALE_CAT_NUMBER,

    // date/time
    wxLOCALE_CAT_DATE,

    // monetary value
    wxLOCALE_CAT_MONEY,

    // default category for wxLocaleInfo values which only apply to a single
    // category (e.g. wxLOCALE_SHORT_DATE_FMT)
    wxLOCALE_CAT_DEFAULT,

    wxLOCALE_CAT_MAX
};

// ----------------------------------------------------------------------------
// wxLocaleInfo: the items understood by wxLocale::GetInfo()
// ----------------------------------------------------------------------------

enum wxLocaleInfo
{
    // the thousands separator (for wxLOCALE_CAT_NUMBER or MONEY)
    wxLOCALE_THOUSANDS_SEP,

    // the character used as decimal point (for wxLOCALE_CAT_NUMBER or MONEY)
    wxLOCALE_DECIMAL_POINT,

    // the stftime()-formats used for short/long date and time representations
    // (under some platforms short and long date formats are the same)
    //
    // NB: these elements should appear in this order, code in GetInfo() relies
    //     on it
    wxLOCALE_SHORT_DATE_FMT,
    wxLOCALE_LONG_DATE_FMT,
    wxLOCALE_DATE_TIME_FMT,
    wxLOCALE_TIME_FMT

};

// ----------------------------------------------------------------------------
// wxLanguageInfo: encapsulates wxLanguage to OS native lang.desc.
//                 translation information
// ----------------------------------------------------------------------------

struct WXDLLIMPEXP_BASE wxLanguageInfo
{
    int Language;                   // wxLanguage id
    wxString CanonicalName;         // Canonical name, e.g. fr_FR
#ifdef __WINDOWS__
    wxUint32 WinLang,               // Win32 language identifiers
             WinSublang;
#endif // __WINDOWS__
    wxString Description;           // human-readable name of the language
    wxLayoutDirection LayoutDirection;

#ifdef __WINDOWS__
    // return the LCID corresponding to this language
    wxUint32 GetLCID() const;
#endif // __WINDOWS__

    // return the locale name corresponding to this language usable with
    // setlocale() on the current system or empty string if this locale is not
    // supported
    wxString GetLocaleName() const;

    // Call setlocale() and return non-null value if it works for this language.
    //
    // This function is mostly for internal use, as changing locale involves
    // more than just calling setlocale() on some platforms, use wxLocale to
    // do everything that needs to be done instead of calling this method.
    const char* TrySetLocale() const;
};

#endif // wxUSE_INTL

#endif // _WX_LOCALEDEFS_H_
