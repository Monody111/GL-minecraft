//
//  NonCopyable.hpp
//  GL
//
//  Created by Chen.Zr on 2020/2/3.
//  Copyright © 2020 Chen.Zr. All rights reserved.
//

#ifndef NonCopyable_hpp
#define NonCopyable_hpp

struct NonCopyable
{
    NonCopyable() = default;
    private:
        NonCopyable(const NonCopyable&) = delete;
        NonCopyable& operator=(const NonCopyable&) = delete;
};

#endif /* NonCopyable_hpp */
