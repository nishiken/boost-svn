/* boost random/uniform_smallint.hpp header file
 *
 * Copyright Jens Maurer 2000-2001
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * See http://www.boost.org for most recent version including documentation.
 *
 * $Id$
 *
 * Revision history
 *  2001-04-08  added min<max assertion (N. Becker)
 *  2001-02-18  moved to individual header files
 */

#ifndef BOOST_RANDOM_UNIFORM_SMALLINT_HPP
#define BOOST_RANDOM_UNIFORM_SMALLINT_HPP

#include <cassert>
#include <iostream>
#include <boost/config.hpp>
#include <boost/limits.hpp>
#include <boost/static_assert.hpp>
#include <boost/random/detail/config.hpp>
#include <boost/random/uniform_01.hpp>
#include <boost/detail/workaround.hpp>

namespace boost {

// uniform integer distribution on a small range [min, max]

/**
 * The distribution function uniform_smallint models a \random_distribution.
 * On each invocation, it returns a random integer value uniformly distributed
 * in the set of integer numbers {min, min+1, min+2, ..., max}. It assumes
 * that the desired range (max-min+1) is small compared to the range of the
 * underlying source of random numbers and thus makes no attempt to limit
 * quantization errors.
 *
 * Let \f$r_{\mathtt{out}} = (\mbox{max}-\mbox{min}+1)\f$ the desired range of
 * integer numbers, and
 * let \f$r_{\mathtt{base}}\f$ be the range of the underlying source of random
 * numbers. Then, for the uniform distribution, the theoretical probability
 * for any number i in the range \f$r_{\mathtt{out}}\f$ will be
 * \f$\displaystyle p_{\mathtt{out}}(i) = \frac{1}{r_{\mathtt{out}}}\f$.
 * Likewise, assume a uniform distribution on \f$r_{\mathtt{base}}\f$ for
 * the underlying source of random numbers, i.e.
 * \f$\displaystyle p_{\mathtt{base}}(i) = \frac{1}{r_{\mathtt{base}}}\f$.
 * Let \f$p_{\mathtt{out\_s}}(i)\f$ denote the random
 * distribution generated by @c uniform_smallint. Then the sum over all
 * i in \f$r_{\mathtt{out}}\f$ of
 * \f$\displaystyle
 * \left(\frac{p_{\mathtt{out\_s}}(i)}{p_{\mathtt{out}}(i)} - 1\right)^2\f$
 * shall not exceed
 * \f$\displaystyle \frac{r_{\mathtt{out}}}{r_{\mathtt{base}}^2}
 * (r_{\mathtt{base}} \mbox{ mod } r_{\mathtt{out}})
 * (r_{\mathtt{out}} - r_{\mathtt{base}} \mbox{ mod } r_{\mathtt{out}})\f$.
 *
 * The template parameter IntType shall denote an integer-like value type.
 *
 * Note: The property above is the square sum of the relative differences
 * in probabilities between the desired uniform distribution
 * \f$p_{\mathtt{out}}(i)\f$ and the generated distribution
 * \f$p_{\mathtt{out\_s}}(i)\f$.
 * The property can be fulfilled with the calculation
 * \f$(\mbox{base\_rng} \mbox{ mod } r_{\mathtt{out}})\f$, as follows:
 * Let \f$r = r_{\mathtt{base}} \mbox{ mod } r_{\mathtt{out}}\f$.
 * The base distribution on \f$r_{\mathtt{base}}\f$ is folded onto the
 * range \f$r_{\mathtt{out}}\f$. The numbers i < r have assigned
 * \f$\displaystyle
 * \left\lfloor\frac{r_{\mathtt{base}}}{r_{\mathtt{out}}}\right\rfloor+1\f$
 * numbers of the base distribution, the rest has only \f$\displaystyle
 * \left\lfloor\frac{r_{\mathtt{base}}}{r_{\mathtt{out}}}\right\rfloor\f$.
 * Therefore,
 * \f$\displaystyle p_{\mathtt{out\_s}}(i) =
 * \left(\left\lfloor\frac{r_{\mathtt{base}}}
 * {r_{\mathtt{out}}}\right\rfloor+1\right) /
 * r_{\mathtt{base}}\f$ for i < r and \f$\displaystyle p_{\mathtt{out\_s}}(i) =
 * \left\lfloor\frac{r_{\mathtt{base}}}
 * {r_{\mathtt{out}}}\right\rfloor/r_{\mathtt{base}}\f$ otherwise.
 * Substituting this in the
 * above sum formula leads to the desired result.
 *
 * Note: The upper bound for
 * \f$(r_{\mathtt{base}} \mbox{ mod } r_{\mathtt{out}})
 * (r_{\mathtt{out}} - r_{\mathtt{base}} \mbox{ mod } r_{\mathtt{out}})\f$ is
 * \f$\displaystyle \frac{r_{\mathtt{out}}^2}{4}\f$.  Regarding the upper bound
 * for the square sum of the relative quantization error of
 * \f$\displaystyle \frac{r_\mathtt{out}^3}{4r_{\mathtt{base}}^2}\f$, it
 * seems wise to either choose \f$r_{\mathtt{base}}\f$ so that
 * \f$r_{\mathtt{base}} > 10r_{\mathtt{out}}^2\f$ or ensure that
 * \f$r_{\mathtt{base}}\f$ is
 * divisible by \f$r_{\mathtt{out}}\f$.
 */
template<class IntType = int>
class uniform_smallint
{
public:
  typedef IntType input_type;
  typedef IntType result_type;

  /**
   * Constructs a @c uniform_smallint. @c min and @c max are the
   * lower and upper bounds of the output range, respectively.
   */
  explicit uniform_smallint(IntType min_arg = 0, IntType max_arg = 9)
    : _min(min_arg), _max(max_arg)
  {
#ifndef BOOST_NO_LIMITS_COMPILE_TIME_CONSTANTS
    // MSVC fails BOOST_STATIC_ASSERT with std::numeric_limits at class scope
    BOOST_STATIC_ASSERT(std::numeric_limits<IntType>::is_integer);
#endif
 }

  result_type min BOOST_PREVENT_MACRO_SUBSTITUTION () const { return _min; }
  result_type max BOOST_PREVENT_MACRO_SUBSTITUTION () const { return _max; }
  void reset() { }

  template<class Engine>
  result_type operator()(Engine& eng)
  {
    typedef typename Engine::result_type base_result;
    base_result _range = static_cast<base_result>(_max-_min)+1;
    base_result _factor = 1;
    
    // LCGs get bad when only taking the low bits.
    // (probably put this logic into a partial template specialization)
    // Check how many low bits we can ignore before we get too much
    // quantization error.
    base_result r_base = (eng.max)() - (eng.min)();
    if(r_base == (std::numeric_limits<base_result>::max)()) {
      _factor = 2;
      r_base /= 2;
    }
    r_base += 1;
    if(r_base % _range == 0) {
      // No quantization effects, good
      _factor = r_base / _range;
    } else {
      // carefully avoid overflow; pessimizing here
      for( ; r_base/_range/32 >= _range; _factor *= 2)
        r_base /= 2;
    }

    return static_cast<result_type>(((eng() - (eng.min)()) / _factor) % _range + _min);
  }

#ifndef BOOST_RANDOM_NO_STREAM_OPERATORS
  template<class CharT, class Traits>
  friend std::basic_ostream<CharT,Traits>&
  operator<<(std::basic_ostream<CharT,Traits>& os, const uniform_smallint& ud)
  {
    os << ud._min << " " << ud._max;
    return os;
  }

  template<class CharT, class Traits>
  friend std::basic_istream<CharT,Traits>&
  operator>>(std::basic_istream<CharT,Traits>& is, uniform_smallint& ud)
  {
    is >> std::ws >> ud._min >> std::ws >> ud._max;
    return is;
  }
#endif

private:

  result_type _min;
  result_type _max;
};

} // namespace boost

#endif // BOOST_RANDOM_UNIFORM_SMALLINT_HPP