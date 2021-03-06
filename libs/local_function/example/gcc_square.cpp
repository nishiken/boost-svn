
// Copyright (C) 2009-2012 Lorenzo Caminiti
// Distributed under the Boost Software License, Version 1.0
// (see accompanying file LICENSE_1_0.txt or a copy at
// http://www.boost.org/LICENSE_1_0.txt)
// Home at http://www.boost.org/libs/local_function

#include <boost/local_function.hpp>
#define BOOST_TEST_MODULE TestGccSquare
#include <boost/test/unit_test.hpp>

int add_square(int a, int b) {
    int BOOST_LOCAL_FUNCTION(int z) {
        return z * z;
    } BOOST_LOCAL_FUNCTION_NAME(square)

    return square(a) + square(b);
}

BOOST_AUTO_TEST_CASE(test_gcc_square) {
    BOOST_CHECK(add_square(2, 4) == 20);
}

