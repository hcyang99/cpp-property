// Copyright (C) 2020 Haichao Yang
//
// GNU GENERAL PUBLIC LICENSE VERSION 3
// This file is free software; you can redistribute it and/or modify it 
// under the terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.
//
// <http://www.gnu.org/licenses/>.

#pragma once
namespace MyProperty
{
    template <typename T>
    struct __DefaultSetHandler
    {
        bool operator()(const T& v)
        {
            return true;
        }
    };

    template <typename T, typename SetHandler = __DefaultSetHandler<T>>
    class Property
    {
        public:
            const T& operator=(const T& v) 
            { 
                SetHandler handle;
                if (handle(v))
                    value = v;
                return v;
            }

            operator T() const { return value; }
            
        private:
            T value;
    };

    template <typename T, typename C, typename SetHandler = __DefaultSetHandler<T>>
    class ReadOnlyProperty
    {
        friend C;
        public:
            operator T() const { return value; }

        private:
            const T& operator=(const T& v) 
            { 
                SetHandler handle;
                if (handle(v))
                    value = v;
                return v;
            }

            T value;
    };
}


