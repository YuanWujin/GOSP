/*
 * Copyright (C) 2019  明心  <imleizhang@qq.com>
 * All rights reserved.
 *
 * This program is an open-source software; and it is distributed in the hope
 * that it will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.
 * This program is not a free software; so you can not redistribute it(include
 * binary form and source code form) without my authorization. And if you
 * need use it for any commercial purpose, you should first get commercial
 * authorization from me, otherwise there will be your's legal&credit risks.
 *
 */

#ifndef GMITEM_H
#define GMITEM_H

#include <gObject.h>
#include <gFont.h>
#include <gPixmap.h>
#include <gImage.h>
#include <gPointer.h>
#include <gTimer.h>
#include <gPainter.h>
#include <gEvent.h>
#include "gCtrlForm.h"
#include <gConstDefine.h>
#include <gGlobal.h>

class GCtrlForm;
class GMItemPrivate;
class GCtrlDefaultAppStyle;

class GMItem : public GObject
{
    SET_CLASS_NAME(GMItem)
    G_DISABLE_COPY(GMItem, GObject)
public:
    GMItem ( GCtrlForm* form, GMItem* parent=0, const char* name=0 );
    virtual ~GMItem();
    void setX (int x);
    void setY (int y);
    void setZ (int z);
    void setWidth( int w );
    void setHeight( int h );
    int x() const;
    int y() const;
    int z() const;
    int width () const;
    int height () const;
    int right () const;
    int bottom() const;
    GRect rect() const;
    void setPosition( int x, int y);
    void setSize( int w, int h );
    void setGeometry ( int x, int y, int w, int h);
    void moveBy ( int x, int y );
    virtual bool isCtrlItem();
    virtual void show ();
    virtual void hide ();
    GCtrlForm* form();
    bool isVisible ();
    void setVisible (bool b);
    virtual void draw ( GPainter& );
    void setPaletteBackgroundColor ( const GColor &c );
    void loadBackgroundPixmap( const GString& strPic );


#if 0
    void addChild( GMItem* pItem ) {
        m_listChildren.append(pItem);
    }
#endif
    GCtrlDefaultAppStyle* getDefaultAppStyle();
    virtual bool isComplex();
public slots:
    void update();
protected:
    virtual void paintEvent ( GPainter& );
private:
    GMItemPrivate *iPriv;
#if 0
    GPtrList<GMItem> m_listChildren;
#endif
};

class GMCtrlItemPrivate;

class GMCtrlItem : public GMItem
{
    SET_CLASS_NAME(GMCtrlItem)
    G_DISABLE_ASSIGN(GMCtrlItem)
public:
    GMCtrlItem ( GCtrlForm* form, GMItem* parent=0, const char* name=0 );
    virtual ~GMCtrlItem();
    virtual bool isCtrlItem();
    bool isFocusEnabled();
    void setFocusEnabled( bool b );
    void setFocus();
    bool hasFocus();

    bool fwKeyPress ( GKeyEvent * );
    void setTabIndex( unsigned int index );
    unsigned int tabIndex();
    void emitLoseFocus();
    void emitGetFocus();
    virtual void hide ();
signals:
    GSignal<void(void)>  loseFocus;

    GSignal<void(void)>  getFocus;
protected:
    virtual bool keyPressEvent(GKeyEvent* );
    virtual bool fwKeyPressEvent(GKeyEvent*)=0;
private:
    GMCtrlItemPrivate *ciPriv;
};

class GMContainerItem : public GMCtrlItem
{
    G_DISABLE_ASSIGN(GMContainerItem)
public:
    GMContainerItem ( GCtrlForm* form, GMItem* parent=0, const char* name=0 );
    void setFocusToItem(GMCtrlItem* pItem );
protected:
    GPointer<GMCtrlItem> mpFocus;
};

class GMPixmapPrivate;

class GMPixmap : public GMItem
{
    G_DISABLE_ASSIGN(GMPixmap)
public:
    GMPixmap ( GCtrlForm* form, GMItem* parent=0, const char* name=0 );
    GMPixmap ( const GString & strPath, GCtrlForm* form, GMItem* parent=0, const char* name=0 );
    GMPixmap ( const GPixmap & pm, GCtrlForm* form, GMItem* parent=0, const char* name=0 );
    virtual ~GMPixmap();
    void load( const GString& strPath );
    void setPixmap( const GPixmap &pm );
    void loadButNotAdjustSize( const GString& strPath );
    void setPixmapButNotAdjustSize( const GPixmap &pm );
protected:
    virtual void paintEvent ( GPainter& );
private:
    GMPixmapPrivate *pixPriv;
};

class GMImagePrivate;

class GMImage : public GMItem
{
    G_DISABLE_ASSIGN(GMImage)
public:
    GMImage ( GCtrlForm* form, GMItem* parent=0, const char* name=0 );
    GMImage ( const GString & strPath, GCtrlForm* form, GMItem* parent=0, const char* name=0 );
    GMImage ( const GImage & img, GCtrlForm* form, GMItem* parent=0, const char* name=0 );
    virtual ~GMImage();
    void load( const GString& strPath );
    void setImage( const GImage &img );

protected:
    virtual void paintEvent ( GPainter& );
private:
    GMImagePrivate *imgPriv;
};

class GMTextPrivate;

class GMText : public GMItem
{
    G_DISABLE_ASSIGN(GMText)
public:
    GMText ( GCtrlForm* form, GMItem* parent=0, const char* name=0 );
    GMText ( const GString & str, GCtrlForm* form, GMItem* parent=0, const char* name=0 );
    virtual ~GMText();
    void setText( const GString& str );
    void setFont( const GFont & font );
    void setColor( const GColor& color );
    void setTextFlags( int nFlags );
    GString text();
    GSize getSingleLineSize();
protected:
    virtual void paintEvent ( GPainter& );
protected:
    GMTextPrivate *txtPriv;
};

class GMScrollTextPrivate;

class GMScrollText : public GMText
{
    SET_CLASS_NAME(GMScrollText)
    G_DISABLE_ASSIGN(GMScrollText)
public:
    GMScrollText ( GCtrlForm* form, GMItem* parent=0, const char* name=0 );
    GMScrollText ( const GString & str, GCtrlForm* form, GMItem* parent=0, const char* name=0 );
    virtual ~GMScrollText();

    void startScroll( unsigned int msec=500 );
    void stopScroll();
    bool isScroll();
    
private:
    bool isNeedScroll();
    
private slots:
    void slotUpdate();
    
private:
    GMScrollTextPrivate *stPriv;
};

#endif
// have a nice day
// have a nice day
// have a nice day
// have a nice day
// have a nice day
// have a nice day
