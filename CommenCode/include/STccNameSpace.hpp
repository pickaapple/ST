//
//  STccNamaspace.hpp
//  STCommenCode
//
//  Created by yhys on 2017/8/5.
//  Copyright © 2017年 ST Studio. All rights reserved.
//

#ifndef STccNamaspace_hpp
#define STccNamaspace_hpp

#ifdef __cplusplus
//STcc
#define STCC              STcc
#define NS_STCC_BEGIN     namespace STCC {
#define NS_STCC_END       }
#define USING_NS_STCC     using namespace STCC;
#define NS_STCC           STcc::

#else
//STcc
#define STCC
#define NS_STCC_BEGIN
#define NS_STCC_END
#define USING_NS_STCC
#define NS_STCC
#endif

#endif /* STccNamaspace_hpp */
