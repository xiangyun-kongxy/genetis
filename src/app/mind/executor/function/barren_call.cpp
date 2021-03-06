//
//  barren_call.cpp
//  executor
//
//  Created by 孔祥云 on 11/9/17.
//  Copyright © 2017 xiangyun.kong. All rights reserved.
//

#include "barren_call.hpp"

#include <key_barren.hpp>

namespace mind {
    
    ptr<barren> barren_call::call() {
        return  _call(_init_param(deque<ptr<barren>>()));
    }
    
    deque<ptr<barren>>
    barren_call::_init_param(const deque<ptr<mind::barren> > &gp) {
        deque<ptr<barren>> params;
        for (long i = 3; i < size(); ++i) {
            if ((*this)[i] < 0) {
                if (gp.size() > -(*this)[i]) {
                    params.push_back(gp[-(*this)[i] - 1]);
                } else {
                    params.push_back(barren::load(br_false));
                }
            } else if ((*this)[i] == 0) {
                params.push_back(barren::load(br_false));
            } else {
                ptr<barren_call> sub_call = barren::load((*this)[i]);
                if (sub_call != nullptr) {
                    params.push_back(sub_call->_call(gp));
                } else {
                    params.push_back(barren::load(br_false));
                }
            }
        }
        return params;
    }
    
    ptr<barren_function>
    barren_call::_get_function(const deque<ptr<barren>>& params) {
        ptr<barren_function> func = barren::load((*this)[2]);
        
        if (func != nullptr) {
            ptr<barren_call> call = func;
            if (call->is_call()) {
                func = call->_call(params);
            }
        } else {
            func = barren::load(br_false);
        }
        
        return func;
    }
    
    ptr<barren> barren_call::_call(const deque<ptr<mind::barren> > &params) {
        if (!is_call()) {
            return this;
        }
        
        ptr<barren_function> func = _get_function(params);
        if (!func->is_function()) {
            return func;
        }
    
        bfunction  rfunc = func->get_raw_function();
        if (rfunc != nullptr) {
            ptr<barren_call> result = rfunc(_init_param(params));
            if (result->is_call()) {
                return result->_call(params);
            } else {
                return result;
            }
        } else {
            return barren::load(br_false);
        }
    }
    
    bool barren_call::is_call() {
        return size() >= 3 && (*(barren_call*)this)[1L] == barren::load(br_call)->id();
    }
}
