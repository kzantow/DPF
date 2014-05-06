/*
 * DISTRHO Plugin Framework (DPF)
 * Copyright (C) 2012-2014 Filipe Coelho <falktx@falktx.com>
 *
 * Permission to use, copy, modify, and/or distribute this software for any purpose with
 * or without fee is hereby granted, provided that the above copyright notice and this
 * permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD
 * TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN
 * NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER
 * IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include "../Geometry.hpp"

START_NAMESPACE_DGL

// -----------------------------------------------------------------------
// Point

template<typename T>
Point<T>::Point() noexcept
    : fX(0),
      fY(0)
{
}

template<typename T>
Point<T>::Point(const T& x, const T& y) noexcept
    : fX(x),
      fY(y)
{
}

template<typename T>
Point<T>::Point(const Point<T>& pos) noexcept
    : fX(pos.fX),
      fY(pos.fY)
{
}

template<typename T>
const T& Point<T>::getX() const noexcept
{
    return fX;
}

template<typename T>
const T& Point<T>::getY() const noexcept
{
    return fY;
}

template<typename T>
void Point<T>::setX(const T& x) noexcept
{
    fX = x;
}

template<typename T>
void Point<T>::setY(const T& y) noexcept
{
    fY = y;
}

template<typename T>
void Point<T>::setPos(const T& x, const T& y) noexcept
{
    fX = x;
    fY = y;
}

template<typename T>
void Point<T>::setPos(const Point<T>& pos) noexcept
{
    fX = pos.fX;
    fY = pos.fY;
}

template<typename T>
void Point<T>::moveBy(const T& x, const T& y) noexcept
{
    fX += x;
    fY += y;
}

template<typename T>
void Point<T>::moveBy(const Point<T>& pos) noexcept
{
    fX += pos.fX;
    fY += pos.fY;
}

template<typename T>
Point<T>& Point<T>::operator=(const Point<T>& pos) noexcept
{
    fX = pos.fX;
    fY = pos.fY;
    return *this;
}

template<typename T>
Point<T>& Point<T>::operator+=(const Point<T>& pos) noexcept
{
    fX += pos.fX;
    fY += pos.fY;
    return *this;
}

template<typename T>
Point<T>& Point<T>::operator-=(const Point<T>& pos) noexcept
{
    fX -= pos.fX;
    fY -= pos.fY;
    return *this;
}

template<typename T>
bool Point<T>::operator==(const Point<T>& pos) const noexcept
{
    return (fX == pos.fX && fY== pos.fY);
}

template<typename T>
bool Point<T>::operator!=(const Point<T>& pos) const noexcept
{
    return !operator==(pos);
}

// -----------------------------------------------------------------------
// Size

template<typename T>
Size<T>::Size() noexcept
    : fWidth(0),
      fHeight(0)
{
}

template<typename T>
Size<T>::Size(const T& width, const T& height) noexcept
    : fWidth(width),
      fHeight(height)
{
}

template<typename T>
Size<T>::Size(const Size<T>& size) noexcept
    : fWidth(size.fWidth),
      fHeight(size.fHeight)
{
}

template<typename T>
const T& Size<T>::getWidth() const noexcept
{
    return fWidth;
}

template<typename T>
const T& Size<T>::getHeight() const noexcept
{
    return fHeight;
}

template<typename T>
void Size<T>::setWidth(const T& width) noexcept
{
    fWidth = width;
}

template<typename T>
void Size<T>::setHeight(const T& height) noexcept
{
    fHeight = height;
}

template<typename T>
void Size<T>::growBy(const T& multiplier) noexcept
{
    fWidth  *= multiplier;
    fHeight *= multiplier;
}

template<typename T>
void Size<T>::shrinkBy(const T& divider) noexcept
{
    fWidth  /= divider;
    fHeight /= divider;
}

template<typename T>
Size<T>& Size<T>::operator=(const Size<T>& size) noexcept
{
    fWidth  = size.fWidth;
    fHeight = size.fHeight;
    return *this;
}

template<typename T>
Size<T>& Size<T>::operator+=(const Size<T>& size) noexcept
{
    fWidth  += size.fWidth;
    fHeight += size.fHeight;
    return *this;
}

template<typename T>
Size<T>& Size<T>::operator-=(const Size<T>& size) noexcept
{
    fWidth  -= size.fWidth;
    fHeight -= size.fHeight;
    return *this;
}

template<typename T>
Size<T>& Size<T>::operator*=(const T& m) noexcept
{
    fWidth  *= m;
    fHeight *= m;
    return *this;
}

template<typename T>
Size<T>& Size<T>::operator/=(const T& d) noexcept
{
    fWidth  /= d;
    fHeight /= d;
    return *this;
}

template<typename T>
bool Size<T>::operator==(const Size<T>& size) const noexcept
{
    return (fWidth == size.fWidth && fHeight == size.fHeight);
}

template<typename T>
bool Size<T>::operator!=(const Size<T>& size) const noexcept
{
    return !operator==(size);
}

// -----------------------------------------------------------------------
// Rectangle

template<typename T>
Rectangle<T>::Rectangle() noexcept
    : fPos(0, 0),
      fSize(0, 0)
{
}

template<typename T>
Rectangle<T>::Rectangle(const T& x, const T& y, const T& width, const T& height) noexcept
    : fPos(x, y),
      fSize(width, height)
{
}

template<typename T>
Rectangle<T>::Rectangle(const T& x, const T& y, const Size<T>& size) noexcept
    : fPos(x, y),
      fSize(size)
{
}

template<typename T>
Rectangle<T>::Rectangle(const Point<T>& pos, const T& width, const T& height) noexcept
    : fPos(pos),
      fSize(width, height)
{
}

template<typename T>
Rectangle<T>::Rectangle(const Point<T>& pos, const Size<T>& size) noexcept
    : fPos(pos),
      fSize(size)
{
}

template<typename T>
Rectangle<T>::Rectangle(const Rectangle<T>& rect) noexcept
    : fPos(rect.fPos),
      fSize(rect.fSize)
{
}

template<typename T>
const T& Rectangle<T>::getX() const noexcept
{
    return fPos.fX;
}

template<typename T>
const T& Rectangle<T>::getY() const noexcept
{
    return fPos.fY;
}

template<typename T>
const T& Rectangle<T>::getWidth() const noexcept
{
    return fSize.fWidth;
}

template<typename T>
const T& Rectangle<T>::getHeight() const noexcept
{
    return fSize.fHeight;
}

template<typename T>
const Point<T>& Rectangle<T>::getPos() const noexcept
{
    return fPos;
}

template<typename T>
const Size<T>& Rectangle<T>::getSize() const noexcept
{
    return fSize;
}

template<typename T>
bool Rectangle<T>::contains(const T& x, const T& y) const noexcept
{
    return (x >= fPos.fX && y >= fPos.fY && x <= fPos.fX+fSize.fWidth && y <= fPos.fY+fSize.fHeight);
}

template<typename T>
bool Rectangle<T>::contains(const Point<T>& pos) const noexcept
{
    return contains(pos.fX, pos.fY);
}

template<typename T>
bool Rectangle<T>::containsX(const T& x) const noexcept
{
    return (x >= fPos.fX && x <= fPos.fX + fSize.fWidth);
}

template<typename T>
bool Rectangle<T>::containsY(const T& y) const noexcept
{
    return (y >= fPos.fY && y <= fPos.fY + fSize.fHeight);
}

template<typename T>
void Rectangle<T>::setX(const T& x) noexcept
{
    fPos.fX = x;
}

template<typename T>
void Rectangle<T>::setY(const T& y) noexcept
{
    fPos.fY = y;
}

template<typename T>
void Rectangle<T>::setPos(const T& x, const T& y) noexcept
{
    fPos.fX = x;
    fPos.fY = y;
}

template<typename T>
void Rectangle<T>::setPos(const Point<T>& pos) noexcept
{
    fPos = pos;
}

template<typename T>
void Rectangle<T>::move(const T& x, const T& y) noexcept
{
    fPos.fX += x;
    fPos.fY += y;
}

template<typename T>
void Rectangle<T>::move(const Point<T>& pos) noexcept
{
    fPos += pos;
}

template<typename T>
void Rectangle<T>::setWidth(const T& width) noexcept
{
    fSize.fWidth = width;
}

template<typename T>
void Rectangle<T>::setHeight(const T& height) noexcept
{
    fSize.fHeight = height;
}

template<typename T>
void Rectangle<T>::setSize(const T& width, const T& height) noexcept
{
    fSize.fWidth  = width;
    fSize.fHeight = height;
}

template<typename T>
void Rectangle<T>::setSize(const Size<T>& size) noexcept
{
    fSize = size;
}

template<typename T>
void Rectangle<T>::draw()
{
    // TODO - use glVexter2 d/f/i/s according to T type

    glBegin(GL_QUADS);

    {
        glTexCoord2f(0.0f, 0.0f);
        glVertex2i(fPos.fX, fPos.fY);

        glTexCoord2f(1.0f, 0.0f);
        glVertex2i(fPos.fX+fSize.fWidth, fPos.fY);

        glTexCoord2f(1.0f, 1.0f);
        glVertex2i(fPos.fX+fSize.fWidth, fPos.fY+fSize.fHeight);

        glTexCoord2f(0.0f, 1.0f);
        glVertex2i(fPos.fX, fPos.fY+fSize.fHeight);
    }

    glEnd();
}

template<typename T>
Rectangle<T>& Rectangle<T>::operator=(const Rectangle<T>& rect) noexcept
{
    fPos  = rect.fPos;
    fSize = rect.fSize;
    return *this;
}

// -----------------------------------------------------------------------
// Possible template data types

template class Point<short>;
template class Point<int>;
template class Point<long>;
template class Point<float>;
template class Point<double>;

template class Size<short>;
template class Size<int>;
template class Size<long>;
template class Size<float>;
template class Size<double>;

template class Rectangle<short>;
template class Rectangle<int>;
template class Rectangle<long>;
template class Rectangle<float>;
template class Rectangle<double>;

// -----------------------------------------------------------------------

END_NAMESPACE_DGL

