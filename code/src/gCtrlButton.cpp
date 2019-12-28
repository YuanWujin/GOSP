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

#include "gCtrlButton.h"
#include "gCtrlStyle.h"
#include "gCtrlForm.h"
#include <gConstDefine.h>
#include <gGlobal.h>

class GMButtonHmq
{
public:
    GMButtonHmq( const GString& strCaption, const GPixmap& bg, const GPixmap& focus, GCtrlForm* form, GMItem* parent ) : m_txtCaption( strCaption, form, parent, "btnCaption" ),
        m_pixBg( bg, form, parent, "btnBg" ),
        m_pixFocus( focus, form, parent, "btnFocus" )
    {
        
    }
    
    GMButtonHmq( GCtrlForm* form, GMItem* parent ) : m_txtCaption( form, parent, "btnCaption" ),
        m_pixBg( form, parent, "btnBg" ),
        m_pixFocus( form, parent, "btnFocus" )
    {}
    
    GMText m_txtCaption;
    GMPixmap m_pixBg;
    GMPixmap m_pixFocus;
};

GMButton::GMButton( GCtrlForm* form, GMItem* parent, const char* name )
    : GMCtrlItem( form, parent, name )
{
    btnMqs = new GMButtonHmq( form, this);
    
    GCtrlDefaultAppStyle* pAppStyle = getDefaultAppStyle();
    GCtrlItemStyle* pStyle=NULL;
    
    while (NULL== (pStyle=pAppStyle->itemStyle("GCtrlButton" ) ) ) {
        pAppStyle->appendButtonStyle();
    }

    btnMqs->m_pixBg.setPixmap( pStyle->pixmap( btnMqs->m_pixBg.name() ) );
    btnMqs->m_pixFocus.setPixmap( pStyle->pixmap( btnMqs->m_pixFocus.name() ) );
    btnMqs->m_txtCaption.setFont( pStyle->font( btnMqs->m_txtCaption.name()) );
    btnMqs->m_txtCaption.setColor( pStyle->color( btnMqs->m_txtCaption.name() ) );
    int nW = btnMqs->m_pixFocus.width() > btnMqs->m_pixBg.width() ? btnMqs->m_pixFocus.width() : btnMqs->m_pixBg.width();
    int nH = btnMqs->m_pixFocus.height() > btnMqs->m_pixBg.height() ? btnMqs->m_pixFocus.height() : btnMqs->m_pixBg.height();
    setSize( nW, nH );
    btnMqs->m_txtCaption.setSize( nW, nH );
    btnMqs->m_txtCaption.setTextFlags( Giveda::WordBreak | Giveda::AlignCenter );
}

GMButton::GMButton( const GString& strCaption, const GPixmap& bg, const GPixmap& focus, GCtrlForm* form, GMItem* parent, const char* name )
    : GMCtrlItem( form, parent, name )
{
    btnMqs = new GMButtonHmq(strCaption, bg, focus, form, this);
    
    int nW = btnMqs->m_pixFocus.width() > btnMqs->m_pixBg.width() ? btnMqs->m_pixFocus.width() : btnMqs->m_pixBg.width();
    int nH = btnMqs->m_pixFocus.height() > btnMqs->m_pixBg.height() ? btnMqs->m_pixFocus.height() : btnMqs->m_pixBg.height();
    setSize( nW, nH );
    btnMqs->m_txtCaption.setSize( nW, nH );
    btnMqs->m_txtCaption.setTextFlags( Giveda::WordBreak | Giveda::AlignCenter );
}

GMButton::~GMButton()
{
    delete btnMqs;
}

void GMButton::setCaption ( GString strCaption )
{
    btnMqs->m_txtCaption.setText ( strCaption );
}

void GMButton::setBgPixmap ( const GPixmap& pix )
{
    btnMqs->m_pixBg.setPixmap ( pix );
}

void GMButton::setFocusPixmap ( const GPixmap& pix )
{
    btnMqs->m_pixFocus.setPixmap ( pix );
}

void GMButton::paintEvent( GPainter& p )
{
    if(hasFocus())
    {
        btnMqs->m_pixFocus.draw(p);
    }
    else
    {
        btnMqs->m_pixBg.draw(p);
    }

    btnMqs->m_txtCaption.draw(p);
}

bool GMButton::fwKeyPressEvent( GKeyEvent* e )
{
    bool bRetVal = true;
    switch( e->key() )
    {
    case Giveda::Key_Return:
        clicked.emit();
        break;
    default:
        bRetVal = false;
        break;
    }

    return bRetVal;
}

GCtrlButton::GCtrlButton( GCtrlForm* form, GMItem* parent, const char* name )
    : GMButton( form, parent, name )
{
    form->appendItem(this);
}

GCtrlButton::GCtrlButton( const GString& strCaption, GCtrlForm* form, GMItem* parent, const char* name )
    : GMButton( form, parent, name )
{
    form->appendItem(this);
    setCaption( strCaption );
}

GCtrlButton::GCtrlButton( const GString& strCaption, const GPixmap& bg, const GPixmap& focus, GCtrlForm* form, GMItem* parent, const char* name )
    : GMButton( strCaption, bg, focus, form, parent, name )
{
    form->appendItem(this);
}

// have a nice day ^_^
// have a nice day ^_^
