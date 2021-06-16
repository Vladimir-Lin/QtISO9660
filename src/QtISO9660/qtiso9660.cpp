/****************************************************************************
 *
 * Copyright (C) 2016 Neutrino International Inc.
 *
 * Author   : Brian Lin ( Vladimir Lin , Vladimir Forest )
 * E-mail   : lin.foxman@gmail.com
 *          : lin.vladimir@gmail.com
 *          : wolfram_lin@yahoo.com
 *          : wolfram_lin@sina.com
 *          : wolfram_lin@163.com
 * Skype    : wolfram_lin
 * WeChat   : 153-0271-7160
 * WhatsApp : 153-0271-7160
 * QQ       : lin.vladimir@gmail.com
 * URL      : http://qtucl.sourceforge.net/
 *
 * QtUCL acts as an interface between Qt and UCL library.
 * Please keep QtUCL as simple as possible.
 *
 * Copyright 2001 ~ 2016
 *
 ****************************************************************************/

#include <qtiso9660.h>


QT_BEGIN_NAMESPACE

//////////////////////////////////////////////////////////////////////////////

QtISO9660:: QtISO9660 (void)
{
}

QtISO9660::~QtISO9660 (void)
{
}

int QtISO9660::isVolume (char * block)
{
  IsoVolume * iv = (IsoVolume *) block                              ;
  if ( 1 != iv -> Version                               ) return -1 ;
  if ( 0 != ::memcmp ( iv -> Identifier , "CD001" , 5 ) ) return -1 ;
  return iv -> Type                                                 ;
}

//////////////////////////////////////////////////////////////////////////////

QT_END_NAMESPACE
