//
//  main.cpp
//  spl
//
//  Created by 孔祥云 on 3/22/17.
//  Copyright © 2017 孔祥云. All rights reserved.
//

#include <iostream>
#include <string>

#include <bsp/bsp_complier.hpp>

using namespace std;
using namespace spl;

int main(int argc, const char * argv[]) {
    bsp::compiler compiler;
    compiler.add_dir("/Users/kongxiangyun/Documents/project/kxy/xiangyun.kong/bsp/mind");
    compiler.compile();
    compiler.show_barren();
    return 0;
}
