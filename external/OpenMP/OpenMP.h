//
//  OpenMP.h
//  pvrtool
//
//  Created by Mihailo Gazda on 12/11/2015.
//  Copyright (c) 2015 Mihailo Gazda. All rights reserved.
//

#ifndef pvrtool_OpenMP_h
#define pvrtool_OpenMP_h

//  MSVC has native support for MP mac does not
#if defined(_WIN32)

#include <omp.h>

#endif

#endif
