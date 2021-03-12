/*
 ***********************************************************************************************************************
 *
 *  Copyright (c) 2019-2021 Advanced Micro Devices, Inc. All Rights Reserved.
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 *
 **********************************************************************************************************************/
/**
***********************************************************************************************************************
* @file  opt_layer.h
* @brief Optimization layer base class
***********************************************************************************************************************
*/

#ifndef __OPT_LAYER_H__
#define __OPT_LAYER_H__

#pragma once

#include "include/vk_dispatch.h"

namespace vk
{

// =====================================================================================================================
// Class that specifies dispatch table override behavior for derived appopt layers
class OptLayer
{
public:
    OptLayer() {}
    virtual ~OptLayer() {}

    virtual void OverrideDispatchTable(DispatchTable* pDispatchTable) = 0;

    VK_INLINE const DispatchTable* GetNextLayer() const
        { return &m_nextLayer; }

protected:
    DispatchTable m_nextLayer;                               // Dispatch table to the next layer's functions

private:
    PAL_DISALLOW_COPY_AND_ASSIGN(OptLayer);
};

} // namespace vk

#endif /* __OPT_LAYER_H__ */
