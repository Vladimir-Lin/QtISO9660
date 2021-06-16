/****************************************************************************
 *
 * Copyright (C) 2001~2016 Neutrino International Inc.
 *
 * Author   : Brian Lin ( Foxman , Vladimir Lin , Vladimir Forest )
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

#ifndef QT_ISO9660_H
#define QT_ISO9660_H

#include <QtCore>
#ifndef QT_STATIC
#include <QtScript>
#endif

QT_BEGIN_NAMESPACE

#ifndef QT_STATIC
#  if defined(QT_BUILD_QTISO9660_LIB)
#    define Q_ISO9660_EXPORT Q_DECL_EXPORT
#  else
#    define Q_ISO9660_EXPORT Q_DECL_IMPORT
#  endif
#else
#    define Q_ISO9660_EXPORT
#endif

#define QT_ISO9660_LIB 1

class Q_ISO9660_EXPORT QtISO9660 ;

#pragma pack(push,1)

typedef struct                               {
  unsigned char Type                         ;
  char          Identifier          [    5 ] ;
  unsigned char Version                      ;
}               IsoVolume                    ;

typedef struct                               {
  unsigned char Type                         ;
  char          Identifier          [    5 ] ;
  unsigned char Version                      ;
  char          BootSystem          [   32 ] ;
  char          BootIdentifier      [   32 ] ;
  char          Unused              [ 1976 ] ;
}               IsoBootRecord                ;

typedef struct                               {
  unsigned char Type                         ;
  char          Identifier          [    5 ] ;
  unsigned char Version                      ;
  char          Unused1                      ;
  char          SystemId            [   32 ] ;
  char          VolumeId            [   32 ] ;
  char          Unused2             [    8 ] ;
  qint64        VolumeSpaceSize              ;
  char          Unused3             [   32 ] ;
  qint32        VolumeSetSize                ;
  qint32        VolumeSequenceNumber         ;
  qint32        LogicalBlockSize             ;
  qint64        PathTableSize                ;
  qint32        TypeLPathTable               ;
  qint32        OptTypeLPathTable            ;
  qint32        TypeMPathTable               ;
  qint32        OptTypeMPathTable            ;
  char          RootDirectoryRecord [   34 ] ;
  char          VolumeSetId         [  128 ] ;
  char          PublisherId         [  128 ] ;
  char          PreparerId          [  128 ] ;
  char          ApplicationId       [  128 ] ;
  char          CopyrightFileId     [   37 ] ;
  char          AbstractFileId      [   37 ] ;
  char          BibliographicFileId [   37 ] ;
  char          CreationDate        [   17 ] ;
  char          ModificationDate    [   17 ] ;
  char          ExpirationDate      [   17 ] ;
  char          EffectiveDate       [   17 ] ;
  unsigned char FileStructureVersion         ;
  unsigned char Unused4                      ;
  char          ApplicationData     [  512 ] ;
  char          Unused5             [  653 ] ;
}               IsoDescriptor                ;

typedef struct                               {
  unsigned char Type                         ;
  char          Identifier          [    5 ] ;
  unsigned char Version                      ;
  unsigned char Flags                        ;
  char          SystemId            [   32 ] ;
  char          VolumeId            [   32 ] ;
  char          Unused2             [    8 ] ;
  qint64        VolumeSpaceSize              ;
  char          EscapeSequences     [   32 ] ;
  qint32        VolumeSetSize                ;
  qint32        VolumeSequenceNumber         ;
  qint32        LogicalBlockSize             ;
  qint64        PathTableSize                ;
  qint32        TypeLPathTable               ;
  qint32        OptTypeLPathTable            ;
  qint32        TypeMPathTable               ;
  qint32        OptTypeMPathTable            ;
  char          RootDirectoryRecord [   34 ] ;
  char          VolumeSetId         [  128 ] ;
  char          PublisherId         [  128 ] ;
  char          PreparerId          [  128 ] ;
  char          ApplicationId       [  128 ] ;
  char          CopyrightFileId     [   37 ] ;
  char          AbstractFileId      [   37 ] ;
  char          BibliographicFileId [   37 ] ;
  char          CreationDate        [   17 ] ;
  char          ModificationDate    [   17 ] ;
  char          ExpirationDate      [   17 ] ;
  char          EffectiveDate       [   17 ] ;
  unsigned char FileStructureVersion         ;
  unsigned char Unused4                      ;
  char          ApplicationData     [  512 ] ;
  char          Unused5             [  653 ] ;
}               IsoSupplementary             ;

typedef struct                               {
  unsigned char Type                         ;
  char          Identifier          [    5 ] ;
  unsigned char Version                      ;
  unsigned char Unused1                      ;
  char          SystemIdentifier    [   32 ] ;
  char          PartitionIdentifier [   32 ] ;
  qint64        PartitionLocation            ;
  qint64        PartitionSize                ;
  char          Unused2             [ 1960 ] ;
}               IsoPartition                 ;

typedef struct                               {
  unsigned char Length                       ;
  unsigned char ExtAttrLength                ;
  qint64        Extent                       ;
  qint64        Size                         ;
  unsigned char Date                [    7 ] ;
  unsigned char Flags                        ;
  unsigned char FileUnitSize                 ;
  unsigned char Interleave                   ;
  qint32        VolumeSequenceNumber         ;
  unsigned char NameLen                      ;
  char          Name                [    1 ] ;
}               IsoDirectory                 ;

typedef struct                               {
  unsigned char Length                       ;
  unsigned char ExtAttrLength                ;
  qint64        Extent                       ;
  qint16        DirectoryNumber              ;
  char          Identifier          [    1 ] ;
}               IsoPathTable                 ;

typedef struct                               {
  qint32        Owner                        ;
  qint32        Group                        ;
  qint16        Permissions                  ;
  char          FileCreation        [   17 ] ;
  char          FileModification    [   17 ] ;
  char          FileExpiration      [   17 ] ;
  char          FileEffective       [   17 ] ;
  unsigned char Format                       ;
  unsigned char Attributes                   ;
  qint32        RecordLength                 ;
  char          SystemIdentifier    [   32 ] ;
  char          Unused1             [   64 ] ;
  unsigned char ExtendedVersion              ;
  unsigned char LengthOfEscapeSequences      ;
  char          Unused2             [   64 ] ;
  qint32        LengthOfApplicationUse       ;
  char          Application         [    1 ] ;
}               IsoAttribute                 ;

#pragma pack(pop)

class Q_ISO9660_EXPORT QtISO9660
{
  public:

    QMap<QString,QVariant> Information ;

    explicit    QtISO9660 (void) ;
    virtual    ~QtISO9660 (void) ;

    virtual int isVolume  (char * block) ;

  protected:

  private:

} ;

QT_END_NAMESPACE

#endif
