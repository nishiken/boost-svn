///////////////////////////////////////////////////////////////////////////////
// posix_charset_matcher.hpp
//
//  Copyright 2004 Eric Niebler. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_XPRESSIVE_DETAIL_CORE_MATCHER_POSIX_CHARSET_MATCHER_HPP_EAN_10_04_2005
#define BOOST_XPRESSIVE_DETAIL_CORE_MATCHER_POSIX_CHARSET_MATCHER_HPP_EAN_10_04_2005

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

#include <boost/assert.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/xpressive/detail/detail_fwd.hpp>
#include <boost/xpressive/detail/core/quant_style.hpp>
#include <boost/xpressive/detail/core/state.hpp>
#include <boost/xpressive/detail/utility/traits_utils.hpp>

namespace boost { namespace xpressive { namespace detail
{

    ///////////////////////////////////////////////////////////////////////////////
    // posix_charset_matcher
    //
    template<typename TraitsT, bool ICaseT>
    struct posix_charset_matcher
      : quant_style_fixed_width<1>
    {
        typedef TraitsT traits_type;
        typedef mpl::bool_<ICaseT> icase_type;
        typedef typename TraitsT::char_class_type char_class_type;

        posix_charset_matcher(char_class_type m, bool no)
          : not_(no)
          , mask_(m)
        {
            BOOST_ASSERT(0 != this->mask_);
        }

        template<typename BidiIterT, typename NextT>
        bool match(state_type<BidiIterT> &state, NextT const &next) const
        {
            if(state.eos() || this->not_ == traits_cast<TraitsT>(state).isctype(
               detail::translate(*state.cur_, traits_cast<TraitsT>(state), icase_type()), this->mask_))
            {
                return false;
            }

            ++state.cur_;
            if(next.match(state))
            {
                return true;
            }

            --state.cur_;
            return false;
        }

        bool not_;
        char_class_type mask_;
    };

}}}

#endif
