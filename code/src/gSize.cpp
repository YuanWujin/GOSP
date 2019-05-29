/*
 * Copyright (C) 2019  明心  <imleizhang@qq.com>
 * All rights reserved.
 * 
 * This program is an open-source software; and it is distributed in the hope 
 * that it will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
 * PURPOSE. 
 * This program is not a free software; so you can not redistribute it and/or 
 * modify it without my authorization. If you only need use it for personal
 * study purpose(no redistribution, and without any  commercial behavior), 
 * you should accept and follow the GNU AGPL v3 license, otherwise there
 * will be your's credit and legal risks.  And if you need use it for any 
 * commercial purpose, you should first get commercial authorization from
 * me, otherwise there will be your's credit and legal risks. 
 *
 */

#include <config_giveda.h>

#ifdef CONFIG_gSize

#ifndef GSIZE_H
#define GSIZE_H

#include <gGlobal.h>

#pragma pack(1)
struct T_SIZE
{
    T_OFFSET w;
    T_OFFSET h;
};
#pragma pack()

/*! @file  gSize.h
 * @brief  GSize 尺寸大小
 * 
 * @author 明心
 * @version 1.0.0
 * @date 2019-2-6
 */

/*!
 * @class GSize
 * @brief GSize 尺寸大小。对二维平面上的尺寸大小进行各种数学运算。
 * 
 */
class  DLL_PUBLIC GSize
{
public:
    GSize();
    GSize(T_OFFSET w, T_OFFSET h);
    virtual ~GSize() {}
    
    bool isNull() const;
    bool isEmpty() const;
    bool isValid() const;
    
    T_OFFSET width() const;
    T_OFFSET height() const;
    void setWidth(T_OFFSET w);
    void setHeight(T_OFFSET h);
    void transpose();
    
    GSize expandedTo(const GSize &) const;
    GSize boundedTo(const GSize &) const;
    
    T_OFFSET &rwidth();
    T_OFFSET &rheight();
    
    GSize &operator+=(const GSize &);
    GSize &operator-=(const GSize &);
    GSize &operator*=(double c);
    GSize &operator/=(double c);
    
    friend bool operator==(const GSize &, const GSize &);
    friend bool operator!=(const GSize &, const GSize &);
    friend bool operator>(const GSize &, const GSize &);
    friend const GSize operator+(const GSize &, const GSize &);
    friend const GSize operator-(const GSize &, const GSize &);
    friend const GSize operator*(const GSize &, double);
    friend const GSize operator*(double, const GSize &);
    friend const GSize operator/(const GSize &, double);
    
private:
    T_SIZE m_data;
};

#endif // ZSIZE_H

#endif  //CONFIG_gSize